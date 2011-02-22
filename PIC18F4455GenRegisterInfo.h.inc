//===- TableGen'erated file -------------------------------------*- C++ -*-===//
//
// Register Information Header Fragment
//
// Automatically generated file, do not edit!
//
//===----------------------------------------------------------------------===//

#include "llvm/Target/TargetRegisterInfo.h"
#include <string>

namespace llvm {

struct PIC18F4455GenRegisterInfo : public TargetRegisterInfo {
  explicit PIC18F4455GenRegisterInfo(int CallFrameSetupOpcode = -1, int CallFrameDestroyOpcode = -1);
  virtual int getDwarfRegNumFull(unsigned RegNum, unsigned Flavour) const;
  virtual int getDwarfRegNum(unsigned RegNum, bool isEH) const = 0;
  virtual bool needsStackRealignment(const MachineFunction &) const
     { return false; }
  unsigned getSubReg(unsigned RegNo, unsigned Index) const;
  unsigned getSubRegIndex(unsigned RegNo, unsigned SubRegNo) const;
  unsigned composeSubRegIndices(unsigned, unsigned) const;
};

namespace PIC18F4455 { // Register classes
  enum {
    BSRRegClassID = 0,
    FPWRegClassID = 1,
    GR16RegClassID = 2,
    GR8RegClassID = 3,
    PCLATHRRegClassID = 4,
    SPWRegClassID = 5,
    STATUSRRegClassID = 6,
    WRegClassID = 7
  };

  struct BSRClass : public TargetRegisterClass {
    BSRClass();
  };
  extern BSRClass	BSRRegClass;
  static TargetRegisterClass * const BSRRegisterClass = &BSRRegClass;
  struct FPWClass : public TargetRegisterClass {
    FPWClass();
  };
  extern FPWClass	FPWRegClass;
  static TargetRegisterClass * const FPWRegisterClass = &FPWRegClass;
  struct GR16Class : public TargetRegisterClass {
    GR16Class();
  };
  extern GR16Class	GR16RegClass;
  static TargetRegisterClass * const GR16RegisterClass = &GR16RegClass;
  struct GR8Class : public TargetRegisterClass {
    GR8Class();
  };
  extern GR8Class	GR8RegClass;
  static TargetRegisterClass * const GR8RegisterClass = &GR8RegClass;
  struct PCLATHRClass : public TargetRegisterClass {
    PCLATHRClass();
  };
  extern PCLATHRClass	PCLATHRRegClass;
  static TargetRegisterClass * const PCLATHRRegisterClass = &PCLATHRRegClass;
  struct SPWClass : public TargetRegisterClass {
    SPWClass();
  };
  extern SPWClass	SPWRegClass;
  static TargetRegisterClass * const SPWRegisterClass = &SPWRegClass;
  struct STATUSRClass : public TargetRegisterClass {
    STATUSRClass();
  };
  extern STATUSRClass	STATUSRRegClass;
  static TargetRegisterClass * const STATUSRRegisterClass = &STATUSRRegClass;
  struct WClass : public TargetRegisterClass {
    WClass();
  };
  extern WClass	WRegClass;
  static TargetRegisterClass * const WRegisterClass = &WRegClass;
} // end of namespace PIC18F4455

} // End llvm namespace 
