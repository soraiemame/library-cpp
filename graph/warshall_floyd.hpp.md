---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/warshall_floyd.test.cpp
    title: test/graph/warshall_floyd.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/warshall_floyd.hpp\"\n\n\n\n#include <vector>\n\n\
    template<class T>\nstruct warshall_floyd{\n    warshall_floyd(const std::vector<std::vector<T>>&\
    \ G,T LM = std::numeric_limits<T>::max()):LM(LM){init(G);}\n\n    void append(int\
    \ from,int to,T cost){\n        if(dist[from][to] <= cost)return;\n        int\
    \ n = dist.size();\n        dist[from][to] = cost;\n        for(int i = 0;i <\
    \ n;i++){\n            for(int j = 0;j < n;j++){\n                if(dist[i][from]\
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
    \ dist;\n    std::vector<std::vector<int>> pre;\n};\n\n\n"
  code: "#ifndef SORAIE_WARSHALL_FLOYD\n#define SORAIE_WARSHALL_FLOYD\n\n#include\
    \ <vector>\n\ntemplate<class T>\nstruct warshall_floyd{\n    warshall_floyd(const\
    \ std::vector<std::vector<T>>& G,T LM = std::numeric_limits<T>::max()):LM(LM){init(G);}\n\
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
    \ dist;\n    std::vector<std::vector<int>> pre;\n};\n\n#endif /*SORAIE_WARSHALL_FLOYD*/"
  dependsOn: []
  isVerificationFile: false
  path: graph/warshall_floyd.hpp
  requiredBy: []
  timestamp: '2021-03-31 10:49:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/warshall_floyd.test.cpp
documentation_of: graph/warshall_floyd.hpp
layout: document
redirect_from:
- /library/graph/warshall_floyd.hpp
- /library/graph/warshall_floyd.hpp.html
title: graph/warshall_floyd.hpp
---
