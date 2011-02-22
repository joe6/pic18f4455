//===-- PIC18F4455.h - Top-level interface for PIC18F4455 representation --*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source 
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the entry points for global functions defined in 
// the LLVM PIC18F4455 back-end.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_TARGET_PIC18F4455_H
#define LLVM_TARGET_PIC18F4455_H

#include "llvm/Target/TargetMachine.h"


namespace llvm {
  class PIC18F4455TargetMachine;
  class FunctionPass;
  class formatted_raw_ostream;

  FunctionPass *createPIC18F4455ISelDag(PIC18F4455TargetMachine &TM);

  extern Target ThePIC18F4455Target;

namespace PIC18F4455CC {
  // MSP430 specific condition code.
  // TODO add pic18 condition codes
  enum CondCodes {
    COND_EQ = 0,  // aka COND_Z
    COND_NE = 1,  // aka COND_NZ
    COND_GT = 2,  // aka COND_C
    COND_LT = 3,  // aka COND_NC
    COND_GE = 4,
    COND_LE = 5,

    COND_INVALID = -1
  };
}
  
} // end namespace llvm;

// Defines symbolic names for PIC18F4455 registers.  This defines a mapping from
// register name to register number.
#include "PIC18F4455GenRegisterNames.inc"

// Defines symbolic names for the PIC18F4455 instructions.
#include "PIC18F4455GenInstrNames.inc"

#endif
