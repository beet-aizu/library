---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2646.test.cpp
    title: test/aoj/2646.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/associative_array.test.cpp
    title: test/yosupo/associative_array.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"tools/cc_hash.cpp\"\n\n#ifndef call_from_test\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename\
    \ T>\nstruct cc_hash{\n  uint64_t operator()(T x) const{\n    uint64_t y(x);\n\
    \    y += 0x9e3779b97f4a7c15;\n    y = (y ^ (y >> 30)) * 0xbf58476d1ce4e5b9;\n\
    \    y = (y ^ (y >> 27)) * 0x94d049bb133111eb;\n    return y ^ (y >> 31);\n  }\n\
    };\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct cc_hash{\n  uint64_t\
    \ operator()(T x) const{\n    uint64_t y(x);\n    y += 0x9e3779b97f4a7c15;\n \
    \   y = (y ^ (y >> 30)) * 0xbf58476d1ce4e5b9;\n    y = (y ^ (y >> 27)) * 0x94d049bb133111eb;\n\
    \    return y ^ (y >> 31);\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/cc_hash.cpp
  requiredBy: []
  timestamp: '2020-05-24 17:44:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2646.test.cpp
  - test/yosupo/associative_array.test.cpp
documentation_of: tools/cc_hash.cpp
layout: document
redirect_from:
- /library/tools/cc_hash.cpp
- /library/tools/cc_hash.cpp.html
title: tools/cc_hash.cpp
---
