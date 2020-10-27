---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bbst/rbst/basic/base.cpp
    title: bbst/rbst/basic/base.cpp
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/basic/ushi.cpp
    title: bbst/rbst/basic/ushi.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ bbst/rbst/basic/ushi.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../bbst/rbst/basic/base.cpp\"\n#include \"../../bbst/rbst/basic/ushi.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,q;\n  cin>>n>>q;\n\n  auto f=[](int a,int b){return min(a,b);};\n  using\
    \ Node = NodeBase<int>;\n  constexpr size_t LIM = 1e6;\n  Ushi<Node, LIM> rmq(f,INT_MAX);\n\
    \  auto rt=rmq.build(vector<Node>(n,INT_MAX));\n\n  for(int i=0;i<q;i++){\n  \
    \  int c,x,y;\n    cin>>c>>x>>y;\n    if(c==0) rmq.set_val(rt,x,y);\n    if(c==1)\
    \ cout<<rmq.query(rt,x,y+1)<<\"\\n\";\n  }\n  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - bbst/rbst/basic/base.cpp
  - bbst/rbst/basic/ushi.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_A.bbst.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 12:55:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_A.bbst.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_A.bbst.test.cpp
- /verify/test/aoj/DSL_2_A.bbst.test.cpp.html
title: test/aoj/DSL_2_A.bbst.test.cpp
---
