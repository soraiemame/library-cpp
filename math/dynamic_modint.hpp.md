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
  bundledCode: "#line 1 \"math/dynamic_modint.hpp\"\n\n\n\n#include <iostream>\n#include\
    \ <algorithm>\n\nstruct dynamic_modint{\n    int x;\n    dynamic_modint(long long\
    \ a = 0):x((a % get_mod() + get_mod()) % get_mod()){}\n    inline dynamic_modint\
    \ operator-()const noexcept{return dynamic_modint(-x);}\n    inline dynamic_modint\
    \ &operator+=(const dynamic_modint &a)noexcept{\n        if((x += a.x) >= get_mod())x\
    \ -= get_mod();\n        return *this;\n    }\n    inline dynamic_modint &operator-=(const\
    \ dynamic_modint &a)noexcept{\n        if((x -= a.x) < get_mod())x += get_mod();\n\
    \        return *this;\n    }\n    inline dynamic_modint &operator*=(const dynamic_modint\
    \ &a)noexcept{\n        x = (long long)(x) * a.x % get_mod();\n        return\
    \ *this;\n    }\n    inline dynamic_modint &operator++()noexcept{\n        x++;\n\
    \        if(x == get_mod())x = 0;\n        return *this;\n    }\n    inline dynamic_modint\
    \ operator++(int)noexcept{\n        dynamic_modint res(*this);\n        operator++();\n\
    \        return res;\n    }\n    inline dynamic_modint &operator--()noexcept{\n\
    \        x--;\n        if(x == -1)x = get_mod() - 1;\n        return *this;\n\
    \    }\n    inline dynamic_modint operator--(int)noexcept{\n        dynamic_modint\
    \ res(*this);\n        operator--();\n        return res;\n    }\n    inline dynamic_modint\
    \ operator+(const dynamic_modint &a)const noexcept{\n        dynamic_modint res(*this);\n\
    \        return res += a;\n    }\n    inline dynamic_modint operator-(const dynamic_modint\
    \ &a)const noexcept{\n        dynamic_modint res(*this);\n        return res -=\
    \ a;\n    }\n    inline dynamic_modint operator*(const dynamic_modint &a)const\
    \ noexcept{\n        dynamic_modint res(*this);\n        return res *= a;\n  \
    \  }\n    inline dynamic_modint inv()const{\n        int a = x,b = get_mod(),u\
    \ = 1,v = 0,t;\n        while(b){\n            t = a / b;\n            a -= t\
    \ * b;std::swap(a,b);\n            u -= t * v;std::swap(u,v);\n        }\n   \
    \     return u;\n    }\n    inline dynamic_modint &operator/=(const dynamic_modint\
    \ &a)noexcept{return (*this) *= a.inv();}\n    inline dynamic_modint operator/(const\
    \ dynamic_modint &a)const noexcept{\n        dynamic_modint res(*this);\n    \
    \    return res /= a;\n    }\n    inline constexpr bool operator==(const dynamic_modint\
    \ &a)const noexcept{return x == a.x;}\n    friend std::istream &operator>>(std::istream\
    \ &is,dynamic_modint &a) {\n        is >> a.x;\n        a.x = (a.x % get_mod()\
    \ + get_mod()) % get_mod();\n        return is;\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &os,const dynamic_modint &a){\n        os << a.x;\n\
    \        return os;\n    }\n    dynamic_modint pow(long long b)const noexcept{\n\
    \        dynamic_modint res(1),mul(x);\n        while(b > 0){\n            if(b\
    \ & 1)res *= mul;\n            mul *= mul;\n            b >>= 1;\n        }\n\
    \        return res;\n    }\n\n    static int &get_mod(){\n        static int\
    \ dynamic_modint_mod = 0;\n        return dynamic_modint_mod;\n    }\n\n    static\
    \ void set_mod(int mod){get_mod() = mod;}\n};\n\n\n"
  code: "#ifndef SORAIE_DYNAMIC_MODINT\n#define SORAIE_DYNAMIC_MODINT\n\n#include\
    \ <iostream>\n#include <algorithm>\n\nstruct dynamic_modint{\n    int x;\n   \
    \ dynamic_modint(long long a = 0):x((a % get_mod() + get_mod()) % get_mod()){}\n\
    \    inline dynamic_modint operator-()const noexcept{return dynamic_modint(-x);}\n\
    \    inline dynamic_modint &operator+=(const dynamic_modint &a)noexcept{\n   \
    \     if((x += a.x) >= get_mod())x -= get_mod();\n        return *this;\n    }\n\
    \    inline dynamic_modint &operator-=(const dynamic_modint &a)noexcept{\n   \
    \     if((x -= a.x) < get_mod())x += get_mod();\n        return *this;\n    }\n\
    \    inline dynamic_modint &operator*=(const dynamic_modint &a)noexcept{\n   \
    \     x = (long long)(x) * a.x % get_mod();\n        return *this;\n    }\n  \
    \  inline dynamic_modint &operator++()noexcept{\n        x++;\n        if(x ==\
    \ get_mod())x = 0;\n        return *this;\n    }\n    inline dynamic_modint operator++(int)noexcept{\n\
    \        dynamic_modint res(*this);\n        operator++();\n        return res;\n\
    \    }\n    inline dynamic_modint &operator--()noexcept{\n        x--;\n     \
    \   if(x == -1)x = get_mod() - 1;\n        return *this;\n    }\n    inline dynamic_modint\
    \ operator--(int)noexcept{\n        dynamic_modint res(*this);\n        operator--();\n\
    \        return res;\n    }\n    inline dynamic_modint operator+(const dynamic_modint\
    \ &a)const noexcept{\n        dynamic_modint res(*this);\n        return res +=\
    \ a;\n    }\n    inline dynamic_modint operator-(const dynamic_modint &a)const\
    \ noexcept{\n        dynamic_modint res(*this);\n        return res -= a;\n  \
    \  }\n    inline dynamic_modint operator*(const dynamic_modint &a)const noexcept{\n\
    \        dynamic_modint res(*this);\n        return res *= a;\n    }\n    inline\
    \ dynamic_modint inv()const{\n        int a = x,b = get_mod(),u = 1,v = 0,t;\n\
    \        while(b){\n            t = a / b;\n            a -= t * b;std::swap(a,b);\n\
    \            u -= t * v;std::swap(u,v);\n        }\n        return u;\n    }\n\
    \    inline dynamic_modint &operator/=(const dynamic_modint &a)noexcept{return\
    \ (*this) *= a.inv();}\n    inline dynamic_modint operator/(const dynamic_modint\
    \ &a)const noexcept{\n        dynamic_modint res(*this);\n        return res /=\
    \ a;\n    }\n    inline constexpr bool operator==(const dynamic_modint &a)const\
    \ noexcept{return x == a.x;}\n    friend std::istream &operator>>(std::istream\
    \ &is,dynamic_modint &a) {\n        is >> a.x;\n        a.x = (a.x % get_mod()\
    \ + get_mod()) % get_mod();\n        return is;\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &os,const dynamic_modint &a){\n        os << a.x;\n\
    \        return os;\n    }\n    dynamic_modint pow(long long b)const noexcept{\n\
    \        dynamic_modint res(1),mul(x);\n        while(b > 0){\n            if(b\
    \ & 1)res *= mul;\n            mul *= mul;\n            b >>= 1;\n        }\n\
    \        return res;\n    }\n\n    static int &get_mod(){\n        static int\
    \ dynamic_modint_mod = 0;\n        return dynamic_modint_mod;\n    }\n\n    static\
    \ void set_mod(int mod){get_mod() = mod;}\n};\n\n#endif /*SORAIE_DYNAMIC_MODINT*/"
  dependsOn: []
  isVerificationFile: false
  path: math/dynamic_modint.hpp
  requiredBy: []
  timestamp: '2021-04-10 17:20:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/dynamic_modint.hpp
layout: document
redirect_from:
- /library/math/dynamic_modint.hpp
- /library/math/dynamic_modint.hpp.html
title: math/dynamic_modint.hpp
---
