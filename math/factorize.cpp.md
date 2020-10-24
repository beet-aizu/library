---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/3062.test.cpp
    title: test/aoj/3062.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_A.test.cpp
    title: test/aoj/NTL_1_A.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/factorize.cpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nmap<T, int> factorize(T\
    \ x){\n  map<T, int> res;\n  for(int i=2;i*i<=x;i++){\n    while(x%i==0){\n  \
    \    x/=i;\n      res[i]++;\n    }\n  }\n  if(x!=1) res[x]++;\n  return res;\n\
    }\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename T>\nmap<T, int> factorize(T x){\n  map<T,\
    \ int> res;\n  for(int i=2;i*i<=x;i++){\n    while(x%i==0){\n      x/=i;\n   \
    \   res[i]++;\n    }\n  }\n  if(x!=1) res[x]++;\n  return res;\n}\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: math/factorize.cpp
  requiredBy: []
  timestamp: '2019-12-26 23:22:59+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/3062.test.cpp
  - test/aoj/NTL_1_A.test.cpp
documentation_of: math/factorize.cpp
layout: document
redirect_from:
- /library/math/factorize.cpp
- /library/math/factorize.cpp.html
title: math/factorize.cpp
---
