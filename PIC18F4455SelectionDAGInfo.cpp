//===-- PIC18F4455SelectionDAGInfo.cpp - PIC18F4455 SelectionDAG Info ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the PIC18F4455SelectionDAGInfo class.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "pic18f4455-selectiondag-info"
#include "PIC18F4455TargetMachine.h"
using namespace llvm;

PIC18F4455SelectionDAGInfo::PIC18F4455SelectionDAGInfo(const PIC18F4455TargetMachine &TM)
  : TargetSelectionDAGInfo(TM) {
}

PIC18F4455SelectionDAGInfo::~PIC18F4455SelectionDAGInfo() {
}
