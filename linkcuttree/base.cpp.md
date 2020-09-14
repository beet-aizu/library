---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"linkcuttree/base.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename Node, size_t LIM>\n\
    struct LinkCutTreeBase{\n  static array<Node, LIM> pool;\n  size_t ptr;\n\n  LinkCutTreeBase():ptr(0){}\n\
    \n  inline Node* create(){\n    return &pool[ptr++];\n  }\n\n  inline Node* create(Node\
    \ v){\n    return &(pool[ptr++]=v);\n  }\n\n  inline size_t idx(Node *t){\n  \
    \  return t-&pool[0];\n  }\n\n  Node* operator[](size_t k){\n    return &(pool[k]);\n\
    \  }\n\n  virtual void toggle(Node *t) = 0;\n  virtual Node* eval(Node *t) = 0;\n\
    \  virtual void pushup(Node *t) = 0;\n\n  void rotR(Node *t){\n    Node *x=t->p,*y=x->p;\n\
    \    if((x->l=t->r)) t->r->p=x;\n    t->r=x;x->p=t;\n    pushup(x);pushup(t);\n\
    \    if((t->p=y)){\n      if(y->l==x) y->l=t;\n      if(y->r==x) y->r=t;\n   \
    \   pushup(y);\n    }\n  }\n\n  void rotL(Node *t){\n    Node *x=t->p,*y=x->p;\n\
    \    if((x->r=t->l)) t->l->p=x;\n    t->l=x;x->p=t;\n    pushup(x);pushup(t);\n\
    \    if((t->p=y)){\n      if(y->l==x) y->l=t;\n      if(y->r==x) y->r=t;\n   \
    \   pushup(y);\n    }\n  }\n\n  // for splay tree (not original tree)\n  bool\
    \ is_root(Node *t){\n    return !t->p||(t->p->l!=t&&t->p->r!=t);\n  }\n\n  void\
    \ splay(Node *t){\n    eval(t);\n    while(!is_root(t)){\n      Node *q=t->p;\n\
    \      if(is_root(q)){\n        eval(q);eval(t);\n        if(q->l==t) rotR(t);\n\
    \        else rotL(t);\n      }else{\n        auto *r=q->p;\n        eval(r);eval(q);eval(t);\n\
    \        if(r->l==q){\n          if(q->l==t) rotR(q),rotR(t);\n          else\
    \ rotL(t),rotR(t);\n        }else{\n          if(q->r==t) rotL(q),rotL(t);\n \
    \         else rotR(t),rotL(t);\n        }\n      }\n    }\n  }\n\n  virtual Node*\
    \ expose(Node *t){\n    Node *rp=nullptr;\n    for(Node *c=t;c;c=c->p){\n    \
    \  splay(c);\n      c->r=rp;\n      pushup(c);\n      rp=c;\n    }\n    splay(t);\n\
    \    return rp;\n  }\n\n  // c must be root on LCT\n  void link(Node *par,Node\
    \ *c){\n    expose(c);\n    expose(par);\n    c->p=par;\n    par->r=c;\n    pushup(par);\n\
    \  }\n\n  void cut(Node *c){\n    expose(c);\n    Node *par=c->l;\n    c->l=nullptr;\n\
    \    pushup(c);\n    par->p=nullptr;\n  }\n\n  void evert(Node *t){\n    expose(t);\n\
    \    toggle(t);\n    eval(t);\n  }\n\n  Node *parent(Node *t){\n    expose(t);\n\
    \    if(!(t->l)) return nullptr;\n    t=eval(t->l);\n    while(t->r) t=eval(t->r);\n\
    \    splay(t);\n    return t;\n  }\n\n  Node *root(Node *t){\n    expose(t);\n\
    \    while(t->l) t=eval(t->l);\n    splay(t);\n    return t;\n  }\n\n  bool is_connected(Node\
    \ *a,Node *b){\n    return root(a)==root(b);\n  }\n\n  Node *lca(Node *a,Node\
    \ *b){\n    expose(a);\n    return expose(b);\n  }\n};\ntemplate<typename Node,\
    \ size_t LIM>\narray<Node, LIM> LinkCutTreeBase<Node, LIM>::pool;\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename Node, size_t LIM>\nstruct LinkCutTreeBase{\n\
    \  static array<Node, LIM> pool;\n  size_t ptr;\n\n  LinkCutTreeBase():ptr(0){}\n\
    \n  inline Node* create(){\n    return &pool[ptr++];\n  }\n\n  inline Node* create(Node\
    \ v){\n    return &(pool[ptr++]=v);\n  }\n\n  inline size_t idx(Node *t){\n  \
    \  return t-&pool[0];\n  }\n\n  Node* operator[](size_t k){\n    return &(pool[k]);\n\
    \  }\n\n  virtual void toggle(Node *t) = 0;\n  virtual Node* eval(Node *t) = 0;\n\
    \  virtual void pushup(Node *t) = 0;\n\n  void rotR(Node *t){\n    Node *x=t->p,*y=x->p;\n\
    \    if((x->l=t->r)) t->r->p=x;\n    t->r=x;x->p=t;\n    pushup(x);pushup(t);\n\
    \    if((t->p=y)){\n      if(y->l==x) y->l=t;\n      if(y->r==x) y->r=t;\n   \
    \   pushup(y);\n    }\n  }\n\n  void rotL(Node *t){\n    Node *x=t->p,*y=x->p;\n\
    \    if((x->r=t->l)) t->l->p=x;\n    t->l=x;x->p=t;\n    pushup(x);pushup(t);\n\
    \    if((t->p=y)){\n      if(y->l==x) y->l=t;\n      if(y->r==x) y->r=t;\n   \
    \   pushup(y);\n    }\n  }\n\n  // for splay tree (not original tree)\n  bool\
    \ is_root(Node *t){\n    return !t->p||(t->p->l!=t&&t->p->r!=t);\n  }\n\n  void\
    \ splay(Node *t){\n    eval(t);\n    while(!is_root(t)){\n      Node *q=t->p;\n\
    \      if(is_root(q)){\n        eval(q);eval(t);\n        if(q->l==t) rotR(t);\n\
    \        else rotL(t);\n      }else{\n        auto *r=q->p;\n        eval(r);eval(q);eval(t);\n\
    \        if(r->l==q){\n          if(q->l==t) rotR(q),rotR(t);\n          else\
    \ rotL(t),rotR(t);\n        }else{\n          if(q->r==t) rotL(q),rotL(t);\n \
    \         else rotR(t),rotL(t);\n        }\n      }\n    }\n  }\n\n  virtual Node*\
    \ expose(Node *t){\n    Node *rp=nullptr;\n    for(Node *c=t;c;c=c->p){\n    \
    \  splay(c);\n      c->r=rp;\n      pushup(c);\n      rp=c;\n    }\n    splay(t);\n\
    \    return rp;\n  }\n\n  // c must be root on LCT\n  void link(Node *par,Node\
    \ *c){\n    expose(c);\n    expose(par);\n    c->p=par;\n    par->r=c;\n    pushup(par);\n\
    \  }\n\n  void cut(Node *c){\n    expose(c);\n    Node *par=c->l;\n    c->l=nullptr;\n\
    \    pushup(c);\n    par->p=nullptr;\n  }\n\n  void evert(Node *t){\n    expose(t);\n\
    \    toggle(t);\n    eval(t);\n  }\n\n  Node *parent(Node *t){\n    expose(t);\n\
    \    if(!(t->l)) return nullptr;\n    t=eval(t->l);\n    while(t->r) t=eval(t->r);\n\
    \    splay(t);\n    return t;\n  }\n\n  Node *root(Node *t){\n    expose(t);\n\
    \    while(t->l) t=eval(t->l);\n    splay(t);\n    return t;\n  }\n\n  bool is_connected(Node\
    \ *a,Node *b){\n    return root(a)==root(b);\n  }\n\n  Node *lca(Node *a,Node\
    \ *b){\n    expose(a);\n    return expose(b);\n  }\n};\ntemplate<typename Node,\
    \ size_t LIM>\narray<Node, LIM> LinkCutTreeBase<Node, LIM>::pool;\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: linkcuttree/path.cpp
    title: linkcuttree/path.cpp
  - icon: ':heavy_check_mark:'
    path: linkcuttree/farthest.cpp
    title: linkcuttree/farthest.cpp
  - icon: ':heavy_check_mark:'
    path: linkcuttree/subtree.cpp
    title: linkcuttree/subtree.cpp
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1595.linkcuttree.test.cpp
    title: test/aoj/1595.linkcuttree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_D.linkcuttree.test.cpp
    title: test/aoj/GRL_5_D.linkcuttree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_A.linkcuttree.test.cpp
    title: test/aoj/GRL_5_A.linkcuttree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_E.linkcuttree.test.cpp
    title: test/aoj/GRL_5_E.linkcuttree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2450.linkcuttree.test.cpp
    title: test/aoj/2450.linkcuttree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3120.test.cpp
    title: test/aoj/3120.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0367.linkcuttree.test.cpp
    title: test/aoj/0367.linkcuttree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
    title: test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp
    title: test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp
    title: test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
    title: test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca.linkcuttree.test.cpp
    title: test/yosupo/lca.linkcuttree.test.cpp
  isVerificationFile: false
  path: linkcuttree/base.cpp
  requiredBy:
  - linkcuttree/path.cpp
  - linkcuttree/farthest.cpp
  - linkcuttree/subtree.cpp
  timestamp: '2020-07-16 18:11:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - test/aoj/1595.linkcuttree.test.cpp
  - test/aoj/GRL_5_D.linkcuttree.test.cpp
  - test/aoj/GRL_5_A.linkcuttree.test.cpp
  - test/aoj/GRL_5_E.linkcuttree.test.cpp
  - test/aoj/2450.linkcuttree.test.cpp
  - test/aoj/3120.test.cpp
  - test/aoj/0367.linkcuttree.test.cpp
  - test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
  - test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp
  - test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp
  - test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
  - test/yosupo/lca.linkcuttree.test.cpp
documentation_of: linkcuttree/base.cpp
layout: document
redirect_from:
- /library/linkcuttree/base.cpp
- /library/linkcuttree/base.cpp.html
title: linkcuttree/base.cpp
---
