---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"heuristic/xorshift.ignore.cpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n/**\n * @ignore\n */\n\n//BEGIN CUT HERE\nuint32_t xor128(){\n\
    \  static uint32_t x = 123456789;\n  static uint32_t y = 362436069;\n  static\
    \ uint32_t z = 521288629;\n  static uint32_t w = 88675123;\n  uint32_t t = x ^\
    \ (x << 11);\n  x = y; y = z; z = w;\n  return w = (w ^ (w >> 19)) ^ (t ^ (t >>\
    \ 8));\n}\n//END CUT HERE\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n\
    }\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n\n/**\n * @ignore\n */\n\n\
    //BEGIN CUT HERE\nuint32_t xor128(){\n  static uint32_t x = 123456789;\n  static\
    \ uint32_t y = 362436069;\n  static uint32_t z = 521288629;\n  static uint32_t\
    \ w = 88675123;\n  uint32_t t = x ^ (x << 11);\n  x = y; y = z; z = w;\n  return\
    \ w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n}\n//END CUT HERE\n//INSERT ABOVE HERE\n\
    signed main(){\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: heuristic/xorshift.ignore.cpp
  requiredBy: []
  timestamp: '2020-09-04 08:31:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: heuristic/xorshift.ignore.cpp
layout: document
redirect_from:
- /library/heuristic/xorshift.ignore.cpp
- /library/heuristic/xorshift.ignore.cpp.html
title: heuristic/xorshift.ignore.cpp
---
