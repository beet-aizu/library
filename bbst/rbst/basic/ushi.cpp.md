---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/basic/base.cpp
    title: bbst/rbst/basic/base.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1508.test.cpp
    title: test/aoj/1508.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.bbst.test.cpp
    title: test/aoj/DSL_2_A.bbst.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://www.hackerrank.com/contests/happy-query-contest/challenges/range-sorting-query
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ bbst/rbst/basic/ushi.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"base.cpp\"\n#undef call_from_test\n\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename Tp>\nstruct NodeBase{\n  using T = Tp;\n \
    \ NodeBase *l,*r,*p;\n  size_t cnt;\n  bool rev;\n  T val,dat;\n  NodeBase(T val):\n\
    \    cnt(1),rev(0),val(val),dat(val){l=r=p=nullptr;}\n};\n\ntemplate<typename\
    \ Node, size_t LIM>\nstruct Ushi : BBSTBase<Node, LIM, Ushi<Node, LIM>>{\n  using\
    \ super = BBSTBase<Node, LIM, Ushi>;\n\n  using T = typename Node::T;\n  using\
    \ F = function<T(T, T)>;\n  using S = function<T(T)>;\n\n  F f;\n  S flip;\n \
    \ T ti;\n\n  Ushi(F f,S flip,T ti):\n    f(f),flip(flip),ti(ti){}\n\n  Ushi(F\
    \ f,T ti):Ushi(f,[](T a){return a;},ti){}\n\n  using super::toggle;\n  inline\
    \ void toggle(Node *t){\n    swap(t->l,t->r);\n    t->val=flip(t->val);\n    t->dat=flip(t->dat);\n\
    \    t->rev^=1;\n  }\n\n  inline Node* eval(Node* t){\n    if(t->rev){\n     \
    \ if(t->l) toggle(t->l);\n      if(t->r) toggle(t->r);\n      t->rev=false;\n\
    \    }\n    return t;\n  }\n\n  using super::count;\n  inline Node* pushup(Node\
    \ *t){\n    t->cnt=count(t->l)+1+count(t->r);\n    t->dat=t->val;\n    if(t->l)\
    \ t->dat=f(t->l->dat,t->dat);\n    if(t->r) t->dat=f(t->dat,t->r->dat);\n    return\
    \ t;\n  }\n\n  using super::merge;\n  using super::split;\n\n  T query(const Node\
    \ *a){\n    return a?a->dat:ti;\n  }\n\n  T query(Node *&a,size_t l,size_t r){\n\
    \    auto s=split(a,l);\n    auto t=split(s.second,r-l);\n    auto u=t.first;\n\
    \    T res=query(u);\n    a=merge(s.first,merge(u,t.second));\n    return res;\n\
    \  }\n\n  T get_val(Node *a,size_t k){\n    return super::find_by_order(a,k)->val;\n\
    \  }\n\n  Node* set_val(Node *a,size_t k,T val){\n    assert(k<count(a));\n  \
    \  a=eval(a);\n    size_t num=count(a->l);\n    if(k<num) a->l=set_val(a->l,k,val);\n\
    \    if(k>num) a->r=set_val(a->r,k-(num+1),val);\n    if(k==num) a->val=val;\n\
    \    return pushup(a);\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT\
    \ ABOVE HERE\n\n// test toggle\nsigned HAPPYQUERY_C(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n;\n  cin>>n;\n  vector<int> vs(n);\n  for(int i=0;i<n;i++) cin>>vs[i];\n\
    \n  int q;\n  cin>>q;\n  vector<int> ts(q);\n  vector<int> ls(q),rs(q);\n  vector<int>\
    \ ps(q),xs(q);\n  vector<int> as(q),bs(q),cs(q),ds(q);\n  for(int i=0;i<q;i++){\n\
    \    cin>>ts[i];\n    if(ts[i]==1) cin>>ls[i]>>rs[i],ls[i]--;\n    if(ts[i]==2)\
    \ cin>>ps[i]>>xs[i],ps[i]--;\n    if(ts[i]==3){\n      cin>>as[i]>>bs[i]>>cs[i]>>ds[i];\n\
    \      as[i]--;cs[i]--;\n    }\n  }\n\n  using ll = long long;\n  auto f=[](ll\
    \ a,ll b){return a+b;};\n  ll ti=0;\n\n  using Node=NodeBase<ll>;\n  constexpr\
    \ size_t LIM = 1e6;\n  Ushi<Node, LIM> G(f,ti);\n\n  unordered_map<int, ll> memo;\n\
    \  auto hs=\n    [&](int x){\n      if(!memo.count(x))\n        memo[x]=G.xor128();\n\
    \      return memo[x];\n    };\n\n  vector<Node> ws;\n  for(int i=0;i<n;i++) ws.emplace_back(hs(vs[i]));\n\
    \  auto rt=G.build(ws);\n\n  for(int i=0;i<q;i++){\n    if(ts[i]==1) rt=G.toggle(rt,ls[i],rs[i]);\n\
    \    if(ts[i]==2) rt=G.set_val(rt,ps[i],hs(xs[i]));\n    if(ts[i]==3){\n     \
    \ ll x=G.query(rt,as[i],bs[i]);\n      ll y=G.query(rt,cs[i],ds[i]);\n      cout<<(x==y?\"\
    Yes\":\"No\")<<\"\\n\";\n    }\n  }\n  cout<<flush;\n  return 0;\n}\n/*\n  verified\
    \ on 2019/06/24\n  https://www.hackerrank.com/contests/happy-query-contest/challenges/range-sorting-query\n\
    */\n\nsigned main(){\n  HAPPYQUERY_C();\n  return 0;\n}\n#endif\n"
  dependsOn:
  - bbst/rbst/basic/base.cpp
  isVerificationFile: false
  path: bbst/rbst/basic/ushi.cpp
  requiredBy: []
  timestamp: '2020-10-28 18:29:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_A.bbst.test.cpp
  - test/aoj/1508.test.cpp
documentation_of: bbst/rbst/basic/ushi.cpp
layout: document
redirect_from:
- /library/bbst/rbst/basic/ushi.cpp
- /library/bbst/rbst/basic/ushi.cpp.html
title: bbst/rbst/basic/ushi.cpp
---
