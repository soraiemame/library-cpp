---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/unionfind.hpp
    title: data-structure/unionfind.hpp
  - icon: ':warning:'
    path: utils/randbase.hpp
    title: utils/randbase.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utils/random.hpp\"\n\n\n\n#include <set>\n\n#line 1 \"utils/randbase.hpp\"\
    \n\n\n\n#include <cassert>\n#include <vector>\n#include <algorithm>\n#include\
    \ <chrono>\n#include <unordered_set>\n\nnamespace my_rand{\n    // [0, 2^64 -\
    \ 1)\n    uint64_t rng(){\n        static uint64_t x_ =\n            uint64_t(std::chrono::duration_cast<std::chrono::nanoseconds>(\n\
    \                        std::chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                        .count()) *\n            10150724397891781847ULL;\n \
    \       x_ ^= x_ << 7;\n        return x_ ^= x_ >> 9;\n    }\n\n    // [l, r)\n\
    \    int64_t randint(int64_t l,int64_t r) {\n        assert(l < r);\n        return\
    \ l + rng() % (r - l);\n    }\n\n    // [0.0, 1.0)\n    double rnd(){\n      \
    \  union raw_cast{\n            double t;\n            uint64_t u;\n        };\n\
    \        constexpr uint64_t p = uint64_t(1023 - 64) << 52;\n        return rng()\
    \ * ((raw_cast*)(&p))->t;\n    }\n\n    uint64_t rng128(){\n        static uint64_t\
    \ tx = 123456789,ty = 362436069,tz = 521288629,tw = 88675123;\n        uint64_t\
    \ tt = (tx^(tx<<11));\n        tx = ty; ty = tz; tz = tw;\n        return (tw=(tw^(tw>>19))^(tt^(tt>>8)));\n\
    \    }\n\n    int64_t xor128(int64_t l,int64_t r){\n        assert(l < r);\n \
    \       return l + rng128() % (r - l);\n    }\n}\n\nusing my_rand::randint;\n\
    using my_rand::rnd;\nusing my_rand::rng;\nusing my_rand::xor128;\nusing my_rand::rng128;\n\
    \n\n#line 1 \"data-structure/unionfind.hpp\"\n\n\n\n#line 6 \"data-structure/unionfind.hpp\"\
    \n#include <assert.h>\n\nstruct UnionFind{\n    int n;\n    std::vector<int> dat;\n\
    \    UnionFind(int n_){init(n_);}\n    void init(int n_){\n        n = n_;\n \
    \       dat = std::vector<int>(n_,-1);\n    }\n    int find(int v){\n        assert(0\
    \ <= v && v < n);\n        if(dat[v] < 0)return v;\n        else return dat[v]\
    \ = find(dat[v]);\n    }\n    void unite(int a,int b){\n        assert(0 <= a\
    \ && a < n && 0 <= b && b < n);\n        a = find(a);\n        b = find(b);\n\
    \        if(a == b)return;\n        if(dat[a] > dat[b])std::swap(a,b);\n     \
    \   dat[a] += dat[b];\n        dat[b] = a;\n    }\n    bool same(int a,int b){\n\
    \        assert(0 <= a && a < n && 0 <= b && b < n);\n        return find(a) ==\
    \ find(b);\n    }\n    int size(int v){\n        assert(0 <= v && v < n);\n  \
    \      return -dat[v];\n    }\n};\n\n\n#line 8 \"utils/random.hpp\"\n\nnamespace\
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
    using my_rand::randgraph;\n\n\n"
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
  dependsOn:
  - utils/randbase.hpp
  - data-structure/unionfind.hpp
  isVerificationFile: false
  path: utils/random.hpp
  requiredBy: []
  timestamp: '2021-05-10 14:03:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utils/random.hpp
layout: document
redirect_from:
- /library/utils/random.hpp
- /library/utils/random.hpp.html
title: utils/random.hpp
---
