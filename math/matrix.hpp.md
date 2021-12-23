---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/matrix.test.cpp
    title: test/matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/matrix.hpp\"\n\n\n\n#include <vector>\n#include <cassert>\n\
    #include <iostream>\n\ntemplate<class T>\nstruct Matrix{\n    int h,w;\n    std::vector<std::vector<T>>\
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
    \        return os;\n    }\n};\n\n\n"
  code: "#ifndef SORAIE_MATRIX\n#define SORAIE_MATRIX\n\n#include <vector>\n#include\
    \ <cassert>\n#include <iostream>\n\ntemplate<class T>\nstruct Matrix{\n    int\
    \ h,w;\n    std::vector<std::vector<T>> dat;\n    Matrix(const std::vector<std::vector<T>>&\
    \ _dat):h(_dat.size()),w(_dat[0].size()),dat(_dat){}\n    Matrix(const int& _h,const\
    \ int& _w):h(_h),w(_w),dat(std::vector<std::vector<T>>(_h,std::vector<T>(_w))){}\n\
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
    \        return os;\n    }\n};\n\n#endif /*SORAIE_MATRIX*/"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy: []
  timestamp: '2021-05-13 19:21:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/matrix.test.cpp
documentation_of: math/matrix.hpp
layout: document
redirect_from:
- /library/math/matrix.hpp
- /library/math/matrix.hpp.html
title: math/matrix.hpp
---
