---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0425.test.cpp
    title: test/aoj/0425.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2290.test.cpp
    title: initialize potential
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"vector/identity.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n\n//BEGIN CUT HERE\nvector<int> identity(int n){\n \
    \ vector<int> ord(n);\n  iota(ord.begin(),ord.end(),0);\n  return ord;\n}\n//END\
    \ CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n\n//BEGIN CUT HERE\nvector<int> identity(int n){\n  vector<int> ord(n);\n\
    \  iota(ord.begin(),ord.end(),0);\n  return ord;\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: vector/identity.cpp
  requiredBy: []
  timestamp: '2020-10-27 12:29:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2290.test.cpp
  - test/aoj/0425.test.cpp
documentation_of: vector/identity.cpp
layout: document
redirect_from:
- /library/vector/identity.cpp
- /library/vector/identity.cpp.html
title: vector/identity.cpp
---
