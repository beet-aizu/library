---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2842.BIT2D.test.cpp
    title: test/aoj/2842.BIT2D.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructure/BIT2D.cpp\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct BIT2D{\n\
    \  int n,m;\n  T d;\n  vector< vector<T> > bit;\n  //1-indexed\n  BIT2D():n(-1),m(-1){}\n\
    \  BIT2D(int n_,int m_):n(n_),m(m_),bit(n_+1,vector<T>(m+1,0)){}\n  T sum(int\
    \ i,int j){\n    T s(0);\n    for(int x=i;x>0;x-=(x&-x))\n      for(int y=j;y>0;y-=(y&-y))\n\
    \        s+=bit[x][y];\n    return s;\n  }\n  void add(int i,int j,T a){\n   \
    \ if(i==0||j==0) return;\n    for(int x=i;x<=n;x+=(x&-x))\n      for(int y=j;y<=m;y+=(y&-y))\n\
    \        bit[x][y]+=a;\n  }\n  // (x1,x2] * (y1,y2];\n  T sum(int x1,int y1,int\
    \ x2,int y2){\n    return sum(x1,y1)-sum(x1,y2)-sum(x2,y1)+sum(x2,y2);\n  }\n\
    };\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename T>\nstruct BIT2D{\n  int n,m;\n  T d;\n  vector<\
    \ vector<T> > bit;\n  //1-indexed\n  BIT2D():n(-1),m(-1){}\n  BIT2D(int n_,int\
    \ m_):n(n_),m(m_),bit(n_+1,vector<T>(m+1,0)){}\n  T sum(int i,int j){\n    T s(0);\n\
    \    for(int x=i;x>0;x-=(x&-x))\n      for(int y=j;y>0;y-=(y&-y))\n        s+=bit[x][y];\n\
    \    return s;\n  }\n  void add(int i,int j,T a){\n    if(i==0||j==0) return;\n\
    \    for(int x=i;x<=n;x+=(x&-x))\n      for(int y=j;y<=m;y+=(y&-y))\n        bit[x][y]+=a;\n\
    \  }\n  // (x1,x2] * (y1,y2];\n  T sum(int x1,int y1,int x2,int y2){\n    return\
    \ sum(x1,y1)-sum(x1,y2)-sum(x2,y1)+sum(x2,y2);\n  }\n};\n//END CUT HERE\n#ifndef\
    \ call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/BIT2D.cpp
  requiredBy: []
  timestamp: '2019-11-11 16:56:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2842.BIT2D.test.cpp
documentation_of: datastructure/BIT2D.cpp
layout: document
redirect_from:
- /library/datastructure/BIT2D.cpp
- /library/datastructure/BIT2D.cpp.html
title: datastructure/BIT2D.cpp
---
