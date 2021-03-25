---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/dynamic_tree_vertex_set_path_composite.toptree.test.cpp
    title: test/yosupo/dynamic_tree_vertex_set_path_composite.toptree.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/twoway.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct TwoWay{\n  T x,y;\n\
    \  TwoWay(T z=T()):x(z),y(z){}\n  TwoWay(T x,T y):x(x),y(y){}\n  TwoWay operator+(const\
    \ TwoWay &o)const{return TwoWay(x+o.x,o.y+y);}\n  TwoWay operator*(const TwoWay\
    \ &o)const{return TwoWay(x*o.x,o.y*y);}\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct TwoWay{\n  T x,y;\n  TwoWay(T\
    \ z=T()):x(z),y(z){}\n  TwoWay(T x,T y):x(x),y(y){}\n  TwoWay operator+(const\
    \ TwoWay &o)const{return TwoWay(x+o.x,o.y+y);}\n  TwoWay operator*(const TwoWay\
    \ &o)const{return TwoWay(x*o.x,o.y*y);}\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: math/twoway.cpp
  requiredBy: []
  timestamp: '2020-10-27 16:41:24+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/dynamic_tree_vertex_set_path_composite.toptree.test.cpp
documentation_of: math/twoway.cpp
layout: document
redirect_from:
- /library/math/twoway.cpp
- /library/math/twoway.cpp.html
title: math/twoway.cpp
---
