---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/cartesiantree.cpp
    title: datastructure/cartesiantree.cpp
  - icon: ':heavy_check_mark:'
    path: tree/lca.cpp
    title: tree/lca.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
  bundledCode: "#line 1 \"test/aoj/DSL_3_D.cartesiantree.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#line 2 \"\
    datastructure/cartesiantree.cpp\"\n\n#ifndef call_from_test\n#line 5 \"datastructure/cartesiantree.cpp\"\
    \nusing namespace std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename T>\nvector<int>\
    \ cartesian_tree(const vector<T> &vs){\n  int n=vs.size();\n  vector<int> ps(n,-1),ls(n,-1),rs(n,-1);\n\
    \  int cur=0;\n  for(int i=1;i<n;i++){\n    if(vs[cur]<=vs[i]){\n      rs[cur]=i;\n\
    \      ps[i]=cur;\n      cur=i;\n      continue;\n    }\n    while(~ps[cur] and\
    \ vs[i]<vs[ps[cur]]) cur=ps[cur];\n    ps[i]=ps[cur];\n    if(~ps[i]) rs[ps[i]]=i;\n\
    \    ls[i]=cur;\n    ps[cur]=i;\n    cur=i;\n  }\n  return ps;\n}\n//END CUT HERE\n\
    \n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n#line 1 \"tree/lca.cpp\"\
    \n\n#line 3 \"tree/lca.cpp\"\nusing namespace std;\n#endif\n//BEGIN CUT HERE\n\
    struct LCA{\n  const int lg = 12;\n  const int sz = 1<<lg;\n  const int ms = sz-1;\n\
    \  int n;\n  vector<int> P,D,E,A,B,T,ht;\n  vector<vector<int> > G,dat;\n  LCA(int\
    \ n):\n    n(n),P(n,-1),D(n),E(n*2,0),A(n*2,-1),B(n*2/lg+1),T(sz,0),G(n){}\n\n\
    \  void add_edge(int u,int v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n\
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
    \  return 0;\n}\n#endif\n#line 9 \"test/aoj/DSL_3_D.cartesiantree.test.cpp\"\n\
    #undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,l;\n  cin>>n>>l;\n\n  vector<int> vs(n);\n  for(int i=0;i<n;i++) cin>>vs[i];\n\
    \n  auto ps=cartesian_tree(vs);\n\n  LCA lca(n);\n  int rt;\n  for(int i=0;i<n;i++){\n\
    \    if(~ps[i]) lca.add_edge(i,ps[i]);\n    else rt=i;\n  }\n  lca.build(rt);\n\
    \n  for(int i=0;i+l<=n;i++){\n    if(i) cout<<\" \";\n    cout<<vs[lca.lca(i,i+l-1)];\n\
    \  }\n  cout<<endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../datastructure/cartesiantree.cpp\"\n#include \"../../tree/lca.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,l;\n  cin>>n>>l;\n\n  vector<int> vs(n);\n  for(int i=0;i<n;i++) cin>>vs[i];\n\
    \n  auto ps=cartesian_tree(vs);\n\n  LCA lca(n);\n  int rt;\n  for(int i=0;i<n;i++){\n\
    \    if(~ps[i]) lca.add_edge(i,ps[i]);\n    else rt=i;\n  }\n  lca.build(rt);\n\
    \n  for(int i=0;i+l<=n;i++){\n    if(i) cout<<\" \";\n    cout<<vs[lca.lca(i,i+l-1)];\n\
    \  }\n  cout<<endl;\n  return 0;\n}\n"
  dependsOn:
  - datastructure/cartesiantree.cpp
  - tree/lca.cpp
  isVerificationFile: true
  path: test/aoj/DSL_3_D.cartesiantree.test.cpp
  requiredBy: []
  timestamp: '2020-07-27 11:21:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_3_D.cartesiantree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_3_D.cartesiantree.test.cpp
- /verify/test/aoj/DSL_3_D.cartesiantree.test.cpp.html
title: test/aoj/DSL_3_D.cartesiantree.test.cpp
---
