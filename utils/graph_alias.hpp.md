---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algorithm/minimum_spanning_tree.hpp
    title: algorithm/minimum_spanning_tree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: graph/spfa.hpp
    title: graph/spfa.hpp
  - icon: ':warning:'
    path: test/graph/abstract_dijkstra.cpp
    title: test/graph/abstract_dijkstra.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/dijkstra.test.cpp
    title: test/graph/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/dijkstra2.test.cpp
    title: test/graph/dijkstra2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/spfa.test.cpp
    title: test/graph/spfa.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/minimum_spanning_tree.test.cpp
    title: test/minimum_spanning_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utils/graph_alias.hpp\"\n\n\n\n#include <iostream>\n\ntemplate<class\
    \ T = long long>\nstruct edge{\n    int from,to;T cost;\n    edge(){}\n    edge(int\
    \ to,T cost):from(-1),to(to),cost(cost){}\n    edge(int from,int to,T cost):from(from),to(to),cost(cost){}\n\
    \    friend std::ostream &operator<<(std::ostream &os,const edge& a){\n      \
    \  if(a.from == -1)return os << \"{\" << a.to << \",\" << a.cost << \"}\";\n \
    \       else return os << \"{\" << a.from << \"->\" << a.to << \",\" << a.cost\
    \ << \"}\";\n    }\n};\n\n\n"
  code: "#ifndef SORAIE_GRAPH_ALIAS\n#define SORAIE_GRAPH_ALIAS\n\n#include <iostream>\n\
    \ntemplate<class T = long long>\nstruct edge{\n    int from,to;T cost;\n    edge(){}\n\
    \    edge(int to,T cost):from(-1),to(to),cost(cost){}\n    edge(int from,int to,T\
    \ cost):from(from),to(to),cost(cost){}\n    friend std::ostream &operator<<(std::ostream\
    \ &os,const edge& a){\n        if(a.from == -1)return os << \"{\" << a.to << \"\
    ,\" << a.cost << \"}\";\n        else return os << \"{\" << a.from << \"->\" <<\
    \ a.to << \",\" << a.cost << \"}\";\n    }\n};\n\n#endif /*SORAIE_GRAPH_ALIAS*/"
  dependsOn: []
  isVerificationFile: false
  path: utils/graph_alias.hpp
  requiredBy:
  - test/graph/abstract_dijkstra.cpp
  - graph/spfa.hpp
  - graph/dijkstra.hpp
  - algorithm/minimum_spanning_tree.hpp
  timestamp: '2021-03-31 10:49:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/minimum_spanning_tree.test.cpp
  - test/graph/dijkstra2.test.cpp
  - test/graph/dijkstra.test.cpp
  - test/graph/spfa.test.cpp
documentation_of: utils/graph_alias.hpp
layout: document
redirect_from:
- /library/utils/graph_alias.hpp
- /library/utils/graph_alias.hpp.html
title: utils/graph_alias.hpp
---
