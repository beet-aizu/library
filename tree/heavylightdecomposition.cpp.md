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
    title: Path & Subtree Queries
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_path_sum.test.cpp
    title: test/yosupo/vertex_add_path_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/heavylightdecomposition.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\nclass HLD{\nprivate:\n  void dfs_sz(int\
    \ v) {\n    auto &es=G[v];\n    if(~par[v]) es.erase(find(es.begin(),es.end(),par[v]));\n\
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
    signed main(){\n  return 0;\n};\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
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
    signed main(){\n  return 0;\n};\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/heavylightdecomposition.cpp
  requiredBy: []
  timestamp: '2020-09-15 22:29:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/vertex_add_path_sum.test.cpp
  - test/aoj/0367.test.cpp
  - test/aoj/2667.test.cpp
  - test/aoj/2450.test.cpp
documentation_of: tree/heavylightdecomposition.cpp
layout: document
title: Heavy Light Decomposition
---

## できること

HL分解では、木（あるいは森 ）上のパスを $O(\log N)$ 個に分割することができます。
分割後のパスに対して操作を行った後にマージし直すことで、操作を高速に行うことができます。

HL分解を使えるかどうかの条件は、載せるデータ構造（セグ木、BIT）等のみに依存します。
つまり、ある単純な（一直線に並んでいるような）要素列に対しての問題が $O(X)$ で解けるなら、
それが木の上のパスになった場合でも $O(X \log N)$ で解くことができます。

## つかいかた
頂点属性のクエリの場合は `for_each()` 、辺属性のクエリの場合は `for_each_edge()` で処理します

演算が可換でない場合は `w = lca(u, v)` として、`for_each(w, u)` と `for_each_edge(w, v)` の結果を合成すればよいです


### 解説記事
[Easiest HLD with subtree queries](https://codeforces.com/blog/entry/53170)

[Heavy-Light Decomposition](https://beet-aizu.hatenablog.com/entry/2017/12/12/235950) (実装が古い)
