---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: utils/graph_alias.hpp
    title: utils/graph_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
  bundledCode: "#line 1 \"test/graph/dijkstra.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 1 \"graph/dijkstra.hpp\"\n\
    \n\n\n#line 5 \"graph/dijkstra.hpp\"\n#include <algorithm>\n#include <queue>\n\
    #include <cassert>\n\n#line 1 \"utils/graph_alias.hpp\"\n\n\n\n#line 5 \"utils/graph_alias.hpp\"\
    \n\ntemplate<class T = long long>\nstruct edge{\n    int from,to;T cost;\n   \
    \ edge(){}\n    edge(int to,T cost):from(-1),to(to),cost(cost){}\n    edge(int\
    \ from,int to,T cost):from(from),to(to),cost(cost){}\n    friend std::ostream\
    \ &operator<<(std::ostream &os,const edge& a){\n        if(a.from == -1)return\
    \ os << \"{\" << a.to << \",\" << a.cost << \"}\";\n        else return os <<\
    \ \"{\" << a.from << \"->\" << a.to << \",\" << a.cost << \"}\";\n    }\n};\n\n\
    \n#line 10 \"graph/dijkstra.hpp\"\n\nnamespace dijkstra{\n    int _s = -1;\n \
    \   std::vector<int> from;\n\n    template<class T>\n    std::vector<T> get_dist(const\
    \ std::vector<std::vector<edge<T>>>& G,const std::vector<int>& st,T LM = std::numeric_limits<T>::max()){\n\
    \        from.resize(G.size(),-1);\n        std::vector<T> res(G.size(),LM);\n\
    \        std::priority_queue<std::pair<T,int>,std::vector<std::pair<T,int>>,std::greater<std::pair<T,int>>>\
    \ que;\n        for(const int &a : st){\n            que.push(std::make_pair(0,a));\n\
    \            res[a] = 0;\n        }\n        while(!que.empty()){\n          \
    \  auto p = que.top();\n            que.pop();\n            if(res[p.second] <\
    \ p.first)continue;\n            for(const edge<T> &e : G[p.second]){\n      \
    \          if(res[e.to] > res[p.second] + e.cost){\n                    res[e.to]\
    \ = res[p.second] + e.cost;\n                    from[e.to] = p.second;\n    \
    \                que.push(std::make_pair(res[e.to],e.to));\n                }\n\
    \            }\n        }\n        return res;\n    }\n\n    template<class V,class\
    \ E,long long (*trans)(E,long long)>\n    std::vector<V> get_dist(const std::vector<std::vector<E>>&\
    \ G,const std::vector<int>& st,V LM = std::numeric_limits<V>::max()){\n      \
    \  std::vector<V> res(G.size(),LM);\n        from.resize(G.size(),-1);\n     \
    \   std::priority_queue<std::pair<V,int>,std::vector<std::pair<V,int>>,std::greater<std::pair<V,int>>>\
    \ que;\n        for(const int& a : st){\n            que.push(std::make_pair(0,a));\n\
    \            res[a] = 0;\n        }\n        while(!que.empty()){\n          \
    \  auto p = que.top();\n            que.pop();\n            if(p.first > res[p.second])continue;\n\
    \            for(auto e : G[p.second]){\n                V nx = trans(e,p.first);\n\
    \                if(nx < res[e.to]){\n                    res[e.to] = nx;\n  \
    \                  from[e.to] = p.second;\n                    que.push(std::make_pair(res[e.to],e.to));\n\
    \                }\n            }\n        }\n        return res;\n    }\n\n \
    \   template<class T>\n    std::vector<T> get_dist(const std::vector<std::vector<edge<T>>>&\
    \ G,int s,T LM = std::numeric_limits<T>::max()){\n        _s = s;\n        std::vector<int>\
    \ st = {s};\n        return get_dist(G,st,LM);\n    }\n    template<class V,class\
    \ E,long long (*trans)(E,long long)>\n    std::vector<V> get_dist(const std::vector<std::vector<E>>&\
    \ G,int s,V LM = std::numeric_limits<V>::max()){\n        _s = s;\n        std::vector<int>\
    \ st = {s};\n        return get_dist<V,E,trans>(G,st,LM);\n    }\n\n    std::vector<int>\
    \ path(int s,int t){\n        if(s == t)return {s};\n        else if(from[t] ==\
    \ -1)return {};\n        std::vector<int> res;\n        for(int cur = t;cur !=\
    \ s;cur = from[cur])res.push_back(cur);\n        res.push_back(s);\n        std::reverse(res.begin(),res.end());\n\
    \        return res;\n    }\n\n    std::vector<int> path(int t){\n        assert(_s\
    \ != -1);\n        return path(_s,t);\n    }\n};\nusing dijkstra::get_dist;\n\
    using dijkstra::path;\n\n\n#line 7 \"test/graph/dijkstra.test.cpp\"\n\nint main(){\n\
    \    int N,M,S;\n    std::cin >> N >> M >> S;\n    std::vector<std::vector<edge<>>>\
    \ G(N);\n    for(int i = 0;i < M;i++){\n        int a,b;long long c;\n       \
    \ std::cin >> a >> b >> c;\n        G[a].push_back({b,c});\n    }\n    const long\
    \ long INF = 1LL << 60;\n    auto ans = get_dist(G,S,INF);\n    for(int i = 0;i\
    \ < N;i++){\n        if(ans[i] == INF)std::cout << \"INF\\n\";\n        else std::cout\
    \ << ans[i] << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../graph/dijkstra.hpp\"\
    \n\nint main(){\n    int N,M,S;\n    std::cin >> N >> M >> S;\n    std::vector<std::vector<edge<>>>\
    \ G(N);\n    for(int i = 0;i < M;i++){\n        int a,b;long long c;\n       \
    \ std::cin >> a >> b >> c;\n        G[a].push_back({b,c});\n    }\n    const long\
    \ long INF = 1LL << 60;\n    auto ans = get_dist(G,S,INF);\n    for(int i = 0;i\
    \ < N;i++){\n        if(ans[i] == INF)std::cout << \"INF\\n\";\n        else std::cout\
    \ << ans[i] << \"\\n\";\n    }\n}"
  dependsOn:
  - graph/dijkstra.hpp
  - utils/graph_alias.hpp
  isVerificationFile: true
  path: test/graph/dijkstra.test.cpp
  requiredBy: []
  timestamp: '2021-03-31 10:49:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/dijkstra.test.cpp
layout: document
redirect_from:
- /verify/test/graph/dijkstra.test.cpp
- /verify/test/graph/dijkstra.test.cpp.html
title: test/graph/dijkstra.test.cpp
---
