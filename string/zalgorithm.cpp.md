---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/run.cpp
    title: string/run.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3081.test.cpp
    title: test/aoj/3081.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/runenumerate.test.cpp
    title: test/yosupo/runenumerate.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/zalgorithm.test.cpp
    title: test/yosupo/zalgorithm.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/zalgorithm.cpp\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\n// longest common prefix of s and\
    \ s[i:n]\ntemplate<typename T>\nvector<int> zalgorithm(vector<T> vs){\n  int n=vs.size();\n\
    \  vector<int> as(n+1,0);\n  as[0]=n;\n  int i=1,j=0;\n  while(i<n){\n    while(i+j<n&&vs[j]==vs[i+j])\
    \ j++;\n    as[i]=j;\n    if(j==0){\n      i++;\n      continue;\n    }\n    int\
    \ k=1;\n    while(i+k<n&&k+as[k]<j) as[i+k]=as[k],k++;\n    i+=k;\n    j-=k;\n\
    \  }\n  return as;\n}\nvector<int> zalgorithm(string s){\n  return zalgorithm(vector<char>(s.begin(),s.end()));\n\
    }\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\n// longest common prefix of s and s[i:n]\ntemplate<typename\
    \ T>\nvector<int> zalgorithm(vector<T> vs){\n  int n=vs.size();\n  vector<int>\
    \ as(n+1,0);\n  as[0]=n;\n  int i=1,j=0;\n  while(i<n){\n    while(i+j<n&&vs[j]==vs[i+j])\
    \ j++;\n    as[i]=j;\n    if(j==0){\n      i++;\n      continue;\n    }\n    int\
    \ k=1;\n    while(i+k<n&&k+as[k]<j) as[i+k]=as[k],k++;\n    i+=k;\n    j-=k;\n\
    \  }\n  return as;\n}\nvector<int> zalgorithm(string s){\n  return zalgorithm(vector<char>(s.begin(),s.end()));\n\
    }\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: string/zalgorithm.cpp
  requiredBy:
  - string/run.cpp
  timestamp: '2020-02-15 17:46:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3081.test.cpp
  - test/yosupo/zalgorithm.test.cpp
  - test/yosupo/runenumerate.test.cpp
documentation_of: string/zalgorithm.cpp
layout: document
redirect_from:
- /library/string/zalgorithm.cpp
- /library/string/zalgorithm.cpp.html
title: string/zalgorithm.cpp
---
