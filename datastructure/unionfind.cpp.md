---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: datastructure/skewheap.cpp
    title: datastructure/skewheap.cpp
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.cpp
    title: graph/kruskal.cpp
  - icon: ':heavy_check_mark:'
    path: graph/lowlink.cpp
    title: graph/lowlink.cpp
  - icon: ':heavy_check_mark:'
    path: linearalgebra/tree_theorem.cpp
    title: linearalgebra/tree_theorem.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0314.test.cpp
    title: test/aoj/0314.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0403.test.cpp
    title: test/aoj/0403.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2995.test.cpp
    title: test/aoj/2995.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_1_A.test.cpp
    title: test/aoj/DSL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/manhattanmst.test.cpp
    title: test/yosupo/manhattanmst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/unionfind.test.cpp
    title: test/yosupo/unionfind.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructure/unionfind.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\nstruct UnionFind{\n  int num;\n\
    \  vector<int> rs,ps;\n  UnionFind(){}\n  UnionFind(int n):num(n),rs(n,1),ps(n,0){iota(ps.begin(),ps.end(),0);}\n\
    \  int find(int x){\n    return (x==ps[x]?x:ps[x]=find(ps[x]));\n  }\n  bool same(int\
    \ x,int y){\n    return find(x)==find(y);\n  }\n  void unite(int x,int y){\n \
    \   x=find(x);y=find(y);\n    if(x==y) return;\n    if(rs[x]<rs[y]) swap(x,y);\n\
    \    rs[x]+=rs[y];\n    ps[y]=x;\n    num--;\n  }\n  int size(int x){\n    return\
    \ rs[find(x)];\n  }\n  int count() const{\n    return num;\n  }\n};\n//END CUT\
    \ HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nstruct UnionFind{\n  int num;\n  vector<int> rs,ps;\n  UnionFind(){}\n\
    \  UnionFind(int n):num(n),rs(n,1),ps(n,0){iota(ps.begin(),ps.end(),0);}\n  int\
    \ find(int x){\n    return (x==ps[x]?x:ps[x]=find(ps[x]));\n  }\n  bool same(int\
    \ x,int y){\n    return find(x)==find(y);\n  }\n  void unite(int x,int y){\n \
    \   x=find(x);y=find(y);\n    if(x==y) return;\n    if(rs[x]<rs[y]) swap(x,y);\n\
    \    rs[x]+=rs[y];\n    ps[y]=x;\n    num--;\n  }\n  int size(int x){\n    return\
    \ rs[find(x)];\n  }\n  int count() const{\n    return num;\n  }\n};\n//END CUT\
    \ HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/unionfind.cpp
  requiredBy:
  - graph/lowlink.cpp
  - graph/kruskal.cpp
  - linearalgebra/tree_theorem.cpp
  - datastructure/skewheap.cpp
  timestamp: '2020-05-17 19:42:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_1_A.test.cpp
  - test/aoj/2995.test.cpp
  - test/aoj/GRL_2_A.test.cpp
  - test/aoj/0403.test.cpp
  - test/aoj/0314.test.cpp
  - test/yosupo/unionfind.test.cpp
  - test/yosupo/manhattanmst.test.cpp
documentation_of: datastructure/unionfind.cpp
layout: document
redirect_from:
- /library/datastructure/unionfind.cpp
- /library/datastructure/unionfind.cpp.html
title: datastructure/unionfind.cpp
---
