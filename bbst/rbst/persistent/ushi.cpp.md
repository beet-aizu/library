---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/basic/base.cpp
    title: bbst/rbst/basic/base.cpp
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/persistent/base.cpp
    title: bbst/rbst/persistent/base.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0437.test.cpp
    title: test/aoj/0437.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ bbst/rbst/persistent/ushi.cpp: line 7: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n#define call_from_test\n#include \"../basic/base.cpp\"\n#include \"base.cpp\"\
    \n#undef call_from_test\n\n#endif\n//BEGIN CUT HERE\ntemplate<typename Tp>\nstruct\
    \ NodeBase{\n  using T = Tp;\n  NodeBase *l,*r,*p;\n  size_t cnt;\n  bool rev;\n\
    \  T val,dat;\n  NodeBase(T val):\n    cnt(1),rev(0),val(val),dat(val){l=r=p=nullptr;}\n\
    };\n\ntemplate<typename Node, size_t LIM>\nstruct PersistentUshi :\n  PersistentBase<Node,\
    \ LIM, PersistentUshi<Node, LIM>>{\n  using super = PersistentBase<Node, LIM,\
    \ PersistentUshi>;\n  using T = typename Node::T;\n  using F = function<T(T, T)>;\n\
    \  using S = function<T(T)>;\n\n  F f;\n  S flip;\n  T ti;\n\n  PersistentUshi(F\
    \ f,S flip,T ti):\n    f(f),flip(flip),ti(ti){}\n\n  PersistentUshi(F f,T ti):PersistentUshi(f,[](T\
    \ a){return a;},ti){}\n\n  using super::toggle;\n  inline void toggle(Node *t){\n\
    \    swap(t->l,t->r);\n    t->val=flip(t->val);\n    t->dat=flip(t->dat);\n  \
    \  t->rev^=1;\n  }\n\n  using super::clone;\n  inline Node* eval(Node* t){\n \
    \   t=clone(t);\n    if(t->rev){\n      t->l=clone(t->l);\n      t->r=clone(t->r);\n\
    \n      if(t->l) toggle(t->l);\n      if(t->r) toggle(t->r);\n      t->rev=false;\n\
    \    }\n    return t;\n  }\n\n  using super::count;\n  inline Node* pushup(Node\
    \ *t){\n    t->cnt=count(t->l)+1+count(t->r);\n    t->dat=t->val;\n    if(t->l)\
    \ t->dat=f(t->l->dat,t->dat);\n    if(t->r) t->dat=f(t->dat,t->r->dat);\n    return\
    \ t;\n  }\n\n  using super::merge;\n  using super::split;\n\n  T query(const Node\
    \ *a){\n    return a?a->dat:ti;\n  }\n\n  T query(Node *&a,size_t l,size_t r){\n\
    \    auto s=split(a,l);\n    auto t=split(s.second,r-l);\n    auto u=t.first;\n\
    \    T res=query(u);\n    a=merge(s.first,merge(u,t.second));\n    return res;\n\
    \  }\n\n  T get_val(Node *a,size_t k){\n    return super::find_by_order(a,k)->val;\n\
    \  }\n\n  Node* set_val(Node *a,size_t k,T val){\n    assert(k<count(a));\n  \
    \  a=eval(a);\n    size_t num=count(a->l);\n    if(k<num) a->l=set_val(a->l,k,val);\n\
    \    if(k>num) a->r=set_val(a->r,k-(num+1),val);\n    if(k==num) a->val=val;\n\
    \    return pushup(a);\n  }\n};\n//END CUT HERE\n//INSERT ABOVE HERE\n#ifndef\
    \ call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - bbst/rbst/basic/base.cpp
  - bbst/rbst/persistent/base.cpp
  isVerificationFile: false
  path: bbst/rbst/persistent/ushi.cpp
  requiredBy: []
  timestamp: '2020-10-28 18:29:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0437.test.cpp
documentation_of: bbst/rbst/persistent/ushi.cpp
layout: document
redirect_from:
- /library/bbst/rbst/persistent/ushi.cpp
- /library/bbst/rbst/persistent/ushi.cpp.html
title: bbst/rbst/persistent/ushi.cpp
---
