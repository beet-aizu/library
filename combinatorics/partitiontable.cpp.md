---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_J.test.cpp
    title: test/aoj/DPL_5_J.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_L.test.cpp
    title: test/aoj/DPL_5_L.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"combinatorics/partitiontable.cpp\"\n\n#ifndef call_from_test\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename\
    \ M>\nstruct PartitionTable{\n  vector< vector<M> > dp;\n  PartitionTable(int\
    \ h,int w):dp(h+1,vector<M>(w+1,0)){\n    dp[0][0]=M(1);\n    for(int i=0;i<=h;i++){\n\
    \      for(int j=1;j<=w;j++){\n        dp[i][j]=dp[i][j-1];\n        if(i-j>=0)\
    \ dp[i][j]+=dp[i-j][j];\n      }\n    }\n  }\n  // put n identical balls into\
    \ k identical boxes\n  M operator()(int n,int k){return dp[n][k];}\n\n  // put\
    \ n identical balls into some boxes\n  M operator()(int n){return dp[n][n];}\n\
    };\n//END CUT HERE\n\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename M>\nstruct PartitionTable{\n\
    \  vector< vector<M> > dp;\n  PartitionTable(int h,int w):dp(h+1,vector<M>(w+1,0)){\n\
    \    dp[0][0]=M(1);\n    for(int i=0;i<=h;i++){\n      for(int j=1;j<=w;j++){\n\
    \        dp[i][j]=dp[i][j-1];\n        if(i-j>=0) dp[i][j]+=dp[i-j][j];\n    \
    \  }\n    }\n  }\n  // put n identical balls into k identical boxes\n  M operator()(int\
    \ n,int k){return dp[n][k];}\n\n  // put n identical balls into some boxes\n \
    \ M operator()(int n){return dp[n][n];}\n};\n//END CUT HERE\n\n#ifndef call_from_test\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: combinatorics/partitiontable.cpp
  requiredBy: []
  timestamp: '2020-03-12 17:02:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_5_J.test.cpp
  - test/aoj/DPL_5_L.test.cpp
documentation_of: combinatorics/partitiontable.cpp
layout: document
redirect_from:
- /library/combinatorics/partitiontable.cpp
- /library/combinatorics/partitiontable.cpp.html
title: combinatorics/partitiontable.cpp
---
