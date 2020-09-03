---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 2 \"math/twoway.cpp\"\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct TwoWay{\n\
    \  T x,y;\n  TwoWay(T z=T()):x(z),y(z){}\n  TwoWay(T x,T y):x(x),y(y){}\n  TwoWay\
    \ operator+(const TwoWay &o)const{return TwoWay(x+o.x,o.y+y);}\n  TwoWay operator*(const\
    \ TwoWay &o)const{return TwoWay(x*o.x,o.y*y);}\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct TwoWay{\n  T x,y;\n\
    \  TwoWay(T z=T()):x(z),y(z){}\n  TwoWay(T x,T y):x(x),y(y){}\n  TwoWay operator+(const\
    \ TwoWay &o)const{return TwoWay(x+o.x,o.y+y);}\n  TwoWay operator*(const TwoWay\
    \ &o)const{return TwoWay(x*o.x,o.y*y);}\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_tree_vertex_set_path_composite.toptree.test.cpp
    title: test/yosupo/dynamic_tree_vertex_set_path_composite.toptree.test.cpp
  isVerificationFile: false
  path: math/twoway.cpp
  requiredBy: []
  timestamp: '2020-03-29 20:43:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - test/yosupo/dynamic_tree_vertex_set_path_composite.toptree.test.cpp
documentation_of: math/twoway.cpp
layout: document
redirect_from:
- /library/math/twoway.cpp
- /library/math/twoway.cpp.html
title: math/twoway.cpp
---
