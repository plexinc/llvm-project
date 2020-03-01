set(LLVM_LINK_COMPONENTS support)

add_clang_library(clangTidyPlexModule
  AvoidStdCallOnceCheck.cpp
  PlexTidyModule.cpp

  LINK_LIBS
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  clangTidy
  clangTidyUtils
  clangTooling
  )
