include_directories( ${CMAKE_CURRENT_BINARY_DIR}/.. ${CMAKE_CURRENT_SOURCE_DIR}/.. )

add_llvm_library(LLVMPIC18F4455Info
  PIC18F4455TargetInfo.cpp
  )

add_dependencies(LLVMPIC18F4455Info PIC18F4455Table_gen)
