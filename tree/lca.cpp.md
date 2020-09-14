---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0391.test.cpp
    title: test/aoj/0391.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_C.lca.test.cpp
    title: test/aoj/GRL_5_C.lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_3_D.cartesiantree.test.cpp
    title: test/aoj/DSL_3_D.cartesiantree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"tree/lca.cpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\nstruct LCA{\n  const int lg = 12;\n  const int\
    \ sz = 1<<lg;\n  const int ms = sz-1;\n  int n;\n  vector<int> P,D,E,A,B,T,ht;\n\
    \  vector<vector<int> > G,dat;\n  LCA(int n):\n    n(n),P(n,-1),D(n),E(n*2,0),A(n*2,-1),B(n*2/lg+1),T(sz,0),G(n){}\n\
    \n  void add_edge(int u,int v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n\
    \  }\n\n  void dfs(int v,int p,int d){\n    int k=0,u;\n    vector<int> iter(n,0);\n\
    \n    using T = tuple<int, int, int>;\n    stack<T> st;\n\n  START:\n    D[v]=k;\n\
    \    A[k]=P[v]=p;\n    E[k++]=d;\n    for(;iter[v]<(int)G[v].size();iter[v]++){\n\
    \      u=G[v][iter[v]];\n      if(u==p) continue;\n      st.emplace(v,p,d);\n\
    \      p=v;v=u;d=d+1;\n      goto START;\n    END:\n      tie(v,p,d)=st.top();st.pop();\n\
    \    }\n\n    A[k]=P[v];\n    E[k++]=d-1;\n\n    if(!st.empty()) goto END;\n \
    \ }\n\n  // if it need leftmost, then add: if(E[i]==E[j]) return i<j?i:j;\n  inline\
    \ int comp(int i,int j){return E[i]<E[j]?i:j;};\n  inline int comp(int i,int j,int\
    \ k){return comp(comp(i,j),k);};\n\n  void build(int r=0){\n    dfs(r,-1,1);\n\
    \n    B[0]=1;\n    for(int i=1;i<n*2;i++) B[i/lg]|=(E[i-1]<E[i])<<(i%lg);\n\n\
    \    for(int b=0;b<sz;b++){\n      int e=0,w=1,&x=T[b];\n      for(int i=0;i<lg;i++){\n\
    \        if((b>>i)&1) e++;\n        else e--;\n        if(e<w) e=w,x=i;\n    \
    \  }\n    }\n\n    int m=(n*2+lg-1)/lg;\n    int h=1;\n    while((1<<h)<m) h++;\n\
    \    dat.assign(h,vector<int>(m,-1));\n    ht.assign(m+1,0);\n    for(int j=2;j<=m;j++)\
    \ ht[j]=ht[j>>1]+1;\n\n    for(int j=0;j<n*2;j++){\n      if(dat[0][j/lg]<0) dat[0][j/lg]=j;\n\
    \      dat[0][j/lg]=comp(dat[0][j/lg],j);\n    }\n\n    for(int i=1,p=1;i<h;i++,p<<=1)\n\
    \      for(int j=0;j<m;j++)\n        dat[i][j]=comp(dat[i-1][j],dat[i-1][min(j+p,m-1)]);\n\
    \  }\n\n  inline int cs(int a,int b){\n    int l=b-a;\n    return comp(dat[ht[l]][a],dat[ht[l]][b-(1<<ht[l])]);\n\
    \  }\n\n  inline int es(int i,int l,int r){\n    int x=r-i*lg+1,y=l-i*lg;\n  \
    \  int b=(((B[i]|(ms<<x))>>y)|(ms<<(lg-y)))&ms;\n    return l+T[b];\n  }\n\n \
    \ inline int ls(int i,int l){\n    int k=l-i*lg;\n    int b=((B[i]>>k)|(ms<<(lg-k)))&ms;\n\
    \    return l+T[b];\n  }\n\n  inline int rs(int j,int r){\n    int k=r-j*lg+1;\n\
    \    int b=(B[j]|(ms<<k))&ms;\n    return j*lg+T[b];\n  }\n\n  inline int rmq(int\
    \ l,int r){\n    int i=l/lg,j=r/lg;\n    if(i==j) return es(i,l,r);\n    if(i+1==j)\
    \ return comp(ls(i,l),rs(j,r));\n    return comp(ls(i,l),cs(i+1,j),rs(j,r));\n\
    \  }\n\n  int lca(int l,int r){\n    if(l==r) return l;\n    if(D[l]>D[r]) swap(l,r);\n\
    \    int x=D[l],y=D[r];\n    int m=rmq(x,y);\n    return m==x?l:A[m];\n  }\n};\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nstruct LCA{\n  const int lg = 12;\n  const int sz = 1<<lg;\n\
    \  const int ms = sz-1;\n  int n;\n  vector<int> P,D,E,A,B,T,ht;\n  vector<vector<int>\
    \ > G,dat;\n  LCA(int n):\n    n(n),P(n,-1),D(n),E(n*2,0),A(n*2,-1),B(n*2/lg+1),T(sz,0),G(n){}\n\
    \n  void add_edge(int u,int v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n\
    \  }\n\n  void dfs(int v,int p,int d){\n    int k=0,u;\n    vector<int> iter(n,0);\n\
    \n    using T = tuple<int, int, int>;\n    stack<T> st;\n\n  START:\n    D[v]=k;\n\
    \    A[k]=P[v]=p;\n    E[k++]=d;\n    for(;iter[v]<(int)G[v].size();iter[v]++){\n\
    \      u=G[v][iter[v]];\n      if(u==p) continue;\n      st.emplace(v,p,d);\n\
    \      p=v;v=u;d=d+1;\n      goto START;\n    END:\n      tie(v,p,d)=st.top();st.pop();\n\
    \    }\n\n    A[k]=P[v];\n    E[k++]=d-1;\n\n    if(!st.empty()) goto END;\n \
    \ }\n\n  // if it need leftmost, then add: if(E[i]==E[j]) return i<j?i:j;\n  inline\
    \ int comp(int i,int j){return E[i]<E[j]?i:j;};\n  inline int comp(int i,int j,int\
    \ k){return comp(comp(i,j),k);};\n\n  void build(int r=0){\n    dfs(r,-1,1);\n\
    \n    B[0]=1;\n    for(int i=1;i<n*2;i++) B[i/lg]|=(E[i-1]<E[i])<<(i%lg);\n\n\
    \    for(int b=0;b<sz;b++){\n      int e=0,w=1,&x=T[b];\n      for(int i=0;i<lg;i++){\n\
    \        if((b>>i)&1) e++;\n        else e--;\n        if(e<w) e=w,x=i;\n    \
    \  }\n    }\n\n    int m=(n*2+lg-1)/lg;\n    int h=1;\n    while((1<<h)<m) h++;\n\
    \    dat.assign(h,vector<int>(m,-1));\n    ht.assign(m+1,0);\n    for(int j=2;j<=m;j++)\
    \ ht[j]=ht[j>>1]+1;\n\n    for(int j=0;j<n*2;j++){\n      if(dat[0][j/lg]<0) dat[0][j/lg]=j;\n\
    \      dat[0][j/lg]=comp(dat[0][j/lg],j);\n    }\n\n    for(int i=1,p=1;i<h;i++,p<<=1)\n\
    \      for(int j=0;j<m;j++)\n        dat[i][j]=comp(dat[i-1][j],dat[i-1][min(j+p,m-1)]);\n\
    \  }\n\n  inline int cs(int a,int b){\n    int l=b-a;\n    return comp(dat[ht[l]][a],dat[ht[l]][b-(1<<ht[l])]);\n\
    \  }\n\n  inline int es(int i,int l,int r){\n    int x=r-i*lg+1,y=l-i*lg;\n  \
    \  int b=(((B[i]|(ms<<x))>>y)|(ms<<(lg-y)))&ms;\n    return l+T[b];\n  }\n\n \
    \ inline int ls(int i,int l){\n    int k=l-i*lg;\n    int b=((B[i]>>k)|(ms<<(lg-k)))&ms;\n\
    \    return l+T[b];\n  }\n\n  inline int rs(int j,int r){\n    int k=r-j*lg+1;\n\
    \    int b=(B[j]|(ms<<k))&ms;\n    return j*lg+T[b];\n  }\n\n  inline int rmq(int\
    \ l,int r){\n    int i=l/lg,j=r/lg;\n    if(i==j) return es(i,l,r);\n    if(i+1==j)\
    \ return comp(ls(i,l),rs(j,r));\n    return comp(ls(i,l),cs(i+1,j),rs(j,r));\n\
    \  }\n\n  int lca(int l,int r){\n    if(l==r) return l;\n    if(D[l]>D[r]) swap(l,r);\n\
    \    int x=D[l],y=D[r];\n    int m=rmq(x,y);\n    return m==x?l:A[m];\n  }\n};\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/lca.cpp
  requiredBy: []
  timestamp: '2019-12-17 21:09:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0391.test.cpp
  - test/aoj/GRL_5_C.lca.test.cpp
  - test/aoj/DSL_3_D.cartesiantree.test.cpp
documentation_of: tree/lca.cpp
layout: document
redirect_from:
- /library/tree/lca.cpp
- /library/tree/lca.cpp.html
title: tree/lca.cpp
---
