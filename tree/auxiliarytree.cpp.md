---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/eulertourforvertex.cpp
    title: tree/eulertourforvertex.cpp
  - icon: ':heavy_check_mark:'
    path: tree/lowestcommonancestor.cpp
    title: tree/lowestcommonancestor.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/3407.test.cpp
    title: test/yukicoder/3407.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4852.test.cpp
    title: test/yukicoder/4852.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ tree/auxiliarytree.cpp: line 8: unable to process #include in #if / #ifdef /\
    \ #ifndef other than include guards\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define call_from_test\n#include \"eulertourforvertex.cpp\"\n#include\
    \ \"lowestcommonancestor.cpp\"\n#undef call_from_test\n\n#endif\n\n//BEGIN CUT\
    \ HERE\nstruct AuxiliaryTree : EulerTourForVertex{\n  using super = EulerTourForVertex;\n\
    \  LowestCommonAncestor lca;\n\n  vector<vector<int>> T;\n  AuxiliaryTree(){}\n\
    \  AuxiliaryTree(int n):super(n),lca(n),T(n){}\n\n  void build(int r=0){\n   \
    \ super::build(r);\n    lca.G=super::G;\n    lca.build(r);\n  }\n\n  void add_aux_edge(int\
    \ u,int v){\n    T[u].emplace_back(v);\n    T[v].emplace_back(u);\n  }\n\n  using\
    \ super::idx;\n  void query(vector<int> &vs){\n    assert(!vs.empty());\n    sort(vs.begin(),vs.end(),\n\
    \         [&](int a,int b){return idx(a)<idx(b);});\n    vs.erase(unique(vs.begin(),vs.end()),vs.end());\n\
    \n    int k=vs.size();\n    stack<int> st;\n    st.emplace(vs[0]);\n    for(int\
    \ i=0;i+1<k;i++){\n      int w=lca.lca(vs[i],vs[i+1]);\n      if(w!=vs[i]){\n\
    \        int l=st.top();st.pop();\n        while(!st.empty()&&lca.dep[w]<lca.dep[st.top()]){\n\
    \          add_aux_edge(st.top(),l);\n          l=st.top();st.pop();\n       \
    \ }\n        if(st.empty()||st.top()!=w){\n          st.emplace(w);\n        \
    \  vs.emplace_back(w);\n        }\n        add_aux_edge(w,l);\n      }\n     \
    \ st.emplace(vs[i+1]);\n    }\n\n    while(st.size()>1){\n      int c=st.top();st.pop();\n\
    \      add_aux_edge(st.top(),c);\n    }\n  }\n\n  void clear(const vector<int>\
    \ &ws){\n    for(int w:ws) T[w].clear();\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - tree/eulertourforvertex.cpp
  - tree/lowestcommonancestor.cpp
  isVerificationFile: false
  path: tree/auxiliarytree.cpp
  requiredBy: []
  timestamp: '2020-09-15 18:05:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/3407.test.cpp
  - test/yukicoder/4852.test.cpp
documentation_of: ./tree/auxiliarytree.cpp
layout: document
title: Aux Tree
---

## できること
与えられた木の頂点の部分集合に関して、その頂点を全て含むような最小の木を構築する

## つかいかた
- query($S$): 部分集合 $S$ の Aux Tree を破壊的に構築する（必要な頂点が $S$ に追加される）
- clear($S$): Aux Tree を初期化する

## 計算量
部分集合のサイズを$k$として、$O(k \log k)$

Aux Treeの頂点数は $2k$ 以下になる


## 参考リンク
[LCAをベースに構築するAuxiliary Treeのメモ](https://smijake3.hatenablog.com/entry/2019/09/15/200200)