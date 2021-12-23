---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/warshall_floyd.hpp
    title: graph/warshall_floyd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
  bundledCode: "#line 1 \"test/graph/warshall_floyd.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\n\n#include\
    \ <iostream>\n#include <algorithm>\n#include <vector>\n\n#line 1 \"graph/warshall_floyd.hpp\"\
    \n\n\n\n#line 5 \"graph/warshall_floyd.hpp\"\n\ntemplate<class T>\nstruct warshall_floyd{\n\
    \    warshall_floyd(const std::vector<std::vector<T>>& G,T LM = std::numeric_limits<T>::max()):LM(LM){init(G);}\n\
    \n    void append(int from,int to,T cost){\n        if(dist[from][to] <= cost)return;\n\
    \        int n = dist.size();\n        dist[from][to] = cost;\n        for(int\
    \ i = 0;i < n;i++){\n            for(int j = 0;j < n;j++){\n                if(dist[i][from]\
    \ == LM || dist[to][j] == LM)continue;\n                else if(dist[i][j] > dist[i][from]\
    \ + cost + dist[to][j]){\n                    dist[i][j] = dist[i][from] + cost\
    \ + dist[to][j];\n                    pre[i][j] = pre[to][j];\n              \
    \  }\n            }\n        }\n    }\n    \n    std::vector<std::vector<T>> get_dist(){return\
    \ dist;}\n\n    std::vector<int> path(int s,int t){\n        std::vector<int>\
    \ res;\n        for(int cur = t;cur != s;cur = pre[s][cur])res.push_back(cur);\n\
    \        res.push_back(s);\n        reverse(res.begin(),res.end());\n        return\
    \ res;\n    }\n\n    bool negative_cycle(){\n        for(int i = 0;i < int(dist.size());i++)if(dist[i][i]\
    \ < 0)return true;\n        return false;\n    }\n\nprivate:\n    void init(const\
    \ std::vector<std::vector<T>>& G){\n        dist = G;\n        int n = G.size();\n\
    \        for(int i = 0;i < n;i++)dist[i][i] = 0;\n        pre = std::vector<std::vector<int>>(n,std::vector<int>(n,-1));\n\
    \        for(int i = 0;i < n;i++){\n            for(int j = 0;j < n;j++){\n  \
    \              for(int k = 0;k < n;k++){\n                    if(dist[j][i] ==\
    \ LM || dist[i][k] == LM)continue;\n                    else if(dist[j][k] > dist[j][i]\
    \ + dist[i][k]){\n                        dist[j][k] = dist[j][i] + dist[i][k];\n\
    \                        pre[j][k] = pre[i][k];\n                    }\n     \
    \           }\n            }\n        }\n    }\n    T LM;\n    std::vector<std::vector<T>>\
    \ dist;\n    std::vector<std::vector<int>> pre;\n};\n\n\n#line 8 \"test/graph/warshall_floyd.test.cpp\"\
    \n\nint main(){\n    const long long INF = 1LL << 60;\n    int N,M;\n    std::cin\
    \ >> N >> M;\n    std::vector<std::vector<long long>> G(N,std::vector<long long>(N,INF));\n\
    \    for(int i = 0;i < M;i++){\n        int a,b;long long c;\n        std::cin\
    \ >> a >> b >> c;\n        G[a][b] = std::min(G[a][b],c);\n    }\n    warshall_floyd<long\
    \ long> WF(G,INF);\n    if(WF.negative_cycle()){\n        std::cout << \"NEGATIVE\
    \ CYCLE\\n\";\n    }\n    else{\n        auto ans = WF.get_dist();\n        for(int\
    \ i = 0;i < N;i++){\n            for(int j = 0;j < N;j++){\n                std::cout\
    \ << (ans[i][j] == INF ? \"INF\" : std::to_string(ans[i][j])) << (j == N - 1 ?\
    \ \"\\n\" : \" \");\n            }\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n\n#include <iostream>\n#include <algorithm>\n#include <vector>\n\n#include \"\
    ../../graph/warshall_floyd.hpp\"\n\nint main(){\n    const long long INF = 1LL\
    \ << 60;\n    int N,M;\n    std::cin >> N >> M;\n    std::vector<std::vector<long\
    \ long>> G(N,std::vector<long long>(N,INF));\n    for(int i = 0;i < M;i++){\n\
    \        int a,b;long long c;\n        std::cin >> a >> b >> c;\n        G[a][b]\
    \ = std::min(G[a][b],c);\n    }\n    warshall_floyd<long long> WF(G,INF);\n  \
    \  if(WF.negative_cycle()){\n        std::cout << \"NEGATIVE CYCLE\\n\";\n   \
    \ }\n    else{\n        auto ans = WF.get_dist();\n        for(int i = 0;i < N;i++){\n\
    \            for(int j = 0;j < N;j++){\n                std::cout << (ans[i][j]\
    \ == INF ? \"INF\" : std::to_string(ans[i][j])) << (j == N - 1 ? \"\\n\" : \"\
    \ \");\n            }\n        }\n    }\n}"
  dependsOn:
  - graph/warshall_floyd.hpp
  isVerificationFile: true
  path: test/graph/warshall_floyd.test.cpp
  requiredBy: []
  timestamp: '2021-03-31 10:49:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/warshall_floyd.test.cpp
layout: document
redirect_from:
- /verify/test/graph/warshall_floyd.test.cpp
- /verify/test/graph/warshall_floyd.test.cpp.html
title: test/graph/warshall_floyd.test.cpp
---
