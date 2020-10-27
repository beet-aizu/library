---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2934.test.cpp
    title: test/aoj/2934.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://snuke.hatenablog.com/entry/2014/12/02/235837
  bundledCode: "#line 1 \"string/manacher.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n// https://snuke.hatenablog.com/entry/2014/12/02/235837\n\
    //BEGIN CUT HERE\nvector<int> manacher(string s){\n  int n=s.size();\n  vector<int>\
    \ vs(n);\n  for(int i=0,j=0;i<n;){\n    while(i-j>=0 and i+j<n and s[i-j]==s[i+j])\
    \ j++;\n    vs[i]=j;\n    int k=1;\n    while(i-k>=0 and i+k<n and k+vs[i-k]<j)\
    \ vs[i+k]=vs[i-k],k++;\n    i+=k;j-=k;\n  }\n  return vs;\n}\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n// https://snuke.hatenablog.com/entry/2014/12/02/235837\n//BEGIN CUT HERE\n\
    vector<int> manacher(string s){\n  int n=s.size();\n  vector<int> vs(n);\n  for(int\
    \ i=0,j=0;i<n;){\n    while(i-j>=0 and i+j<n and s[i-j]==s[i+j]) j++;\n    vs[i]=j;\n\
    \    int k=1;\n    while(i-k>=0 and i+k<n and k+vs[i-k]<j) vs[i+k]=vs[i-k],k++;\n\
    \    i+=k;j-=k;\n  }\n  return vs;\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: string/manacher.cpp
  requiredBy: []
  timestamp: '2020-10-27 13:26:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2934.test.cpp
documentation_of: string/manacher.cpp
layout: document
redirect_from:
- /library/string/manacher.cpp
- /library/string/manacher.cpp.html
title: string/manacher.cpp
---
