---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/largestrectangle.cpp
    title: algorithm/largestrectangle.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C
  bundledCode: "#line 1 \"test/aoj/DPL_3_C.test.cpp\"\n// verification-helper: PROBLEM\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"algorithm/largestrectangle.cpp\"\
    \n\n#line 3 \"algorithm/largestrectangle.cpp\"\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename T>\nT largestrectangle(vector<T> &v){\n  int\
    \ n=v.size();\n  T res=0;\n  using P = pair<int, T>;\n  stack<P> sp;\n  sp.emplace(-1,T(0));\n\
    \  for(int i=0;i<n;i++){\n    int j=i;\n    while(sp.top().second>v[i]){\n   \
    \   j=sp.top().first;\n      res=max(res,(i-j)*sp.top().second);\n      sp.pop();\n\
    \    }\n    if(sp.top().second<v[i]) sp.emplace(j,v[i]);\n  }\n  while(!sp.empty()){\n\
    \    res=max(res,(n-sp.top().first)*sp.top().second);\n    sp.pop();\n  }\n  return\
    \ res;\n}\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n#line 8 \"test/aoj/DPL_3_C.test.cpp\"\n#undef\
    \ call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n;\n  cin>>n;\n\n  using ll = long long;\n  vector<ll> vs(n);\n  for(int\
    \ i=0;i<n;i++) cin>>vs[i];\n\n  cout<<largestrectangle(vs)<<endl;\n  return 0;\n\
    }\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../algorithm/largestrectangle.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n;\n  cin>>n;\n\n  using ll\
    \ = long long;\n  vector<ll> vs(n);\n  for(int i=0;i<n;i++) cin>>vs[i];\n\n  cout<<largestrectangle(vs)<<endl;\n\
    \  return 0;\n}\n"
  dependsOn:
  - algorithm/largestrectangle.cpp
  isVerificationFile: true
  path: test/aoj/DPL_3_C.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 12:43:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_3_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_3_C.test.cpp
- /verify/test/aoj/DPL_3_C.test.cpp.html
title: test/aoj/DPL_3_C.test.cpp
---
