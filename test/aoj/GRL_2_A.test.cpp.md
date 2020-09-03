---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#line 1 \"test/aoj/GRL_2_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #line 1 \"graph/kruskal.cpp\"\n\n#line 3 \"graph/kruskal.cpp\"\nusing namespace\
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
    #endif\n#line 8 \"test/aoj/GRL_2_A.test.cpp\"\n#undef call_from_test\n\nsigned\
    \ main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int V,E;\n  cin>>V>>E;\n\
    \n  Kruskal<int> G(V);\n  for(int i=0;i<E;i++){\n    int a,b,c;\n    cin>>a>>b>>c;\n\
    \    G.add_edge(a,b,c);\n  }\n\n  cout<<G.build()<<endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../graph/kruskal.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int V,E;\n  cin>>V>>E;\n\n  Kruskal<int>\
    \ G(V);\n  for(int i=0;i<E;i++){\n    int a,b,c;\n    cin>>a>>b>>c;\n    G.add_edge(a,b,c);\n\
    \  }\n\n  cout<<G.build()<<endl;\n  return 0;\n}\n"
  dependsOn:
  - graph/kruskal.cpp
  extendedDependsOn:
  - icon: ':warning:'
    path: graph/kruskal.cpp
    title: graph/kruskal.cpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: test/aoj/GRL_2_A.test.cpp
  requiredBy: []
  timestamp: '2019-11-21 16:50:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: test/aoj/GRL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_2_A.test.cpp
- /verify/test/aoj/GRL_2_A.test.cpp.html
title: test/aoj/GRL_2_A.test.cpp
---
