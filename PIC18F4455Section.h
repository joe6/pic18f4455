//===- PIC18F4455Section.h - PIC18F4455-specific section representation -*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the PIC18F4455Section class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_PIC18F4455SECTION_H
#define LLVM_PIC18F4455SECTION_H

#include "llvm/MC/MCSection.h"
#include "llvm/GlobalVariable.h"
#include <vector>

namespace llvm {
  /// PIC18F4455Section - Represents a physical section in PIC18F4455 COFF.
  /// Contains data objects.
  ///
  class PIC18F4455Section : public MCSection {
    /// Name of the section to uniquely identify it.
    StringRef Name;

    /// User can specify an address at which a section should be placed. 
    /// Negative value here means user hasn't specified any. 
    StringRef Address; 

    /// Overlay information - Sections with same color can be overlaid on
    /// one another.
    int Color; 

    /// Total size of all data objects contained here.
    unsigned Size;
    
  public:
    /// Return the name of the section.
    StringRef getName() const { return Name; }

    /// Return the Address of the section.
    StringRef getAddress() const { return Address; }

    /// Return the Color of the section.
    int getColor() const { return Color; }
    void setColor(int color) { Color = color; }

    /// Return the size of the section.
    unsigned getSize() const { return Size; }
    void setSize(unsigned size) { Size = size; }

  };

} // end namespace llvm

#endif
