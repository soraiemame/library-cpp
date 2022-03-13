---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Mo.hpp\"\n\n\n\n#include <iostream>\n#include\
    \ <vector>\n#include <algorithm>\n#include <cmath>\n#include <numeric>\n\nstruct\
    \ Mo {\n    explicit Mo(int n) : n(n) {}\n    void add(int l,int r) {\n      \
    \  lr.emplace_back(l,r);\n    }\n    template<class AL,class AR,class EL,class\
    \ ER,class O>\n    void build(const AL& add_left,const AR& add_right,const EL&\
    \ erase_left,const ER& erase_right,const O& out) {\n        int q = int(lr.size());\n\
    \        if(q == 0) {\n            std::cerr << \"No queries found.\\n\";\n  \
    \          return;\n        }\n        int bs = n / std::min<int>(n,std::sqrt(q));\n\
    \        std::vector<int> ord(q);\n        std::iota(ord.begin(), ord.end(), 0);\n\
    \        std::sort(ord.begin(),ord.end(),[&](int a,int b){\n            int abl\
    \ = lr[a].first / bs,bbl = lr[b].first / bs;\n            if(abl != bbl) return\
    \ abl < bbl;\n            else return (abl & 1) ? lr[a].second > lr[b].second\
    \ : lr[a].second < lr[b].second;\n        });\n        int cl = 0,cr = 0;\n  \
    \      for(int idx : ord) {\n            while(cl > lr[idx].first)  add_left(--cl);\n\
    \            while(cr < lr[idx].second) add_right(cr++);\n            while(cl\
    \ < lr[idx].first)  erase_left(cl++);\n            while(cr > lr[idx].second)\
    \ erase_right(--cr);\n            out(idx);\n        }\n    }\n    template<class\
    \ A,class E,class O>\n    void build(const A& add,const E& erase,const O& out)\
    \ { build(add,add,erase,erase,out); }\nprivate:\n    int n;\n    std::vector<std::pair<int,int>>\
    \ lr;\n};\n\n\n"
  code: "#ifndef SORAIE_MO\n#define SORAIE_MO\n\n#include <iostream>\n#include <vector>\n\
    #include <algorithm>\n#include <cmath>\n#include <numeric>\n\nstruct Mo {\n  \
    \  explicit Mo(int n) : n(n) {}\n    void add(int l,int r) {\n        lr.emplace_back(l,r);\n\
    \    }\n    template<class AL,class AR,class EL,class ER,class O>\n    void build(const\
    \ AL& add_left,const AR& add_right,const EL& erase_left,const ER& erase_right,const\
    \ O& out) {\n        int q = int(lr.size());\n        if(q == 0) {\n         \
    \   std::cerr << \"No queries found.\\n\";\n            return;\n        }\n \
    \       int bs = n / std::min<int>(n,std::sqrt(q));\n        std::vector<int>\
    \ ord(q);\n        std::iota(ord.begin(), ord.end(), 0);\n        std::sort(ord.begin(),ord.end(),[&](int\
    \ a,int b){\n            int abl = lr[a].first / bs,bbl = lr[b].first / bs;\n\
    \            if(abl != bbl) return abl < bbl;\n            else return (abl &\
    \ 1) ? lr[a].second > lr[b].second : lr[a].second < lr[b].second;\n        });\n\
    \        int cl = 0,cr = 0;\n        for(int idx : ord) {\n            while(cl\
    \ > lr[idx].first)  add_left(--cl);\n            while(cr < lr[idx].second) add_right(cr++);\n\
    \            while(cl < lr[idx].first)  erase_left(cl++);\n            while(cr\
    \ > lr[idx].second) erase_right(--cr);\n            out(idx);\n        }\n   \
    \ }\n    template<class A,class E,class O>\n    void build(const A& add,const\
    \ E& erase,const O& out) { build(add,add,erase,erase,out); }\nprivate:\n    int\
    \ n;\n    std::vector<std::pair<int,int>> lr;\n};\n\n#endif /*SORIAE_MO*/"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Mo.hpp
  requiredBy: []
  timestamp: '2022-03-13 11:22:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/Mo.hpp
layout: document
redirect_from:
- /library/algorithm/Mo.hpp
- /library/algorithm/Mo.hpp.html
title: algorithm/Mo.hpp
---
