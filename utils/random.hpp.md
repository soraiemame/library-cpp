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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: randbase.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef SORAIE_RANDOM\n#define SORAIE_RANDOM\n\n#include <set>\n\n#include\
    \ \"randbase.hpp\"\n#include \"../data-structure/unionfind.hpp\"\n\nnamespace\
    \ my_rand{\n\n    template <typename T>\n    void randshf(std::vector<T>& v){\n\
    \        int n = v.size();\n        for(int loop = 0;loop < 2;loop++)for(int i\
    \ = 0;i < n;i++)std::swap(v[i],v[randint(0, n)]);\n    }\n\n    std::vector<int64_t>\
    \ randvec(int len,int64_t l,int64_t r){\n        std::vector<int64_t> res(len);\n\
    \        for(int i = 0;i < len;i++)res[i] = randint(l,r);\n        return res;\n\
    \    }\n\n    std::vector<int64_t> randset(int64_t l,int64_t r,int64_t n) {\n\
    \        assert(l <= r && n <= r - l);\n        std::unordered_set<int64_t> s;\n\
    \        for (int64_t i = n;i;--i) {\n            int64_t m = randint(l, r + 1\
    \ - i);\n            if (s.find(m) != s.end()) m = r - i;\n            s.insert(m);\n\
    \        }\n        std::vector<int64_t> ret;\n        for(auto& x : s)ret.push_back(x);\n\
    \        return ret;\n    }\n\n    std::vector<std::pair<int,int>> randtree(int\
    \ n,int start_index = 1){\n        UnionFind uf(n);\n        std::vector<pair<int,int>>\
    \ edges;\n        std::vector<pair<int,int>> res;\n        for(int i = 0;i < n;i++){\n\
    \            for(int j = i + 1;j < n;j++){\n                edges.push_back(std::make_pair(i,j));\n\
    \            }\n        }\n        randshf(edges);\n        for(auto&& e : edges){\n\
    \            if(!uf.same(e.first,e.second)){\n                res.push_back(std::make_pair(e.first\
    \ + start_index,e.second + start_index));\n                uf.unite(e.first,e.second);\n\
    \            }\n        }\n        return res;\n    }\n\n    std::vector<std::pair<int,int>>\
    \ randgraph(int n,int m,int start_index = 1){\n        std::vector<std::pair<int,int>>\
    \ res(m);\n        std::set<std::pair<int,int>> used;\n        for(int i = 0;i\
    \ < m;i++){\n            int fr = randint(0,n),to = randint(0,n);\n          \
    \  while(used.count(std::make_pair(fr,to))){\n                fr = randint(0,n);\n\
    \                to = randint(0,n);\n            }\n            used.insert(std::make_pair(fr,to));\n\
    \            res[i] = std::make_pair(fr + start_index,to + start_index);\n   \
    \     }\n        return res;\n    }\n};\n\nusing my_rand::randshf;\nusing my_rand::randvec;\n\
    using my_rand::randset;\nusing my_rand::randtree;\nusing my_rand::randtree;\n\
    using my_rand::randgraph;\n\n#endif /*SORAIE_RANDOM*/"
  dependsOn: []
  isVerificationFile: false
  path: utils/random.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utils/random.hpp
layout: document
redirect_from:
- /library/utils/random.hpp
- /library/utils/random.hpp.html
title: utils/random.hpp
---
