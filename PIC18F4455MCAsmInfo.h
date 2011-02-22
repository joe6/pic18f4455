//=====-- PIC18F4455MCAsmInfo.h - PIC18F4455 asm properties -------------*- C++ -*--====//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source 
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the declaration of the PIC18F4455MCAsmInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef PIC18F4455TARGETASMINFO_H
#define PIC18F4455TARGETASMINFO_H

#include "llvm/MC/MCAsmInfo.h"

namespace llvm {
  class Target;
  class StringRef;

  class PIC18F4455MCAsmInfo : public MCAsmInfo {
    const char *RomData8bitsDirective;
    const char *RomData16bitsDirective;
    const char *RomData32bitsDirective;
  public:    
    PIC18F4455MCAsmInfo(const Target &T, StringRef TT);
    
    virtual const char *getDataASDirective(unsigned size, unsigned AS) const;
  };

} // namespace llvm

#endif
