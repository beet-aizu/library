---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0367.test.cpp
    title: test/aoj/0367.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2450.test.cpp
    title: test/aoj/2450.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2667.test.cpp
    title: test/aoj/2667.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_C.test.cpp
    title: test/aoj/GRL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_path_sum.test.cpp
    title: test/yosupo/vertex_add_path_sum.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"tree/heavylightdecomposition.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\nclass HLD {\nprivate:\n  void\
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
    signed main(){\n  return 0;\n};\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nclass HLD {\nprivate:\n  void dfs_sz(int v) {\n    for(int &u:G[v])\n\
    \      if(u==par[v]) swap(u,G[v].back());\n    if(~par[v]) G[v].pop_back();\n\n\
    \    for(int &u:G[v]){\n      par[u]=v;\n      dep[u]=dep[v]+1;\n      dfs_sz(u);\n\
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
    signed main(){\n  return 0;\n};\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/heavylightdecomposition.cpp
  requiredBy: []
  timestamp: '2020-09-14 21:32:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0367.test.cpp
  - test/aoj/2450.test.cpp
  - test/aoj/2667.test.cpp
  - test/aoj/GRL_5_C.test.cpp
  - test/yosupo/vertex_add_path_sum.test.cpp
documentation_of: ./tree/heavylightdecomposition.cpp
layout: document
title: Heavy Light Decomposition
---

## できること

HL分解では、木（あるいは森 ）上のパスを $O(\log N)$ 個に分割することができます。
分割後のパスに対して操作を行った後にマージし直すことで、操作を高速に行うことができます。

HL分解を使えるかどうかの条件は、載せるデータ構造（セグ木、BIT）等のみに依存します。
つまり、ある単純な（一直線に並んでいるような）要素列に対しての問題が $O(X)$ で解けるなら、
それが木の上のパスになった場合でも $O(X \log N)$ で解くことができます。

## 使い方

-   コンストラクタにグラフのサイズを渡します。
-   `add_edge(u,v)` で `u` と `v` の間に辺を貼ります。
-   `build()` で構築します。

頂点属性のクエリの場合は `for_each()` 、
辺属性のクエリの場合は `for_each_edge()` で処理します。

### 解説記事
[Easiest HLD with subtree queries](https://codeforces.com/blog/entry/53170)
[Heavy-Light Decomposition](https://beet-aizu.hatenablog.com/entry/2017/12/12/235950)
