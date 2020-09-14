---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: mod/order.cpp
    title: mod/order.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3062.test.cpp
    title: test/aoj/3062.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_B.test.cpp
    title: test/aoj/NTL_1_B.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"mod/pow.cpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nT mod_pow(T a,long long\
    \ n,T mod){\n  using ll = long long;\n  T res(1);\n  while(n){\n    if(n&1) res=(ll)res*a%mod;\n\
    \    a=(ll)a*a%mod;\n    n>>=1;\n  }\n  return res;\n}\n//END CUT HERE\n#ifndef\
    \ call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename T>\nT mod_pow(T a,long long n,T mod){\n  using\
    \ ll = long long;\n  T res(1);\n  while(n){\n    if(n&1) res=(ll)res*a%mod;\n\
    \    a=(ll)a*a%mod;\n    n>>=1;\n  }\n  return res;\n}\n//END CUT HERE\n#ifndef\
    \ call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/pow.cpp
  requiredBy:
  - mod/order.cpp
  timestamp: '2019-12-17 20:56:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3062.test.cpp
  - test/aoj/NTL_1_B.test.cpp
documentation_of: mod/pow.cpp
layout: document
redirect_from:
- /library/mod/pow.cpp
- /library/mod/pow.cpp.html
title: mod/pow.cpp
---
