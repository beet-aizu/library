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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_A
  bundledCode: "#line 1 \"test/aoj/ITP1_11_A.test.cpp\"\n// verification-helper: PROBLEM\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_A\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"tools/dice.cpp\"\n\n\
    #line 3 \"tools/dice.cpp\"\nusing namespace std;\n#endif\n//BEGIN CUT HERE\nstruct\
    \ Die{\n  int s[6];\n  int &top()   {return s[0];}\n  int &south() {return s[1];}\n\
    \  int &east()  {return s[2];}\n  int &west()  {return s[3];}\n  int &north()\
    \ {return s[4];}\n  int &bottom(){return s[5];}\n  void roll(char c){\n    //the\
    \ view from above\n    // N\n    //W E\n    // S\n    string b(\"EWNSRL\");\n\
    \    int v[6][4]={{0,3,5,2},\n                 {0,2,5,3},\n                 {0,1,5,4},\n\
    \                 {0,4,5,1},\n                 {1,2,4,3},\n                 {1,3,4,2}};\n\
    \    for(int k=0;k<6;k++){\n      if(b[k]!=c) continue;\n      int t=s[v[k][0]];\n\
    \      s[v[k][0]]=s[v[k][1]];\n      s[v[k][1]]=s[v[k][2]];\n      s[v[k][2]]=s[v[k][3]];\n\
    \      s[v[k][3]]=t;\n    }\n  }\n  using ll = long long;\n  ll hash(){\n    ll\
    \ res=0;\n    for(int i=0;i<6;i++) res=res*256+s[i];\n    return res;\n  }\n \
    \ bool operator==(const Die &d) const{\n    for(int i=0;i<6;i++) if(s[i]!=d.s[i])\
    \ return 0;\n    return 1;\n  }\n};\n\nvector<Die> makeDice(Die d){\n  vector<Die>\
    \ res;\n  for(int i=0;i<6;i++){\n    Die t(d);\n    if(i==1) t.roll('N');\n  \
    \  if(i==2) t.roll('S');\n    if(i==3) t.roll('S'),t.roll('S');\n    if(i==4)\
    \ t.roll('L');\n    if(i==5) t.roll('R');\n    for(int k=0;k<4;k++){\n      res.push_back(t);\n\
    \      t.roll('E');\n    }\n  }\n  return res;\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    signed main(){\n  return 0;\n}\n#endif\n#line 8 \"test/aoj/ITP1_11_A.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  Die d;\n  for(int i=0;i<6;i++) cin>>d.s[i];\n\n  string s;\n  cin>>s;\n\n\
    \  for(int i=0;i<(int)s.size();i++) d.roll(s[i]);\n\n  cout<<d.top()<<endl;\n\
    \  return 0;\n}\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_A\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../tools/dice.cpp\"\n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n\n  Die d;\n  for(int i=0;i<6;i++) cin>>d.s[i];\n\
    \n  string s;\n  cin>>s;\n\n  for(int i=0;i<(int)s.size();i++) d.roll(s[i]);\n\
    \n  cout<<d.top()<<endl;\n  return 0;\n}\n"
  dependsOn:
  - tools/dice.cpp
  isVerificationFile: true
  path: test/aoj/ITP1_11_A.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 15:10:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ITP1_11_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ITP1_11_A.test.cpp
- /verify/test/aoj/ITP1_11_A.test.cpp.html
title: test/aoj/ITP1_11_A.test.cpp
---
