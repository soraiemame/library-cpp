---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/NTT_all_mod.hpp
    title: math/NTT_all_mod.hpp
  - icon: ':heavy_check_mark:'
    path: math/NTT_primitive_mod.hpp
    title: math/NTT_primitive_mod.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/NTT_1000000007.test.cpp
    title: test/NTT_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/NTT_998244353.test.cpp
    title: test/NTT_998244353.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/modint.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <iostream>\n\ntemplate<int MOD = 1000000007>\nstruct modint{\n    using mint\
    \ = modint<MOD>;\n    int x;\n    modint(long long a = 0):x((a % MOD + MOD) %\
    \ MOD){}\n    inline constexpr modint operator-()const noexcept{return modint(-x);}\n\
    \    inline constexpr modint &operator+=(const modint &a)noexcept{\n        if\
    \ ((x += a.x) >= MOD) x -= MOD;\n        return *this;\n    }\n    inline constexpr\
    \ modint &operator-=(const modint &a)noexcept{\n        if ((x -= a.x) < 0) x\
    \ += MOD;\n        return *this;\n    }\n    inline constexpr modint &operator*=(const\
    \ modint &a)noexcept{\n        x = (long long)(x) * a.x % MOD;\n        return\
    \ *this;\n    }\n    inline constexpr modint &operator++()noexcept{\n        x++;\n\
    \        if(x == MOD)x = 0;\n        return *this;\n    }\n    inline constexpr\
    \ modint operator++(int)noexcept{\n        modint res(*this);\n        operator++();\n\
    \        return res;\n    }\n    inline constexpr modint &operator--()noexcept{\n\
    \        x--;\n        if(x == -1)x = MOD - 1;\n        return *this;\n    }\n\
    \    inline constexpr modint operator--(int)noexcept{\n        modint res(*this);\n\
    \        operator--();\n        return res;\n    }\n    inline constexpr modint\
    \ operator+(const modint &a)const noexcept{\n        modint res(*this);\n    \
    \    return res += a;\n    }\n    inline constexpr modint operator-(const modint\
    \ &a)const noexcept{\n        modint res(*this);\n        return res -= a;\n \
    \   }\n    inline constexpr modint operator*(const modint &a)const noexcept{\n\
    \        modint res(*this);\n        return res *= a;\n    }\n    inline constexpr\
    \ modint inv()const{\n        int a = x,b = MOD,u = 1,v = 0,t;\n        while(b){\n\
    \            t = a / b;\n            a -= t * b;std::swap(a,b);\n            u\
    \ -= t * v;std::swap(u,v);\n        }\n        return u;\n    }\n    inline constexpr\
    \ modint &operator/=(const modint &a)noexcept{return (*this) *= a.inv();}\n  \
    \  inline constexpr modint operator/(const modint &a)const noexcept{\n       \
    \ modint res(*this);\n        return res /= a;\n    }\n    inline constexpr bool\
    \ operator==(const modint &a)const noexcept{return x == a.x;}\n    friend std::istream\
    \ &operator>>(std::istream &is,modint &a) {\n        is >> a.x;\n        a.x =\
    \ (a.x % MOD + MOD) % MOD;\n        return is;\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &os,const modint &a){\n        os << a.x;\n       \
    \ return os;\n    }\n    friend mint modpow(mint a,long long b)noexcept{\n   \
    \     mint res(1);\n        while(b){\n            if(b & 1)res *= a;\n      \
    \      a *= a;\n            b >>= 1;\n        }\n        return res;\n    }\n\n\
    \    static constexpr int get_mod(){return MOD;}\n};\nusing modint1000000007 =\
    \ modint<1'000'000'007>;\nusing modint998244353 = modint<998'244'353>;\n\n\n"
  code: "#ifndef SORAIE_MODINT\n#define SORAIE_MODINT\n\n#include <algorithm>\n#include\
    \ <iostream>\n\ntemplate<int MOD = 1000000007>\nstruct modint{\n    using mint\
    \ = modint<MOD>;\n    int x;\n    modint(long long a = 0):x((a % MOD + MOD) %\
    \ MOD){}\n    inline constexpr modint operator-()const noexcept{return modint(-x);}\n\
    \    inline constexpr modint &operator+=(const modint &a)noexcept{\n        if\
    \ ((x += a.x) >= MOD) x -= MOD;\n        return *this;\n    }\n    inline constexpr\
    \ modint &operator-=(const modint &a)noexcept{\n        if ((x -= a.x) < 0) x\
    \ += MOD;\n        return *this;\n    }\n    inline constexpr modint &operator*=(const\
    \ modint &a)noexcept{\n        x = (long long)(x) * a.x % MOD;\n        return\
    \ *this;\n    }\n    inline constexpr modint &operator++()noexcept{\n        x++;\n\
    \        if(x == MOD)x = 0;\n        return *this;\n    }\n    inline constexpr\
    \ modint operator++(int)noexcept{\n        modint res(*this);\n        operator++();\n\
    \        return res;\n    }\n    inline constexpr modint &operator--()noexcept{\n\
    \        x--;\n        if(x == -1)x = MOD - 1;\n        return *this;\n    }\n\
    \    inline constexpr modint operator--(int)noexcept{\n        modint res(*this);\n\
    \        operator--();\n        return res;\n    }\n    inline constexpr modint\
    \ operator+(const modint &a)const noexcept{\n        modint res(*this);\n    \
    \    return res += a;\n    }\n    inline constexpr modint operator-(const modint\
    \ &a)const noexcept{\n        modint res(*this);\n        return res -= a;\n \
    \   }\n    inline constexpr modint operator*(const modint &a)const noexcept{\n\
    \        modint res(*this);\n        return res *= a;\n    }\n    inline constexpr\
    \ modint inv()const{\n        int a = x,b = MOD,u = 1,v = 0,t;\n        while(b){\n\
    \            t = a / b;\n            a -= t * b;std::swap(a,b);\n            u\
    \ -= t * v;std::swap(u,v);\n        }\n        return u;\n    }\n    inline constexpr\
    \ modint &operator/=(const modint &a)noexcept{return (*this) *= a.inv();}\n  \
    \  inline constexpr modint operator/(const modint &a)const noexcept{\n       \
    \ modint res(*this);\n        return res /= a;\n    }\n    inline constexpr bool\
    \ operator==(const modint &a)const noexcept{return x == a.x;}\n    friend std::istream\
    \ &operator>>(std::istream &is,modint &a) {\n        is >> a.x;\n        a.x =\
    \ (a.x % MOD + MOD) % MOD;\n        return is;\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &os,const modint &a){\n        os << a.x;\n       \
    \ return os;\n    }\n    friend mint modpow(mint a,long long b)noexcept{\n   \
    \     mint res(1);\n        while(b){\n            if(b & 1)res *= a;\n      \
    \      a *= a;\n            b >>= 1;\n        }\n        return res;\n    }\n\n\
    \    static constexpr int get_mod(){return MOD;}\n};\nusing modint1000000007 =\
    \ modint<1'000'000'007>;\nusing modint998244353 = modint<998'244'353>;\n\n#endif\
    \ /*SORAIE_MODINT*/"
  dependsOn: []
  isVerificationFile: false
  path: math/modint.hpp
  requiredBy:
  - math/NTT_all_mod.hpp
  - math/NTT_primitive_mod.hpp
  timestamp: '2021-04-10 16:51:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/NTT_998244353.test.cpp
  - test/NTT_1000000007.test.cpp
documentation_of: math/modint.hpp
layout: document
redirect_from:
- /library/math/modint.hpp
- /library/math/modint.hpp.html
title: math/modint.hpp
---
