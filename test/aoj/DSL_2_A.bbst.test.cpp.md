---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 58, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ bbst/rbst/basic/ushi.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../bbst/rbst/basic/base.cpp\"\n#include \"../../bbst/rbst/basic/ushi.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,q;\n  cin>>n>>q;\n\n  auto f=[](int a,int b){return min(a,b);};\n  using\
    \ Node = NodeBase<int>;\n  constexpr size_t LIM = 1e6;\n  Ushi<Node, LIM> rmq(f,INT_MAX);\n\
    \  auto rt=rmq.build(vector<Node>(n,INT_MAX));\n\n  for(int i=0;i<q;i++){\n  \
    \  int c,x,y;\n    cin>>c>>x>>y;\n    if(c==0) rmq.set_val(rt,x,y);\n    if(c==1)\
    \ cout<<rmq.query(rt,x,y+1)<<\"\\n\";\n  }\n  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - bbst/rbst/basic/base.cpp
  - bbst/rbst/basic/ushi.cpp
  extendedDependsOn:
  - icon: ':warning:'
    path: bbst/rbst/basic/base.cpp
    title: bbst/rbst/basic/base.cpp
  - icon: ':warning:'
    path: bbst/rbst/basic/ushi.cpp
    title: bbst/rbst/basic/ushi.cpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: test/aoj/DSL_2_A.bbst.test.cpp
  requiredBy: []
  timestamp: '2020-05-09 16:23:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: test/aoj/DSL_2_A.bbst.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_A.bbst.test.cpp
- /verify/test/aoj/DSL_2_A.bbst.test.cpp.html
title: test/aoj/DSL_2_A.bbst.test.cpp
---
