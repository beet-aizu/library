---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/rangeslide.cpp
    title: datastructure/rangeslide.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
  bundledCode: "#line 1 \"test/aoj/DSL_3_D.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #line 1 \"datastructure/rangeslide.cpp\"\n\n#line 3 \"datastructure/rangeslide.cpp\"\
    \nusing namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T, typename\
    \ F>\nstruct RangeSlide{\n  vector<size_t> ls,rs;\n  vector<T> vs;\n  F cmp;\n\
    \  RangeSlide(vector<T> vs,F cmp):vs(vs),cmp(cmp){}\n\n  void add_range(size_t\
    \ l,size_t r){\n    ls.emplace_back(l);\n    rs.emplace_back(r);\n  }\n\n  vector<size_t>\
    \ build(){\n    deque<size_t> deq;\n    vector<size_t> res;\n    for(size_t i=0,l=0,r=0;i<ls.size();i++){\n\
    \      if(r<=ls[i]){\n        deq.clear();\n        l=r=ls[i];\n      }\n    \
    \  while(r<rs[i]){\n        while(!deq.empty()&&\n              !cmp(vs[deq.back()],vs[r]))\
    \ deq.pop_back();\n        deq.emplace_back(r++);\n      }\n      while(l<ls[i]){\n\
    \        if(deq.front()==l++) deq.pop_front();\n      }\n      res.emplace_back(deq.front());\n\
    \    }\n    return res;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT\
    \ ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n#line 8 \"test/aoj/DSL_3_D.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,l;\n  cin>>n>>l;\n  vector<int> as(n);\n  for(int i=0;i<n;i++) cin>>as[i];\n\
    \n  auto cmp=[](int a,int b){return a<b;};\n  RangeSlide<int, decltype(cmp)> rs(as,cmp);\n\
    \n  for(int i=0;i+l<=n;i++) rs.add_range(i,i+l);\n  auto res=rs.build();\n  for(int\
    \ i=0;i+l<=n;i++){\n    if(i) cout<<\" \";\n    cout<<as[res[i]];\n  }\n  cout<<endl;\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../datastructure/rangeslide.cpp\"\n#undef call_from_test\n\nsigned\
    \ main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,l;\n  cin>>n>>l;\n\
    \  vector<int> as(n);\n  for(int i=0;i<n;i++) cin>>as[i];\n\n  auto cmp=[](int\
    \ a,int b){return a<b;};\n  RangeSlide<int, decltype(cmp)> rs(as,cmp);\n\n  for(int\
    \ i=0;i+l<=n;i++) rs.add_range(i,i+l);\n  auto res=rs.build();\n  for(int i=0;i+l<=n;i++){\n\
    \    if(i) cout<<\" \";\n    cout<<as[res[i]];\n  }\n  cout<<endl;\n  return 0;\n\
    }\n"
  dependsOn:
  - datastructure/rangeslide.cpp
  isVerificationFile: true
  path: test/aoj/DSL_3_D.test.cpp
  requiredBy: []
  timestamp: '2020-05-07 20:09:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_3_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_3_D.test.cpp
- /verify/test/aoj/DSL_3_D.test.cpp.html
title: test/aoj/DSL_3_D.test.cpp
---
