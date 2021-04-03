---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/lichaotree.hpp
    title: data-structure/lichaotree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"test/lichaotree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\
    \n\n#include <iostream>\n#include <vector>\n#include <array>\n\n#line 1 \"data-structure/lichaotree.hpp\"\
    \n\n\n\n#include <algorithm>\n#line 6 \"data-structure/lichaotree.hpp\"\n\ntemplate<class\
    \ T,int MIN = 1>\nstruct LiChaoTree{\n    const T linf = std::numeric_limits<T>::max();\n\
    private:\n    using Line = std::pair<T,T>;\n\n    int n;\n    std::vector<T> xl;\n\
    \    std::vector<Line> dat;\n\n    T eval(Line f,T x){return f.first * x + f.second;}\n\
    \n    void inner_update(Line f,int k,int l,int r){\n        f = Line(f.first *\
    \ MIN,f.second * MIN);\n        while(l != r){\n            int m = (l + r) >>\
    \ 1;\n            T lx = xl[l],mx = xl[m],rx = xl[r - 1];\n            Line &g\
    \ = dat[k];\n            if(eval(f,lx) < eval(g,lx) && eval(f,rx) < eval(g,rx)){\n\
    \                g = f;\n                return;\n            }\n            if(eval(f,lx)\
    \ >= eval(g,lx) && eval(f,rx) >= eval(g,rx))return;\n            if(eval(f,mx)\
    \ < eval(g,mx))swap(f,g);\n            if(eval(f,lx) < eval(g,lx)){\n        \
    \        k = (k << 1) + 1;\n                r = m;\n            }\n          \
    \  else{\n                k = (k << 1) + 2;\n                l = m;\n        \
    \    }\n        }\n    }\n    \npublic:\n    LiChaoTree(const std::vector<T>&\
    \ _xl){\n        xl = _xl;\n        xl.push_back(std::numeric_limits<T>::max());\n\
    \        xl.push_back(std::numeric_limits<T>::min());\n        std::sort(xl.begin(),xl.end());xl.erase(std::unique(xl.begin(),xl.end()),xl.end());\n\
    \        n = 1;\n        while(n < xl.size())n <<= 1;\n        xl.resize(n,xl.back());\n\
    \        dat = std::vector<Line>(n << 1,Line(0,linf));\n    }\n    \n    void\
    \ add_line(Line f){inner_update(f,0,0,n);}\n    void add_line(T a,T b){inner_update(Line(a,b));}\n\
    \n    // [lx,rx)\n    void add_segment(Line f,T lx,T rx){\n        int l = std::lower_bound(xl.begin(),xl.end(),lx)\
    \ - xl.begin(),r = std::lower_bound(xl.begin(),xl.end(),rx) - xl.begin();\n  \
    \      int a0 = l,b0 = r;\n        l += n;r += n;\n        int sz = 1;\n     \
    \   while(l < r){\n            if(r & 1){\n                r--;\n            \
    \    b0 -= sz;\n                inner_update(f,r - 1,b0,b0 + sz);\n          \
    \  }\n            if(l & 1){\n                inner_update(f,l - 1,a0,a0 + sz);\n\
    \                l++;\n                a0 += sz;\n            }\n            l\
    \ >>= 1;r >>= 1;\n            sz <<= 1;\n        }\n    }\n\n    // [lx,rx)\n\
    \    void add_segment(T a,T b,T lx,T rx){add_segment(Line(a,b),lx,rx);}\n\n  \
    \  T get(T x){\n        x *= MIN;\n        int i = std::lower_bound(xl.begin(),xl.end(),x)\
    \ - xl.begin();\n        i += n - 1;\n        T res = eval(dat[i],x);\n      \
    \  while(i){\n            i = (i - 1) >> 1;\n            res = std::min(res,eval(dat[i],x));\n\
    \        }\n        return res;\n    }\n};\n\n\n#line 8 \"test/lichaotree.test.cpp\"\
    \n\nint main(){\n    int N,Q;\n    std::cin >> N >> Q;\n    std::vector<long long>\
    \ A(N),B(N),L(N),R(N);\n    for(int i = 0;i < N;i++)std::cin >> L[i] >> R[i] >>\
    \ A[i] >> B[i];\n    std::vector<int> t(Q);\n    std::vector<std::array<long long,4>>\
    \ query(Q);\n    std::vector<long long> xl;\n    for(int i = 0;i < Q;i++){\n \
    \       std::cin >> t[i];\n        if(t[i] == 0){\n            std::cin >> query[i][2]\
    \ >> query[i][3] >> query[i][0] >> query[i][1];\n        }\n        else{\n  \
    \          std::cin >> query[i][0];\n            xl.push_back(query[i][0]);\n\
    \        }\n    }\n    LiChaoTree<long long> cht(xl);\n    for(int i = 0;i < N;i++)cht.add_segment(A[i],B[i],L[i],R[i]);\n\
    \    for(int i = 0;i < Q;i++){\n        if(t[i] == 0)cht.add_segment(query[i][0],query[i][1],query[i][2],query[i][3]);\n\
    \        else{\n            long long ans = cht.get(query[i][0]);\n          \
    \  if(ans == 0)std::cout << \"INFINITY\\n\";\n            else std::cout << ans\
    \ << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    \n#include <iostream>\n#include <vector>\n#include <array>\n\n#include \"../data-structure/lichaotree.hpp\"\
    \n\nint main(){\n    int N,Q;\n    std::cin >> N >> Q;\n    std::vector<long long>\
    \ A(N),B(N),L(N),R(N);\n    for(int i = 0;i < N;i++)std::cin >> L[i] >> R[i] >>\
    \ A[i] >> B[i];\n    std::vector<int> t(Q);\n    std::vector<std::array<long long,4>>\
    \ query(Q);\n    std::vector<long long> xl;\n    for(int i = 0;i < Q;i++){\n \
    \       std::cin >> t[i];\n        if(t[i] == 0){\n            std::cin >> query[i][2]\
    \ >> query[i][3] >> query[i][0] >> query[i][1];\n        }\n        else{\n  \
    \          std::cin >> query[i][0];\n            xl.push_back(query[i][0]);\n\
    \        }\n    }\n    LiChaoTree<long long> cht(xl);\n    for(int i = 0;i < N;i++)cht.add_segment(A[i],B[i],L[i],R[i]);\n\
    \    for(int i = 0;i < Q;i++){\n        if(t[i] == 0)cht.add_segment(query[i][0],query[i][1],query[i][2],query[i][3]);\n\
    \        else{\n            long long ans = cht.get(query[i][0]);\n          \
    \  if(ans == 0)std::cout << \"INFINITY\\n\";\n            else std::cout << ans\
    \ << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - data-structure/lichaotree.hpp
  isVerificationFile: true
  path: test/lichaotree.test.cpp
  requiredBy: []
  timestamp: '2021-04-03 15:07:18+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/lichaotree.test.cpp
layout: document
redirect_from:
- /verify/test/lichaotree.test.cpp
- /verify/test/lichaotree.test.cpp.html
title: test/lichaotree.test.cpp
---
