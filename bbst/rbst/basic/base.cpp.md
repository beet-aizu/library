---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/persistent/array.cpp
    title: bbst/rbst/persistent/array.cpp
  - icon: ':warning:'
    path: bbst/rbst/persistent/lazy.cpp
    title: bbst/rbst/persistent/lazy.cpp
  - icon: ':warning:'
    path: bbst/rbst/persistent/ushi.cpp
    title: bbst/rbst/persistent/ushi.cpp
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/basic/dual.cpp
    title: bbst/rbst/basic/dual.cpp
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/basic/array.cpp
    title: bbst/rbst/basic/array.cpp
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/basic/lazy.cpp
    title: bbst/rbst/basic/lazy.cpp
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/basic/ushi.cpp
    title: bbst/rbst/basic/ushi.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2890.test.cpp
    title: test/aoj/2890.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_E.bbst.test.cpp
    title: test/aoj/DSL_2_E.bbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I.bbst.test.cpp
    title: test/aoj/DSL_2_I.bbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_D.bbst.test.cpp
    title: test/aoj/DSL_2_D.bbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.bbst.test.cpp
    title: test/aoj/DSL_2_A.bbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.bbst.test.cpp
    title: test/aoj/DSL_2_G.bbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H.bbst.test.cpp
    title: test/aoj/DSL_2_H.bbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.bbst.test.cpp
    title: test/aoj/DSL_2_F.bbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1579.test.cpp
    title: test/aoj/1579.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1508.test.cpp
    title: test/aoj/1508.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_queue.test.cpp
    title: test/yosupo/persistent_queue.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"bbst/rbst/basic/base.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename Node, size_t\
    \ LIM>\nstruct BBSTBase{\n  using u32 = uint32_t;\n  u32 xor128(){\n    static\
    \ u32 x = 123456789;\n    static u32 y = 362436069;\n    static u32 z = 521288629;\n\
    \    static u32 w = 88675123;\n\n    u32 t = x ^ (x << 11);\n    x = y; y = z;\
    \ z = w;\n    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n  }\n\n  static array<Node,\
    \ LIM> pool;\n  size_t ptr;\n  BBSTBase():ptr(0){}\n\n  size_t count(const Node\
    \ *a){\n    return a?a->cnt:0;\n  }\n\n  inline Node* create(){\n    return &pool[ptr++];\n\
    \  }\n\n  inline Node* create(Node v){\n    return &(pool[ptr++]=v);\n  }\n\n\
    \  virtual void toggle(Node *a)=0;\n  virtual Node* eval(Node* a)=0;\n  virtual\
    \ Node* recalc(Node* a)=0;\n\n  Node* toggle(Node *a,size_t l,size_t r){\n   \
    \ auto s=split(a,l);\n    auto t=split(s.second,r-l);\n    auto u=eval(t.first);\n\
    \    toggle(u);\n    return merge(s.first,merge(u,t.second));\n  }\n\n  Node*\
    \ merge(Node* a,Node* b){\n    if(a==nullptr) return b;\n    if(b==nullptr) return\
    \ a;\n    if(xor128()%(count(a)+count(b))<count(a)){\n      a=eval(a);\n     \
    \ a->r=merge(a->r,b);\n      a->r->p=a;\n      return recalc(a);\n    }\n    b=eval(b);\n\
    \    b->l=merge(a,b->l);\n    b->l->p=b;\n    return recalc(b);\n  }\n\n  pair<Node*,\
    \ Node*> split(Node* a,size_t k){\n    if(a==nullptr) return make_pair(a,a);\n\
    \    a=eval(a);\n    if(k<=count(a->l)){\n      if(a->l) a->l->p=nullptr;\n  \
    \    auto s=split(a->l,k);\n      a->l=s.second;\n      if(a->l) a->l->p=a;\n\
    \      return make_pair(s.first,recalc(a));\n    }\n    if(a->r) a->r->p=nullptr;\n\
    \    auto s=split(a->r,k-(count(a->l)+1));\n    a->r=s.first;\n    if(a->r) a->r->p=a;\n\
    \    return make_pair(recalc(a),s.second);\n  }\n\n  Node* insert(Node *a,size_t\
    \ pos,Node v){\n    Node* b=create(v);\n    auto s=split(a,pos);\n    return a=merge(merge(s.first,b),s.second);\n\
    \  }\n\n  Node* erase(Node *a,size_t pos){\n    auto s=split(a,pos);\n    auto\
    \ t=split(s.second,1);\n    return merge(s.first,t.second);\n  }\n\n  Node* find_by_order(Node\
    \ *a,size_t k){\n    assert(k<count(a));\n    a=eval(a);\n    size_t num=count(a->l);\n\
    \    if(k<num) return find_by_order(a->l,k);\n    if(k>num) return find_by_order(a->r,k-(num+1));\n\
    \    return a;\n  }\n\n  inline bool is_right(Node* a){\n    return a->p&&a->p->r==a;\n\
    \  }\n\n  size_t order_of_key(Node* a){\n    size_t res=count(a->l);\n    while(a){\n\
    \      if(is_right(a)) res+=count(a->p->l)+1;\n      a=a->p;\n    }\n    return\
    \ res;\n  }\n\n  Node* build(size_t l,size_t r,const vector<Node> &vs){\n    if(l+1==r)\
    \ return create(vs[l]);\n    size_t m=(l+r)>>1;\n    return merge(build(l,m,vs),build(m,r,vs));\n\
    \  }\n\n  Node* build(const vector<Node> &vs){\n    return build(0,vs.size(),vs);\n\
    \  }\n};\ntemplate<typename Node, size_t LIM>\narray<Node, LIM> BBSTBase<Node,\
    \ LIM>::pool;\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename Node, size_t LIM>\nstruct BBSTBase{\n  using\
    \ u32 = uint32_t;\n  u32 xor128(){\n    static u32 x = 123456789;\n    static\
    \ u32 y = 362436069;\n    static u32 z = 521288629;\n    static u32 w = 88675123;\n\
    \n    u32 t = x ^ (x << 11);\n    x = y; y = z; z = w;\n    return w = (w ^ (w\
    \ >> 19)) ^ (t ^ (t >> 8));\n  }\n\n  static array<Node, LIM> pool;\n  size_t\
    \ ptr;\n  BBSTBase():ptr(0){}\n\n  size_t count(const Node *a){\n    return a?a->cnt:0;\n\
    \  }\n\n  inline Node* create(){\n    return &pool[ptr++];\n  }\n\n  inline Node*\
    \ create(Node v){\n    return &(pool[ptr++]=v);\n  }\n\n  virtual void toggle(Node\
    \ *a)=0;\n  virtual Node* eval(Node* a)=0;\n  virtual Node* recalc(Node* a)=0;\n\
    \n  Node* toggle(Node *a,size_t l,size_t r){\n    auto s=split(a,l);\n    auto\
    \ t=split(s.second,r-l);\n    auto u=eval(t.first);\n    toggle(u);\n    return\
    \ merge(s.first,merge(u,t.second));\n  }\n\n  Node* merge(Node* a,Node* b){\n\
    \    if(a==nullptr) return b;\n    if(b==nullptr) return a;\n    if(xor128()%(count(a)+count(b))<count(a)){\n\
    \      a=eval(a);\n      a->r=merge(a->r,b);\n      a->r->p=a;\n      return recalc(a);\n\
    \    }\n    b=eval(b);\n    b->l=merge(a,b->l);\n    b->l->p=b;\n    return recalc(b);\n\
    \  }\n\n  pair<Node*, Node*> split(Node* a,size_t k){\n    if(a==nullptr) return\
    \ make_pair(a,a);\n    a=eval(a);\n    if(k<=count(a->l)){\n      if(a->l) a->l->p=nullptr;\n\
    \      auto s=split(a->l,k);\n      a->l=s.second;\n      if(a->l) a->l->p=a;\n\
    \      return make_pair(s.first,recalc(a));\n    }\n    if(a->r) a->r->p=nullptr;\n\
    \    auto s=split(a->r,k-(count(a->l)+1));\n    a->r=s.first;\n    if(a->r) a->r->p=a;\n\
    \    return make_pair(recalc(a),s.second);\n  }\n\n  Node* insert(Node *a,size_t\
    \ pos,Node v){\n    Node* b=create(v);\n    auto s=split(a,pos);\n    return a=merge(merge(s.first,b),s.second);\n\
    \  }\n\n  Node* erase(Node *a,size_t pos){\n    auto s=split(a,pos);\n    auto\
    \ t=split(s.second,1);\n    return merge(s.first,t.second);\n  }\n\n  Node* find_by_order(Node\
    \ *a,size_t k){\n    assert(k<count(a));\n    a=eval(a);\n    size_t num=count(a->l);\n\
    \    if(k<num) return find_by_order(a->l,k);\n    if(k>num) return find_by_order(a->r,k-(num+1));\n\
    \    return a;\n  }\n\n  inline bool is_right(Node* a){\n    return a->p&&a->p->r==a;\n\
    \  }\n\n  size_t order_of_key(Node* a){\n    size_t res=count(a->l);\n    while(a){\n\
    \      if(is_right(a)) res+=count(a->p->l)+1;\n      a=a->p;\n    }\n    return\
    \ res;\n  }\n\n  Node* build(size_t l,size_t r,const vector<Node> &vs){\n    if(l+1==r)\
    \ return create(vs[l]);\n    size_t m=(l+r)>>1;\n    return merge(build(l,m,vs),build(m,r,vs));\n\
    \  }\n\n  Node* build(const vector<Node> &vs){\n    return build(0,vs.size(),vs);\n\
    \  }\n};\ntemplate<typename Node, size_t LIM>\narray<Node, LIM> BBSTBase<Node,\
    \ LIM>::pool;\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: bbst/rbst/basic/base.cpp
  requiredBy:
  - bbst/rbst/persistent/array.cpp
  - bbst/rbst/persistent/lazy.cpp
  - bbst/rbst/persistent/ushi.cpp
  - bbst/rbst/basic/dual.cpp
  - bbst/rbst/basic/array.cpp
  - bbst/rbst/basic/lazy.cpp
  - bbst/rbst/basic/ushi.cpp
  timestamp: '2020-03-22 15:37:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2890.test.cpp
  - test/aoj/DSL_2_E.bbst.test.cpp
  - test/aoj/DSL_2_I.bbst.test.cpp
  - test/aoj/DSL_2_D.bbst.test.cpp
  - test/aoj/DSL_2_A.bbst.test.cpp
  - test/aoj/DSL_2_G.bbst.test.cpp
  - test/aoj/DSL_2_H.bbst.test.cpp
  - test/aoj/DSL_2_F.bbst.test.cpp
  - test/aoj/1579.test.cpp
  - test/aoj/1508.test.cpp
  - test/yosupo/persistent_queue.test.cpp
documentation_of: bbst/rbst/basic/base.cpp
layout: document
redirect_from:
- /library/bbst/rbst/basic/base.cpp
- /library/bbst/rbst/basic/base.cpp.html
title: bbst/rbst/basic/base.cpp
---
