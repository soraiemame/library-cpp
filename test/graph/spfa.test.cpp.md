---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/spfa.hpp
    title: graph/spfa.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
  bundledCode: "#line 1 \"test/graph/spfa.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 1 \"graph/spfa.hpp\"\n\n\n\
    \n#line 5 \"graph/spfa.hpp\"\n#include <queue>\n#include <algorithm>\n#include\
    \ <cassert>\n\n#line 1 \"utils/graph_alias.hpp\"\n\n\n\n#line 5 \"utils/graph_alias.hpp\"\
    \n\ntemplate<class T = long long>\nstruct edge{\n    int from,to;T cost;\n   \
    \ edge(){}\n    edge(int to,T cost):from(-1),to(to),cost(cost){}\n    edge(int\
    \ from,int to,T cost):from(from),to(to),cost(cost){}\n    friend std::ostream\
    \ &operator<<(std::ostream &os,const edge& a){\n        if(a.from == -1)return\
    \ os << \"{\" << a.to << \",\" << a.cost << \"}\";\n        else return os <<\
    \ \"{\" << a.from << \"->\" << a.to << \",\" << a.cost << \"}\";\n    }\n};\n\n\
    \n#line 10 \"graph/spfa.hpp\"\n\nnamespace spfa{\n    int _s = -1;\n    std::vector<int>\
    \ from;\n\n    template<class T>\n    std::vector<T> get_dist(const std::vector<std::vector<edge<T>>>&\
    \ G,const std::vector<int>& st,T LM = std::numeric_limits<T>::max()){\n      \
    \  int sz = G.size();\n        from.resize(sz,-1);\n        std::vector<T> res(sz,LM);\n\
    \        std::vector<bool> pending(sz,false);\n        std::vector<int> times(sz,0);\n\
    \        std::queue<int> que;\n        for(const int& p : st){\n            que.push(p);\n\
    \            times[p]++;\n            pending[p] = true;\n            res[p] =\
    \ 0;\n        }\n        while(!que.empty()){\n            int n = que.front();\n\
    \            que.pop();\n            pending[n] = false;\n            for(const\
    \ auto& e : G[n]){\n                T nx = res[n] + e.cost;\n                if(nx\
    \ < res[e.to]){\n                    res[e.to] = nx;\n                    from[e.to]\
    \ = n;\n                    if(!pending[e.to]){\n                        if(++times[e.to]\
    \ >= sz)return {};\n                        pending[e.to] = true;\n          \
    \              que.push(e.to);\n                    }\n                }\n   \
    \         }\n        }\n        return res;\n    }\n\n    template<class T>\n\
    \    std::vector<T> get_dist(const std::vector<std::vector<edge<T>>>& G,int s,T\
    \ LM = std::numeric_limits<T>::max()){\n        _s = s;\n        std::vector<int>\
    \ st = {s};\n        return get_dist(G,st,LM);\n    }\n\n    std::vector<int>\
    \ path(int s,int t){\n        if(s == t)return {s};\n        else if(from[t] ==\
    \ -1)return {};\n        std::vector<int> res;\n        for(int cur = t;cur !=\
    \ s;cur = from[cur])res.push_back(cur);\n        res.push_back(s);\n        std::reverse(res.begin(),res.end());\n\
    \        return res;\n    }\n\n    std::vector<int> path(int t){\n        assert(_s\
    \ != -1);\n        return path(_s,t);\n    }\n};\nusing spfa::get_dist;\nusing\
    \ spfa::path;\n\n\n#line 7 \"test/graph/spfa.test.cpp\"\n\nint main(){\n    int\
    \ N,M,S;\n    std::cin >> N >> M >> S;\n    std::vector<std::vector<edge<>>> G(N);\n\
    \    for(int i = 0;i < M;i++){\n        int a,b;long long c;\n        std::cin\
    \ >> a >> b >> c;\n        G[a].push_back({b,c});\n    }\n    const long long\
    \ INF = 1LL << 60;\n    auto ans = get_dist(G,S,INF);\n    if(ans.empty())std::cout\
    \ << \"NEGATIVE CYCLE\\n\";\n    else{\n        for(long long &x : ans){\n   \
    \         if(x == INF)std::cout << \"INF\\n\";\n            else std::cout <<\
    \ x << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../graph/spfa.hpp\"\
    \n\nint main(){\n    int N,M,S;\n    std::cin >> N >> M >> S;\n    std::vector<std::vector<edge<>>>\
    \ G(N);\n    for(int i = 0;i < M;i++){\n        int a,b;long long c;\n       \
    \ std::cin >> a >> b >> c;\n        G[a].push_back({b,c});\n    }\n    const long\
    \ long INF = 1LL << 60;\n    auto ans = get_dist(G,S,INF);\n    if(ans.empty())std::cout\
    \ << \"NEGATIVE CYCLE\\n\";\n    else{\n        for(long long &x : ans){\n   \
    \         if(x == INF)std::cout << \"INF\\n\";\n            else std::cout <<\
    \ x << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - graph/spfa.hpp
  - utils/graph_alias.hpp
  isVerificationFile: true
  path: test/graph/spfa.test.cpp
  requiredBy: []
  timestamp: '2021-03-31 10:49:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/spfa.test.cpp
layout: document
redirect_from:
- /verify/test/graph/spfa.test.cpp
- /verify/test/graph/spfa.test.cpp.html
title: test/graph/spfa.test.cpp
---
