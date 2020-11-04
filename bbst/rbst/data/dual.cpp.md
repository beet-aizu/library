---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1579.test.cpp
    title: test/aoj/1579.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"bbst/rbst/data/dual.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename E, typename\
    \ H>\nstruct Dual{\n  struct Node{\n    Node *l,*r,*p;\n    size_t cnt;\n    bool\
    \ rev;\n    E val,laz;\n    Node(E val):\n      cnt(1),rev(0),val(val),laz(val){l=r=p=nullptr;}\n\
    \  };\n\n  H h;\n  E ei;\n  Dual(H h,E ei):h(h),ei(ei){}\n\n  static inline size_t\
    \ count(const Node *t){\n    return t?t->cnt:0;\n  }\n\n  inline void toggle(Node\
    \ *t){\n    swap(t->l,t->r);\n    t->rev^=1;\n  }\n\n  inline void propagate(Node\
    \ *t,E x){\n    t->val=h(t->val,x);\n    t->laz=h(t->laz,x);\n  }\n\n  inline\
    \ bool dirty(Node *t){\n    return t->rev or t->laz!=ei;\n  }\n\n  inline Node*\
    \ eval(Node* t){\n    if(t->rev){\n      if(t->l) toggle(t->l);\n      if(t->r)\
    \ toggle(t->r);\n      t->rev=false;\n    }\n    if(t->laz!=ei){\n      if(t->l)\
    \ propagate(t->l,t->laz);\n      if(t->r) propagate(t->r,t->laz);\n      t->laz=ei;\n\
    \    }\n    return t;\n  }\n\n  inline Node* pushup(Node *t){\n    t->cnt=count(t->l)+1+count(t->r);\n\
    \    return t;\n  }\n\n  inline E get_val(Node *t){\n    assert(t);\n    return\
    \ t->val;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename E, typename H>\nstruct Dual{\n  struct\
    \ Node{\n    Node *l,*r,*p;\n    size_t cnt;\n    bool rev;\n    E val,laz;\n\
    \    Node(E val):\n      cnt(1),rev(0),val(val),laz(val){l=r=p=nullptr;}\n  };\n\
    \n  H h;\n  E ei;\n  Dual(H h,E ei):h(h),ei(ei){}\n\n  static inline size_t count(const\
    \ Node *t){\n    return t?t->cnt:0;\n  }\n\n  inline void toggle(Node *t){\n \
    \   swap(t->l,t->r);\n    t->rev^=1;\n  }\n\n  inline void propagate(Node *t,E\
    \ x){\n    t->val=h(t->val,x);\n    t->laz=h(t->laz,x);\n  }\n\n  inline bool\
    \ dirty(Node *t){\n    return t->rev or t->laz!=ei;\n  }\n\n  inline Node* eval(Node*\
    \ t){\n    if(t->rev){\n      if(t->l) toggle(t->l);\n      if(t->r) toggle(t->r);\n\
    \      t->rev=false;\n    }\n    if(t->laz!=ei){\n      if(t->l) propagate(t->l,t->laz);\n\
    \      if(t->r) propagate(t->r,t->laz);\n      t->laz=ei;\n    }\n    return t;\n\
    \  }\n\n  inline Node* pushup(Node *t){\n    t->cnt=count(t->l)+1+count(t->r);\n\
    \    return t;\n  }\n\n  inline E get_val(Node *t){\n    assert(t);\n    return\
    \ t->val;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: bbst/rbst/data/dual.cpp
  requiredBy: []
  timestamp: '2020-11-04 18:27:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1579.test.cpp
documentation_of: bbst/rbst/data/dual.cpp
layout: document
redirect_from:
- /library/bbst/rbst/data/dual.cpp
- /library/bbst/rbst/data/dual.cpp.html
title: bbst/rbst/data/dual.cpp
---
