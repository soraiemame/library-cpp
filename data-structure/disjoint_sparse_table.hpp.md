---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/disjoint_sparse_table.test.cpp
    title: test/disjoint_sparse_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/disjoint_sparse_table.hpp\"\n\n\n\n#include\
    \ <vector>\n#include <cassert>\n\ntemplate<class T,T (*op)(T,T)>\nstruct DisjointSparseTable{\n\
    private:\n    int _n,log,sz;\n    std::vector<std::vector<T>> table;\n    static\
    \ int msb(int x){\n    #ifdef __has_builtin\n        return 31 ^ __builtin_clz(x);\n\
    \    #else\n        int res = 0;\n        if(x >> 16){\n            res += 16;x\
    \ >>= 16;\n        }\n        if(x >> 8){\n            res += 8;x >>= 8;\n   \
    \     }\n        if(x >> 4){\n            res += 4;x >>= 4;\n        }\n     \
    \   if(x >> 2){\n            res += 2;x >>= 2;\n        }\n        return res\
    \ + (x >> 1);\n    #endif\n    }\n    void build(const std::vector<T>& dat){\n\
    \        int w = sz;\n        for(int lv = 0;lv < log;lv++){\n            int\
    \ l = 0,r = w;\n            for(;l < sz;l += w,r += w){\n                int m\
    \ = (l + r) >> 1;\n\n                table[lv][m] = dat[m];\n                for(int\
    \ i = m + 1;i < r;i++)table[lv][i] = op(table[lv][i - 1],dat[i]);\n\n        \
    \        table[lv][m - 1] = dat[m - 1];\n                for(int i = m - 2;i >=\
    \ l;i--)table[lv][i] = op(table[lv][i + 1],dat[i]);\n            }\n         \
    \   w >>= 1;\n        }\n    }\n\npublic:\n    DisjointSparseTable(const std::vector<T>&\
    \ dat){\n        _n = dat.size();\n        sz = 1;\n        log = 0;\n       \
    \ while(sz < _n)sz <<= 1,log++;\n        table = std::vector<std::vector<T>>(log,std::vector<T>(sz));\n\
    \        std::vector<T> _dat = dat;\n        _dat.resize(sz);\n        build(_dat);\n\
    \    }\n    // [l,r)\n    T query(int l,int r)const{\n        assert(0 <= l &&\
    \ l < r && r <= _n);\n        r--;\n        if(l == r)return table.back()[l];\n\
    \        int clz = msb(l ^ r);\n        int lev = log - clz - 1;\n        T res\
    \ = op(table[lev][l],table[lev][r]);\n        return res;\n    }\n    inline T\
    \ operator[](int k)const{\n        assert(k < _n);\n        return table.back()[k];\n\
    \    }\n};\n\n\n"
  code: "#ifndef SORAIE_DISJOINT_SPARSE_TABLE\n#define SORAIE_DISJOINT_SPARSE_TABLE\n\
    \n#include <vector>\n#include <cassert>\n\ntemplate<class T,T (*op)(T,T)>\nstruct\
    \ DisjointSparseTable{\nprivate:\n    int _n,log,sz;\n    std::vector<std::vector<T>>\
    \ table;\n    static int msb(int x){\n    #ifdef __has_builtin\n        return\
    \ 31 ^ __builtin_clz(x);\n    #else\n        int res = 0;\n        if(x >> 16){\n\
    \            res += 16;x >>= 16;\n        }\n        if(x >> 8){\n           \
    \ res += 8;x >>= 8;\n        }\n        if(x >> 4){\n            res += 4;x >>=\
    \ 4;\n        }\n        if(x >> 2){\n            res += 2;x >>= 2;\n        }\n\
    \        return res + (x >> 1);\n    #endif\n    }\n    void build(const std::vector<T>&\
    \ dat){\n        int w = sz;\n        for(int lv = 0;lv < log;lv++){\n       \
    \     int l = 0,r = w;\n            for(;l < sz;l += w,r += w){\n            \
    \    int m = (l + r) >> 1;\n\n                table[lv][m] = dat[m];\n       \
    \         for(int i = m + 1;i < r;i++)table[lv][i] = op(table[lv][i - 1],dat[i]);\n\
    \n                table[lv][m - 1] = dat[m - 1];\n                for(int i =\
    \ m - 2;i >= l;i--)table[lv][i] = op(table[lv][i + 1],dat[i]);\n            }\n\
    \            w >>= 1;\n        }\n    }\n\npublic:\n    DisjointSparseTable(const\
    \ std::vector<T>& dat){\n        _n = dat.size();\n        sz = 1;\n        log\
    \ = 0;\n        while(sz < _n)sz <<= 1,log++;\n        table = std::vector<std::vector<T>>(log,std::vector<T>(sz));\n\
    \        std::vector<T> _dat = dat;\n        _dat.resize(sz);\n        build(_dat);\n\
    \    }\n    // [l,r)\n    T query(int l,int r)const{\n        assert(0 <= l &&\
    \ l < r && r <= _n);\n        r--;\n        if(l == r)return table.back()[l];\n\
    \        int clz = msb(l ^ r);\n        int lev = log - clz - 1;\n        T res\
    \ = op(table[lev][l],table[lev][r]);\n        return res;\n    }\n    inline T\
    \ operator[](int k)const{\n        assert(k < _n);\n        return table.back()[k];\n\
    \    }\n};\n\n#endif /*SORAIE_DISJOINT_SPARSE_TABLE*/"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/disjoint_sparse_table.hpp
  requiredBy: []
  timestamp: '2021-05-04 18:29:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/disjoint_sparse_table.test.cpp
documentation_of: data-structure/disjoint_sparse_table.hpp
layout: document
redirect_from:
- /library/data-structure/disjoint_sparse_table.hpp
- /library/data-structure/disjoint_sparse_table.hpp.html
title: data-structure/disjoint_sparse_table.hpp
---
