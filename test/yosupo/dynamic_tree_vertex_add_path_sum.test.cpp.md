---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: linkcuttree/base.cpp
    title: linkcuttree/base.cpp
  - icon: ':heavy_check_mark:'
    path: linkcuttree/path.cpp
    title: linkcuttree/path.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ linkcuttree/path.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../linkcuttree/base.cpp\"\n#include \"../../linkcuttree/path.cpp\"\n#undef\
    \ call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  const char newl = '\\n';\n\n  int n,q;\n  cin>>n>>q;\n  vector<int> as(n);\n\
    \  for(int i=0;i<n;i++) cin>>as[i];\n\n  using ll = long long;\n  using Node =\
    \ NodeBase<ll, ll>;\n  auto f=[&](ll a,ll b){return a+b;};\n  constexpr size_t\
    \ LIM = 2e5+100;\n  using LCT = Path<Node, LIM>;\n  LCT lct(f,f,f,0);\n\n  for(int\
    \ i=0;i<n;i++) lct.create(as[i]);\n\n  for(int i=1;i<n;i++){\n    int u,v;\n \
    \   cin>>u>>v;\n    lct.evert(lct[v]);\n    lct.link(lct[u],lct[v]);\n  }\n\n\
    \  for(int i=0;i<q;i++){\n    int t;\n    cin>>t;\n    if(t==0){\n      int u,v,w,x;\n\
    \      cin>>u>>v>>w>>x;\n\n      lct.evert(lct[u]);\n      lct.cut(lct[v]);\n\n\
    \      lct.evert(lct[x]);\n      lct.link(lct[w],lct[x]);\n    }\n\n    if(t==1){\n\
    \      int p,x;\n      cin>>p>>x;\n      lct.evert(lct[p]);\n      lct.update(lct[p],x);\n\
    \    }\n\n    if(t==2){\n      int u,v;\n      cin>>u>>v;\n      lct.evert(lct[u]);\n\
    \      cout<<lct.query(lct[v])<<newl;\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - linkcuttree/base.cpp
  - linkcuttree/path.cpp
  isVerificationFile: true
  path: test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2021-03-25 09:21:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp
- /verify/test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp.html
title: test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp
---
