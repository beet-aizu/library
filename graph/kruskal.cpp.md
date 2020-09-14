---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: linearalgebra/tree_theorem.cpp
    title: linearalgebra/tree_theorem.cpp
  - icon: ':warning:'
    path: graph/voronoiminimumspanningtree.cpp
    title: graph/voronoiminimumspanningtree.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0403.test.cpp
    title: test/aoj/0403.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"graph/kruskal.cpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct Kruskal{\n\n  struct\
    \ edge{\n    int from,to;\n    T cost;\n    int used;\n    edge(int from,int to,T\
    \ cost):\n      from(from),to(to),cost(cost),used(0){}\n    bool operator<(const\
    \ edge& e) const{\n      return cost<e.cost;\n    }\n  };\n  vector<int> r,p;\n\
    \  vector<edge> es;\n\n  Kruskal(){}\n  Kruskal(int n):r(n,1),p(n){\n    iota(p.begin(),p.end(),0);\n\
    \  }\n\n  int find(int x){\n    return (x==p[x]?x:p[x]=find(p[x]));\n  }\n\n \
    \ bool same(int x,int y){\n    return find(x)==find(y);\n  }\n\n  void unite(int\
    \ x,int y){\n    x=find(x);y=find(y);\n    if(x==y) return;\n    if(r[x]<r[y])\
    \ swap(x,y);\n    r[x]+=r[y];\n    p[y]=x;\n  }\n\n  void add_edge(int u,int v,T\
    \ c){\n    es.emplace_back(u,v,c);\n  }\n\n  T build(){\n    sort(es.begin(),es.end());\n\
    \    T res=0;\n    for(auto &e:es){\n      if(!same(e.from,e.to)){\n        res+=e.cost;\n\
    \        unite(e.from,e.to);\n        e.used=1;\n      }\n    }\n    return res;\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\nint main(){\n  return 0;\n}\n\
    #endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename T>\nstruct Kruskal{\n\n  struct edge{\n  \
    \  int from,to;\n    T cost;\n    int used;\n    edge(int from,int to,T cost):\n\
    \      from(from),to(to),cost(cost),used(0){}\n    bool operator<(const edge&\
    \ e) const{\n      return cost<e.cost;\n    }\n  };\n  vector<int> r,p;\n  vector<edge>\
    \ es;\n\n  Kruskal(){}\n  Kruskal(int n):r(n,1),p(n){\n    iota(p.begin(),p.end(),0);\n\
    \  }\n\n  int find(int x){\n    return (x==p[x]?x:p[x]=find(p[x]));\n  }\n\n \
    \ bool same(int x,int y){\n    return find(x)==find(y);\n  }\n\n  void unite(int\
    \ x,int y){\n    x=find(x);y=find(y);\n    if(x==y) return;\n    if(r[x]<r[y])\
    \ swap(x,y);\n    r[x]+=r[y];\n    p[y]=x;\n  }\n\n  void add_edge(int u,int v,T\
    \ c){\n    es.emplace_back(u,v,c);\n  }\n\n  T build(){\n    sort(es.begin(),es.end());\n\
    \    T res=0;\n    for(auto &e:es){\n      if(!same(e.from,e.to)){\n        res+=e.cost;\n\
    \        unite(e.from,e.to);\n        e.used=1;\n      }\n    }\n    return res;\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\nint main(){\n  return 0;\n}\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/kruskal.cpp
  requiredBy:
  - linearalgebra/tree_theorem.cpp
  - graph/voronoiminimumspanningtree.cpp
  timestamp: '2019-11-21 16:50:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_2_A.test.cpp
  - test/aoj/0403.test.cpp
documentation_of: graph/kruskal.cpp
layout: document
redirect_from:
- /library/graph/kruskal.cpp
- /library/graph/kruskal.cpp.html
title: graph/kruskal.cpp
---
