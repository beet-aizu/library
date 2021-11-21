---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/7107.test.cpp
    title: test LCMConvolution
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/moebius.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\n// [0, n]\nvector<int> moebius(int n){\n  n++;\n\
    \  vector<int> pr(n),sq(n);\n  using ll = long long;\n  for(ll i=2;i<n;i++){\n\
    \    if(pr[i]) continue;\n    for(ll j=i;j<n;j+=i) pr[j]=i;\n    for(ll j=i*i;j<n;j+=i*i)\
    \ sq[j]=1;\n  }\n  vector<int> sign(n,0);\n  sign[1]=1;\n  for(ll i=2;i<n;i++){\n\
    \    if(sq[i]) continue;\n    sign[i]=-sign[i/pr[i]];\n  }\n  return sign;\n}\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\n// [0, n]\nvector<int> moebius(int n){\n  n++;\n  vector<int>\
    \ pr(n),sq(n);\n  using ll = long long;\n  for(ll i=2;i<n;i++){\n    if(pr[i])\
    \ continue;\n    for(ll j=i;j<n;j+=i) pr[j]=i;\n    for(ll j=i*i;j<n;j+=i*i) sq[j]=1;\n\
    \  }\n  vector<int> sign(n,0);\n  sign[1]=1;\n  for(ll i=2;i<n;i++){\n    if(sq[i])\
    \ continue;\n    sign[i]=-sign[i/pr[i]];\n  }\n  return sign;\n}\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: math/moebius.cpp
  requiredBy: []
  timestamp: '2021-11-21 12:07:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/7107.test.cpp
documentation_of: math/moebius.cpp
layout: document
redirect_from:
- /library/math/moebius.cpp
- /library/math/moebius.cpp.html
title: math/moebius.cpp
---
