---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2603.test.cpp
    title: test/aoj/2603.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/monotoneminima.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\nnamespace MonotoneMinima{\n  template<typename\
    \ T,typename F>\n  void induce(int l,int r,int a,int b,vector<int> &dp,F dist){\n\
    \    if(l==r) return;\n    int m=(l+r)>>1;\n    int &idx=(dp[m]=a);\n    T res=dist(m,idx);\n\
    \    for(int i=a;i<b;i++){\n      T tmp=dist(m,i);\n      if(tmp<res) res=tmp,idx=i;\n\
    \    }\n    induce<T>(l,m,a,idx+1,dp,dist);\n    induce<T>(m+1,r,idx,b,dp,dist);\n\
    \  }\n\n  // p < q -> argmin f(p, *) < argmin f(q, *)\n  template<typename T,typename\
    \ F>\n  vector<int> args(int n,int m,F dist){\n    vector<int> dp(n,-1);\n   \
    \ induce<T>(0,n,0,m,dp,dist);\n    return dp;\n  }\n}\n//END CUT HERE\n#ifndef\
    \ call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\nnamespace MonotoneMinima{\n  template<typename T,typename\
    \ F>\n  void induce(int l,int r,int a,int b,vector<int> &dp,F dist){\n    if(l==r)\
    \ return;\n    int m=(l+r)>>1;\n    int &idx=(dp[m]=a);\n    T res=dist(m,idx);\n\
    \    for(int i=a;i<b;i++){\n      T tmp=dist(m,i);\n      if(tmp<res) res=tmp,idx=i;\n\
    \    }\n    induce<T>(l,m,a,idx+1,dp,dist);\n    induce<T>(m+1,r,idx,b,dp,dist);\n\
    \  }\n\n  // p < q -> argmin f(p, *) < argmin f(q, *)\n  template<typename T,typename\
    \ F>\n  vector<int> args(int n,int m,F dist){\n    vector<int> dp(n,-1);\n   \
    \ induce<T>(0,n,0,m,dp,dist);\n    return dp;\n  }\n}\n//END CUT HERE\n#ifndef\
    \ call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/monotoneminima.cpp
  requiredBy: []
  timestamp: '2020-10-27 12:43:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2603.test.cpp
documentation_of: algorithm/monotoneminima.cpp
layout: document
redirect_from:
- /library/algorithm/monotoneminima.cpp
- /library/algorithm/monotoneminima.cpp.html
title: algorithm/monotoneminima.cpp
---
