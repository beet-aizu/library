---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ bbst/rbst/basic/dual.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"base.cpp\"\n#undef call_from_test\n\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename Ep>\nstruct NodeBase{\n  using E = Ep;\n \
    \ NodeBase *l,*r,*p;\n  size_t cnt;\n  bool rev;\n  E dat,laz;\n  NodeBase():cnt(1),rev(0){l=r=p=nullptr;}\n\
    \  NodeBase(E dat,E laz):\n    cnt(1),rev(0),dat(dat),laz(laz){l=r=p=nullptr;}\n\
    };\n\ntemplate<typename Node, size_t LIM>\nstruct Dual : BBSTBase<Node, LIM>{\n\
    \  using E = typename Node::E;\n  using super = BBSTBase<Node, LIM>;\n  using\
    \ H = function<E(E, E)>;\n\n  H h;\n  E ei;\n\n  Dual(H h,E ei):super(),h(h),ei(ei){}\n\
    \n  using super::create;\n  using super::merge;\n  using super::split;\n\n  Node*\
    \ build(size_t l,size_t r){\n    if(l+1==r) return create(Node(ei,ei));\n    size_t\
    \ m=(l+r)>>1;\n    return merge(build(l,m),build(m,r));\n  }\n\n  Node* init(int\
    \ n){\n    return build(0,n);\n  }\n\n  using super::count;\n  Node* recalc(Node\
    \ *a){\n    a->cnt=count(a->l)+1+count(a->r);\n    return a;\n  }\n\n  void propagate(Node\
    \ *a,E x){\n    a->dat=h(a->dat,x);\n    a->laz=h(a->laz,x);\n  }\n\n  using super::toggle;\n\
    \  void toggle(Node *a){\n    swap(a->l,a->r);\n    a->rev^=1;\n  }\n\n  // remove\
    \ \"virtual\" for optimization\n  virtual Node* eval(Node* a){\n    if(a->laz!=ei){\n\
    \      if(a->l) propagate(a->l,a->laz);\n      if(a->r) propagate(a->r,a->laz);\n\
    \      a->laz=ei;\n    }\n    if(a->rev){\n      if(a->l) toggle(a->l);\n    \
    \  if(a->r) toggle(a->r);\n      a->rev=false;\n    }\n    return recalc(a);\n\
    \  }\n\n  Node* update(Node *a,size_t l,size_t r,E x){\n    auto s=split(a,l);\n\
    \    auto t=split(s.second,r-l);\n    auto u=eval(t.first);\n    propagate(u,x);\n\
    \    return merge(s.first,merge(u,t.second));\n  }\n\n  Node* set_val(Node *a,size_t\
    \ k,E x){\n    assert(k<count(a));\n    a=eval(a);\n    size_t num=count(a->l);\n\
    \    if(k<num) a->l=set_val(a->l,k,x);\n    if(k>num) a->r=set_val(a->r,k-(num+1),x);\n\
    \    if(k==num) a->dat=x;\n    return recalc(a);\n  }\n\n  E get_val(Node *a,size_t\
    \ k){\n    assert(k<count(a));\n    a=eval(a);\n    size_t num=count(a->l);\n\
    \    if(k<num) return get_val(a->l,k);\n    if(k>num) return get_val(a->r,k-(num+1));\n\
    \    return a->dat;\n  }\n\n  void dump(Node* a,typename vector<E>::iterator it){\n\
    \    if(!count(a)) return;\n    a=eval(a);\n    dump(a->l,it);\n    *(it+count(a->l))=a->dat;\n\
    \    dump(a->r,it+count(a->l)+1);\n  }\n\n  vector<E> dump(Node* a){\n    vector<E>\
    \ vs(count(a));\n    dump(a,vs.begin());\n    return vs;\n  }\n};\n//END CUT HERE\n\
    //INSERT ABOVE HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  dependsOn:
  - bbst/rbst/basic/base.cpp
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/basic/base.cpp
    title: bbst/rbst/basic/base.cpp
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_D.bbst.test.cpp
    title: test/aoj/DSL_2_D.bbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_E.bbst.test.cpp
    title: test/aoj/DSL_2_E.bbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1579.test.cpp
    title: test/aoj/1579.test.cpp
  isVerificationFile: false
  path: bbst/rbst/basic/dual.cpp
  requiredBy: []
  timestamp: '2020-03-22 15:37:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - test/aoj/DSL_2_D.bbst.test.cpp
  - test/aoj/DSL_2_E.bbst.test.cpp
  - test/aoj/1579.test.cpp
documentation_of: bbst/rbst/basic/dual.cpp
layout: document
redirect_from:
- /library/bbst/rbst/basic/dual.cpp
- /library/bbst/rbst/basic/dual.cpp.html
title: bbst/rbst/basic/dual.cpp
---
