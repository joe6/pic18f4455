//===- TableGen'erated file -------------------------------------*- C++ -*-===//
//
// Target Instruction Descriptors
//
// Automatically generated file, do not edit!
//
//===----------------------------------------------------------------------===//

namespace llvm {

static const unsigned ImplicitList1[] = { PIC18F4455::SPWR, 0 };
static const TargetRegisterClass* Barriers1[] = { &PIC18F4455::SPWRegClass, NULL };
static const TargetRegisterClass* Barriers2[] = { &PIC18F4455::STATUSRRegClass, NULL };
static const unsigned ImplicitList2[] = { PIC18F4455::STATUS, 0 };
static const unsigned ImplicitList3[] = { PIC18F4455::WREG, 0 };

static const TargetOperandInfo OperandInfo2[] = { { -1, 0, 0 }, };
static const TargetOperandInfo OperandInfo3[] = { { -1, 0, 0 }, { -1, 0, 0 }, { -1, 0, 0 }, };
static const TargetOperandInfo OperandInfo4[] = { { -1, 0, 0 }, { -1, 0, ((0 << 16) | (1 << TOI::TIED_TO)) }, { -1, 0, 0 }, { -1, 0, 0 }, };
static const TargetOperandInfo OperandInfo5[] = { { -1, 0, 0 }, { -1, 0, 0 }, { -1, 0, 0 }, { -1, 0, 0 }, };
static const TargetOperandInfo OperandInfo6[] = { { -1, 0, 0 }, { -1, 0, 0 }, };
static const TargetOperandInfo OperandInfo7[] = { { PIC18F4455::GR8RegClassID, 0, 0 }, { PIC18F4455::GR8RegClassID, 0, ((0 << 16) | (1 << TOI::TIED_TO)) }, { -1, 0, 0 }, { -1, 0, 0 }, { -1, 0, 0 }, };
static const TargetOperandInfo OperandInfo8[] = { { PIC18F4455::GR8RegClassID, 0, 0 }, { -1, 0, 0 }, { -1, 0, 0 }, { -1, 0, 0 }, };
static const TargetOperandInfo OperandInfo9[] = { { PIC18F4455::GR8RegClassID, 0, 0 }, { PIC18F4455::GR8RegClassID, 0, 0 }, };
static const TargetOperandInfo OperandInfo10[] = { { PIC18F4455::GR8RegClassID, 0, 0 }, };
static const TargetOperandInfo OperandInfo11[] = { { PIC18F4455::GR8RegClassID, 0, 0 }, { PIC18F4455::WRegClassID, 0, 0 }, };
static const TargetOperandInfo OperandInfo12[] = { { PIC18F4455::WRegClassID, 0, 0 }, };
static const TargetOperandInfo OperandInfo13[] = { { PIC18F4455::WRegClassID, 0, 0 }, { PIC18F4455::GR8RegClassID, 0, 0 }, };
static const TargetOperandInfo OperandInfo14[] = { { PIC18F4455::GR8RegClassID, 0, 0 }, { PIC18F4455::GR8RegClassID, 0, 0 }, { PIC18F4455::GR8RegClassID, 0, 0 }, { -1, 0, 0 }, };
static const TargetOperandInfo OperandInfo15[] = { { PIC18F4455::GR8RegClassID, 0, 0 }, { PIC18F4455::GR8RegClassID, 0, ((0 << 16) | (1 << TOI::TIED_TO)) }, { -1, 0, 0 }, };
static const TargetOperandInfo OperandInfo16[] = { { PIC18F4455::GR16RegClassID, 0, 0 }, { PIC18F4455::GR16RegClassID, 0, 0 }, };
static const TargetOperandInfo OperandInfo17[] = { { PIC18F4455::GR8RegClassID, 0, 0 }, { PIC18F4455::GR16RegClassID, 0, 0 }, { -1, 0, 0 }, };
static const TargetOperandInfo OperandInfo18[] = { { PIC18F4455::WRegClassID, 0, 0 }, { -1, 0, 0 }, };
static const TargetOperandInfo OperandInfo19[] = { { PIC18F4455::WRegClassID, 0, 0 }, { -1, 0, 0 }, { -1, 0, 0 }, };
static const TargetOperandInfo OperandInfo20[] = { { PIC18F4455::GR16RegClassID, 0, 0 }, { -1, 0, 0 }, { -1, 0, 0 }, { -1, 0, 0 }, };
static const TargetOperandInfo OperandInfo21[] = { { PIC18F4455::GR16RegClassID, 0, 0 }, { PIC18F4455::GR16RegClassID, 0, ((0 << 16) | (1 << TOI::TIED_TO)) }, { PIC18F4455::GR8RegClassID, 0, 0 }, };
static const TargetOperandInfo OperandInfo22[] = { { PIC18F4455::GR16RegClassID, 0, 0 }, { PIC18F4455::GR8RegClassID, 0, 0 }, };
static const TargetOperandInfo OperandInfo23[] = { { PIC18F4455::PCLATHRRegClassID, 0, 0 }, { PIC18F4455::GR8RegClassID, 0, 0 }, };

static const TargetInstrDesc PIC18F4455Insts[] = {
  { 0,	0,	0,	0,	"PHI", 0|(1<<TID::Variadic)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, 0 },  // Inst #0 = PHI
  { 1,	0,	0,	0,	"INLINEASM", 0|(1<<TID::Variadic)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, 0 },  // Inst #1 = INLINEASM
  { 2,	1,	0,	0,	"PROLOG_LABEL", 0|(1<<TID::NotDuplicable)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo2 },  // Inst #2 = PROLOG_LABEL
  { 3,	1,	0,	0,	"EH_LABEL", 0|(1<<TID::NotDuplicable)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo2 },  // Inst #3 = EH_LABEL
  { 4,	1,	0,	0,	"GC_LABEL", 0|(1<<TID::NotDuplicable)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo2 },  // Inst #4 = GC_LABEL
  { 5,	0,	0,	0,	"KILL", 0|(1<<TID::Variadic), 0x0ULL, NULL, NULL, NULL, 0 },  // Inst #5 = KILL
  { 6,	3,	1,	0,	"EXTRACT_SUBREG", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo3 },  // Inst #6 = EXTRACT_SUBREG
  { 7,	4,	1,	0,	"INSERT_SUBREG", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo4 },  // Inst #7 = INSERT_SUBREG
  { 8,	1,	1,	0,	"IMPLICIT_DEF", 0|(1<<TID::Rematerializable)|(1<<TID::CheapAsAMove), 0x0ULL, NULL, NULL, NULL, OperandInfo2 },  // Inst #8 = IMPLICIT_DEF
  { 9,	4,	1,	0,	"SUBREG_TO_REG", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo5 },  // Inst #9 = SUBREG_TO_REG
  { 10,	3,	1,	0,	"COPY_TO_REGCLASS", 0|(1<<TID::CheapAsAMove), 0x0ULL, NULL, NULL, NULL, OperandInfo3 },  // Inst #10 = COPY_TO_REGCLASS
  { 11,	0,	0,	0,	"DBG_VALUE", 0|(1<<TID::Variadic)|(1<<TID::UnmodeledSideEffects)|(1<<TID::CheapAsAMove), 0x0ULL, NULL, NULL, NULL, 0 },  // Inst #11 = DBG_VALUE
  { 12,	1,	1,	0,	"REG_SEQUENCE", 0|(1<<TID::Variadic)|(1<<TID::CheapAsAMove), 0x0ULL, NULL, NULL, NULL, OperandInfo2 },  // Inst #12 = REG_SEQUENCE
  { 13,	2,	1,	0,	"COPY", 0|(1<<TID::CheapAsAMove), 0x0ULL, NULL, NULL, NULL, OperandInfo6 },  // Inst #13 = COPY
  { 14,	1,	0,	0,	"ADJCALLSTACKDOWN", 0, 0x0ULL, ImplicitList1, ImplicitList1, Barriers1, OperandInfo2 },  // Inst #14 = ADJCALLSTACKDOWN
  { 15,	2,	0,	0,	"ADJCALLSTACKUP", 0, 0x0ULL, ImplicitList1, ImplicitList1, Barriers1, OperandInfo6 },  // Inst #15 = ADJCALLSTACKUP
  { 16,	5,	1,	0,	"AndFW", 0|(1<<TID::MayLoad), 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo7 },  // Inst #16 = AndFW
  { 17,	4,	0,	0,	"AndWF", 0|(1<<TID::MayStore), 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo8 },  // Inst #17 = AndWF
  { 18,	1,	0,	0,	"CALL", 0|(1<<TID::Call)|(1<<TID::Variadic), 0x0ULL, NULL, NULL, NULL, OperandInfo2 },  // Inst #18 = CALL
  { 19,	2,	1,	0,	"MOV8rr", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo9 },  // Inst #19 = MOV8rr
  { 20,	1,	1,	0,	"MOV8rs", 0|(1<<TID::MayLoad)|(1<<TID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, ImplicitList1, Barriers1, OperandInfo10 },  // Inst #20 = MOV8rs
  { 21,	2,	1,	0,	"MOV8rw", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo11 },  // Inst #21 = MOV8rw
  { 22,	1,	0,	0,	"MOV8sr", 0|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, ImplicitList1, Barriers1, OperandInfo10 },  // Inst #22 = MOV8sr
  { 23,	1,	0,	0,	"MOV8sw", 0|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, ImplicitList1, Barriers1, OperandInfo12 },  // Inst #23 = MOV8sw
  { 24,	2,	1,	0,	"MOV8wr", 0|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo13 },  // Inst #24 = MOV8wr
  { 25,	1,	1,	0,	"MOV8ws", 0|(1<<TID::MayLoad)|(1<<TID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, ImplicitList1, Barriers1, OperandInfo12 },  // Inst #25 = MOV8ws
  { 26,	5,	1,	0,	"OrFW", 0|(1<<TID::MayLoad), 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo7 },  // Inst #26 = OrFW
  { 27,	4,	0,	0,	"OrWF", 0|(1<<TID::MayStore), 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo8 },  // Inst #27 = OrWF
  { 28,	1,	0,	0,	"Retlw", 0|(1<<TID::Return)|(1<<TID::Barrier)|(1<<TID::Terminator), 0x0ULL, ImplicitList3, NULL, NULL, OperandInfo2 },  // Inst #28 = Retlw
  { 29,	0,	0,	0,	"Return", 0|(1<<TID::Return)|(1<<TID::Barrier)|(1<<TID::Terminator), 0x0ULL, NULL, NULL, NULL, 0 },  // Inst #29 = Return
  { 30,	4,	1,	0,	"SELECT_CC_Int_ICC", 0|(1<<TID::UsesCustomInserter), 0x0ULL, NULL, NULL, NULL, OperandInfo14 },  // Inst #30 = SELECT_CC_Int_ICC
  { 31,	5,	1,	0,	"XOrFW", 0|(1<<TID::MayLoad), 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo7 },  // Inst #31 = XOrFW
  { 32,	4,	0,	0,	"XOrWF", 0|(1<<TID::MayStore), 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo8 },  // Inst #32 = XOrWF
  { 33,	5,	1,	0,	"addfw_1", 0|(1<<TID::MayLoad), 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo7 },  // Inst #33 = addfw_1
  { 34,	5,	1,	0,	"addfw_2", 0|(1<<TID::MayLoad), 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo7 },  // Inst #34 = addfw_2
  { 35,	5,	1,	0,	"addfwc", 0|(1<<TID::MayLoad), 0x0ULL, ImplicitList2, ImplicitList2, Barriers2, OperandInfo7 },  // Inst #35 = addfwc
  { 36,	3,	1,	0,	"addlw_1", 0, 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo15 },  // Inst #36 = addlw_1
  { 37,	3,	1,	0,	"addlw_2", 0, 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo15 },  // Inst #37 = addlw_2
  { 38,	3,	1,	0,	"addlwc", 0, 0x0ULL, ImplicitList2, ImplicitList2, Barriers2, OperandInfo15 },  // Inst #38 = addlwc
  { 39,	4,	0,	0,	"addwf_1", 0|(1<<TID::MayStore), 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo8 },  // Inst #39 = addwf_1
  { 40,	4,	0,	0,	"addwf_2", 0|(1<<TID::MayStore), 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo8 },  // Inst #40 = addwf_2
  { 41,	4,	0,	0,	"addwfc", 0|(1<<TID::MayStore), 0x0ULL, ImplicitList2, ImplicitList2, Barriers2, OperandInfo8 },  // Inst #41 = addwfc
  { 42,	3,	1,	0,	"andlw", 0, 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo15 },  // Inst #42 = andlw
  { 43,	1,	0,	0,	"br_uncond", 0|(1<<TID::Branch)|(1<<TID::Terminator), 0x0ULL, NULL, NULL, NULL, OperandInfo2 },  // Inst #43 = br_uncond
  { 44,	2,	1,	0,	"copy_fsr", 0|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo16 },  // Inst #44 = copy_fsr
  { 45,	2,	1,	0,	"copy_w", 0|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo9 },  // Inst #45 = copy_w
  { 46,	3,	1,	0,	"load_indirect", 0|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo17 },  // Inst #46 = load_indirect
  { 47,	4,	1,	0,	"movf", 0|(1<<TID::MayLoad), 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo8 },  // Inst #47 = movf
  { 48,	4,	1,	0,	"movf_1", 0|(1<<TID::MayLoad), 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo8 },  // Inst #48 = movf_1
  { 49,	4,	1,	0,	"movf_1_1", 0|(1<<TID::MayLoad), 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo8 },  // Inst #49 = movf_1_1
  { 50,	4,	1,	0,	"movf_2", 0|(1<<TID::MayLoad), 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo8 },  // Inst #50 = movf_2
  { 51,	2,	1,	0,	"movlw", 0|(1<<TID::Rematerializable), 0x0ULL, NULL, NULL, NULL, OperandInfo18 },  // Inst #51 = movlw
  { 52,	3,	1,	0,	"movlw_hi_1", 0|(1<<TID::Rematerializable), 0x0ULL, NULL, NULL, NULL, OperandInfo19 },  // Inst #52 = movlw_hi_1
  { 53,	3,	1,	0,	"movlw_hi_2", 0|(1<<TID::Rematerializable), 0x0ULL, NULL, NULL, NULL, OperandInfo19 },  // Inst #53 = movlw_hi_2
  { 54,	3,	1,	0,	"movlw_lo_1", 0|(1<<TID::Rematerializable), 0x0ULL, NULL, NULL, NULL, OperandInfo19 },  // Inst #54 = movlw_lo_1
  { 55,	3,	1,	0,	"movlw_lo_2", 0|(1<<TID::Rematerializable), 0x0ULL, NULL, NULL, NULL, OperandInfo19 },  // Inst #55 = movlw_lo_2
  { 56,	4,	0,	0,	"movwf", 0|(1<<TID::MayStore), 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #56 = movwf
  { 57,	4,	0,	0,	"movwf_1", 0|(1<<TID::MayStore), 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #57 = movwf_1
  { 58,	4,	0,	0,	"movwf_2", 0|(1<<TID::MayStore), 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #58 = movwf_2
  { 59,	3,	1,	0,	"orlw", 0, 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo15 },  // Inst #59 = orlw
  { 60,	2,	0,	0,	"pic18f4455brcond", 0|(1<<TID::Branch)|(1<<TID::Terminator), 0x0ULL, ImplicitList2, NULL, NULL, OperandInfo6 },  // Inst #60 = pic18f4455brcond
  { 61,	4,	1,	0,	"restore_fsr0", 0|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo20 },  // Inst #61 = restore_fsr0
  { 62,	4,	1,	0,	"restore_fsr1", 0|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo20 },  // Inst #62 = restore_fsr1
  { 63,	4,	0,	0,	"save_fsr0", 0|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo20 },  // Inst #63 = save_fsr0
  { 64,	4,	0,	0,	"save_fsr1", 0|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo20 },  // Inst #64 = save_fsr1
  { 65,	3,	1,	0,	"set_fsrhi", 0|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo21 },  // Inst #65 = set_fsrhi
  { 66,	2,	1,	0,	"set_fsrlo", 0|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo22 },  // Inst #66 = set_fsrlo
  { 67,	2,	1,	0,	"set_pclath", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo23 },  // Inst #67 = set_pclath
  { 68,	3,	0,	0,	"store_indirect", 0|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo17 },  // Inst #68 = store_indirect
  { 69,	5,	1,	0,	"subfw_1", 0|(1<<TID::MayLoad), 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo7 },  // Inst #69 = subfw_1
  { 70,	5,	1,	0,	"subfw_2", 0|(1<<TID::MayLoad), 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo7 },  // Inst #70 = subfw_2
  { 71,	5,	1,	0,	"subfw_cc", 0|(1<<TID::MayLoad)|(1<<TID::Terminator), 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo7 },  // Inst #71 = subfw_cc
  { 72,	5,	1,	0,	"subfwb", 0|(1<<TID::MayLoad), 0x0ULL, ImplicitList2, ImplicitList2, Barriers2, OperandInfo7 },  // Inst #72 = subfwb
  { 73,	3,	1,	0,	"sublw_1", 0, 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo15 },  // Inst #73 = sublw_1
  { 74,	3,	1,	0,	"sublw_2", 0, 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo15 },  // Inst #74 = sublw_2
  { 75,	3,	1,	0,	"sublw_3", 0, 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo15 },  // Inst #75 = sublw_3
  { 76,	3,	1,	0,	"sublw_4", 0, 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo15 },  // Inst #76 = sublw_4
  { 77,	3,	1,	0,	"sublw_5", 0, 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo15 },  // Inst #77 = sublw_5
  { 78,	3,	1,	0,	"sublw_6", 0, 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo15 },  // Inst #78 = sublw_6
  { 79,	3,	1,	0,	"sublw_cc", 0|(1<<TID::Terminator), 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo15 },  // Inst #79 = sublw_cc
  { 80,	4,	0,	0,	"subwf_1", 0|(1<<TID::MayStore), 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo8 },  // Inst #80 = subwf_1
  { 81,	4,	0,	0,	"subwf_2", 0|(1<<TID::MayStore), 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo8 },  // Inst #81 = subwf_2
  { 82,	4,	0,	0,	"subwf_cc", 0|(1<<TID::MayStore), 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo8 },  // Inst #82 = subwf_cc
  { 83,	4,	0,	0,	"subwfb", 0|(1<<TID::MayStore), 0x0ULL, ImplicitList2, ImplicitList2, Barriers2, OperandInfo8 },  // Inst #83 = subwfb
  { 84,	3,	1,	0,	"xorlw", 0, 0x0ULL, NULL, ImplicitList2, Barriers2, OperandInfo15 },  // Inst #84 = xorlw
};
} // End llvm namespace 
