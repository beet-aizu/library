---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
    title: test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
  - icon: ':x:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/affine.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\nnamespace Affine{\n  template<typename T>\n\
    \  T op(T a,T b){return T(a.first+b.first,a.second+b.second);}\n  template<typename\
    \ T, typename E>\n  T mapping(T a,E b){return T(a.first*b.first+a.second*b.second,a.second);}\n\
    \  template<typename E>\n  E composition(E a,E b){return E(a.first*b.first,a.second*b.first+b.second);}\n\
    \n  template<typename T> T e(){return T(0,0);};\n  template<typename E> E id(){return\
    \ E(1,0);};\n\n  template<typename T, typename E>\n  decltype(auto) params(){\n\
    \    auto f=[](T a,T b){return op(a,b);};\n    auto g=[](T a,E b){return mapping(a,b);};\n\
    \    auto h=[](E a,E b){return composition(a,b);};\n    return make_tuple(f,g,h,e<T>(),id<E>());\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\nnamespace Affine{\n  template<typename T>\n  T op(T\
    \ a,T b){return T(a.first+b.first,a.second+b.second);}\n  template<typename T,\
    \ typename E>\n  T mapping(T a,E b){return T(a.first*b.first+a.second*b.second,a.second);}\n\
    \  template<typename E>\n  E composition(E a,E b){return E(a.first*b.first,a.second*b.first+b.second);}\n\
    \n  template<typename T> T e(){return T(0,0);};\n  template<typename E> E id(){return\
    \ E(1,0);};\n\n  template<typename T, typename E>\n  decltype(auto) params(){\n\
    \    auto f=[](T a,T b){return op(a,b);};\n    auto g=[](T a,E b){return mapping(a,b);};\n\
    \    auto h=[](E a,E b){return composition(a,b);};\n    return make_tuple(f,g,h,e<T>(),id<E>());\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: math/affine.cpp
  requiredBy: []
  timestamp: '2020-11-28 18:20:37+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
  - test/yosupo/range_affine_range_sum.test.cpp
documentation_of: math/affine.cpp
layout: document
redirect_from:
- /library/math/affine.cpp
- /library/math/affine.cpp.html
title: math/affine.cpp
---
