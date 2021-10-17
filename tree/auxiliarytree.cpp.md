---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/lowestcommonancestor.cpp
    title: tree/lowestcommonancestor.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0439.test.cpp
    title: test/aoj/0439.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/3407.test.cpp
    title: test/yukicoder/3407.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4852.test.cpp
    title: test/yukicoder/4852.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ tree/auxiliarytree.cpp: line 6: unable to process #include in #if / #ifdef /\
    \ #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"lowestcommonancestor.cpp\"\n#undef call_from_test\n\
    \n#endif\n\n//BEGIN CUT HERE\nstruct AuxiliaryTree : LowestCommonAncestor{\n \
    \ using super = LowestCommonAncestor;\n\n  vector<int> idx;\n  vector<vector<int>>\
    \ T;\n  AuxiliaryTree(int n):super(n),idx(n),T(n){}\n\n  void dfs(int v,int p,int\
    \ &pos){\n    idx[v]=pos++;\n    for(int u:G[v])\n      if(u!=p) dfs(u,v,pos);\n\
    \  }\n\n  void build(int r=0){\n    super::build(r);\n    int pos=0;\n    dfs(r,-1,pos);\n\
    \  }\n\n  void add_aux_edge(int u,int v){\n    T[u].emplace_back(v);\n    T[v].emplace_back(u);\n\
    \  }\n\n  using super::lca, super::dep;\n  void query(vector<int> &vs){\n    assert(!vs.empty());\n\
    \    sort(vs.begin(),vs.end(),\n         [&](int a,int b){return idx[a]<idx[b];});\n\
    \    vs.erase(unique(vs.begin(),vs.end()),vs.end());\n\n    int k=vs.size();\n\
    \    stack<int> st;\n    st.emplace(vs[0]);\n    for(int i=0;i+1<k;i++){\n   \
    \   int w=lca(vs[i],vs[i+1]);\n      if(w!=vs[i]){\n        int l=st.top();st.pop();\n\
    \        while(!st.empty() and dep[w]<dep[st.top()]){\n          add_aux_edge(st.top(),l);\n\
    \          l=st.top();st.pop();\n        }\n        if(st.empty() or st.top()!=w){\n\
    \          st.emplace(w);\n          vs.emplace_back(w);\n        }\n        add_aux_edge(w,l);\n\
    \      }\n      st.emplace(vs[i+1]);\n    }\n\n    while(st.size()>1){\n     \
    \ int c=st.top();st.pop();\n      add_aux_edge(st.top(),c);\n    }\n  }\n\n  void\
    \ clear(const vector<int> &ws){\n    for(int w:ws) T[w].clear();\n  }\n};\n//END\
    \ CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - tree/lowestcommonancestor.cpp
  isVerificationFile: false
  path: tree/auxiliarytree.cpp
  requiredBy: []
  timestamp: '2020-10-27 19:32:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/4852.test.cpp
  - test/yukicoder/3407.test.cpp
  - test/aoj/0439.test.cpp
documentation_of: tree/auxiliarytree.cpp
layout: document
title: Auxiliary Tree
---

## できること
与えられた木の頂点の部分集合に関して、その頂点を全て含むような最小の木を構築する

## つかいかた
- `query(ws)`: 部分集合 `ws` の Aux Tree を破壊的に構築する（必要な頂点が `ws` に追加される）
- `clear(ws)`: `ws` から伸びている辺を削除する

## 計算量
部分集合のサイズを$k$として、$O(k \log k)$

Aux Treeの頂点数は $2k$ 以下になる


## 参考リンク
[LCAをベースに構築するAuxiliary Treeのメモ](https://smijake3.hatenablog.com/entry/2019/09/15/200200)
