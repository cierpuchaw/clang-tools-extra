// RUN: %check_clang_tidy %s boost-replace-scoped-ptr %t -- -- \
// RUN:   -std=c++11 -I %S/Inputs/boost-replace-scoped-ptr

#include "scoped_ptr.h"

// Test function return values (declaration)
boost::scoped_ptr<int> f1();
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: use std::unique_ptr instead of boost::scoped_ptr [boost-replace-scoped-ptr]

// Test function parameters
void f2(const boost::scoped_ptr<int>& p);
// CHECK-MESSAGES: :[[@LINE-1]]:22: warning: use std::unique_ptr


// Other scoped_ptrs, not in ns boost::

namespace testns {
template <class X> struct scoped_ptr {};
}

testns::scoped_ptr<int> nf1();
void nf2(const testns::scoped_ptr<int>& p);
void nf3(testns::scoped_ptr<int> p);
