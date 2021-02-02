---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0502.test.cpp
    title: test/aoj/0502.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1197.test.cpp
    title: test/aoj/1197.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3138.test.cpp
    title: test/aoj/3138.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP1_11_A.test.cpp
    title: test/aoj/ITP1_11_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP1_11_B.test.cpp
    title: test/aoj/ITP1_11_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP1_11_C.test.cpp
    title: test/aoj/ITP1_11_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP1_11_D.test.cpp
    title: test/aoj/ITP1_11_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/dice.cpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T=int>\nstruct Die{\n  array<T,\
    \ 6> fs;\n  int &top()   {return fs[0];}\n  int &south() {return fs[1];}\n  int\
    \ &east()  {return fs[2];}\n  int &west()  {return fs[3];}\n  int &north() {return\
    \ fs[4];}\n  int &bottom(){return fs[5];}\n  void roll(char c){\n    //the view\
    \ from above\n    // N\n    //W E\n    // S\n    string b(\"EWNSRL\");\n    int\
    \ v[6][4]={{0,3,5,2},\n                 {0,2,5,3},\n                 {0,1,5,4},\n\
    \                 {0,4,5,1},\n                 {1,2,4,3},\n                 {1,3,4,2}};\n\
    \    for(int k=0;k<6;k++){\n      if(b[k]!=c) continue;\n      int t=fs[v[k][0]];\n\
    \      fs[v[k][0]]=fs[v[k][1]];\n      fs[v[k][1]]=fs[v[k][2]];\n      fs[v[k][2]]=fs[v[k][3]];\n\
    \      fs[v[k][3]]=t;\n    }\n  }\n  using ll = long long;\n  ll hash(){\n   \
    \ ll res=0;\n    for(int i=0;i<6;i++) res=res*256+fs[i];\n    return res;\n  }\n\
    \  bool operator==(const Die &d) const{\n    for(int i=0;i<6;i++) if(fs[i]!=d.fs[i])\
    \ return 0;\n    return 1;\n  }\n};\n\ntemplate<typename T>\nvector<Die<T>> makeDice(Die<T>\
    \ d){\n  vector<Die<T>> res;\n  for(int i=0;i<6;i++){\n    Die t(d);\n    if(i==1)\
    \ t.roll('N');\n    if(i==2) t.roll('S');\n    if(i==3) t.roll('S'),t.roll('S');\n\
    \    if(i==4) t.roll('L');\n    if(i==5) t.roll('R');\n    for(int k=0;k<4;k++){\n\
    \      res.emplace_back(t);\n      t.roll('E');\n    }\n  }\n  return res;\n}\n\
    //END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename T=int>\nstruct Die{\n  array<T, 6> fs;\n \
    \ int &top()   {return fs[0];}\n  int &south() {return fs[1];}\n  int &east()\
    \  {return fs[2];}\n  int &west()  {return fs[3];}\n  int &north() {return fs[4];}\n\
    \  int &bottom(){return fs[5];}\n  void roll(char c){\n    //the view from above\n\
    \    // N\n    //W E\n    // S\n    string b(\"EWNSRL\");\n    int v[6][4]={{0,3,5,2},\n\
    \                 {0,2,5,3},\n                 {0,1,5,4},\n                 {0,4,5,1},\n\
    \                 {1,2,4,3},\n                 {1,3,4,2}};\n    for(int k=0;k<6;k++){\n\
    \      if(b[k]!=c) continue;\n      int t=fs[v[k][0]];\n      fs[v[k][0]]=fs[v[k][1]];\n\
    \      fs[v[k][1]]=fs[v[k][2]];\n      fs[v[k][2]]=fs[v[k][3]];\n      fs[v[k][3]]=t;\n\
    \    }\n  }\n  using ll = long long;\n  ll hash(){\n    ll res=0;\n    for(int\
    \ i=0;i<6;i++) res=res*256+fs[i];\n    return res;\n  }\n  bool operator==(const\
    \ Die &d) const{\n    for(int i=0;i<6;i++) if(fs[i]!=d.fs[i]) return 0;\n    return\
    \ 1;\n  }\n};\n\ntemplate<typename T>\nvector<Die<T>> makeDice(Die<T> d){\n  vector<Die<T>>\
    \ res;\n  for(int i=0;i<6;i++){\n    Die t(d);\n    if(i==1) t.roll('N');\n  \
    \  if(i==2) t.roll('S');\n    if(i==3) t.roll('S'),t.roll('S');\n    if(i==4)\
    \ t.roll('L');\n    if(i==5) t.roll('R');\n    for(int k=0;k<4;k++){\n      res.emplace_back(t);\n\
    \      t.roll('E');\n    }\n  }\n  return res;\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/dice.cpp
  requiredBy: []
  timestamp: '2020-10-25 17:34:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1197.test.cpp
  - test/aoj/ITP1_11_C.test.cpp
  - test/aoj/0502.test.cpp
  - test/aoj/ITP1_11_A.test.cpp
  - test/aoj/3138.test.cpp
  - test/aoj/ITP1_11_D.test.cpp
  - test/aoj/ITP1_11_B.test.cpp
documentation_of: tools/dice.cpp
layout: document
redirect_from:
- /library/tools/dice.cpp
- /library/tools/dice.cpp.html
title: tools/dice.cpp
---
