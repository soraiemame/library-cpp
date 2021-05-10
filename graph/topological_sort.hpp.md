---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/topological_sort.test.cpp
    title: test/topological_sort.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/topological_sort.hpp\"\n\n\n\n#include <vector>\n\
    #include <queue>\n#include <cassert>\n\nstd::vector<int> topological_sort(const\
    \ std::vector<std::vector<int>>& G){\n    int v = G.size();\n    std::vector<int>\
    \ in(v);\n    for(int i = 0;i < v;i++){\n        for(auto&& e : G[i])in[e]++;\n\
    \    }\n\n    std::queue<int> que;\n    std::vector<int> res;\n    for(int i =\
    \ 0;i < v;i++){\n        if(in[i] == 0)que.push(i);\n    }\n\n    while(!que.empty()){\n\
    \        int n = que.front();\n        que.pop();\n        res.push_back(n);\n\
    \        for(auto&& e : G[n]){\n            assert(in[e]);\n            in[e]--;\n\
    \            if(in[e] == 0)que.push(e);\n        }\n    }\n    return res;\n}\n\
    \n\n"
  code: "#ifndef SORAIE_TOPOSORT\n#define SORAIE_TOPOSORT\n\n#include <vector>\n#include\
    \ <queue>\n#include <cassert>\n\nstd::vector<int> topological_sort(const std::vector<std::vector<int>>&\
    \ G){\n    int v = G.size();\n    std::vector<int> in(v);\n    for(int i = 0;i\
    \ < v;i++){\n        for(auto&& e : G[i])in[e]++;\n    }\n\n    std::queue<int>\
    \ que;\n    std::vector<int> res;\n    for(int i = 0;i < v;i++){\n        if(in[i]\
    \ == 0)que.push(i);\n    }\n\n    while(!que.empty()){\n        int n = que.front();\n\
    \        que.pop();\n        res.push_back(n);\n        for(auto&& e : G[n]){\n\
    \            assert(in[e]);\n            in[e]--;\n            if(in[e] == 0)que.push(e);\n\
    \        }\n    }\n    return res;\n}\n\n#endif /*SORAIE_TOPOSORT*/"
  dependsOn: []
  isVerificationFile: false
  path: graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2021-05-10 14:03:35+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/topological_sort.test.cpp
documentation_of: graph/topological_sort.hpp
layout: document
redirect_from:
- /library/graph/topological_sort.hpp
- /library/graph/topological_sort.hpp.html
title: graph/topological_sort.hpp
---
