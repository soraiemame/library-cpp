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
  bundledCode: "#line 1 \"algorithm/rhograph.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <functional>\n\ntemplate<int LOG = 64>\nstruct RhoGraph{\n    int n;\n    std::vector<std::vector<int>>\
    \ table;\n    std::function<int(int)> func;\n    RhoGraph(int _n,const function<int(int)>&\
    \ _func):n(_n),func(_func){ build(); }\n    void build(){\n        table = std::vector<std::vector<int>>(LOG,std::vector<int>(n));\n\
    \        for(int i = 0;i < n;i++)table[0][i] = func(i);\n        for(int i = 1;i\
    \ < LOG;i++){\n            for(int j = 0;j < n;j++){\n                table[i][j]\
    \ = table[i - 1][table[i - 1][j]];\n            }\n        }\n    }\n    int query(int\
    \ x,long long k){\n        for(int i = LOG - 1;i >= 0;i--){\n            if(k\
    \ >> i & 1)x = table[i][x];\n        }\n        return x;\n    }\n};\n\n\n"
  code: "#ifndef SORAIE_RHOGRAPH\n#define SORAIE_RHOGRAPH\n\n#include <vector>\n#include\
    \ <functional>\n\ntemplate<int LOG = 64>\nstruct RhoGraph{\n    int n;\n    std::vector<std::vector<int>>\
    \ table;\n    std::function<int(int)> func;\n    RhoGraph(int _n,const function<int(int)>&\
    \ _func):n(_n),func(_func){ build(); }\n    void build(){\n        table = std::vector<std::vector<int>>(LOG,std::vector<int>(n));\n\
    \        for(int i = 0;i < n;i++)table[0][i] = func(i);\n        for(int i = 1;i\
    \ < LOG;i++){\n            for(int j = 0;j < n;j++){\n                table[i][j]\
    \ = table[i - 1][table[i - 1][j]];\n            }\n        }\n    }\n    int query(int\
    \ x,long long k){\n        for(int i = LOG - 1;i >= 0;i--){\n            if(k\
    \ >> i & 1)x = table[i][x];\n        }\n        return x;\n    }\n};\n\n#endif\
    \ /*SORAIE_RHOGRAPH*/"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/rhograph.hpp
  requiredBy: []
  timestamp: '2021-06-05 15:15:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/rhograph.hpp
layout: document
redirect_from:
- /library/algorithm/rhograph.hpp
- /library/algorithm/rhograph.hpp.html
title: algorithm/rhograph.hpp
---
