---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tree/auxiliarytree.cpp
    title: Auxiliary Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0439.test.cpp
    title: test/aoj/0439.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2270.test.cpp
    title: test/aoj/2270.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_C.test.cpp
    title: test/aoj/GRL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca.test.cpp
    title: test/yosupo/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/3407.test.cpp
    title: test/yukicoder/3407.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4852.test.cpp
    title: test/yukicoder/4852.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/lowestcommonancestor.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\nstruct LowestCommonAncestor{\n\
    \  int n,h;\n  vector< vector<int> > G,par;\n  vector<int> dep;\n  LowestCommonAncestor(){}\n\
    \  LowestCommonAncestor(int n):n(n),G(n),dep(n){\n    h=1;\n    while((1<<h)<=n)\
    \ h++;\n    par.assign(h,vector<int>(n,-1));\n  }\n\n  void add_edge(int u,int\
    \ v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n  }\n\n  void dfs(int\
    \ v,int p,int d){\n    par[0][v]=p;\n    dep[v]=d;\n    for(int u:G[v])\n    \
    \  if(u!=p) dfs(u,v,d+1);\n  }\n\n  void build(int r=0){\n    dfs(r,-1,0);\n \
    \   for(int k=0;k+1<h;k++)\n      for(int v=0;v<n;v++)\n        if(~par[k][v])\n\
    \          par[k+1][v]=par[k][par[k][v]];\n  }\n\n  int lca(int u,int v){\n  \
    \  if(dep[u]>dep[v]) swap(u,v);\n    for(int k=0;k<h;k++)\n      if((dep[v]-dep[u])>>k&1)\n\
    \        v=par[k][v];\n\n    if(u==v) return u;\n\n    for(int k=h-1;k>=0;k--)\n\
    \      if(par[k][u]!=par[k][v])\n        u=par[k][u],v=par[k][v];\n\n    return\
    \ par[0][u];\n  }\n\n  int distance(int u,int v){\n    return dep[u]+dep[v]-dep[lca(u,v)]*2;\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n\
    }\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nstruct LowestCommonAncestor{\n  int n,h;\n  vector< vector<int>\
    \ > G,par;\n  vector<int> dep;\n  LowestCommonAncestor(){}\n  LowestCommonAncestor(int\
    \ n):n(n),G(n),dep(n){\n    h=1;\n    while((1<<h)<=n) h++;\n    par.assign(h,vector<int>(n,-1));\n\
    \  }\n\n  void add_edge(int u,int v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n\
    \  }\n\n  void dfs(int v,int p,int d){\n    par[0][v]=p;\n    dep[v]=d;\n    for(int\
    \ u:G[v])\n      if(u!=p) dfs(u,v,d+1);\n  }\n\n  void build(int r=0){\n    dfs(r,-1,0);\n\
    \    for(int k=0;k+1<h;k++)\n      for(int v=0;v<n;v++)\n        if(~par[k][v])\n\
    \          par[k+1][v]=par[k][par[k][v]];\n  }\n\n  int lca(int u,int v){\n  \
    \  if(dep[u]>dep[v]) swap(u,v);\n    for(int k=0;k<h;k++)\n      if((dep[v]-dep[u])>>k&1)\n\
    \        v=par[k][v];\n\n    if(u==v) return u;\n\n    for(int k=h-1;k>=0;k--)\n\
    \      if(par[k][u]!=par[k][v])\n        u=par[k][u],v=par[k][v];\n\n    return\
    \ par[0][u];\n  }\n\n  int distance(int u,int v){\n    return dep[u]+dep[v]-dep[lca(u,v)]*2;\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n\
    }\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/lowestcommonancestor.cpp
  requiredBy:
  - tree/auxiliarytree.cpp
  timestamp: '2019-12-17 21:09:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/3407.test.cpp
  - test/yukicoder/4852.test.cpp
  - test/aoj/GRL_5_C.test.cpp
  - test/aoj/2270.test.cpp
  - test/aoj/0439.test.cpp
  - test/yosupo/lca.test.cpp
documentation_of: tree/lowestcommonancestor.cpp
layout: document
redirect_from:
- /library/tree/lowestcommonancestor.cpp
- /library/tree/lowestcommonancestor.cpp.html
title: tree/lowestcommonancestor.cpp
---
