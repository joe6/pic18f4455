//====- PIC18F4455MachineFuctionInfo.h - PIC18F4455 machine function info -*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares PIC18F4455-specific per-machine-function information.
//
//===----------------------------------------------------------------------===//

#ifndef PIC18F4455MACHINEFUNCTIONINFO_H
#define PIC18F4455MACHINEFUNCTIONINFO_H

#include "llvm/CodeGen/MachineFunction.h"

namespace llvm {

/// PIC18F4455MachineFunctionInfo - This class is derived from MachineFunction
/// private PIC18F4455 target-specific information for each MachineFunction.
class PIC18F4455MachineFunctionInfo : public MachineFunctionInfo {
  // The frameindexes generated for spill/reload are stack based.
  // This maps maintain zero based indexes for these FIs.
  std::map<unsigned, unsigned> FiTmpOffsetMap;
  unsigned TmpSize;

  // These are the frames for return value and argument passing 
  // These FrameIndices will be expanded to foo.frame external symbol
  // and all others will be expanded to foo.tmp external symbol.
  unsigned ReservedFrameCount;

public:
  PIC18F4455MachineFunctionInfo()
    : TmpSize(0), ReservedFrameCount(0) {}

  explicit PIC18F4455MachineFunctionInfo(MachineFunction &MF)
    : TmpSize(0), ReservedFrameCount(0) {}

  std::map<unsigned, unsigned> &getFiTmpOffsetMap() { return FiTmpOffsetMap; }

  unsigned getTmpSize() const { return TmpSize; }
  void setTmpSize(unsigned Size) { TmpSize = Size; }

  unsigned getReservedFrameCount() const { return ReservedFrameCount; }
  void setReservedFrameCount(unsigned Count) { ReservedFrameCount = Count; }
};

} // End llvm namespace

#endif
