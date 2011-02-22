//===- PIC18F4455InstrInfo.cpp - PIC18F4455 Instruction Information -----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source 
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the PIC18F4455 implementation of the TargetInstrInfo class.
//
//===----------------------------------------------------------------------===//

#include "PIC18F4455.h"
#include "PIC18F4455ABINames.h"
#include "PIC18F4455InstrInfo.h"
#include "PIC18F4455TargetMachine.h"
#include "PIC18F4455GenInstrInfo.inc"
#include "llvm/Function.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h" 
#include "llvm/ADT/StringExtras.h"
#include <cstdio>
#include <iostream>

using namespace llvm;

// FIXME: Add the subtarget support on this constructor.
PIC18F4455InstrInfo::PIC18F4455InstrInfo(PIC18F4455TargetMachine &tm)
  : TargetInstrInfoImpl(PIC18F4455Insts, array_lengthof(PIC18F4455Insts)),
    TM(tm), 
    RegInfo(*this, *TM.getSubtargetImpl()) {}


// isStoreToStackSlot - If the specified machine instruction is a
//    direct store to a stack slot, return the virtual or physical
//    register number of the source reg along with the FrameIndex of
//    the loaded stack slot. If not, return 0. This predicate must
//    return 0 if the instruction has any side effects other than
//    storing to the stack slot.
unsigned PIC18F4455InstrInfo::
   isStoreToStackSlot(const MachineInstr *MI, int &FrameIndex) const {
  if (MI->getOpcode() == PIC18F4455::movwf 
      && MI->getOperand(0).isReg()
      && MI->getOperand(1).isSymbol()) {
    FrameIndex = MI->getOperand(1).getIndex();
    return MI->getOperand(0).getReg();
  }
  return 0;
}

// isLoadFromStackSlot - If the specified machine instruction is a 
//    direct load from a stack slot, return the virtual or physical
//    register number of the dest reg along with the FrameIndex of the
//    stack slot. If not, return 0.  This predicate must return 0 if
//    the instruction has any side effects other than storing to the
//    stack slot.
unsigned PIC18F4455InstrInfo::
   isLoadFromStackSlot(const MachineInstr *MI, int &FrameIndex) const {
  if (MI->getOpcode() == PIC18F4455::movf 
      && MI->getOperand(0).isReg()
      && MI->getOperand(1).isSymbol()) {
    FrameIndex = MI->getOperand(1).getIndex();
    return MI->getOperand(0).getReg();
  }
  return 0;
}

void PIC18F4455InstrInfo::
   storeRegToStackSlot( MachineBasicBlock &MBB
                      , MachineBasicBlock::iterator MBBI
                      , unsigned SrcReg, bool isKill, int FI
                      , const TargetRegisterClass *RC
                      , const TargetRegisterInfo *TRI) const {
  DEBUG(errs() << "siva: storeRegToStackSlot begin\n");
  //const PIC18F4455TargetLowering *PTLI = TM.getTargetLowering();
  DebugLoc DL;
  if (MBBI != MBB.end()) DL = MBBI->getDebugLoc();

  const Function *Func = MBB.getParent()->getFunction();
  const std::string FuncName = Func->getName();

  // On the order of operands here: think "movwf SrcReg, tmp_slot, offset"
  if (RC == PIC18F4455::GR8RegisterClass) {
    //MachineFunction &MF = *MBB.getParent();
    //MachineRegisterInfo &RI = MF.getRegInfo();
    BuildMI(MBB, MBBI, DL, get(PIC18F4455::MOV8sr))
      .addReg(SrcReg, getKillRegState(isKill));
      //.addReg(SrcReg);
  }
  else if (RC == PIC18F4455::WRegisterClass) {
    //MachineFunction &MF = *MBB.getParent();
    //MachineRegisterInfo &RI = MF.getRegInfo();
    BuildMI(MBB, MBBI, DL, get(PIC18F4455::MOV8sw))
      .addReg(SrcReg, getKillRegState(isKill));
      //.addReg(SrcReg);
  }
  else llvm_unreachable("Can't store this register to stack slot");
  DEBUG(errs() << "siva: storeRegToStackSlot end\n");
}

void PIC18F4455InstrInfo::
   loadRegFromStackSlot( MachineBasicBlock &MBB
                       , MachineBasicBlock::iterator MBBI
                       , unsigned DestReg, int FI
                       , const TargetRegisterClass *RC
                       , const TargetRegisterInfo *TRI) const {
  DEBUG(errs() << "siva: loadRegFromStackSlot begin\n");
  //const PIC18F4455TargetLowering *PTLI = TM.getTargetLowering();
  DebugLoc DL;
  if (MBBI != MBB.end()) DL = MBBI->getDebugLoc();

  const Function *Func = MBB.getParent()->getFunction();
  const std::string FuncName = Func->getName();

  // On the order of operands here: think "movf FrameIndex, W".
  if (RC == PIC18F4455::GR8RegisterClass) {
    //MachineFunction &MF = *MBB.getParent();
    //MachineRegisterInfo &RI = MF.getRegInfo();
    BuildMI(MBB, MBBI, DL, get(PIC18F4455::MOV8rs)).addReg(DestReg);
  }
  else if (RC == PIC18F4455::WRegisterClass) {
    //MachineFunction &MF = *MBB.getParent();
    //MachineRegisterInfo &RI = MF.getRegInfo();
    BuildMI(MBB, MBBI, DL, get(PIC18F4455::MOV8ws)).addReg(DestReg);
  }
  else llvm_unreachable("Can't load this register from stack slot");
  DEBUG(errs() << "siva: loadRegToStackSlot end\n");
}

void PIC18F4455InstrInfo::
   copyPhysReg(MachineBasicBlock &MBB,
               MachineBasicBlock::iterator I, DebugLoc DL,
               unsigned DestReg, unsigned SrcReg,
               bool KillSrc) const {
  DEBUG(errs() << "siva: copyPhysReg begin\n");
  unsigned Opc;
  if (PIC18F4455::GR8RegClass.contains(DestReg, SrcReg))
    Opc = PIC18F4455::MOV8rr;
  else if (PIC18F4455::WRegClass.contains(DestReg)
           && PIC18F4455::GR8RegClass.contains(SrcReg))
    Opc = PIC18F4455::MOV8wr;
  else if (PIC18F4455::WRegClass.contains(SrcReg)
           && PIC18F4455::GR8RegClass.contains(DestReg))
    Opc = PIC18F4455::MOV8rw;
  else
    llvm_unreachable("Impossible reg-to-reg copy");

  BuildMI(MBB, I, DL, get(Opc), DestReg)
    .addReg(SrcReg, getKillRegState(KillSrc));
  DEBUG(errs() << "siva: copyPhysReg end\n");
}

/// InsertBranch - Insert a branch into the end of the specified
/// MachineBasicBlock.  This operands to this method are the same as those
/// returned by AnalyzeBranch.  This is invoked in cases where AnalyzeBranch
/// returns success and when an unconditional branch (TBB is non-null, FBB is
/// null, Cond is empty) needs to be inserted. It returns the number of
/// instructions inserted.
unsigned PIC18F4455InstrInfo::
InsertBranch(MachineBasicBlock &MBB, MachineBasicBlock *TBB, 
             MachineBasicBlock *FBB,
             const SmallVectorImpl<MachineOperand> &Cond,
             DebugLoc DL) const {
  // Shouldn't be a fall through.
  assert(TBB && "InsertBranch must not be told to insert a fallthrough");

  if (FBB == 0) { // One way branch.
    if (Cond.empty()) {
      // Unconditional branch?
      BuildMI(&MBB, DL, get(PIC18F4455::br_uncond)).addMBB(TBB);
    }
    return 1;
  }

  // FIXME: If the there are some conditions specified then conditional branch
  // should be generated.   
  // For the time being no instruction is being generated therefore
  // returning NULL.
  return 0;
}

bool PIC18F4455InstrInfo::AnalyzeBranch(MachineBasicBlock &MBB,
                                   MachineBasicBlock *&TBB,
                                   MachineBasicBlock *&FBB,
                                   SmallVectorImpl<MachineOperand> &Cond,
                                   bool AllowModify) const {
  MachineBasicBlock::iterator I = MBB.end();
  if (I == MBB.begin())
    return true;

  // Get the terminator instruction.
  --I;
  while (I->isDebugValue()) {
    if (I == MBB.begin())
      return true;
    --I;
  }
  // Handle unconditional branches. If the unconditional branch's target is
  // successor basic block then remove the unconditional branch. 
  if (I->getOpcode() == PIC18F4455::br_uncond  && AllowModify) {
    if (MBB.isLayoutSuccessor(I->getOperand(0).getMBB())) {
      TBB = 0;
      I->eraseFromParent();
    }
  }
  return true;
}
