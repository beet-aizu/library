---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0367.test.cpp
    title: test/aoj/0367.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0377.test.cpp
    title: test/aoj/0377.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0613.test.cpp
    title: test/aoj/0613.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2646.test.cpp
    title: test/aoj/2646.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2790.test.cpp
    title: test/aoj/2790.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3142.test.cpp
    title: test/aoj/3142.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/2448.test.cpp
    title: test/aoj/geometry/2448.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/frequency_table_of_tree_distance.test.cpp
    title: test/yosupo/frequency_table_of_tree_distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/tree_diameter.test.cpp
    title: test/yosupo/tree_diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/3912.test.cpp
    title: test/yukicoder/3912.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/3961.test.cpp
    title: test/yukicoder/3961.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4852.test.cpp
    title: test/yukicoder/4852.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/fixpoint.cpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename F>\nstruct FixPoint : F{\n\
    \  FixPoint(F&& f):F(forward<F>(f)){}\n  template<typename... Args>\n  decltype(auto)\
    \ operator()(Args&&... args) const{\n    return F::operator()(*this,forward<Args>(args)...);\n\
    \  }\n};\ntemplate<typename F>\ninline decltype(auto) MFP(F&& f){\n  return FixPoint<F>{forward<F>(f)};\n\
    }\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename F>\nstruct FixPoint : F{\n  FixPoint(F&& f):F(forward<F>(f)){}\n\
    \  template<typename... Args>\n  decltype(auto) operator()(Args&&... args) const{\n\
    \    return F::operator()(*this,forward<Args>(args)...);\n  }\n};\ntemplate<typename\
    \ F>\ninline decltype(auto) MFP(F&& f){\n  return FixPoint<F>{forward<F>(f)};\n\
    }\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/fixpoint.cpp
  requiredBy: []
  timestamp: '2019-12-26 23:42:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2790.test.cpp
  - test/aoj/0367.test.cpp
  - test/aoj/0377.test.cpp
  - test/aoj/geometry/2448.test.cpp
  - test/aoj/0613.test.cpp
  - test/aoj/3142.test.cpp
  - test/aoj/2646.test.cpp
  - test/yukicoder/3912.test.cpp
  - test/yukicoder/3961.test.cpp
  - test/yukicoder/4852.test.cpp
  - test/yosupo/tree_diameter.test.cpp
  - test/yosupo/frequency_table_of_tree_distance.test.cpp
documentation_of: tools/fixpoint.cpp
layout: document
redirect_from:
- /library/tools/fixpoint.cpp
- /library/tools/fixpoint.cpp.html
title: tools/fixpoint.cpp
---
