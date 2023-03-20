---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/impl/basic.cpp
    title: bbst/rbst/impl/basic.cpp
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/impl/persistent.cpp
    title: bbst/rbst/impl/persistent.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0437.test.cpp
    title: test/aoj/0437.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0438.test.cpp
    title: test find_by_order, order_of_key
  - icon: ':heavy_check_mark:'
    path: test/aoj/1508.test.cpp
    title: test/aoj/1508.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1579.test.cpp
    title: test/aoj/1579.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2890.test.cpp
    title: test order_of_key
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
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_queue.test.cpp
    title: test/yosupo/persistent_queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"bbst/rbst/rbst.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename Impl, typename Data,\
    \ typename Node, size_t LIM>\nstruct RBST{\n  using u32 = uint32_t;\n  u32 xor128(){\n\
    \    static u32 x = 123456789;\n    static u32 y = 362436069;\n    static u32\
    \ z = 521288629;\n    static u32 w = 88675123;\n\n    u32 t = x ^ (x << 11);\n\
    \    x = y; y = z; z = w;\n    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n\
    \  }\n\n  alignas(Node) static inline char pool[sizeof(Node)*LIM];\n  static inline\
    \ Node* ptr = (Node*)pool;\n  static inline size_t size;\n\n  template<typename...\
    \ Args>\n  inline Node* create(Args&&... args){\n    return new (ptr+size++) Node(std::forward<Args>(args)...);\n\
    \  }\n\n  inline size_t count(const Node *t){return Data::count(t);}\n\n  inline\
    \ Node* touch(Node *t){\n    return static_cast<Impl*>(this)->touch(t);\n  }\n\
    \n  inline void toggle(Node *t){\n    return static_cast<Impl*>(this)->toggle(t);\n\
    \  }\n\n  inline Node* pushup(Node *t){\n    return static_cast<Impl*>(this)->pushup(t);\n\
    \  }\n\n  Node* toggle(Node *a,size_t l,size_t r){\n    auto s=split(a,l);\n \
    \   auto t=split(s.second,r-l);\n    auto u=touch(t.first);\n    toggle(u);\n\
    \    return merge(s.first,merge(u,t.second));\n  }\n\n  Node* merge(Node* a,Node*\
    \ b){\n    if(a==nullptr) return b;\n    if(b==nullptr) return a;\n    if(xor128()%(count(a)+count(b))<count(a)){\n\
    \      a=touch(a);\n      a->r=merge(a->r,b);\n      a->r->p=a;\n      return\
    \ pushup(a);\n    }\n    b=touch(b);\n    b->l=merge(a,b->l);\n    b->l->p=b;\n\
    \    return pushup(b);\n  }\n\n  pair<Node*, Node*> split(Node* a,size_t k){\n\
    \    if(a==nullptr) return make_pair(a,a);\n    a=touch(a);\n    if(k<=count(a->l)){\n\
    \      if(a->l) a->l->p=nullptr;\n      auto s=split(a->l,k);\n      a->l=s.second;\n\
    \      if(a->l) a->l->p=a;\n      return make_pair(s.first,pushup(a));\n    }\n\
    \    if(a->r) a->r->p=nullptr;\n    auto s=split(a->r,k-(count(a->l)+1));\n  \
    \  a->r=s.first;\n    if(a->r) a->r->p=a;\n    return make_pair(pushup(a),s.second);\n\
    \  }\n\n  Node* insert(Node *a,size_t k,Node v){\n    Node* b=create(v);\n   \
    \ auto s=split(a,k);\n    return merge(merge(s.first,b),s.second);\n  }\n\n  Node*\
    \ erase(Node *a,size_t k){\n    assert(k<count(a));\n    auto s=split(a,k);\n\
    \    auto t=split(s.second,1);\n    return merge(s.first,t.second);\n  }\n\n \
    \ Node* find_by_order(Node *a,size_t k){\n    assert(k<count(a));\n    a=touch(a);\n\
    \    size_t num=count(a->l);\n    if(k<num) return find_by_order(a->l,k);\n  \
    \  if(k>num) return find_by_order(a->r,k-(num+1));\n    return a;\n  }\n\n  inline\
    \ bool is_right(Node* a){\n    return a->p and a->p->r==a;\n  }\n\n  size_t order_of_key(Node*\
    \ a){\n    size_t res=count(a->l);\n    while(a){\n      if(is_right(a)) res+=count(a->p->l)+1;\n\
    \      a=a->p;\n    }\n    return res;\n  }\n\n  Node* build(size_t l,size_t r,const\
    \ vector<Node> &vs){\n    if(l+1==r) return create(vs[l]);\n    size_t m=(l+r)>>1;\n\
    \    return merge(build(l,m,vs),build(m,r,vs));\n  }\n\n  Node* build(const vector<Node>\
    \ &vs){\n    return build(0,vs.size(),vs);\n  }\n\n  template<typename T>\n  Node*\
    \ set_val(Node *a,size_t k,T val){\n    assert(k<count(a));\n    a=touch(a);\n\
    \    size_t num=count(a->l);\n    if(k<num) a->l=set_val(a->l,k,val);\n    if(k>num)\
    \ a->r=set_val(a->r,k-(num+1),val);\n    if(k==num) a->val=val;\n    return pushup(a);\n\
    \  }\n\n  Node* get_val(Node *a,size_t k){\n    assert(k<count(a));\n    a=touch(a);\n\
    \    size_t num=count(a->l);\n    if(k<num) return get_val(a->l,k);\n    if(k>num)\
    \ return get_val(a->r,k-(num+1));\n    return a;\n  }\n\n  template<typename E>\n\
    \  Node* update(Node *a,size_t l,size_t r,E v){\n    auto s=split(a,l);\n    auto\
    \ t=split(s.second,r-l);\n    auto u=touch(t.first);\n    static_cast<Impl*>(this)->propagate(u,v);\n\
    \    return merge(s.first,merge(u,t.second));\n  }\n\n  decltype(auto) query(Node\
    \ *&a,size_t l,size_t r){\n    auto s=split(a,l);\n    auto t=split(s.second,r-l);\n\
    \    auto u=t.first;\n    auto res=static_cast<Impl*>(this)->query(u);\n    a=merge(s.first,merge(u,t.second));\n\
    \    return res;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE\
    \ HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename Impl, typename Data, typename Node,\
    \ size_t LIM>\nstruct RBST{\n  using u32 = uint32_t;\n  u32 xor128(){\n    static\
    \ u32 x = 123456789;\n    static u32 y = 362436069;\n    static u32 z = 521288629;\n\
    \    static u32 w = 88675123;\n\n    u32 t = x ^ (x << 11);\n    x = y; y = z;\
    \ z = w;\n    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n  }\n\n  alignas(Node)\
    \ static inline char pool[sizeof(Node)*LIM];\n  static inline Node* ptr = (Node*)pool;\n\
    \  static inline size_t size;\n\n  template<typename... Args>\n  inline Node*\
    \ create(Args&&... args){\n    return new (ptr+size++) Node(std::forward<Args>(args)...);\n\
    \  }\n\n  inline size_t count(const Node *t){return Data::count(t);}\n\n  inline\
    \ Node* touch(Node *t){\n    return static_cast<Impl*>(this)->touch(t);\n  }\n\
    \n  inline void toggle(Node *t){\n    return static_cast<Impl*>(this)->toggle(t);\n\
    \  }\n\n  inline Node* pushup(Node *t){\n    return static_cast<Impl*>(this)->pushup(t);\n\
    \  }\n\n  Node* toggle(Node *a,size_t l,size_t r){\n    auto s=split(a,l);\n \
    \   auto t=split(s.second,r-l);\n    auto u=touch(t.first);\n    toggle(u);\n\
    \    return merge(s.first,merge(u,t.second));\n  }\n\n  Node* merge(Node* a,Node*\
    \ b){\n    if(a==nullptr) return b;\n    if(b==nullptr) return a;\n    if(xor128()%(count(a)+count(b))<count(a)){\n\
    \      a=touch(a);\n      a->r=merge(a->r,b);\n      a->r->p=a;\n      return\
    \ pushup(a);\n    }\n    b=touch(b);\n    b->l=merge(a,b->l);\n    b->l->p=b;\n\
    \    return pushup(b);\n  }\n\n  pair<Node*, Node*> split(Node* a,size_t k){\n\
    \    if(a==nullptr) return make_pair(a,a);\n    a=touch(a);\n    if(k<=count(a->l)){\n\
    \      if(a->l) a->l->p=nullptr;\n      auto s=split(a->l,k);\n      a->l=s.second;\n\
    \      if(a->l) a->l->p=a;\n      return make_pair(s.first,pushup(a));\n    }\n\
    \    if(a->r) a->r->p=nullptr;\n    auto s=split(a->r,k-(count(a->l)+1));\n  \
    \  a->r=s.first;\n    if(a->r) a->r->p=a;\n    return make_pair(pushup(a),s.second);\n\
    \  }\n\n  Node* insert(Node *a,size_t k,Node v){\n    Node* b=create(v);\n   \
    \ auto s=split(a,k);\n    return merge(merge(s.first,b),s.second);\n  }\n\n  Node*\
    \ erase(Node *a,size_t k){\n    assert(k<count(a));\n    auto s=split(a,k);\n\
    \    auto t=split(s.second,1);\n    return merge(s.first,t.second);\n  }\n\n \
    \ Node* find_by_order(Node *a,size_t k){\n    assert(k<count(a));\n    a=touch(a);\n\
    \    size_t num=count(a->l);\n    if(k<num) return find_by_order(a->l,k);\n  \
    \  if(k>num) return find_by_order(a->r,k-(num+1));\n    return a;\n  }\n\n  inline\
    \ bool is_right(Node* a){\n    return a->p and a->p->r==a;\n  }\n\n  size_t order_of_key(Node*\
    \ a){\n    size_t res=count(a->l);\n    while(a){\n      if(is_right(a)) res+=count(a->p->l)+1;\n\
    \      a=a->p;\n    }\n    return res;\n  }\n\n  Node* build(size_t l,size_t r,const\
    \ vector<Node> &vs){\n    if(l+1==r) return create(vs[l]);\n    size_t m=(l+r)>>1;\n\
    \    return merge(build(l,m,vs),build(m,r,vs));\n  }\n\n  Node* build(const vector<Node>\
    \ &vs){\n    return build(0,vs.size(),vs);\n  }\n\n  template<typename T>\n  Node*\
    \ set_val(Node *a,size_t k,T val){\n    assert(k<count(a));\n    a=touch(a);\n\
    \    size_t num=count(a->l);\n    if(k<num) a->l=set_val(a->l,k,val);\n    if(k>num)\
    \ a->r=set_val(a->r,k-(num+1),val);\n    if(k==num) a->val=val;\n    return pushup(a);\n\
    \  }\n\n  Node* get_val(Node *a,size_t k){\n    assert(k<count(a));\n    a=touch(a);\n\
    \    size_t num=count(a->l);\n    if(k<num) return get_val(a->l,k);\n    if(k>num)\
    \ return get_val(a->r,k-(num+1));\n    return a;\n  }\n\n  template<typename E>\n\
    \  Node* update(Node *a,size_t l,size_t r,E v){\n    auto s=split(a,l);\n    auto\
    \ t=split(s.second,r-l);\n    auto u=touch(t.first);\n    static_cast<Impl*>(this)->propagate(u,v);\n\
    \    return merge(s.first,merge(u,t.second));\n  }\n\n  decltype(auto) query(Node\
    \ *&a,size_t l,size_t r){\n    auto s=split(a,l);\n    auto t=split(s.second,r-l);\n\
    \    auto u=t.first;\n    auto res=static_cast<Impl*>(this)->query(u);\n    a=merge(s.first,merge(u,t.second));\n\
    \    return res;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE\
    \ HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: bbst/rbst/rbst.cpp
  requiredBy:
  - bbst/rbst/impl/persistent.cpp
  - bbst/rbst/impl/basic.cpp
  timestamp: '2020-11-04 17:54:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
  - test/yosupo/persistent_queue.test.cpp
  - test/aoj/2890.test.cpp
  - test/aoj/DSL_2_I.bbst.test.cpp
  - test/aoj/1579.test.cpp
  - test/aoj/0437.test.cpp
  - test/aoj/0438.test.cpp
  - test/aoj/1508.test.cpp
  - test/aoj/DSL_2_H.bbst.test.cpp
  - test/aoj/DSL_2_G.bbst.test.cpp
  - test/aoj/DSL_2_F.bbst.test.cpp
documentation_of: bbst/rbst/rbst.cpp
layout: document
redirect_from:
- /library/bbst/rbst/rbst.cpp
- /library/bbst/rbst/rbst.cpp.html
title: bbst/rbst/rbst.cpp
---
