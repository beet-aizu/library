---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3024.test.cpp
    title: test/aoj/3024.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segtree/persistent/ushi.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate <typename T>\nstruct\
    \ SegmentTree{\n  using F = function<T(T,T)>;\n  F f;\n  T ti;\n  SegmentTree(F\
    \ f,T ti):f(f),ti(ti){}\n\n  struct Node{\n    Node *l,*r;\n    T dat;\n    Node(T\
    \ dat):dat(dat){l=r=nullptr;}\n  };\n\n  Node* clone(Node *a){\n    return new\
    \ Node(*a);\n  }\n\n  Node* reflect(Node *a){\n    a->dat=f(a->l->dat,a->r->dat);\n\
    \    return a;\n  }\n\n  int n,height;\n  Node* build(const vector<T> &v){\n \
    \   int n_=v.size();\n    n=1;height=0;\n    while(n<n_) n<<=1,height++;\n   \
    \ vector<Node*> vs(n<<1);\n    for(int i=0;i<n_;i++) vs[n+i]=new Node(v[i]);\n\
    \    for(int i=n_;i<n;i++) vs[n+i]=new Node(ti);\n    for(int i=n-1;i;i--){\n\
    \      vs[i]=new Node(ti);\n      vs[i]->l=vs[(i<<1)|0];\n      vs[i]->r=vs[(i<<1)|1];\n\
    \      reflect(vs[i]);\n    }\n    return vs[1];\n  }\n\n  Node* set_val(Node*\
    \ t,int k,T x,int h){\n    t=clone(t);\n    if(h<0){\n      t->dat=x;\n      return\
    \ t;\n    }\n    if((k>>h)&1) t->r=set_val(t->r,k,x,h-1);\n    else t->l=set_val(t->l,k,x,h-1);\n\
    \    return reflect(t);\n  }\n\n  T query(Node* t,int l,int r,int lb,int ub){\n\
    \    if(r<=lb or ub<=l) return ti;\n    if(l<=lb and ub<=r) return t->dat;\n \
    \   int m=(lb+ub)>>1;\n    return f(query(t->l,l,r,lb,m),query(t->r,l,r,m,ub));\n\
    \  }\n\n  Node* set_val(Node* t,int k,T x){\n    return set_val(t,k,x,height-1);\n\
    \  }\n\n  T query(Node* t,int l,int r){\n    return query(t,l,r,0,n);\n  }\n};\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate <typename T>\nstruct SegmentTree{\n  using\
    \ F = function<T(T,T)>;\n  F f;\n  T ti;\n  SegmentTree(F f,T ti):f(f),ti(ti){}\n\
    \n  struct Node{\n    Node *l,*r;\n    T dat;\n    Node(T dat):dat(dat){l=r=nullptr;}\n\
    \  };\n\n  Node* clone(Node *a){\n    return new Node(*a);\n  }\n\n  Node* reflect(Node\
    \ *a){\n    a->dat=f(a->l->dat,a->r->dat);\n    return a;\n  }\n\n  int n,height;\n\
    \  Node* build(const vector<T> &v){\n    int n_=v.size();\n    n=1;height=0;\n\
    \    while(n<n_) n<<=1,height++;\n    vector<Node*> vs(n<<1);\n    for(int i=0;i<n_;i++)\
    \ vs[n+i]=new Node(v[i]);\n    for(int i=n_;i<n;i++) vs[n+i]=new Node(ti);\n \
    \   for(int i=n-1;i;i--){\n      vs[i]=new Node(ti);\n      vs[i]->l=vs[(i<<1)|0];\n\
    \      vs[i]->r=vs[(i<<1)|1];\n      reflect(vs[i]);\n    }\n    return vs[1];\n\
    \  }\n\n  Node* set_val(Node* t,int k,T x,int h){\n    t=clone(t);\n    if(h<0){\n\
    \      t->dat=x;\n      return t;\n    }\n    if((k>>h)&1) t->r=set_val(t->r,k,x,h-1);\n\
    \    else t->l=set_val(t->l,k,x,h-1);\n    return reflect(t);\n  }\n\n  T query(Node*\
    \ t,int l,int r,int lb,int ub){\n    if(r<=lb or ub<=l) return ti;\n    if(l<=lb\
    \ and ub<=r) return t->dat;\n    int m=(lb+ub)>>1;\n    return f(query(t->l,l,r,lb,m),query(t->r,l,r,m,ub));\n\
    \  }\n\n  Node* set_val(Node* t,int k,T x){\n    return set_val(t,k,x,height-1);\n\
    \  }\n\n  T query(Node* t,int l,int r){\n    return query(t,l,r,0,n);\n  }\n};\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: segtree/persistent/ushi.cpp
  requiredBy: []
  timestamp: '2020-10-27 13:26:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3024.test.cpp
documentation_of: segtree/persistent/ushi.cpp
layout: document
redirect_from:
- /library/segtree/persistent/ushi.cpp
- /library/segtree/persistent/ushi.cpp.html
title: segtree/persistent/ushi.cpp
---
