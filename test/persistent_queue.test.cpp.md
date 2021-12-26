---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent_array.hpp
    title: data-structure/persistent_array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_queue
    links:
    - https://judge.yosupo.jp/problem/persistent_queue
  bundledCode: "#line 1 \"test/persistent_queue.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 1 \"data-structure/persistent_array.hpp\"\
    \n\n\n\n#include <cassert>\n#include <cstring>\n\ntemplate<class T, int csz =\
    \ 16>\nstruct PersistentArray {\nprivate:\n    struct node;\n    using np = node*;\n\
    \    struct node {\n        T val;\n        np ch[csz] = {};\n    };\n\n    np\
    \ root;\n\n    np set(int idx, const T& x, const np& t) {\n        np res = new\
    \ node();\n        if (t) {\n            memcpy(res->ch, t->ch, sizeof(t->ch));\n\
    \            res->val = t->val;\n        }\n        if (idx == 0) res->val = x;\n\
    \        else res->ch[idx % csz] = set(idx / csz, x, res->ch[idx % csz]);\n  \
    \      return res;\n    }\n\n    T get(int idx, const np& t) const {\n       \
    \ if (idx == 0)return t->val;\n        return get(idx / csz, t->ch[idx % csz]);\n\
    \    }\n\npublic:\n    int n;\n\n    void set(int idx, const T& x) {\n       \
    \ assert(0 <= idx && (n < 0 || idx < n));\n        root = set(idx, x, root);\n\
    \    }\n\n    T get(int idx) const {\n        assert(0 <= idx && (n < 0 || idx\
    \ < n));\n        return get(idx, root);\n    }\n\n    PersistentArray(int n =\
    \ -1) : root(nullptr), n(n) {}\n\n    template<class stream> friend stream& operator<<(stream&\
    \ os, const PersistentArray& a) {\n        assert(a.n >= 0);\n        os << '[';\n\
    \        for (int i = 0;i < a.n;i++)os << a.get(i) << (i == a.n - 1 ? \"\" : \"\
    ,\");\n        os << ']';\n        return os;\n    }\n};\n\n\n#line 7 \"test/persistent_queue.test.cpp\"\
    \n\nint main(){\n    int Q;\n    std::cin >> Q;\n    std::vector<PersistentArray<int>>\
    \ qs(Q + 1,PersistentArray<int>(Q));\n    std::vector<int> fr(Q + 1),ba(Q + 1);\n\
    \    for(int i = 0;i < Q;i++){\n        int q,t;\n        std::cin >> q >> t;\n\
    \        if(q == 0){\n            int x;\n            std::cin >> x;\n       \
    \     qs[i + 1] = qs[t + 1];\n            fr[i + 1] = fr[t + 1];\n           \
    \ ba[i + 1] = ba[t + 1];\n            qs[i + 1].set(ba[i + 1],x);\n          \
    \  ba[i + 1]++;\n        }\n        else{\n            std::cout << qs[t + 1].get(fr[t\
    \ + 1]) << \"\\n\";\n            qs[i + 1] = qs[t + 1];\n            fr[i + 1]\
    \ = fr[t + 1];\n            ba[i + 1] = ba[t + 1];\n            fr[i + 1]++;\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\n\n\
    #include <iostream>\n#include <vector>\n\n#include \"../data-structure/persistent_array.hpp\"\
    \n\nint main(){\n    int Q;\n    std::cin >> Q;\n    std::vector<PersistentArray<int>>\
    \ qs(Q + 1,PersistentArray<int>(Q));\n    std::vector<int> fr(Q + 1),ba(Q + 1);\n\
    \    for(int i = 0;i < Q;i++){\n        int q,t;\n        std::cin >> q >> t;\n\
    \        if(q == 0){\n            int x;\n            std::cin >> x;\n       \
    \     qs[i + 1] = qs[t + 1];\n            fr[i + 1] = fr[t + 1];\n           \
    \ ba[i + 1] = ba[t + 1];\n            qs[i + 1].set(ba[i + 1],x);\n          \
    \  ba[i + 1]++;\n        }\n        else{\n            std::cout << qs[t + 1].get(fr[t\
    \ + 1]) << \"\\n\";\n            qs[i + 1] = qs[t + 1];\n            fr[i + 1]\
    \ = fr[t + 1];\n            ba[i + 1] = ba[t + 1];\n            fr[i + 1]++;\n\
    \        }\n    }\n}\n"
  dependsOn:
  - data-structure/persistent_array.hpp
  isVerificationFile: true
  path: test/persistent_queue.test.cpp
  requiredBy: []
  timestamp: '2021-12-26 12:05:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/persistent_queue.test.cpp
layout: document
redirect_from:
- /verify/test/persistent_queue.test.cpp
- /verify/test/persistent_queue.test.cpp.html
title: test/persistent_queue.test.cpp
---
