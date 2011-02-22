##===- lib/Target/PIC18F4455/Makefile ---------------------------*- Makefile -*-===##
# 
#                     The LLVM Compiler Infrastructure
#
# This file is distributed under the University of Illinois Open Source 
# License. See LICENSE.TXT for details.
# 
##===----------------------------------------------------------------------===##

LEVEL = ../../..
LIBRARYNAME = LLVMPIC18F4455CodeGen
TARGET = PIC18F4455

# Make sure that tblgen is run, first thing.
BUILT_SOURCES = PIC18F4455GenRegisterInfo.h.inc PIC18F4455GenRegisterNames.inc \
		PIC18F4455GenRegisterInfo.inc PIC18F4455GenInstrNames.inc \
		PIC18F4455GenInstrInfo.inc    PIC18F4455GenAsmWriter.inc \
		PIC18F4455GenDAGISel.inc      PIC18F4455GenCallingConv.inc \
		PIC18F4455GenSubtarget.inc

DIRS = AsmPrinter TargetInfo PIC18F4455Passes

include $(LEVEL)/Makefile.common

