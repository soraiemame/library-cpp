---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/topological_sort.hpp
    title: graph/topological_sort.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B
  bundledCode: "#line 1 \"test/topological_sort.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B\"\
    \n\n#include <vector>\n#include <iostream>\n\n#line 1 \"graph/topological_sort.hpp\"\
    \n\n\n\n#line 5 \"graph/topological_sort.hpp\"\n#include <queue>\n#include <cassert>\n\
    \nstd::vector<int> topological_sort(const std::vector<std::vector<int>>& G){\n\
    \    int v = G.size();\n    std::vector<int> in(v);\n    for(int i = 0;i < v;i++){\n\
    \        for(auto&& e : G[i])in[e]++;\n    }\n\n    std::queue<int> que;\n   \
    \ std::vector<int> res;\n    for(int i = 0;i < v;i++){\n        if(in[i] == 0)que.push(i);\n\
    \    }\n\n    while(!que.empty()){\n        int n = que.front();\n        que.pop();\n\
    \        res.push_back(n);\n        for(auto&& e : G[n]){\n            assert(in[e]);\n\
    \            in[e]--;\n            if(in[e] == 0)que.push(e);\n        }\n   \
    \ }\n    return res;\n}\n\n\n#line 7 \"test/topological_sort.test.cpp\"\n\nint\
    \ main(){\n    int N,M;\n    std::cin >> N >> M;\n    std::vector<std::vector<int>>\
    \ G(N);\n    for(int i = 0;i < M;i++){\n        int a,b;\n        std::cin >>\
    \ a >> b;\n        G[a].push_back(b);\n    }\n    auto ans = topological_sort(G);\n\
    \    for(int v : ans){\n        std::cout << v << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B\"\
    \n\n#include <vector>\n#include <iostream>\n\n#include \"../graph/topological_sort.hpp\"\
    \n\nint main(){\n    int N,M;\n    std::cin >> N >> M;\n    std::vector<std::vector<int>>\
    \ G(N);\n    for(int i = 0;i < M;i++){\n        int a,b;\n        std::cin >>\
    \ a >> b;\n        G[a].push_back(b);\n    }\n    auto ans = topological_sort(G);\n\
    \    for(int v : ans){\n        std::cout << v << \"\\n\";\n    }\n}"
  dependsOn:
  - graph/topological_sort.hpp
  isVerificationFile: true
  path: test/topological_sort.test.cpp
  requiredBy: []
  timestamp: '2021-05-10 14:03:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/topological_sort.test.cpp
layout: document
redirect_from:
- /verify/test/topological_sort.test.cpp
- /verify/test/topological_sort.test.cpp.html
title: test/topological_sort.test.cpp
---
