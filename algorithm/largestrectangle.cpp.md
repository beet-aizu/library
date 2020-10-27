---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DPL_3_B.test.cpp
    title: test/aoj/DPL_3_B.test.cpp
  - icon: ':x:'
    path: test/aoj/DPL_3_C.test.cpp
    title: test/aoj/DPL_3_C.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/largestrectangle.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nT largestrectangle(vector<T>\
    \ &v){\n  int n=v.size();\n  T res=0;\n  using P = pair<int, T>;\n  stack<P> sp;\n\
    \  sp.emplace(-1,T(0));\n  for(int i=0;i<n;i++){\n    int j=i;\n    while(sp.top().second>v[i]){\n\
    \      j=sp.top().first;\n      res=max(res,(i-j)*sp.top().second);\n      sp.pop();\n\
    \    }\n    if(sp.top().second<v[i]) sp.emplace(j,v[i]);\n  }\n  while(!sp.empty()){\n\
    \    res=max(res,(n-sp.top().first)*sp.top().second);\n    sp.pop();\n  }\n  return\
    \ res;\n}\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename T>\nT largestrectangle(vector<T> &v){\n\
    \  int n=v.size();\n  T res=0;\n  using P = pair<int, T>;\n  stack<P> sp;\n  sp.emplace(-1,T(0));\n\
    \  for(int i=0;i<n;i++){\n    int j=i;\n    while(sp.top().second>v[i]){\n   \
    \   j=sp.top().first;\n      res=max(res,(i-j)*sp.top().second);\n      sp.pop();\n\
    \    }\n    if(sp.top().second<v[i]) sp.emplace(j,v[i]);\n  }\n  while(!sp.empty()){\n\
    \    res=max(res,(n-sp.top().first)*sp.top().second);\n    sp.pop();\n  }\n  return\
    \ res;\n}\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/largestrectangle.cpp
  requiredBy: []
  timestamp: '2020-10-27 12:43:10+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DPL_3_C.test.cpp
  - test/aoj/DPL_3_B.test.cpp
documentation_of: algorithm/largestrectangle.cpp
layout: document
redirect_from:
- /library/algorithm/largestrectangle.cpp
- /library/algorithm/largestrectangle.cpp.html
title: algorithm/largestrectangle.cpp
---
