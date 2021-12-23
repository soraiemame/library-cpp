---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/RSQ.hpp
    title: algorithm/RSQ.hpp
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
  bundledCode: "#line 1 \"test/static_RSQ.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 1 \"algorithm/RSQ.hpp\"\n\n\
    #define SORAIE_RSQ\n\n#line 5 \"algorithm/RSQ.hpp\"\n#include <cassert>\n\ntemplate<class\
    \ T>\nstruct RangeSumQuery{\n    int n;\n    std::vector<T> dat;\n    RangeSumQuery(const\
    \ std::vector<T>& _dat):n(_dat.size()){\n        dat.resize(n + 1);\n        for(int\
    \ i = 0;i < n;i++)dat[i + 1] = dat[i] + _dat[i];\n    }\n    // [l,r)\n    T query(int\
    \ l,int r){\n        assert(0 <= l && l <= r && r <= n);\n        return dat[r]\
    \ - dat[l];\n    }\n};\ntemplate<class T>\nstruct RangeSumQuery2{\n    int n,m;\n\
    \    std::vector<std::vector<T>> dat;\n    RangeSumQuery2(const std::vector<std::vector<T>>&\
    \ _dat):n(_dat.size()),m(_dat[0].size()){\n        dat = std::vector<std::vector<T>>(n\
    \ + 1,std::vector<T>(m + 1));\n        for(int i = 0;i < n;i++)for(int j = 0;j\
    \ < m;j++)dat[i + 1][j + 1] = _dat[i][j];\n        for(int i = 1;i <= n;i++)for(int\
    \ j = 0;j < m;j++)dat[i][j + 1] += dat[i][j];\n        for(int i = 0;i < n;i++)for(int\
    \ j = 1;j <= m;j++)dat[i + 1][j] += dat[i][j];\n    }\n\n    // lx <= x < rx ,\
    \ ly <= y < ry\n    T query(int lx,int ly,int rx,int ry){\n        assert(0 <=\
    \ lx && lx <= rx && rx <= n);\n        assert(0 <= ly && ly <= ry && ry <= m);\n\
    \        return dat[rx][ry] - dat[rx][ly] - dat[lx][ry] + dat[lx][ly];\n    }\n\
    };\n\n#endif /*SORIAE_RSQ*/\n#line 7 \"test/static_RSQ.test.cpp\"\n\nint main(){\n\
    \    int N,Q;\n    std::cin >> N >> Q;\n    std::vector<long long> vec(N);\n \
    \   for(int i = 0;i < N;i++)std::cin >> vec[i];\n    RangeSumQuery<long long>\
    \ rsq(vec);\n\n    for(int i = 0;i < Q;i++){\n        int l,r;\n        std::cin\
    \ >> l >> r;\n        std::cout << rsq.query(l,r) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include <iostream>\n#include <vector>\n\n#include \"../algorithm/RSQ.hpp\"\n\n\
    int main(){\n    int N,Q;\n    std::cin >> N >> Q;\n    std::vector<long long>\
    \ vec(N);\n    for(int i = 0;i < N;i++)std::cin >> vec[i];\n    RangeSumQuery<long\
    \ long> rsq(vec);\n\n    for(int i = 0;i < Q;i++){\n        int l,r;\n       \
    \ std::cin >> l >> r;\n        std::cout << rsq.query(l,r) << \"\\n\";\n    }\n\
    }"
  dependsOn:
  - algorithm/RSQ.hpp
  isVerificationFile: true
  path: test/static_RSQ.test.cpp
  requiredBy: []
  timestamp: '2021-05-31 18:40:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/static_RSQ.test.cpp
layout: document
redirect_from:
- /verify/test/static_RSQ.test.cpp
- /verify/test/static_RSQ.test.cpp.html
title: test/static_RSQ.test.cpp
---
