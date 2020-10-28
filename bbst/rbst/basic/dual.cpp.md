---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bbst/rbst/basic/base.cpp
    title: bbst/rbst/basic/base.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/1579.test.cpp
    title: test/aoj/1579.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL_2_D.bbst.test.cpp
    title: test/aoj/DSL_2_D.bbst.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL_2_E.bbst.test.cpp
    title: test/aoj/DSL_2_E.bbst.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ bbst/rbst/basic/dual.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"base.cpp\"\n#undef call_from_test\n\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename Ep>\nstruct NodeBase{\n  using E = Ep;\n \
    \ NodeBase *l,*r,*p;\n  size_t cnt;\n  bool rev;\n  E val,laz;\n  NodeBase(E val,E\
    \ laz):\n    cnt(1),rev(0),val(val),laz(laz){l=r=p=nullptr;}\n};\n\ntemplate<typename\
    \ Node, size_t LIM>\nstruct Dual : BBSTBase<Node, LIM, Dual<Node, LIM>>{\n  using\
    \ super = BBSTBase<Node, LIM, Dual>;\n  using E = typename Node::E;\n  using H\
    \ = function<E(E, E)>;\n\n  H h;\n  E ei;\n\n  Dual(H h,E ei):h(h),ei(ei){}\n\n\
    \  void propagate(Node *t,E x){\n    t->val=h(t->val,x);\n    t->laz=h(t->laz,x);\n\
    \  }\n\n  void toggle(Node *t){\n    swap(t->l,t->r);\n    t->rev^=1;\n  }\n\n\
    \  Node* eval(Node* t){\n    if(t->laz!=ei){\n      if(t->l) propagate(t->l,t->laz);\n\
    \      if(t->r) propagate(t->r,t->laz);\n      t->laz=ei;\n    }\n    if(t->rev){\n\
    \      if(t->l) toggle(t->l);\n      if(t->r) toggle(t->r);\n      t->rev=false;\n\
    \    }\n    return t;\n  }\n\n  using super::count;\n  Node* pushup(Node *t){\n\
    \    t->cnt=count(t->l)+1+count(t->r);\n    return t;\n  }\n\n  Node* init(int\
    \ n){\n    return build(vector<Node>(n,Node(ei,ei)));\n  }\n\n  using super::merge;\n\
    \  using super::split;\n\n  Node* update(Node *a,size_t l,size_t r,E x){\n   \
    \ auto s=split(a,l);\n    auto t=split(s.second,r-l);\n    auto u=eval(t.first);\n\
    \    propagate(u,x);\n    return merge(s.first,merge(u,t.second));\n  }\n\n  Node*\
    \ set_val(Node *a,size_t k,E x){\n    assert(k<count(a));\n    a=eval(a);\n  \
    \  size_t num=count(a->l);\n    if(k<num) a->l=set_val(a->l,k,x);\n    if(k>num)\
    \ a->r=set_val(a->r,k-(num+1),x);\n    if(k==num) a->val=x;\n    return pushup(a);\n\
    \  }\n\n  E get_val(Node *a,size_t k){\n    assert(k<count(a));\n    a=eval(a);\n\
    \    size_t num=count(a->l);\n    if(k<num) return get_val(a->l,k);\n    if(k>num)\
    \ return get_val(a->r,k-(num+1));\n    return a->val;\n  }\n};\n//END CUT HERE\n\
    //INSERT ABOVE HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  dependsOn:
  - bbst/rbst/basic/base.cpp
  isVerificationFile: false
  path: bbst/rbst/basic/dual.cpp
  requiredBy: []
  timestamp: '2020-10-28 15:23:04+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_2_E.bbst.test.cpp
  - test/aoj/1579.test.cpp
  - test/aoj/DSL_2_D.bbst.test.cpp
documentation_of: bbst/rbst/basic/dual.cpp
layout: document
redirect_from:
- /library/bbst/rbst/basic/dual.cpp
- /library/bbst/rbst/basic/dual.cpp.html
title: bbst/rbst/basic/dual.cpp
---
