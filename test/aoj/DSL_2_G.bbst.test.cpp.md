---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bbst/rbst/basic/base.cpp
    title: bbst/rbst/basic/base.cpp
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/basic/lazy.cpp
    title: bbst/rbst/basic/lazy.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ bbst/rbst/basic/lazy.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../bbst/rbst/basic/base.cpp\"\n#include \"../../bbst/rbst/basic/lazy.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  using ll = long long;\n  int n,q;\n  cin>>n>>q;\n\n  using P = pair<ll, ll>;\n\
    \  auto f=[](P a,P b){return P(a.first+b.first,a.second+b.second);};\n  auto g=[](P\
    \ a,ll b){return P(a.first+b*a.second,a.second);};\n  auto h=[](ll a,ll b){return\
    \ a+b;};\n\n  using Node = NodeBase<P, ll>;\n  constexpr size_t LIM = 1e6;\n \
    \ Lazy<Node, LIM> G(f,g,h,P(0,0),0);\n  auto rt=G.build(vector<Node>(n,Node(P(0,1),0)));\n\
    \n  for(int i=0;i<q;i++){\n    int c;\n    cin>>c;\n    if(c==0){\n      int s,t,x;\n\
    \      cin>>s>>t>>x;\n      s--;\n      rt=G.update(rt,s,t,x);\n    }\n    if(c==1){\n\
    \      int s,t;\n      cin>>s>>t;\n      s--;\n      cout<<G.query(rt,s,t).first<<\"\
    \\n\";\n    }\n  }\n  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - bbst/rbst/basic/base.cpp
  - bbst/rbst/basic/lazy.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_G.bbst.test.cpp
  requiredBy: []
  timestamp: '2020-10-28 15:23:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_G.bbst.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_G.bbst.test.cpp
- /verify/test/aoj/DSL_2_G.bbst.test.cpp.html
title: test/aoj/DSL_2_G.bbst.test.cpp
---
