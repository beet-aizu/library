---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sum_of_floor_of_linear.test.cpp
    title: test/yosupo/sum_of_floor_of_linear.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"math/sum_of_floor.cpp\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\n// sum_{i=0}^{n-1} (ai + b) // m\n\
    // 0 <= a, b\ntemplate<typename T>\nT sum_of_floor(T n,T m,T a,T b){\n  T res=0;\n\
    \  if(a>=m){\n    res+=(n-1)*n*(a/m)/2;\n    a%=m;\n  }\n  if(b>=m){\n    res+=n*(b/m);\n\
    \    b%=m;\n  }\n  T y=(a*n+b)/m;\n  T x=y*m-b;\n  if(y==0) return res;\n  res+=(n-(x+a-1)/a)*y;\n\
    \  res+=sum_of_floor(y,a,m,(a-x%a)%a);\n  return res;\n}\n//END CUT HERE\n#ifndef\
    \ call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\n// sum_{i=0}^{n-1} (ai + b) // m\n// 0 <= a, b\ntemplate<typename\
    \ T>\nT sum_of_floor(T n,T m,T a,T b){\n  T res=0;\n  if(a>=m){\n    res+=(n-1)*n*(a/m)/2;\n\
    \    a%=m;\n  }\n  if(b>=m){\n    res+=n*(b/m);\n    b%=m;\n  }\n  T y=(a*n+b)/m;\n\
    \  T x=y*m-b;\n  if(y==0) return res;\n  res+=(n-(x+a-1)/a)*y;\n  res+=sum_of_floor(y,a,m,(a-x%a)%a);\n\
    \  return res;\n}\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: math/sum_of_floor.cpp
  requiredBy: []
  timestamp: '2019-12-21 18:07:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/sum_of_floor_of_linear.test.cpp
documentation_of: math/sum_of_floor.cpp
layout: document
redirect_from:
- /library/math/sum_of_floor.cpp
- /library/math/sum_of_floor.cpp.html
title: math/sum_of_floor.cpp
---
