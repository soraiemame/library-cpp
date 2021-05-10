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
  bundledCode: "#line 1 \"utils/random_checker.hpp\"\n\n\n\n#include <iostream>\n\n\
    template<class InputType,class OutputType,OutputType (*solve)(InputType),OutputType\
    \ (*solve_naive)(InputType),\nInputType (*gen_input)(),void (*output_in)(InputType),void\
    \ (*output_out)(OutputType)>\nint random_checker(int tmp = 0){\n    auto test\
    \ = [&](int id){\n        InputType testcase = gen_input();\n        OutputType\
    \ out = solve(testcase),out_naive = solve_naive(testcase);\n        if(out !=\
    \ out_naive){\n            std::cerr << \"\\033[31mTest failed on test \" << id\
    \ << \". \\033[m\\n\";\n            std::cerr << \"Test case:\\n\";\n        \
    \    output_in(testcase);\n            std::cerr << \"\\nsolve output:\\n\";\n\
    \            output_out(out);\n            std::cerr << \"\\nsolve naive output:\\\
    n\";\n            output_out(out_naive);\n            return 1;\n        }\n \
    \       return 0;\n    };\n    int i = 1;\n    if(tmp == -1){\n        while(true){\n\
    \            if(test(i))return 1;\n            i++;\n        }\n    }\n    else{\n\
    \        for(;i <= tmp;i++){\n            if(test(i))return 1;\n        }\n  \
    \      std::cerr << \"\\033[32mNo test failed\\n\\033[m\";\n        return 0;\n\
    \    }\n}\n\n\n"
  code: "#ifndef SORAIE_RANDOM_CHECKER\n#define SORAIE_RANDOM_CHECKER\n\n#include\
    \ <iostream>\n\ntemplate<class InputType,class OutputType,OutputType (*solve)(InputType),OutputType\
    \ (*solve_naive)(InputType),\nInputType (*gen_input)(),void (*output_in)(InputType),void\
    \ (*output_out)(OutputType)>\nint random_checker(int tmp = 0){\n    auto test\
    \ = [&](int id){\n        InputType testcase = gen_input();\n        OutputType\
    \ out = solve(testcase),out_naive = solve_naive(testcase);\n        if(out !=\
    \ out_naive){\n            std::cerr << \"\\033[31mTest failed on test \" << id\
    \ << \". \\033[m\\n\";\n            std::cerr << \"Test case:\\n\";\n        \
    \    output_in(testcase);\n            std::cerr << \"\\nsolve output:\\n\";\n\
    \            output_out(out);\n            std::cerr << \"\\nsolve naive output:\\\
    n\";\n            output_out(out_naive);\n            return 1;\n        }\n \
    \       return 0;\n    };\n    int i = 1;\n    if(tmp == -1){\n        while(true){\n\
    \            if(test(i))return 1;\n            i++;\n        }\n    }\n    else{\n\
    \        for(;i <= tmp;i++){\n            if(test(i))return 1;\n        }\n  \
    \      std::cerr << \"\\033[32mNo test failed\\n\\033[m\";\n        return 0;\n\
    \    }\n}\n\n#endif /*SORAIE_RANDOM_CHECKER*/"
  dependsOn: []
  isVerificationFile: false
  path: utils/random_checker.hpp
  requiredBy: []
  timestamp: '2021-05-10 14:03:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utils/random_checker.hpp
layout: document
redirect_from:
- /library/utils/random_checker.hpp
- /library/utils/random_checker.hpp.html
title: utils/random_checker.hpp
---
