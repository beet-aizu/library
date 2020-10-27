---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2415.knuthyao.test.cpp
    title: test/aoj/2415.knuthyao.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2488.test.cpp
    title: test/aoj/2488.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/knuthyao.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\n// f(i,l) + f(j,k) >= f(i,k) + f(j,l)\
    \ (i <= j, k <= l)\ntemplate<typename T, typename F>\nT KnuthYao(int n,F cost){\n\
    \  vector< vector<T> > dp(n,vector<T>(n));\n  vector< vector<int> > ar(n,vector<int>(n));\n\
    \  for(int i=0;i<n;i++) dp[i][i]=T(0),ar[i][i]=i;\n  for(int w=1;w<n;w++){\n \
    \   for(int i=0;i+w<n;i++){\n      int j=i+w;\n      int p=ar[i][j-1],q=ar[i+1][j];\n\
    \      dp[i][j]=dp[i][p]+dp[p+1][j]+cost(i,p,j);\n      ar[i][j]=p;\n      for(int\
    \ k=p;k<=q&&k+1<=j;k++){\n        T res=dp[i][k]+dp[k+1][j]+cost(i,k,j);\n   \
    \     if(res<dp[i][j]) dp[i][j]=res,ar[i][j]=k;\n      }\n    }\n  }\n  return\
    \ dp[0][n-1];\n}\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\n// f(i,l) + f(j,k) >= f(i,k) + f(j,l) (i <= j, k <=\
    \ l)\ntemplate<typename T, typename F>\nT KnuthYao(int n,F cost){\n  vector< vector<T>\
    \ > dp(n,vector<T>(n));\n  vector< vector<int> > ar(n,vector<int>(n));\n  for(int\
    \ i=0;i<n;i++) dp[i][i]=T(0),ar[i][i]=i;\n  for(int w=1;w<n;w++){\n    for(int\
    \ i=0;i+w<n;i++){\n      int j=i+w;\n      int p=ar[i][j-1],q=ar[i+1][j];\n  \
    \    dp[i][j]=dp[i][p]+dp[p+1][j]+cost(i,p,j);\n      ar[i][j]=p;\n      for(int\
    \ k=p;k<=q&&k+1<=j;k++){\n        T res=dp[i][k]+dp[k+1][j]+cost(i,k,j);\n   \
    \     if(res<dp[i][j]) dp[i][j]=res,ar[i][j]=k;\n      }\n    }\n  }\n  return\
    \ dp[0][n-1];\n}\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/knuthyao.cpp
  requiredBy: []
  timestamp: '2020-10-27 12:43:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2415.knuthyao.test.cpp
  - test/aoj/2488.test.cpp
documentation_of: algorithm/knuthyao.cpp
layout: document
redirect_from:
- /library/algorithm/knuthyao.cpp
- /library/algorithm/knuthyao.cpp.html
title: algorithm/knuthyao.cpp
---
