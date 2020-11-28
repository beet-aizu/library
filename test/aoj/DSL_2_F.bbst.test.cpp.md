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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ bbst/rbst/impl/basic.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../bbst/rbst/rbst.cpp\"\n#include \"../../bbst/rbst/data/lazy.cpp\"\n#include\
    \ \"../../bbst/rbst/impl/basic.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n  const char newl = '\\n';\n\n  int\
    \ n,q;\n  cin>>n>>q;\n\n  auto f=[](int a,int b){return min(a,b);};\n  auto g=[](int\
    \  ,int b){return b;};\n  auto flip=[](int a){return a;};\n\n  using Data = Lazy<int,\
    \ int, decltype(f), decltype(g), decltype(g),\n                    decltype(flip)>;\n\
    \  using Node = Data::Node;\n  constexpr size_t LIM = 1e6;\n  Basic<Data, LIM>\
    \ G(f,g,g,flip,INT_MAX,-1);\n  auto rt=G.build(vector<Node>(n,Node(INT_MAX,-1)));\n\
    \n  for(int i=0;i<q;i++){\n    int c;\n    cin>>c;\n    if(c==0){\n      int s,t,x;\n\
    \      cin>>s>>t>>x;\n      rt=G.update(rt,s,t+1,x);\n    }\n    if(c==1){\n \
    \     int s,t;\n      cin>>s>>t;\n      cout<<G.query(rt,s,t+1)<<newl;\n    }\n\
    \  }\n  return 0;\n}\n"
  dependsOn:
  - bbst/rbst/rbst.cpp
  - bbst/rbst/data/lazy.cpp
  - bbst/rbst/impl/basic.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_F.bbst.test.cpp
  requiredBy: []
  timestamp: '2020-11-04 18:35:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_F.bbst.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_F.bbst.test.cpp
- /verify/test/aoj/DSL_2_F.bbst.test.cpp.html
title: test/aoj/DSL_2_F.bbst.test.cpp
---
