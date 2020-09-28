---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0377.test.cpp
    title: test/aoj/0377.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0415.test.cpp
    title: test/aoj/0415.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_edge_connected_components.test.cpp
    title: test/yosupo/two_edge_connected_components.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/twoedgeconnectedcomponents.cpp\"\n\n#ifndef call_from_test\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#endif\n//BEGIN CUT HERE\n// work\
    \ with multigraph\nstruct TwoEdgeConnectedComponents{\n  vector<int> ord,low,par,blg,sz;\n\
    \  vector<vector<int>> G,C;\n\n  TwoEdgeConnectedComponents(int n):\n    ord(n,-1),low(n),par(n,-1),blg(n,-1),sz(n,1),G(n){}\n\
    \n  void add_edge(int u,int v){\n    if(u==v) return;\n    G[u].emplace_back(v);\n\
    \    G[v].emplace_back(u);\n  }\n\n  bool is_bridge(int u,int v){\n    if(ord[u]>ord[v])\
    \ swap(u,v);\n    return ord[u]<low[v];\n  }\n\n  void dfs(int v,int &pos){\n\
    \    ord[v]=low[v]=pos++;\n    int dup=0;\n    for(int u:G[v]){\n      if(u==par[v]\
    \ and !dup){\n        dup=1;\n        continue;\n      }\n      if(~ord[u]){\n\
    \        low[v]=min(low[v],ord[u]);\n        continue;\n      }\n      par[u]=v;\n\
    \      dfs(u,pos);\n      sz[v]+=sz[u];\n      low[v]=min(low[v],low[u]);\n  \
    \  }\n  }\n\n  void fill_component(int v){\n    C[blg[v]].emplace_back(v);\n \
    \   for(int u:G[v]){\n      if(~blg[u]||is_bridge(u,v)) continue;\n      blg[u]=blg[v];\n\
    \      fill_component(u);\n    }\n  }\n\n  void add_component(int v,int &k){\n\
    \    if(~blg[v]) return;\n    blg[v]=k++;\n    C.emplace_back();\n    fill_component(v);\n\
    \  }\n\n  int build(){\n    int n=G.size(),pos=0;\n    for(int i=0;i<n;i++)\n\
    \      if(ord[i]<0) dfs(i,pos);\n\n    int k=0;\n    for(int i=0;i<n;i++) add_component(i,k);\n\
    \n    return k;\n  }\n\n  const vector<int>& operator[](int i)const{return C[i];}\n\
    \n  vector<vector<int>> forest(){\n    int n=G.size(),k=C.size();\n    vector<vector<int>>\
    \ T(k);\n    for(int v=0;v<n;v++)\n      for(int u:G[v])\n        if(blg[v]!=blg[u])\n\
    \          T[blg[v]].emplace_back(blg[u]);\n    return T;\n  }\n};\n//END CUT\
    \ HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\n// work with multigraph\nstruct TwoEdgeConnectedComponents{\n\
    \  vector<int> ord,low,par,blg,sz;\n  vector<vector<int>> G,C;\n\n  TwoEdgeConnectedComponents(int\
    \ n):\n    ord(n,-1),low(n),par(n,-1),blg(n,-1),sz(n,1),G(n){}\n\n  void add_edge(int\
    \ u,int v){\n    if(u==v) return;\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n\
    \  }\n\n  bool is_bridge(int u,int v){\n    if(ord[u]>ord[v]) swap(u,v);\n   \
    \ return ord[u]<low[v];\n  }\n\n  void dfs(int v,int &pos){\n    ord[v]=low[v]=pos++;\n\
    \    int dup=0;\n    for(int u:G[v]){\n      if(u==par[v] and !dup){\n       \
    \ dup=1;\n        continue;\n      }\n      if(~ord[u]){\n        low[v]=min(low[v],ord[u]);\n\
    \        continue;\n      }\n      par[u]=v;\n      dfs(u,pos);\n      sz[v]+=sz[u];\n\
    \      low[v]=min(low[v],low[u]);\n    }\n  }\n\n  void fill_component(int v){\n\
    \    C[blg[v]].emplace_back(v);\n    for(int u:G[v]){\n      if(~blg[u]||is_bridge(u,v))\
    \ continue;\n      blg[u]=blg[v];\n      fill_component(u);\n    }\n  }\n\n  void\
    \ add_component(int v,int &k){\n    if(~blg[v]) return;\n    blg[v]=k++;\n   \
    \ C.emplace_back();\n    fill_component(v);\n  }\n\n  int build(){\n    int n=G.size(),pos=0;\n\
    \    for(int i=0;i<n;i++)\n      if(ord[i]<0) dfs(i,pos);\n\n    int k=0;\n  \
    \  for(int i=0;i<n;i++) add_component(i,k);\n\n    return k;\n  }\n\n  const vector<int>&\
    \ operator[](int i)const{return C[i];}\n\n  vector<vector<int>> forest(){\n  \
    \  int n=G.size(),k=C.size();\n    vector<vector<int>> T(k);\n    for(int v=0;v<n;v++)\n\
    \      for(int u:G[v])\n        if(blg[v]!=blg[u])\n          T[blg[v]].emplace_back(blg[u]);\n\
    \    return T;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE\
    \ HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/twoedgeconnectedcomponents.cpp
  requiredBy: []
  timestamp: '2020-03-12 16:29:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0415.test.cpp
  - test/aoj/0377.test.cpp
  - test/yosupo/two_edge_connected_components.test.cpp
documentation_of: graph/twoedgeconnectedcomponents.cpp
layout: document
redirect_from:
- /library/graph/twoedgeconnectedcomponents.cpp
- /library/graph/twoedgeconnectedcomponents.cpp.html
title: graph/twoedgeconnectedcomponents.cpp
---
