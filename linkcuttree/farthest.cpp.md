---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: linkcuttree/base.cpp
    title: linkcuttree/base.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1595.linkcuttree.test.cpp
    title: test/aoj/1595.linkcuttree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_A.linkcuttree.test.cpp
    title: test/aoj/GRL_5_A.linkcuttree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/tkppc/tasks/tkppc2015_j
    - https://ei1333.hateblo.jp/entry/2019/06/13/133736
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ linkcuttree/farthest.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"base.cpp\"\n#undef call_from_test\n\n#endif\n\
    // https://ei1333.hateblo.jp/entry/2019/06/13/133736\n//BEGIN CUT HERE\ntemplate<typename\
    \ Tp>\nstruct NodeBase{\n  using T = Tp;\n  NodeBase *l,*r,*p;\n  bool rev;\n\
    \  T val,ld,rd,smd;\n  multiset<T> td;\n  NodeBase(T val):rev(0),val(val){\n \
    \   l=r=p=nullptr;\n    ld=rd=smd=val;\n    td.emplace(0);\n  }\n};\n\ntemplate<typename\
    \ Np, size_t LIM>\nstruct Farthest : LinkCutTreeBase<Np, LIM, Farthest<Np, LIM>>{\n\
    \  using super = LinkCutTreeBase<Np, LIM, Farthest>;\n  using Node = Np;\n  using\
    \ T = typename Node::T;\n\n  Node* create(T val){\n    return super::create(Node(val));\n\
    \  }\n\n  inline void toggle(Node *t){\n    swap(t->l,t->r);\n    swap(t->ld,t->rd);\n\
    \    t->rev^=1;\n  }\n\n  inline Node* eval(Node *t){\n    if(t->rev){\n     \
    \ if(t->l) toggle(t->l);\n      if(t->r) toggle(t->r);\n      t->rev=false;\n\
    \    }\n    return t;\n  }\n\n  inline void pushup(Node *t){\n    if(t==nullptr)\
    \ return;\n    t->smd=t->val;\n    if(t->l) t->smd+=t->l->smd;\n    if(t->r) t->smd+=t->r->smd;\n\
    \n    T lld=t->l?t->l->ld:0;\n    T rrd=t->r?t->r->rd:0;\n\n    T lsmd=t->l?t->l->smd:0;\n\
    \    T rsmd=t->r?t->r->smd:0;\n\n    t->ld=max(lld,lsmd+t->val+*(t->td).rbegin());\n\
    \    if(t->r) t->ld=max(t->ld,lsmd+t->val+t->r->ld);\n\n    t->rd=max(rrd,rsmd+t->val+*(t->td).rbegin());\n\
    \    if(t->l) t->rd=max(t->rd,rsmd+t->val+t->l->rd);\n  }\n\n  using super::splay;\n\
    \n  inline Node* expose(Node *t){\n    Node *rp=nullptr;\n    for(Node *c=t;c;c=c->p){\n\
    \      splay(c);\n      if(c->r) c->td.emplace(c->r->ld);\n      c->r=rp;\n  \
    \    if(c->r) c->td.erase(c->td.find(c->r->ld));\n      pushup(c);\n      rp=c;\n\
    \    }\n    splay(t);\n    return rp;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned TKPPC2015_J(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using ll = long long;\n  using Node = NodeBase<ll>;\n  constexpr size_t LIM\
    \ = 1e6+200;\n  using LCT = Farthest<Node, LIM>;\n  LCT lct;\n\n  vector<LCT::Node*>\
    \ vs;\n  vector<LCT::Node*> es;\n  vs.reserve(5e5+100);\n  es.reserve(5e5+100);\n\
    \n  int num=0;\n  vs.emplace_back(lct.create(0));\n  es.emplace_back(lct.create(0));\n\
    \  num++;\n\n  int q;\n  cin>>q;\n  for(int i=0;i<q;i++){\n    int t,a,c;\n  \
    \  cin>>t>>a>>c;\n    if(t==1){\n      vs.emplace_back(lct.create(0));\n     \
    \ es.emplace_back(lct.create(c));\n      lct.link(vs[a],es[num]);\n      lct.link(es[num],vs[num]);\n\
    \      num++;\n    }\n    if(t==2){\n      lct.expose(es[a]);\n      es[a]->val=c;\n\
    \      lct.pushup(es[a]);\n    }\n    if(t==3){\n      lct.evert(vs[a]);\n   \
    \   cout<<(vs[a]->ld)<<\"\\n\";\n    }\n  }\n  cout<<flush;\n  return 0;\n}\n\
    /*\n  verified on 2020/10/28\n  https://atcoder.jp/contests/tkppc/tasks/tkppc2015_j\n\
    */\n\nsigned main(){\n  TKPPC2015_J();\n  return 0;\n}\n#endif\n"
  dependsOn:
  - linkcuttree/base.cpp
  isVerificationFile: false
  path: linkcuttree/farthest.cpp
  requiredBy: []
  timestamp: '2021-03-25 09:21:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1595.linkcuttree.test.cpp
  - test/aoj/GRL_5_A.linkcuttree.test.cpp
documentation_of: linkcuttree/farthest.cpp
layout: document
redirect_from:
- /library/linkcuttree/farthest.cpp
- /library/linkcuttree/farthest.cpp.html
title: linkcuttree/farthest.cpp
---
