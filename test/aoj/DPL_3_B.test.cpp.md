---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/largestrectangle.cpp
    title: algorithm/largestrectangle.cpp
  - icon: ':heavy_check_mark:'
    path: tools/chminmax.cpp
    title: tools/chminmax.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B
  bundledCode: "#line 1 \"test/aoj/DPL_3_B.test.cpp\"\n// verification-helper: PROBLEM\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 2 \"tools/chminmax.cpp\"\
    \n\n#ifndef call_from_test\n#line 5 \"tools/chminmax.cpp\"\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename T1,typename T2> inline void chmin(T1\
    \ &a,T2 b){if(a>b) a=b;}\ntemplate<typename T1,typename T2> inline void chmax(T1\
    \ &a,T2 b){if(a<b) a=b;}\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n\
    \  return 0;\n}\n#endif\n#line 2 \"algorithm/largestrectangle.cpp\"\n\n#ifndef\
    \ call_from_test\n#line 5 \"algorithm/largestrectangle.cpp\"\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nT largestrectangle(vector<T>\
    \ &v){\n  int n=v.size();\n  T res=0;\n  using P = pair<int, T>;\n  stack<P> sp;\n\
    \  sp.emplace(-1,T(0));\n  for(int i=0;i<n;i++){\n    int j=i;\n    while(sp.top().second>v[i]){\n\
    \      j=sp.top().first;\n      res=max(res,(i-j)*sp.top().second);\n      sp.pop();\n\
    \    }\n    if(sp.top().second<v[i]) sp.emplace(j,v[i]);\n  }\n  while(!sp.empty()){\n\
    \    res=max(res,(n-sp.top().first)*sp.top().second);\n    sp.pop();\n  }\n  return\
    \ res;\n}\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n#line 9 \"test/aoj/DPL_3_B.test.cpp\"\n#undef\
    \ call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int h,w;\n  cin>>h>>w;\n\n  vector< vector<int> > cs(h,vector<int>(w));\n\
    \  for(int i=0;i<h;i++)\n    for(int j=0;j<w;j++)\n      cin>>cs[i][j];\n\n  int\
    \ res=0;\n  vector<int> dp(w,0);\n  for(int i=0;i<h;i++){\n    for(int j=0;j<w;j++)\n\
    \      dp[j]=cs[i][j]==0?dp[j]+1:0;\n    chmax(res,largestrectangle(dp));\n  }\n\
    \n  cout<<res<<endl;\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../tools/chminmax.cpp\"\n#include \"../../algorithm/largestrectangle.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int h,w;\n  cin>>h>>w;\n\n  vector< vector<int> > cs(h,vector<int>(w));\n\
    \  for(int i=0;i<h;i++)\n    for(int j=0;j<w;j++)\n      cin>>cs[i][j];\n\n  int\
    \ res=0;\n  vector<int> dp(w,0);\n  for(int i=0;i<h;i++){\n    for(int j=0;j<w;j++)\n\
    \      dp[j]=cs[i][j]==0?dp[j]+1:0;\n    chmax(res,largestrectangle(dp));\n  }\n\
    \n  cout<<res<<endl;\n  return 0;\n}\n"
  dependsOn:
  - tools/chminmax.cpp
  - algorithm/largestrectangle.cpp
  isVerificationFile: true
  path: test/aoj/DPL_3_B.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 14:33:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_3_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_3_B.test.cpp
- /verify/test/aoj/DPL_3_B.test.cpp.html
title: test/aoj/DPL_3_B.test.cpp
---
