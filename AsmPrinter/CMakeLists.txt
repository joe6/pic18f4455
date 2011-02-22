include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}/..
  ${CMAKE_CURRENT_SOURCE_DIR}/..
  )

add_llvm_library(LLVMPIC18F4455AsmPrinter
  PIC18F4455AsmPrinter.cpp
  )
add_dependencies(LLVMPIC18F4455AsmPrinter PIC18F4455CodeGenTable_gen)
