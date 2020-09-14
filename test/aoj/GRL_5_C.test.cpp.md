---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/heavylightdecomposition.cpp
    title: Heavy Light Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
  bundledCode: "#line 1 \"test/aoj/GRL_5_C.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #line 1 \"tree/heavylightdecomposition.cpp\"\n\n#line 3 \"tree/heavylightdecomposition.cpp\"\
    \nusing namespace std;\n#endif\n//BEGIN CUT HERE\nclass HLD {\nprivate:\n  void\
    \ dfs_sz(int v) {\n    for(int &u:G[v])\n      if(u==par[v]) swap(u,G[v].back());\n\
    \    if(~par[v]) G[v].pop_back();\n\n    for(int &u:G[v]){\n      par[u]=v;\n\
    \      dep[u]=dep[v]+1;\n      dfs_sz(u);\n      sub[v]+=sub[u];\n      if(sub[u]>sub[G[v][0]])\
    \ swap(u,G[v][0]);\n    }\n  }\n\n  void dfs_hld(int v,int c,int &pos) {\n   \
    \ vid[v]=pos++;\n    inv[vid[v]]=v;\n    type[v]=c;\n    for(int u:G[v]){\n  \
    \    if(u==par[v]) continue;\n      head[u]=(u==G[v][0]?head[v]:u);\n      dfs_hld(u,c,pos);\n\
    \    }\n  }\n\npublic:\n  vector< vector<int> > G;\n  vector<int> vid, head, sub,\
    \ par, dep, inv, type;\n\n  HLD(int n):\n    G(n),vid(n,-1),head(n),sub(n,1),\n\
    \    par(n,-1),dep(n,0),inv(n),type(n){}\n\n  void add_edge(int u,int v) {\n \
    \   G[u].emplace_back(v);\n    G[v].emplace_back(u);\n  }\n\n  void build(vector<int>\
    \ rs={0}) {\n    int c=0,pos=0;\n    for(int r:rs){\n      dfs_sz(r);\n      head[r]=r;\n\
    \      dfs_hld(r,c++,pos);\n    }\n  }\n\n  int lca(int u,int v){\n    while(1){\n\
    \      if(vid[u]>vid[v]) swap(u,v);\n      if(head[u]==head[v]) return u;\n  \
    \    v=par[head[v]];\n    }\n  }\n\n  int distance(int u,int v){\n    return dep[u]+dep[v]-2*dep[lca(u,v)];\n\
    \  }\n\n  // for_each(vertex)\n  // [l, r) <- attention!!\n  template<typename\
    \ F>\n  void for_each(int u, int v, const F& f) {\n    while(1){\n      if(vid[u]>vid[v])\
    \ swap(u,v);\n      f(max(vid[head[v]],vid[u]),vid[v]+1);\n      if(head[u]!=head[v])\
    \ v=par[head[v]];\n      else break;\n    }\n  }\n\n  template<typename T,typename\
    \ Q,typename F>\n  T for_each(int u,int v,T ti,const Q &q,const F &f){\n    T\
    \ l=ti,r=ti;\n    while(1){\n      if(vid[u]>vid[v]){\n        swap(u,v);\n  \
    \      swap(l,r);\n      }\n      l=f(l,q(max(vid[head[v]],vid[u]),vid[v]+1));\n\
    \      if(head[u]!=head[v]) v=par[head[v]];\n      else break;\n    }\n    return\
    \ f(l,r);\n  }\n\n  // for_each(edge)\n  // [l, r) <- attention!!\n  template<typename\
    \ F>\n  void for_each_edge(int u, int v,const F& f) {\n    while(1){\n      if(vid[u]>vid[v])\
    \ swap(u,v);\n      if(head[u]!=head[v]){\n        f(vid[head[v]],vid[v]+1);\n\
    \        v=par[head[v]];\n      }else{\n        if(u!=v) f(vid[u]+1,vid[v]+1);\n\
    \        break;\n      }\n    }\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    signed main(){\n  return 0;\n};\n#endif\n#line 8 \"test/aoj/GRL_5_C.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n;\n  cin>>n;\n  HLD lca(n);\n  for(int i=0;i<n;i++){\n    int k;\n  \
    \  cin>>k;\n    for(int j=0;j<k;j++){\n      int c;\n      cin>>c;\n      lca.add_edge(i,c);\n\
    \    }\n  }\n  lca.build();\n\n  int q;\n  cin>>q;\n  while(q--){\n    int u,v;\n\
    \    cin>>u>>v;\n    cout<<lca.lca(u,v)<<\"\\n\";\n  }\n  cout<<flush;\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../tree/heavylightdecomposition.cpp\"\n#undef call_from_test\n\n\
    signed main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n;\n  cin>>n;\n\
    \  HLD lca(n);\n  for(int i=0;i<n;i++){\n    int k;\n    cin>>k;\n    for(int\
    \ j=0;j<k;j++){\n      int c;\n      cin>>c;\n      lca.add_edge(i,c);\n    }\n\
    \  }\n  lca.build();\n\n  int q;\n  cin>>q;\n  while(q--){\n    int u,v;\n   \
    \ cin>>u>>v;\n    cout<<lca.lca(u,v)<<\"\\n\";\n  }\n  cout<<flush;\n  return\
    \ 0;\n}\n"
  dependsOn:
  - tree/heavylightdecomposition.cpp
  isVerificationFile: true
  path: test/aoj/GRL_5_C.test.cpp
  requiredBy: []
  timestamp: '2020-09-14 21:32:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_5_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_C.test.cpp
- /verify/test/aoj/GRL_5_C.test.cpp.html
title: test/aoj/GRL_5_C.test.cpp
---
