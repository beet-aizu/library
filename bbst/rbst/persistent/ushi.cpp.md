---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/basic/base.cpp
    title: bbst/rbst/basic/base.cpp
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/basic/ushi.cpp
    title: bbst/rbst/basic/ushi.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://www.hackerrank.com/contests/happy-query-contest/challenges/minimum-history-query/problem
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ bbst/rbst/persistent/ushi.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../basic/base.cpp\"\n#include \"../basic/ushi.cpp\"\
    \n#undef call_from_test\n\n#endif\n//BEGIN CUT HERE\ntemplate<typename Node, size_t\
    \ LIM>\nstruct PersistentUshi : Ushi<Node, LIM>{\n  using super = Ushi<Node, LIM>;\n\
    \  using super::super;\n  using T = typename Node::T;\n\n  inline Node* clone(Node*\
    \ a){\n    if(a==nullptr) return a;\n    return super::create(*a);\n  }\n\n  Node*\
    \ eval(Node* a){\n    a=clone(a);\n    if(a->rev){\n      a->l=clone(a->l);\n\
    \      a->r=clone(a->r);\n    }\n    return super::eval(a);\n  }\n\n  T query(Node\
    \ *a,size_t l,size_t r){\n    auto s=super::split(a,l);\n    auto t=super::split(s.second,r-l);\n\
    \    return super::query(t.first);\n  }\n\n  Node* rebuild(Node* a){\n    auto\
    \ v=super::dump(a);\n    super::ptr=0;\n    return super::build(v);\n  }\n\n \
    \ bool almost_full() const{\n    return super::ptr>LIM*9/10;\n  }\n};\n//END CUT\
    \ HERE\n//INSERT ABOVE HERE\n#ifndef call_from_test\nsigned HAPPYQUERY_B(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n;\n  cin>>n;\n  vector<int>\
    \ as(n);\n  for(int i=0;i<n;i++) cin>>as[i];\n\n  auto f=[](int a,int b){return\
    \ min(a,b);};\n  int ti=INT_MAX;\n\n  using Node = NodeBase<int>;\n  constexpr\
    \ size_t LIM = 7e6;\n  PersistentUshi<Node, LIM> G(f,ti);\n  auto rt=G.build(vector<Node>(as.begin(),as.end()));\n\
    \n  vector<decltype(rt)> rts;\n  rts.emplace_back(rt);\n\n  int q1;\n  cin>>q1;\n\
    \  rts.reserve(q1+1);\n\n  for(int i=0;i<q1;i++){\n    int p,x;\n    cin>>p>>x;\n\
    \    p--;\n    rt=G.set_val(rt,p,x);\n    rts.emplace_back(rt);\n  }\n\n  int\
    \ q2;\n  cin>>q2;\n  int x=0;\n  for(int i=0;i<q2;i++){\n    int a,b,c;\n    cin>>a>>b>>c;\n\
    \    int k=a^x;\n    int l=(b^x)-1;\n    int r=(c^x);\n    assert(l<r);\n    x=G.query(rts[k],l,r);\n\
    \    cout<<x<<\"\\n\";\n  }\n  cout<<flush;\n  return 0;\n}\n/*\n  verified on\
    \ 2019/10/22\n  https://www.hackerrank.com/contests/happy-query-contest/challenges/minimum-history-query/problem\n\
    */\n\nsigned main(){\n  HAPPYQUERY_B();\n  return 0;\n}\n#endif\n"
  dependsOn:
  - bbst/rbst/basic/base.cpp
  - bbst/rbst/basic/ushi.cpp
  isVerificationFile: false
  path: bbst/rbst/persistent/ushi.cpp
  requiredBy: []
  timestamp: '2020-05-09 16:23:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bbst/rbst/persistent/ushi.cpp
layout: document
redirect_from:
- /library/bbst/rbst/persistent/ushi.cpp
- /library/bbst/rbst/persistent/ushi.cpp.html
title: bbst/rbst/persistent/ushi.cpp
---
