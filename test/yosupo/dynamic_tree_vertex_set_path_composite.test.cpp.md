---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: linkcuttree/base.cpp
    title: linkcuttree/base.cpp
  - icon: ':x:'
    path: linkcuttree/path.cpp
    title: linkcuttree/path.cpp
  - icon: ':x:'
    path: math/dual.cpp
    title: math/dual.cpp
  - icon: ':question:'
    path: math/linearfunction.cpp
    title: math/linearfunction.cpp
  - icon: ':question:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ linkcuttree/path.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../mod/mint.cpp\"\n#include \"../../math/linearfunction.cpp\"\n#include\
    \ \"../../math/dual.cpp\"\n#include \"../../linkcuttree/base.cpp\"\n#include \"\
    ../../linkcuttree/path.cpp\"\n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n  const char newl = '\\n';\n\n  int n,q;\n  cin>>n>>q;\n\
    \  vector<int> as(n),bs(n);\n  for(int i=0;i<n;i++) cin>>as[i]>>bs[i];\n\n  using\
    \ M = Mint<int, 998244353>;\n  using LF = LinearFunction<M>;\n  using DL = Dual<LF>;\n\
    \n  using P = pair<LF, DL>;\n  using Node = NodeBase<P, int>;\n  auto f=[&](P\
    \ a,P b){return P(a.first*b.first,a.second*b.second);};\n  auto g=[&](P a,int){return\
    \ a;};\n  auto h=[&](int a,int){return a;};\n  auto flip=[&](P a){return P(a.second.v,a.first);};\n\
    \n  constexpr size_t LIM = 2e5+100;\n  using LCT = Path<Node, LIM>;\n  LCT lct(f,g,h,flip,0);\n\
    \n  for(int i=0;i<n;i++) lct.create(P(LF(as[i],bs[i]),LF(as[i],bs[i])));\n\n \
    \ for(int i=1;i<n;i++){\n    int u,v;\n    cin>>u>>v;\n    lct.evert(lct[v]);\n\
    \    lct.link(lct[u],lct[v]);\n  }\n\n  for(int i=0;i<q;i++){\n    int t;\n  \
    \  cin>>t;\n\n    if(t==0){\n      int u,v,w,x;\n      cin>>u>>v>>w>>x;\n\n  \
    \    lct.evert(lct[u]);\n      lct.cut(lct[v]);\n\n      lct.evert(lct[x]);\n\
    \      lct.link(lct[w],lct[x]);\n    }\n\n    if(t==1){\n      int p,c,d;\n  \
    \    cin>>p>>c>>d;\n      lct.set_val(lct[p],P(LF(c,d),LF(c,d)));\n    }\n\n \
    \   if(t==2){\n      int u,v,x;\n      cin>>u>>v>>x;\n      lct.evert(lct[u]);\n\
    \      cout<<lct.query(lct[v]).first(x)<<newl;\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - mod/mint.cpp
  - math/linearfunction.cpp
  - math/dual.cpp
  - linkcuttree/base.cpp
  - linkcuttree/path.cpp
  isVerificationFile: true
  path: test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 18:48:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
- /verify/test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp.html
title: test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
---
