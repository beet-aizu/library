---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2563.test.cpp
    title: test/aoj/2563.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 2 \"algorithm/parallelbinarysearch.cpp\"\n\n#ifndef call_from_test\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#endif\n//BEGIN CUT HERE\n// n\
    \ questions, q operations\nvector<int> parallel_binary_search(int n,int q,\n \
    \                                  function<void(void)> init,\n              \
    \                     function<void(int)> apply,\n                           \
    \        function<bool(int)> check){\n  vector< vector<int> > C(q);\n  vector<int>\
    \ L(n,-1),R(n,q);\n  bool flg=1;\n  while(flg){\n    flg=0;\n    init();\n   \
    \ for(int i=0;i<n;i++)\n      if(L[i]+1<R[i]) C[(L[i]+R[i])>>1].emplace_back(i);\n\
    \    for(int i=0;i<q;i++){\n      flg|=!C[i].empty();\n      apply(i);\n     \
    \ for(int j:C[i]){\n        if(check(j)) R[j]=i;\n        else L[j]=i;\n     \
    \ }\n      C[i].clear();\n    }\n  }\n  return R;\n}\n//END CUT HERE\n#ifndef\
    \ call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\n// n questions, q operations\nvector<int> parallel_binary_search(int\
    \ n,int q,\n                                   function<void(void)> init,\n  \
    \                                 function<void(int)> apply,\n               \
    \                    function<bool(int)> check){\n  vector< vector<int> > C(q);\n\
    \  vector<int> L(n,-1),R(n,q);\n  bool flg=1;\n  while(flg){\n    flg=0;\n   \
    \ init();\n    for(int i=0;i<n;i++)\n      if(L[i]+1<R[i]) C[(L[i]+R[i])>>1].emplace_back(i);\n\
    \    for(int i=0;i<q;i++){\n      flg|=!C[i].empty();\n      apply(i);\n     \
    \ for(int j:C[i]){\n        if(check(j)) R[j]=i;\n        else L[j]=i;\n     \
    \ }\n      C[i].clear();\n    }\n  }\n  return R;\n}\n//END CUT HERE\n#ifndef\
    \ call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/parallelbinarysearch.cpp
  requiredBy: []
  timestamp: '2020-03-12 16:36:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2563.test.cpp
documentation_of: algorithm/parallelbinarysearch.cpp
layout: document
redirect_from:
- /library/algorithm/parallelbinarysearch.cpp
- /library/algorithm/parallelbinarysearch.cpp.html
title: algorithm/parallelbinarysearch.cpp
---
