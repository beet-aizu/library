---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1595.test.cpp
    title: test/aoj/1595.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3148.test.cpp
    title: test/aoj/3148.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2085.test.cpp
    title: test/yukicoder/2085.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/rerooting.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename T, typename Edge>\n\
    struct ReRooting{\n  struct Node{\n    int to,rev;\n    Edge data;\n    Node(int\
    \ to,Edge data):to(to),data(data){}\n    bool operator<(const Node &v)const{return\
    \ to<v.to;};\n  };\n\n  using Fold = function<T(T, T)>;\n  using Lift = function<T(T,\
    \ Edge)>;\n\n  vector< vector<Node> > G;\n  vector< vector<T> > ld,rd;\n  vector<int>\
    \ lp,rp;\n\n  const Fold fold;\n  const Lift lift;\n  const T id;\n\n  ReRooting(int\
    \ n,const Fold fold,const Lift lift,const T id):\n    G(n),ld(n),rd(n),lp(n),rp(n),fold(fold),lift(lift),id(id){}\n\
    \n  void add_edge(int u,int v,Edge d,Edge e){\n    G[u].emplace_back(v,d);\n \
    \   G[v].emplace_back(u,e);\n  }\n\n  void add_edge(int u,int v,Edge d){add_edge(u,v,d,d);}\n\
    \n  // k: idx for edge (not vertex)\n  T dfs(int v,int k){\n    while(lp[v]!=k\
    \ and lp[v]<(int)G[v].size()){\n      auto &e=G[v][lp[v]];\n      ld[v][lp[v]+1]=fold(ld[v][lp[v]],lift(dfs(e.to,e.rev),e.data));\n\
    \      lp[v]++;\n    }\n    while(rp[v]!=k and rp[v]>=0){\n      auto &e=G[v][rp[v]];\n\
    \      rd[v][rp[v]]=fold(rd[v][rp[v]+1],lift(dfs(e.to,e.rev),e.data));\n     \
    \ rp[v]--;\n    }\n    if(k<0) return rd[v][0];\n    return fold(ld[v][k],rd[v][k+1]);\n\
    \  }\n\n  int search(vector<Node> &vs,int idx){\n    return lower_bound(vs.begin(),vs.end(),Node(idx,vs[0].data))-vs.begin();\n\
    \  }\n\n  vector<T> build(){\n    int n=G.size();\n    for(int i=0;i<n;i++){\n\
    \      sort(G[i].begin(),G[i].end());\n      ld[i].assign((int)G[i].size()+1,id);\n\
    \      rd[i].assign((int)G[i].size()+1,id);\n      lp[i]=0;\n      rp[i]=(int)G[i].size()-1;\n\
    \    }\n\n    for(int i=0;i<n;i++)\n      for(Node &t:G[i])\n        t.rev=search(G[t.to],i);\n\
    \n    vector<T> res;\n    for(int i=0;i<n;i++)\n      res.emplace_back(dfs(i,-1));\n\
    \n    return res;\n  }\n\n  // p: idx for vertex\n  T subtree(int v,int p){\n\
    \    int k=search(G[p],v);\n    assert(k<(int)G[p].size() and G[p][k].to==v);\n\
    \    return lift(dfs(v,G[p][k].rev),G[p][k].data);\n  }\n};\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n\n//BEGIN CUT HERE\ntemplate<typename T, typename Edge>\nstruct ReRooting{\n\
    \  struct Node{\n    int to,rev;\n    Edge data;\n    Node(int to,Edge data):to(to),data(data){}\n\
    \    bool operator<(const Node &v)const{return to<v.to;};\n  };\n\n  using Fold\
    \ = function<T(T, T)>;\n  using Lift = function<T(T, Edge)>;\n\n  vector< vector<Node>\
    \ > G;\n  vector< vector<T> > ld,rd;\n  vector<int> lp,rp;\n\n  const Fold fold;\n\
    \  const Lift lift;\n  const T id;\n\n  ReRooting(int n,const Fold fold,const\
    \ Lift lift,const T id):\n    G(n),ld(n),rd(n),lp(n),rp(n),fold(fold),lift(lift),id(id){}\n\
    \n  void add_edge(int u,int v,Edge d,Edge e){\n    G[u].emplace_back(v,d);\n \
    \   G[v].emplace_back(u,e);\n  }\n\n  void add_edge(int u,int v,Edge d){add_edge(u,v,d,d);}\n\
    \n  // k: idx for edge (not vertex)\n  T dfs(int v,int k){\n    while(lp[v]!=k\
    \ and lp[v]<(int)G[v].size()){\n      auto &e=G[v][lp[v]];\n      ld[v][lp[v]+1]=fold(ld[v][lp[v]],lift(dfs(e.to,e.rev),e.data));\n\
    \      lp[v]++;\n    }\n    while(rp[v]!=k and rp[v]>=0){\n      auto &e=G[v][rp[v]];\n\
    \      rd[v][rp[v]]=fold(rd[v][rp[v]+1],lift(dfs(e.to,e.rev),e.data));\n     \
    \ rp[v]--;\n    }\n    if(k<0) return rd[v][0];\n    return fold(ld[v][k],rd[v][k+1]);\n\
    \  }\n\n  int search(vector<Node> &vs,int idx){\n    return lower_bound(vs.begin(),vs.end(),Node(idx,vs[0].data))-vs.begin();\n\
    \  }\n\n  vector<T> build(){\n    int n=G.size();\n    for(int i=0;i<n;i++){\n\
    \      sort(G[i].begin(),G[i].end());\n      ld[i].assign((int)G[i].size()+1,id);\n\
    \      rd[i].assign((int)G[i].size()+1,id);\n      lp[i]=0;\n      rp[i]=(int)G[i].size()-1;\n\
    \    }\n\n    for(int i=0;i<n;i++)\n      for(Node &t:G[i])\n        t.rev=search(G[t.to],i);\n\
    \n    vector<T> res;\n    for(int i=0;i<n;i++)\n      res.emplace_back(dfs(i,-1));\n\
    \n    return res;\n  }\n\n  // p: idx for vertex\n  T subtree(int v,int p){\n\
    \    int k=search(G[p],v);\n    assert(k<(int)G[p].size() and G[p][k].to==v);\n\
    \    return lift(dfs(v,G[p][k].rev),G[p][k].data);\n  }\n};\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/rerooting.cpp
  requiredBy: []
  timestamp: '2020-10-27 16:41:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3148.test.cpp
  - test/aoj/1595.test.cpp
  - test/yukicoder/2085.test.cpp
documentation_of: tree/rerooting.cpp
layout: document
title: ReRooting
---

## できること
全ての頂点について、その頂点を根としたときの木DPの結果を求める

ある頂点を根としたときの部分木の結果を求めることもできる [問題](https://atcoder.jp/contests/tenka1-2015-quala/tasks/tenka1_2015_qualA_d) [提出例](https://atcoder.jp/contests/tenka1-2015-quala/submissions/11218391)

## データの持ち方
- `T`: 結果
- `Edge`: 辺の情報
- `Node`: 逆辺のindexなどを管理する

## つかいかた
以下のラムダ式を実装する
- `fold(x, y)`: 結果 `x` と結果 `y` をマージ
- `lift(x, e)`: 結果 `x` を辺 `e` を使って上に持ち上げる

## 計算量
頂点数を $N$ として $O(N \log N)$

「ある頂点を根としたときの部分木の結果」が必要なければ $O(N)$ にもできる

## 参考リンク
[†全方位木DP†について](https://ei1333.hateblo.jp/entry/2017/04/10/224413)

[もうひとつの全方位木DP](https://ei1333.hateblo.jp/entry/2018/12/21/004022)
