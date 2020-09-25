---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/2334.test.cpp
    title: test/aoj/geometry/2334.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0423.test.cpp
    title: test/aoj/0423.test.cpp
  - icon: ':x:'
    path: test/yosupo/shortest_path.test.cpp
    title: test/yosupo/shortest_path.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"graph/dijkstra.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct Dijkstra{\n\
    \  struct Edge{\n    int to;\n    T cost;\n    Edge(int to,T cost):to(to),cost(cost){}\n\
    \    bool operator<(const Edge &o)const{return cost>o.cost;}\n  };\n\n  vector<\
    \ vector<Edge> > G;\n  vector<T> ds;\n  vector<int> bs;\n  Dijkstra(int n):G(n){}\n\
    \n  void add_edge(int u,int v,T c){\n    G[u].emplace_back(v,c);\n  }\n\n  void\
    \ build(int s){\n    int n=G.size();\n    ds.assign(n,numeric_limits<T>::max());\n\
    \    bs.assign(n,-1);\n\n    priority_queue<Edge> pq;\n    ds[s]=0;\n    pq.emplace(s,ds[s]);\n\
    \n    while(!pq.empty()){\n      auto p=pq.top();pq.pop();\n      int v=p.to;\n\
    \      if(ds[v]<p.cost) continue;\n      for(auto e:G[v]){\n        if(ds[e.to]>ds[v]+e.cost){\n\
    \          ds[e.to]=ds[v]+e.cost;\n          bs[e.to]=v;\n          pq.emplace(e.to,ds[e.to]);\n\
    \        }\n      }\n    }\n  }\n\n  T operator[](int k){return ds[k];}\n\n  vector<int>\
    \ restore(int to){\n    vector<int> res;\n    if(bs[to]<0) return res;\n    while(~to)\
    \ res.emplace_back(to),to=bs[to];\n    reverse(res.begin(),res.end());\n    return\
    \ res;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct Dijkstra{\n  struct Edge{\n\
    \    int to;\n    T cost;\n    Edge(int to,T cost):to(to),cost(cost){}\n    bool\
    \ operator<(const Edge &o)const{return cost>o.cost;}\n  };\n\n  vector< vector<Edge>\
    \ > G;\n  vector<T> ds;\n  vector<int> bs;\n  Dijkstra(int n):G(n){}\n\n  void\
    \ add_edge(int u,int v,T c){\n    G[u].emplace_back(v,c);\n  }\n\n  void build(int\
    \ s){\n    int n=G.size();\n    ds.assign(n,numeric_limits<T>::max());\n    bs.assign(n,-1);\n\
    \n    priority_queue<Edge> pq;\n    ds[s]=0;\n    pq.emplace(s,ds[s]);\n\n   \
    \ while(!pq.empty()){\n      auto p=pq.top();pq.pop();\n      int v=p.to;\n  \
    \    if(ds[v]<p.cost) continue;\n      for(auto e:G[v]){\n        if(ds[e.to]>ds[v]+e.cost){\n\
    \          ds[e.to]=ds[v]+e.cost;\n          bs[e.to]=v;\n          pq.emplace(e.to,ds[e.to]);\n\
    \        }\n      }\n    }\n  }\n\n  T operator[](int k){return ds[k];}\n\n  vector<int>\
    \ restore(int to){\n    vector<int> res;\n    if(bs[to]<0) return res;\n    while(~to)\
    \ res.emplace_back(to),to=bs[to];\n    reverse(res.begin(),res.end());\n    return\
    \ res;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.cpp
  requiredBy: []
  timestamp: '2020-05-05 14:35:59+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/geometry/2334.test.cpp
  - test/aoj/0423.test.cpp
  - test/yosupo/shortest_path.test.cpp
documentation_of: graph/dijkstra.cpp
layout: document
redirect_from:
- /library/graph/dijkstra.cpp
- /library/graph/dijkstra.cpp.html
title: graph/dijkstra.cpp
---
