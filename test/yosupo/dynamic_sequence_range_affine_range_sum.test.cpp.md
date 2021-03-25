---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/data/lazy.cpp
    title: bbst/rbst/data/lazy.cpp
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/impl/basic.cpp
    title: bbst/rbst/impl/basic.cpp
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/rbst.cpp
    title: bbst/rbst/rbst.cpp
  - icon: ':heavy_check_mark:'
    path: math/affine.cpp
    title: math/affine.cpp
  - icon: ':question:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ bbst/rbst/impl/basic.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../mod/mint.cpp\"\n#include \"../../math/affine.cpp\"\n#include \"../../bbst/rbst/rbst.cpp\"\
    \n#include \"../../bbst/rbst/data/lazy.cpp\"\n#include \"../../bbst/rbst/impl/basic.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  const char newl = '\\n';\n\n  using M = Mint<int, 998244353>;\n  using T =\
    \ pair<M, M>;\n  using E = pair<M, M>;\n  auto [f,g,h,ti,ei]=Affine::params<T,\
    \ E>();\n\n  auto flip=[](T a){return a;};\n  using Data = decltype(Lazy(f,g,h,flip,ti,ei));\n\
    \  using Node = Data::Node;\n  constexpr size_t LIM = 1e6;\n  Basic<Data, LIM>\
    \ G(f,g,h,flip,ti,ei);\n\n  int n,q;\n  cin>>n>>q;\n  vector<int> as(n);\n  for(int\
    \ i=0;i<n;i++) cin>>as[i];\n  vector<Node> vt;\n  for(int i=0;i<n;i++) vt.emplace_back(T(as[i],1),ei);\n\
    \  auto rt=G.build(vt);\n\n  for(int i=0;i<q;i++){\n    int t;\n    cin>>t;\n\
    \    if(t==0){\n      int k,x;\n      cin>>k>>x;\n      rt=G.insert(rt,k,Node(T(x,1),ei));\n\
    \    }\n    if(t==1){\n      int k;\n      cin>>k;\n      rt=G.erase(rt,k);\n\
    \    }\n    if(t==2){\n      int l,r;\n      cin>>l>>r;\n      rt=G.toggle(rt,l,r);\n\
    \    }\n    if(t==3){\n      int l,r,b,c;\n      cin>>l>>r>>b>>c;\n      rt=G.update(rt,l,r,E(b,c));\n\
    \    }\n    if(t==4){\n      int l,r;\n      cin>>l>>r;\n      cout<<G.query(rt,l,r).first<<newl;\n\
    \    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - mod/mint.cpp
  - math/affine.cpp
  - bbst/rbst/rbst.cpp
  - bbst/rbst/data/lazy.cpp
  - bbst/rbst/impl/basic.cpp
  isVerificationFile: true
  path: test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2021-03-25 09:46:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
- /verify/test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp.html
title: test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
---
