---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0437.test.cpp
    title: test/aoj/0437.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1508.test.cpp
    title: test/aoj/1508.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"bbst/rbst/data/ushi.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T, typename\
    \ F, typename Flip>\nstruct Ushi{\n  F f;\n  Flip flip;\n  T ti;\n\n  Ushi(F f,Flip\
    \ flip,T ti):f(f),flip(flip),ti(ti){}\n\n  struct Node{\n    Node *l,*r,*p;\n\
    \    size_t cnt;\n    bool rev;\n    T val,dat;\n    Node(T val):\n      cnt(1),rev(0),val(val),dat(val){l=r=p=nullptr;}\n\
    \  };\n\n  static inline size_t count(const Node *t){\n    return t?t->cnt:0;\n\
    \  }\n\n  inline void toggle(Node *t){\n    swap(t->l,t->r);\n    t->val=flip(t->val);\n\
    \    t->dat=flip(t->dat);\n    t->rev^=1;\n  }\n\n  inline bool dirty(Node *t){\n\
    \    return t->rev;\n  }\n\n  inline Node* eval(Node* t){\n    if(t->rev){\n \
    \     if(t->l) toggle(t->l);\n      if(t->r) toggle(t->r);\n      t->rev=false;\n\
    \    }\n    return t;\n  }\n\n  inline Node* pushup(Node *t){\n    t->cnt=count(t->l)+1+count(t->r);\n\
    \    t->dat=t->val;\n    if(t->l) t->dat=f(t->l->dat,t->dat);\n    if(t->r) t->dat=f(t->dat,t->r->dat);\n\
    \    return t;\n  }\n\n  inline T get_val(Node *t){\n    assert(t);\n    return\
    \ t->val;\n  }\n\n  inline T reflect(Node *t){\n    assert(t);\n    return t->dat;\n\
    \  }\n\n  void dump(typename vector<Node>::iterator it,Node* const t,bool rev){\n\
    \    if(!count(t)) return;\n\n    Node *l=t->l,*r=t->r;\n    if(rev) swap(l,r);\n\
    \    rev^=t->rev;\n\n    dump(it,l,rev);\n    *(it+count(l))=Node(t->val);\n \
    \   dump(it+count(l)+1,r,rev);\n  }\n\n  vector<Node> dump(Node* t){\n    assert(t!=nullptr);\n\
    \    vector<Node> vs(count(t),*t);\n    dump(vs.begin(),t,false);\n    return\
    \ vs;\n  }\n};\n\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename T, typename F, typename Flip>\nstruct\
    \ Ushi{\n  F f;\n  Flip flip;\n  T ti;\n\n  Ushi(F f,Flip flip,T ti):f(f),flip(flip),ti(ti){}\n\
    \n  struct Node{\n    Node *l,*r,*p;\n    size_t cnt;\n    bool rev;\n    T val,dat;\n\
    \    Node(T val):\n      cnt(1),rev(0),val(val),dat(val){l=r=p=nullptr;}\n  };\n\
    \n  static inline size_t count(const Node *t){\n    return t?t->cnt:0;\n  }\n\n\
    \  inline void toggle(Node *t){\n    swap(t->l,t->r);\n    t->val=flip(t->val);\n\
    \    t->dat=flip(t->dat);\n    t->rev^=1;\n  }\n\n  inline bool dirty(Node *t){\n\
    \    return t->rev;\n  }\n\n  inline Node* eval(Node* t){\n    if(t->rev){\n \
    \     if(t->l) toggle(t->l);\n      if(t->r) toggle(t->r);\n      t->rev=false;\n\
    \    }\n    return t;\n  }\n\n  inline Node* pushup(Node *t){\n    t->cnt=count(t->l)+1+count(t->r);\n\
    \    t->dat=t->val;\n    if(t->l) t->dat=f(t->l->dat,t->dat);\n    if(t->r) t->dat=f(t->dat,t->r->dat);\n\
    \    return t;\n  }\n\n  inline T get_val(Node *t){\n    assert(t);\n    return\
    \ t->val;\n  }\n\n  inline T reflect(Node *t){\n    assert(t);\n    return t->dat;\n\
    \  }\n\n  void dump(typename vector<Node>::iterator it,Node* const t,bool rev){\n\
    \    if(!count(t)) return;\n\n    Node *l=t->l,*r=t->r;\n    if(rev) swap(l,r);\n\
    \    rev^=t->rev;\n\n    dump(it,l,rev);\n    *(it+count(l))=Node(t->val);\n \
    \   dump(it+count(l)+1,r,rev);\n  }\n\n  vector<Node> dump(Node* t){\n    assert(t!=nullptr);\n\
    \    vector<Node> vs(count(t),*t);\n    dump(vs.begin(),t,false);\n    return\
    \ vs;\n  }\n};\n\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: bbst/rbst/data/ushi.cpp
  requiredBy: []
  timestamp: '2020-11-04 18:27:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1508.test.cpp
  - test/aoj/0437.test.cpp
documentation_of: bbst/rbst/data/ushi.cpp
layout: document
redirect_from:
- /library/bbst/rbst/data/ushi.cpp
- /library/bbst/rbst/data/ushi.cpp.html
title: bbst/rbst/data/ushi.cpp
---
