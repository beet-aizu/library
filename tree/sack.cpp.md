---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2995.test.cpp
    title: test/aoj/2995.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/sack.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n\n//BEGIN CUT HERE\nstruct Sack{\n  using F = function<void(int)>;\n\
    \n  vector<int> sub,hvy,big;\n  vector< vector<int> > G,Q;\n  F expand,shrink,query;\n\
    \n  Sack(int n,F expand,F shrink,F query):\n    sub(n,1),hvy(n,-1),big(n,0),G(n),Q(n),\n\
    \    expand(expand),shrink(shrink),query(query){}\n\n  void add_edge(int u,int\
    \ v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n  }\n\n  void add_query(int\
    \ v,int k){\n    Q[v].emplace_back(k);\n  }\n\n  void add(int v,int p,int x){\n\
    \    if(x==1) expand(v);\n    else shrink(v);\n    for(int u:G[v])\n      if(u!=p\
    \ and !big[u]) add(u,v,x);\n  }\n\n  void dfs(int v=0,int p=-1,bool k=0){\n  \
    \  for(int u:G[v])\n      if(u!=p and u!=hvy[v]) dfs(u,v,0);\n    if(~hvy[v]){\n\
    \      dfs(hvy[v],v,1);\n      big[hvy[v]]=1;\n    }\n    add(v,p,1);\n    for(int\
    \ k:Q[v]) query(k);\n    if(~hvy[v]) big[hvy[v]]=0;\n    if(!k) add(v,p,0);\n\
    \  }\n\n  void build(int v=0,int p=-1){\n    for(int u:G[v]){\n      if(u==p)\
    \ continue;\n      build(u,v);\n      if(hvy[v]<0 or sub[hvy[v]]<sub[u]) hvy[v]=u;\n\
    \      sub[v]+=sub[u];\n    }\n    if(p==-1) dfs(v,p);\n  }\n};\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n\n//BEGIN CUT HERE\nstruct Sack{\n  using F = function<void(int)>;\n\n\
    \  vector<int> sub,hvy,big;\n  vector< vector<int> > G,Q;\n  F expand,shrink,query;\n\
    \n  Sack(int n,F expand,F shrink,F query):\n    sub(n,1),hvy(n,-1),big(n,0),G(n),Q(n),\n\
    \    expand(expand),shrink(shrink),query(query){}\n\n  void add_edge(int u,int\
    \ v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n  }\n\n  void add_query(int\
    \ v,int k){\n    Q[v].emplace_back(k);\n  }\n\n  void add(int v,int p,int x){\n\
    \    if(x==1) expand(v);\n    else shrink(v);\n    for(int u:G[v])\n      if(u!=p\
    \ and !big[u]) add(u,v,x);\n  }\n\n  void dfs(int v=0,int p=-1,bool k=0){\n  \
    \  for(int u:G[v])\n      if(u!=p and u!=hvy[v]) dfs(u,v,0);\n    if(~hvy[v]){\n\
    \      dfs(hvy[v],v,1);\n      big[hvy[v]]=1;\n    }\n    add(v,p,1);\n    for(int\
    \ k:Q[v]) query(k);\n    if(~hvy[v]) big[hvy[v]]=0;\n    if(!k) add(v,p,0);\n\
    \  }\n\n  void build(int v=0,int p=-1){\n    for(int u:G[v]){\n      if(u==p)\
    \ continue;\n      build(u,v);\n      if(hvy[v]<0 or sub[hvy[v]]<sub[u]) hvy[v]=u;\n\
    \      sub[v]+=sub[u];\n    }\n    if(p==-1) dfs(v,p);\n  }\n};\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/sack.cpp
  requiredBy: []
  timestamp: '2020-10-14 14:10:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2995.test.cpp
documentation_of: tree/sack.cpp
layout: document
title: Sack (dsu on tree)
---

## できること
部分木に対するクエリを処理できる

unordered 系を使ったマージテクより定数倍が軽いことが多い

## つかいかた
以下のラムダ式を実装する
- `expand(v)` : `v` を追加したときの処理
- `shrink(v)` : `v` を削除したときの処理
- `query(k)` : `k` 番目のクエリに対する処理

## 計算量
頂点数を $N$ として、`expand`, `shrink` が $O(N \log N)$ 回呼び出される

## 注意
- `shrink(v)` を呼ぶときは全体が初期化されるので、 `expand(v)` で変更した値を全て初期値にしてもよい（直前の操作のロールバックができる必要はない）
- 頂点 `v` の追加削除の際に複数の処理を行う必要がある場合は、`v` の子としてダミーの頂点を追加するとよい


## 参考リンク
[[Tutorial] Sack (dsu on tree)](https://codeforces.com/blog/entry/44351)
