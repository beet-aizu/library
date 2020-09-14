---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/basic/base.cpp
    title: bbst/rbst/basic/base.cpp
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/basic/lazy.cpp
    title: bbst/rbst/basic/lazy.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://atcoder.jp/contests/arc030/tasks/arc030_4
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 189, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ bbst/rbst/persistent/lazy.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../basic/base.cpp\"\n#include \"../basic/lazy.cpp\"\
    \n#undef call_from_test\n\n#endif\n//BEGIN CUT HERE\ntemplate<typename Node, size_t\
    \ LIM>\nstruct PersistentLazy : Lazy<Node, LIM>{\n  using super = Lazy<Node, LIM>;\n\
    \  using super::super;\n  using T = typename Node::T;\n\n  inline Node* clone(Node*\
    \ a){\n    if(a==nullptr) return a;\n    return super::create(*a);\n  }\n\n  Node*\
    \ eval(Node* a){\n    a=clone(a);\n    a->l=clone(a->l);\n    a->r=clone(a->r);\n\
    \    return super::eval(a);\n  }\n\n  T query(Node *a,size_t l,size_t r){\n  \
    \  auto s=super::split(a,l);\n    auto t=super::split(s.second,r-l);\n    return\
    \ super::query(t.first);\n  }\n\n  Node* rebuild(Node* a){\n    auto vs=super::dump(a);\n\
    \    super::ptr=0;\n    return super::build(vs);\n  }\n\n  bool almost_full()\
    \ const{\n    return super::ptr>LIM*9/10;\n  }\n};\n//END CUT HERE\n//INSERT ABOVE\
    \ HERE\nsigned ARC030_D(){\n  int n,q;\n  scanf(\"%d %d\",&n,&q);\n\n  using ll\
    \ = long long;\n  using P = pair<ll, ll>;\n  vector<P> v(n,P(0,1));\n  for(int\
    \ i=0;i<n;i++) scanf(\"%lld\",&v[i].first);\n\n  auto f=[](P a,P b){return P(a.first+b.first,a.second+b.second);};\n\
    \  auto g=[](P a,ll b){return P(a.first+b*a.second,a.second);};\n  auto h=[](ll\
    \ a,ll b){return a+b;};\n\n  using Node = NodeBase<P, ll>;\n  constexpr size_t\
    \ LIM = 6e6;\n  PersistentLazy<Node, LIM> G(f,g,h,P(0,0),0);\n  auto rt=G.build(v);\n\
    \n  for(int i=0;i<q;i++){\n    int t;\n    scanf(\"%d\",&t);\n    if(t==1){\n\
    \      int a,b,v;\n      scanf(\"%d %d %d\",&a,&b,&v);\n      a--;\n      rt=G.update(rt,a,b,v);\n\
    \    }\n    if(t==2){\n      int a,b,c,d;\n      scanf(\"%d %d %d %d\",&a,&b,&c,&d);\n\
    \      a--;c--;\n      auto s=G.split(rt,a);\n      auto t=G.split(s.second,b-a);\n\
    \      auto u=G.split(rt,c);\n      auto v=G.split(u.second,d-c);\n\n      rt=G.merge(G.merge(s.first,v.first),t.second);\n\
    \    }\n    if(t==3){\n      int a,b;\n      scanf(\"%d %d\",&a,&b);\n      a--;\n\
    \      printf(\"%lld\\n\",G.query(rt,a,b).first);\n    }\n\n    if(G.almost_full())\
    \ rt=G.rebuild(rt);\n  }\n  return 0;\n}\n/*\n  verified on 2019/10/22\n  https://atcoder.jp/contests/arc030/tasks/arc030_4\n\
    */\n\nsigned main(){\n  ARC030_D();\n  return 0;\n}\n"
  dependsOn:
  - bbst/rbst/basic/base.cpp
  - bbst/rbst/basic/lazy.cpp
  isVerificationFile: false
  path: bbst/rbst/persistent/lazy.cpp
  requiredBy: []
  timestamp: '2020-05-09 16:23:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bbst/rbst/persistent/lazy.cpp
layout: document
redirect_from:
- /library/bbst/rbst/persistent/lazy.cpp
- /library/bbst/rbst/persistent/lazy.cpp.html
title: bbst/rbst/persistent/lazy.cpp
---
