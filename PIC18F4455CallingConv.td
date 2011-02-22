//=- PIC18F4455CallingConv.td - Calling Conventions  tablegen -----=//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//=----------------------------------------------------------------=//
// This describes the calling conventions for PIC18F4455 architecture.
//=----------------------------------------------------------------=//

//=----------------------------------------------------------------=//
// PIC18F4455 Return Value Calling Convention
//=----------------------------------------------------------------=//
def RetCC_PIC18F4455 : CallingConv<[
   // i8 are returned in registers R15B, R14B, R13B, R12B
   CCIfType<[i8], CCAssignToReg<[WREG]>>,
   CCIfType<[i8], CCAssignToReg<[ R0, R1, R2, R3, R4
                                //, R5, R6, R7, R8, R9 ]>>
                                , R9 ]>>
   , CCAssignToStack<1, 1>
]>;

//=----------------------------------------------------------------=//
// PIC18F4455 Argument Calling Conventions
//=----------------------------------------------------------------=//
def CC_PIC18F4455 : CallingConv<[
   // All arguments get passed in registers if there is space.
   CCIfType<[i8], CCAssignToReg<[WREG]>>,
   CCIfType<[i8], CCAssignToReg<[ R0, R1, R2, R3, R4
                                //, R5, R6, R7, R8, R9 ]>>
                                , R9 ]>>
   , CCAssignToStack<1, 1>
]>;
