---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/basic/base.cpp
    title: bbst/rbst/basic/base.cpp
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/persistent/base.cpp
    title: bbst/rbst/persistent/base.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/arc030/tasks/arc030_4
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ bbst/rbst/persistent/lazy.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../basic/base.cpp\"\n#include \"base.cpp\"\n\
    #undef call_from_test\n\n#endif\n//BEGIN CUT HERE\ntemplate<typename Tp, typename\
    \ Ep>\nstruct NodeBase{\n  using T = Tp;\n  using E = Ep;\n  NodeBase *l,*r,*p;\n\
    \  size_t cnt;\n  bool rev;\n  T val,dat;\n  E laz;\n  NodeBase(T val,E laz):\n\
    \    cnt(1),rev(0),val(val),dat(val),laz(laz){l=r=p=nullptr;}\n};\n\ntemplate<typename\
    \ Node, size_t LIM>\nstruct PersistentLazy :\n  PersistentBase<Node, LIM, PersistentLazy<Node,\
    \ LIM>>{\n  using super = PersistentBase<Node, LIM, PersistentLazy>;\n\n  using\
    \ T = typename Node::T;\n  using E = typename Node::E;\n\n  using F = function<T(T,\
    \ T)>;\n  using G = function<T(T, E)>;\n  using H = function<E(E, E)>;\n  using\
    \ S = function<T(T)>;\n\n  F f;\n  G g;\n  H h;\n  S flip;\n  T ti;\n  E ei;\n\
    \n  PersistentLazy(F f,G g,H h,S flip,T ti,E ei):\n    f(f),g(g),h(h),flip(flip),ti(ti),ei(ei){}\n\
    \n  PersistentLazy(F f,G g,H h,T ti,E ei):\n    PersistentLazy(f,g,h,[](T a){return\
    \ a;},ti,ei){}\n\n  inline void propagate(Node *t,E v){\n    t->laz=h(t->laz,v);\n\
    \    t->val=g(t->val,v);\n    t->dat=g(t->dat,v);\n  }\n\n  inline void toggle(Node\
    \ *t){\n    swap(t->l,t->r);\n    t->val=flip(t->val);\n    t->dat=flip(t->dat);\n\
    \    t->rev^=1;\n  }\n\n  using super::clone;\n  inline Node* eval(Node* t){\n\
    \    t=clone(t);\n\n    if(t->laz!=ei or t->rev){\n      t->l=clone(t->l);\n \
    \     t->r=clone(t->r);\n    }\n\n    if(t->laz!=ei){\n      if(t->l) propagate(t->l,t->laz);\n\
    \      if(t->r) propagate(t->r,t->laz);\n      t->laz=ei;\n    }\n\n    if(t->rev){\n\
    \      if(t->l) toggle(t->l);\n      if(t->r) toggle(t->r);\n      t->rev=false;\n\
    \    }\n    return t;\n  }\n\n  using super::count;\n  inline Node* pushup(Node\
    \ *t){\n    t->cnt=count(t->l)+1+count(t->r);\n    t->dat=t->val;\n    if(t->l)\
    \ t->dat=f(t->l->dat,t->dat);\n    if(t->r) t->dat=f(t->dat,t->r->dat);\n    return\
    \ t;\n  }\n\n  using super::merge;\n  using super::split;\n\n  T query(const Node\
    \ *a){\n    return a?a->dat:ti;\n  }\n\n  T query(Node *a,size_t l,size_t r){\n\
    \    auto s=split(a,l);\n    auto t=split(s.second,r-l);\n    auto u=t.first;\n\
    \    return query(u);\n  }\n\n  Node* update(Node *a,size_t l,size_t r,E v){\n\
    \    auto s=split(a,l);\n    auto t=split(s.second,r-l);\n    auto u=eval(t.first);\n\
    \    propagate(u,v);\n    return merge(s.first,merge(u,t.second));\n  }\n\n  T\
    \ get_val(Node *a,size_t k){\n    assert(k<count(a));\n    a=eval(a);\n    size_t\
    \ num=count(a->l);\n    if(k<num) return get_val(a->l,k);\n    if(k>num) return\
    \ get_val(a->r,k-(num+1));\n    return a->val;\n  }\n\n  Node* set_val(Node *a,size_t\
    \ k,T val){\n    assert(k<count(a));\n    a=eval(a);\n    size_t num=count(a->l);\n\
    \    if(k<num) a->l=set_val(a->l,k,val);\n    if(k>num) a->r=set_val(a->r,k-(num+1),val);\n\
    \    if(k==num) a->val=val;\n    return pushup(a);\n  }\n};\n//END CUT HERE\n\
    //INSERT ABOVE HERE\nsigned ARC030_D(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,q;\n  cin>>n>>q;\n\n  using ll = long long;\n  using P = pair<ll, ll>;\n\
    \  vector<P> vp(n,P(0,1));\n  for(int i=0;i<n;i++) cin>>vp[i].first;\n\n  auto\
    \ f=[](P a,P b){return P(a.first+b.first,a.second+b.second);};\n  auto g=[](P\
    \ a,ll b){return P(a.first+b*a.second,a.second);};\n  auto h=[](ll a,ll b){return\
    \ a+b;};\n\n  using Node = NodeBase<P, ll>;\n  constexpr size_t LIM = 6e6;\n \
    \ PersistentLazy<Node, LIM> G(f,g,h,P(0,0),0);\n\n  vector<Node> vs;\n  for(auto\
    \ v:vp) vs.emplace_back(v,0);\n  auto rt=G.build(vs);\n\n  for(int i=0;i<q;i++){\n\
    \    int t;\n    cin>>t;\n\n    if(t==1){\n      int a,b,v;\n      cin>>a>>b>>v;\n\
    \      a--;\n      rt=G.update(rt,a,b,v);\n    }\n\n    if(t==2){\n      int a,b,c,d;\n\
    \      cin>>a>>b>>c>>d;\n      a--;c--;\n      auto s=G.split(rt,a);\n      auto\
    \ t=G.split(s.second,b-a);\n      auto u=G.split(rt,c);\n      auto v=G.split(u.second,d-c);\n\
    \n      rt=G.merge(G.merge(s.first,v.first),t.second);\n    }\n\n    if(t==3){\n\
    \      int a,b;\n      cin>>a>>b;\n      a--;\n      cout<<G.query(rt,a,b).first<<'\\\
    n';\n    }\n\n    if(G.almost_full()) rt=G.rebuild(rt);\n  }\n  return 0;\n}\n\
    /*\n  verified on 2020/10/28\n  https://atcoder.jp/contests/arc030/tasks/arc030_4\n\
    */\n\nsigned main(){\n  ARC030_D();\n  return 0;\n}\n"
  dependsOn:
  - bbst/rbst/basic/base.cpp
  - bbst/rbst/persistent/base.cpp
  isVerificationFile: false
  path: bbst/rbst/persistent/lazy.cpp
  requiredBy: []
  timestamp: '2020-10-28 18:29:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bbst/rbst/persistent/lazy.cpp
layout: document
redirect_from:
- /library/bbst/rbst/persistent/lazy.cpp
- /library/bbst/rbst/persistent/lazy.cpp.html
title: bbst/rbst/persistent/lazy.cpp
---
