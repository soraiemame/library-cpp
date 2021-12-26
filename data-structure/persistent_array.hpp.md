---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent_unionfind.hpp
    title: data-structure/persistent_unionfind.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/persistent_queue.test.cpp
    title: test/persistent_queue.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/persistent_unionfind.test.cpp
    title: test/persistent_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/persistent_array.hpp\"\n\n\n\n#include <cassert>\n\
    #include <cstring>\n\ntemplate<class T, int csz = 16>\nstruct PersistentArray\
    \ {\nprivate:\n    struct node;\n    using np = node*;\n    struct node {\n  \
    \      T val;\n        np ch[csz] = {};\n    };\n\n    np root;\n\n    np set(int\
    \ idx, const T& x, const np& t) {\n        np res = new node();\n        if (t)\
    \ {\n            memcpy(res->ch, t->ch, sizeof(t->ch));\n            res->val\
    \ = t->val;\n        }\n        if (idx == 0) res->val = x;\n        else res->ch[idx\
    \ % csz] = set(idx / csz, x, res->ch[idx % csz]);\n        return res;\n    }\n\
    \n    T get(int idx, const np& t) const {\n        if (idx == 0)return t->val;\n\
    \        return get(idx / csz, t->ch[idx % csz]);\n    }\n\npublic:\n    int n;\n\
    \n    void set(int idx, const T& x) {\n        assert(0 <= idx && (n < 0 || idx\
    \ < n));\n        root = set(idx, x, root);\n    }\n\n    T get(int idx) const\
    \ {\n        assert(0 <= idx && (n < 0 || idx < n));\n        return get(idx,\
    \ root);\n    }\n\n    PersistentArray(int n = -1) : root(nullptr), n(n) {}\n\n\
    \    template<class stream> friend stream& operator<<(stream& os, const PersistentArray&\
    \ a) {\n        assert(a.n >= 0);\n        os << '[';\n        for (int i = 0;i\
    \ < a.n;i++)os << a.get(i) << (i == a.n - 1 ? \"\" : \",\");\n        os << ']';\n\
    \        return os;\n    }\n};\n\n\n"
  code: "#ifndef SORIAE_PERSISTENT_ARRAY\n#define SORIAE_PERSISTENT_ARRAY\n\n#include\
    \ <cassert>\n#include <cstring>\n\ntemplate<class T, int csz = 16>\nstruct PersistentArray\
    \ {\nprivate:\n    struct node;\n    using np = node*;\n    struct node {\n  \
    \      T val;\n        np ch[csz] = {};\n    };\n\n    np root;\n\n    np set(int\
    \ idx, const T& x, const np& t) {\n        np res = new node();\n        if (t)\
    \ {\n            memcpy(res->ch, t->ch, sizeof(t->ch));\n            res->val\
    \ = t->val;\n        }\n        if (idx == 0) res->val = x;\n        else res->ch[idx\
    \ % csz] = set(idx / csz, x, res->ch[idx % csz]);\n        return res;\n    }\n\
    \n    T get(int idx, const np& t) const {\n        if (idx == 0)return t->val;\n\
    \        return get(idx / csz, t->ch[idx % csz]);\n    }\n\npublic:\n    int n;\n\
    \n    void set(int idx, const T& x) {\n        assert(0 <= idx && (n < 0 || idx\
    \ < n));\n        root = set(idx, x, root);\n    }\n\n    T get(int idx) const\
    \ {\n        assert(0 <= idx && (n < 0 || idx < n));\n        return get(idx,\
    \ root);\n    }\n\n    PersistentArray(int n = -1) : root(nullptr), n(n) {}\n\n\
    \    template<class stream> friend stream& operator<<(stream& os, const PersistentArray&\
    \ a) {\n        assert(a.n >= 0);\n        os << '[';\n        for (int i = 0;i\
    \ < a.n;i++)os << a.get(i) << (i == a.n - 1 ? \"\" : \",\");\n        os << ']';\n\
    \        return os;\n    }\n};\n\n#endif /*SORIAE_PERSISTENT_ARRAY*/"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/persistent_array.hpp
  requiredBy:
  - data-structure/persistent_unionfind.hpp
  timestamp: '2021-12-26 12:05:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/persistent_unionfind.test.cpp
  - test/persistent_queue.test.cpp
documentation_of: data-structure/persistent_array.hpp
layout: document
redirect_from:
- /library/data-structure/persistent_array.hpp
- /library/data-structure/persistent_array.hpp.html
title: data-structure/persistent_array.hpp
---
