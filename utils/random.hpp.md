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
  bundledCode: "#line 1 \"utils/random.hpp\"\n\n\n\n#include <cassert>\n#include <vector>\n\
    #include <algorithm>\n#include <chrono>\n#include <unordered_set>\n\nnamespace\
    \ my_rand{\n    // [0, 2^64 - 1)\n    uint64_t rng(){\n        static uint64_t\
    \ x_ =\n            uint64_t(std::chrono::duration_cast<std::chrono::nanoseconds>(\n\
    \                        std::chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                        .count()) *\n            10150724397891781847ULL;\n \
    \       x_ ^= x_ << 7;\n        return x_ ^= x_ >> 9;\n    }\n\n    // [l, r)\n\
    \    int64_t randint(int64_t l,int64_t r) {\n        assert(l < r);\n        return\
    \ l + rng() % (r - l);\n    }\n\n    std::vector<int64_t> randset(int64_t l,int64_t\
    \ r,int64_t n) {\n        assert(l <= r && n <= r - l);\n        std::unordered_set<int64_t>\
    \ s;\n        for (int64_t i = n;i;--i) {\n            int64_t m = randint(l,\
    \ r + 1 - i);\n            if (s.find(m) != s.end()) m = r - i;\n            s.insert(m);\n\
    \        }\n        std::vector<int64_t> ret;\n        for(auto& x : s)ret.push_back(x);\n\
    \        return ret;\n    }\n\n    // [0.0, 1.0)\n    double rnd(){\n        union\
    \ raw_cast{\n            double t;\n            uint64_t u;\n        };\n    \
    \    constexpr uint64_t p = uint64_t(1023 - 64) << 52;\n        return rng() *\
    \ ((raw_cast*)(&p))->t;\n    }\n\n    template <typename T>\n    void randshf(std::vector<T>&\
    \ v){\n        int n = v.size();\n        for(int loop = 0;loop < 2;loop++)for(int\
    \ i = 0;i < n;i++)std::swap(v[i],v[randint(0, n)]);\n    }\n\n    uint64_t rng128(){\n\
    \        static uint64_t tx = 123456789,ty = 362436069,tz = 521288629,tw = 88675123;\n\
    \        uint64_t tt = (tx^(tx<<11));\n        tx = ty; ty = tz; tz = tw;\n  \
    \      return (tw=(tw^(tw>>19))^(tt^(tt>>8)));\n    }\n\n    int64_t xor128(int64_t\
    \ l,int64_t r){\n        assert(l < r);\n        return l + rng128() % (r - l);\n\
    \    }\n}\n\nusing my_rand::randint;\nusing my_rand::randset;\nusing my_rand::randshf;\n\
    using my_rand::rnd;\nusing my_rand::rng;\nusing my_rand::xor128;\nusing my_rand::rng128;\n\
    \n\n"
  code: "#ifndef SORAIE_RANDOM\n#define SORAIE_RANDOM\n\n#include <cassert>\n#include\
    \ <vector>\n#include <algorithm>\n#include <chrono>\n#include <unordered_set>\n\
    \nnamespace my_rand{\n    // [0, 2^64 - 1)\n    uint64_t rng(){\n        static\
    \ uint64_t x_ =\n            uint64_t(std::chrono::duration_cast<std::chrono::nanoseconds>(\n\
    \                        std::chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                        .count()) *\n            10150724397891781847ULL;\n \
    \       x_ ^= x_ << 7;\n        return x_ ^= x_ >> 9;\n    }\n\n    // [l, r)\n\
    \    int64_t randint(int64_t l,int64_t r) {\n        assert(l < r);\n        return\
    \ l + rng() % (r - l);\n    }\n\n    std::vector<int64_t> randset(int64_t l,int64_t\
    \ r,int64_t n) {\n        assert(l <= r && n <= r - l);\n        std::unordered_set<int64_t>\
    \ s;\n        for (int64_t i = n;i;--i) {\n            int64_t m = randint(l,\
    \ r + 1 - i);\n            if (s.find(m) != s.end()) m = r - i;\n            s.insert(m);\n\
    \        }\n        std::vector<int64_t> ret;\n        for(auto& x : s)ret.push_back(x);\n\
    \        return ret;\n    }\n\n    // [0.0, 1.0)\n    double rnd(){\n        union\
    \ raw_cast{\n            double t;\n            uint64_t u;\n        };\n    \
    \    constexpr uint64_t p = uint64_t(1023 - 64) << 52;\n        return rng() *\
    \ ((raw_cast*)(&p))->t;\n    }\n\n    template <typename T>\n    void randshf(std::vector<T>&\
    \ v){\n        int n = v.size();\n        for(int loop = 0;loop < 2;loop++)for(int\
    \ i = 0;i < n;i++)std::swap(v[i],v[randint(0, n)]);\n    }\n\n    uint64_t rng128(){\n\
    \        static uint64_t tx = 123456789,ty = 362436069,tz = 521288629,tw = 88675123;\n\
    \        uint64_t tt = (tx^(tx<<11));\n        tx = ty; ty = tz; tz = tw;\n  \
    \      return (tw=(tw^(tw>>19))^(tt^(tt>>8)));\n    }\n\n    int64_t xor128(int64_t\
    \ l,int64_t r){\n        assert(l < r);\n        return l + rng128() % (r - l);\n\
    \    }\n}\n\nusing my_rand::randint;\nusing my_rand::randset;\nusing my_rand::randshf;\n\
    using my_rand::rnd;\nusing my_rand::rng;\nusing my_rand::xor128;\nusing my_rand::rng128;\n\
    \n#endif /*SORAIE_RANDOM*/"
  dependsOn: []
  isVerificationFile: false
  path: utils/random.hpp
  requiredBy: []
  timestamp: '2021-04-01 16:42:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utils/random.hpp
layout: document
redirect_from:
- /library/utils/random.hpp
- /library/utils/random.hpp.html
title: utils/random.hpp
---
