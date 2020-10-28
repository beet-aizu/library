---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/basic/base.cpp
    title: bbst/rbst/basic/base.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0438.test.cpp
    title: test find_by_order, order_of_key
  - icon: ':heavy_check_mark:'
    path: test/aoj/2890.test.cpp
    title: test order_of_key
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
    \ bbst/rbst/basic/array.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"base.cpp\"\n#undef call_from_test\n\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename Tp>\nstruct NodeBase{\n  using T = Tp;\n \
    \ NodeBase *l,*r,*p;\n  size_t cnt;\n  bool rev;\n  T val;\n  NodeBase(T val):\n\
    \    cnt(1),rev(0),val(val){l=r=p=nullptr;}\n};\n\ntemplate<typename Node, size_t\
    \ LIM>\nstruct Array : BBSTBase<Node, LIM, Array<Node, LIM>>{\n  using super =\
    \ BBSTBase<Node, LIM, Array>;\n  using T = typename Node::T;\n\n  inline void\
    \ toggle(Node *t){\n    swap(t->l,t->r);\n    t->rev^=1;\n  }\n\n  inline Node*\
    \ eval(Node* t){\n    if(t->rev){\n      if(t->l) toggle(t->l);\n      if(t->r)\
    \ toggle(t->r);\n      t->rev=false;\n    }\n    return t;\n  }\n\n  using super::count;\n\
    \  inline Node* pushup(Node *t){\n    t->cnt=count(t->l)+1+count(t->r);\n    return\
    \ t;\n  }\n\n  using super::find_by_order;\n\n  Node* set_val(Node *a,size_t k,T\
    \ val){\n    auto b=find_by_order(a,k);\n    b->val=val;\n    return b;\n  }\n\
    \n  T get_val(Node *a,size_t k){\n    return find_by_order(a,k)->val;\n  }\n};\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn:
  - bbst/rbst/basic/base.cpp
  isVerificationFile: false
  path: bbst/rbst/basic/array.cpp
  requiredBy: []
  timestamp: '2020-10-28 18:43:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2890.test.cpp
  - test/aoj/0438.test.cpp
documentation_of: bbst/rbst/basic/array.cpp
layout: document
redirect_from:
- /library/bbst/rbst/basic/array.cpp
- /library/bbst/rbst/basic/array.cpp.html
title: bbst/rbst/basic/array.cpp
---
