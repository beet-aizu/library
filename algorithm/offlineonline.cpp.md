---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3086.test.cpp
    title: test/aoj/3086.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1948.test.cpp
    title: test/yukicoder/1948.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1950.test.cpp
    title: test/yukicoder/1950.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2113.test.cpp
    title: test/yukicoder/2113.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://qiita.com/tmaehara/items/0687af2cfb807cde7860
  bundledCode: "#line 1 \"algorithm/offlineonline.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n\n// https://qiita.com/tmaehara/items/0687af2cfb807cde7860\n\
    //BEGIN CUT HERE\nnamespace OfflineOnline{\n  vector<int> used;\n\n  template<typename\
    \ T>\n  void update(vector<T> &dp,int k,T val){\n    if(!used[k]) dp[k]=val;\n\
    \    dp[k]=min(dp[k],val);\n    used[k]=1;\n  }\n\n  // [l, r), [a, b]\n  template<typename\
    \ T,typename F>\n  void induce(int l,int r,int a,int b,vector<T> &dp,F dist){\n\
    \    if(l==r) return;\n    int m=(l+r)>>1;\n    assert(m<a);\n    int idx=a;\n\
    \    T res=dist(m,idx)+dp[idx];\n    for(int i=a;i<=b;i++){\n      T tmp=dist(m,i)+dp[i];\n\
    \      if(tmp<res) res=tmp,idx=i;\n    }\n    update(dp,m,res);\n    induce(l,m+0,a,idx,dp,dist);\n\
    \    induce(m+1,r,idx,b,dp,dist);\n  }\n\n  template<typename T,typename F>\n\
    \  void solve(int l,int r,vector<T> &dp,F dist){\n    if(l+1==r) return update(dp,l,dist(l,r)+dp[r]);\n\
    \    int m=(l+r)>>1;\n    solve(m,r,dp,dist);\n    induce(l,m,m,r,dp,dist);\n\
    \    solve(l,m,dp,dist);\n  }\n\n  // dp[i] = min_{i<j} dist(i,j) + dp[j]\n  template<typename\
    \ T,typename F>\n  T solve(int n,F dist){\n    vector<T> dp(n+1,0);\n    used.assign(n+1,0);\n\
    \    used[n]=1;\n    solve(0,n,dp,dist);\n    return dp[0];\n  }\n};\n//END CUT\
    \ HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n\n// https://qiita.com/tmaehara/items/0687af2cfb807cde7860\n//BEGIN CUT\
    \ HERE\nnamespace OfflineOnline{\n  vector<int> used;\n\n  template<typename T>\n\
    \  void update(vector<T> &dp,int k,T val){\n    if(!used[k]) dp[k]=val;\n    dp[k]=min(dp[k],val);\n\
    \    used[k]=1;\n  }\n\n  // [l, r), [a, b]\n  template<typename T,typename F>\n\
    \  void induce(int l,int r,int a,int b,vector<T> &dp,F dist){\n    if(l==r) return;\n\
    \    int m=(l+r)>>1;\n    assert(m<a);\n    int idx=a;\n    T res=dist(m,idx)+dp[idx];\n\
    \    for(int i=a;i<=b;i++){\n      T tmp=dist(m,i)+dp[i];\n      if(tmp<res) res=tmp,idx=i;\n\
    \    }\n    update(dp,m,res);\n    induce(l,m+0,a,idx,dp,dist);\n    induce(m+1,r,idx,b,dp,dist);\n\
    \  }\n\n  template<typename T,typename F>\n  void solve(int l,int r,vector<T>\
    \ &dp,F dist){\n    if(l+1==r) return update(dp,l,dist(l,r)+dp[r]);\n    int m=(l+r)>>1;\n\
    \    solve(m,r,dp,dist);\n    induce(l,m,m,r,dp,dist);\n    solve(l,m,dp,dist);\n\
    \  }\n\n  // dp[i] = min_{i<j} dist(i,j) + dp[j]\n  template<typename T,typename\
    \ F>\n  T solve(int n,F dist){\n    vector<T> dp(n+1,0);\n    used.assign(n+1,0);\n\
    \    used[n]=1;\n    solve(0,n,dp,dist);\n    return dp[0];\n  }\n};\n//END CUT\
    \ HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/offlineonline.cpp
  requiredBy: []
  timestamp: '2020-10-27 12:43:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3086.test.cpp
  - test/yukicoder/1948.test.cpp
  - test/yukicoder/2113.test.cpp
  - test/yukicoder/1950.test.cpp
documentation_of: algorithm/offlineonline.cpp
layout: document
redirect_from:
- /library/algorithm/offlineonline.cpp
- /library/algorithm/offlineonline.cpp.html
title: algorithm/offlineonline.cpp
---
