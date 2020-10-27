---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2872.test.cpp
    title: test/aoj/2872.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_B.test.cpp
    title: test/aoj/GRL_1_B.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/bellmanford.cpp\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct BellmanFord{\n\
    \  struct edge{\n    int u,v;\n    T w;\n    edge(int u,int v,T w):u(u),v(v),w(w){}\n\
    \  };\n\n  vector< vector<int> > G;\n  vector<int> used,reach;\n  BellmanFord(int\
    \ n):G(n),used(n,0),reach(n,1){}\n\n  vector<edge> es;\n  void add_edge(int u,int\
    \ v,T c){\n    es.emplace_back(u,v,c);\n    G[u].emplace_back(v);\n  }\n\n  vector<T>\
    \ build(int from,int &neg_loop){\n    const T INF = numeric_limits<T>::max();\n\
    \    int n=G.size();\n    vector<T> ds(n,INF);\n    ds[from]=0;\n    for(int j=0;j<n;j++){\n\
    \      bool update=0;\n      for(auto e:es){\n        if(!reach[e.u] or !reach[e.v]\
    \ or ds[e.u]==INF) continue;\n        if(ds[e.v]>ds[e.u]+e.w){\n          ds[e.v]=ds[e.u]+e.w;\n\
    \          update=1;\n        }\n      }\n      if(!update) break;\n      if(j==n-1){\n\
    \        neg_loop=1;\n        return ds;\n      }\n    }\n    neg_loop=0;\n  \
    \  return ds;\n  }\n\n  void dfs(int v){\n    if(used[v]) return;\n    used[v]=1;\n\
    \    for(int u:G[v]) dfs(u);\n  }\n\n  T shortest_path(int from,int to,int &neg_loop){\n\
    \    int n=G.size();\n    for(int i=0;i<n;i++){\n      fill(used.begin(),used.end(),0);\n\
    \      dfs(i);\n      reach[i]=used[to];\n    }\n    return build(from,neg_loop)[to];\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n\
    }\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename T>\nstruct BellmanFord{\n  struct edge{\n\
    \    int u,v;\n    T w;\n    edge(int u,int v,T w):u(u),v(v),w(w){}\n  };\n\n\
    \  vector< vector<int> > G;\n  vector<int> used,reach;\n  BellmanFord(int n):G(n),used(n,0),reach(n,1){}\n\
    \n  vector<edge> es;\n  void add_edge(int u,int v,T c){\n    es.emplace_back(u,v,c);\n\
    \    G[u].emplace_back(v);\n  }\n\n  vector<T> build(int from,int &neg_loop){\n\
    \    const T INF = numeric_limits<T>::max();\n    int n=G.size();\n    vector<T>\
    \ ds(n,INF);\n    ds[from]=0;\n    for(int j=0;j<n;j++){\n      bool update=0;\n\
    \      for(auto e:es){\n        if(!reach[e.u] or !reach[e.v] or ds[e.u]==INF)\
    \ continue;\n        if(ds[e.v]>ds[e.u]+e.w){\n          ds[e.v]=ds[e.u]+e.w;\n\
    \          update=1;\n        }\n      }\n      if(!update) break;\n      if(j==n-1){\n\
    \        neg_loop=1;\n        return ds;\n      }\n    }\n    neg_loop=0;\n  \
    \  return ds;\n  }\n\n  void dfs(int v){\n    if(used[v]) return;\n    used[v]=1;\n\
    \    for(int u:G[v]) dfs(u);\n  }\n\n  T shortest_path(int from,int to,int &neg_loop){\n\
    \    int n=G.size();\n    for(int i=0;i<n;i++){\n      fill(used.begin(),used.end(),0);\n\
    \      dfs(i);\n      reach[i]=used[to];\n    }\n    return build(from,neg_loop)[to];\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n\
    }\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/bellmanford.cpp
  requiredBy: []
  timestamp: '2020-10-27 15:54:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_B.test.cpp
  - test/aoj/2872.test.cpp
documentation_of: graph/bellmanford.cpp
layout: document
redirect_from:
- /library/graph/bellmanford.cpp
- /library/graph/bellmanford.cpp.html
title: graph/bellmanford.cpp
---
