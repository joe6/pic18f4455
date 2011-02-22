set(LLVM_TARGET_DEFINITIONS PIC18F4455.td)

tablegen(PIC18F4455GenRegisterInfo.h.inc -gen-register-desc-header)
tablegen(PIC18F4455GenRegisterNames.inc -gen-register-enums)
tablegen(PIC18F4455GenRegisterInfo.inc -gen-register-desc)
tablegen(PIC18F4455GenInstrNames.inc -gen-instr-enums)
tablegen(PIC18F4455GenInstrInfo.inc -gen-instr-desc)
tablegen(PIC18F4455GenAsmWriter.inc -gen-asm-writer)
tablegen(PIC18F4455GenDAGISel.inc -gen-dag-isel)
tablegen(PIC18F4455GenCallingConv.inc -gen-callingconv)
tablegen(PIC18F4455GenSubtarget.inc -gen-subtarget)

add_llvm_target(PIC18F4455CodeGen
  PIC18F4455DebugInfo.cpp
  PIC18F4455InstrInfo.cpp
  PIC18F4455ISelDAGToDAG.cpp
  PIC18F4455ISelLowering.cpp
  PIC18F4455MCAsmInfo.cpp
  PIC18F4455RegisterInfo.cpp
  PIC18F4455Section.cpp
  PIC18F4455Subtarget.cpp
  PIC18F4455TargetMachine.cpp
  PIC18F4455TargetObjectFile.cpp
  PIC18F4455SelectionDAGInfo.cpp
  )
