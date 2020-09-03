---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/yosupo/vertex_add_path_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"tree/heavylightdecomposition.cpp\"\
    \n\n#line 3 \"tree/heavylightdecomposition.cpp\"\nusing namespace std;\n#endif\n\
    /*\n * @docs docs/heavylightdecomposition.md\n * @see http://beet-aizu.hatenablog.com/entry/2017/12/12/235950\n\
    \ */\n//BEGIN CUT HERE\nclass HLD {\nprivate:\n  void dfs_sz(int v) {\n    for(int\
    \ &u:G[v])\n      if(u==par[v]) swap(u,G[v].back());\n    if(~par[v]) G[v].pop_back();\n\
    \n    for(int &u:G[v]){\n      par[u]=v;\n      dep[u]=dep[v]+1;\n      dfs_sz(u);\n\
    \      sub[v]+=sub[u];\n      if(sub[u]>sub[G[v][0]]) swap(u,G[v][0]);\n    }\n\
    \  }\n\n  void dfs_hld(int v,int c,int &pos) {\n    vid[v]=pos++;\n    inv[vid[v]]=v;\n\
    \    type[v]=c;\n    for(int u:G[v]){\n      if(u==par[v]) continue;\n      head[u]=(u==G[v][0]?head[v]:u);\n\
    \      dfs_hld(u,c,pos);\n    }\n  }\n\npublic:\n  vector< vector<int> > G;\n\
    \  vector<int> vid, head, sub, par, dep, inv, type;\n\n  HLD(int n):\n    G(n),vid(n,-1),head(n),sub(n,1),\n\
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
    signed main(){\n  return 0;\n};\n#endif\n#line 1 \"datastructure/binaryindexedtree.cpp\"\
    \n\n#line 3 \"datastructure/binaryindexedtree.cpp\"\nusing namespace std;\n#endif\n\
    /*\n * @docs docs/binaryindexedtree.md\n */\n//BEGIN CUT HERE\ntemplate<typename\
    \ T>\nstruct BIT{\n  int n;\n  vector<T> bit;\n  // 1-indexed\n  BIT(int n_):n(n_+1),bit(n+1,0){}\n\
    \n  T sum(int i){\n    T s(0);\n    for(int x=i;x>0;x-=(x&-x))\n      s+=bit[x];\n\
    \    return s;\n  }\n\n  void add(int i,T a){\n    if(i==0) return;\n    for(int\
    \ x=i;x<=n;x+=(x&-x))\n      bit[x]+=a;\n  }\n\n  // [l, r)\n  T query(int l,int\
    \ r){\n    return sum(r-1)-sum(l-1);\n  }\n\n  int lower_bound(int w){\n    if(w<=0)\
    \ return 0;\n    int x=0,r=1;\n    while(r<n) r<<=1;\n    for(int k=r;k>0;k>>=1){\n\
    \      if(x+k<=n&&bit[x+k]<w){\n        w-=bit[x+k];\n        x+=k;\n      }\n\
    \    }\n    return x+1;\n  }\n\n  // 0-indexed\n  T sum0(int i){return sum(i+1);}\n\
    \  void add0(int i,T a){add(i+1,a);}\n  T query0(int l,int r){return sum(r)-sum(l);}\n\
    };\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n\
    #line 9 \"test/yosupo/vertex_add_path_sum.test.cpp\"\n#undef call_from_test\n\n\
    signed main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,q;\n  cin>>n>>q;\n\
    \n  vector<int> as(n);\n  for(int i=0;i<n;i++) cin>>as[i];\n\n  HLD G(n);\n  for(int\
    \ i=1;i<n;i++){\n    int u,v;\n    cin>>u>>v;\n    G.add_edge(u,v);\n  }\n  G.build();\n\
    \n  using ll = long long;\n  BIT<ll> bit(n);\n  for(int i=0;i<n;i++)\n    bit.add0(G.vid[i],as[i]);\n\
    \n  for(int i=0;i<q;i++){\n    int t;\n    cin>>t;\n    if(t==0){\n      int p,x;\n\
    \      cin>>p>>x;\n      bit.add0(G.vid[p],x);\n    }\n    if(t==1){\n      int\
    \ u,v;\n      cin>>u>>v;\n      ll res=0;\n      auto f=[&](int l,int r){res+=bit.query0(l,r);};\n\
    \      G.for_each(u,v,f);\n      cout<<res<<\"\\n\";\n    }\n  }\n  cout<<flush;\n\
    \n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../tree/heavylightdecomposition.cpp\"\n#include \"../../datastructure/binaryindexedtree.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,q;\n  cin>>n>>q;\n\n  vector<int> as(n);\n  for(int i=0;i<n;i++) cin>>as[i];\n\
    \n  HLD G(n);\n  for(int i=1;i<n;i++){\n    int u,v;\n    cin>>u>>v;\n    G.add_edge(u,v);\n\
    \  }\n  G.build();\n\n  using ll = long long;\n  BIT<ll> bit(n);\n  for(int i=0;i<n;i++)\n\
    \    bit.add0(G.vid[i],as[i]);\n\n  for(int i=0;i<q;i++){\n    int t;\n    cin>>t;\n\
    \    if(t==0){\n      int p,x;\n      cin>>p>>x;\n      bit.add0(G.vid[p],x);\n\
    \    }\n    if(t==1){\n      int u,v;\n      cin>>u>>v;\n      ll res=0;\n   \
    \   auto f=[&](int l,int r){res+=bit.query0(l,r);};\n      G.for_each(u,v,f);\n\
    \      cout<<res<<\"\\n\";\n    }\n  }\n  cout<<flush;\n\n  return 0;\n}\n"
  dependsOn:
  - tree/heavylightdecomposition.cpp
  - datastructure/binaryindexedtree.cpp
  extendedDependsOn:
  - icon: ':warning:'
    path: tree/heavylightdecomposition.cpp
    title: tree/heavylightdecomposition.cpp
  - icon: ':warning:'
    path: datastructure/binaryindexedtree.cpp
    title: datastructure/binaryindexedtree.cpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: test/yosupo/vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2020-08-20 15:14:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: test/yosupo/vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/vertex_add_path_sum.test.cpp
- /verify/test/yosupo/vertex_add_path_sum.test.cpp.html
title: test/yosupo/vertex_add_path_sum.test.cpp
---
