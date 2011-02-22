//=- PIC18F4455.td - Describe the PIC18F4455 Target Machine -----------*- tblgen -*-==//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source 
// License. See LICENSE.TXT for details.
//
//=----------------------------------------------------------------=//
// This is the top level entry point for the PIC18F4455 target.
//=----------------------------------------------------------------=//

//=----------------------------------------------------------------=//
// Target-independent interfaces
//=----------------------------------------------------------------=//

include "llvm/Target/Target.td"

include "PIC18F4455RegisterInfo.td"
include "PIC18F4455InstrInfo.td"
include "PIC18F4455CallingConv.td"

//=----------------------------------------------------------------=//
// Subtarget Features. 
//=----------------------------------------------------------------=//
//def FeatureCooper : SubtargetFeature<"cooper", "IsCooper", "true",
//                                     "PIC18F4455 Cooper ISA Support">;
// no features
def FeatureCooper : SubtargetFeature<"cooper", "IsCooper", "true",
                                     "PIC16 Cooper ISA Support">;

//=----------------------------------------------------------------=//
// PIC18F4455 supported processors.
//=----------------------------------------------------------------=//

def : Processor<"generic", NoItineraries, []>;
def : Processor<"cooper", NoItineraries, [FeatureCooper]>;


def PIC18F4455InstrInfo   : InstrInfo;
def PIC18F4455InstPrinter : AsmWriter {
   string AsmWriterClassName  = "InstPrinter";
   }

def PIC18F4455 : Target {
   let InstructionSet = PIC18F4455InstrInfo;
//   let AssemblyWriters = [PIC18F4455InstPrinter];
   }

