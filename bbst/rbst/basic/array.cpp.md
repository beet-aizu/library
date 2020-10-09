---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/basic/base.cpp
    title: bbst/rbst/basic/base.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/persistent/array.cpp
    title: bbst/rbst/persistent/array.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0438.test.cpp
    title: test find_by_order, order_of_key
  - icon: ':heavy_check_mark:'
    path: test/aoj/2890.test.cpp
    title: test order_of_key
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_queue.test.cpp
    title: test/yosupo/persistent_queue.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ bbst/rbst/basic/array.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"base.cpp\"\n#undef call_from_test\n\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename Tp>\nstruct NodeBase{\n  using T = Tp;\n \
    \ NodeBase *l,*r,*p;\n  size_t cnt;\n  bool rev;\n  T val;\n  NodeBase():cnt(1),rev(0){l=r=p=nullptr;}\n\
    \  NodeBase(T val):\n    cnt(1),rev(0),val(val){l=r=p=nullptr;}\n};\n\ntemplate<typename\
    \ Node, size_t LIM>\nstruct Array : BBSTBase<Node, LIM>{\n  using T = typename\
    \ Node::T;\n  using super = BBSTBase<Node, LIM>;\n\n  Array():super(){}\n\n  using\
    \ super::count;\n\n  Node* recalc(Node *a){\n    a->cnt=count(a->l)+1+count(a->r);\n\
    \    return a;\n  }\n\n  void toggle(Node *a){\n    swap(a->l,a->r);\n    a->rev^=1;\n\
    \  }\n\n  // remove \"virtual\" for optimization\n  virtual Node* eval(Node* a){\n\
    \    if(a->rev){\n      if(a->l) toggle(a->l);\n      if(a->r) toggle(a->r);\n\
    \      a->rev=false;\n    }\n    return recalc(a);\n  }\n\n  using super::find_by_order;\n\
    \n  Node* set_val(Node *a,size_t k,T val){\n    auto b=find_by_order(a,k);\n \
    \   b->val=val;\n    return b;\n  }\n\n  T get_val(Node *a,size_t k){\n    return\
    \ find_by_order(a,k)->val;\n  }\n\n  void dump(Node* a,typename vector<T>::iterator\
    \ it){\n    if(!count(a)) return;\n    if(a->rev){\n      if(a->l) toggle(a->l);\n\
    \      if(a->r) toggle(a->r);\n      a->rev=false;\n    }\n    dump(a->l,it);\n\
    \    *(it+count(a->l))=a->val;\n    dump(a->r,it+count(a->l)+1);\n  }\n\n  vector<T>\
    \ dump(Node* a){\n    vector<T> vs(count(a));\n    dump(a,vs.begin());\n    return\
    \ vs;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - bbst/rbst/basic/base.cpp
  isVerificationFile: false
  path: bbst/rbst/basic/array.cpp
  requiredBy:
  - bbst/rbst/persistent/array.cpp
  timestamp: '2020-10-02 16:55:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0438.test.cpp
  - test/aoj/2890.test.cpp
  - test/yosupo/persistent_queue.test.cpp
documentation_of: bbst/rbst/basic/array.cpp
layout: document
redirect_from:
- /library/bbst/rbst/basic/array.cpp
- /library/bbst/rbst/basic/array.cpp.html
title: bbst/rbst/basic/array.cpp
---
