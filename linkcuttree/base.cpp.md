---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: linkcuttree/farthest.cpp
    title: linkcuttree/farthest.cpp
  - icon: ':heavy_check_mark:'
    path: linkcuttree/path.cpp
    title: linkcuttree/path.cpp
  - icon: ':heavy_check_mark:'
    path: linkcuttree/subtree.cpp
    title: linkcuttree/subtree.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0367.linkcuttree.test.cpp
    title: test/aoj/0367.linkcuttree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1595.linkcuttree.test.cpp
    title: test/aoj/1595.linkcuttree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2450.linkcuttree.test.cpp
    title: test/aoj/2450.linkcuttree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3120.test.cpp
    title: test/aoj/3120.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_A.linkcuttree.test.cpp
    title: test/aoj/GRL_5_A.linkcuttree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_D.linkcuttree.test.cpp
    title: test/aoj/GRL_5_D.linkcuttree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_E.linkcuttree.test.cpp
    title: test/aoj/GRL_5_E.linkcuttree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp
    title: test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
    title: test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
    title: test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca.linkcuttree.test.cpp
    title: test/yosupo/lca.linkcuttree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linkcuttree/base.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename Node, size_t LIM,\
    \ typename Impl>\nstruct LinkCutTreeBase{\n  alignas(Node) static char pool[sizeof(Node)\
    \ * LIM];\n  static Node* ptr;\n  static size_t size;\n\n  template<typename...\
    \ Args>\n  inline Node* create(Args&&... args){\n    return new (ptr+size++) Node(std::forward<Args>(args)...);\n\
    \  }\n\n  inline size_t idx(Node *t){return t-ptr;}\n  Node* operator[](size_t\
    \ k){return ptr+k;}\n\n  inline void toggle(Node *t){\n    static_cast<Impl*>(this)->toggle(t);\n\
    \  }\n\n  inline Node* eval(Node *t){\n    return static_cast<Impl*>(this)->eval(t);\n\
    \  }\n\n  inline void pushup(Node *t){\n    static_cast<Impl*>(this)->pushup(t);\n\
    \  }\n\n  inline Node* expose(Node *t){\n    return static_cast<Impl*>(this)->expose(t);\n\
    \  }\n\n  void rotR(Node *t){\n    Node *x=t->p,*y=x->p;\n    if((x->l=t->r))\
    \ t->r->p=x;\n    t->r=x;x->p=t;\n    pushup(x);pushup(t);\n    if((t->p=y)){\n\
    \      if(y->l==x) y->l=t;\n      if(y->r==x) y->r=t;\n      pushup(y);\n    }\n\
    \  }\n\n  void rotL(Node *t){\n    Node *x=t->p,*y=x->p;\n    if((x->r=t->l))\
    \ t->l->p=x;\n    t->l=x;x->p=t;\n    pushup(x);pushup(t);\n    if((t->p=y)){\n\
    \      if(y->l==x) y->l=t;\n      if(y->r==x) y->r=t;\n      pushup(y);\n    }\n\
    \  }\n\n  // for splay tree (not original tree)\n  bool is_root(Node *t){\n  \
    \  return !t->p or (t->p->l!=t and t->p->r!=t);\n  }\n\n  void splay(Node *t){\n\
    \    eval(t);\n    while(!is_root(t)){\n      Node *q=t->p;\n      if(is_root(q)){\n\
    \        eval(q);eval(t);\n        if(q->l==t) rotR(t);\n        else rotL(t);\n\
    \      }else{\n        auto *r=q->p;\n        eval(r);eval(q);eval(t);\n     \
    \   if(r->l==q){\n          if(q->l==t) rotR(q),rotR(t);\n          else rotL(t),rotR(t);\n\
    \        }else{\n          if(q->r==t) rotL(q),rotL(t);\n          else rotR(t),rotL(t);\n\
    \        }\n      }\n    }\n  }\n\n  // c must be root on LCT\n  void link(Node\
    \ *par,Node *c){\n    expose(c);\n    expose(par);\n    c->p=par;\n    par->r=c;\n\
    \    pushup(par);\n  }\n\n  void cut(Node *c){\n    expose(c);\n    Node *par=c->l;\n\
    \    c->l=nullptr;\n    pushup(c);\n    par->p=nullptr;\n  }\n\n  void evert(Node\
    \ *t){\n    expose(t);\n    toggle(t);\n    eval(t);\n  }\n\n  Node *parent(Node\
    \ *t){\n    expose(t);\n    if(!(t->l)) return nullptr;\n    t=eval(t->l);\n \
    \   while(t->r) t=eval(t->r);\n    splay(t);\n    return t;\n  }\n\n  Node *root(Node\
    \ *t){\n    expose(t);\n    while(t->l) t=eval(t->l);\n    splay(t);\n    return\
    \ t;\n  }\n\n  bool is_connected(Node *a,Node *b){\n    return root(a)==root(b);\n\
    \  }\n\n  Node *lca(Node *a,Node *b){\n    expose(a);\n    return expose(b);\n\
    \  }\n};\ntemplate<typename Node, size_t LIM, typename Impl>\nalignas(Node) char\
    \ LinkCutTreeBase<Node, LIM, Impl>::pool[];\ntemplate<typename Node, size_t LIM,\
    \ typename Impl>\nNode* LinkCutTreeBase<Node, LIM, Impl>::ptr=\n  (Node*)LinkCutTreeBase<Node,\
    \ LIM, Impl>::pool;\ntemplate<typename Node, size_t LIM, typename Impl>\nsize_t\
    \ LinkCutTreeBase<Node, LIM, Impl>::size=0;\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename Node, size_t LIM, typename Impl>\n\
    struct LinkCutTreeBase{\n  alignas(Node) static char pool[sizeof(Node) * LIM];\n\
    \  static Node* ptr;\n  static size_t size;\n\n  template<typename... Args>\n\
    \  inline Node* create(Args&&... args){\n    return new (ptr+size++) Node(std::forward<Args>(args)...);\n\
    \  }\n\n  inline size_t idx(Node *t){return t-ptr;}\n  Node* operator[](size_t\
    \ k){return ptr+k;}\n\n  inline void toggle(Node *t){\n    static_cast<Impl*>(this)->toggle(t);\n\
    \  }\n\n  inline Node* eval(Node *t){\n    return static_cast<Impl*>(this)->eval(t);\n\
    \  }\n\n  inline void pushup(Node *t){\n    static_cast<Impl*>(this)->pushup(t);\n\
    \  }\n\n  inline Node* expose(Node *t){\n    return static_cast<Impl*>(this)->expose(t);\n\
    \  }\n\n  void rotR(Node *t){\n    Node *x=t->p,*y=x->p;\n    if((x->l=t->r))\
    \ t->r->p=x;\n    t->r=x;x->p=t;\n    pushup(x);pushup(t);\n    if((t->p=y)){\n\
    \      if(y->l==x) y->l=t;\n      if(y->r==x) y->r=t;\n      pushup(y);\n    }\n\
    \  }\n\n  void rotL(Node *t){\n    Node *x=t->p,*y=x->p;\n    if((x->r=t->l))\
    \ t->l->p=x;\n    t->l=x;x->p=t;\n    pushup(x);pushup(t);\n    if((t->p=y)){\n\
    \      if(y->l==x) y->l=t;\n      if(y->r==x) y->r=t;\n      pushup(y);\n    }\n\
    \  }\n\n  // for splay tree (not original tree)\n  bool is_root(Node *t){\n  \
    \  return !t->p or (t->p->l!=t and t->p->r!=t);\n  }\n\n  void splay(Node *t){\n\
    \    eval(t);\n    while(!is_root(t)){\n      Node *q=t->p;\n      if(is_root(q)){\n\
    \        eval(q);eval(t);\n        if(q->l==t) rotR(t);\n        else rotL(t);\n\
    \      }else{\n        auto *r=q->p;\n        eval(r);eval(q);eval(t);\n     \
    \   if(r->l==q){\n          if(q->l==t) rotR(q),rotR(t);\n          else rotL(t),rotR(t);\n\
    \        }else{\n          if(q->r==t) rotL(q),rotL(t);\n          else rotR(t),rotL(t);\n\
    \        }\n      }\n    }\n  }\n\n  // c must be root on LCT\n  void link(Node\
    \ *par,Node *c){\n    expose(c);\n    expose(par);\n    c->p=par;\n    par->r=c;\n\
    \    pushup(par);\n  }\n\n  void cut(Node *c){\n    expose(c);\n    Node *par=c->l;\n\
    \    c->l=nullptr;\n    pushup(c);\n    par->p=nullptr;\n  }\n\n  void evert(Node\
    \ *t){\n    expose(t);\n    toggle(t);\n    eval(t);\n  }\n\n  Node *parent(Node\
    \ *t){\n    expose(t);\n    if(!(t->l)) return nullptr;\n    t=eval(t->l);\n \
    \   while(t->r) t=eval(t->r);\n    splay(t);\n    return t;\n  }\n\n  Node *root(Node\
    \ *t){\n    expose(t);\n    while(t->l) t=eval(t->l);\n    splay(t);\n    return\
    \ t;\n  }\n\n  bool is_connected(Node *a,Node *b){\n    return root(a)==root(b);\n\
    \  }\n\n  Node *lca(Node *a,Node *b){\n    expose(a);\n    return expose(b);\n\
    \  }\n};\ntemplate<typename Node, size_t LIM, typename Impl>\nalignas(Node) char\
    \ LinkCutTreeBase<Node, LIM, Impl>::pool[];\ntemplate<typename Node, size_t LIM,\
    \ typename Impl>\nNode* LinkCutTreeBase<Node, LIM, Impl>::ptr=\n  (Node*)LinkCutTreeBase<Node,\
    \ LIM, Impl>::pool;\ntemplate<typename Node, size_t LIM, typename Impl>\nsize_t\
    \ LinkCutTreeBase<Node, LIM, Impl>::size=0;\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: linkcuttree/base.cpp
  requiredBy:
  - linkcuttree/subtree.cpp
  - linkcuttree/path.cpp
  - linkcuttree/farthest.cpp
  timestamp: '2020-10-28 18:43:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
  - test/yosupo/lca.linkcuttree.test.cpp
  - test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
  - test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp
  - test/aoj/1595.linkcuttree.test.cpp
  - test/aoj/0367.linkcuttree.test.cpp
  - test/aoj/GRL_5_E.linkcuttree.test.cpp
  - test/aoj/3120.test.cpp
  - test/aoj/GRL_5_A.linkcuttree.test.cpp
  - test/aoj/GRL_5_D.linkcuttree.test.cpp
  - test/aoj/2450.linkcuttree.test.cpp
documentation_of: linkcuttree/base.cpp
layout: document
redirect_from:
- /library/linkcuttree/base.cpp
- /library/linkcuttree/base.cpp.html
title: linkcuttree/base.cpp
---
