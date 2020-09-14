---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2951.test.cpp
    title: test/aoj/2951.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0022.test.cpp
    title: test/yukicoder/0022.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"polynomial/lagrangeinterpolation.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename M>\nM lagrange_interpolation(vector<M>\
    \ &y,M t){\n  int n=y.size()-1;\n  if(t.v<=n) return y[t.v];\n\n  vector<M> dp(n+1,1),pd(n+1,1);\n\
    \  for(int i=0;i<n;i++) dp[i+1]=dp[i]*(t-M(i));\n  for(int i=n;i>0;i--) pd[i-1]=pd[i]*(t-M(i));\n\
    \n  vector<M> fact(n+1,1),finv(n+1,1);\n  for(int i=1;i<=n;i++) fact[i]=fact[i-1]*M(i);\n\
    \  finv[n]=M(1)/fact[n];\n  for(int i=n;i>=1;i--) finv[i-1]=finv[i]*M(i);\n\n\
    \  M res(0);\n  for(int i=0;i<=n;i++){\n    M tmp=y[i]*dp[i]*pd[i]*finv[i]*finv[n-i];\n\
    \    if((n-i)&1) res-=tmp;\n    else res+=tmp;\n  }\n  return res;\n}\n//END CUT\
    \ HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename M>\nM lagrange_interpolation(vector<M> &y,M\
    \ t){\n  int n=y.size()-1;\n  if(t.v<=n) return y[t.v];\n\n  vector<M> dp(n+1,1),pd(n+1,1);\n\
    \  for(int i=0;i<n;i++) dp[i+1]=dp[i]*(t-M(i));\n  for(int i=n;i>0;i--) pd[i-1]=pd[i]*(t-M(i));\n\
    \n  vector<M> fact(n+1,1),finv(n+1,1);\n  for(int i=1;i<=n;i++) fact[i]=fact[i-1]*M(i);\n\
    \  finv[n]=M(1)/fact[n];\n  for(int i=n;i>=1;i--) finv[i-1]=finv[i]*M(i);\n\n\
    \  M res(0);\n  for(int i=0;i<=n;i++){\n    M tmp=y[i]*dp[i]*pd[i]*finv[i]*finv[n-i];\n\
    \    if((n-i)&1) res-=tmp;\n    else res+=tmp;\n  }\n  return res;\n}\n//END CUT\
    \ HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: polynomial/lagrangeinterpolation.cpp
  requiredBy: []
  timestamp: '2020-03-10 20:00:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2951.test.cpp
  - test/yukicoder/0022.test.cpp
documentation_of: polynomial/lagrangeinterpolation.cpp
layout: document
redirect_from:
- /library/polynomial/lagrangeinterpolation.cpp
- /library/polynomial/lagrangeinterpolation.cpp.html
title: polynomial/lagrangeinterpolation.cpp
---
