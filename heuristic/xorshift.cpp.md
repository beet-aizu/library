---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"heuristic/xorshift.cpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n\n/**\n * @ignore\n */\n\n//BEGIN CUT HERE\nuint32_t xor128(){\n\
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
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: heuristic/xorshift.cpp
  requiredBy: []
  timestamp: '2020-03-10 22:18:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: heuristic/xorshift.cpp
layout: document
redirect_from:
- /library/heuristic/xorshift.cpp
- /library/heuristic/xorshift.cpp.html
title: heuristic/xorshift.cpp
---
