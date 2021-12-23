---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/lichaotree.test.cpp
    title: test/lichaotree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/lichaotree.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <vector>\n\ntemplate<class T,int MIN = 1>\nstruct LiChaoTree{\n    const\
    \ T linf = std::numeric_limits<T>::max();\nprivate:\n    using Line = std::pair<T,T>;\n\
    \n    int n;\n    std::vector<T> xl;\n    std::vector<Line> dat;\n\n    T eval(Line\
    \ f,T x){return f.first * x + f.second;}\n\n    void inner_update(Line f,int k,int\
    \ l,int r){\n        f = Line(f.first * MIN,f.second * MIN);\n        while(l\
    \ != r){\n            int m = (l + r) >> 1;\n            T lx = xl[l],mx = xl[m],rx\
    \ = xl[r - 1];\n            Line &g = dat[k];\n            if(eval(f,lx) < eval(g,lx)\
    \ && eval(f,rx) < eval(g,rx)){\n                g = f;\n                return;\n\
    \            }\n            if(eval(f,lx) >= eval(g,lx) && eval(f,rx) >= eval(g,rx))return;\n\
    \            if(eval(f,mx) < eval(g,mx))swap(f,g);\n            if(eval(f,lx)\
    \ < eval(g,lx)){\n                k = (k << 1) + 1;\n                r = m;\n\
    \            }\n            else{\n                k = (k << 1) + 2;\n       \
    \         l = m;\n            }\n        }\n    }\n    \npublic:\n    LiChaoTree(const\
    \ std::vector<T>& _xl){\n        xl = _xl;\n        xl.push_back(std::numeric_limits<T>::max());\n\
    \        xl.push_back(std::numeric_limits<T>::min());\n        std::sort(xl.begin(),xl.end());xl.erase(std::unique(xl.begin(),xl.end()),xl.end());\n\
    \        int _n = xl.size();\n        n = 1;\n        while(n < _n)n <<= 1;\n\
    \        xl.resize(n,xl.back());\n        dat = std::vector<Line>(n << 1,Line(0,linf));\n\
    \    }\n    \n    void add_line(Line f){inner_update(f,0,0,n);}\n    void add_line(T\
    \ a,T b){inner_update(Line(a,b));}\n\n    // [lx,rx)\n    void add_segment(Line\
    \ f,T lx,T rx){\n        int l = std::lower_bound(xl.begin(),xl.end(),lx) - xl.begin(),r\
    \ = std::lower_bound(xl.begin(),xl.end(),rx) - xl.begin();\n        int a0 = l,b0\
    \ = r;\n        l += n;r += n;\n        int sz = 1;\n        while(l < r){\n \
    \           if(r & 1){\n                r--;\n                b0 -= sz;\n    \
    \            inner_update(f,r - 1,b0,b0 + sz);\n            }\n            if(l\
    \ & 1){\n                inner_update(f,l - 1,a0,a0 + sz);\n                l++;\n\
    \                a0 += sz;\n            }\n            l >>= 1;r >>= 1;\n    \
    \        sz <<= 1;\n        }\n    }\n\n    // [lx,rx)\n    void add_segment(T\
    \ a,T b,T lx,T rx){add_segment(Line(a,b),lx,rx);}\n\n    T get(T x){\n       \
    \ x *= MIN;\n        int i = std::lower_bound(xl.begin(),xl.end(),x) - xl.begin();\n\
    \        i += n - 1;\n        T res = eval(dat[i],x);\n        while(i){\n   \
    \         i = (i - 1) >> 1;\n            res = std::min(res,eval(dat[i],x));\n\
    \        }\n        return res;\n    }\n};\n\n\n"
  code: "#ifndef SORAIE_LICHAO\n#define SORAIE_LICHAO\n\n#include <algorithm>\n#include\
    \ <vector>\n\ntemplate<class T,int MIN = 1>\nstruct LiChaoTree{\n    const T linf\
    \ = std::numeric_limits<T>::max();\nprivate:\n    using Line = std::pair<T,T>;\n\
    \n    int n;\n    std::vector<T> xl;\n    std::vector<Line> dat;\n\n    T eval(Line\
    \ f,T x){return f.first * x + f.second;}\n\n    void inner_update(Line f,int k,int\
    \ l,int r){\n        f = Line(f.first * MIN,f.second * MIN);\n        while(l\
    \ != r){\n            int m = (l + r) >> 1;\n            T lx = xl[l],mx = xl[m],rx\
    \ = xl[r - 1];\n            Line &g = dat[k];\n            if(eval(f,lx) < eval(g,lx)\
    \ && eval(f,rx) < eval(g,rx)){\n                g = f;\n                return;\n\
    \            }\n            if(eval(f,lx) >= eval(g,lx) && eval(f,rx) >= eval(g,rx))return;\n\
    \            if(eval(f,mx) < eval(g,mx))swap(f,g);\n            if(eval(f,lx)\
    \ < eval(g,lx)){\n                k = (k << 1) + 1;\n                r = m;\n\
    \            }\n            else{\n                k = (k << 1) + 2;\n       \
    \         l = m;\n            }\n        }\n    }\n    \npublic:\n    LiChaoTree(const\
    \ std::vector<T>& _xl){\n        xl = _xl;\n        xl.push_back(std::numeric_limits<T>::max());\n\
    \        xl.push_back(std::numeric_limits<T>::min());\n        std::sort(xl.begin(),xl.end());xl.erase(std::unique(xl.begin(),xl.end()),xl.end());\n\
    \        int _n = xl.size();\n        n = 1;\n        while(n < _n)n <<= 1;\n\
    \        xl.resize(n,xl.back());\n        dat = std::vector<Line>(n << 1,Line(0,linf));\n\
    \    }\n    \n    void add_line(Line f){inner_update(f,0,0,n);}\n    void add_line(T\
    \ a,T b){inner_update(Line(a,b));}\n\n    // [lx,rx)\n    void add_segment(Line\
    \ f,T lx,T rx){\n        int l = std::lower_bound(xl.begin(),xl.end(),lx) - xl.begin(),r\
    \ = std::lower_bound(xl.begin(),xl.end(),rx) - xl.begin();\n        int a0 = l,b0\
    \ = r;\n        l += n;r += n;\n        int sz = 1;\n        while(l < r){\n \
    \           if(r & 1){\n                r--;\n                b0 -= sz;\n    \
    \            inner_update(f,r - 1,b0,b0 + sz);\n            }\n            if(l\
    \ & 1){\n                inner_update(f,l - 1,a0,a0 + sz);\n                l++;\n\
    \                a0 += sz;\n            }\n            l >>= 1;r >>= 1;\n    \
    \        sz <<= 1;\n        }\n    }\n\n    // [lx,rx)\n    void add_segment(T\
    \ a,T b,T lx,T rx){add_segment(Line(a,b),lx,rx);}\n\n    T get(T x){\n       \
    \ x *= MIN;\n        int i = std::lower_bound(xl.begin(),xl.end(),x) - xl.begin();\n\
    \        i += n - 1;\n        T res = eval(dat[i],x);\n        while(i){\n   \
    \         i = (i - 1) >> 1;\n            res = std::min(res,eval(dat[i],x));\n\
    \        }\n        return res;\n    }\n};\n\n#endif /*SORAIE_LICHAO*/"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/lichaotree.hpp
  requiredBy: []
  timestamp: '2021-04-03 15:14:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/lichaotree.test.cpp
documentation_of: data-structure/lichaotree.hpp
layout: document
redirect_from:
- /library/data-structure/lichaotree.hpp
- /library/data-structure/lichaotree.hpp.html
title: data-structure/lichaotree.hpp
---
