---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3143.test.cpp
    title: test/aoj/3143.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 2 \"toptree/farthest.cpp\"\n\n#ifndef call_from_test\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#endif\n//BEGIN CUT HERE\nstruct Vertex{\n\
    \  void* handle;\n  Vertex():handle(nullptr){}\n};\n\ntemplate<typename T>\nstruct\
    \ Farthest{\n  struct pi{\n    T dist;\n    int idx;\n    pi():dist(0),idx(-1){}\n\
    \    pi(T dist,int idx):dist(dist),idx(idx){}\n    bool operator<(const pi &o)const{return\
    \ dist<o.dist;}\n    pi operator+(const T e)const{return pi(dist+e,idx);}\n  };\n\
    \  pi md,lf,rg;\n  T len;\n  Farthest():lf(0,-1),rg(0,-1),len(0){}\n  Farthest(T\
    \ d,int f,int t):lf(d,t),rg(d,f),len(d){}\n  Farthest(pi md,pi lf,pi rg,T len):\n\
    \    md(md),lf(lf),rg(rg),len(len){}\n  void toggle(){swap(lf,rg);}\n\n  static\
    \ Farthest compress(Farthest &x,Vertex*,Farthest &y){\n    return Farthest(\n\
    \      max(x.rg,y.lf),\n      max(x.lf,y.lf+x.len),\n      max(y.rg,x.rg+y.len),\n\
    \      x.len+y.len);\n  }\n  static Farthest rake(Farthest &x,Farthest &y){\n\
    \    return Farthest(pi(),max(x.lf,y.rg+x.len),max(x.rg,y.rg),x.len);\n  }\n};\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\nstruct Vertex{\n  void* handle;\n  Vertex():handle(nullptr){}\n\
    };\n\ntemplate<typename T>\nstruct Farthest{\n  struct pi{\n    T dist;\n    int\
    \ idx;\n    pi():dist(0),idx(-1){}\n    pi(T dist,int idx):dist(dist),idx(idx){}\n\
    \    bool operator<(const pi &o)const{return dist<o.dist;}\n    pi operator+(const\
    \ T e)const{return pi(dist+e,idx);}\n  };\n  pi md,lf,rg;\n  T len;\n  Farthest():lf(0,-1),rg(0,-1),len(0){}\n\
    \  Farthest(T d,int f,int t):lf(d,t),rg(d,f),len(d){}\n  Farthest(pi md,pi lf,pi\
    \ rg,T len):\n    md(md),lf(lf),rg(rg),len(len){}\n  void toggle(){swap(lf,rg);}\n\
    \n  static Farthest compress(Farthest &x,Vertex*,Farthest &y){\n    return Farthest(\n\
    \      max(x.rg,y.lf),\n      max(x.lf,y.lf+x.len),\n      max(y.rg,x.rg+y.len),\n\
    \      x.len+y.len);\n  }\n  static Farthest rake(Farthest &x,Farthest &y){\n\
    \    return Farthest(pi(),max(x.lf,y.rg+x.len),max(x.rg,y.rg),x.len);\n  }\n};\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: toptree/farthest.cpp
  requiredBy: []
  timestamp: '2020-09-01 16:43:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3143.test.cpp
documentation_of: toptree/farthest.cpp
layout: document
redirect_from:
- /library/toptree/farthest.cpp
- /library/toptree/farthest.cpp.html
title: toptree/farthest.cpp
---
