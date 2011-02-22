//===-- PIC18F4455TargetMachine.h - Define TargetMachine for PIC18F4455 ---*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the PIC18F4455 specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===//


#ifndef PIC18F4455_TARGETMACHINE_H
#define PIC18F4455_TARGETMACHINE_H

#include "PIC18F4455InstrInfo.h"
#include "PIC18F4455ISelLowering.h"
#include "PIC18F4455SelectionDAGInfo.h"
#include "PIC18F4455RegisterInfo.h"
#include "PIC18F4455Subtarget.h"
#include "llvm/Target/TargetData.h"
#include "llvm/Target/TargetFrameInfo.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {

/// PIC18F4455TargetMachine
///
class PIC18F4455TargetMachine : public LLVMTargetMachine {
  PIC18F4455Subtarget        Subtarget;
  const TargetData      DataLayout;       // Calculates type size & alignment
  PIC18F4455InstrInfo        InstrInfo;
  PIC18F4455TargetLowering   TLInfo;
  PIC18F4455SelectionDAGInfo TSInfo;

  // PIC18F4455 does not have any call stack frame, therefore not having 
  // any PIC18F4455 specific FrameInfo class.
  TargetFrameInfo       FrameInfo;

public:
  PIC18F4455TargetMachine(const Target &T, const std::string &TT,
                          const std::string &FS );

  virtual const TargetFrameInfo *getFrameInfo() const { return &FrameInfo; }
  virtual const PIC18F4455InstrInfo *getInstrInfo() const  { return &InstrInfo; }
  virtual const TargetData *getTargetData() const     { return &DataLayout;}
  virtual const PIC18F4455Subtarget *getSubtargetImpl() const { return &Subtarget; }
 
  virtual const PIC18F4455RegisterInfo *getRegisterInfo() const { 
    return &(InstrInfo.getRegisterInfo()); 
  }

  virtual const PIC18F4455TargetLowering *getTargetLowering() const { 
    return &TLInfo;
  }

  virtual const PIC18F4455SelectionDAGInfo* getSelectionDAGInfo() const {
    return &TSInfo;
  }

  virtual bool addInstSelector(PassManagerBase &PM,
                               CodeGenOpt::Level OptLevel);
}; // PIC18F4455TargetMachine.

} // end namespace llvm

#endif
