//===-- PIC18F4455AsmPrinter.h - PIC18F4455 LLVM assembly writer ----------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains a printer that converts from our internal representation
// of machine-dependent LLVM code to PIC18F4455 assembly language.
//
//===----------------------------------------------------------------------===//

#ifndef PIC18F4455ASMPRINTER_H
#define PIC18F4455ASMPRINTER_H

#include "PIC18F4455.h"
#include "PIC18F4455TargetMachine.h"
#include "PIC18F4455DebugInfo.h"
#include "PIC18F4455MCAsmInfo.h"
#include "llvm/Analysis/DebugInfo.h"
#include "llvm/CodeGen/AsmPrinter.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Target/TargetMachine.h"
#include <list>
#include <set>
#include <string>

namespace llvm {
  class LLVM_LIBRARY_VISIBILITY PIC18F4455AsmPrinter : public AsmPrinter {
  public:
    explicit PIC18F4455AsmPrinter(TargetMachine &TM, MCStreamer &Streamer);
  private:
    virtual const char *getPassName() const {
      return "PIC18F4455 Assembly Printer";
    }
    
    bool runOnMachineFunction(MachineFunction &F);
    void printOperand(const MachineInstr *MI, int opNum, raw_ostream &O);
    void printCCOperand(const MachineInstr *MI, int opNum, raw_ostream &O);
    void printInstruction(const MachineInstr *MI, raw_ostream &O);
    static const char *getRegisterName(unsigned RegNo);

    void EmitInstruction(const MachineInstr *MI);
    void EmitFunctionDecls (Module &M);
    void EmitUndefinedVars (Module &M);
    void EmitDefinedVars (Module &M);
    void EmitIData (Module &M);
    void EmitUData (Module &M);
    void EmitAllAutos (Module &M);
    void EmitRomData (Module &M);
    void EmitSharedUdata(Module &M);
    void EmitUserSections (Module &M);
    void EmitFunctionFrame(MachineFunction &MF);
    void printLibcallDecls();
    void ColorAutoSection(const Function *F);
  protected:
    bool doInitialization(Module &M);
    bool doFinalization(Module &M);

    /// EmitGlobalVariable - Emit the specified global variable and its
    /// initializer to the output stream.
    virtual void EmitGlobalVariable(const GlobalVariable *GV) {
      // PIC18F4455 doesn't use normal hooks for this.
    }
    
  private:
    PIC18F4455DbgInfo DbgInfo;
    const PIC18F4455MCAsmInfo *PMAI;
    std::set<std::string> LibcallDecls; // Sorted & uniqued set of extern decls.
    std::vector<const GlobalVariable *> ExternalVarDecls;
    std::vector<const GlobalVariable *> ExternalVarDefs;
  };
} // end of namespace

#endif
