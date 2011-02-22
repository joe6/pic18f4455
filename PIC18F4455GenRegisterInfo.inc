//===- TableGen'erated file -------------------------------------*- C++ -*-===//
//
// Register Information Source Fragment
//
// Automatically generated file, do not edit!
//
//===----------------------------------------------------------------------===//

namespace llvm {

namespace {     // Register classes...
  // BSR Register Class...
  static const unsigned BSR[] = {
    PIC18F4455::BS, 
  };

  // FPW Register Class...
  static const unsigned FPW[] = {
    PIC18F4455::FPWR, 
  };

  // GR16 Register Class...
  static const unsigned GR16[] = {
    PIC18F4455::FSR2, 
  };

  // GR8 Register Class...
  static const unsigned GR8[] = {
    PIC18F4455::R0, PIC18F4455::R1, PIC18F4455::R2, PIC18F4455::R3, PIC18F4455::R4, PIC18F4455::R5, PIC18F4455::R6, PIC18F4455::R7, PIC18F4455::R8, PIC18F4455::R9, 
  };

  // PCLATHR Register Class...
  static const unsigned PCLATHR[] = {
    PIC18F4455::PCLATH, 
  };

  // SPW Register Class...
  static const unsigned SPW[] = {
    PIC18F4455::SPWR, 
  };

  // STATUSR Register Class...
  static const unsigned STATUSR[] = {
    PIC18F4455::STATUS, 
  };

  // W Register Class...
  static const unsigned W[] = {
    PIC18F4455::WREG, 
  };

  // BSRVTs Register Class Value Types...
  static const EVT BSRVTs[] = {
    MVT::i8, MVT::Other
  };

  // FPWVTs Register Class Value Types...
  static const EVT FPWVTs[] = {
    MVT::i16, MVT::Other
  };

  // GR16VTs Register Class Value Types...
  static const EVT GR16VTs[] = {
    MVT::i16, MVT::Other
  };

  // GR8VTs Register Class Value Types...
  static const EVT GR8VTs[] = {
    MVT::i8, MVT::Other
  };

  // PCLATHRVTs Register Class Value Types...
  static const EVT PCLATHRVTs[] = {
    MVT::i8, MVT::Other
  };

  // SPWVTs Register Class Value Types...
  static const EVT SPWVTs[] = {
    MVT::i16, MVT::Other
  };

  // STATUSRVTs Register Class Value Types...
  static const EVT STATUSRVTs[] = {
    MVT::i8, MVT::Other
  };

  // WVTs Register Class Value Types...
  static const EVT WVTs[] = {
    MVT::i8, MVT::Other
  };

}  // end anonymous namespace

namespace PIC18F4455 {   // Register class instances
  BSRClass	BSRRegClass;
  FPWClass	FPWRegClass;
  GR16Class	GR16RegClass;
  GR8Class	GR8RegClass;
  PCLATHRClass	PCLATHRRegClass;
  SPWClass	SPWRegClass;
  STATUSRClass	STATUSRRegClass;
  WClass	WRegClass;

  static const TargetRegisterClass* const NullRegClasses[] = { NULL };

  // BSR Register Class sub-classes...
  static const TargetRegisterClass* const BSRSubclasses[] = {
    NULL
  };

  // FPW Register Class sub-classes...
  static const TargetRegisterClass* const FPWSubclasses[] = {
    NULL
  };

  // GR16 Register Class sub-classes...
  static const TargetRegisterClass* const GR16Subclasses[] = {
    NULL
  };

  // GR8 Register Class sub-classes...
  static const TargetRegisterClass* const GR8Subclasses[] = {
    NULL
  };

  // PCLATHR Register Class sub-classes...
  static const TargetRegisterClass* const PCLATHRSubclasses[] = {
    NULL
  };

  // SPW Register Class sub-classes...
  static const TargetRegisterClass* const SPWSubclasses[] = {
    NULL
  };

  // STATUSR Register Class sub-classes...
  static const TargetRegisterClass* const STATUSRSubclasses[] = {
    NULL
  };

  // W Register Class sub-classes...
  static const TargetRegisterClass* const WSubclasses[] = {
    NULL
  };

  // BSR Register Class super-classes...
  static const TargetRegisterClass* const BSRSuperclasses[] = {
    NULL
  };

  // FPW Register Class super-classes...
  static const TargetRegisterClass* const FPWSuperclasses[] = {
    NULL
  };

  // GR16 Register Class super-classes...
  static const TargetRegisterClass* const GR16Superclasses[] = {
    NULL
  };

  // GR8 Register Class super-classes...
  static const TargetRegisterClass* const GR8Superclasses[] = {
    NULL
  };

  // PCLATHR Register Class super-classes...
  static const TargetRegisterClass* const PCLATHRSuperclasses[] = {
    NULL
  };

  // SPW Register Class super-classes...
  static const TargetRegisterClass* const SPWSuperclasses[] = {
    NULL
  };

  // STATUSR Register Class super-classes...
  static const TargetRegisterClass* const STATUSRSuperclasses[] = {
    NULL
  };

  // W Register Class super-classes...
  static const TargetRegisterClass* const WSuperclasses[] = {
    NULL
  };


BSRClass::BSRClass()  : TargetRegisterClass(BSRRegClassID, "BSR", BSRVTs, BSRSubclasses, BSRSuperclasses, NullRegClasses, NullRegClasses, 1, 1, 1, BSR, BSR + 1) {}

FPWClass::FPWClass()  : TargetRegisterClass(FPWRegClassID, "FPW", FPWVTs, FPWSubclasses, FPWSuperclasses, NullRegClasses, NullRegClasses, 2, 2, 1, FPW, FPW + 1) {}

GR16Class::GR16Class()  : TargetRegisterClass(GR16RegClassID, "GR16", GR16VTs, GR16Subclasses, GR16Superclasses, NullRegClasses, NullRegClasses, 2, 2, 1, GR16, GR16 + 1) {}

GR8Class::GR8Class()  : TargetRegisterClass(GR8RegClassID, "GR8", GR8VTs, GR8Subclasses, GR8Superclasses, NullRegClasses, NullRegClasses, 1, 1, 1, GR8, GR8 + 10) {}

PCLATHRClass::PCLATHRClass()  : TargetRegisterClass(PCLATHRRegClassID, "PCLATHR", PCLATHRVTs, PCLATHRSubclasses, PCLATHRSuperclasses, NullRegClasses, NullRegClasses, 1, 1, 1, PCLATHR, PCLATHR + 1) {}

SPWClass::SPWClass()  : TargetRegisterClass(SPWRegClassID, "SPW", SPWVTs, SPWSubclasses, SPWSuperclasses, NullRegClasses, NullRegClasses, 2, 2, 1, SPW, SPW + 1) {}

STATUSRClass::STATUSRClass()  : TargetRegisterClass(STATUSRRegClassID, "STATUSR", STATUSRVTs, STATUSRSubclasses, STATUSRSuperclasses, NullRegClasses, NullRegClasses, 1, 1, 1, STATUSR, STATUSR + 1) {}

WClass::WClass()  : TargetRegisterClass(WRegClassID, "W", WVTs, WSubclasses, WSuperclasses, NullRegClasses, NullRegClasses, 1, 1, 1, W, W + 1) {}
}

namespace {
  const TargetRegisterClass* const RegisterClasses[] = {
    &PIC18F4455::BSRRegClass,
    &PIC18F4455::FPWRegClass,
    &PIC18F4455::GR16RegClass,
    &PIC18F4455::GR8RegClass,
    &PIC18F4455::PCLATHRRegClass,
    &PIC18F4455::SPWRegClass,
    &PIC18F4455::STATUSRRegClass,
    &PIC18F4455::WRegClass,
  };


  // Number of hash collisions: 0
  const unsigned SubregHashTable[] = { PIC18F4455::NoRegister, PIC18F4455::NoRegister, 
PIC18F4455::NoRegister, PIC18F4455::NoRegister };
  const unsigned SubregHashTableSize = 2;


  // Number of hash collisions: 0
  const unsigned AliasesHashTable[] = { PIC18F4455::NoRegister, PIC18F4455::NoRegister, 
PIC18F4455::NoRegister, PIC18F4455::NoRegister };
  const unsigned AliasesHashTableSize = 2;


  // Register Alias Sets...
  const unsigned Empty_AliasSet[] = { 0 };


  // Register Sub-registers Sets...
  const unsigned Empty_SubRegsSet[] = { 0 };
  const unsigned Empty_SuperRegsSet[] = { 0 };

  const TargetRegisterDesc RegisterDescriptors[] = { // Descriptors
    { "NOREG",	0,	0,	0 },
    { "BS",	Empty_AliasSet,	Empty_SubRegsSet,	Empty_SuperRegsSet },
    { "FPWR",	Empty_AliasSet,	Empty_SubRegsSet,	Empty_SuperRegsSet },
    { "FSR2",	Empty_AliasSet,	Empty_SubRegsSet,	Empty_SuperRegsSet },
    { "PCLATH",	Empty_AliasSet,	Empty_SubRegsSet,	Empty_SuperRegsSet },
    { "R0",	Empty_AliasSet,	Empty_SubRegsSet,	Empty_SuperRegsSet },
    { "R1",	Empty_AliasSet,	Empty_SubRegsSet,	Empty_SuperRegsSet },
    { "R2",	Empty_AliasSet,	Empty_SubRegsSet,	Empty_SuperRegsSet },
    { "R3",	Empty_AliasSet,	Empty_SubRegsSet,	Empty_SuperRegsSet },
    { "R4",	Empty_AliasSet,	Empty_SubRegsSet,	Empty_SuperRegsSet },
    { "R5",	Empty_AliasSet,	Empty_SubRegsSet,	Empty_SuperRegsSet },
    { "R6",	Empty_AliasSet,	Empty_SubRegsSet,	Empty_SuperRegsSet },
    { "R7",	Empty_AliasSet,	Empty_SubRegsSet,	Empty_SuperRegsSet },
    { "R8",	Empty_AliasSet,	Empty_SubRegsSet,	Empty_SuperRegsSet },
    { "R9",	Empty_AliasSet,	Empty_SubRegsSet,	Empty_SuperRegsSet },
    { "SPWR",	Empty_AliasSet,	Empty_SubRegsSet,	Empty_SuperRegsSet },
    { "STATUS",	Empty_AliasSet,	Empty_SubRegsSet,	Empty_SuperRegsSet },
    { "WREG",	Empty_AliasSet,	Empty_SubRegsSet,	Empty_SuperRegsSet },
  };

  const char *const SubRegIndexTable[] = { "" };

}

unsigned PIC18F4455GenRegisterInfo::getSubReg(unsigned RegNo, unsigned Index) const {
  switch (RegNo) {
  default:
    return 0;
  };
  return 0;
}

unsigned PIC18F4455GenRegisterInfo::getSubRegIndex(unsigned RegNo, unsigned SubRegNo) const {
  switch (RegNo) {
  default:
    return 0;
  };
  return 0;
}

unsigned PIC18F4455GenRegisterInfo::composeSubRegIndices(unsigned IdxA, unsigned IdxB) const {
  switch (IdxA) {
  default:
    return IdxB;
  }
}

PIC18F4455GenRegisterInfo::PIC18F4455GenRegisterInfo(int CallFrameSetupOpcode, int CallFrameDestroyOpcode)
  : TargetRegisterInfo(RegisterDescriptors, 18, RegisterClasses, RegisterClasses+8,
                 SubRegIndexTable,
                 CallFrameSetupOpcode, CallFrameDestroyOpcode,
                 SubregHashTable, SubregHashTableSize,
                 AliasesHashTable, AliasesHashTableSize) {
}

int PIC18F4455GenRegisterInfo::getDwarfRegNumFull(unsigned RegNum, unsigned Flavour) const {
  switch (Flavour) {
  default:
    assert(0 && "Unknown DWARF flavour");
    return -1;
  };
}

} // End llvm namespace 
