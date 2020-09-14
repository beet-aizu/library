---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"math/dual.cpp\"\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct Dual{\n\
    \  T v;\n  Dual(T v=T()):v(v){}\n  Dual operator+(const Dual &o)const{return Dual(o.v+v);}\n\
    \  Dual operator*(const Dual &o)const{return Dual(o.v*v);}\n};\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct Dual{\n  T v;\n\
    \  Dual(T v=T()):v(v){}\n  Dual operator+(const Dual &o)const{return Dual(o.v+v);}\n\
    \  Dual operator*(const Dual &o)const{return Dual(o.v*v);}\n};\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: math/dual.cpp
  requiredBy: []
  timestamp: '2020-03-29 20:43:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/dual.cpp
layout: document
redirect_from:
- /library/math/dual.cpp
- /library/math/dual.cpp.html
title: math/dual.cpp
---
