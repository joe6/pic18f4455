//===- TableGen'erated file -------------------------------------*- C++ -*-===//
//
// Calling Convention Implementation Fragment
//
// Automatically generated file, do not edit!
//
//===----------------------------------------------------------------------===//

static bool CC_PIC18F4455(unsigned ValNo, EVT ValVT,
                          EVT LocVT, CCValAssign::LocInfo LocInfo,
                          ISD::ArgFlagsTy ArgFlags, CCState &State);
static bool RetCC_PIC18F4455(unsigned ValNo, EVT ValVT,
                             EVT LocVT, CCValAssign::LocInfo LocInfo,
                             ISD::ArgFlagsTy ArgFlags, CCState &State);


static bool CC_PIC18F4455(unsigned ValNo, EVT ValVT,
                          EVT LocVT, CCValAssign::LocInfo LocInfo,
                          ISD::ArgFlagsTy ArgFlags, CCState &State) {

  if (LocVT == MVT::i8) {
    if (unsigned Reg = State.AllocateReg(PIC18F4455::WREG)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::i8) {
    static const unsigned RegList1[] = {
      PIC18F4455::R0, PIC18F4455::R1, PIC18F4455::R2, PIC18F4455::R3, PIC18F4455::R4, PIC18F4455::R9
    };
    if (unsigned Reg = State.AllocateReg(RegList1, 6)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  unsigned Offset2 = State.AllocateStack(1, 1);
  State.addLoc(CCValAssign::getMem(ValNo, ValVT, Offset2, LocVT, LocInfo));
  return false;

  return true;  // CC didn't match.
}


static bool RetCC_PIC18F4455(unsigned ValNo, EVT ValVT,
                             EVT LocVT, CCValAssign::LocInfo LocInfo,
                             ISD::ArgFlagsTy ArgFlags, CCState &State) {

  if (LocVT == MVT::i8) {
    if (unsigned Reg = State.AllocateReg(PIC18F4455::WREG)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::i8) {
    static const unsigned RegList1[] = {
      PIC18F4455::R0, PIC18F4455::R1, PIC18F4455::R2, PIC18F4455::R3, PIC18F4455::R4, PIC18F4455::R9
    };
    if (unsigned Reg = State.AllocateReg(RegList1, 6)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  unsigned Offset2 = State.AllocateStack(1, 1);
  State.addLoc(CCValAssign::getMem(ValNo, ValVT, Offset2, LocVT, LocInfo));
  return false;

  return true;  // CC didn't match.
}
