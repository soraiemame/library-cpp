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
  bundledCode: "#line 1 \"utils/time.hpp\"\n\n\n\n#include <chrono>\n\nstruct Timer{\n\
    \    chrono::high_resolution_clock::time_point st;\n\n    Timer(){reset();}\n\n\
    \    void reset(){st = chrono::high_resolution_clock::now();}\n    chrono::milliseconds::rep\
    \ elapsed(){\n        auto ed = chrono::high_resolution_clock::now();\n      \
    \  return chrono::duration_cast<chrono::milliseconds>(ed - st).count();\n    }\n\
    };\n\n\n"
  code: "#ifndef SORAIE_TIME\n#define SORAIE_TIME\n\n#include <chrono>\n\nstruct Timer{\n\
    \    chrono::high_resolution_clock::time_point st;\n\n    Timer(){reset();}\n\n\
    \    void reset(){st = chrono::high_resolution_clock::now();}\n    chrono::milliseconds::rep\
    \ elapsed(){\n        auto ed = chrono::high_resolution_clock::now();\n      \
    \  return chrono::duration_cast<chrono::milliseconds>(ed - st).count();\n    }\n\
    };\n\n#endif /*SORAIE_TIME*/"
  dependsOn: []
  isVerificationFile: false
  path: utils/time.hpp
  requiredBy: []
  timestamp: '2021-04-01 16:42:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utils/time.hpp
layout: document
redirect_from:
- /library/utils/time.hpp
- /library/utils/time.hpp.html
title: utils/time.hpp
---
