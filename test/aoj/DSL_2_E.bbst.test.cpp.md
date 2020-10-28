---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bbst/rbst/basic/base.cpp
    title: bbst/rbst/basic/base.cpp
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/basic/dual.cpp
    title: bbst/rbst/basic/dual.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ bbst/rbst/basic/dual.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../bbst/rbst/basic/base.cpp\"\n#include \"../../bbst/rbst/basic/dual.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,q;\n  cin>>n>>q;\n\n  auto h=[](int a,int b){return a+b;};\n  int ei=0;\n\
    \n  using Node = NodeBase<int>;\n  constexpr size_t LIM = 1e6;\n  Dual<Node, LIM>\
    \ G(h,ei);\n\n  auto rt=G.init(n);\n\n  for(int i=0;i<q;i++){\n    int tp;\n \
    \   cin>>tp;\n    if(tp==0){\n      int s,t,x;\n      cin>>s>>t>>x;\n      s--;\n\
    \      rt=G.update(rt,s,t,x);\n    }\n    if(tp==1){\n      int s;\n      cin>>s;\n\
    \      s--;\n      cout<<G.get_val(rt,s)<<\"\\n\";\n    }\n  }\n  cout<<flush;\n\
    \  return 0;\n}\n"
  dependsOn:
  - bbst/rbst/basic/base.cpp
  - bbst/rbst/basic/dual.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_E.bbst.test.cpp
  requiredBy: []
  timestamp: '2020-10-28 18:43:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_E.bbst.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_E.bbst.test.cpp
- /verify/test/aoj/DSL_2_E.bbst.test.cpp.html
title: test/aoj/DSL_2_E.bbst.test.cpp
---
