---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_1_C.test.cpp
    title: test/aoj/ALDS1_1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/isprime.cpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nint isprime(T x){\n  if(x<=1)\
    \ return 0;\n  for(T i=2;i*i<=x;i++)\n    if(x%i==0) return 0;\n  return 1;\n\
    }\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename T>\nint isprime(T x){\n  if(x<=1) return 0;\n\
    \  for(T i=2;i*i<=x;i++)\n    if(x%i==0) return 0;\n  return 1;\n}\n//END CUT\
    \ HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: math/isprime.cpp
  requiredBy: []
  timestamp: '2020-02-11 11:14:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_1_C.test.cpp
documentation_of: math/isprime.cpp
layout: document
redirect_from:
- /library/math/isprime.cpp
- /library/math/isprime.cpp.html
title: math/isprime.cpp
---
