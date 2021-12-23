---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/static_RSQ.test.cpp
    title: test/static_RSQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/RSQ.hpp\"\n\n#define SORAIE_RSQ\n\n#include <vector>\n\
    #include <cassert>\n\ntemplate<class T>\nstruct RangeSumQuery{\n    int n;\n \
    \   std::vector<T> dat;\n    RangeSumQuery(const std::vector<T>& _dat):n(_dat.size()){\n\
    \        dat.resize(n + 1);\n        for(int i = 0;i < n;i++)dat[i + 1] = dat[i]\
    \ + _dat[i];\n    }\n    // [l,r)\n    T query(int l,int r){\n        assert(0\
    \ <= l && l <= r && r <= n);\n        return dat[r] - dat[l];\n    }\n};\ntemplate<class\
    \ T>\nstruct RangeSumQuery2{\n    int n,m;\n    std::vector<std::vector<T>> dat;\n\
    \    RangeSumQuery2(const std::vector<std::vector<T>>& _dat):n(_dat.size()),m(_dat[0].size()){\n\
    \        dat = std::vector<std::vector<T>>(n + 1,std::vector<T>(m + 1));\n   \
    \     for(int i = 0;i < n;i++)for(int j = 0;j < m;j++)dat[i + 1][j + 1] = _dat[i][j];\n\
    \        for(int i = 1;i <= n;i++)for(int j = 0;j < m;j++)dat[i][j + 1] += dat[i][j];\n\
    \        for(int i = 0;i < n;i++)for(int j = 1;j <= m;j++)dat[i + 1][j] += dat[i][j];\n\
    \    }\n\n    // lx <= x < rx , ly <= y < ry\n    T query(int lx,int ly,int rx,int\
    \ ry){\n        assert(0 <= lx && lx <= rx && rx <= n);\n        assert(0 <= ly\
    \ && ly <= ry && ry <= m);\n        return dat[rx][ry] - dat[rx][ly] - dat[lx][ry]\
    \ + dat[lx][ly];\n    }\n};\n\n#endif /*SORIAE_RSQ*/\n"
  code: "#ifndef SORIAE_RSQ\n#define SORAIE_RSQ\n\n#include <vector>\n#include <cassert>\n\
    \ntemplate<class T>\nstruct RangeSumQuery{\n    int n;\n    std::vector<T> dat;\n\
    \    RangeSumQuery(const std::vector<T>& _dat):n(_dat.size()){\n        dat.resize(n\
    \ + 1);\n        for(int i = 0;i < n;i++)dat[i + 1] = dat[i] + _dat[i];\n    }\n\
    \    // [l,r)\n    T query(int l,int r){\n        assert(0 <= l && l <= r && r\
    \ <= n);\n        return dat[r] - dat[l];\n    }\n};\ntemplate<class T>\nstruct\
    \ RangeSumQuery2{\n    int n,m;\n    std::vector<std::vector<T>> dat;\n    RangeSumQuery2(const\
    \ std::vector<std::vector<T>>& _dat):n(_dat.size()),m(_dat[0].size()){\n     \
    \   dat = std::vector<std::vector<T>>(n + 1,std::vector<T>(m + 1));\n        for(int\
    \ i = 0;i < n;i++)for(int j = 0;j < m;j++)dat[i + 1][j + 1] = _dat[i][j];\n  \
    \      for(int i = 1;i <= n;i++)for(int j = 0;j < m;j++)dat[i][j + 1] += dat[i][j];\n\
    \        for(int i = 0;i < n;i++)for(int j = 1;j <= m;j++)dat[i + 1][j] += dat[i][j];\n\
    \    }\n\n    // lx <= x < rx , ly <= y < ry\n    T query(int lx,int ly,int rx,int\
    \ ry){\n        assert(0 <= lx && lx <= rx && rx <= n);\n        assert(0 <= ly\
    \ && ly <= ry && ry <= m);\n        return dat[rx][ry] - dat[rx][ly] - dat[lx][ry]\
    \ + dat[lx][ly];\n    }\n};\n\n#endif /*SORIAE_RSQ*/"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/RSQ.hpp
  requiredBy: []
  timestamp: '2021-05-31 18:40:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/static_RSQ.test.cpp
documentation_of: algorithm/RSQ.hpp
layout: document
redirect_from:
- /library/algorithm/RSQ.hpp
- /library/algorithm/RSQ.hpp.html
title: algorithm/RSQ.hpp
---
