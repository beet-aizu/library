---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/binaryindexedtree.cpp
    title: Binary Indexed Tree
  - icon: ':heavy_check_mark:'
    path: tree/heavylightdecomposition.cpp
    title: Heavy Light Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/yosupo/vertex_add_path_sum.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/vertex_add_path_sum\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"tree/heavylightdecomposition.cpp\"\
    \n\n#line 3 \"tree/heavylightdecomposition.cpp\"\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nclass HLD{\nprivate:\n  void dfs_sz(int v) {\n    auto &es=G[v];\n\
    \    if(~par[v]) es.erase(find(es.begin(),es.end(),par[v]));\n\n    for(int &u:es){\n\
    \      par[u]=v;\n      dfs_sz(u);\n      sub[v]+=sub[u];\n      if(sub[u]>sub[es[0]])\
    \ swap(u,es[0]);\n    }\n  }\n\n  void dfs_hld(int v,int &pos) {\n    vid[v]=pos++;\n\
    \    inv[vid[v]]=v;\n    for(int u:G[v]){\n      if(u==par[v]) continue;\n   \
    \   nxt[u]=(u==G[v][0]?nxt[v]:u);\n      dfs_hld(u,pos);\n    }\n  }\n\npublic:\n\
    \  vector< vector<int> > G;\n\n  // vid: vertex -> idx\n  // inv: idx -> vertex\n\
    \  vector<int> vid,nxt,sub,par,inv;\n\n  HLD(int n):G(n),vid(n,-1),nxt(n),sub(n,1),par(n,-1),inv(n){}\n\
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
    signed main(){\n  return 0;\n};\n#endif\n#line 1 \"datastructure/binaryindexedtree.cpp\"\
    \n\n#line 3 \"datastructure/binaryindexedtree.cpp\"\nusing namespace std;\n#endif\n\
    \n//BEGIN CUT HERE\ntemplate<typename T>\nclass BIT{\nprivate:\n  // \\sum_{j\
    \ < i}  v[j]\n  T sum(int i){\n    T s(0);\n    for(int x=i;x>0;x-=(x&-x))\n \
    \     s+=bit[x];\n    return s;\n  }\npublic:\n  int n;\n  vector<T> bit;\n  BIT(int\
    \ n_):n(n_+1),bit(n+1,0){}\n\n  // v[i] += a\n  void add(int i,T a){\n    for(int\
    \ x=++i;x<=n;x+=(x&-x))\n      bit[x]+=a;\n  }\n  // \\sum_{l <= i < r} v[i]\n\
    \  T query(int l,int r){return sum(r)-sum(l);}\n\n  // min({x | sum(x) >= w})\n\
    \  int lower_bound(const T w){\n    if(w<=0) return 0;\n    T r=w;\n    int x=0,p=1;\n\
    \    while(p<n) p<<=1;\n    for(int k=p;k>0;k>>=1){\n      if(x+k<=n and bit[x+k]<r){\n\
    \        r-=bit[x+k];\n        x+=k;\n      }\n    }\n    x++;\n    assert(sum(x-1)<w\
    \ and sum(x)>=w);\n    return x;\n  }\n\n  // min({x | sum(x) > w})\n  int upper_bound(T\
    \ w){return lower_bound(w+1);}\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n#line 9 \"test/yosupo/vertex_add_path_sum.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,q;\n  cin>>n>>q;\n\n  vector<int> as(n);\n  for(int i=0;i<n;i++) cin>>as[i];\n\
    \n  HLD G(n);\n  for(int i=1;i<n;i++){\n    int u,v;\n    cin>>u>>v;\n    G.add_edge(u,v);\n\
    \  }\n  G.build();\n\n  using ll = long long;\n  BIT<ll> bit(n);\n  for(int i=0;i<n;i++)\n\
    \    bit.add(G.vid[i],as[i]);\n\n  for(int i=0;i<q;i++){\n    int t;\n    cin>>t;\n\
    \    if(t==0){\n      int p,x;\n      cin>>p>>x;\n      bit.add(G.vid[p],x);\n\
    \    }\n    if(t==1){\n      int u,v;\n      cin>>u>>v;\n      ll res=0;\n   \
    \   auto f=[&](int l,int r){res+=bit.query(l,r);};\n      G.for_each(u,v,f);\n\
    \      cout<<res<<'\\n';\n    }\n  }\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/vertex_add_path_sum\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../tree/heavylightdecomposition.cpp\"\n#include \"../../datastructure/binaryindexedtree.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,q;\n  cin>>n>>q;\n\n  vector<int> as(n);\n  for(int i=0;i<n;i++) cin>>as[i];\n\
    \n  HLD G(n);\n  for(int i=1;i<n;i++){\n    int u,v;\n    cin>>u>>v;\n    G.add_edge(u,v);\n\
    \  }\n  G.build();\n\n  using ll = long long;\n  BIT<ll> bit(n);\n  for(int i=0;i<n;i++)\n\
    \    bit.add(G.vid[i],as[i]);\n\n  for(int i=0;i<q;i++){\n    int t;\n    cin>>t;\n\
    \    if(t==0){\n      int p,x;\n      cin>>p>>x;\n      bit.add(G.vid[p],x);\n\
    \    }\n    if(t==1){\n      int u,v;\n      cin>>u>>v;\n      ll res=0;\n   \
    \   auto f=[&](int l,int r){res+=bit.query(l,r);};\n      G.for_each(u,v,f);\n\
    \      cout<<res<<'\\n';\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - tree/heavylightdecomposition.cpp
  - datastructure/binaryindexedtree.cpp
  isVerificationFile: true
  path: test/yosupo/vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 12:55:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/vertex_add_path_sum.test.cpp
- /verify/test/yosupo/vertex_add_path_sum.test.cpp.html
title: test/yosupo/vertex_add_path_sum.test.cpp
---
