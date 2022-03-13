---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent_array.hpp
    title: data-structure/persistent_array.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent_unionfind.hpp
    title: data-structure/persistent_unionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"test/persistent_unionfind.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/persistent_unionfind\"\n\n#include <iostream>\n\
    #include <vector>\n\n#line 1 \"data-structure/persistent_unionfind.hpp\"\n\n\n\
    \n#include <cassert>\n#include <algorithm>\n\n#line 1 \"data-structure/persistent_array.hpp\"\
    \n\n\n\n#line 5 \"data-structure/persistent_array.hpp\"\n#include <cstring>\n\n\
    template<class T, int csz = 16>\nstruct PersistentArray {\nprivate:\n    struct\
    \ node;\n    using np = node*;\n    struct node {\n        T val;\n        np\
    \ ch[csz] = {};\n    };\n\n    np root;\n\n    np set(int idx, const T& x, const\
    \ np& t) {\n        np res = new node();\n        if (t) {\n            memcpy(res->ch,\
    \ t->ch, sizeof(t->ch));\n            res->val = t->val;\n        }\n        if\
    \ (idx == 0) res->val = x;\n        else res->ch[idx % csz] = set(idx / csz, x,\
    \ res->ch[idx % csz]);\n        return res;\n    }\n\n    T get(int idx, const\
    \ np& t) const {\n        if (idx == 0)return t->val;\n        return get(idx\
    \ / csz, t->ch[idx % csz]);\n    }\n\npublic:\n    int n;\n\n    void set(int\
    \ idx, const T& x) {\n        assert(0 <= idx && (n < 0 || idx < n));\n      \
    \  root = set(idx, x, root);\n    }\n\n    T get(int idx) const {\n        assert(0\
    \ <= idx && (n < 0 || idx < n));\n        return get(idx, root);\n    }\n\n  \
    \  PersistentArray(int n = -1) : root(nullptr), n(n) {}\n\n    template<class\
    \ stream> friend stream& operator<<(stream& os, const PersistentArray& a) {\n\
    \        assert(a.n >= 0);\n        os << '[';\n        for (int i = 0;i < a.n;i++)os\
    \ << a.get(i) << (i == a.n - 1 ? \"\" : \",\");\n        os << ']';\n        return\
    \ os;\n    }\n};\n\n\n#line 8 \"data-structure/persistent_unionfind.hpp\"\n\n\
    struct PersistentUnionFind {\n    PersistentUnionFind(int n = 0) : n(n), dat(n)\
    \ {\n        for (int i = 0;i < n;i++)dat.set(i, -1);\n    }\n\n    int find(int\
    \ a) const {\n        assert(0 <= a && a < n);\n        if (dat.get(a) < 0)return\
    \ a;\n        else return find(dat.get(a));\n    }\n\n    void merge(int a, int\
    \ b) {\n        assert(0 <= a && a < n && 0 <= b && b < n);\n        a = find(a);\n\
    \        b = find(b);\n        if (a == b)return;\n        if (dat.get(a) > dat.get(b))std::swap(a,\
    \ b);\n        dat.set(a, dat.get(a) + dat.get(b));\n        dat.set(b, a);\n\
    \    }\n\n    bool same(int a, int b) const {\n        assert(0 <= a && a < n\
    \ && 0 <= b && b < n);\n        return find(a) == find(b);\n    }\n\n    int size(int\
    \ a) const {\n        assert(0 <= a && a < n);\n        return -dat.get(find(a));\n\
    \    }\n\n    template<class stream> friend stream& operator<<(stream& os, const\
    \ PersistentUnionFind& a) { return os << a.dat; }\n\n    int n;\n    PersistentArray<int>\
    \ dat;\n};\n\n\n#line 7 \"test/persistent_unionfind.test.cpp\"\n\nint main(){\n\
    \    int N,Q;\n    std::cin >> N >> Q;\n    std::vector<PersistentUnionFind> ufs(Q\
    \ + 1,PersistentUnionFind(N));\n    for(int i = 0;i < Q;i++){\n        int t,k,u,v;\n\
    \        std::cin >> t >> k >> u >> v;\n        if(t == 0){\n            ufs[i\
    \ + 1] = ufs[k + 1];\n            ufs[i + 1].merge(u,v);\n        }\n        else{\n\
    \            std::cout << ufs[k + 1].same(u,v) << \"\\n\";\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include <iostream>\n#include <vector>\n\n#include \"../data-structure/persistent_unionfind.hpp\"\
    \n\nint main(){\n    int N,Q;\n    std::cin >> N >> Q;\n    std::vector<PersistentUnionFind>\
    \ ufs(Q + 1,PersistentUnionFind(N));\n    for(int i = 0;i < Q;i++){\n        int\
    \ t,k,u,v;\n        std::cin >> t >> k >> u >> v;\n        if(t == 0){\n     \
    \       ufs[i + 1] = ufs[k + 1];\n            ufs[i + 1].merge(u,v);\n       \
    \ }\n        else{\n            std::cout << ufs[k + 1].same(u,v) << \"\\n\";\n\
    \        }\n    }\n}\n"
  dependsOn:
  - data-structure/persistent_unionfind.hpp
  - data-structure/persistent_array.hpp
  isVerificationFile: true
  path: test/persistent_unionfind.test.cpp
  requiredBy: []
  timestamp: '2021-12-26 12:05:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/persistent_unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/persistent_unionfind.test.cpp
- /verify/test/persistent_unionfind.test.cpp.html
title: test/persistent_unionfind.test.cpp
---