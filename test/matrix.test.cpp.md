---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/matrix.hpp
    title: math/matrix.hpp
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: math/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"test/matrix.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 1 \"math/matrix.hpp\"\n\n\n\
    \n#line 5 \"math/matrix.hpp\"\n#include <cassert>\n#line 7 \"math/matrix.hpp\"\
    \n\ntemplate<class T>\nstruct Matrix{\n    int h,w;\n    std::vector<std::vector<T>>\
    \ dat;\n    Matrix(const std::vector<std::vector<T>>& _dat):h(_dat.size()),w(_dat[0].size()),dat(_dat){}\n\
    \    Matrix(const int& _h,const int& _w):h(_h),w(_w),dat(std::vector<std::vector<T>>(_h,std::vector<T>(_w))){}\n\
    \n    std::vector<T>& operator[](int k){return dat[k];}\n\n    inline constexpr\
    \ Matrix &operator+=(const Matrix& a) noexcept {\n        assert(a.h == h && a.w\
    \ == w);\n        for(int i = 0;i < h;i++){\n            for(int j = 0;j < w;j++){\n\
    \                dat[i][j] += a.dat[i][j];\n            }\n        }\n       \
    \ return *this;\n    }\n\n    inline constexpr Matrix &operator*=(const Matrix&\
    \ a) noexcept {\n        assert(w == a.h);\n        Matrix res(h,a.w);\n     \
    \   for(int i = 0;i < h;i++){\n            for(int j = 0;j < a.h;j++){\n     \
    \           for(int k = 0;k < a.w;k++){\n                    res[i][k] += dat[i][j]\
    \ * a.dat[j][k];\n                }\n            }\n        }\n        *this =\
    \ res;\n        return *this;\n    }\n\n    inline constexpr Matrix operator+(const\
    \ Matrix& a) const noexcept { return Matrix(*this) += a; }\n    inline constexpr\
    \ Matrix operator*(const Matrix& a) const noexcept { return Matrix(*this) *= a;\
    \ }\n\n    inline constexpr Matrix pow(long long k) const noexcept {\n       \
    \ assert(h == w);\n        Matrix res = id(h),a(*this);\n        while(k){\n \
    \           if(k & 1)res *= a;\n            a *= a;\n            k >>= 1;\n  \
    \      }\n        return res;\n    }\n\n    inline constexpr static Matrix id(int\
    \ n){\n        Matrix res(n,n);\n        for(int i = 0;i < n;i++)res.dat[i][i]\
    \ = T(1);\n        return res;\n    }\n\n    friend std::ostream &operator<<(std::ostream&\
    \ os,const Matrix& a){\n        for(int i = 0;i < a.dat.size();i++){\n       \
    \     os << \"[\";\n            for(int j = 0;j < a.dat[i].size();j++){\n    \
    \            os << a.dat[i][j] << (j == a.dat[i].size() - 1 ? \"]\" : \" \");\n\
    \            }\n            if(i != a.dat.size() - 1)os << \"\\n\";\n        }\n\
    \        return os;\n    }\n};\n\n\n#line 1 \"math/modint.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#line 6 \"math/modint.hpp\"\n\ntemplate<int MOD = 1000000007>\n\
    struct modint{\n    using mint = modint<MOD>;\n    int x;\n    modint(long long\
    \ a = 0):x((a % MOD + MOD) % MOD){}\n    inline constexpr modint operator-()const\
    \ noexcept{return modint(-x);}\n    inline constexpr modint &operator+=(const\
    \ modint &a)noexcept{\n        if((x += a.x) >= MOD)x -= MOD;\n        return\
    \ *this;\n    }\n    inline constexpr modint &operator-=(const modint &a)noexcept{\n\
    \        if((x -= a.x) < 0)x += MOD;\n        return *this;\n    }\n    inline\
    \ constexpr modint &operator*=(const modint &a)noexcept{\n        x = (long long)(x)\
    \ * a.x % MOD;\n        return *this;\n    }\n    inline constexpr modint &operator++()noexcept{\n\
    \        x++;\n        if(x == MOD)x = 0;\n        return *this;\n    }\n    inline\
    \ constexpr modint operator++(int)noexcept{\n        modint res(*this);\n    \
    \    operator++();\n        return res;\n    }\n    inline constexpr modint &operator--()noexcept{\n\
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
    \ return os;\n    }\n    inline constexpr mint pow(long long b)const noexcept{\n\
    \        mint res(1),mul(x);\n        while(b > 0){\n            if(b & 1)res\
    \ *= mul;\n            mul *= mul;\n            b >>= 1;\n        }\n        return\
    \ res;\n    }\n\n    static constexpr int get_mod(){return MOD;}\n};\nusing modint1000000007\
    \ = modint<1'000'000'007>;\nusing modint998244353 = modint<998'244'353>;\n\n\n\
    #line 8 \"test/matrix.test.cpp\"\n\nint main(){\n    using mint = modint998244353;\n\
    \    using mat = Matrix<mint>;\n    \n    int N,M,K;\n    std::cin >> N >> M >>\
    \ K;\n    \n    mat A(N,M),B(M,K);\n    for(int i = 0;i < N;i++){\n        for(int\
    \ j = 0;j < M;j++)std::cin >> A[i][j];\n    }\n    for(int i = 0;i < M;i++){\n\
    \        for(int j = 0;j < K;j++)std::cin >> B[i][j];\n    }\n\n    mat ans =\
    \ A * B;\n    for(int i = 0;i < N;i++){\n        for(int j = 0;j < K;j++){\n \
    \           std::cout << ans[i][j] << (j == K - 1 ? \"\\n\" : \" \");\n      \
    \  }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"../math/matrix.hpp\"\n#include \"\
    ../math/modint.hpp\"\n\nint main(){\n    using mint = modint998244353;\n    using\
    \ mat = Matrix<mint>;\n    \n    int N,M,K;\n    std::cin >> N >> M >> K;\n  \
    \  \n    mat A(N,M),B(M,K);\n    for(int i = 0;i < N;i++){\n        for(int j\
    \ = 0;j < M;j++)std::cin >> A[i][j];\n    }\n    for(int i = 0;i < M;i++){\n \
    \       for(int j = 0;j < K;j++)std::cin >> B[i][j];\n    }\n\n    mat ans = A\
    \ * B;\n    for(int i = 0;i < N;i++){\n        for(int j = 0;j < K;j++){\n   \
    \         std::cout << ans[i][j] << (j == K - 1 ? \"\\n\" : \" \");\n        }\n\
    \    }\n}"
  dependsOn:
  - math/matrix.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: test/matrix.test.cpp
  requiredBy: []
  timestamp: '2021-05-13 19:21:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/matrix.test.cpp
layout: document
redirect_from:
- /verify/test/matrix.test.cpp
- /verify/test/matrix.test.cpp.html
title: test/matrix.test.cpp
---
