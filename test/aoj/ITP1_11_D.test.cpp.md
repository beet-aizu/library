---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/dice.cpp
    title: tools/dice.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_D
  bundledCode: "#line 1 \"test/aoj/ITP1_11_D.test.cpp\"\n// verification-helper: PROBLEM\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_D\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"tools/dice.cpp\"\n\n\
    #line 3 \"tools/dice.cpp\"\nusing namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename\
    \ T=int>\nstruct Die{\n  array<T, 6> fs;\n  int &top()   {return fs[0];}\n  int\
    \ &south() {return fs[1];}\n  int &east()  {return fs[2];}\n  int &west()  {return\
    \ fs[3];}\n  int &north() {return fs[4];}\n  int &bottom(){return fs[5];}\n  void\
    \ roll(char c){\n    //the view from above\n    // N\n    //W E\n    // S\n  \
    \  string b(\"EWNSRL\");\n    int v[6][4]={{0,3,5,2},\n                 {0,2,5,3},\n\
    \                 {0,1,5,4},\n                 {0,4,5,1},\n                 {1,2,4,3},\n\
    \                 {1,3,4,2}};\n    for(int k=0;k<6;k++){\n      if(b[k]!=c) continue;\n\
    \      int t=fs[v[k][0]];\n      fs[v[k][0]]=fs[v[k][1]];\n      fs[v[k][1]]=fs[v[k][2]];\n\
    \      fs[v[k][2]]=fs[v[k][3]];\n      fs[v[k][3]]=t;\n    }\n  }\n  using ll\
    \ = long long;\n  ll hash(){\n    ll res=0;\n    for(int i=0;i<6;i++) res=res*256+fs[i];\n\
    \    return res;\n  }\n  bool operator==(const Die &d) const{\n    for(int i=0;i<6;i++)\
    \ if(fs[i]!=d.fs[i]) return 0;\n    return 1;\n  }\n};\n\ntemplate<typename T>\n\
    vector<Die<T>> makeDice(Die<T> d){\n  vector<Die<T>> res;\n  for(int i=0;i<6;i++){\n\
    \    Die t(d);\n    if(i==1) t.roll('N');\n    if(i==2) t.roll('S');\n    if(i==3)\
    \ t.roll('S'),t.roll('S');\n    if(i==4) t.roll('L');\n    if(i==5) t.roll('R');\n\
    \    for(int k=0;k<4;k++){\n      res.push_back(t);\n      t.roll('E');\n    }\n\
    \  }\n  return res;\n}\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n\
    \  return 0;\n}\n#endif\n#line 8 \"test/aoj/ITP1_11_D.test.cpp\"\n#undef call_from_test\n\
    \nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n;\n  cin>>n;\n\
    \n  vector<Die<int>> ds(n);\n  for(int j=0;j<n;j++)\n    for(int i=0;i<6;i++)\n\
    \      cin>>ds[j].fs[i];\n\n  bool ff=true;\n  for(int i=0;i<n;i++){\n    auto\
    \ vd=makeDice(ds[i]);\n    for(int j=0;j<i;j++){\n      bool f=false;\n      for(auto\
    \ d:vd) f|=d==ds[j];\n      ff&=!f;\n    }\n  }\n\n  cout<<(ff?\"Yes\":\"No\"\
    )<<endl;\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_D\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../tools/dice.cpp\"\n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n\n  int n;\n  cin>>n;\n\n  vector<Die<int>> ds(n);\n\
    \  for(int j=0;j<n;j++)\n    for(int i=0;i<6;i++)\n      cin>>ds[j].fs[i];\n\n\
    \  bool ff=true;\n  for(int i=0;i<n;i++){\n    auto vd=makeDice(ds[i]);\n    for(int\
    \ j=0;j<i;j++){\n      bool f=false;\n      for(auto d:vd) f|=d==ds[j];\n    \
    \  ff&=!f;\n    }\n  }\n\n  cout<<(ff?\"Yes\":\"No\")<<endl;\n  return 0;\n}\n"
  dependsOn:
  - tools/dice.cpp
  isVerificationFile: true
  path: test/aoj/ITP1_11_D.test.cpp
  requiredBy: []
  timestamp: '2020-09-28 15:14:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ITP1_11_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ITP1_11_D.test.cpp
- /verify/test/aoj/ITP1_11_D.test.cpp.html
title: test/aoj/ITP1_11_D.test.cpp
---