//===--- ReplaceScopedPtrCheck.h - clang-tidy--------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_BOOST_REPLACE_SCOPED_PTR_H
#define LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_BOOST_REPLACE_SCOPED_PTR_H

#include "../ClangTidy.h"

namespace clang {
namespace tidy {
namespace boost {

/// FIXME: Write a short description.
///
/// For the user-facing documentation see:
/// http://clang.llvm.org/extra/clang-tidy/checks/boost-replace-scoped-ptr.html
class ReplaceScopedPtrCheck : public ClangTidyCheck {
public:
  ReplaceScopedPtrCheck(StringRef Name, ClangTidyContext *Context)
      : ClangTidyCheck(Name, Context) {}
  void registerMatchers(ast_matchers::MatchFinder *Finder) override;
  void check(const ast_matchers::MatchFinder::MatchResult &Result) override;
};

} // namespace boost
} // namespace tidy
} // namespace clang

#endif // LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_BOOST_REPLACE_SCOPED_PTR_H
