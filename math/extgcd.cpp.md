---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 2 \"math/extgcd.cpp\"\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nT extgcd(T\
    \ a,T b,T& x,T& y){\n  T d=a;\n  if(b!=0){\n    d=extgcd(b,a%b,y,x);\n    y-=(a/b)*x;\n\
    \  }else{\n    x=1;y=0;\n  }\n  return d;\n}\n\ntemplate<typename T>\nT mod_inverse(T\
    \ a,T mod){\n  T x,y;\n  extgcd(a,mod,x,y);\n  return (x%mod+mod)%mod;\n}\n//END\
    \ CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nT extgcd(T a,T b,T& x,T&\
    \ y){\n  T d=a;\n  if(b!=0){\n    d=extgcd(b,a%b,y,x);\n    y-=(a/b)*x;\n  }else{\n\
    \    x=1;y=0;\n  }\n  return d;\n}\n\ntemplate<typename T>\nT mod_inverse(T a,T\
    \ mod){\n  T x,y;\n  extgcd(a,mod,x,y);\n  return (x%mod+mod)%mod;\n}\n//END CUT\
    \ HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy:
  - icon: ':warning:'
    path: math/linearcongruence.cpp
    title: math/linearcongruence.cpp
  - icon: ':warning:'
    path: math/combination.cpp
    title: math/combination.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2970.test.cpp
    title: test/aoj/2970.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2659.test.cpp
    title: test/aoj/2659.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_E.test.cpp
    title: test/aoj/NTL_1_E.test.cpp
  extendedVerifiedWith: []
  isVerificationFile: false
  path: math/extgcd.cpp
  requiredBy:
  - math/linearcongruence.cpp
  - math/combination.cpp
  - test/aoj/2970.test.cpp
  - test/aoj/2659.test.cpp
  - test/aoj/NTL_1_E.test.cpp
  timestamp: '2020-03-22 10:35:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: math/extgcd.cpp
layout: document
redirect_from:
- /library/math/extgcd.cpp
- /library/math/extgcd.cpp.html
title: math/extgcd.cpp
---
