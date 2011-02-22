//===-- PIC18F4455TargetMachine.cpp - Define TargetMachine for PIC18F4455 -----------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source 
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Top-level implementation for the PIC18F4455 target.
//
//===----------------------------------------------------------------------===//

#include "PIC18F4455.h"
#include "PIC18F4455MCAsmInfo.h"
#include "PIC18F4455TargetMachine.h"
#include "llvm/PassManager.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/Target/TargetRegistry.h"

using namespace llvm;

extern "C" void LLVMInitializePIC18F4455Target() {
  // Register the target. Curretnly the codegen works for
  // enhanced pic18f4455 mid-range.
  RegisterTargetMachine<PIC18F4455TargetMachine> X(ThePIC18F4455Target);
  RegisterAsmInfo<PIC18F4455MCAsmInfo> A(ThePIC18F4455Target);
}


// PIC18F4455TargetMachine - Enhanced PIC18F4455 mid-range Machine. May also represent
// a Traditional Machine if 'Trad' is true.
PIC18F4455TargetMachine::PIC18F4455TargetMachine( const Target &T
                                                , const std::string &TT
                                                , const std::string &FS) :
  LLVMTargetMachine(T, TT),
  //Subtarget(TT, FS),
  DataLayout("e-p:16:8:8-i8:8:8-n8"), 
  InstrInfo(*this), TLInfo(*this), TSInfo(*this),
  FrameInfo(TargetFrameInfo::StackGrowsUp, 8, 0) { }


bool PIC18F4455TargetMachine::addInstSelector(PassManagerBase &PM,
                                         CodeGenOpt::Level OptLevel) {
  // Install an instruction selector.
  PM.add(createPIC18F4455ISelDag(*this));
  return false;
}

