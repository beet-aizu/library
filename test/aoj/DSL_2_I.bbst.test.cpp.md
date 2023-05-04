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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ bbst/rbst/impl/basic.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../bbst/rbst/rbst.cpp\"\n#include \"../../bbst/rbst/data/lazy.cpp\"\n#include\
    \ \"../../bbst/rbst/impl/basic.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n  const char newl = '\\n';\n\n  int\
    \ n,q;\n  cin>>n>>q;\n\n  using P = pair<int, int>;\n  auto f=[](P a,P b){return\
    \ P(a.first+b.first,a.second+b.second);};\n  auto g=[](P a,int b){return P(a.second*b,a.second);};\n\
    \  auto h=[](int,int b){return b;};\n  auto flip=[](P a){return a;};\n\n  int\
    \ ei=-1010;\n  using Data = decltype(Lazy(f,g,h,flip,P(0,0),ei));\n  using Node\
    \ = Data::Node;\n  constexpr size_t LIM = 1e6;\n  Basic<Data, LIM> G(f,g,h,flip,P(0,0),ei);\n\
    \  auto rt=G.build(vector<Node>(n,Node(P(0,1),ei)));\n\n  for(int i=0;i<q;i++){\n\
    \    int c;\n    cin>>c;\n    if(c==0){\n      int s,t,x;\n      cin>>s>>t>>x;\n\
    \      rt=G.update(rt,s,t+1,x);\n    }\n    if(c==1){\n      int s,t;\n      cin>>s>>t;\n\
    \      cout<<G.query(rt,s,t+1).first<<newl;\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - bbst/rbst/rbst.cpp
  - bbst/rbst/data/lazy.cpp
  - bbst/rbst/impl/basic.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_I.bbst.test.cpp
  requiredBy: []
  timestamp: '2020-11-28 18:14:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_I.bbst.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_I.bbst.test.cpp
- /verify/test/aoj/DSL_2_I.bbst.test.cpp.html
title: test/aoj/DSL_2_I.bbst.test.cpp
---
