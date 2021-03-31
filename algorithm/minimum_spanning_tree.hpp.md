---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/unionfind.hpp
    title: data-structure/unionfind.hpp
  - icon: ':heavy_check_mark:'
    path: utils/graph_alias.hpp
    title: utils/graph_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/minimum_spanning_tree.hpp\"\n\n\n\n#include <vector>\n\
    #include <algorithm>\n\n#line 1 \"data-structure/unionfind.hpp\"\n\n\n\n#line\
    \ 6 \"data-structure/unionfind.hpp\"\n#include <assert.h>\n\nstruct UnionFind{\n\
    \    int n;\n    std::vector<int> dat;\n    UnionFind(int n_){init(n_);}\n   \
    \ void init(int n_){\n        n = n_;\n        dat = std::vector<int>(n_,-1);\n\
    \    }\n    int find(int v){\n        assert(0 <= v && v < n);\n        if(dat[v]\
    \ < 0)return v;\n        else return dat[v] = find(dat[v]);\n    }\n    void unite(int\
    \ a,int b){\n        assert(0 <= a && a < n && 0 <= b && b < n);\n        a =\
    \ find(a);\n        b = find(b);\n        if(a == b)return;\n        if(dat[a]\
    \ > dat[b])std::swap(a,b);\n        dat[a] += dat[b];\n        dat[b] = a;\n \
    \   }\n    bool same(int a,int b){\n        assert(0 <= a && a < n && 0 <= b &&\
    \ b < n);\n        return find(a) == find(b);\n    }\n    int size(int v){\n \
    \       assert(0 <= v && v < n);\n        return -dat[v];\n    }\n};\n\n\n#line\
    \ 1 \"utils/graph_alias.hpp\"\n\n\n\n#include <iostream>\n\ntemplate<class T =\
    \ long long>\nstruct edge{\n    int from,to;T cost;\n    edge(){}\n    edge(int\
    \ to,T cost):from(-1),to(to),cost(cost){}\n    edge(int from,int to,T cost):from(from),to(to),cost(cost){}\n\
    \    friend std::ostream &operator<<(std::ostream &os,const edge& a){\n      \
    \  if(a.from == -1)return os << \"{\" << a.to << \",\" << a.cost << \"}\";\n \
    \       else return os << \"{\" << a.from << \"->\" << a.to << \",\" << a.cost\
    \ << \"}\";\n    }\n};\n\n\n#line 9 \"algorithm/minimum_spanning_tree.hpp\"\n\n\
    template<class T>\nstd::pair<T,std::vector<edge2<T>>> minimum_spanning_tree(const\
    \ std::vector<edge2<T>> &_es,bool sorted = false){\n    std::vector<edge2<T>>\
    \ es = _es;\n    if(!sorted)std::sort(es.begin(),es.end(),[](const edge2<T> a,const\
    \ edge2<T> b){return a.cost < b.cost;});\n    int n = es.size();\n    std::pair<T,std::vector<edge2<T>>>\
    \ res;\n    UnionFind UF(n);\n    for(edge2<T>& e : es){\n        if(!UF.same(e.from,e.to)){\n\
    \            res.first += e.cost;\n            res.second.push_back(e);\n    \
    \    }\n    }\n    return res;\n}\n\n\n"
  code: "#ifndef SORAIE_MST\n#define SORAIE_MST\n\n#include <vector>\n#include <algorithm>\n\
    \n#include \"../data-structure/unionfind.hpp\"\n#include \"../utils/graph_alias.hpp\"\
    \n\ntemplate<class T>\nstd::pair<T,std::vector<edge2<T>>> minimum_spanning_tree(const\
    \ std::vector<edge2<T>> &_es,bool sorted = false){\n    std::vector<edge2<T>>\
    \ es = _es;\n    if(!sorted)std::sort(es.begin(),es.end(),[](const edge2<T> a,const\
    \ edge2<T> b){return a.cost < b.cost;});\n    int n = es.size();\n    std::pair<T,std::vector<edge2<T>>>\
    \ res;\n    UnionFind UF(n);\n    for(edge2<T>& e : es){\n        if(!UF.same(e.from,e.to)){\n\
    \            res.first += e.cost;\n            res.second.push_back(e);\n    \
    \    }\n    }\n    return res;\n}\n\n#endif /*SORAIE_MST*/"
  dependsOn:
  - data-structure/unionfind.hpp
  - utils/graph_alias.hpp
  isVerificationFile: false
  path: algorithm/minimum_spanning_tree.hpp
  requiredBy: []
  timestamp: '2021-03-31 10:49:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/minimum_spanning_tree.hpp
layout: document
redirect_from:
- /library/algorithm/minimum_spanning_tree.hpp
- /library/algorithm/minimum_spanning_tree.hpp.html
title: algorithm/minimum_spanning_tree.hpp
---
