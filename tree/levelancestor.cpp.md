---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tree/eulertourforbfs.cpp
    title: tree/eulertourforbfs.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0391.test.cpp
    title: test/aoj/0391.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/3405.test.cpp
    title: test/yukicoder/3405.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/levelancestor.cpp\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\nstruct LevelAncestor{\n  int n,h;\n\
    \  vector<vector<int> > G,par,lad;\n  vector<int> dep,nxt,len,pth,ord,hs;\n  LevelAncestor(){}\n\
    \  LevelAncestor(int n):\n    n(n),G(n),dep(n),nxt(n,-1),len(n),pth(n),ord(n),hs(n+1,0){\n\
    \    h=1;\n    while((1<<h)<=n) h++;\n    par.assign(h,vector<int>(n,-1));\n \
    \   for(int i=2;i<=n;i++) hs[i]=hs[i>>1]+1;\n  }\n\n  void add_edge(int u,int\
    \ v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n  }\n\n  void dfs(int\
    \ v,int p,int d,int f){\n    if(nxt[v]<0){\n      par[0][nxt[v]=v]=p;\n      len[v]=dep[v]=d;\n\
    \      for(int u:G[v]){\n        if(u==p) continue;\n        dfs(u,v,d+1,0);\n\
    \        if(len[v]<len[u]) nxt[v]=u,len[v]=len[u];\n      }\n    }\n    if(!f)\
    \ return;\n    pth[v]=lad.size();\n    lad.emplace_back();\n    for(int k=v;;k=nxt[k]){\n\
    \      lad.back().emplace_back(k);\n      pth[k]=pth[v];\n      if(k==nxt[k])\
    \ break;\n    }\n    for(;;p=v,v=nxt[v]){\n      for(int u:G[v])\n        if(u!=p&&u!=nxt[v])\
    \ dfs(u,v,d+1,1);\n      if(v==nxt[v]) break;\n    }\n  }\n\n  void build(int\
    \ r=0){\n    dfs(r,-1,0,1);\n    for(int k=0;k+1<h;k++){\n      for(int v=0;v<n;v++){\n\
    \        if(par[k][v]<0) par[k+1][v]=-1;\n        else par[k+1][v]=par[k][par[k][v]];\n\
    \      }\n    }\n    for(int i=0;i<(int)lad.size();i++){\n      int v=lad[i][0],p=par[0][v];\n\
    \      if(~p){\n        int k=pth[p],l=min(ord[p]+1,(int)lad[i].size());\n   \
    \     lad[i].resize(l+lad[i].size());\n        for(int j=0,m=lad[i].size();j+l<m;j++)\n\
    \          lad[i][m-(j+1)]=lad[i][m-(j+l+1)];\n        for(int j=0;j<l;j++)\n\
    \          lad[i][j]=lad[k][ord[p]-l+j+1];\n      }\n      for(int j=0;j<(int)lad[i].size();j++)\n\
    \        if(pth[lad[i][j]]==i) ord[lad[i][j]]=j;\n    }\n  }\n\n  int lca(int\
    \ u,int v){\n    if(dep[u]>dep[v]) swap(u,v);\n    for(int k=0;k<h;k++){\n   \
    \   if((dep[v]-dep[u])>>k&1){\n        v=par[k][v];\n      }\n    }\n    if(u==v)\
    \ return u;\n    for(int k=h-1;k>=0;k--){\n      if(par[k][u]!=par[k][v]){\n \
    \       u=par[k][u];\n        v=par[k][v];\n      }\n    }\n    return par[0][u];\n\
    \  }\n\n  int up(int v,int d){\n    if(d==0) return v;\n    v=par[hs[d]][v];\n\
    \    d-=1LL<<hs[d];\n    return lad[pth[v]][ord[v]-d];\n  }\n\n  int distance(int\
    \ u,int v){\n    return dep[u]+dep[v]-dep[lca(u,v)]*2;\n  }\n};\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nstruct LevelAncestor{\n  int n,h;\n  vector<vector<int> > G,par,lad;\n\
    \  vector<int> dep,nxt,len,pth,ord,hs;\n  LevelAncestor(){}\n  LevelAncestor(int\
    \ n):\n    n(n),G(n),dep(n),nxt(n,-1),len(n),pth(n),ord(n),hs(n+1,0){\n    h=1;\n\
    \    while((1<<h)<=n) h++;\n    par.assign(h,vector<int>(n,-1));\n    for(int\
    \ i=2;i<=n;i++) hs[i]=hs[i>>1]+1;\n  }\n\n  void add_edge(int u,int v){\n    G[u].emplace_back(v);\n\
    \    G[v].emplace_back(u);\n  }\n\n  void dfs(int v,int p,int d,int f){\n    if(nxt[v]<0){\n\
    \      par[0][nxt[v]=v]=p;\n      len[v]=dep[v]=d;\n      for(int u:G[v]){\n \
    \       if(u==p) continue;\n        dfs(u,v,d+1,0);\n        if(len[v]<len[u])\
    \ nxt[v]=u,len[v]=len[u];\n      }\n    }\n    if(!f) return;\n    pth[v]=lad.size();\n\
    \    lad.emplace_back();\n    for(int k=v;;k=nxt[k]){\n      lad.back().emplace_back(k);\n\
    \      pth[k]=pth[v];\n      if(k==nxt[k]) break;\n    }\n    for(;;p=v,v=nxt[v]){\n\
    \      for(int u:G[v])\n        if(u!=p&&u!=nxt[v]) dfs(u,v,d+1,1);\n      if(v==nxt[v])\
    \ break;\n    }\n  }\n\n  void build(int r=0){\n    dfs(r,-1,0,1);\n    for(int\
    \ k=0;k+1<h;k++){\n      for(int v=0;v<n;v++){\n        if(par[k][v]<0) par[k+1][v]=-1;\n\
    \        else par[k+1][v]=par[k][par[k][v]];\n      }\n    }\n    for(int i=0;i<(int)lad.size();i++){\n\
    \      int v=lad[i][0],p=par[0][v];\n      if(~p){\n        int k=pth[p],l=min(ord[p]+1,(int)lad[i].size());\n\
    \        lad[i].resize(l+lad[i].size());\n        for(int j=0,m=lad[i].size();j+l<m;j++)\n\
    \          lad[i][m-(j+1)]=lad[i][m-(j+l+1)];\n        for(int j=0;j<l;j++)\n\
    \          lad[i][j]=lad[k][ord[p]-l+j+1];\n      }\n      for(int j=0;j<(int)lad[i].size();j++)\n\
    \        if(pth[lad[i][j]]==i) ord[lad[i][j]]=j;\n    }\n  }\n\n  int lca(int\
    \ u,int v){\n    if(dep[u]>dep[v]) swap(u,v);\n    for(int k=0;k<h;k++){\n   \
    \   if((dep[v]-dep[u])>>k&1){\n        v=par[k][v];\n      }\n    }\n    if(u==v)\
    \ return u;\n    for(int k=h-1;k>=0;k--){\n      if(par[k][u]!=par[k][v]){\n \
    \       u=par[k][u];\n        v=par[k][v];\n      }\n    }\n    return par[0][u];\n\
    \  }\n\n  int up(int v,int d){\n    if(d==0) return v;\n    v=par[hs[d]][v];\n\
    \    d-=1LL<<hs[d];\n    return lad[pth[v]][ord[v]-d];\n  }\n\n  int distance(int\
    \ u,int v){\n    return dep[u]+dep[v]-dep[lca(u,v)]*2;\n  }\n};\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/levelancestor.cpp
  requiredBy:
  - tree/eulertourforbfs.cpp
  timestamp: '2019-12-26 22:42:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0391.test.cpp
  - test/yukicoder/3405.test.cpp
documentation_of: tree/levelancestor.cpp
layout: document
redirect_from:
- /library/tree/levelancestor.cpp
- /library/tree/levelancestor.cpp.html
title: tree/levelancestor.cpp
---
