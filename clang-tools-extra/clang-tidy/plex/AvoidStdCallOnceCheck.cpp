//===--- AvoidStdCallOnceCheck.cpp - clang-tidy ---------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "AvoidStdCallOnceCheck.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

#include <stdio.h>

using namespace clang::ast_matchers;

namespace clang {
namespace tidy {
namespace plex {

void AvoidStdCallOnceCheck::registerMatchers(MatchFinder *Finder) {
  Finder->addMatcher(
    callExpr(
      callee(
        functionDecl(
          hasName("std::call_once")))
    ).bind("func"), this);
}

void AvoidStdCallOnceCheck::check(const MatchFinder::MatchResult &Result) {
  const auto *MatchedDecl = Result.Nodes.getNodeAs<CallExpr>("func");
  diag(MatchedDecl->getBeginLoc(),
    "Avoid using std::call_once. Use boost::call_once instead.");
}

} // namespace plex
} // namespace tidy
} // namespace clang
