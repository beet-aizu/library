---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: linkcuttree/base.cpp
    title: linkcuttree/base.cpp
  - icon: ':x:'
    path: linkcuttree/subtree.cpp
    title: linkcuttree/subtree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ linkcuttree/subtree.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/vertex_add_subtree_sum\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../linkcuttree/base.cpp\"\n#include \"../../linkcuttree/subtree.cpp\"\n\
    #undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  using ll = long long;\n\n  int n,q;\n  cin>>n>>q;\n  vector<ll> as(n);\n \
    \ for(int i=0;i<n;i++) cin>>as[i];\n\n  using Node = NodeBase<ll>;\n  constexpr\
    \ size_t LIM = 1e6;\n  using LCT = SubTree<Node, LIM>;\n  LCT lct;\n\n  for(int\
    \ i=0;i<n;i++) lct.create(as[i]);\n\n  for(int i=1;i<n;i++){\n    int p;\n   \
    \ cin>>p;\n    lct.link(lct[p],lct[i]);\n  }\n\n  for(int i=0;i<q;i++){\n    int\
    \ t;\n    cin>>t;\n    if(t==0){\n      int u,x;\n      cin>>u>>x;\n      as[u]+=x;\n\
    \      lct.set_val(lct[u],as[u]);\n    }\n    if(t==1){\n      int u;\n      cin>>u;\n\
    \      Node* p=lct.parent(lct[u]);\n      if(p) lct.cut(lct[u]);\n      cout<<lct.query(lct[u])<<\"\
    \\n\";\n      if(p) lct.link(p,lct[u]);\n    }\n  }\n  cout<<flush;\n  return\
    \ 0;\n}\n"
  dependsOn:
  - linkcuttree/base.cpp
  - linkcuttree/subtree.cpp
  isVerificationFile: true
  path: test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 19:04:41+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp
- /verify/test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp.html
title: test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp
---
