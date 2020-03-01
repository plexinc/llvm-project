//===------- PlexTidyModule.cpp - clang-tidy --------------------.--------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===---------------------------------------------------------------------===//

#include "../ClangTidy.h"
#include "../ClangTidyModule.h"
#include "../ClangTidyModuleRegistry.h"
#include "AvoidStdCallOnceCheck.h"

namespace clang {
namespace tidy {
namespace plex {

class PlexModule : public ClangTidyModule {
public:
  void addCheckFactories(ClangTidyCheckFactories &CheckFactories) override {
    CheckFactories.registerCheck<AvoidStdCallOnceCheck>(
        "plex-avoid-std-call-once");
  }
};

// Register the PlexModule using this statically initialized variable.
static ClangTidyModuleRegistry::Add<PlexModule> X("plex-module",
                                                    "Add Plex checks.");

} // namespace plex

// This anchor is used to force the linker to link in the generated object file
// and thus register the PlexModule.
volatile int PlexModuleAnchorSource = 0;

} // namespace tidy
} // namespace clang
