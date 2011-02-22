// PIC18F4455InstrFormats.td - PIC18F4455 Instruction Formats tblgen//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open
// Source License. See LICENSE.TXT for details.
//
//------------------------------------------------------------------//

//------------------------------------------------------------------//
//  Describe PIC18F4455 instructions format
//
//  All the possible PIC18F4455 fields are:
//
//  opcode  - operation code.
//  f       - register file address.
//  d       - 1-bit destination specifier, file register or W
//  k       - 8/11 bit literals
//  b       - 3 bits bit num specifier
//  n       - 20-bit immediate value
//  s       - fast call or return mode
//  a       - access or banked
//
//------------------------------------------------------------------//

// Generic PIC18F4455 Format

class PIC18F4455WordInst<dag outs, dag ins, string asmstr, list<dag> pattern>
  : Instruction {
  field bits<16> Inst;

  let Namespace = "PIC18F4455";
  dag OutOperandList = outs;
  dag InOperandList = ins;
  let AsmString = asmstr;
  let Pattern = pattern;
}

class PIC18F4455DwordInst<dag outs, dag ins, string asmstr, list<dag> pattern>
  : Instruction {
  field bits<32> Inst;

  let Namespace = "PIC18F4455";
  dag OutOperandList = outs;
  dag InOperandList = ins;
  let AsmString = asmstr;
  let Pattern = pattern;
}

//=----------------------------------------------------------------=//
// Byte Oriented instruction class in PIC18F4455 : <|opcode|d|a|f|>
// opcode = 6 bits.
// d = direction = 1 bit.
// a = access or banked = 1 bit.
// f = file register address = 8 bits.
//=----------------------------------------------------------------=//

class ByteFormat<bits<6> opcode, dag outs, dag ins, string asmstr,
                 list<dag> pattern>
  :PIC18F4455WordInst<outs, ins, asmstr, pattern> {
  bits<1>  d;
  bits<1>  a;
  bits<8>  f;

  let Inst{15-10} = opcode;

  let Inst{9} = d;
  let Inst{8} = a;
  let Inst{7-0} = f; 
}

//=----------------------------------------------------------------=//
// Bit Oriented instruction class in PIC18F4455 : <|opcode|b|a|f|>
// opcode = 4 bits.
// b = bit specifier = 3 bits.
// a = access or banked = 1 bit.
// f = file register address = 8 bits.
//=----------------------------------------------------------------=//

class BitFormat<bits<4> opcode, dag outs, dag ins, string asmstr, 
                list<dag> pattern>
  : PIC18F4455WordInst<outs, ins, asmstr, pattern> {
  bits<3>  b;
  bits<1>  a;
  bits<8>  f;

  let Inst{15-12} = opcode;

  let Inst{11-9} = b;
  let Inst{8}   = a;
  let Inst{7-0} = f; 
}

//=----------------------------------------------------------------=//
// Literal Format instruction class in PIC18F4455 : <|opcode|k|>
// opcode = 8 bits
// k = literal = 8 bits
//=----------------------------------------------------------------=//

class LiteralFormat<bits<8> opcode, dag outs, dag ins, string asmstr, 
                    list<dag> pattern>
  : PIC18F4455WordInst<outs, ins, asmstr, pattern> {
  bits<8> k;
  
  let Inst{15-8} = opcode;

  let Inst{7-0} = k; 
}

//=----------------------------------------------------------------=//
// Control Format goto instruction class in PIC18F4455 : <|opcode|k|>
// opcode = 8 bits.
// n = jump address = 20 bits.
//=----------------------------------------------------------------=//

class ControlFormatGoto<bits<16> opcode, dag outs, dag ins,
                        string asmstr,  list<dag> pattern>
  : PIC18F4455DwordInst<outs, ins, asmstr, pattern> {
  bits<20> n;

  let Inst{31-16} = opcode;
   // TODO need to specify the constant here
  let Inst{19-0} = n; 
}

//=----------------------------------------------------------------=//
// Control Format call instruction class in PIC18F4455: <|opcode|s|k|>
// opcode = 8 bits.
// s = fast call or return mode = 1 bit
// n = jump address = 20 bits.
//=----------------------------------------------------------------=//

class ControlFormatCall<bits<15> opcode, dag outs, dag ins,
                        string asmstr,  list<dag> pattern>
  : PIC18F4455DwordInst<outs, ins, asmstr, pattern> {
  bits<20>  n;
  bits<1>   s;

  let Inst{31-17} = opcode;
  let Inst{16} = s;
   // TODO need to specify the constant here
  let Inst{19-0} = n; 
}

//=----------------------------------------------------------------=//
// Control Format bra instruction class in PIC18F4455 : <|opcode|k|>
// opcode = 5 bits.
// n = literal = 11 bits.
//=----------------------------------------------------------------=//

class ControlFormatBra<bits<5> opcode, dag outs, dag ins,
                       string asmstr,  list<dag> pattern>
  : PIC18F4455WordInst<outs, ins, asmstr, pattern> {
  bits<11>  n;

  let Inst{15-11} = opcode;
  let Inst{10-0} = n; 
}

//=----------------------------------------------------------------=//
// Control Format bc instruction class in PIC18F4455 : <|opcode|k|>
// opcode = 8 bits.
// n = literal = 8 bits.
//=----------------------------------------------------------------=//

class ControlFormatBc<bits<8> opcode, dag outs, dag ins,
                      string asmstr,  list<dag> pattern>
  : PIC18F4455WordInst<outs, ins, asmstr, pattern> {
  bits<8>  k;

  let Inst{15-8} = opcode;
  let Inst{7-0} = k; 
}

//=----------------------------------------------------------------=//
// Pseudo instruction class in PIC18F4455
//=----------------------------------------------------------------=//

class Pseudo<dag outs, dag ins, string asmstr, list<dag> pattern>
  : PIC18F4455WordInst<outs, ins, asmstr, pattern> {
   let Inst{13-6} = 0;
}
