---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2720.test.cpp
    title: test/aoj/2720.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/carmichael.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\n// min m s.t. a^m = 1 mod n (a, n\
    \ are coprime)\ntemplate<typename T>\nT carmichael_lambda(T n){\n  T res=1;\n\
    \  if(n%8==0) n/=2;\n  for(int i=2;i*i<=n;i++){\n    if(n%i==0){\n      T tmp=i-1;\n\
    \      for(n/=i;n%i==0;n/=i) tmp*=i;\n      res=lcm(res,tmp);\n    }\n  }\n  if(n!=1)\
    \ res=lcm(res,n-1);\n  return res;\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\n// min m s.t. a^m = 1 mod n (a, n are coprime)\ntemplate<typename\
    \ T>\nT carmichael_lambda(T n){\n  T res=1;\n  if(n%8==0) n/=2;\n  for(int i=2;i*i<=n;i++){\n\
    \    if(n%i==0){\n      T tmp=i-1;\n      for(n/=i;n%i==0;n/=i) tmp*=i;\n    \
    \  res=lcm(res,tmp);\n    }\n  }\n  if(n!=1) res=lcm(res,n-1);\n  return res;\n\
    }\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: math/carmichael.cpp
  requiredBy: []
  timestamp: '2020-10-24 13:53:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2720.test.cpp
documentation_of: math/carmichael.cpp
layout: document
redirect_from:
- /library/math/carmichael.cpp
- /library/math/carmichael.cpp.html
title: math/carmichael.cpp
---
