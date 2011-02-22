//=- PIC18F4455RegisterInfo.td - PIC18F4455 Register defs - tblgen =//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open
// Source License. See LICENSE.TXT for details.
//
//=----------------------------------------------------------------=//

//=----------------------------------------------------------------=//
//  Declarations that describe the PIC18F4455 register file
//=----------------------------------------------------------------=//

class PIC18F4455Reg<string n> : Register<n> {
  let Namespace = "PIC18F4455";
}

// PIC18F4455 Registers.
def WREG    : PIC18F4455Reg<"WREG">;
def SPWR    : PIC18F4455Reg<"FSR0">;
def FPWR    : PIC18F4455Reg<"FSR1">;
def FSR2    : PIC18F4455Reg<"FSR2">;
def BS      : PIC18F4455Reg<"BS">;
def PCLATH  : PIC18F4455Reg<"PCLATH">;
def R0      : PIC18F4455Reg<"R0">;
def R1      : PIC18F4455Reg<"R1">;
def R2      : PIC18F4455Reg<"R2">;
def R3      : PIC18F4455Reg<"R3">;
def R4      : PIC18F4455Reg<"R4">;
def R5      : PIC18F4455Reg<"R5">;
def R6      : PIC18F4455Reg<"R6">;
def R7      : PIC18F4455Reg<"R7">;
def R8      : PIC18F4455Reg<"R8">;
def R9      : PIC18F4455Reg<"R9">;

def STATUS  : PIC18F4455Reg<"STATUS">;

// PIC18F4455 Register classes.
def W       : RegisterClass<"PIC18F4455", [i8],  8,  [WREG]>;
def BSR     : RegisterClass<"PIC18F4455", [i8],  8,  [BS]>;
def PCLATHR : RegisterClass<"PIC18F4455", [i8],  8,  [PCLATH]>;
def STATUSR : RegisterClass<"PIC18F4455", [i8],  8,  [STATUS]>;
def SPW     : RegisterClass<"PIC18F4455", [i16], 16, [SPWR]>;
def FPW     : RegisterClass<"PIC18F4455", [i16], 16, [FPWR]>;
def GR16    : RegisterClass<"PIC18F4455", [i16], 16, [FSR2]>;
def GR8     : RegisterClass<"PIC18F4455", [i8],  8
                           , [R0, R1, R2, R3, R4, R5, R6, R7, R8, R9]>; 


