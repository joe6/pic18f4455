//===- PIC18F4455RegisterInfo.h - PIC18F4455 Register Information Impl ----*- C++ -*-===//
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

#ifndef PIC18F4455REGISTERINFO_H
#define PIC18F4455REGISTERINFO_H

#include "llvm/Target/TargetRegisterInfo.h"
#include "PIC18F4455GenRegisterInfo.h.inc"

namespace llvm {

// Forward Declarations.
  class PIC18F4455Subtarget;
  class TargetInstrInfo;

class PIC18F4455RegisterInfo : public PIC18F4455GenRegisterInfo {
  private:
    const TargetInstrInfo &TII;
    const PIC18F4455Subtarget &ST;
  
  public:
    PIC18F4455RegisterInfo( const TargetInstrInfo &tii
                          , const PIC18F4455Subtarget &st);


  //------------------------------------------------------
  // Pure virtual functions from TargetRegisterInfo
  //------------------------------------------------------

  // PIC18F4455 callee saved registers
  virtual const unsigned* 
  getCalleeSavedRegs(const MachineFunction *MF = 0) const;

  virtual BitVector getReservedRegs(const MachineFunction &MF) const;
  virtual bool hasFP(const MachineFunction &MF) const;

  virtual void eliminateFrameIndex(MachineBasicBlock::iterator MI,
                                   int SPAdj, RegScavenger *RS=NULL) const;

  void eliminateCallFramePseudoInstr(MachineFunction &MF,
                                     MachineBasicBlock &MBB,
                                     MachineBasicBlock::iterator I) const;

  virtual void emitPrologue(MachineFunction &MF) const;
  virtual void emitEpilogue(MachineFunction &MF, MachineBasicBlock &MBB) const;
  virtual int getDwarfRegNum(unsigned RegNum, bool isEH) const;
  virtual unsigned getFrameRegister(const MachineFunction &MF) const;
  virtual unsigned getRARegister() const;

};

} // end namespace llvm

#endif
