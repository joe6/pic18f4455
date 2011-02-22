//===-- PIC18F4455TargetInfo.cpp - PIC18F4455 Target Implementation -----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "PIC18F4455.h"
#include "llvm/Module.h"
#include "llvm/Target/TargetRegistry.h"
using namespace llvm;

Target llvm::ThePIC18F4455Target;//, llvm::TheCooperTarget;

extern "C" void LLVMInitializePIC18F4455TargetInfo() { 
  RegisterTarget<Triple::pic18f4455>
   X( ThePIC18F4455Target
    , "pic18f4455"
    , "PIC18F4455 14-bit [experimental]");
}
