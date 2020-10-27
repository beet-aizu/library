---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/find_linear_recurrence.test.cpp
    title: test/yosupo/find_linear_recurrence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0104.test.cpp
    title: test/yukicoder/0104.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0444.test.cpp
    title: test/yukicoder/0444.test.cpp
  - icon: ':x:'
    path: test/yukicoder/3211.test.cpp
    title: test/yukicoder/3211.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"polynomial/berlekampmassey.cpp\"\n\n#ifndef call_from_test\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#endif\n//BEGIN CUT HERE\n//\
    \ construct a charasteristic equation from sequence\n// return a monic polynomial\
    \ in O(n^2)\ntemplate<typename T>\nvector<T> berlekamp_massey(vector<T> &as){\n\
    \  using Poly = vector<T>;\n  int n=as.size();\n  Poly bs({-T(1)}),cs({-T(1)});\n\
    \  T y(1);\n  for(int ed=1;ed<=n;ed++){\n    int l=cs.size(),m=bs.size();\n  \
    \  T x(0);\n    for(int i=0;i<l;i++) x+=cs[i]*as[ed-l+i];\n    bs.emplace_back(0);\n\
    \    m++;\n    if(x==T(0)) continue;\n    T freq=x/y;\n    if(m<=l){\n      for(int\
    \ i=0;i<m;i++)\n        cs[l-1-i]-=freq*bs[m-1-i];\n      continue;\n    }\n \
    \   auto ts=cs;\n    cs.insert(cs.begin(),m-l,T(0));\n    for(int i=0;i<m;i++)\
    \ cs[m-1-i]-=freq*bs[m-1-i];\n    bs=ts;\n    y=x;\n  }\n  for(auto &c:cs) c/=cs.back();\n\
    \  return cs;\n}\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#endif\n//BEGIN CUT HERE\n// construct a charasteristic equation from\
    \ sequence\n// return a monic polynomial in O(n^2)\ntemplate<typename T>\nvector<T>\
    \ berlekamp_massey(vector<T> &as){\n  using Poly = vector<T>;\n  int n=as.size();\n\
    \  Poly bs({-T(1)}),cs({-T(1)});\n  T y(1);\n  for(int ed=1;ed<=n;ed++){\n   \
    \ int l=cs.size(),m=bs.size();\n    T x(0);\n    for(int i=0;i<l;i++) x+=cs[i]*as[ed-l+i];\n\
    \    bs.emplace_back(0);\n    m++;\n    if(x==T(0)) continue;\n    T freq=x/y;\n\
    \    if(m<=l){\n      for(int i=0;i<m;i++)\n        cs[l-1-i]-=freq*bs[m-1-i];\n\
    \      continue;\n    }\n    auto ts=cs;\n    cs.insert(cs.begin(),m-l,T(0));\n\
    \    for(int i=0;i<m;i++) cs[m-1-i]-=freq*bs[m-1-i];\n    bs=ts;\n    y=x;\n \
    \ }\n  for(auto &c:cs) c/=cs.back();\n  return cs;\n}\n//END CUT HERE\n#ifndef\
    \ call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: polynomial/berlekampmassey.cpp
  requiredBy: []
  timestamp: '2020-03-12 17:15:27+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/0104.test.cpp
  - test/yukicoder/0444.test.cpp
  - test/yukicoder/3211.test.cpp
  - test/yosupo/find_linear_recurrence.test.cpp
documentation_of: polynomial/berlekampmassey.cpp
layout: document
redirect_from:
- /library/polynomial/berlekampmassey.cpp
- /library/polynomial/berlekampmassey.cpp.html
title: polynomial/berlekampmassey.cpp
---
