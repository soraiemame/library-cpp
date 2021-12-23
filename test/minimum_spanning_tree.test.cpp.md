---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/minimum_spanning_tree.hpp
    title: algorithm/minimum_spanning_tree.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/unionfind.hpp
    title: data-structure/unionfind.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
  bundledCode: "#line 1 \"test/minimum_spanning_tree.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#line 1 \"algorithm/minimum_spanning_tree.hpp\"\
    \n\n\n\n#line 5 \"algorithm/minimum_spanning_tree.hpp\"\n#include <algorithm>\n\
    \n#line 1 \"data-structure/unionfind.hpp\"\n\n\n\n#line 6 \"data-structure/unionfind.hpp\"\
    \n#include <assert.h>\n\nstruct UnionFind{\n    int n;\n    std::vector<int> dat;\n\
    \    UnionFind(int n_){init(n_);}\n    void init(int n_){\n        n = n_;\n \
    \       dat = std::vector<int>(n_,-1);\n    }\n    int find(int v){\n        assert(0\
    \ <= v && v < n);\n        if(dat[v] < 0)return v;\n        else return dat[v]\
    \ = find(dat[v]);\n    }\n    void unite(int a,int b){\n        assert(0 <= a\
    \ && a < n && 0 <= b && b < n);\n        a = find(a);\n        b = find(b);\n\
    \        if(a == b)return;\n        if(dat[a] > dat[b])std::swap(a,b);\n     \
    \   dat[a] += dat[b];\n        dat[b] = a;\n    }\n    bool same(int a,int b){\n\
    \        assert(0 <= a && a < n && 0 <= b && b < n);\n        return find(a) ==\
    \ find(b);\n    }\n    int size(int v){\n        assert(0 <= v && v < n);\n  \
    \      return -dat[v];\n    }\n};\n\n\n#line 1 \"utils/graph_alias.hpp\"\n\n\n\
    \n#line 5 \"utils/graph_alias.hpp\"\n\ntemplate<class T = long long>\nstruct edge{\n\
    \    int from,to;T cost;\n    edge(){}\n    edge(int to,T cost):from(-1),to(to),cost(cost){}\n\
    \    edge(int from,int to,T cost):from(from),to(to),cost(cost){}\n    friend std::ostream\
    \ &operator<<(std::ostream &os,const edge& a){\n        if(a.from == -1)return\
    \ os << \"{\" << a.to << \",\" << a.cost << \"}\";\n        else return os <<\
    \ \"{\" << a.from << \"->\" << a.to << \",\" << a.cost << \"}\";\n    }\n};\n\n\
    \n#line 9 \"algorithm/minimum_spanning_tree.hpp\"\n\ntemplate<class T>\nstd::pair<T,std::vector<edge<T>>>\
    \ minimum_spanning_tree(const std::vector<edge<T>> &_es,bool sorted = false){\n\
    \    std::vector<edge<T>> es = _es;\n    if(!sorted)std::sort(es.begin(),es.end(),[](const\
    \ edge<T> a,const edge<T> b){return a.cost < b.cost;});\n    int n = 0;\n    for(auto&&\
    \ e : es)n = std::max({n,e.from,e.to});\n    std::pair<T,std::vector<edge<T>>>\
    \ res;\n    UnionFind UF(n + 1);\n    for(auto&& e : es){\n        if(!UF.same(e.from,e.to)){\n\
    \            res.first += e.cost;\n            res.second.push_back(e);\n    \
    \        UF.unite(e.from,e.to);\n        }\n    }\n    return res;\n}\n\n\n#line\
    \ 7 \"test/minimum_spanning_tree.test.cpp\"\n\nint main(){\n    int N,M;\n   \
    \ std::cin >> N >> M;\n    std::vector<edge<int>> vec(M);\n    for(int i = 0;i\
    \ < M;i++){\n        int a,b,c;\n        std::cin >> a >> b >> c;\n        vec[i]\
    \ = edge(a,b,c);\n    }\n    std::cout << minimum_spanning_tree(vec).first <<\
    \ \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../algorithm/minimum_spanning_tree.hpp\"\
    \n\nint main(){\n    int N,M;\n    std::cin >> N >> M;\n    std::vector<edge<int>>\
    \ vec(M);\n    for(int i = 0;i < M;i++){\n        int a,b,c;\n        std::cin\
    \ >> a >> b >> c;\n        vec[i] = edge(a,b,c);\n    }\n    std::cout << minimum_spanning_tree(vec).first\
    \ << \"\\n\";\n}"
  dependsOn:
  - algorithm/minimum_spanning_tree.hpp
  - data-structure/unionfind.hpp
  - utils/graph_alias.hpp
  isVerificationFile: true
  path: test/minimum_spanning_tree.test.cpp
  requiredBy: []
  timestamp: '2021-04-08 21:36:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/minimum_spanning_tree.test.cpp
layout: document
redirect_from:
- /verify/test/minimum_spanning_tree.test.cpp
- /verify/test/minimum_spanning_tree.test.cpp.html
title: test/minimum_spanning_tree.test.cpp
---
