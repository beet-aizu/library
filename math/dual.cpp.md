---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
    title: test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/dual.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct Dual{\n  T v;\n\
    \  Dual(T v=T()):v(v){}\n  Dual operator+(const Dual &o)const{return Dual(o.v+v);}\n\
    \  Dual operator*(const Dual &o)const{return Dual(o.v*v);}\n};\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct Dual{\n  T v;\n  Dual(T\
    \ v=T()):v(v){}\n  Dual operator+(const Dual &o)const{return Dual(o.v+v);}\n \
    \ Dual operator*(const Dual &o)const{return Dual(o.v*v);}\n};\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: math/dual.cpp
  requiredBy: []
  timestamp: '2020-10-27 16:41:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
documentation_of: math/dual.cpp
layout: document
redirect_from:
- /library/math/dual.cpp
- /library/math/dual.cpp.html
title: math/dual.cpp
---
