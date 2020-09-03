---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
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
  extendedDependsOn: []
  extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0425.test.cpp
    title: test/aoj/0425.test.cpp
  extendedVerifiedWith: []
  isVerificationFile: false
  path: vector/identity.cpp
  requiredBy:
  - test/aoj/0425.test.cpp
  timestamp: '2020-04-22 14:12:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: vector/identity.cpp
layout: document
redirect_from:
- /library/vector/identity.cpp
- /library/vector/identity.cpp.html
title: vector/identity.cpp
---
