//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source 
// License. See LICENSE.TXT for details.
//
//=----------------------------------------------------------------=//
//
// This file defines the interfaces that PIC18F4455 uses to lower
//    LLVM code into a selection DAG.
//
//=----------------------------------------------------------------=//

#define DEBUG_TYPE "pic18f4455-lower"
#include "PIC18F4455ABINames.h"
#include "PIC18F4455ISelLowering.h"
#include "PIC18F4455.h"
#include "PIC18F4455TargetMachine.h"
#include "PIC18F4455MachineFunctionInfo.h"
#include "llvm/DerivedTypes.h"
#include "llvm/GlobalValue.h"
#include "llvm/Function.h"
#include "llvm/CallingConv.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/CodeGen/PseudoSourceValue.h"
#include "llvm/CodeGen/SelectionDAGISel.h"
#include "llvm/CodeGen/SelectionDAGNodes.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/ValueTypes.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/ADT/StringExtras.h"
#include <iostream>


using namespace llvm;

// PIC18F4455TargetLowering Constructor.
PIC18F4455TargetLowering::
   PIC18F4455TargetLowering(PIC18F4455TargetMachine &TM) :
      TargetLowering(TM, new TargetLoweringObjectFileELF()) {
 
  Subtarget = &TM.getSubtarget<PIC18F4455Subtarget>();

  // Set up the register classes.
  addRegisterClass(MVT::i8, PIC18F4455::GR8RegisterClass);
  addRegisterClass(MVT::i16, PIC18F4455::GR16RegisterClass);

  // Compute derived properties from the register classes
  computeRegisterProperties();

  // Even if we have only 1 bit shift here, we can perform
  // shifts of the whole bitwidth 1 bit per step.
  setShiftAmountType(MVT::i8);

  setStackPointerRegisterToSaveRestore(PIC18F4455::SPWR);
  setBooleanContents(ZeroOrOneBooleanContent);

  // We have post-incremented loads / stores.
}

SDValue PIC18F4455TargetLowering::LowerOperation(SDValue Op,
                                            SelectionDAG &DAG) const {
  switch (Op.getOpcode()) {
    case ISD::ADD: // fall through
    case ISD::ADDC:
    case ISD::SUB:
    case ISD::SUBC:
    case ISD::STORE:       return ExpandStore(Op.getNode(), DAG);
    case ISD::MUL:         return LowerMUL(Op, DAG);
    case ISD::SHL:
    case ISD::SRA:
    case ISD::SRL:         return LowerShift(Op, DAG);
    case ISD::OR:
    case ISD::AND:
    default:
       DEBUG(Op.getOpcode());
       llvm_unreachable("unimplemented targetLowering operand in ");
       return SDValue();
  }
}

std::pair<const TargetRegisterClass*, uint8_t>
PIC18F4455TargetLowering::findRepresentativeClass(EVT VT) const {
  switch (VT.getSimpleVT().SimpleTy) {
  default:
    return TargetLowering::findRepresentativeClass(VT);
  case MVT::i16:
    return std::make_pair(PIC18F4455::GR16RegisterClass, 1);
  }
}

// getOutFlag - Extract the flag result if the Op has it.
static SDValue getOutFlag(SDValue &Op) {
  // Flag is the last value of the node.
  SDValue Flag = Op.getValue(Op.getNode()->getNumValues() - 1);

  assert (Flag.getValueType() == MVT::Flag 
          && "Node does not have an out Flag");

  return Flag;
}
// Get the TmpOffset for FrameIndex
unsigned PIC18F4455TargetLowering::GetTmpOffsetForFI(unsigned FI, unsigned size,
                                                MachineFunction &MF) const {
  PIC18F4455MachineFunctionInfo *FuncInfo = MF.getInfo<PIC18F4455MachineFunctionInfo>();
  std::map<unsigned, unsigned> &FiTmpOffsetMap = FuncInfo->getFiTmpOffsetMap();

  std::map<unsigned, unsigned>::iterator 
            MapIt = FiTmpOffsetMap.find(FI);
  if (MapIt != FiTmpOffsetMap.end())
      return MapIt->second;

  // This FI (FrameIndex) is not yet mapped, so map it
  FiTmpOffsetMap[FI] = FuncInfo->getTmpSize(); 
  FuncInfo->setTmpSize(FuncInfo->getTmpSize() + size);
  return FiTmpOffsetMap[FI];
}

void PIC18F4455TargetLowering::ResetTmpOffsetMap(SelectionDAG &DAG) const {
  MachineFunction &MF = DAG.getMachineFunction();
  PIC18F4455MachineFunctionInfo *FuncInfo = MF.getInfo<PIC18F4455MachineFunctionInfo>();
  FuncInfo->getFiTmpOffsetMap().clear();
  FuncInfo->setTmpSize(0);
}

// To extract chain value from the SDValue Nodes
// This function will help to maintain the chain extracting
// code at one place. In case of any change in future it will
// help maintain the code.
static SDValue getChain(SDValue &Op) { 
  SDValue Chain = Op.getValue(Op.getNode()->getNumValues() - 1);

  // If the last value returned in Flag then the chain is
  // second last value returned.
  if (Chain.getValueType() == MVT::Flag)
    Chain = Op.getValue(Op.getNode()->getNumValues() - 2);
  
  // All nodes may not produce a chain. Therefore following assert
  // verifies that the node is returning a chain only.
  assert (Chain.getValueType() == MVT::Other 
          && "Node does not have a chain");

  return Chain;
}

/// PopulateResults - Helper function to LowerOperation.
/// If a node wants to return multiple results after lowering,
/// it stuffs them into an array of SDValue called Results.

static void PopulateResults(SDValue N, SmallVectorImpl<SDValue>&Results) {
  if (N.getOpcode() == ISD::MERGE_VALUES) {
    int NumResults = N.getNumOperands();
    for( int i = 0; i < NumResults; i++)
      Results.push_back(N.getOperand(i));
  }
  else
    Results.push_back(N);
}

MVT::SimpleValueType
PIC18F4455TargetLowering::getSetCCResultType(EVT ValType) const {
  return MVT::i8;
}

MVT::SimpleValueType
PIC18F4455TargetLowering::getCmpLibcallReturnType() const {
  return MVT::i8; 
}

/// The type legalizer framework of generating legalizer can generate libcalls
/// only when the operand/result types are illegal.
/// PIC18F4455 needs to generate libcalls even for the legal types (i8) for some ops.
/// For example an arithmetic right shift. These functions are used to lower
/// such operations that generate libcall for legal types.

void 
PIC18F4455TargetLowering::setPIC18F4455LibcallName(PIC18F4455ISD::PIC18F4455Libcall Call,
                                         const char *Name) {
  PIC18F4455LibcallNames[Call] = Name; 
}

const char *
PIC18F4455TargetLowering::getPIC18F4455LibcallName(PIC18F4455ISD::PIC18F4455Libcall Call) const {
  return PIC18F4455LibcallNames[Call];
}

SDValue
PIC18F4455TargetLowering::MakePIC18F4455Libcall(PIC18F4455ISD::PIC18F4455Libcall Call,
                                      EVT RetVT, const SDValue *Ops,
                                      unsigned NumOps, bool isSigned,
                                      SelectionDAG &DAG, DebugLoc dl) const {

  TargetLowering::ArgListTy Args;
  Args.reserve(NumOps);

  TargetLowering::ArgListEntry Entry;
  for (unsigned i = 0; i != NumOps; ++i) {
    Entry.Node = Ops[i];
    Entry.Ty = Entry.Node.getValueType().getTypeForEVT(*DAG.getContext());
    Entry.isSExt = isSigned;
    Entry.isZExt = !isSigned;
    Args.push_back(Entry);
  }

  SDValue Callee = DAG.getExternalSymbol(getPIC18F4455LibcallName(Call), MVT::i16);

   const Type *RetTy = RetVT.getTypeForEVT(*DAG.getContext());
   std::pair<SDValue,SDValue> CallInfo = 
     LowerCallTo(DAG.getEntryNode(), RetTy, isSigned, !isSigned, false,
                 false, 0, CallingConv::C, false,
                 /*isReturnValueUsed=*/true,
                 Callee, Args, DAG, dl);

  return CallInfo.first;
}

const char *PIC18F4455TargetLowering::getTargetNodeName(unsigned Opcode) const {
  switch (Opcode) {
  default:                         return NULL;
  case PIC18F4455ISD::Lo:               return "PIC18F4455ISD::Lo";
  case PIC18F4455ISD::Hi:               return "PIC18F4455ISD::Hi";
  case PIC18F4455ISD::MTLO:             return "PIC18F4455ISD::MTLO";
  case PIC18F4455ISD::MTHI:             return "PIC18F4455ISD::MTHI";
  case PIC18F4455ISD::MTPCLATH:         return "PIC18F4455ISD::MTPCLATH";
  case PIC18F4455ISD::PIC18F4455Connect:     return "PIC18F4455ISD::PIC18F4455Connect";
  case PIC18F4455ISD::PIC18F4455Load:        return "PIC18F4455ISD::PIC18F4455Load";
  case PIC18F4455ISD::PIC18F4455LdArg:       return "PIC18F4455ISD::PIC18F4455LdArg";
  case PIC18F4455ISD::PIC18F4455LdWF:        return "PIC18F4455ISD::PIC18F4455LdWF";
  case PIC18F4455ISD::PIC18F4455Store:       return "PIC18F4455ISD::PIC18F4455Store";
  case PIC18F4455ISD::PIC18F4455StWF:        return "PIC18F4455ISD::PIC18F4455StWF";
  case PIC18F4455ISD::BCF:              return "PIC18F4455ISD::BCF";
  case PIC18F4455ISD::LSLF:             return "PIC18F4455ISD::LSLF";
  case PIC18F4455ISD::LRLF:             return "PIC18F4455ISD::LRLF";
  case PIC18F4455ISD::RLF:              return "PIC18F4455ISD::RLF";
  case PIC18F4455ISD::RRF:              return "PIC18F4455ISD::RRF";
  case PIC18F4455ISD::CALL:             return "PIC18F4455ISD::CALL";
  case PIC18F4455ISD::CALLW:            return "PIC18F4455ISD::CALLW";
  case PIC18F4455ISD::SUBCC:            return "PIC18F4455ISD::SUBCC";
  case PIC18F4455ISD::SELECT_ICC:       return "PIC18F4455ISD::SELECT_ICC";
  case PIC18F4455ISD::BRCOND:           return "PIC18F4455ISD::BRCOND";
  case PIC18F4455ISD::RET:              return "PIC18F4455ISD::RET";
  case PIC18F4455ISD::RETLW:            return "PIC18F4455ISD::RETLW";
  case PIC18F4455ISD::Dummy:            return "PIC18F4455ISD::Dummy";
  }
}

void PIC18F4455TargetLowering::ReplaceNodeResults(SDNode *N,
                                             SmallVectorImpl<SDValue>&Results,
                                             SelectionDAG &DAG) const {

  switch (N->getOpcode()) {
    case ISD::GlobalAddress:
      Results.push_back(ExpandGlobalAddress(N, DAG));
      return;
    case ISD::ExternalSymbol:
      Results.push_back(ExpandExternalSymbol(N, DAG));
      return;
    case ISD::STORE:
      Results.push_back(ExpandStore(N, DAG));
      return;
    case ISD::LOAD:
      //assert (0 && "Load not implemented");
      //PopulateResults(ExpandLoad(N, DAG), Results);
      return;
    case ISD::ADD:
      //assert (0 && "add not implemented");
      // Results.push_back(ExpandAdd(N, DAG));
      return;
    case ISD::FrameIndex:
      //assert (0 && "frameindex not implemented");
      //Results.push_back(ExpandFrameIndex(N, DAG));
      return;
    default:
      std::cout << ("not implemented " + utostr(N->getOpcode())) << std::endl;
      assert (0 && "not implemented ");
      return;
  }
}

#include "PIC18F4455GenCallingConv.inc"

SDValue
PIC18F4455TargetLowering::
   LowerFormalArguments(SDValue Chain
                       , CallingConv::ID CallConv
                       , bool isVarArg
                       , const SmallVectorImpl<ISD::InputArg> &Ins
                       , DebugLoc dl
                       , SelectionDAG &DAG
                       , SmallVectorImpl<SDValue> &InVals) const {
  switch (CallConv) {
  default:
    llvm_unreachable("Unsupported calling convention");
  case CallingConv::Fast:
  case CallingConv::C:
    return LowerCCCArguments(Chain, CallConv, isVarArg, Ins
                            , dl, DAG, InVals);
  }
}

/// LowerCCCArguments - transform physical registers into virtual registers and
/// generate load operations for arguments places on the stack.
// FIXME: struct return stuff
// FIXME: varargs
SDValue PIC18F4455TargetLowering::
   LowerCCCArguments(SDValue Chain
                    , CallingConv::ID CallConv
                    , bool isVarArg
                    , const SmallVectorImpl<ISD::InputArg> &Ins
                    , DebugLoc dl
                    , SelectionDAG &DAG
                    , SmallVectorImpl<SDValue> &InVals) const {
  MachineFunction &MF = DAG.getMachineFunction();
  MachineFrameInfo *MFI = MF.getFrameInfo();
  MachineRegisterInfo &RegInfo = MF.getRegInfo();

  // Assign locations to all of the incoming arguments.
  SmallVector<CCValAssign, 16> ArgLocs;
  CCState CCInfo(CallConv, isVarArg, getTargetMachine(),
                 ArgLocs, *DAG.getContext());
  CCInfo.AnalyzeFormalArguments(Ins, CC_PIC18F4455);

  assert(!isVarArg && "Varargs not supported yet");

  for (unsigned i = 0, e = ArgLocs.size(); i != e; ++i) {
    CCValAssign &VA = ArgLocs[i];
    if (VA.isRegLoc()) {
      // Arguments passed in registers
      EVT RegVT = VA.getLocVT();
      unsigned VReg;
      switch (RegVT.getSimpleVT().SimpleTy) {
      default: {
         DEBUG(errs() << "LowerFormalArguments Unhandled argument type: "
                      << RegVT.getSimpleVT().SimpleTy << "\n");
         llvm_unreachable(0);
        }
      case MVT::i8:
         VReg =
          RegInfo.createVirtualRegister(PIC18F4455::GR8RegisterClass);
      //case MVT::i16:
      //   VReg =
      //    RegInfo.createVirtualRegister(PIC18F4455::FSR16RegisterClass);
      }
      RegInfo.addLiveIn(VA.getLocReg(), VReg);
      SDValue ArgValue = DAG.getCopyFromReg(Chain, dl, VReg, RegVT);
      InVals.push_back(ArgValue);
    } else {
      // Sanity check
      assert(VA.isMemLoc());
      // Load the argument to a virtual register
      unsigned ObjSize = VA.getLocVT().getSizeInBits()/8;
      if (ObjSize > 2) {
        errs() << "LowerFormalArguments Unhandled argument type: "
             << VA.getLocVT().getSimpleVT().SimpleTy
             << "\n";
      }
      // Create the frame index object for this incoming parameter...
      int FI =
            MFI->CreateFixedObject(ObjSize, VA.getLocMemOffset(), true);

      // Create the SelectionDAG nodes corresponding to a load
      //    from this parameter
      SDValue FIN = DAG.getFrameIndex(FI, MVT::i16);
      InVals.push_back(DAG.getLoad(VA.getLocVT(), dl, Chain, FIN
                                  , PseudoSourceValue::getFixedStack(FI)
                                  , 0, false, false, 0));
    }
  }

  return Chain;
}


SDValue PIC18F4455TargetLowering::ExpandStore(SDNode *N, SelectionDAG &DAG) const { 
  StoreSDNode *St = cast<StoreSDNode>(N);
  SDValue Chain = St->getChain();
  SDValue Src = St->getValue();
  SDValue Ptr = St->getBasePtr();
  EVT ValueType = Src.getValueType();
  unsigned StoreOffset = 0;
  DebugLoc dl = N->getDebugLoc();

  SDValue PtrLo, PtrHi;
  LegalizeAddress(Ptr, DAG, PtrLo, PtrHi, StoreOffset, dl);
 
  if (ValueType == MVT::i8) {
    return DAG.getNode (PIC18F4455ISD::PIC18F4455Store, dl, MVT::Other, Chain, Src,
                        PtrLo, PtrHi, 
                        DAG.getConstant (0 + StoreOffset, MVT::i8));
  }
  else if (ValueType == MVT::i16) {
    // Get the Lo and Hi parts from MERGE_VALUE or BUILD_PAIR.
    SDValue SrcLo, SrcHi;
    GetExpandedParts(Src, DAG, SrcLo, SrcHi);
    SDValue ChainLo = Chain, ChainHi = Chain;
    // FIXME: This makes unsafe assumptions. The Chain may be a TokenFactor
    // created for an unrelated purpose, in which case it may not have
    // exactly two operands. Also, even if it does have two operands, they
    // may not be the low and high parts of an aligned load that was split.
    if (Chain.getOpcode() == ISD::TokenFactor) {
      ChainLo = Chain.getOperand(0);
      ChainHi = Chain.getOperand(1);
    }
    SDValue Store1 = DAG.getNode(PIC18F4455ISD::PIC18F4455Store, dl, MVT::Other,
                                 ChainLo,
                                 SrcLo, PtrLo, PtrHi,
                                 DAG.getConstant (0 + StoreOffset, MVT::i8));

    SDValue Store2 = DAG.getNode(PIC18F4455ISD::PIC18F4455Store, dl, MVT::Other, ChainHi, 
                                 SrcHi, PtrLo, PtrHi,
                                 DAG.getConstant (1 + StoreOffset, MVT::i8));

    return DAG.getNode(ISD::TokenFactor, dl, MVT::Other, getChain(Store1),
                       getChain(Store2));
  }
  else if (ValueType == MVT::i32) {
    // Get the Lo and Hi parts from MERGE_VALUE or BUILD_PAIR.
    SDValue SrcLo, SrcHi;
    GetExpandedParts(Src, DAG, SrcLo, SrcHi);

    // Get the expanded parts of each of SrcLo and SrcHi.
    SDValue SrcLo1, SrcLo2, SrcHi1, SrcHi2;
    GetExpandedParts(SrcLo, DAG, SrcLo1, SrcLo2);
    GetExpandedParts(SrcHi, DAG, SrcHi1, SrcHi2);

    SDValue ChainLo = Chain, ChainHi = Chain;
    // FIXME: This makes unsafe assumptions; see the FIXME above.
    if (Chain.getOpcode() == ISD::TokenFactor) {  
      ChainLo = Chain.getOperand(0);
      ChainHi = Chain.getOperand(1);
    }
    SDValue ChainLo1 = ChainLo, ChainLo2 = ChainLo, ChainHi1 = ChainHi,
            ChainHi2 = ChainHi;
    // FIXME: This makes unsafe assumptions; see the FIXME above.
    if (ChainLo.getOpcode() == ISD::TokenFactor) {
      ChainLo1 = ChainLo.getOperand(0);
      ChainLo2 = ChainLo.getOperand(1);
    }
    // FIXME: This makes unsafe assumptions; see the FIXME above.
    if (ChainHi.getOpcode() == ISD::TokenFactor) {
      ChainHi1 = ChainHi.getOperand(0);
      ChainHi2 = ChainHi.getOperand(1);
    }
    SDValue Store1 = DAG.getNode(PIC18F4455ISD::PIC18F4455Store, dl, MVT::Other,
                                 ChainLo1,
                                 SrcLo1, PtrLo, PtrHi,
                                 DAG.getConstant (0 + StoreOffset, MVT::i8));

    SDValue Store2 = DAG.getNode(PIC18F4455ISD::PIC18F4455Store, dl, MVT::Other, ChainLo2,
                                 SrcLo2, PtrLo, PtrHi,
                                 DAG.getConstant (1 + StoreOffset, MVT::i8));

    SDValue Store3 = DAG.getNode(PIC18F4455ISD::PIC18F4455Store, dl, MVT::Other, ChainHi1,
                                 SrcHi1, PtrLo, PtrHi,
                                 DAG.getConstant (2 + StoreOffset, MVT::i8));

    SDValue Store4 = DAG.getNode(PIC18F4455ISD::PIC18F4455Store, dl, MVT::Other, ChainHi2,
                                 SrcHi2, PtrLo, PtrHi,
                                 DAG.getConstant (3 + StoreOffset, MVT::i8));

    SDValue RetLo =  DAG.getNode(ISD::TokenFactor, dl, MVT::Other, 
                                 getChain(Store1), getChain(Store2));
    SDValue RetHi =  DAG.getNode(ISD::TokenFactor, dl, MVT::Other, 
                                 getChain(Store3), getChain(Store4));
    return  DAG.getNode(ISD::TokenFactor, dl, MVT::Other, RetLo, RetHi);

  } else if (ValueType == MVT::i64) {
    SDValue SrcLo, SrcHi;
    GetExpandedParts(Src, DAG, SrcLo, SrcHi);
    SDValue ChainLo = Chain, ChainHi = Chain;
    // FIXME: This makes unsafe assumptions; see the FIXME above.
    if (Chain.getOpcode() == ISD::TokenFactor) {
      ChainLo = Chain.getOperand(0);
      ChainHi = Chain.getOperand(1);
    }
    SDValue Store1 = DAG.getStore(ChainLo, dl, SrcLo, Ptr, NULL,
                                  0 + StoreOffset, false, false, 0);

    Ptr = DAG.getNode(ISD::ADD, dl, Ptr.getValueType(), Ptr,
                      DAG.getConstant(4, Ptr.getValueType()));
    SDValue Store2 = DAG.getStore(ChainHi, dl, SrcHi, Ptr, NULL,
                                  1 + StoreOffset, false, false, 0);

    return DAG.getNode(ISD::TokenFactor, dl, MVT::Other, Store1,
                       Store2);
  } else {
    assert (0 && "value type not supported");
    return SDValue();
  }
}

SDValue PIC18F4455TargetLowering::ExpandExternalSymbol(SDNode *N,
                                                  SelectionDAG &DAG)
 const {
  ExternalSymbolSDNode *ES = dyn_cast<ExternalSymbolSDNode>(SDValue(N, 0));
  // FIXME there isn't really debug info here
  DebugLoc dl = ES->getDebugLoc();

  SDValue TES = DAG.getTargetExternalSymbol(ES->getSymbol(), MVT::i8);
  SDValue Offset = DAG.getConstant(0, MVT::i8);
  SDValue Lo = DAG.getNode(PIC18F4455ISD::Lo, dl, MVT::i8, TES, Offset);
  SDValue Hi = DAG.getNode(PIC18F4455ISD::Hi, dl, MVT::i8, TES, Offset);

  return DAG.getNode(ISD::BUILD_PAIR, dl, MVT::i16, Lo, Hi);
}

// ExpandGlobalAddress - 
SDValue PIC18F4455TargetLowering::ExpandGlobalAddress(SDNode *N,
                                                 SelectionDAG &DAG) const {
  GlobalAddressSDNode *G = dyn_cast<GlobalAddressSDNode>(SDValue(N, 0));
  // FIXME there isn't really debug info here
  DebugLoc dl = G->getDebugLoc();
  
  SDValue TGA = DAG.getTargetGlobalAddress(G->getGlobal(), N->getDebugLoc(),
                                           MVT::i8,
                                           G->getOffset());

  SDValue Offset = DAG.getConstant(0, MVT::i8);
  SDValue Lo = DAG.getNode(PIC18F4455ISD::Lo, dl, MVT::i8, TGA, Offset);
  SDValue Hi = DAG.getNode(PIC18F4455ISD::Hi, dl, MVT::i8, TGA, Offset);

  return DAG.getNode(ISD::BUILD_PAIR, dl, MVT::i16, Lo, Hi);
}

bool PIC18F4455TargetLowering::isDirectAddress(const SDValue &Op) const {
  assert (Op.getNode() != NULL && "Can't operate on NULL SDNode!!");

  if (Op.getOpcode() == ISD::BUILD_PAIR) {
   if (Op.getOperand(0).getOpcode() == PIC18F4455ISD::Lo) 
     return true;
  }
  return false;
}

// Return true if DirectAddress is in ROM_SPACE
bool PIC18F4455TargetLowering::isRomAddress(const SDValue &Op) const {

  // RomAddress is a GlobalAddress in ROM_SPACE_
  // If the Op is not a GlobalAddress return NULL without checking
  // anything further.
  if (!isDirectAddress(Op))
    return false; 

  // Its a GlobalAddress.
  // It is BUILD_PAIR((PIC18F4455Lo TGA), (PIC18F4455Hi TGA)) and Op is BUILD_PAIR
  SDValue TGA = Op.getOperand(0).getOperand(0);
  GlobalAddressSDNode *GSDN = dyn_cast<GlobalAddressSDNode>(TGA);

  if (GSDN->getAddressSpace() == PIC18F4455ISD::ROM_SPACE)
    return true;

  // Any other address space return it false
  return false;
}


// GetExpandedParts - This function is on the similiar lines as
// the GetExpandedInteger in type legalizer is. This returns expanded
// parts of Op in Lo and Hi. 

void PIC18F4455TargetLowering::GetExpandedParts(SDValue Op, SelectionDAG &DAG,
                                           SDValue &Lo, SDValue &Hi) const {
  SDNode *N = Op.getNode();
  DebugLoc dl = N->getDebugLoc();
  EVT NewVT = getTypeToTransformTo(*DAG.getContext(), N->getValueType(0));

  // Extract the lo component.
  Lo = DAG.getNode(ISD::EXTRACT_ELEMENT, dl, NewVT, Op,
                   DAG.getConstant(0, MVT::i8));

  // extract the hi component
  Hi = DAG.getNode(ISD::EXTRACT_ELEMENT, dl, NewVT, Op,
                   DAG.getConstant(1, MVT::i8));
}

// This function legalizes the PIC18F4455 Addresses. If the Pointer is  
//  -- Direct address variable residing 
//     --> then a Banksel for that variable will be created.
//  -- Rom variable            
//     --> then it will be treated as an indirect address.
//  -- Indirect address 
//     --> then the address will be loaded into FSR
//  -- ADD with constant operand
//     --> then constant operand of ADD will be returned as Offset
//         and non-constant operand of ADD will be treated as pointer.
// Returns the high and lo part of the address, and the offset(in case of ADD).

void PIC18F4455TargetLowering::LegalizeAddress(SDValue Ptr, SelectionDAG &DAG, 
                                          SDValue &Lo, SDValue &Hi,
                                          unsigned &Offset, DebugLoc dl) const {

  // Offset, by default, should be 0
  Offset = 0;

  // If the pointer is ADD with constant,
  // return the constant value as the offset  
  if (Ptr.getOpcode() == ISD::ADD) {
    SDValue OperLeft = Ptr.getOperand(0);
    SDValue OperRight = Ptr.getOperand(1);
    if ((OperLeft.getOpcode() == ISD::Constant) &&
        (dyn_cast<ConstantSDNode>(OperLeft)->getZExtValue() < 32 )) {
      Offset = dyn_cast<ConstantSDNode>(OperLeft)->getZExtValue();
      Ptr = OperRight;
    } else if ((OperRight.getOpcode() == ISD::Constant)  &&
               (dyn_cast<ConstantSDNode>(OperRight)->getZExtValue() < 32 )){
      Offset = dyn_cast<ConstantSDNode>(OperRight)->getZExtValue();
      Ptr = OperLeft;
    }
  }

  // If the pointer is Type i8 and an external symbol
  // then treat it as direct address.
  // One example for such case is storing and loading
  // from function frame during a call
  if (Ptr.getValueType() == MVT::i8) {
    switch (Ptr.getOpcode()) {
    case ISD::TargetExternalSymbol:
      Lo = Ptr;
      Hi = DAG.getConstant(1, MVT::i8);
      return;
    }
  }

  // Expansion of FrameIndex has Lo/Hi parts
  if (isDirectAddress(Ptr)) { 
      SDValue TFI = Ptr.getOperand(0).getOperand(0); 
      int FrameOffset;
      if (TFI.getOpcode() == ISD::TargetFrameIndex) {
        //LegalizeFrameIndex(TFI, DAG, Lo, FrameOffset);
        //Hi = DAG.getConstant(1, MVT::i8);
        //Offset += FrameOffset; 
        return;
      } else if (TFI.getOpcode() == ISD::TargetExternalSymbol) {
        // FrameIndex has already been expanded.
        // Now just make use of its expansion
        Lo = TFI;
        Hi = DAG.getConstant(1, MVT::i8);
        SDValue FOffset = Ptr.getOperand(0).getOperand(1);
        assert (FOffset.getOpcode() == ISD::Constant && 
                          "Invalid operand of PIC18F4455ISD::Lo");
        Offset += dyn_cast<ConstantSDNode>(FOffset)->getZExtValue();
        return;
      }
  }

  if (isDirectAddress(Ptr) && !isRomAddress(Ptr)) {
    // Direct addressing case for RAM variables. The Hi part is constant
    // and the Lo part is the TGA itself.
    Lo = Ptr.getOperand(0).getOperand(0);

    // For direct addresses Hi is a constant. Value 1 for the constant
    // signifies that banksel needs to generated for it. Value 0 for
    // the constant signifies that banksel does not need to be generated 
    // for it. Mark it as 1 now and optimize later. 
    //Hi = DAG.getConstant(1, MVT::i8);
    // siva no need of banksel, hence mark it as 0
    Hi = DAG.getConstant(0, MVT::i8);
    return; 
  }

  // Indirect addresses. Get the hi and lo parts of ptr. 
  GetExpandedParts(Ptr, DAG, Lo, Hi);

  // Put the hi and lo parts into FSR.
  Lo = DAG.getNode(PIC18F4455ISD::MTLO, dl, MVT::i8, Lo);
  Hi = DAG.getNode(PIC18F4455ISD::MTHI, dl, MVT::i8, Hi);

  return;
}

SDValue PIC18F4455TargetLowering::LowerShift(SDValue Op, SelectionDAG &DAG) const {
  // We should have handled larger operands in type legalizer itself.
  assert (Op.getValueType() == MVT::i8 && "illegal shift to lower");
 
  SDNode *N = Op.getNode();
  SDValue Value = N->getOperand(0);
  SDValue Amt = N->getOperand(1);
  PIC18F4455ISD::PIC18F4455Libcall CallCode;
  switch (N->getOpcode()) {
  case ISD::SRA:
    CallCode = PIC18F4455ISD::SRA_I8;
    break;
  case ISD::SHL:
    CallCode = PIC18F4455ISD::SLL_I8;
    break;
  case ISD::SRL:
    CallCode = PIC18F4455ISD::SRL_I8;
    break;
  default:
    assert ( 0 && "This shift is not implemented yet.");
    return SDValue();
  }
  SmallVector<SDValue, 2> Ops(2);
  Ops[0] = Value;
  Ops[1] = Amt;
  SDValue Call = MakePIC18F4455Libcall(CallCode, N->getValueType(0), &Ops[0], 2, 
                                  true, DAG, N->getDebugLoc());
  return Call;
}

SDValue PIC18F4455TargetLowering::LowerMUL(SDValue Op, SelectionDAG &DAG) const {
  // We should have handled larger operands in type legalizer itself.
  assert (Op.getValueType() == MVT::i8 && "illegal multiply to lower");

  SDNode *N = Op.getNode();
  SmallVector<SDValue, 2> Ops(2);
  Ops[0] = N->getOperand(0);
  Ops[1] = N->getOperand(1);
  SDValue Call = MakePIC18F4455Libcall(PIC18F4455ISD::MUL_I8, N->getValueType(0), 
                                  &Ops[0], 2, true, DAG, N->getDebugLoc());
  return Call;
}

SDValue PIC18F4455TargetLowering::
LowerIndirectCallArguments(SDValue Chain, SDValue InFlag,
                           SDValue DataAddr_Lo, SDValue DataAddr_Hi,
                           const SmallVectorImpl<ISD::OutputArg> &Outs,
                           const SmallVectorImpl<SDValue> &OutVals,
                           const SmallVectorImpl<ISD::InputArg> &Ins,
                           DebugLoc dl, SelectionDAG &DAG) const {
  unsigned NumOps = Outs.size();

  // If call has no arguments then do nothing and return.
  if (NumOps == 0)
    return Chain;

  std::vector<SDValue> Ops;
  SDVTList Tys = DAG.getVTList(MVT::Other, MVT::Flag);
  SDValue Arg, StoreRet;

  // For PIC18F4455 ABI the arguments come after the return value. 
  unsigned RetVals = Ins.size();
  for (unsigned i = 0, ArgOffset = RetVals; i < NumOps; i++) {
    // Get the arguments
    Arg = OutVals[i];
    
    Ops.clear();
    Ops.push_back(Chain);
    Ops.push_back(Arg);
    Ops.push_back(DataAddr_Lo);
    Ops.push_back(DataAddr_Hi);
    Ops.push_back(DAG.getConstant(ArgOffset, MVT::i8));
    Ops.push_back(InFlag);

    StoreRet = DAG.getNode (PIC18F4455ISD::PIC18F4455StWF, dl, Tys, &Ops[0], Ops.size());

    Chain = getChain(StoreRet);
    InFlag = getOutFlag(StoreRet);
    ArgOffset++;
  }
  return Chain;
}

SDValue PIC18F4455TargetLowering::
LowerDirectCallArguments(SDValue ArgLabel, SDValue Chain, SDValue InFlag,
                         const SmallVectorImpl<ISD::OutputArg> &Outs,
                         const SmallVectorImpl<SDValue> &OutVals,
                         DebugLoc dl, SelectionDAG &DAG) const {
  unsigned NumOps = Outs.size();
  std::string Name;
  SDValue Arg, StoreAt;
  EVT ArgVT;
  unsigned Size=0;

  // If call has no arguments then do nothing and return.
  if (NumOps == 0)
    return Chain; 

  // FIXME: This portion of code currently assumes only
  // primitive types being passed as arguments.

  // Legalize the address before use
  SDValue PtrLo, PtrHi;
  unsigned AddressOffset;
  int StoreOffset = 0;
  LegalizeAddress(ArgLabel, DAG, PtrLo, PtrHi, AddressOffset, dl);
  SDValue StoreRet;

  std::vector<SDValue> Ops;
  SDVTList Tys = DAG.getVTList(MVT::Other, MVT::Flag);
  for (unsigned i=0, Offset = 0; i<NumOps; i++) {
    // Get the argument
    Arg = OutVals[i];
    StoreOffset = (Offset + AddressOffset);
   
    // Store the argument on frame

    Ops.clear();
    Ops.push_back(Chain);
    Ops.push_back(Arg);
    Ops.push_back(PtrLo);
    Ops.push_back(PtrHi);
    Ops.push_back(DAG.getConstant(StoreOffset, MVT::i8));
    Ops.push_back(InFlag);

    StoreRet = DAG.getNode (PIC18F4455ISD::PIC18F4455StWF, dl, Tys, &Ops[0], Ops.size());

    Chain = getChain(StoreRet);
    InFlag = getOutFlag(StoreRet);

    // Update the frame offset to be used for next argument
    ArgVT = Arg.getValueType();
    Size = ArgVT.getSizeInBits();
    Size = Size/8;    // Calculate size in bytes
    Offset += Size;   // Increase the frame offset
  }
  return Chain;
}

SDValue PIC18F4455TargetLowering::
LowerIndirectCallReturn(SDValue Chain, SDValue InFlag,
                        SDValue DataAddr_Lo, SDValue DataAddr_Hi,
                        const SmallVectorImpl<ISD::InputArg> &Ins,
                        DebugLoc dl, SelectionDAG &DAG,
                        SmallVectorImpl<SDValue> &InVals) const {
  unsigned RetVals = Ins.size();

  // If call does not have anything to return
  // then do nothing and go back.
  if (RetVals == 0)
    return Chain;

  // Call has something to return
  SDValue LoadRet;

  SDVTList Tys = DAG.getVTList(MVT::i8, MVT::Other, MVT::Flag);
  for(unsigned i=0;i<RetVals;i++) {
    LoadRet = DAG.getNode(PIC18F4455ISD::PIC18F4455LdWF, dl, Tys, Chain, DataAddr_Lo,
                          DataAddr_Hi, DAG.getConstant(i, MVT::i8),
                          InFlag);
    InFlag = getOutFlag(LoadRet);
    Chain = getChain(LoadRet);
    InVals.push_back(LoadRet);
  }
  return Chain;
}

SDValue PIC18F4455TargetLowering::
LowerDirectCallReturn(SDValue RetLabel, SDValue Chain, SDValue InFlag,
                      const SmallVectorImpl<ISD::InputArg> &Ins,
                      DebugLoc dl, SelectionDAG &DAG,
                      SmallVectorImpl<SDValue> &InVals) const {

  // Currently handling primitive types only. They will come in
  // i8 parts
  unsigned RetVals = Ins.size();

  // Return immediately if the return type is void
  if (RetVals == 0)
    return Chain;

  // Call has something to return
  
  // Legalize the address before use
  SDValue LdLo, LdHi;
  unsigned LdOffset;
  LegalizeAddress(RetLabel, DAG, LdLo, LdHi, LdOffset, dl);

  SDVTList Tys = DAG.getVTList(MVT::i8, MVT::Other, MVT::Flag);
  SDValue LoadRet;
 
  for(unsigned i=0, Offset=0;i<RetVals;i++) {

    LoadRet = DAG.getNode(PIC18F4455ISD::PIC18F4455LdWF, dl, Tys, Chain, LdLo, LdHi,
                          DAG.getConstant(LdOffset + Offset, MVT::i8),
                          InFlag);

    InFlag = getOutFlag(LoadRet);

    Chain = getChain(LoadRet);
    Offset++;
    InVals.push_back(LoadRet);
  }

  return Chain;
}

SDValue
PIC18F4455TargetLowering::
   LowerCall(SDValue Chain, SDValue Callee,
             CallingConv::ID CallConv, bool isVarArg,
             bool &isTailCall,
             const SmallVectorImpl<ISD::OutputArg> &Outs,
             const SmallVectorImpl<SDValue> &OutVals,
             const SmallVectorImpl<ISD::InputArg> &Ins,
             DebugLoc dl, SelectionDAG &DAG,
             SmallVectorImpl<SDValue> &InVals) const {
  // target does not yet support tail call optimization.
  isTailCall = false;

  switch (CallConv) {
  default:
    llvm_unreachable("Unsupported calling convention");
  case CallingConv::Fast:
  case CallingConv::C:
    return LowerCCCCallTo(Chain, Callee, CallConv, isVarArg, isTailCall,
                          Outs, OutVals, Ins, dl, DAG, InVals);
  }
}

// LowerCCCCallTo - functions arguments are copied from virtual regs to
//    (physical regs)/(stack frame), CALLSEQ_START and CALLSEQ_END are
//    emitted.
// TODO: sret.
SDValue
PIC18F4455TargetLowering::
   LowerCCCCallTo( SDValue Chain, SDValue Callee,
                   CallingConv::ID CallConv, bool isVarArg,
                   bool isTailCall,
                   const SmallVectorImpl<ISD::OutputArg> &Outs,
                   const SmallVectorImpl<SDValue> &OutVals,
                   const SmallVectorImpl<ISD::InputArg> &Ins,
                   DebugLoc dl, SelectionDAG &DAG,
                   SmallVectorImpl<SDValue> &InVals) const {

  // Analyze operands of the call, assigning locations to each operand.
  SmallVector<CCValAssign, 16> ArgLocs;
  CCState CCInfo(CallConv, isVarArg, getTargetMachine(),
                 ArgLocs, *DAG.getContext());

  CCInfo.AnalyzeCallOperands(Outs, CC_PIC18F4455);

  // Get a count of how many bytes are to be pushed on the stack.
  unsigned NumBytes = CCInfo.getNextStackOffset();

  Chain = DAG.getCALLSEQ_START(Chain
                              , DAG.getConstant(NumBytes
                                               , getPointerTy(), true));

  SmallVector<std::pair<unsigned, SDValue>, 4> RegsToPass;
  SmallVector<SDValue, 12> MemOpChains;
  SDValue StackPtr;

  // Walk the register/memloc assignments, inserting copies/loads.
  for (unsigned i = 0, e = ArgLocs.size(); i != e; ++i) {
    CCValAssign &VA = ArgLocs[i];

    SDValue Arg = OutVals[i];

    // Promote the value if needed.
    switch (VA.getLocInfo()) {
      default: llvm_unreachable("Unknown loc info!");
      case CCValAssign::Full: break;
    }

    // Arguments that can be passed on register must be kept at
    //   RegsToPass vector
    if (VA.isRegLoc()) {
      RegsToPass.push_back(std::make_pair(VA.getLocReg(), Arg));
    } else {
      assert(VA.isMemLoc());

      if (StackPtr.getNode() == 0)
        StackPtr = DAG.getCopyFromReg(Chain, dl, PIC18F4455::SPWR
                                     , getPointerTy());

      SDValue PtrOff =
         DAG.getNode(ISD::ADD, dl, getPointerTy(),
                     StackPtr,
                     DAG.getIntPtrConstant(VA.getLocMemOffset()));


      MemOpChains.push_back(DAG.getStore(Chain, dl, Arg, PtrOff
                                        , PseudoSourceValue::getStack()
                                        , VA.getLocMemOffset()
                                        , false, false, 0));
    }
  }

  // Transform all store nodes into one single node because all store
  //  nodes are independent of each other.
  if (!MemOpChains.empty())
    Chain = DAG.getNode(ISD::TokenFactor, dl, MVT::Other,
                        &MemOpChains[0], MemOpChains.size());

  // Build a sequence of copy-to-reg nodes chained together with token
  //  chain and flag operands which copy the outgoing args into
  //  registers. The InFlag in necessary since all emited instructions
  //  must be stuck together.
  SDValue InFlag;
  for (unsigned i = 0, e = RegsToPass.size(); i != e; ++i) {
    Chain = DAG.getCopyToReg(Chain, dl, RegsToPass[i].first,
                             RegsToPass[i].second, InFlag);
    InFlag = Chain.getValue(1);
  }

  // If the callee is a GlobalAddress node (quite common, every direct
  //  call is) turn it into a TargetGlobalAddress node so that legalize
  //  doesn't hack it. Likewise ExternalSymbol -> TargetExternalSymbol.
  if (GlobalAddressSDNode *G = dyn_cast<GlobalAddressSDNode>(Callee)) {
    Callee = DAG.getTargetGlobalAddress(G->getGlobal(), dl, MVT::i16);
    DEBUG(errs() << "siva: global address sd node\n");
  }
  else if (ExternalSymbolSDNode *E =
            dyn_cast<ExternalSymbolSDNode>(Callee)) {
    Callee = DAG.getTargetExternalSymbol(E->getSymbol(), MVT::i16);
    DEBUG(errs() << "siva: external symbol sd node\n");
  }

  // Returns a chain & a flag for retval copy to use.
  SDVTList NodeTys = DAG.getVTList(MVT::Other, MVT::Flag);
  SmallVector<SDValue, 8> Ops;
  Ops.push_back(Chain);
  Ops.push_back(Callee);

  // Add argument registers to the end of the list so that they are
  // known live into the call.
  for (unsigned i = 0, e = RegsToPass.size(); i != e; ++i)
    Ops.push_back(DAG.getRegister(RegsToPass[i].first,
                                  RegsToPass[i].second.getValueType()));

  if (InFlag.getNode())
    Ops.push_back(InFlag);

  Chain = DAG.getNode(PIC18F4455ISD::CALL, dl, NodeTys, &Ops[0]
                     , Ops.size());
  InFlag = Chain.getValue(1);

  // Create the CALLSEQ_END node.
  Chain =
   DAG.getCALLSEQ_END(Chain
                     , DAG.getConstant(NumBytes, getPointerTy(), true)
                     , DAG.getConstant(0, getPointerTy(), true)
                     , InFlag);
  InFlag = Chain.getValue(1);

  // Handle result values, copying them out of physregs into vregs that
  // we return.
  return LowerCallResult(Chain, InFlag, CallConv, isVarArg, Ins, dl,
                         DAG, InVals);
}

/// LowerCallResult - Lower the result values of a call into the
/// appropriate copies out of appropriate physical registers.
///
SDValue
PIC18F4455TargetLowering::
   LowerCallResult(SDValue Chain, SDValue InFlag
                  , CallingConv::ID CallConv, bool isVarArg
                  , const SmallVectorImpl<ISD::InputArg> &Ins
                  , DebugLoc dl, SelectionDAG &DAG
                  , SmallVectorImpl<SDValue> &InVals) const {

  // Assign locations to each value returned by this call.
  SmallVector<CCValAssign, 16> RVLocs;
  CCState CCInfo(CallConv, isVarArg, getTargetMachine(),
                 RVLocs, *DAG.getContext());

  CCInfo.AnalyzeCallResult(Ins, RetCC_PIC18F4455);

  // Copy all of the result registers out of their specified physreg.
  for (unsigned i = 0; i != RVLocs.size(); ++i) {
    Chain = DAG.getCopyFromReg(Chain, dl, RVLocs[i].getLocReg(),
                               RVLocs[i].getValVT(), InFlag).getValue(1);
    InFlag = Chain.getValue(2);
    InVals.push_back(Chain.getValue(0));
  }

  return Chain;
}

SDValue
PIC18F4455TargetLowering::
   LowerReturn(SDValue Chain,
               CallingConv::ID CallConv, bool isVarArg,
               const SmallVectorImpl<ISD::OutputArg> &Outs,
               const SmallVectorImpl<SDValue> &OutVals,
               DebugLoc dl, SelectionDAG &DAG) const {

  // CCValAssign - represent the assignment of the return value to a location
  SmallVector<CCValAssign, 16> RVLocs;

  // CCState - Info about the registers and stack slot.
  CCState CCInfo(CallConv, isVarArg, getTargetMachine(),
                 RVLocs, *DAG.getContext());

  // Analize return values.
  CCInfo.AnalyzeReturn(Outs, RetCC_PIC18F4455);

  // If this is the first return lowered for this function, add the regs to the
  // liveout set for the function.
  if (DAG.getMachineFunction().getRegInfo().liveout_empty()) {
    for (unsigned i = 0; i != RVLocs.size(); ++i)
      if (RVLocs[i].isRegLoc())
        DAG.getMachineFunction().getRegInfo().addLiveOut(RVLocs[i].getLocReg());
  }

  // if there is one 8-bit constant value to return,
  //  use retlw to return that value
  unsigned NumRet = Outs.size();
  DEBUG(errs() << "siva: number of values to return = "
               << NumRet <<"\n");
  std::cout << "from std - siva number of values to return "
            << NumRet <<"\n";
  DAG.dump();
            
  if ((Outs.size() == 1) && (Outs[0].VT == MVT::i8)
      && (isa<ConstantSDNode>(OutVals[0].getNode()))){
   DEBUG(errs() << "siva: Outs.size == 1 "
                << "and Outs[0].VT  == MVT::i8"
                << "is constantnode = "
                << (isa<ConstantSDNode>(OutVals[0].getNode())) << "\n");
   return DAG.getNode(PIC18F4455ISD::RETLW, dl, MVT::Other, Chain
                     , OutVals[0]);
  }

  SDValue Flag;
  // Copy the result values into the output registers.
  for (unsigned i = 0; i != RVLocs.size(); ++i) {
    CCValAssign &VA = RVLocs[i];
    assert(VA.isRegLoc() && "Can only return in registers!");

    Chain = DAG.getCopyToReg(Chain, dl, VA.getLocReg(),
                             OutVals[i], Flag);

    // Guarantee that all emitted copies are stuck together,
    // avoiding something bad.
    Flag = Chain.getValue(1);
  }

  if (Flag.getNode())
    return DAG.getNode(PIC18F4455ISD::RET, dl, MVT::Other, Chain
                      , Flag);

  // Return Void
  return DAG.getNode(PIC18F4455ISD::RET, dl, MVT::Other, Chain);
}

void PIC18F4455TargetLowering::
GetDataAddress(DebugLoc dl, SDValue Callee, SDValue &Chain, 
               SDValue &DataAddr_Lo, SDValue &DataAddr_Hi,
               SelectionDAG &DAG) const {
   assert (Callee.getOpcode() == PIC18F4455ISD::PIC18F4455Connect
           && "Don't know what to do of such callee!!");
   SDValue ZeroOperand = DAG.getConstant(0, MVT::i8);
   SDValue SeqStart  = DAG.getCALLSEQ_START(Chain, ZeroOperand);
   Chain = getChain(SeqStart);
   SDValue OperFlag = getOutFlag(SeqStart); // To manage the data dependency

   // Get the Lo and Hi part of code address
   SDValue Lo = Callee.getOperand(0);
   SDValue Hi = Callee.getOperand(1);

   SDValue Data_Lo, Data_Hi;
   SDVTList Tys = DAG.getVTList(MVT::i8, MVT::Other, MVT::Flag);
   // Subtract 2 from Address to get the Lower part of DataAddress.
   SDVTList VTList = DAG.getVTList(MVT::i8, MVT::Flag);
   Data_Lo = DAG.getNode(ISD::SUBC, dl, VTList, Lo, 
                         DAG.getConstant(2, MVT::i8));
   SDValue Ops[3] = { Hi, DAG.getConstant(0, MVT::i8), Data_Lo.getValue(1)};
   Data_Hi = DAG.getNode(ISD::SUBE, dl, VTList, Ops, 3);
   SDValue PCLATH = DAG.getNode(PIC18F4455ISD::MTPCLATH, dl, MVT::i8, Data_Hi);
   Callee = DAG.getNode(PIC18F4455ISD::PIC18F4455Connect, dl, MVT::i8, Data_Lo, PCLATH);
   SDValue Call = DAG.getNode(PIC18F4455ISD::CALLW, dl, Tys, Chain, Callee,
                              OperFlag);
   Chain = getChain(Call);
   OperFlag = getOutFlag(Call);
   SDValue SeqEnd = DAG.getCALLSEQ_END(Chain, ZeroOperand, ZeroOperand,
                                       OperFlag);
   Chain = getChain(SeqEnd);
   OperFlag = getOutFlag(SeqEnd);

   // Low part of Data Address 
   DataAddr_Lo = DAG.getNode(PIC18F4455ISD::MTLO, dl, MVT::i8, Call, OperFlag);

   // Make the second call.
   SeqStart  = DAG.getCALLSEQ_START(Chain, ZeroOperand);
   Chain = getChain(SeqStart);
   OperFlag = getOutFlag(SeqStart); // To manage the data dependency

   // Subtract 1 from Address to get high part of data address.
   Data_Lo = DAG.getNode(ISD::SUBC, dl, VTList, Lo, 
                         DAG.getConstant(1, MVT::i8));
   SDValue HiOps[3] = { Hi, DAG.getConstant(0, MVT::i8), Data_Lo.getValue(1)};
   Data_Hi = DAG.getNode(ISD::SUBE, dl, VTList, HiOps, 3);
   PCLATH = DAG.getNode(PIC18F4455ISD::MTPCLATH, dl, MVT::i8, Data_Hi);

   // Use new Lo to make another CALLW
   Callee = DAG.getNode(PIC18F4455ISD::PIC18F4455Connect, dl, MVT::i8, Data_Lo, PCLATH);
   Call = DAG.getNode(PIC18F4455ISD::CALLW, dl, Tys, Chain, Callee, OperFlag);
   Chain = getChain(Call);
   OperFlag = getOutFlag(Call);
   SeqEnd = DAG.getCALLSEQ_END(Chain, ZeroOperand, ZeroOperand,
                                        OperFlag);
   Chain = getChain(SeqEnd);
   OperFlag = getOutFlag(SeqEnd);
   // Hi part of Data Address
   DataAddr_Hi = DAG.getNode(PIC18F4455ISD::MTHI, dl, MVT::i8, Call, OperFlag);
}

bool PIC18F4455TargetLowering::isDirectLoad(const SDValue Op) const {
  if (Op.getOpcode() == PIC18F4455ISD::PIC18F4455Load)
    if (Op.getOperand(1).getOpcode() == ISD::TargetGlobalAddress
     || Op.getOperand(1).getOpcode() == ISD::TargetExternalSymbol)
      return true;
  return false;
}

// NeedToConvertToMemOp - Returns true if one of the operands of the
// operation 'Op' needs to be put into memory. Also returns the
// operand no. of the operand to be converted in 'MemOp'. Remember, PIC18F4455 has 
// no instruction that can operation on two registers. Most insns take
// one register and one memory operand (addwf) / Constant (addlw).
bool PIC18F4455TargetLowering::NeedToConvertToMemOp(SDValue Op, unsigned &MemOp, 
                      SelectionDAG &DAG) const {
  // If one of the operand is a constant, return false.
  if (Op.getOperand(0).getOpcode() == ISD::Constant ||
      Op.getOperand(1).getOpcode() == ISD::Constant)
    return false;    

  // Return false if one of the operands is already a direct
  // load and that operand has only one use.
  if (isDirectLoad(Op.getOperand(0))) {
    if (Op.getOperand(0).hasOneUse()) {  
      // Legal and profitable folding check uses the NodeId of DAG nodes.
      // This NodeId is assigned by topological order. Therefore first 
      // assign topological order then perform legal and profitable check.
      // Note:- Though this ordering is done before begining with legalization,
      // newly added node during legalization process have NodeId=-1 (NewNode)
      // therefore before performing any check proper ordering of the node is
      // required.
      DAG.AssignTopologicalOrder();

      // Direct load operands are folded in binary operations. But before folding
      // verify if this folding is legal. Fold only if it is legal otherwise
      // convert this direct load to a separate memory operation.
      if (SelectionDAGISel::IsLegalToFold(Op.getOperand(0),
                                          Op.getNode(), Op.getNode(),
                                          CodeGenOpt::Default))
        return false;
      else 
        MemOp = 0;
    }
  }

  // For operations that are non-cummutative there is no need to check 
  // for right operand because folding right operand may result in 
  // incorrect operation. 
  if (! SelectionDAG::isCommutativeBinOp(Op.getOpcode()))
    return true;

  if (isDirectLoad(Op.getOperand(1))) {
    if (Op.getOperand(1).hasOneUse()) {
      // Legal and profitable folding check uses the NodeId of DAG nodes.
      // This NodeId is assigned by topological order. Therefore first 
      // assign topological order then perform legal and profitable check.
      // Note:- Though this ordering is done before begining with legalization,
      // newly added node during legalization process have NodeId=-1 (NewNode)
      // therefore before performing any check proper ordering of the node is
      // required.
      DAG.AssignTopologicalOrder();

      // Direct load operands are folded in binary operations. But before folding
      // verify if this folding is legal. Fold only if it is legal otherwise
      // convert this direct load to a separate memory operation.
      if (SelectionDAGISel::IsLegalToFold(Op.getOperand(1),
                                          Op.getNode(), Op.getNode(),
                                          CodeGenOpt::Default))
         return false;
      else 
         MemOp = 1; 
    }
  }
  return true;
}  

void PIC18F4455TargetLowering::InitReservedFrameCount(const Function *F,
                                                 SelectionDAG &DAG) const {
  MachineFunction &MF = DAG.getMachineFunction();
  PIC18F4455MachineFunctionInfo *FuncInfo = MF.getInfo<PIC18F4455MachineFunctionInfo>();

  unsigned NumArgs = F->arg_size();

  bool isVoidFunc = (F->getReturnType()->getTypeID() == Type::VoidTyID);

  if (isVoidFunc)
    FuncInfo->setReservedFrameCount(NumArgs);
  else
    FuncInfo->setReservedFrameCount(NumArgs + 1);
}

// Perform DAGCombine of PIC18F4455Load.
// FIXME - Need a more elaborate comment here.
SDValue PIC18F4455TargetLowering::
PerformPIC18F4455LoadCombine(SDNode *N, DAGCombinerInfo &DCI) const {
  SelectionDAG &DAG = DCI.DAG;
  SDValue Chain = N->getOperand(0); 
  if (N->hasNUsesOfValue(0, 0)) {
    DAG.ReplaceAllUsesOfValueWith(SDValue(N,1), Chain);
  }
  return SDValue();
}

// For all the functions with arguments some STORE nodes are generated 
// that store the argument on the frameindex. However in PIC18F4455 the arguments
// are passed on stack only. Therefore these STORE nodes are redundant. 
// To remove these STORE nodes will be removed in PerformStoreCombine 
//
// Currently this function is doint nothing and will be updated for removing
// unwanted store operations
SDValue PIC18F4455TargetLowering::
PerformStoreCombine(SDNode *N, DAGCombinerInfo &DCI) const {
  return SDValue(N, 0);
  /*
  // Storing an undef value is of no use, so remove it
  if (isStoringUndef(N, Chain, DAG)) {
    return Chain; // remove the store and return the chain
  }
  //else everything is ok.
  return SDValue(N, 0);
  */
}

SDValue PIC18F4455TargetLowering::PerformDAGCombine(SDNode *N, 
                                               DAGCombinerInfo &DCI) const {
  switch (N->getOpcode()) {
  case ISD::STORE:   
   return PerformStoreCombine(N, DCI); 
  case PIC18F4455ISD::PIC18F4455Load:   
    return PerformPIC18F4455LoadCombine(N, DCI);
  }
  return SDValue();
}

static PIC18F4455CC::CondCodes IntCCToPIC18F4455CC(ISD::CondCode CC) {
  switch (CC) {
     default: llvm_unreachable("Unknown condition code!");
     case ISD::SETNE:  return PIC18F4455CC::COND_NE;
     case ISD::SETEQ:  return PIC18F4455CC::COND_EQ;
     case ISD::SETGT:  return PIC18F4455CC::COND_GT;
     case ISD::SETGE:  return PIC18F4455CC::COND_GE;
     case ISD::SETLT:  return PIC18F4455CC::COND_LT;
     case ISD::SETLE:  return PIC18F4455CC::COND_LE;
  }
}

MachineBasicBlock *
PIC18F4455TargetLowering::
   EmitInstrWithCustomInserter( MachineInstr *MI
                              , MachineBasicBlock *BB ) const {
  const TargetInstrInfo &TII = *getTargetMachine().getInstrInfo();
  unsigned CC = (PIC18F4455CC::CondCodes)MI->getOperand(3).getImm();
  DebugLoc dl = MI->getDebugLoc();

  // To "insert" a SELECT_CC instruction, we actually have to insert the diamond
  // control-flow pattern.  The incoming instruction knows the destination vreg
  // to set, the condition code register to branch on, the true/false values to
  // select between, and a branch opcode to use.
  const BasicBlock *LLVM_BB = BB->getBasicBlock();
  MachineFunction::iterator It = BB;
  ++It;

  //  thisMBB:
  //  ...
  //   TrueVal = ...
  //   [f]bCC copy1MBB
  //   fallthrough --> copy0MBB
  MachineBasicBlock *thisMBB = BB;
  MachineFunction *F = BB->getParent();
  MachineBasicBlock *copy0MBB = F->CreateMachineBasicBlock(LLVM_BB);
  MachineBasicBlock *sinkMBB = F->CreateMachineBasicBlock(LLVM_BB);
  BuildMI(BB, dl, TII.get(PIC18F4455::pic18f4455brcond)).addMBB(sinkMBB).addImm(CC);
  F->insert(It, copy0MBB);
  F->insert(It, sinkMBB);

  // Transfer the remainder of BB and its successor edges to sinkMBB.
  sinkMBB->splice(sinkMBB->begin(), BB,
                  llvm::next(MachineBasicBlock::iterator(MI)),
                  BB->end());
  sinkMBB->transferSuccessorsAndUpdatePHIs(BB);

  // Next, add the true and fallthrough blocks as its successors.
  BB->addSuccessor(copy0MBB);
  BB->addSuccessor(sinkMBB);

  //  copy0MBB:
  //   %FalseValue = ...
  //   # fallthrough to sinkMBB
  BB = copy0MBB;

  // Update machine-CFG edges
  BB->addSuccessor(sinkMBB);

  //  sinkMBB:
  //   %Result = phi [ %FalseValue, copy0MBB ], [ %TrueValue, thisMBB ]
  //  ...
  BB = sinkMBB;
  BuildMI(*BB, BB->begin(), dl,
          TII.get(PIC18F4455::PHI), MI->getOperand(0).getReg())
    .addReg(MI->getOperand(2).getReg()).addMBB(copy0MBB)
    .addReg(MI->getOperand(1).getReg()).addMBB(thisMBB);

  MI->eraseFromParent();   // The pseudo instruction is gone now.
  return BB;
}

