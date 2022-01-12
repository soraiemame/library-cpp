---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/inversion_number.hpp
    title: algorithm/inversion_number.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/fenwicktree.hpp
    title: atcoder/fenwicktree.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_type_traits.hpp
    title: atcoder/internal_type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D
  bundledCode: "#line 1 \"test/inversion_number.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 1 \"algorithm/inversion_number.hpp\"\
    \n\n\n\n#line 5 \"algorithm/inversion_number.hpp\"\n#include <algorithm>\n\n#line\
    \ 1 \"atcoder/fenwicktree.hpp\"\n\n\n\n#include <cassert>\n#line 6 \"atcoder/fenwicktree.hpp\"\
    \n\n#line 1 \"atcoder/internal_type_traits.hpp\"\n\n\n\n#line 5 \"atcoder/internal_type_traits.hpp\"\
    \n#include <numeric>\n#include <type_traits>\n\nnamespace atcoder {\n\nnamespace\
    \ internal {\n\n#ifndef _MSC_VER\ntemplate <class T>\nusing is_signed_int128 =\n\
    \    typename std::conditional<std::is_same<T, __int128_t>::value ||\n       \
    \                           std::is_same<T, __int128>::value,\n              \
    \                std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value ||\n                                  std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <class T>\nusing make_unsigned_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value,\n     \
    \                         __uint128_t,\n                              unsigned\
    \ __int128>;\n\ntemplate <class T>\nusing is_integral = typename std::conditional<std::is_integral<T>::value\
    \ ||\n                                                  is_signed_int128<T>::value\
    \ ||\n                                                  is_unsigned_int128<T>::value,\n\
    \                                              std::true_type,\n             \
    \                                 std::false_type>::type;\n\ntemplate <class T>\n\
    using is_signed_int = typename std::conditional<(is_integral<T>::value &&\n  \
    \                                               std::is_signed<T>::value) ||\n\
    \                                                    is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n\n#else\n\ntemplate <class T> using\
    \ is_integral = typename std::is_integral<T>;\n\ntemplate <class T>\nusing is_signed_int\
    \ =\n    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int =\n   \
    \ typename std::conditional<is_integral<T>::value &&\n                       \
    \           std::is_unsigned<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <class T>\n\
    using to_unsigned = typename std::conditional<is_signed_int<T>::value,\n     \
    \                                         std::make_unsigned<T>,\n           \
    \                                   std::common_type<T>>::type;\n\n#endif\n\n\
    template <class T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    \ntemplate <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 8 \"atcoder/fenwicktree.hpp\"\
    \n\nnamespace atcoder {\n\n// Reference: https://en.wikipedia.org/wiki/Fenwick_tree\n\
    template <class T> struct fenwick_tree {\n    using U = internal::to_unsigned_t<T>;\n\
    \n  public:\n    fenwick_tree() : _n(0) {}\n    explicit fenwick_tree(int n) :\
    \ _n(n), data(n) {}\n\n    void add(int p, T x) {\n        assert(0 <= p && p\
    \ < _n);\n        p++;\n        while (p <= _n) {\n            data[p - 1] +=\
    \ U(x);\n            p += p & -p;\n        }\n    }\n\n    T sum(int l, int r)\
    \ {\n        assert(0 <= l && l <= r && r <= _n);\n        return sum(r) - sum(l);\n\
    \    }\n\n  private:\n    int _n;\n    std::vector<U> data;\n\n    U sum(int r)\
    \ {\n        U s = 0;\n        while (r > 0) {\n            s += data[r - 1];\n\
    \            r -= r & -r;\n        }\n        return s;\n    }\n};\n\n}  // namespace\
    \ atcoder\n\n\n#line 8 \"algorithm/inversion_number.hpp\"\n\ntemplate<class T>\n\
    long long inversion_number(const std::vector<T> &V,bool compress = true){\n  \
    \  int n = V.size();\n    std::vector<T> vec = V;\n    if(compress){\n       \
    \ std::vector<T> zaatu = V;\n        std::sort(zaatu.begin(),zaatu.end());\n \
    \       for(T& a : vec)a = std::lower_bound(zaatu.begin(),zaatu.end(),a) - zaatu.begin();\n\
    \    }\n    atcoder::fenwick_tree<int> BIT(n);\n    long long ans = 0;\n    for(int\
    \ i = 0;i < n;i++){\n        ans = ans + i - BIT.sum(0,vec[i] + 1);\n        BIT.add(vec[i],1);\n\
    \    }\n    return ans;\n}\n\ntemplate<class T>\nlong long inversion_number(const\
    \ std::vector<T>& a,const std::vector<T>& b) {\n    assert(a.size() == b.size());\n\
    \    auto za = b;\n    auto ca = a,cb = b,sa = a,sb = b;\n    std::sort(sa.begin(),sa.end());\n\
    \    std::sort(sb.begin(),sb.end());\n    if(sa != sb)return -1;\n    std::sort(za.begin(),za.end());\n\
    \    for(T& x : ca)x = std::lower_bound(za.begin(),za.end(),x) - za.begin();\n\
    \    for(T& x : cb)x = std::lower_bound(za.begin(),za.end(),x) - za.begin();\n\
    \    int sz = za.size();\n    std::vector<std::vector<int>> ia(sz),ib(sz);\n \
    \   for(int i = 0;i < sz;i++)ia[ca[i]].push_back(i);\n    for(int i = 0;i < sz;i++)ib[cb[i]].push_back(i);\n\
    \    for(int i = 0;i < sz;i++){\n        for(int j = 0;j < int(ia[i].size());j++){\n\
    \            ca[ia[i][j]] = ib[i][j];\n        }\n    }\n    return inversion_number(ca,false);\n\
    }\n\n\n#line 7 \"test/inversion_number.test.cpp\"\n\nint main(){\n    int N;\n\
    \    std::cin >> N;\n    std::vector<int> vec(N);\n    for(int i = 0;i < N;i++)std::cin\
    \ >> vec[i];\n    std::cout << inversion_number(vec) << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../algorithm/inversion_number.hpp\"\
    \n\nint main(){\n    int N;\n    std::cin >> N;\n    std::vector<int> vec(N);\n\
    \    for(int i = 0;i < N;i++)std::cin >> vec[i];\n    std::cout << inversion_number(vec)\
    \ << \"\\n\";\n}"
  dependsOn:
  - algorithm/inversion_number.hpp
  - atcoder/fenwicktree.hpp
  - atcoder/internal_type_traits.hpp
  isVerificationFile: true
  path: test/inversion_number.test.cpp
  requiredBy: []
  timestamp: '2022-01-12 21:15:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/inversion_number.test.cpp
layout: document
redirect_from:
- /verify/test/inversion_number.test.cpp
- /verify/test/inversion_number.test.cpp.html
title: test/inversion_number.test.cpp
---
