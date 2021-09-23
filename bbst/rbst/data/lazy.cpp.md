---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/impl/persistent.cpp
    title: bbst/rbst/impl/persistent.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.bbst.test.cpp
    title: test/aoj/DSL_2_F.bbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.bbst.test.cpp
    title: test/aoj/DSL_2_G.bbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H.bbst.test.cpp
    title: test/aoj/DSL_2_H.bbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I.bbst.test.cpp
    title: test/aoj/DSL_2_I.bbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
    title: test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"bbst/rbst/data/lazy.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T, typename\
    \ E,\n         typename F, typename G, typename H, typename Flip>\nstruct Lazy{\n\
    \  F f;\n  G g;\n  H h;\n  Flip flip;\n  T ti;\n  E ei;\n\n  Lazy(F f,G g,H h,Flip\
    \ flip,T ti,E ei):\n    f(f),g(g),h(h),flip(flip),ti(ti),ei(ei){}\n\n  struct\
    \ Node{\n    Node *l,*r,*p;\n    size_t cnt;\n    bool rev;\n    T val,dat;\n\
    \    E laz;\n    Node(T val,E laz):\n      cnt(1),rev(0),val(val),dat(val),laz(laz){l=r=p=nullptr;}\n\
    \  };\n\n  static inline size_t count(const Node *t){\n    return t?t->cnt:0;\n\
    \  }\n\n  inline void toggle(Node *t){\n    swap(t->l,t->r);\n    t->val=flip(t->val);\n\
    \    t->dat=flip(t->dat);\n    t->rev^=1;\n  }\n\n  inline bool dirty(Node *t){\n\
    \    return t->rev or t->laz!=ei;\n  }\n\n  inline void propagate(Node *t,E v){\n\
    \    t->laz=h(t->laz,v);\n    t->val=g(t->val,v);\n    t->dat=g(t->dat,v);\n \
    \ }\n\n  inline Node* eval(Node* t){\n    if(t->rev){\n      if(t->l) toggle(t->l);\n\
    \      if(t->r) toggle(t->r);\n      t->rev=false;\n    }\n    if(t->laz!=ei){\n\
    \      if(t->l) propagate(t->l,t->laz);\n      if(t->r) propagate(t->r,t->laz);\n\
    \      t->laz=ei;\n    }\n    return t;\n  }\n\n  inline Node* pushup(Node *t){\n\
    \    t->cnt=count(t->l)+1+count(t->r);\n    t->dat=t->val;\n    if(t->l) t->dat=f(t->l->dat,t->dat);\n\
    \    if(t->r) t->dat=f(t->dat,t->r->dat);\n    return t;\n  }\n\n  inline T get_val(Node\
    \ *t){\n    assert(t);\n    return t->val;\n  }\n\n  inline T reflect(Node *t){\n\
    \    assert(t);\n    return t->dat;\n  }\n\n  void dump(typename vector<Node>::iterator\
    \ it,\n            const Node* t,bool rev,E laz){\n    if(!count(t)) return;\n\
    \n    Node *l=t->l,*r=t->r;\n    if(rev) swap(l,r);\n    rev^=t->rev;\n\n    dump(it,l,rev,h(laz,t->laz));\n\
    \    *(it+count(l))=Node(g(t->val,laz),ei);\n    dump(it+count(l)+1,r,rev,h(laz,t->laz));\n\
    \  }\n\n  vector<Node> dump(Node* t){\n    assert(t!=nullptr);\n    vector<Node>\
    \ vs(count(t),*t);\n    dump(vs.begin(),t,false,ei);\n    return vs;\n  }\n};\n\
    \n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename T, typename E,\n         typename\
    \ F, typename G, typename H, typename Flip>\nstruct Lazy{\n  F f;\n  G g;\n  H\
    \ h;\n  Flip flip;\n  T ti;\n  E ei;\n\n  Lazy(F f,G g,H h,Flip flip,T ti,E ei):\n\
    \    f(f),g(g),h(h),flip(flip),ti(ti),ei(ei){}\n\n  struct Node{\n    Node *l,*r,*p;\n\
    \    size_t cnt;\n    bool rev;\n    T val,dat;\n    E laz;\n    Node(T val,E\
    \ laz):\n      cnt(1),rev(0),val(val),dat(val),laz(laz){l=r=p=nullptr;}\n  };\n\
    \n  static inline size_t count(const Node *t){\n    return t?t->cnt:0;\n  }\n\n\
    \  inline void toggle(Node *t){\n    swap(t->l,t->r);\n    t->val=flip(t->val);\n\
    \    t->dat=flip(t->dat);\n    t->rev^=1;\n  }\n\n  inline bool dirty(Node *t){\n\
    \    return t->rev or t->laz!=ei;\n  }\n\n  inline void propagate(Node *t,E v){\n\
    \    t->laz=h(t->laz,v);\n    t->val=g(t->val,v);\n    t->dat=g(t->dat,v);\n \
    \ }\n\n  inline Node* eval(Node* t){\n    if(t->rev){\n      if(t->l) toggle(t->l);\n\
    \      if(t->r) toggle(t->r);\n      t->rev=false;\n    }\n    if(t->laz!=ei){\n\
    \      if(t->l) propagate(t->l,t->laz);\n      if(t->r) propagate(t->r,t->laz);\n\
    \      t->laz=ei;\n    }\n    return t;\n  }\n\n  inline Node* pushup(Node *t){\n\
    \    t->cnt=count(t->l)+1+count(t->r);\n    t->dat=t->val;\n    if(t->l) t->dat=f(t->l->dat,t->dat);\n\
    \    if(t->r) t->dat=f(t->dat,t->r->dat);\n    return t;\n  }\n\n  inline T get_val(Node\
    \ *t){\n    assert(t);\n    return t->val;\n  }\n\n  inline T reflect(Node *t){\n\
    \    assert(t);\n    return t->dat;\n  }\n\n  void dump(typename vector<Node>::iterator\
    \ it,\n            const Node* t,bool rev,E laz){\n    if(!count(t)) return;\n\
    \n    Node *l=t->l,*r=t->r;\n    if(rev) swap(l,r);\n    rev^=t->rev;\n\n    dump(it,l,rev,h(laz,t->laz));\n\
    \    *(it+count(l))=Node(g(t->val,laz),ei);\n    dump(it+count(l)+1,r,rev,h(laz,t->laz));\n\
    \  }\n\n  vector<Node> dump(Node* t){\n    assert(t!=nullptr);\n    vector<Node>\
    \ vs(count(t),*t);\n    dump(vs.begin(),t,false,ei);\n    return vs;\n  }\n};\n\
    \n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: bbst/rbst/data/lazy.cpp
  requiredBy:
  - bbst/rbst/impl/persistent.cpp
  timestamp: '2020-11-04 18:27:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_F.bbst.test.cpp
  - test/aoj/DSL_2_I.bbst.test.cpp
  - test/aoj/DSL_2_G.bbst.test.cpp
  - test/aoj/DSL_2_H.bbst.test.cpp
  - test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
documentation_of: bbst/rbst/data/lazy.cpp
layout: document
redirect_from:
- /library/bbst/rbst/data/lazy.cpp
- /library/bbst/rbst/data/lazy.cpp.html
title: bbst/rbst/data/lazy.cpp
---
