//===--- ReplaceScopedPtrCheck.cpp - clang-tidy----------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "ReplaceScopedPtrCheck.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;

namespace clang {
namespace tidy {
namespace boost {

static const char ScopedPtrTokenId[] = "ScopedPtrTokenId";

void ReplaceScopedPtrCheck::registerMatchers(MatchFinder *Finder) {
  if (!getLangOpts().CPlusPlus11)
    return;

  const auto ScopedPtrDecl = recordDecl(hasName("::boost::scoped_ptr"));
  const auto ScopedPtrType = qualType(hasDeclaration(ScopedPtrDecl));
  const auto ScopedPtrTypeLoc =
      typeLoc(loc(qualType(ScopedPtrType, unless(elaboratedType()))))
          .bind(ScopedPtrTokenId);
  Finder->addMatcher(ScopedPtrTypeLoc, this);
}

void ReplaceScopedPtrCheck::check(const MatchFinder::MatchResult &Result) {
  const auto* TL = Result.Nodes.getNodeAs<TypeLoc>(ScopedPtrTokenId);
  if (!TL)
    llvm_unreachable("Bad Callback.");

  auto TSTL = TL->getAs<TemplateSpecializationTypeLoc>();
  if (TSTL.isNull())
    return;

  const SourceLocation Loc = TSTL.getTemplateNameLoc();
  diag(Loc, "use std::unique_ptr instead of boost::scoped_ptr");
}

} // namespace boost
} // namespace tidy
} // namespace clang
