---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0367.test.cpp
    title: test/aoj/0367.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/trio.cpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T, typename U, typename V>\n\
    struct trio{\n  T first;\n  U second;\n  V third;\n  trio(T first,U second,V third):\n\
    \    first(first),second(second),third(third){}\n  operator tuple<T&, U&, V&>(){\n\
    \    return forward_as_tuple(first,second,third);\n  }\n  using X = tuple<T, U,\
    \ V>;\n  operator X() const{return make_tuple(first,second,third);}\n  bool operator==(const\
    \ trio&a) const{return (X)(*this)==(X)a;}\n  bool operator!=(const trio&a) const{return\
    \ (X)(*this)!=(X)a;}\n  bool operator< (const trio&a) const{return (X)(*this)<\
    \ (X)a;}\n  bool operator<=(const trio&a) const{return (X)(*this)<=(X)a;}\n  bool\
    \ operator> (const trio&a) const{return (X)(*this)> (X)a;}\n  bool operator>=(const\
    \ trio&a) const{return (X)(*this)>=(X)a;}\n};\ntemplate<typename T, typename U,\
    \ typename V>\ntrio<T, U, V> make_trio(T first,U second,V third){\n  return trio<T,\
    \ U, V>(first,second,third);\n}\n//END CUT HERE\n#ifndef call_from_test\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename T, typename U, typename V>\nstruct trio{\n\
    \  T first;\n  U second;\n  V third;\n  trio(T first,U second,V third):\n    first(first),second(second),third(third){}\n\
    \  operator tuple<T&, U&, V&>(){\n    return forward_as_tuple(first,second,third);\n\
    \  }\n  using X = tuple<T, U, V>;\n  operator X() const{return make_tuple(first,second,third);}\n\
    \  bool operator==(const trio&a) const{return (X)(*this)==(X)a;}\n  bool operator!=(const\
    \ trio&a) const{return (X)(*this)!=(X)a;}\n  bool operator< (const trio&a) const{return\
    \ (X)(*this)< (X)a;}\n  bool operator<=(const trio&a) const{return (X)(*this)<=(X)a;}\n\
    \  bool operator> (const trio&a) const{return (X)(*this)> (X)a;}\n  bool operator>=(const\
    \ trio&a) const{return (X)(*this)>=(X)a;}\n};\ntemplate<typename T, typename U,\
    \ typename V>\ntrio<T, U, V> make_trio(T first,U second,V third){\n  return trio<T,\
    \ U, V>(first,second,third);\n}\n//END CUT HERE\n#ifndef call_from_test\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/trio.cpp
  requiredBy: []
  timestamp: '2020-10-27 17:58:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0367.test.cpp
documentation_of: tools/trio.cpp
layout: document
redirect_from:
- /library/tools/trio.cpp
- /library/tools/trio.cpp.html
title: tools/trio.cpp
---
