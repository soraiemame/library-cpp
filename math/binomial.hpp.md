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
  bundledCode: "#line 1 \"math/binomial.hpp\"\n\n\n\n#include <vector>\n\ntemplate<class\
    \ T>\nstruct binomial{\n    binomial(int n = 0):_fac(n + 10),_inv(n + 10),_finv(n\
    \ + 10){\n        _fac[0] = _inv[0] = _finv[0] = 1;\n        _fac[1] = _inv[1]\
    \ = _finv[1] = 1;\n        for(int i = 2;i < n + 10;i++){\n            _fac[i]\
    \ = _fac[i - 1] * i;\n            _inv[i] = T(i).inv();\n            _finv[i]\
    \ = _finv[i - 1] * _inv[i];\n        }\n    }\n    void expand(int n){\n     \
    \   for(int i = _fac.size();i < n + 10;i++){\n            _fac.push_back(_fac[i\
    \ - 1] * i);\n            _inv[i] = T(i).inv();\n            _finv[i] = _finv[i\
    \ - 1] * _inv[i];\n        }\n    }\n    T fac(int n){\n        expand(n);\n \
    \       return _fac[n];\n    }\n    T inv(int n){\n        expand(n);\n      \
    \  return _inv[n];\n    }\n    T finv(int n){\n        expand(n);\n        return\
    \ _finv[n];\n    }\n\n    T C(int n,int k){\n        if(n < k || k < 0 || n <\
    \ 0)return T(0);\n        return fac(n) * finv(n - k) * finv(k);\n    }\n    T\
    \ P(int n,int k){\n        if(n < k || k < 0 || n < 0)return T(0);\n        debug(n,fac(n),n-k,finv(n\
    \ - k));\n        return fac(n) * finv(n - k);\n    }\n    T H(int n,int k){\n\
    \        if(n < 0 || k < 0)return T(0);\n        return k == 0 ? T(1) : C(n +\
    \ k - 1,k);\n    }\nprivate:\n    std::vector<T> _fac,_inv,_finv;\n};\n\n\n"
  code: "#ifndef SORAIE_BINOMIAL\n#define SORAIE_BINOMIAL\n\n#include <vector>\n\n\
    template<class T>\nstruct binomial{\n    binomial(int n = 0):_fac(n + 10),_inv(n\
    \ + 10),_finv(n + 10){\n        _fac[0] = _inv[0] = _finv[0] = 1;\n        _fac[1]\
    \ = _inv[1] = _finv[1] = 1;\n        for(int i = 2;i < n + 10;i++){\n        \
    \    _fac[i] = _fac[i - 1] * i;\n            _inv[i] = T(i).inv();\n         \
    \   _finv[i] = _finv[i - 1] * _inv[i];\n        }\n    }\n    void expand(int\
    \ n){\n        for(int i = _fac.size();i < n + 10;i++){\n            _fac.push_back(_fac[i\
    \ - 1] * i);\n            _inv[i] = T(i).inv();\n            _finv[i] = _finv[i\
    \ - 1] * _inv[i];\n        }\n    }\n    T fac(int n){\n        expand(n);\n \
    \       return _fac[n];\n    }\n    T inv(int n){\n        expand(n);\n      \
    \  return _inv[n];\n    }\n    T finv(int n){\n        expand(n);\n        return\
    \ _finv[n];\n    }\n\n    T C(int n,int k){\n        if(n < k || k < 0 || n <\
    \ 0)return T(0);\n        return fac(n) * finv(n - k) * finv(k);\n    }\n    T\
    \ P(int n,int k){\n        if(n < k || k < 0 || n < 0)return T(0);\n        debug(n,fac(n),n-k,finv(n\
    \ - k));\n        return fac(n) * finv(n - k);\n    }\n    T H(int n,int k){\n\
    \        if(n < 0 || k < 0)return T(0);\n        return k == 0 ? T(1) : C(n +\
    \ k - 1,k);\n    }\nprivate:\n    std::vector<T> _fac,_inv,_finv;\n};\n\n#endif\
    \ /*SORAIE_BINOMIAL*/"
  dependsOn: []
  isVerificationFile: false
  path: math/binomial.hpp
  requiredBy: []
  timestamp: '2021-05-04 18:25:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/binomial.hpp
layout: document
redirect_from:
- /library/math/binomial.hpp
- /library/math/binomial.hpp.html
title: math/binomial.hpp
---
