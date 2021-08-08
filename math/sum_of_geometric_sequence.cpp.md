---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2520.test.cpp
    title: test/yukicoder/2520.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/sum_of_geometric_sequence.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\n// first: sum_{i=0}^{n-1} r^i\n\
    // second: r^n\ntemplate<typename T>\npair<T, T> sum_of_geometric_sequence_impl(T\
    \ r,long long n){\n  if(n==1) return {T(1),r};\n  auto p=sum_of_geometric_sequence_impl(r,n/2);\n\
    \  T sum=p.first*(T(1)+p.second);\n  T pow=p.second*p.second;\n  if(n&1) sum+=pow,pow*=r;\n\
    \  return {sum,pow};\n}\n// sum_{i=0}^{n-1} r^i\ntemplate<typename T>\nT sum_of_geometric_sequence(T\
    \ r,long long n){\n  return sum_of_geometric_sequence_impl(r,n).first;\n}\n//END\
    \ CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\n// first: sum_{i=0}^{n-1} r^i\n// second: r^n\ntemplate<typename\
    \ T>\npair<T, T> sum_of_geometric_sequence_impl(T r,long long n){\n  if(n==1)\
    \ return {T(1),r};\n  auto p=sum_of_geometric_sequence_impl(r,n/2);\n  T sum=p.first*(T(1)+p.second);\n\
    \  T pow=p.second*p.second;\n  if(n&1) sum+=pow,pow*=r;\n  return {sum,pow};\n\
    }\n// sum_{i=0}^{n-1} r^i\ntemplate<typename T>\nT sum_of_geometric_sequence(T\
    \ r,long long n){\n  return sum_of_geometric_sequence_impl(r,n).first;\n}\n//END\
    \ CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: math/sum_of_geometric_sequence.cpp
  requiredBy: []
  timestamp: '2021-08-08 16:43:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/2520.test.cpp
documentation_of: math/sum_of_geometric_sequence.cpp
layout: document
redirect_from:
- /library/math/sum_of_geometric_sequence.cpp
- /library/math/sum_of_geometric_sequence.cpp.html
title: math/sum_of_geometric_sequence.cpp
---
