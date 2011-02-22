//=-- PIC18F4455ISelDAGToDAG.cpp - A dag to dag inst selector -----=//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source 
// License. See LICENSE.TXT for details.
//
//=----------------------------------------------------------------=//
//
// This file defines an instruction selector for the PIC18F4455 target.
//
//=----------------------------------------------------------------=//

#define DEBUG_TYPE "pic18f4455-isel"

#include "llvm/Support/ErrorHandling.h"
#include "PIC18F4455ISelDAGToDAG.h"
using namespace llvm;

/// createPIC18F4455ISelDag - This pass converts a legalized DAG into a
/// PIC18F4455-specific DAG, ready for instruction scheduling.
FunctionPass *llvm::createPIC18F4455ISelDag(PIC18F4455TargetMachine &TM) {
  return new PIC18F4455DAGToDAGISel(TM);
}


/// Select - Select instructions not customized! Used for
/// expanded, promoted and normal instructions.
SDNode* PIC18F4455DAGToDAGISel::Select(SDNode *N) {

  // Select the default instruction.
  SDNode *ResNode = SelectCode(N);

  return ResNode;
}


// SelectDirectAddr - Match a direct address for DAG. 
// A direct address could be a globaladdress or externalsymbol.
bool PIC18F4455DAGToDAGISel::SelectDirectAddr(SDNode *Op, SDValue N, 
                                      SDValue &Address) {
  // Return true if TGA or ES.
  if (N.getOpcode() == ISD::TargetGlobalAddress
      || N.getOpcode() == ISD::TargetExternalSymbol) {
    Address = N;
    return true;
  }

  return false;
}
