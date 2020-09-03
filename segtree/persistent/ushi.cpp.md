---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"segtree/persistent/ushi.cpp\"\n\n#include<bits/stdc++.h>\n\
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
    \    if(r<=lb||ub<=l) return ti;\n    if(l<=lb&&ub<=r) return t->dat;\n    int\
    \ m=(lb+ub)>>1;\n    return f(query(t->l,l,r,lb,m),query(t->r,l,r,m,ub));\n  }\n\
    \n  Node* set_val(Node* t,int k,T x){\n    return set_val(t,k,x,height-1);\n \
    \ }\n\n  T query(Node* t,int l,int r){\n    return query(t,l,r,0,n);\n  }\n};\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned HAPPYQUERY_B(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n;\n  cin>>n;\n  vector<int>\
    \ as(n);\n  for(int i=0;i<n;i++) cin>>as[i];\n\n  auto f=[](int a,int b){return\
    \ min(a,b);};\n  int ti=INT_MAX;\n  SegmentTree<int> seg(f,ti);\n  auto rt=seg.build(as);\n\
    \n  int q1;\n  cin>>q1;\n\n  vector<decltype(rt)> rts;\n  rts.reserve(q1+1);\n\
    \  rts.emplace_back(rt);\n\n  for(int i=0;i<q1;i++){\n    int p,x;\n    cin>>p>>x;\n\
    \    p--;\n    rt=seg.set_val(rt,p,x);\n    rts.emplace_back(rt);\n  }\n\n  int\
    \ q2;\n  cin>>q2;\n  int x=0;\n  for(int i=0;i<q2;i++){\n    int a,b,c;\n    cin>>a>>b>>c;\n\
    \    int k=a^x;\n    int l=(b^x)-1;\n    int r=(c^x);\n    assert(l<r);\n    x=seg.query(rts[k],l,r);\n\
    \    cout<<x<<\"\\n\";\n  }\n  cout<<flush;\n  return 0;\n}\n/*\n  verified on\
    \ 2019/06/22\n  https://www.hackerrank.com/contests/happy-query-contest/challenges/minimum-history-query\n\
    */\nsigned main(){\n  HAPPYQUERY_B();\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate <typename T>\nstruct SegmentTree{\n  using F = function<T(T,T)>;\n\
    \  F f;\n  T ti;\n  SegmentTree(F f,T ti):f(f),ti(ti){}\n\n  struct Node{\n  \
    \  Node *l,*r;\n    T dat;\n    Node(T dat):dat(dat){l=r=nullptr;}\n  };\n\n \
    \ Node* clone(Node *a){\n    return new Node(*a);\n  }\n\n  Node* reflect(Node\
    \ *a){\n    a->dat=f(a->l->dat,a->r->dat);\n    return a;\n  }\n\n  int n,height;\n\
    \  Node* build(const vector<T> &v){\n    int n_=v.size();\n    n=1;height=0;\n\
    \    while(n<n_) n<<=1,height++;\n    vector<Node*> vs(n<<1);\n    for(int i=0;i<n_;i++)\
    \ vs[n+i]=new Node(v[i]);\n    for(int i=n_;i<n;i++) vs[n+i]=new Node(ti);\n \
    \   for(int i=n-1;i;i--){\n      vs[i]=new Node(ti);\n      vs[i]->l=vs[(i<<1)|0];\n\
    \      vs[i]->r=vs[(i<<1)|1];\n      reflect(vs[i]);\n    }\n    return vs[1];\n\
    \  }\n\n  Node* set_val(Node* t,int k,T x,int h){\n    t=clone(t);\n    if(h<0){\n\
    \      t->dat=x;\n      return t;\n    }\n    if((k>>h)&1) t->r=set_val(t->r,k,x,h-1);\n\
    \    else t->l=set_val(t->l,k,x,h-1);\n    return reflect(t);\n  }\n\n  T query(Node*\
    \ t,int l,int r,int lb,int ub){\n    if(r<=lb||ub<=l) return ti;\n    if(l<=lb&&ub<=r)\
    \ return t->dat;\n    int m=(lb+ub)>>1;\n    return f(query(t->l,l,r,lb,m),query(t->r,l,r,m,ub));\n\
    \  }\n\n  Node* set_val(Node* t,int k,T x){\n    return set_val(t,k,x,height-1);\n\
    \  }\n\n  T query(Node* t,int l,int r){\n    return query(t,l,r,0,n);\n  }\n};\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned HAPPYQUERY_B(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n;\n  cin>>n;\n  vector<int>\
    \ as(n);\n  for(int i=0;i<n;i++) cin>>as[i];\n\n  auto f=[](int a,int b){return\
    \ min(a,b);};\n  int ti=INT_MAX;\n  SegmentTree<int> seg(f,ti);\n  auto rt=seg.build(as);\n\
    \n  int q1;\n  cin>>q1;\n\n  vector<decltype(rt)> rts;\n  rts.reserve(q1+1);\n\
    \  rts.emplace_back(rt);\n\n  for(int i=0;i<q1;i++){\n    int p,x;\n    cin>>p>>x;\n\
    \    p--;\n    rt=seg.set_val(rt,p,x);\n    rts.emplace_back(rt);\n  }\n\n  int\
    \ q2;\n  cin>>q2;\n  int x=0;\n  for(int i=0;i<q2;i++){\n    int a,b,c;\n    cin>>a>>b>>c;\n\
    \    int k=a^x;\n    int l=(b^x)-1;\n    int r=(c^x);\n    assert(l<r);\n    x=seg.query(rts[k],l,r);\n\
    \    cout<<x<<\"\\n\";\n  }\n  cout<<flush;\n  return 0;\n}\n/*\n  verified on\
    \ 2019/06/22\n  https://www.hackerrank.com/contests/happy-query-contest/challenges/minimum-history-query\n\
    */\nsigned main(){\n  HAPPYQUERY_B();\n  return 0;\n}\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3024.test.cpp
    title: test/aoj/3024.test.cpp
  isVerificationFile: false
  path: segtree/persistent/ushi.cpp
  requiredBy: []
  timestamp: '2019-12-17 21:51:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - test/aoj/3024.test.cpp
documentation_of: segtree/persistent/ushi.cpp
layout: document
redirect_from:
- /library/segtree/persistent/ushi.cpp
- /library/segtree/persistent/ushi.cpp.html
title: segtree/persistent/ushi.cpp
---
