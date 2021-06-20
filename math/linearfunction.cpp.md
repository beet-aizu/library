---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
    title: test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_tree_vertex_set_path_composite.toptree.test.cpp
    title: test/yosupo/dynamic_tree_vertex_set_path_composite.toptree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_set_range_composite.test.cpp
    title: test/yosupo/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/queue_operate_all_composite.test.cpp
    title: test/yosupo/queue_operate_all_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/linearfunction.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\n// a * x + b\ntemplate<typename\
    \ T>\nstruct LinearFunction{\n  T a,b;\n  LinearFunction():a(0),b(0){}\n  LinearFunction(T\
    \ a,T b):a(a),b(b){}\n\n  using LF = LinearFunction;\n  static LF add_identity(){return\
    \ LF(T(0),T(0));}\n  static LF mul_identity(){return LF(T(1),T(0));}\n  LF& operator+=(const\
    \ LF &o){\n    a+=o.a;b+=o.b;\n    return *this;\n  }\n  LF& operator*=(const\
    \ LF &o){\n    a=a*o.a;\n    b=b*o.a+o.b;\n    return *this;\n  }\n  LF operator+(const\
    \ LF &o)const{return LF(*this)+=o;}\n  LF operator*(const LF &o)const{return LF(*this)*=o;}\n\
    \n  T operator()(T x) const{return a*x+b;}\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\n// a * x + b\ntemplate<typename T>\nstruct LinearFunction{\n\
    \  T a,b;\n  LinearFunction():a(0),b(0){}\n  LinearFunction(T a,T b):a(a),b(b){}\n\
    \n  using LF = LinearFunction;\n  static LF add_identity(){return LF(T(0),T(0));}\n\
    \  static LF mul_identity(){return LF(T(1),T(0));}\n  LF& operator+=(const LF\
    \ &o){\n    a+=o.a;b+=o.b;\n    return *this;\n  }\n  LF& operator*=(const LF\
    \ &o){\n    a=a*o.a;\n    b=b*o.a+o.b;\n    return *this;\n  }\n  LF operator+(const\
    \ LF &o)const{return LF(*this)+=o;}\n  LF operator*(const LF &o)const{return LF(*this)*=o;}\n\
    \n  T operator()(T x) const{return a*x+b;}\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: math/linearfunction.cpp
  requiredBy: []
  timestamp: '2020-10-27 16:41:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/dynamic_tree_vertex_set_path_composite.toptree.test.cpp
  - test/yosupo/point_set_range_composite.test.cpp
  - test/yosupo/queue_operate_all_composite.test.cpp
  - test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
documentation_of: math/linearfunction.cpp
layout: document
redirect_from:
- /library/math/linearfunction.cpp
- /library/math/linearfunction.cpp.html
title: math/linearfunction.cpp
---
