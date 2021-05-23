---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/impl/persistent.cpp
    title: bbst/rbst/impl/persistent.cpp
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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"bbst/rbst/data/array.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct Array{\n\
    \  struct Node{\n    Node *l,*r,*p;\n    size_t cnt;\n    bool rev;\n    T val;\n\
    \    Node(T val):\n      cnt(1),rev(0),val(val){l=r=p=nullptr;}\n  };\n\n  static\
    \ inline size_t count(const Node *t){\n    return t?t->cnt:0;\n  }\n\n  inline\
    \ void toggle(Node *t){\n    swap(t->l,t->r);\n    t->rev^=1;\n  }\n\n  inline\
    \ bool dirty(Node *t){\n    return t->rev;\n  }\n\n  inline Node* eval(Node* t){\n\
    \    if(t->rev){\n      if(t->l) toggle(t->l);\n      if(t->r) toggle(t->r);\n\
    \      t->rev=false;\n    }\n    return t;\n  }\n\n  inline Node* pushup(Node\
    \ *t){\n    t->cnt=count(t->l)+1+count(t->r);\n    return t;\n  }\n\n  inline\
    \ T get_val(Node *t){\n    assert(t);\n    return t->val;\n  }\n\n  void dump(typename\
    \ vector<Node>::iterator it,Node* const t,bool rev){\n    if(!count(t)) return;\n\
    \n    Node *l=t->l,*r=t->r;\n    if(rev) swap(l,r);\n    rev^=t->rev;\n\n    dump(it,l,rev);\n\
    \    *(it+count(l))=Node(t->val);\n    dump(it+count(l)+1,r,rev);\n  }\n\n  vector<Node>\
    \ dump(Node* t){\n    assert(t!=nullptr);\n    vector<Node> vs(count(t),*t);\n\
    \    dump(vs.begin(),t,false);\n    return vs;\n  }\n};\n//END CUT HERE\n#ifndef\
    \ call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct Array{\n  struct Node{\n\
    \    Node *l,*r,*p;\n    size_t cnt;\n    bool rev;\n    T val;\n    Node(T val):\n\
    \      cnt(1),rev(0),val(val){l=r=p=nullptr;}\n  };\n\n  static inline size_t\
    \ count(const Node *t){\n    return t?t->cnt:0;\n  }\n\n  inline void toggle(Node\
    \ *t){\n    swap(t->l,t->r);\n    t->rev^=1;\n  }\n\n  inline bool dirty(Node\
    \ *t){\n    return t->rev;\n  }\n\n  inline Node* eval(Node* t){\n    if(t->rev){\n\
    \      if(t->l) toggle(t->l);\n      if(t->r) toggle(t->r);\n      t->rev=false;\n\
    \    }\n    return t;\n  }\n\n  inline Node* pushup(Node *t){\n    t->cnt=count(t->l)+1+count(t->r);\n\
    \    return t;\n  }\n\n  inline T get_val(Node *t){\n    assert(t);\n    return\
    \ t->val;\n  }\n\n  void dump(typename vector<Node>::iterator it,Node* const t,bool\
    \ rev){\n    if(!count(t)) return;\n\n    Node *l=t->l,*r=t->r;\n    if(rev) swap(l,r);\n\
    \    rev^=t->rev;\n\n    dump(it,l,rev);\n    *(it+count(l))=Node(t->val);\n \
    \   dump(it+count(l)+1,r,rev);\n  }\n\n  vector<Node> dump(Node* t){\n    assert(t!=nullptr);\n\
    \    vector<Node> vs(count(t),*t);\n    dump(vs.begin(),t,false);\n    return\
    \ vs;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: bbst/rbst/data/array.cpp
  requiredBy:
  - bbst/rbst/impl/persistent.cpp
  timestamp: '2020-11-04 18:27:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/persistent_queue.test.cpp
  - test/aoj/2890.test.cpp
  - test/aoj/0438.test.cpp
documentation_of: bbst/rbst/data/array.cpp
layout: document
redirect_from:
- /library/bbst/rbst/data/array.cpp
- /library/bbst/rbst/data/array.cpp.html
title: bbst/rbst/data/array.cpp
---
