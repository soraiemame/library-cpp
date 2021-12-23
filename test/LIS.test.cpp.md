---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/LIS_LDS.hpp
    title: algorithm/LIS_LDS.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_D
  bundledCode: "#line 1 \"test/LIS.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_D\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 1 \"algorithm/LIS_LDS.hpp\"\
    \n\n\n\n#line 5 \"algorithm/LIS_LDS.hpp\"\n#include <algorithm>\n\ntemplate<class\
    \ T>\nstd::vector<int> LIS(const std::vector<T>& vec){\n    int n = vec.size();\n\
    \    std::vector<int> memo(n,__INT32_MAX__);\n    for(T a : vec)*std::lower_bound(memo.begin(),memo.end(),a)\
    \ = a;\n    return std::vector<int>(memo.begin(),std::lower_bound(memo.begin(),memo.end(),__INT32_MAX__));\n\
    }\ntemplate<class T>\nstd::vector<int> LDS(const std::vector<T>& _vec){\n    std::vector<T>\
    \ vec = _vec;\n    std::reverse(vec.begin(),vec.end());\n    auto res = LIS(vec);\n\
    \    std::reverse(res.begin(),res.end());\n    return res;\n}\n\n\n#line 7 \"\
    test/LIS.test.cpp\"\n\nint main(){\n    int N;\n    std::cin >> N;\n    std::vector<int>\
    \ vec(N);\n    for(int i = 0;i < N;i++)std::cin >> vec[i];\n    std::vector<int>\
    \ ans = LIS(vec);\n    std::cout << ans.size() << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_D\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../algorithm/LIS_LDS.hpp\"\
    \n\nint main(){\n    int N;\n    std::cin >> N;\n    std::vector<int> vec(N);\n\
    \    for(int i = 0;i < N;i++)std::cin >> vec[i];\n    std::vector<int> ans = LIS(vec);\n\
    \    std::cout << ans.size() << \"\\n\";\n}"
  dependsOn:
  - algorithm/LIS_LDS.hpp
  isVerificationFile: true
  path: test/LIS.test.cpp
  requiredBy: []
  timestamp: '2021-04-08 21:01:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LIS.test.cpp
layout: document
redirect_from:
- /verify/test/LIS.test.cpp
- /verify/test/LIS.test.cpp.html
title: test/LIS.test.cpp
---
