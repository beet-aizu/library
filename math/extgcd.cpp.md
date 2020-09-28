---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/combination.cpp
    title: math/combination.cpp
  - icon: ':heavy_check_mark:'
    path: math/linearcongruence.cpp
    title: math/linearcongruence.cpp
  - icon: ':heavy_check_mark:'
    path: mod/inverse.cpp
    title: mod/inverse.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2659.test.cpp
    title: test/aoj/2659.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2970.test.cpp
    title: test/aoj/2970.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_E.test.cpp
    title: test/aoj/NTL_1_E.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/extgcd.cpp\"\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\n// find (x, y) s.t. ax + by =\
    \ gcd(a, b)\n// |x| <= b, |y| <= a\n// return gcd(a, b)\ntemplate<typename T>\n\
    T extgcd(T a,T b,T& x,T& y){\n  T d=a;\n  if(b!=0){\n    d=extgcd(b,a%b,y,x);\n\
    \    y-=(a/b)*x;\n  }else{\n    x=1;y=0;\n  }\n  return d;\n}\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\n// find (x, y) s.t. ax + by = gcd(a, b)\n//\
    \ |x| <= b, |y| <= a\n// return gcd(a, b)\ntemplate<typename T>\nT extgcd(T a,T\
    \ b,T& x,T& y){\n  T d=a;\n  if(b!=0){\n    d=extgcd(b,a%b,y,x);\n    y-=(a/b)*x;\n\
    \  }else{\n    x=1;y=0;\n  }\n  return d;\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: math/extgcd.cpp
  requiredBy:
  - math/combination.cpp
  - math/linearcongruence.cpp
  - mod/inverse.cpp
  timestamp: '2020-09-21 00:38:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2970.test.cpp
  - test/aoj/NTL_1_E.test.cpp
  - test/aoj/2659.test.cpp
documentation_of: math/extgcd.cpp
layout: document
redirect_from:
- /library/math/extgcd.cpp
- /library/math/extgcd.cpp.html
title: math/extgcd.cpp
---
