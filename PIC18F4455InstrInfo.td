//=- PIC18F4455InstrInfo.td - PIC18F4455 Instruction defs tblgen --=//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open
// Source License. See LICENSE.TXT for details.
//
//=----------------------------------------------------------------=//
//
// This file describes the PIC18F4455 instructions in TableGen format.
//
//=----------------------------------------------------------------=//

include "PIC18F4455InstrFormats.td"

//=----------------------------------------------------------------=//
// PIC18F4455 Specific Type Constraints.
//=----------------------------------------------------------------=//
class SDTCisI8<int OpNum> : SDTCisVT<OpNum, i8>;
class SDTCisI16<int OpNum> : SDTCisVT<OpNum, i16>;

//=----------------------------------------------------------------=//
// PIC18F4455 Specific Type Profiles.
//=----------------------------------------------------------------=//

// Generic type profiles for i8/i16 unary/binary operations.
// Taking one i8 or i16 and producing void.
def SDTI8VoidOp : SDTypeProfile<0, 1, [SDTCisI8<0>]>;
def SDTI16VoidOp : SDTypeProfile<0, 1, [SDTCisI16<0>]>;

// Taking one value and producing an output of same type.
def SDTI8UnaryOp : SDTypeProfile<1, 1, [ SDTCisSameAs<0, 1>
                                       , SDTCisI8<0> ]>;
def SDTI16UnaryOp : SDTypeProfile<1, 1, [ SDTCisSameAs<0, 1>
                                        , SDTCisI16<0> ]>;

// Taking two values and producing an output of same type.
def SDTI8BinOp : SDTypeProfile<1, 2, [ SDTCisSameAs<0, 1>
                                     , SDTCisSameAs<0, 2>
                                     , SDTCisI8<0> ]>;
def SDTI16BinOp : SDTypeProfile<1, 2, [ SDTCisSameAs<0, 1>
                                      , SDTCisSameAs<0, 2>
                                      , SDTCisI16<0> ]>;

// PIC18F4455ISD::CALL type prorile
// TODO are the 2 below instructions the same?
//def SDT_PIC18F4455call : SDTypeProfile<0, -1, [SDTCisPtrTy<0>]>;
def SDT_PIC18F4455call : SDTypeProfile<0, -1, [SDTCisVT<0, iPTR>]>;
// callw is an extended instruction, ignore it for now.
//def SDT_PIC18F4455callw : SDTypeProfile<1, -1, [SDTCisInt<0>]>;
def SDT_PIC18F4455retlw : SDTypeProfile<0, -1, [SDTCisI8<0>]>;
def SDT_PIC18F4455CallSeqStart : SDCallSeqStart<[SDTCisVT<0, i8>]>;
def SDT_PIC18F4455CallSeqEnd   :
   SDCallSeqEnd<[SDTCisVT<0, i8>, SDTCisVT<1, i8>]>;

// PIC18F4455ISD::BRCOND
def SDT_PIC18F4455Brcond: SDTypeProfile<0, 2, [ SDTCisVT<0, OtherVT>
                                              , SDTCisI8<1> ]>;

// PIC18F4455ISD::BRCOND
// TODO what does this do?
def SDT_PIC18F4455Selecticc: SDTypeProfile<1, 3, [ SDTCisI8<0>
                                                 , SDTCisSameAs<0, 1>
                                                 , SDTCisSameAs<0, 2>
                                                 , SDTCisSameAs<0, 3>
                                                 ]>;

//=----------------------------------------------------------------=//
// PIC18F4455 addressing modes matching via DAG.
//=----------------------------------------------------------------=//
def diraddr : ComplexPattern<i8, 1, "SelectDirectAddr", [], []>;

//=----------------------------------------------------------------=//
// PIC18F4455 Specific Node Definitions.
//=----------------------------------------------------------------=//
// Node to match PIC18F4455 call
def PIC18F4455call  :
   SDNode<"PIC18F4455ISD::CALL", SDT_PIC18F4455call
         , [SDNPHasChain, SDNPOutFlag, SDNPOptInFlag, SDNPVariadic]>;
/* ignore extended instructions 
def PIC18F4455callw : SDNode<"PIC18F4455ISD::CALLW"
                             , SDT_PIC18F4455callw
                             , [ SDNPHasChain
                               , SDNPOptInFlag
                               , SDNPOutFlag]>; */

def PIC18F4455callseq_start :
   SDNode<"ISD::CALLSEQ_START", SDT_PIC18F4455CallSeqStart
         , [SDNPHasChain, SDNPOutFlag]>;
def PIC18F4455callseq_end   :
   SDNode<"ISD::CALLSEQ_END", SDT_PIC18F4455CallSeqEnd
         , [SDNPHasChain, SDNPOptInFlag, SDNPOutFlag]>;

// Low 8-bits of GlobalAddress.
def PIC18F4455Lo : SDNode<"PIC18F4455ISD::Lo", SDTI8BinOp>;  

// High 8-bits of GlobalAddress.
def PIC18F4455Hi : SDNode<"PIC18F4455ISD::Hi", SDTI8BinOp>;

// The MTHI and MTLO nodes are used only to match them in the incoming
// DAG for replacement by corresponding set_fsrhi, set_fsrlo
// insntructions. These nodes are not used for defining any
// instructions.
def MTLO     : SDNode<"PIC18F4455ISD::MTLO", SDTI8UnaryOp>;
def MTHI     : SDNode<"PIC18F4455ISD::MTHI", SDTI8UnaryOp>;
def MTPCLATH : SDNode<"PIC18F4455ISD::MTPCLATH", SDTI8UnaryOp>;

// Node specific type profiles.
def SDT_PIC18F4455Load : SDTypeProfile<1, 3, [ SDTCisI8<0>
                                             , SDTCisSameAs<0, 1>
                                             , SDTCisSameAs<0, 2>
                                             , SDTCisSameAs<0, 3> ]>;

def SDT_PIC18F4455Store : SDTypeProfile<0, 4, [ SDTCisI8<0>
                                              , SDTCisSameAs<0, 1>
                                              , SDTCisSameAs<0, 2>
                                              , SDTCisSameAs<0, 3> ]>;

def SDT_PIC18F4455Connect : SDTypeProfile<1, 2, [ SDTCisI8<0>
                                                , SDTCisSameAs<0, 1>
                                                , SDTCisSameAs<0, 2>
                                                ]>;

// Node to match a direct store operation.
def PIC18F4455Store: SDNode<"PIC18F4455ISD::PIC18F4455Store"
                            , SDT_PIC18F4455Store
                            , [SDNPHasChain]>;
def PIC18F4455StWF : SDNode<"PIC18F4455ISD::PIC18F4455StWF"
                            , SDT_PIC18F4455Store
                            , [ SDNPHasChain
                              , SDNPInFlag
                              , SDNPOutFlag ]>;


// Node to match a direct load operation.
def PIC18F4455Load   : SDNode<"PIC18F4455ISD::PIC18F4455Load"
                              , SDT_PIC18F4455Load
                              , [SDNPHasChain]>;
def PIC18F4455LdArg  : SDNode<"PIC18F4455ISD::PIC18F4455LdArg"
                              , SDT_PIC18F4455Load
                              , [SDNPHasChain]>;
def PIC18F4455LdWF   : SDNode<"PIC18F4455ISD::PIC18F4455LdWF"
                              , SDT_PIC18F4455Load, [ SDNPHasChain
                                                    , SDNPInFlag
                                                    , SDNPOutFlag]>;
def PIC18F4455Connect: SDNode<"PIC18F4455ISD::PIC18F4455Connect"
                              , SDT_PIC18F4455Connect, []>;

// Node to match a comparison instruction.
def PIC18F4455Subcc : SDNode<"PIC18F4455ISD::SUBCC"
                             , SDTI8BinOp
                             , [SDNPOutFlag]>;

// Node to match a conditional branch.
def PIC18F4455Brcond : SDNode<"PIC18F4455ISD::BRCOND"
                              , SDT_PIC18F4455Brcond
                              , [ SDNPHasChain
                                , SDNPInFlag ]>;

def PIC18F4455Selecticc : SDNode<"PIC18F4455ISD::SELECT_ICC"
                                 , SDT_PIC18F4455Selecticc
                                 , [SDNPInFlag]>;

def PIC18F4455ret       : SDNode<"PIC18F4455ISD::RET"
                                 , SDTNone
                                 , [SDNPHasChain]>;

def PIC18F4455retlw     : SDNode<"PIC18F4455ISD::RETLW"
                                 , SDT_PIC18F4455retlw
                                 //, SDTNone
                                 , [SDNPHasChain]>;


//=----------------------------------------------------------------=//
// PIC18F4455 Operand Definitions.
//=----------------------------------------------------------------=//
def i8mem : Operand<i8>;
def brtarget: Operand<OtherVT>;

// Operand for printing out a condition code.
let PrintMethod = "printCCOperand" in
  def CCOp : Operand<i8>;

//=----------------------------------------------------------------=//
// PIC18F4455 Common Classes.
//=----------------------------------------------------------------=//

// W = W Op F : Load the value from F and do Op to W.
let Constraints = "$src = $dst", mayLoad = 1 in
class BinOpFW<bits<6> OpCode, string OpcStr, SDNode OpNode>:
  ByteFormat<OpCode, (outs GR8:$dst), ( ins GR8:$src
                                      , i8imm:$offset
                                      , i8mem:$ptrlo
                                      , i8imm:$ptrhi )
             , !strconcat(OpcStr, " $ptrlo + $offset, W")
             , [(set GR8:$dst, (OpNode GR8:$src
                                , ( PIC18F4455Load diraddr:$ptrlo
                                  , (i8 imm:$ptrhi)
                                  , (i8 imm:$offset))))]>;

// F = F Op W : Load the value from F, do op with W and store in F.
// This insn class is not marked as TwoAddress because the reg is
// being used as a source operand only. (Remember a TwoAddress insn
// needs a copy.)
let mayStore = 1 in
class BinOpWF<bits<6> OpCode, string OpcStr, SDNode OpNode>:
  ByteFormat<OpCode, (outs),
             ( ins GR8:$src , i8imm:$offset
              , i8mem:$ptrlo, i8imm:$ptrhi)
             , !strconcat(OpcStr, " $ptrlo + $offset, F")
             , [(PIC18F4455Store ( OpNode GR8:$src
                                  , (PIC18F4455Load diraddr:$ptrlo
                                     , (i8 imm:$ptrhi)
                                     , (i8 imm:$offset)))
                 , diraddr:$ptrlo
                 , (i8 imm:$ptrhi)
                 , (i8 imm:$offset))]>;

// W = W Op L : Do Op of L with W and place result in W.
let Constraints = "$src = $dst" in
class BinOpWL<bits<8> opcode, string OpcStr, SDNode OpNode> :
  LiteralFormat<opcode, (outs GR8:$dst)
                , (ins GR8:$src, i8imm:$literal)
                , !strconcat(OpcStr, " $literal")
                , [(set GR8:$dst, (OpNode GR8:$src
                                   , (i8 imm:$literal)))]>;

//=----------------------------------------------------------------=//
// PIC18F4455 Instructions.
//=----------------------------------------------------------------=//

// ADJCALLSTACKDOWN/UP implicitly use/def SP because they may be expanded
//    into a stack adjustment and the codegen must know that they may
//    modify the stack pointer before prolog-epilog rewriting occurs.
// Pessimistically assume ADJCALLSTACKDOWN / ADJCALLSTACKUP will become
//    sub / add which can clobber SRW.
// Pseudo-instructions.
let Defs = [SPWR], Uses = [SPWR] in {
   def ADJCALLSTACKDOWN : Pseudo<(outs), (ins i8imm:$amt)
   // movff $amt,POSTDEC0
                                 , "#ADJCALLSTACKDOWN"
                                 , [(PIC18F4455callseq_start timm:$amt)]>;

   def ADJCALLSTACKUP :
   // movff PREINC0,$amt
      Pseudo<(outs), (ins i8imm:$amt1, i8imm:$amt2) , "#ADJCALLSTACKUP"
            , [(PIC18F4455callseq_end timm:$amt1, timm:$amt2)]>;
}
let Defs = [SPWR], Uses = [SPWR], mayStore = 1 in {
   def MOV8sr : ByteFormat<0x0, (outs), (ins GR8:$src)
                          , "movff\t$src,POSTDEC0", []>;
   def MOV8sw : ByteFormat<0x0, (outs), (ins W:$src)
                          , "movwf\tPOSTDEC0", []>;
}
let Defs = [SPWR], Uses = [SPWR], mayLoad = 1 in {
   def MOV8rs : ByteFormat<0x0, (outs GR8:$dst), (ins)
                          , "movff\tPREINC0,$dst", []>;
   def MOV8ws : ByteFormat<0x0, (outs W:$dst), (ins)
                          , "movf\tPREINC0,W", []>;
}

//-----------------------------------
// Vaious movlw insn patterns.
//-----------------------------------
let isReMaterializable = 1 in {
   // Move 8-bit literal to W.
   def movlw : BitFormat<12, (outs W:WREG), (ins i8imm:$src)
                         , "movlw $src"
                         , [(set W:$dst, (i8 imm:$src))]>;

   // Move a Lo(TGA) to W.
   def movlw_lo_1 : BitFormat<12, (outs W:$dst), ( ins i8imm:$src
                                                   , i8imm:$src2)
                              , "movlw LOW(${src} + ${src2})"
                              , [(set W:$dst
                                  , (PIC18F4455Lo tglobaladdr:$src
                                     , imm:$src2 ))]>;

   // Move a Lo(TES) to W.
   def movlw_lo_2 : BitFormat<12, (outs W:$dst), ( ins i8imm:$src
                                                   , i8imm:$src2)
                              , "movlw LOW(${src} + ${src2})"
                              , [(set W:$dst
                                  , (PIC18F4455Lo texternalsym:$src
                                     , imm:$src2 ))]>;

   // Move a Hi(TGA) to W.
   def movlw_hi_1 : BitFormat<12, (outs W:$dst), (ins i8imm:$src
                                                        , i8imm:$src2)
                              , "movlw HIGH(${src} + ${src2})"
                              , [(set W:$dst
                                  , (PIC18F4455Hi tglobaladdr:$src
                                     , imm:$src2))]>;

   // Move a Hi(TES) to W.
   def movlw_hi_2 : BitFormat<12, (outs W:$dst), (ins i8imm:$src
                                                    , i8imm:$src2)
                              , "movlw HIGH(${src} + ${src2})"
                              , [(set W:$dst
                                  , (PIC18F4455Hi texternalsym:$src
                                     , imm:$src2))]>;
}

// FIXME: Provide proper encoding!
let neverHasSideEffects = 1 in {
   def MOV8rr  : ByteFormat<0x0, (outs GR8:$dst), (ins GR8:$src)
                           , "movff\t{$src, $dst}", []>;
   def MOV8rw  : ByteFormat<0x0, (outs GR8:$dst), (ins W:$src)
                           , "movwf\t{$dst},BANKED", []>;
}
def MOV8wr  : ByteFormat<0x0, (outs W:$dst), (ins GR8:$src)
                        , "movf\t{$src, $dst},BANKED", []>;

//-------------------
// FSR setting insns. 
//-------------------
// These insns are matched via a DAG replacement pattern.
def set_fsrlo: ByteFormat<0, (outs GR16:$fsr), (ins GR8:$val)
                          , "movwf ${fsr}L", []>;

let Constraints = "$src = $dst" in
def set_fsrhi: ByteFormat<0, (outs GR16:$dst)
                          , (ins GR16:$src, GR8:$val)
                          , "movwf ${dst}H", []>;

def set_pclath: ByteFormat<0, (outs PCLATHR:$dst)
                           , (ins GR8:$val)
                           , "movwf ${dst}"
                           , [(set PCLATHR:$dst
                               , (MTPCLATH GR8:$val))]>;

//----------------------------
// copyPhysReg 
// copyPhysReg insns. These are dummy. They should always be deleted
// by the optimizer and never be present in the final generated code.
// if they are, then we have to write correct macros for these insns.
//----------------------------
def copy_fsr: Pseudo<(outs GR16:$dst), (ins GR16:$src)
                      , "copy_fsr $dst, $src", []>;

def copy_w: Pseudo<(outs GR8:$dst), (ins GR8:$src)
                    , "copy_w $dst, $src", []>;

class SAVE_FSR<string OpcStr>:
  Pseudo<(outs)
         , (ins GR16:$src, i8imm:$offset, i8mem:$ptrlo, i8imm:$ptrhi)
         , !strconcat(OpcStr, " $ptrlo, $offset")
         , []>; 
 
def save_fsr0: SAVE_FSR<"save_fsr0">;
def save_fsr1: SAVE_FSR<"save_fsr1">;

class RESTORE_FSR<string OpcStr>:
  Pseudo<(outs GR16:$dst)
         , (ins i8imm:$offset, i8mem:$ptrlo, i8imm:$ptrhi)
         , !strconcat(OpcStr, " $ptrlo, $offset")
         , []>; 

def restore_fsr0: RESTORE_FSR<"restore_fsr0">;
def restore_fsr1: RESTORE_FSR<"restore_fsr1">;

//--------------------------
// Store to memory
//-------------------------

// Direct store.
// Input operands are: val = W, ptrlo = GA, offset = offset
//                     , ptrhi = banksel.
let mayStore = 1 in
class MOVWF_INSN<bits<6> OpCode, SDNode OpNodeDest, SDNode Op>:
  ByteFormat<0, (outs)
             , (ins GR8:$val, i8imm:$offset
                , i8mem:$ptrlo, i8imm:$ptrhi)
             , "movwf ${ptrlo} + ${offset}"
             , [(Op GR8:$val, OpNodeDest:$ptrlo
                 , (i8 imm:$ptrhi)
                 , (i8 imm:$offset))]>;

// Store W to a Global Address.
def movwf : MOVWF_INSN<0, tglobaladdr, PIC18F4455Store>;

// Store W to an External Symobol.
def movwf_1 : MOVWF_INSN<0, texternalsym, PIC18F4455Store>;

// Store with InFlag and OutFlag
// This is same as movwf_1 but has a flag. A flag is required to
// order the stores while passing the params to function.
def movwf_2 : MOVWF_INSN<0, texternalsym, PIC18F4455StWF>;

// Indirect store. Matched via a DAG replacement pattern.
def store_indirect : 
  ByteFormat<0, (outs)
             , (ins GR8:$val, GR16:$fsr, i8imm:$offset)
             , "movwi $offset[$fsr]"
             , []>;

//----------------------------
// Load from memory
//----------------------------
// Direct load.
// Input Operands are: ptrlo = GA, offset = offset, ptrhi = banksel.
// Output: dst = W
let Defs = [STATUS], mayLoad = 1 in
class MOVF_INSN<bits<6> OpCode, SDNode OpNodeSrc, SDNode Op>:
  ByteFormat<0, (outs GR8:$dst)
             , (ins i8imm:$offset, i8mem:$ptrlo, i8imm:$ptrhi)
             , "movf ${ptrlo} + ${offset}, W"
             , [(set GR8:$dst
                 , (Op OpNodeSrc:$ptrlo, (i8 imm:$ptrhi)
                 , (i8 imm:$offset)))]>;

// Load from a GA.
def movf : MOVF_INSN<0, tglobaladdr, PIC18F4455Load>;

// Load from an ES.
def movf_1 : MOVF_INSN<0, texternalsym, PIC18F4455Load>;
def movf_1_1 : MOVF_INSN<0, texternalsym, PIC18F4455LdArg>;

// Load with InFlag and OutFlag
// This is same as movf_1 but has a flag. A flag is required to 
// order the loads while copying the return value of a function.
def movf_2 : MOVF_INSN<0, texternalsym, PIC18F4455LdWF>;

// Indirect load. Matched via a DAG replacement pattern.
def load_indirect : 
  ByteFormat<0, (outs GR8:$dst)
             , (ins GR16:$fsr, i8imm:$offset)
             , "moviw $offset[$fsr]"
             , []>;

//-------------------------
// Bitwise operations patterns
//--------------------------
// W = W op [F]
let Defs = [STATUS] in {
def OrFW :  BinOpFW<0, "iorwf", or>;
def XOrFW : BinOpFW<0, "xorwf", xor>;
def AndFW : BinOpFW<0, "andwf", and>;

// F = W op [F]
def OrWF :  BinOpWF<0, "iorwf", or>;
def XOrWF : BinOpWF<0, "xorwf", xor>;
def AndWF : BinOpWF<0, "andwf", and>;

//-------------------------
// Various add/sub patterns.
//-------------------------

// W = W + [F]
def addfw_1: BinOpFW<0, "addwf", add>;
def addfw_2: BinOpFW<0, "addwf", addc>;

let Uses = [STATUS] in
def addfwc: BinOpFW<0, "addwfc", adde>;  // With Carry.

// F = W + [F]
def addwf_1: BinOpWF<0, "addwf", add>;
def addwf_2: BinOpWF<0, "addwf", addc>;
let Uses = [STATUS] in
def addwfc: BinOpWF<0, "addwfc", adde>;  // With Carry.
}

// W -= [F] ; load from F and sub the value from W.
let Constraints = "$src = $dst", mayLoad = 1 in
class SUBFW<bits<6> OpCode, string OpcStr, SDNode OpNode>:
  ByteFormat<OpCode, (outs GR8:$dst)
             , (ins GR8:$src, i8imm:$offset
                , i8mem:$ptrlo, i8imm:$ptrhi)
             , !strconcat(OpcStr, " $ptrlo + $offset, W")
             , [(set GR8:$dst, (OpNode (PIC18F4455Load diraddr:$ptrlo
                                        , (i8 imm:$ptrhi)
                                        , (i8 imm:$offset))
                                , GR8:$src))]>;
let Defs = [STATUS] in {
def subfw_1: SUBFW<0, "subwf", sub>;
def subfw_2: SUBFW<0, "subwf", subc>;

let Uses = [STATUS] in
def subfwb: SUBFW<0, "subwfb", sube>;  // With Borrow.

}
let Defs = [STATUS], isTerminator = 1 in
def subfw_cc: SUBFW<0, "subwf", PIC18F4455Subcc>;

// [F] -= W ; 
let mayStore = 1 in
class SUBWF<bits<6> OpCode, string OpcStr, SDNode OpNode>:
  ByteFormat<OpCode, (outs)
             , (ins GR8:$src, i8imm:$offset
                , i8mem:$ptrlo, i8imm:$ptrhi)
             , !strconcat(OpcStr, " $ptrlo + $offset")
             , [(PIC18F4455Store
                 (OpNode (PIC18F4455Load diraddr:$ptrlo
                          , (i8 imm:$ptrhi)
                          , (i8 imm:$offset))
                  , GR8:$src)
                 , diraddr:$ptrlo
                 , (i8 imm:$ptrhi)
                 , (i8 imm:$offset))]>;

let Defs = [STATUS] in {
def subwf_1: SUBWF<0, "subwf", sub>;
def subwf_2: SUBWF<0, "subwf", subc>;

let Uses = [STATUS] in
  def subwfb: SUBWF<0, "subwfb", sube>;  // With Borrow.

def subwf_cc: SUBWF<0, "subwf", PIC18F4455Subcc>;
}

// addlw 
let Defs = [STATUS] in {
def addlw_1 : BinOpWL<0, "addlw", add>;
def addlw_2 : BinOpWL<0, "addlw", addc>;

let Uses = [STATUS] in
// With Carry. (Assembler macro).
def addlwc : BinOpWL<0, "addlwc", adde>;

// bitwise operations involving a literal and w.
def andlw : BinOpWL<0, "andlw", and>;
def xorlw : BinOpWL<0, "xorlw", xor>;
def orlw  : BinOpWL<0, "iorlw", or>;
}

// sublw 
// W = C - W ; sub W from literal. (Without borrow).
let Constraints = "$src = $dst" in
class SUBLW<bits<8> opcode, string OpcStr, SDNode OpNode> :
  LiteralFormat<opcode, (outs GR8:$dst)
                , (ins GR8:$src, i8imm:$literal)
                , !strconcat(OpcStr, " $literal")
                , [(set GR8:$dst, (OpNode (i8 imm:$literal)
                                 , GR8:$src))]>;
// subwl 
// W = W - C ; sub literal from W  (Without borrow).
let Constraints = "$src = $dst" in
class SUBWL<bits<8> opcode, string OpcStr, SDNode OpNode> :
  LiteralFormat<opcode, (outs GR8:$dst)
                , (ins GR8:$src, i8imm:$literal)
                , !strconcat(OpcStr, " $literal")
                , [(set GR8:$dst, (OpNode GR8:$src
                                   , (i8 imm:$literal)))]>;

let Defs = [STATUS] in {
def sublw_1 : SUBLW<0, "sublw", sub>;
def sublw_2 : SUBLW<0, "sublw", subc>;
// With borrow (Assembler macro).
def sublw_3 : SUBLW<0, "sublwb", sube>;

// Assembler macro replace with addlw
def sublw_4 : SUBWL<0, "subwl", sub>;
// Assembler macro replace with addlw
def sublw_5 : SUBWL<0, "subwl", subc>;
// With borrow (Assembler macro).
def sublw_6 : SUBWL<0, "subwlb", sube>;
}
let Defs = [STATUS], isTerminator = 1 in 
def sublw_cc : SUBLW<0, "sublw", PIC18F4455Subcc>;

// Call instruction.
let isCall = 1
    //Defs = [WREG, SPWR, FPWR] in {
    in {
    def CALL: LiteralFormat<0x1, (outs), (ins i16imm:$function
                                              , variable_ops)
                            , "call\t$function"
                            , [(PIC18F4455call imm:$function)]>;
}
/* ignore extended instructions for now
let isCall = 1,
    Defs = [W, FSR0, FSR1] in {
    def CALL_1: LiteralFormat<0x1, (outs)
                              , (ins GR8:$func, PCLATHR:$pc)
                              , "callw"
                              , [(PIC18F4455call (PIC18F4455Connect
                                                   GR8:$func
                                                   , PCLATHR:$pc))]>;

let isCall = 1,
    Defs = [FSR0, FSR1] in {
    def CALLW: LiteralFormat<0x1, (outs GR8:$dest), 
                                  (ins GR8:$func, PCLATHR:$pc),
            "callw",
            [(set GR8:$dest, (PIC18F4455callw
                              (PIC18F4455Connect GR8:$func
                               , PCLATHR:$pc)))]>;
}
}*/

let Uses = [STATUS], isBranch = 1, isTerminator = 1, hasDelaySlot = 0 in
def pic18f4455brcond: ControlFormatBc<0x0, (outs)
                                    , (ins brtarget:$dst, CCOp:$cc)
                                    , "b$cc $dst"
                                    , [(PIC18F4455Brcond bb:$dst
                                        , imm:$cc)]>;

// Unconditional branch.
let isBranch = 1, isTerminator = 1, hasDelaySlot = 0 in
def br_uncond: ControlFormatBra<0x0, (outs), (ins brtarget:$dst)
                             , "goto $dst"
                             , [(br bb:$dst)]>;

// SELECT_CC_* - Used to implement the SELECT_CC DAG operation.
// Expanded after instruction selection into a branch sequence.
let usesCustomInserter = 1 in {
  def SELECT_CC_Int_ICC : Pseudo<(outs GR8:$dst), (ins GR8:$T, GR8:$F
                                                   , i8imm:$Cond)
                                 , "; SELECT_CC_Int_ICC PSEUDO!"
                                 , [(set GR8:$dst
                                     , (PIC18F4455Selecticc GR8:$T
                                        , GR8:$F, imm:$Cond))]>;
}


// Return insn.
let isTerminator = 1, isBarrier = 1, isReturn = 1 in
def Return : 
  ControlFormatBra<0, (outs), (ins), "return", [(PIC18F4455ret)]>;

// Retlw insn.
let isTerminator = 1, isBarrier = 1, isReturn = 1, Uses = [WREG] in
def Retlw : 
  LiteralFormat<0x1, (outs), (ins i8imm:$literal)
                , "retlw $literal"
                , [(PIC18F4455retlw (i8 imm:$literal))]>;

//=----------------------------------------------------------------=//
// PIC18F4455 Replacment Patterns.
//=----------------------------------------------------------------=//

// Identify an indirect store and select insns for it.
def : Pat<(PIC18F4455Store GR8:$val, (MTLO GR8:$loaddr)
                           , (MTHI GR8:$hiaddr)
                           , imm:$offset)
          , (store_indirect GR8:$val
              , (set_fsrhi (set_fsrlo GR8:$loaddr), GR8:$hiaddr)
              , imm:$offset)>;

def : Pat<(PIC18F4455StWF GR8:$val
                          , (MTLO GR8:$loaddr)
                          , (MTHI GR8:$hiaddr)
                          , imm:$offset)
          , (store_indirect GR8:$val
              , (set_fsrhi (set_fsrlo GR8:$loaddr), GR8:$hiaddr)
              , imm:$offset)>;

// Identify an indirect load and select insns for it.
def : Pat<(PIC18F4455Load ( MTLO GR8:$loaddr)
                          , (MTHI GR8:$hiaddr)
                          , imm:$offset)
          , (load_indirect (set_fsrhi (set_fsrlo GR8:$loaddr)
                                      , GR8:$hiaddr)
                            , imm:$offset)>;

def : Pat<(PIC18F4455LdWF ( MTLO GR8:$loaddr)
                          , (MTHI GR8:$hiaddr)
                          , imm:$offset)
          , (load_indirect  (set_fsrhi (set_fsrlo GR8:$loaddr)
                                       , GR8:$hiaddr)
                            , imm:$offset)>;

// calls
def : Pat<(PIC18F4455call (i16 tglobaladdr:$dst)),
          (CALL tglobaladdr:$dst)>;
def : Pat<(PIC18F4455call (i16 texternalsym:$dst)),
          (CALL texternalsym:$dst)>;

