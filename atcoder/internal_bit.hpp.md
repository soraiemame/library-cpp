---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: atcoder/convolution.hpp
    title: atcoder/convolution.hpp
  - icon: ':warning:'
    path: atcoder/lazysegtree.hpp
    title: atcoder/lazysegtree.hpp
  - icon: ':warning:'
    path: atcoder/segtree.hpp
    title: atcoder/segtree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/bigint/division.test.cpp
    title: test/bigint/division.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/bigint/multipication.test.cpp
    title: test/bigint/multipication.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/bigint/multipication2.test.cpp
    title: test/bigint/multipication2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/bigint/remainder.test.cpp
    title: test/bigint/remainder.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/internal_bit.hpp\"\n\n\n\n#ifdef _MSC_VER\n#include\
    \ <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n// @param\
    \ n `0 <= n`\n// @return minimum non-negative `x` s.t. `n <= 2**x`\nint ceil_pow2(int\
    \ n) {\n    int x = 0;\n    while ((1U << x) < (unsigned int)(n)) x++;\n    return\
    \ x;\n}\n\n// @param n `1 <= n`\n// @return minimum non-negative `x` s.t. `(n\
    \ & (1 << x)) != 0`\nint bsf(unsigned int n) {\n#ifdef _MSC_VER\n    unsigned\
    \ long index;\n    _BitScanForward(&index, n);\n    return index;\n#else\n   \
    \ return __builtin_ctz(n);\n#endif\n}\n\n}  // namespace internal\n\n}  // namespace\
    \ atcoder\n\n\n"
  code: "#ifndef ATCODER_INTERNAL_BITOP_HPP\n#define ATCODER_INTERNAL_BITOP_HPP 1\n\
    \n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace\
    \ internal {\n\n// @param n `0 <= n`\n// @return minimum non-negative `x` s.t.\
    \ `n <= 2**x`\nint ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) <\
    \ (unsigned int)(n)) x++;\n    return x;\n}\n\n// @param n `1 <= n`\n// @return\
    \ minimum non-negative `x` s.t. `(n & (1 << x)) != 0`\nint bsf(unsigned int n)\
    \ {\n#ifdef _MSC_VER\n    unsigned long index;\n    _BitScanForward(&index, n);\n\
    \    return index;\n#else\n    return __builtin_ctz(n);\n#endif\n}\n\n}  // namespace\
    \ internal\n\n}  // namespace atcoder\n\n#endif  // ATCODER_INTERNAL_BITOP_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/internal_bit.hpp
  requiredBy:
  - atcoder/lazysegtree.hpp
  - atcoder/segtree.hpp
  - atcoder/convolution.hpp
  timestamp: '2021-03-22 15:07:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/bigint/remainder.test.cpp
  - test/bigint/division.test.cpp
  - test/bigint/multipication2.test.cpp
  - test/bigint/multipication.test.cpp
documentation_of: atcoder/internal_bit.hpp
layout: document
redirect_from:
- /library/atcoder/internal_bit.hpp
- /library/atcoder/internal_bit.hpp.html
title: atcoder/internal_bit.hpp
---
