---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1254.test.cpp
    title: test/aoj/1254.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"graph/chromatic.cpp\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\nint chromatic(vector< vector<int>\
    \ > G){\n  int n=G.size();\n  if(n==0) return 0;\n  assert(n<=30);\n\n  vector<int>\
    \ es(n,0);\n  for(int i=0;i<n;i++)\n    for(int j=0;j<n;j++)\n      es[i]|=G[i][j]<<j;\n\
    \n  int s=1<<n;\n  vector<int> dp(s);\n  for(int b=0;b<s;b++)\n    dp[b]=((n-__builtin_popcount(b))&1?-1:1);\n\
    \n  auto calc=\n    [&](const int MOD){\n      vector<int> res(s);\n      res[0]=1;\n\
    \      for(int b=1;b<s;b++){\n        int ctz=__builtin_ctz(b);\n        res[b]=res[b-(1<<ctz)]+res[(b-(1<<ctz))&~es[ctz]];\n\
    \        if(res[b]>=MOD) res[b]-=MOD;\n      }\n      return res;\n    };\n\n\
    \  constexpr int MOD1 = 1077563119;\n  constexpr int MOD2 = 1e9+7;\n  vector<int>\
    \ ind1=calc(MOD1);\n  vector<int> ind2=calc(MOD2);\n\n  using ll = long long;\n\
    \  vector<int> dp1=dp,dp2=dp;\n  for(int i=1;i<n;i++){\n    ll sum1=0,sum2=0;\n\
    \    for(int b=0;b<s;b++){\n      dp1[b]=((ll)dp1[b]*ind1[b])%MOD1;\n      sum1+=dp1[b];\n\
    \n      dp2[b]=((ll)dp2[b]*ind2[b])%MOD2;\n      sum2+=dp2[b];\n    }\n    if(sum1%MOD1!=0)\
    \ return i;\n    if(sum2%MOD2!=0) return i;\n  }\n  return n;\n}\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nint chromatic(vector< vector<int> > G){\n  int n=G.size();\n\
    \  if(n==0) return 0;\n  assert(n<=30);\n\n  vector<int> es(n,0);\n  for(int i=0;i<n;i++)\n\
    \    for(int j=0;j<n;j++)\n      es[i]|=G[i][j]<<j;\n\n  int s=1<<n;\n  vector<int>\
    \ dp(s);\n  for(int b=0;b<s;b++)\n    dp[b]=((n-__builtin_popcount(b))&1?-1:1);\n\
    \n  auto calc=\n    [&](const int MOD){\n      vector<int> res(s);\n      res[0]=1;\n\
    \      for(int b=1;b<s;b++){\n        int ctz=__builtin_ctz(b);\n        res[b]=res[b-(1<<ctz)]+res[(b-(1<<ctz))&~es[ctz]];\n\
    \        if(res[b]>=MOD) res[b]-=MOD;\n      }\n      return res;\n    };\n\n\
    \  constexpr int MOD1 = 1077563119;\n  constexpr int MOD2 = 1e9+7;\n  vector<int>\
    \ ind1=calc(MOD1);\n  vector<int> ind2=calc(MOD2);\n\n  using ll = long long;\n\
    \  vector<int> dp1=dp,dp2=dp;\n  for(int i=1;i<n;i++){\n    ll sum1=0,sum2=0;\n\
    \    for(int b=0;b<s;b++){\n      dp1[b]=((ll)dp1[b]*ind1[b])%MOD1;\n      sum1+=dp1[b];\n\
    \n      dp2[b]=((ll)dp2[b]*ind2[b])%MOD2;\n      sum2+=dp2[b];\n    }\n    if(sum1%MOD1!=0)\
    \ return i;\n    if(sum2%MOD2!=0) return i;\n  }\n  return n;\n}\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/chromatic.cpp
  requiredBy: []
  timestamp: '2019-12-17 22:09:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1254.test.cpp
documentation_of: graph/chromatic.cpp
layout: document
redirect_from:
- /library/graph/chromatic.cpp
- /library/graph/chromatic.cpp.html
title: graph/chromatic.cpp
---
