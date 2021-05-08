---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0402.test.cpp
    title: test/aoj/0402.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bitwise_xor_convolution.test.cpp
    title: test/yosupo/bitwise_xor_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/bitwise/xor.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\nauto zeta=[](auto& lo,auto& hi){\n\
    \  auto x=lo+hi,y=lo-hi;\n  lo=x;\n  hi=y;\n};\nauto moebius=[](auto& lo,auto&\
    \ hi){\n  auto x=lo+hi,y=lo-hi;\n  lo=x/decltype(x)(2);\n  hi=y/decltype(y)(2);\n\
    };\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\nauto zeta=[](auto& lo,auto& hi){\n  auto x=lo+hi,y=lo-hi;\n\
    \  lo=x;\n  hi=y;\n};\nauto moebius=[](auto& lo,auto& hi){\n  auto x=lo+hi,y=lo-hi;\n\
    \  lo=x/decltype(x)(2);\n  hi=y/decltype(y)(2);\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: convolution/bitwise/xor.cpp
  requiredBy: []
  timestamp: '2020-12-16 12:53:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0402.test.cpp
  - test/yosupo/bitwise_xor_convolution.test.cpp
documentation_of: convolution/bitwise/xor.cpp
layout: document
redirect_from:
- /library/convolution/bitwise/xor.cpp
- /library/convolution/bitwise/xor.cpp.html
title: convolution/bitwise/xor.cpp
---
