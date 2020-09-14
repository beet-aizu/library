---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: linkcuttree/base.cpp
    title: linkcuttree/base.cpp
  - icon: ':heavy_check_mark:'
    path: linkcuttree/subtree.cpp
    title: linkcuttree/subtree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 67, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ linkcuttree/subtree.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../linkcuttree/base.cpp\"\n#include \"../../linkcuttree/subtree.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  const char newl = '\\n';\n\n  using ll = long long;\n\n  int n,q;\n  cin>>n>>q;\n\
    \  vector<ll> as(n);\n  for(int i=0;i<n;i++) cin>>as[i];\n\n  using Node = NodeBase<ll>;\n\
    \  constexpr size_t LIM = 2e5+100;\n  using LCT = SubTree<Node, LIM>;\n  LCT lct;\n\
    \n  for(int i=0;i<n;i++) lct.create(as[i]);\n\n  for(int i=1;i<n;i++){\n    int\
    \ u,v;\n    cin>>u>>v;\n    lct.evert(lct[v]);\n    lct.link(lct[u],lct[v]);\n\
    \  }\n\n  for(int i=0;i<q;i++){\n    int t;\n    cin>>t;\n    if(t==0){\n    \
    \  int u,v,w,x;\n      cin>>u>>v>>w>>x;\n\n      lct.evert(lct[u]);\n      lct.cut(lct[v]);\n\
    \n      lct.evert(lct[x]);\n      lct.link(lct[w],lct[x]);\n    }\n\n    if(t==1){\n\
    \      int p,x;\n      cin>>p>>x;\n      as[p]+=x;\n      lct.set_val(lct[p],as[p]);\n\
    \    }\n\n    if(t==2){\n      int v,p;\n      cin>>v>>p;\n      lct.evert(lct[p]);\n\
    \      lct.cut(lct[v]);\n      cout<<lct.query(lct[v])<<newl;\n      lct.link(lct[p],lct[v]);\n\
    \    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - linkcuttree/base.cpp
  - linkcuttree/subtree.cpp
  isVerificationFile: true
  path: test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2020-07-27 11:09:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
- /verify/test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp.html
title: test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
---
