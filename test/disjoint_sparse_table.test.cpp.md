---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/disjoint_sparse_table.hpp
    title: data-structure/disjoint_sparse_table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/disjoint_sparse_table.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/static_range_sum\"\n\n#include <iostream>\n#include\
    \ <vector>\n\n#line 1 \"data-structure/disjoint_sparse_table.hpp\"\n\n\n\n#line\
    \ 5 \"data-structure/disjoint_sparse_table.hpp\"\n#include <cassert>\n\ntemplate<class\
    \ T,T (*op)(T,T)>\nstruct DisjointSparseTable{\nprivate:\n    int _n,log,sz;\n\
    \    std::vector<std::vector<T>> table;\n    static int msb(int x){\n    #ifdef\
    \ __has_builtin\n        return 31 ^ __builtin_clz(x);\n    #else\n        int\
    \ res = 0;\n        if(x >> 16){\n            res += 16;x >>= 16;\n        }\n\
    \        if(x >> 8){\n            res += 8;x >>= 8;\n        }\n        if(x >>\
    \ 4){\n            res += 4;x >>= 4;\n        }\n        if(x >> 2){\n       \
    \     res += 2;x >>= 2;\n        }\n        return res + (x >> 1);\n    #endif\n\
    \    }\n    void build(const std::vector<T>& dat){\n        int w = sz;\n    \
    \    for(int lv = 0;lv < log;lv++){\n            int l = 0,r = w;\n          \
    \  for(;l < sz;l += w,r += w){\n                int m = (l + r) >> 1;\n\n    \
    \            table[lv][m] = dat[m];\n                for(int i = m + 1;i < r;i++)table[lv][i]\
    \ = op(table[lv][i - 1],dat[i]);\n\n                table[lv][m - 1] = dat[m -\
    \ 1];\n                for(int i = m - 2;i >= l;i--)table[lv][i] = op(table[lv][i\
    \ + 1],dat[i]);\n            }\n            w >>= 1;\n        }\n    }\n\npublic:\n\
    \    DisjointSparseTable(const std::vector<T>& dat){\n        _n = dat.size();\n\
    \        sz = 1;\n        log = 0;\n        while(sz < _n)sz <<= 1,log++;\n  \
    \      table = std::vector<std::vector<T>>(log,std::vector<T>(sz));\n        std::vector<T>\
    \ _dat = dat;\n        _dat.resize(sz);\n        if(log)build(_dat);\n       \
    \ else table = std::vector<std::vector<T>>(1,dat);\n    }\n    // [l,r)\n    T\
    \ query(int l,int r)const{\n        assert(0 <= l && l < r && r <= _n);\n    \
    \    r--;\n        if(l == r)return table.back()[l];\n        int clz = msb(l\
    \ ^ r);\n        int lev = log - clz - 1;\n        T res = op(table[lev][l],table[lev][r]);\n\
    \        return res;\n    }\n    inline T operator[](int k)const{\n        assert(k\
    \ < _n);\n        return table.back()[k];\n    }\n};\n\n\n#line 7 \"test/disjoint_sparse_table.test.cpp\"\
    \n\nlong long op(long long a,long long b){return a + b;}\n\nint main(){\n    int\
    \ N,Q;\n    std::cin >> N >> Q;\n    std::vector<long long> vec(N);\n    for(int\
    \ i = 0;i < N;i++)std::cin >> vec[i];\n    DisjointSparseTable<long long,op> dst(vec);\n\
    \    for(int i = 0;i < Q;i++){\n        int l,r;\n        std::cin >> l >> r;\n\
    \        std::cout << dst.query(l,r) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include <iostream>\n#include <vector>\n\n#include \"../data-structure/disjoint_sparse_table.hpp\"\
    \n\nlong long op(long long a,long long b){return a + b;}\n\nint main(){\n    int\
    \ N,Q;\n    std::cin >> N >> Q;\n    std::vector<long long> vec(N);\n    for(int\
    \ i = 0;i < N;i++)std::cin >> vec[i];\n    DisjointSparseTable<long long,op> dst(vec);\n\
    \    for(int i = 0;i < Q;i++){\n        int l,r;\n        std::cin >> l >> r;\n\
    \        std::cout << dst.query(l,r) << \"\\n\";\n    }\n}"
  dependsOn:
  - data-structure/disjoint_sparse_table.hpp
  isVerificationFile: true
  path: test/disjoint_sparse_table.test.cpp
  requiredBy: []
  timestamp: '2021-05-05 21:51:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/disjoint_sparse_table.test.cpp
layout: document
redirect_from:
- /verify/test/disjoint_sparse_table.test.cpp
- /verify/test/disjoint_sparse_table.test.cpp.html
title: test/disjoint_sparse_table.test.cpp
---
