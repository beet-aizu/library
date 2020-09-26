---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/unionfind.cpp
    title: datastructure/unionfind.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algorithm/optimalbinarytree.cpp
    title: algorithm/optimalbinarytree.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_9_C.test.cpp
    title: test/aoj/ALDS1_9_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2415.test.cpp
    title: test/aoj/2415.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/apc001/tasks/apc001_d
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/skewheap.cpp: line 75: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T, typename E>\nstruct SkewHeap{\n\
    \  using G = function<T(T,E)>;\n  using H = function<E(E,E)>;\n  using C = function<bool(T,T)>;\n\
    \  G g;\n  H h;\n  C c;\n  T INF;\n  E ei;\n  SkewHeap(G g,H h,C c,T INF,E ei):g(g),h(h),c(c),INF(INF),ei(ei){}\n\
    \n  struct Node{\n    Node *l,*r;\n    T val;\n    E add;\n    Node(T val,E add):val(val),add(add){l=r=nullptr;}\n\
    \  };\n\n  void eval(Node *a){\n    if(a==nullptr) return;\n    if(a->add==ei)\
    \ return;\n    if(a->l) a->l->add=h(a->l->add,a->add);\n    if(a->r) a->r->add=h(a->r->add,a->add);\n\
    \    a->val=g(a->val,a->add);\n    a->add=ei;\n  }\n\n  T top(Node *a){\n    return\
    \ a!=nullptr?g(a->val,a->add):INF;\n  }\n\n  T snd(Node *a){\n    eval(a);\n \
    \   return a!=nullptr?min(top(a->l),top(a->r)):INF;\n  }\n\n  Node* add(Node *a,E\
    \ d){\n    if(a!=nullptr) a->add=h(a->add,d);\n    return a;\n  }\n\n  Node* push(T\
    \ v){\n    return new Node(v,ei);\n  }\n\n  Node* meld(Node *a,Node *b){\n   \
    \ if(!a||!b) return a?a:b;\n    if(c(top(a),top(b))) swap(a,b);\n    eval(a);\n\
    \    a->r=meld(a->r,b);\n    swap(a->l,a->r);\n    return a;\n  }\n\n  Node* pop(Node*\
    \ a){\n    eval(a);\n    auto res=meld(a->l,a->r);\n    delete a;\n    return\
    \ res;\n  }\n\n};\n//END CUT HERE\n#ifndef call_from_test\n\n#define call_from_test\n\
    #include \"unionfind.cpp\"\n#undef call_from_test\n\nsigned APC001_D(){\n  using\
    \ ll = long long;\n  using Heap = SkewHeap<ll, ll>;\n  ll n,m;\n  cin>>n>>m;\n\
    \  vector<ll> a(n);\n  for(ll i=0;i<n;i++) cin>>a[i];\n\n  auto g=[](ll a,ll b){return\
    \ a+b;};\n  auto h=[](ll a,ll b){return a+b;};\n  auto c=[](ll a,ll b){return\
    \ a>b;};\n\n  const ll INF = 1e16;\n  Heap heap(g,h,c,INF,0);\n  vector<Heap::Node*>\
    \ v(n);\n  for(ll i=0;i<n;i++) v[i]=heap.push(a[i]);\n\n  UnionFind uf(n);\n \
    \ for(ll i=0;i<m;i++){\n    ll x,y;\n    cin>>x>>y;\n    x=uf.find(x);y=uf.find(y);\n\
    \    uf.unite(x,y);\n    if(uf.find(x)!=x) swap(x,y);\n    v[x]=heap.meld(v[x],v[y]);\n\
    \    v[y]=NULL;\n  }\n\n  if(m==n-1){\n    cout<<0<<endl;\n    return 0;\n  }\n\
    \n  Heap::Node* base=NULL;\n\n  ll ans=0,cnt=0;\n  for(ll i=0;i<n;i++){\n    if(uf.find(i)==i){\n\
    \      ans+=heap.top(v[i]);\n      v[i]=heap.pop(v[i]);\n      base=heap.meld(base,v[i]);\n\
    \      cnt++;\n    }\n  }\n\n  while(m*2+cnt<(n-1)*2){\n    if(base==NULL){\n\
    \      cout<<\"Impossible\"<<endl;\n      return 0;\n    }\n    ans+=heap.top(base);\n\
    \    base=heap.pop(base);\n    cnt++;\n  }\n\n  cout<<ans<<endl;\n  return 0;\n\
    }\n/*\n  verified on 2019/12/17\n  https://atcoder.jp/contests/apc001/tasks/apc001_d\n\
    */\n\nsigned main(){\n  APC001_D();\n}\n#endif\n"
  dependsOn:
  - datastructure/unionfind.cpp
  isVerificationFile: false
  path: datastructure/skewheap.cpp
  requiredBy:
  - algorithm/optimalbinarytree.cpp
  timestamp: '2020-05-17 19:42:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_9_C.test.cpp
  - test/aoj/2415.test.cpp
documentation_of: datastructure/skewheap.cpp
layout: document
redirect_from:
- /library/datastructure/skewheap.cpp
- /library/datastructure/skewheap.cpp.html
title: datastructure/skewheap.cpp
---
