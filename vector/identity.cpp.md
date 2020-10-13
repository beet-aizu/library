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
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"vector/identity.cpp\"\n\n#ifndef call_from_test\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#endif\n\n//BEGIN CUT HERE\nvector<int>\
    \ identity(int n){\n  vector<int> ord(n);\n  iota(ord.begin(),ord.end(),0);\n\
    \  return ord;\n}\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n\n//BEGIN CUT HERE\nvector<int> identity(int n){\n  vector<int>\
    \ ord(n);\n  iota(ord.begin(),ord.end(),0);\n  return ord;\n}\n//END CUT HERE\n\
    #ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: vector/identity.cpp
  requiredBy: []
  timestamp: '2020-04-22 14:12:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0425.test.cpp
  - test/aoj/2290.test.cpp
documentation_of: vector/identity.cpp
layout: document
redirect_from:
- /library/vector/identity.cpp
- /library/vector/identity.cpp.html
title: vector/identity.cpp
---
