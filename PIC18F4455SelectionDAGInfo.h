//===-- PIC18F4455SelectionDAGInfo.h - PIC18F4455 SelectionDAG Info -------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines the PIC18F4455 subclass for TargetSelectionDAGInfo.
//
//===----------------------------------------------------------------------===//

#ifndef PIC18F4455SELECTIONDAGINFO_H
#define PIC18F4455SELECTIONDAGINFO_H

#include "llvm/Target/TargetSelectionDAGInfo.h"

namespace llvm {

class PIC18F4455TargetMachine;

class PIC18F4455SelectionDAGInfo : public TargetSelectionDAGInfo {
public:
  explicit PIC18F4455SelectionDAGInfo(const PIC18F4455TargetMachine &TM);
  ~PIC18F4455SelectionDAGInfo();
};

}

#endif
