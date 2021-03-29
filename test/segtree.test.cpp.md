---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree.hpp
    title: data-structure/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
  bundledCode: "#line 1 \"test/segtree.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n\n#include <iostream>\n#include <algorithm>\n\n#line 1 \"data-structure/segtree.hpp\"\
    \n\n\n\n#line 5 \"data-structure/segtree.hpp\"\n#include <cassert>\n#include <vector>\n\
    \ntemplate<class S,S (*op)(S,S),S (*e)()>\nstruct segtree{\n    segtree() : segtree(0)\
    \ {}\n    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}\n    explicit\
    \ segtree(const std::vector<S>& v) : _n(int(v.size())) {\n        log = 0,size\
    \ = 1;\n        while(size < _n)size <<= 1,log++;\n        size = 1 << log;\n\
    \        d = std::vector<S>(2 * size,e());\n        for (int i = 0;i < _n;i++)d[size\
    \ + i] = v[i];\n        for (int i = size - 1;i >= 1;i--)update(i);\n    }\n\n\
    \    void set(int p, S x){\n        assert(0 <= p && p < _n);\n        p += size;\n\
    \        d[p] = x;\n        for(int i = 1;i <= log;i++)update(p >> i);\n    }\n\
    \n    S get(int p) const {\n        assert(0 <= p && p < _n);\n        return\
    \ d[p + size];\n    }\n\n    S prod(int l, int r) const {\n        assert(0 <=\
    \ l && l <= r && r <= _n);\n        S sml = e(),smr = e();\n        l += size;\n\
    \        r += size;\n\n        while(l < r){\n            if(l & 1)sml = op(sml,d[l++]);\n\
    \            if(r & 1)smr = op(d[--r],smr);\n            l >>= 1;\n          \
    \  r >>= 1;\n        }\n        return op(sml,smr);\n    }\n\n    S all_prod()const{return\
    \ d[1];}\n\n    template <bool (*f)(S)> int max_right(int l) const {\n       \
    \ return max_right(l, [](S x) { return f(x); });\n    }\n    template <class F>\
    \ int max_right(int l, F f) const {\n        assert(0 <= l && l <= _n);\n    \
    \    assert(f(e()));\n        if (l == _n) return _n;\n        l += size;\n  \
    \      S sm = e();\n        do {\n            while (l % 2 == 0) l >>= 1;\n  \
    \          if (!f(op(sm, d[l]))) {\n                while (l < size) {\n     \
    \               l = (2 * l);\n                    if (f(op(sm, d[l]))) {\n   \
    \                     sm = op(sm, d[l]);\n                        l++;\n     \
    \               }\n                }\n                return l - size;\n     \
    \       }\n            sm = op(sm, d[l]);\n            l++;\n        } while ((l\
    \ & -l) != l);\n        return _n;\n    }\n\n    template <bool (*f)(S)> int min_left(int\
    \ r) const {\n        return min_left(r, [](S x) { return f(x); });\n    }\n \
    \   template <class F> int min_left(int r, F f) const {\n        assert(0 <= r\
    \ && r <= _n);\n        assert(f(e()));\n        if (r == 0) return 0;\n     \
    \   r += size;\n        S sm = e();\n        do {\n            r--;\n        \
    \    while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(d[r], sm))) {\n\
    \                while (r < size) {\n                    r = (2 * r + 1);\n  \
    \                  if (f(op(d[r], sm))) {\n                        sm = op(d[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = op(d[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\n  private:\n\
    \    int _n,size,log;\n    std::vector<S> d;\n\n    void update(int k){d[k] =\
    \ op(d[2 * k],d[2 * k + 1]);}\n};\n\n\n#line 7 \"test/segtree.test.cpp\"\n\nusing\
    \ S = int;\nS op(S a,S b){return std::min(a,b);}\nS e(){return INT32_MAX;}\n\n\
    int main(){\n    int N,Q;\n    std::cin >> N >> Q;\n    segtree<S,op,e> st(N);\n\
    \    for(int i = 0;i < Q;i++){\n        int t,a,b;\n        std::cin >> t >> a\
    \ >> b;\n        if(t == 0){\n            st.set(a,b);\n        }\n        if(t\
    \ == 1){\n            std::cout << st.prod(a,b + 1) << \"\\n\";\n        }\n \
    \   }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n\n#include <iostream>\n#include <algorithm>\n\n#include \"../data-structure/segtree.hpp\"\
    \n\nusing S = int;\nS op(S a,S b){return std::min(a,b);}\nS e(){return INT32_MAX;}\n\
    \nint main(){\n    int N,Q;\n    std::cin >> N >> Q;\n    segtree<S,op,e> st(N);\n\
    \    for(int i = 0;i < Q;i++){\n        int t,a,b;\n        std::cin >> t >> a\
    \ >> b;\n        if(t == 0){\n            st.set(a,b);\n        }\n        if(t\
    \ == 1){\n            std::cout << st.prod(a,b + 1) << \"\\n\";\n        }\n \
    \   }\n}\n"
  dependsOn:
  - data-structure/segtree.hpp
  isVerificationFile: true
  path: test/segtree.test.cpp
  requiredBy: []
  timestamp: '2021-03-28 19:07:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segtree.test.cpp
layout: document
redirect_from:
- /verify/test/segtree.test.cpp
- /verify/test/segtree.test.cpp.html
title: test/segtree.test.cpp
---
