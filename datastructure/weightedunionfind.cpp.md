---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_1_B.test.cpp
    title: test/aoj/DSL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/3592.test.cpp
    title: test/yukicoder/3592.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructure/weightedunionfind.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate <typename T>\nstruct\
    \ WeightedUnionFind{\n  vector<int> rs,ps;\n  vector<T> ws;\n\n  WeightedUnionFind(int\
    \ n):rs(n,1),ps(n),ws(n,T(0)){\n    iota(ps.begin(),ps.end(),0);\n  }\n\n  int\
    \ find(int x){\n    if(x==ps[x]) return x;\n    int t=find(ps[x]);\n    ws[x]+=ws[ps[x]];\n\
    \    return ps[x]=t;\n  }\n\n  T weight(int x){\n    find(x);\n    return ws[x];\n\
    \  }\n\n  bool same(int x,int y){\n    return find(x)==find(y);\n  }\n\n  void\
    \ unite(int x,int y,T w){\n    w+=weight(x);\n    w-=weight(y);\n    x=find(x);y=find(y);\n\
    \    if(x==y) return;\n    if(rs[x]<rs[y]) swap(x,y),w=-w;\n    rs[x]+=rs[y];\n\
    \    ps[y]=x;\n    ws[y]=w;\n  }\n\n  T diff(int x,int y){\n    return weight(y)-weight(x);\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n\
    }\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate <typename T>\nstruct WeightedUnionFind{\n  vector<int>\
    \ rs,ps;\n  vector<T> ws;\n\n  WeightedUnionFind(int n):rs(n,1),ps(n),ws(n,T(0)){\n\
    \    iota(ps.begin(),ps.end(),0);\n  }\n\n  int find(int x){\n    if(x==ps[x])\
    \ return x;\n    int t=find(ps[x]);\n    ws[x]+=ws[ps[x]];\n    return ps[x]=t;\n\
    \  }\n\n  T weight(int x){\n    find(x);\n    return ws[x];\n  }\n\n  bool same(int\
    \ x,int y){\n    return find(x)==find(y);\n  }\n\n  void unite(int x,int y,T w){\n\
    \    w+=weight(x);\n    w-=weight(y);\n    x=find(x);y=find(y);\n    if(x==y)\
    \ return;\n    if(rs[x]<rs[y]) swap(x,y),w=-w;\n    rs[x]+=rs[y];\n    ps[y]=x;\n\
    \    ws[y]=w;\n  }\n\n  T diff(int x,int y){\n    return weight(y)-weight(x);\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n\
    }\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/weightedunionfind.cpp
  requiredBy: []
  timestamp: '2020-10-27 19:32:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/3592.test.cpp
  - test/aoj/DSL_1_B.test.cpp
documentation_of: datastructure/weightedunionfind.cpp
layout: document
redirect_from:
- /library/datastructure/weightedunionfind.cpp
- /library/datastructure/weightedunionfind.cpp.html
title: datastructure/weightedunionfind.cpp
---
