---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bbst/rbst/basic/base.cpp
    title: bbst/rbst/basic/base.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/code-festival-2014-exhibition-open/tasks/code_festival_exhibition_b
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ bbst/rbst/basic/lazy.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"base.cpp\"\n#undef call_from_test\n\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename Tp, typename Ep>\nstruct NodeBase{\n  using\
    \ T = Tp;\n  using E = Ep;\n  NodeBase *l,*r,*p;\n  size_t cnt;\n  bool rev;\n\
    \  T val,dat;\n  E laz;\n  NodeBase(T val,E laz):\n    cnt(1),rev(0),val(val),dat(val),laz(laz){l=r=p=nullptr;}\n\
    };\n\ntemplate<typename Node, size_t LIM>\nstruct Lazy : BBSTBase<Node, LIM, Lazy<Node,\
    \ LIM>>{\n  using super = BBSTBase<Node, LIM, Lazy>;\n\n  using T = typename Node::T;\n\
    \  using E = typename Node::E;\n\n  using F = function<T(T, T)>;\n  using G =\
    \ function<T(T, E)>;\n  using H = function<E(E, E)>;\n  using S = function<T(T)>;\n\
    \n  F f;\n  G g;\n  H h;\n  S flip;\n  T ti;\n  E ei;\n\n  Lazy(F f,G g,H h,S\
    \ flip,T ti,E ei):\n    f(f),g(g),h(h),flip(flip),ti(ti),ei(ei){}\n\n  Lazy(F\
    \ f,G g,H h,T ti,E ei):\n    Lazy(f,g,h,[](T a){return a;},ti,ei){}\n\n  inline\
    \ void propagate(Node *t,E v){\n    t->laz=h(t->laz,v);\n    t->val=g(t->val,v);\n\
    \    t->dat=g(t->dat,v);\n  }\n\n  inline void toggle(Node *t){\n    swap(t->l,t->r);\n\
    \    t->val=flip(t->val);\n    t->dat=flip(t->dat);\n    t->rev^=1;\n  }\n\n \
    \ inline Node* eval(Node* t){\n    if(t->laz!=ei){\n      if(t->l) propagate(t->l,t->laz);\n\
    \      if(t->r) propagate(t->r,t->laz);\n      t->laz=ei;\n    }\n    if(t->rev){\n\
    \      if(t->l) toggle(t->l);\n      if(t->r) toggle(t->r);\n      t->rev=false;\n\
    \    }\n    return t;\n  }\n\n  using super::count;\n  inline Node* pushup(Node\
    \ *t){\n    t->cnt=count(t->l)+1+count(t->r);\n    t->dat=t->val;\n    if(t->l)\
    \ t->dat=f(t->l->dat,t->dat);\n    if(t->r) t->dat=f(t->dat,t->r->dat);\n    return\
    \ t;\n  }\n\n  using super::merge;\n  using super::split;\n\n  T query(const Node\
    \ *a){\n    return a?a->dat:ti;\n  }\n\n  T query(Node *&a,size_t l,size_t r){\n\
    \    auto s=split(a,l);\n    auto t=split(s.second,r-l);\n    auto u=t.first;\n\
    \    T res=query(u);\n    a=merge(s.first,merge(u,t.second));\n    return res;\n\
    \  }\n\n  Node* update(Node *a,size_t l,size_t r,E v){\n    auto s=split(a,l);\n\
    \    auto t=split(s.second,r-l);\n    auto u=eval(t.first);\n    propagate(u,v);\n\
    \    return merge(s.first,merge(u,t.second));\n  }\n\n  T get_val(Node *a,size_t\
    \ k){\n    assert(k<count(a));\n    a=eval(a);\n    size_t num=count(a->l);\n\
    \    if(k<num) return get_val(a->l,k);\n    if(k>num) return get_val(a->r,k-(num+1));\n\
    \    return a->val;\n  }\n\n  Node* set_val(Node *a,size_t k,T val){\n    assert(k<count(a));\n\
    \    a=eval(a);\n    size_t num=count(a->l);\n    if(k<num) a->l=set_val(a->l,k,val);\n\
    \    if(k>num) a->r=set_val(a->r,k-(num+1),val);\n    if(k==num) a->val=val;\n\
    \    return pushup(a);\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT\
    \ ABOVE HERE\n\n// test insert, erase\nsigned CODEFESTIVAL2014EXHIBITION_B(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int Q;\n  cin>>Q;\n\n  string\
    \ S;\n  cin>>S;\n\n  using T = tuple<int, int, int>;\n  using P = pair<int, int>;\n\
    \  auto f=[](T a,T b){\n    return T(min(get<0>(a),get<0>(b)),min(get<1>(a),get<1>(b)),0);\n\
    \  };\n  auto g=[](T a,P b){\n    return T(get<0>(a)+b.first,get<1>(a)+b.second,get<2>(a));\n\
    \  };\n  auto h=[](P a,P b){\n    return P(a.first+b.first,a.second+b.second);\n\
    \  };\n  const int INF = 1e9;\n\n  using Node = NodeBase<T, P>;\n  constexpr size_t\
    \ LIM = 1e6;\n  Lazy<Node, LIM> G(f,g,h,T(INF,INF,0),P(0,0));\n\n  vector<Node>\
    \ vs((int)S.size()+2,Node(T(0,0,0),G.ei));\n  auto rt=G.build(vs);\n\n  for(int\
    \ i=0;i<(int)S.size();i++)\n    rt=G.set_val(rt,i+1,T(0,0,S[i]=='('?+1:-1));\n\
    \n  for(int i=1;i<=(int)S.size();i++){\n    int z=get<2>(G.get_val(rt,i));\n \
    \   rt=G.update(rt,i,G.count(rt),P(+z,0));\n    rt=G.update(rt,0,i+1,P(0,-z));\n\
    \  }\n\n  for(int i=0;i<Q;i++){\n    char x;\n    int y,z;\n    cin>>x>>y>>z;\n\
    \n    z++;\n    if(x=='(' or x==')'){\n      z=(x=='('?+1:-1);\n      T prv=G.get_val(rt,y-1);\n\
    \      T nxt=G.get_val(rt,y);\n      T cur(get<0>(prv),get<1>(nxt),z);\n     \
    \ rt=G.insert(rt,y,Node(cur,P(0,0)));\n      rt=G.update(rt,y,G.count(rt),P(z,0));\n\
    \      rt=G.update(rt,0,y+1,P(0,-z));\n    }\n\n    if(x=='D'){\n      z=get<2>(G.get_val(rt,y));\n\
    \      rt=G.erase(rt,y);\n      rt=G.update(rt,y,G.count(rt),P(-z,0));\n     \
    \ rt=G.update(rt,0,y,P(0,z));\n    }\n\n    if(x=='Q'){\n      T prv=G.get_val(rt,y-1);\n\
    \      T cur=G.query(rt,y,z);\n      T nxt=G.get_val(rt,z);\n      int ans=0;\n\
    \      if(get<0>(prv)>get<0>(cur)) ans+=get<0>(prv)-get<0>(cur);\n      if(get<1>(nxt)>get<1>(cur))\
    \ ans+=get<1>(nxt)-get<1>(cur);\n      cout<<ans<<'\\n';\n    }\n  }\n\n  return\
    \ 0;\n}\n/*\n  verified on 2020/10/28\n  https://atcoder.jp/contests/code-festival-2014-exhibition-open/tasks/code_festival_exhibition_b\n\
    */\n\nsigned main(){\n  CODEFESTIVAL2014EXHIBITION_B();\n  return 0;\n}\n#endif\n"
  dependsOn:
  - bbst/rbst/basic/base.cpp
  isVerificationFile: false
  path: bbst/rbst/basic/lazy.cpp
  requiredBy: []
  timestamp: '2020-10-28 18:43:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_G.bbst.test.cpp
  - test/aoj/DSL_2_H.bbst.test.cpp
  - test/aoj/DSL_2_F.bbst.test.cpp
  - test/aoj/DSL_2_I.bbst.test.cpp
documentation_of: bbst/rbst/basic/lazy.cpp
layout: document
redirect_from:
- /library/bbst/rbst/basic/lazy.cpp
- /library/bbst/rbst/basic/lazy.cpp.html
title: bbst/rbst/basic/lazy.cpp
---
