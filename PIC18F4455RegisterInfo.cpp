//===- PIC18F4455RegisterInfo.cpp - PIC18F4455 Register Information -----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source 
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the PIC18F4455 implementation of the TargetRegisterInfo class.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "pic18f4455-reg-info"

#include "PIC18F4455.h"
#include "PIC18F4455RegisterInfo.h"
#include "llvm/ADT/BitVector.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

PIC18F4455RegisterInfo::PIC18F4455RegisterInfo(const TargetInstrInfo &tii
                                          , const PIC18F4455Subtarget &st)
  : PIC18F4455GenRegisterInfo( PIC18F4455::ADJCALLSTACKDOWN
                              , PIC18F4455::ADJCALLSTACKUP)
                             , TII(tii)
                             , ST(st) {}

#include "PIC18F4455GenRegisterInfo.inc"

/// PIC18F4455 Callee Saved Registers
const unsigned* PIC18F4455RegisterInfo::
getCalleeSavedRegs(const MachineFunction *MF) const {
  static const unsigned CalleeSavedRegs[] = { 0 };
  return CalleeSavedRegs;
}

BitVector PIC18F4455RegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  BitVector Reserved(getNumRegs());
  return Reserved;
}

bool PIC18F4455RegisterInfo::hasFP(const MachineFunction &MF) const {
  return false;
}

void PIC18F4455RegisterInfo::
eliminateFrameIndex(MachineBasicBlock::iterator II, int SPAdj,
                    RegScavenger *RS) const
{ /* NOT YET IMPLEMENTED */ }

void PIC18F4455RegisterInfo::emitPrologue(MachineFunction &MF) const
{    /* NOT YET IMPLEMENTED */  }

void PIC18F4455RegisterInfo::
emitEpilogue(MachineFunction &MF, MachineBasicBlock &MBB) const
{    /* NOT YET IMPLEMENTED */  }

int PIC18F4455RegisterInfo::
getDwarfRegNum(unsigned RegNum, bool isEH) const {
  llvm_unreachable("Not keeping track of debug information yet!!");
  return -1;
}

unsigned PIC18F4455RegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  llvm_unreachable("PIC18F4455 Does not have any frame register");
  return 0;
}

unsigned PIC18F4455RegisterInfo::getRARegister() const {
  llvm_unreachable("PIC18F4455 Does not have any return address register");
  return 0;
}

// This function eliminates ADJCALLSTACKDOWN,
// ADJCALLSTACKUP pseudo instructions
void PIC18F4455RegisterInfo::
eliminateCallFramePseudoInstr(MachineFunction &MF, MachineBasicBlock &MBB,
                              MachineBasicBlock::iterator I) const {
  // Simply discard ADJCALLSTACKDOWN,
  // ADJCALLSTACKUP instructions.
  MBB.erase(I);
}

