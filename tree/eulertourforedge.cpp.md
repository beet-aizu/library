---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tree/mo_on_tree.cpp
    title: tree/mo_on_tree.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2270.test.cpp
    title: test/aoj/2270.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_D.test.cpp
    title: test/aoj/GRL_5_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/eulertourforedge.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\nclass EulerTourForEdge{\nprivate:\n\
    \  vector<int> ds,us,dep,btm;\n\n  void dfs(int v,int p,int d){\n    dep[v]=d;\n\
    \    for(int u:G[v]){\n      if(u==p) continue;\n      ds[u]=btm.size();\n   \
    \   btm.emplace_back(u);\n      dfs(u,v,d+1);\n      us[u]=btm.size();\n     \
    \ btm.emplace_back(u);\n    }\n  }\npublic:\n  vector< vector<int> > G;\n\n  EulerTourForEdge(int\
    \ n):\n    ds(n),us(n),dep(n),G(n){}\n\n  void add_edge(int u,int v){\n    G[u].emplace_back(v);\n\
    \    G[v].emplace_back(u);\n  }\n\n  void build(int r=0){\n    btm.clear();\n\
    \    ds[r]=btm.size();\n    btm.emplace_back(r);\n    dfs(r,-1,0);\n    us[r]=btm.size();\n\
    \    btm.emplace_back(r);\n  }\n\n  int child(int u,int v){\n    return dep[u]<dep[v]?v:u;\n\
    \  }\n\n  int bottom(int e){\n    return btm[e];\n  }\n\n  // lca(u, v) must be\
    \ u or v\n  template<typename F>\n  void query(int u,int v,F f){\n    if(dep[u]>dep[v])\
    \ swap(u,v);\n    f(ds[u]+1,ds[v]+1);\n  }\n\n  template<typename T,typename G>\n\
    \  void update(int v,T x,G g){\n    g(ds[v], x);\n    g(us[v],-x);\n  }\n};\n\
    //END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nclass EulerTourForEdge{\nprivate:\n  vector<int> ds,us,dep,btm;\n\
    \n  void dfs(int v,int p,int d){\n    dep[v]=d;\n    for(int u:G[v]){\n      if(u==p)\
    \ continue;\n      ds[u]=btm.size();\n      btm.emplace_back(u);\n      dfs(u,v,d+1);\n\
    \      us[u]=btm.size();\n      btm.emplace_back(u);\n    }\n  }\npublic:\n  vector<\
    \ vector<int> > G;\n\n  EulerTourForEdge(int n):\n    ds(n),us(n),dep(n),G(n){}\n\
    \n  void add_edge(int u,int v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n\
    \  }\n\n  void build(int r=0){\n    btm.clear();\n    ds[r]=btm.size();\n    btm.emplace_back(r);\n\
    \    dfs(r,-1,0);\n    us[r]=btm.size();\n    btm.emplace_back(r);\n  }\n\n  int\
    \ child(int u,int v){\n    return dep[u]<dep[v]?v:u;\n  }\n\n  int bottom(int\
    \ e){\n    return btm[e];\n  }\n\n  // lca(u, v) must be u or v\n  template<typename\
    \ F>\n  void query(int u,int v,F f){\n    if(dep[u]>dep[v]) swap(u,v);\n    f(ds[u]+1,ds[v]+1);\n\
    \  }\n\n  template<typename T,typename G>\n  void update(int v,T x,G g){\n   \
    \ g(ds[v], x);\n    g(us[v],-x);\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/eulertourforedge.cpp
  requiredBy:
  - tree/mo_on_tree.cpp
  timestamp: '2020-10-27 19:32:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2270.test.cpp
  - test/aoj/GRL_5_D.test.cpp
documentation_of: tree/eulertourforedge.cpp
layout: document
redirect_from:
- /library/tree/eulertourforedge.cpp
- /library/tree/eulertourforedge.cpp.html
title: tree/eulertourforedge.cpp
---
