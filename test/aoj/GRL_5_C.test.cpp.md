---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    \nusing namespace std;\n#endif\n//BEGIN CUT HERE\nclass HLD{\nprivate:\n  void\
    \ dfs_sz(int v) {\n    auto &es=G[v];\n    if(~par[v]) es.erase(find(es.begin(),es.end(),par[v]));\n\
    \n    for(int &u:es){\n      par[u]=v;\n      dfs_sz(u);\n      sub[v]+=sub[u];\n\
    \      if(sub[u]>sub[es[0]]) swap(u,es[0]);\n    }\n  }\n\n  void dfs_hld(int\
    \ v,int &pos) {\n    vid[v]=pos++;\n    inv[vid[v]]=v;\n    for(int u:G[v]){\n\
    \      if(u==par[v]) continue;\n      nxt[u]=(u==G[v][0]?nxt[v]:u);\n      dfs_hld(u,pos);\n\
    \    }\n  }\n\npublic:\n  vector< vector<int> > G;\n\n  // vid: vertex -> idx\n\
    \  // inv: idx -> vertex\n  vector<int> vid,nxt,sub,par,inv;\n\n  HLD(int n):G(n),vid(n,-1),nxt(n),sub(n,1),par(n,-1),inv(n){}\n\
    \n  void add_edge(int u,int v) {\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n\
    \  }\n\n  void build(int r=0) {\n    int pos=0;\n    dfs_sz(r);\n    nxt[r]=r;\n\
    \    dfs_hld(r,pos);\n  }\n\n  int lca(int u,int v){\n    while(1){\n      if(vid[u]>vid[v])\
    \ swap(u,v);\n      if(nxt[u]==nxt[v]) return u;\n      v=par[nxt[v]];\n    }\n\
    \  }\n\n  template<typename F>\n  void for_each(int u,int v,const F& f) {\n  \
    \  while(1){\n      if(vid[u]>vid[v]) swap(u,v);\n      f(max(vid[nxt[v]],vid[u]),vid[v]+1);\n\
    \      if(nxt[u]!=nxt[v]) v=par[nxt[v]];\n      else break;\n    }\n  }\n\n  template<typename\
    \ F>\n  void for_each_edge(int u,int v,const F& f) {\n    while(1){\n      if(vid[u]>vid[v])\
    \ swap(u,v);\n      if(nxt[u]!=nxt[v]){\n        f(vid[nxt[v]],vid[v]+1);\n  \
    \      v=par[nxt[v]];\n      }else{\n        if(u!=v) f(vid[u]+1,vid[v]+1);\n\
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
  timestamp: '2020-09-15 22:29:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_5_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_C.test.cpp
- /verify/test/aoj/GRL_5_C.test.cpp.html
title: test/aoj/GRL_5_C.test.cpp
---
