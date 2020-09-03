---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"tools/dice.cpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\nstruct Die{\n  int s[6];\n  int &top()   {return\
    \ s[0];}\n  int &south() {return s[1];}\n  int &east()  {return s[2];}\n  int\
    \ &west()  {return s[3];}\n  int &north() {return s[4];}\n  int &bottom(){return\
    \ s[5];}\n  void roll(char c){\n    //the view from above\n    // N\n    //W E\n\
    \    // S\n    string b(\"EWNSRL\");\n    int v[6][4]={{0,3,5,2},\n          \
    \       {0,2,5,3},\n                 {0,1,5,4},\n                 {0,4,5,1},\n\
    \                 {1,2,4,3},\n                 {1,3,4,2}};\n    for(int k=0;k<6;k++){\n\
    \      if(b[k]!=c) continue;\n      int t=s[v[k][0]];\n      s[v[k][0]]=s[v[k][1]];\n\
    \      s[v[k][1]]=s[v[k][2]];\n      s[v[k][2]]=s[v[k][3]];\n      s[v[k][3]]=t;\n\
    \    }\n  }\n  using ll = long long;\n  ll hash(){\n    ll res=0;\n    for(int\
    \ i=0;i<6;i++) res=res*256+s[i];\n    return res;\n  }\n  bool operator==(const\
    \ Die &d) const{\n    for(int i=0;i<6;i++) if(s[i]!=d.s[i]) return 0;\n    return\
    \ 1;\n  }\n};\n\nvector<Die> makeDice(Die d){\n  vector<Die> res;\n  for(int i=0;i<6;i++){\n\
    \    Die t(d);\n    if(i==1) t.roll('N');\n    if(i==2) t.roll('S');\n    if(i==3)\
    \ t.roll('S'),t.roll('S');\n    if(i==4) t.roll('L');\n    if(i==5) t.roll('R');\n\
    \    for(int k=0;k<4;k++){\n      res.push_back(t);\n      t.roll('E');\n    }\n\
    \  }\n  return res;\n}\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nstruct Die{\n  int s[6];\n  int &top()   {return s[0];}\n  int\
    \ &south() {return s[1];}\n  int &east()  {return s[2];}\n  int &west()  {return\
    \ s[3];}\n  int &north() {return s[4];}\n  int &bottom(){return s[5];}\n  void\
    \ roll(char c){\n    //the view from above\n    // N\n    //W E\n    // S\n  \
    \  string b(\"EWNSRL\");\n    int v[6][4]={{0,3,5,2},\n                 {0,2,5,3},\n\
    \                 {0,1,5,4},\n                 {0,4,5,1},\n                 {1,2,4,3},\n\
    \                 {1,3,4,2}};\n    for(int k=0;k<6;k++){\n      if(b[k]!=c) continue;\n\
    \      int t=s[v[k][0]];\n      s[v[k][0]]=s[v[k][1]];\n      s[v[k][1]]=s[v[k][2]];\n\
    \      s[v[k][2]]=s[v[k][3]];\n      s[v[k][3]]=t;\n    }\n  }\n  using ll = long\
    \ long;\n  ll hash(){\n    ll res=0;\n    for(int i=0;i<6;i++) res=res*256+s[i];\n\
    \    return res;\n  }\n  bool operator==(const Die &d) const{\n    for(int i=0;i<6;i++)\
    \ if(s[i]!=d.s[i]) return 0;\n    return 1;\n  }\n};\n\nvector<Die> makeDice(Die\
    \ d){\n  vector<Die> res;\n  for(int i=0;i<6;i++){\n    Die t(d);\n    if(i==1)\
    \ t.roll('N');\n    if(i==2) t.roll('S');\n    if(i==3) t.roll('S'),t.roll('S');\n\
    \    if(i==4) t.roll('L');\n    if(i==5) t.roll('R');\n    for(int k=0;k<4;k++){\n\
    \      res.push_back(t);\n      t.roll('E');\n    }\n  }\n  return res;\n}\n//END\
    \ CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP1_11_D.test.cpp
    title: test/aoj/ITP1_11_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1197.test.cpp
    title: test/aoj/1197.test.cpp
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
    path: test/aoj/0502.test.cpp
    title: test/aoj/0502.test.cpp
  isVerificationFile: false
  path: tools/dice.cpp
  requiredBy: []
  timestamp: '2019-12-17 20:42:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - test/aoj/ITP1_11_D.test.cpp
  - test/aoj/1197.test.cpp
  - test/aoj/ITP1_11_A.test.cpp
  - test/aoj/ITP1_11_B.test.cpp
  - test/aoj/ITP1_11_C.test.cpp
  - test/aoj/0502.test.cpp
documentation_of: tools/dice.cpp
layout: document
redirect_from:
- /library/tools/dice.cpp
- /library/tools/dice.cpp.html
title: tools/dice.cpp
---
