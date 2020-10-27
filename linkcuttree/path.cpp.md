---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: linkcuttree/base.cpp
    title: linkcuttree/base.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0367.linkcuttree.test.cpp
    title: test/aoj/0367.linkcuttree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2450.linkcuttree.test.cpp
    title: test/aoj/2450.linkcuttree.test.cpp
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
    path: test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
    title: test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca.linkcuttree.test.cpp
    title: test/yosupo/lca.linkcuttree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://ei1333.hateblo.jp/entry/2018/05/29/011140
    - https://www.spoj.com/problems/DYNACON1/
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ linkcuttree/path.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"base.cpp\"\n#undef call_from_test\n\n#endif\n\
    /**\n * @see https://ei1333.hateblo.jp/entry/2018/05/29/011140\n */\n//BEGIN CUT\
    \ HERE\ntemplate<typename Tp,typename Ep>\nstruct NodeBase{\n  using T = Tp;\n\
    \  using E = Ep;\n  NodeBase *l,*r,*p;\n  bool rev;\n  T val,dat;\n  E laz;\n\
    \  NodeBase(){}\n  NodeBase(T val,E laz):\n    rev(0),val(val),dat(val),laz(laz){\n\
    \    l=r=p=nullptr;}\n};\n\ntemplate<typename Np, size_t LIM>\nstruct Path : LinkCutTreeBase<Np,\
    \ LIM>{\n  using super = LinkCutTreeBase<Np, LIM>;\n  using Node = Np;\n  using\
    \ T = typename Node::T;\n  using E = typename Node::E;\n\n  using F = function<T(T,\
    \ T)>;\n  using G = function<T(T, E)>;\n  using H = function<E(E, E)>;\n  using\
    \ S = function<T(T)>;\n  F f;\n  G g;\n  H h;\n  S flip;\n  E ei;\n\n  Path(F\
    \ f,G g,H h,E ei):\n    super(),f(f),g(g),h(h),ei(ei){\n    flip=[](T a){return\
    \ a;};\n  }\n\n  Path(F f,G g,H h,S flip,E ei):\n    super(),f(f),g(g),h(h),flip(flip),ei(ei){}\n\
    \n  Node* create(T val){\n    return super::create(Node(val,ei));\n  }\n\n  inline\
    \ void propagate(Node *t,E v){\n    t->laz=h(t->laz,v);\n    t->val=g(t->val,v);\n\
    \    t->dat=g(t->dat,v);\n  }\n\n  inline void toggle(Node *t){\n    swap(t->l,t->r);\n\
    \    t->dat=flip(t->dat);\n    t->rev^=1;\n  }\n\n  inline Node* eval(Node *t){\n\
    \    if(t->laz!=ei){\n      if(t->l) propagate(t->l,t->laz);\n      if(t->r) propagate(t->r,t->laz);\n\
    \      t->laz=ei;\n    }\n    if(t->rev){\n      if(t->l) toggle(t->l);\n    \
    \  if(t->r) toggle(t->r);\n      t->rev=false;\n    }\n    return t;\n  }\n\n\
    \  inline void pushup(Node *t){\n    t->dat=t->val;\n    if(t->l) t->dat=f(t->l->dat,t->dat);\n\
    \    if(t->r) t->dat=f(t->dat,t->r->dat);\n  }\n\n  using super::expose;\n\n \
    \ T query(Node *t){\n    expose(t);\n    return t->dat;\n  }\n\n  void update(Node\
    \ *t,E v){\n    expose(t);\n    propagate(t,v);\n    eval(t);\n  }\n\n  void set_val(Node\
    \ *t,T v){\n    expose(t);\n    t->val=v;\n    eval(t);\n  }\n};\n//END CUT HERE\n\
    #ifndef call_from_test\n\n// test dynamic tree\nsigned SPOJ_DYNACON1(){\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n\n  int n,m;\n  cin>>n>>m;\n  using Node = NodeBase<int,\
    \ int>;\n  constexpr size_t LIM = 1e6;\n  using LCT = Path<Node, LIM>;\n\n  auto\
    \ f=[](int a,int b){return a+b;};\n  LCT lct(f,f,f,0);\n  for(int i=0;i<n;i++)\
    \ lct.create(0);\n\n  for(int i=0;i<m;i++){\n    string s;\n    int a,b;\n   \
    \ cin>>s>>a>>b;\n    a--;b--;\n    if(s==\"add\"s){\n      lct.evert(lct[b]);\n\
    \      lct.link(lct[a],lct[b]);\n    }\n    if(s==\"rem\"s){\n      auto v=lct.lca(lct[a],lct[b])==lct[a]?lct[b]:lct[a];\n\
    \      lct.cut(v);\n    }\n    if(s==\"conn\"s)\n      cout<<(lct.is_connected(lct[a],lct[b])?\"\
    YES\\n\":\"NO\\n\");\n  }\n  cout<<flush;\n  return 0;\n}\n/*\n  verified on 2020/01/08\n\
    \  https://www.spoj.com/problems/DYNACON1/\n*/\n\nsigned main(){\n  //SPOJ_DYNACON1();\n\
    \  return 0;\n}\n#endif\n"
  dependsOn:
  - linkcuttree/base.cpp
  isVerificationFile: false
  path: linkcuttree/path.cpp
  requiredBy: []
  timestamp: '2020-07-16 18:11:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_5_D.linkcuttree.test.cpp
  - test/aoj/0367.linkcuttree.test.cpp
  - test/aoj/2450.linkcuttree.test.cpp
  - test/aoj/GRL_5_E.linkcuttree.test.cpp
  - test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
  - test/yosupo/lca.linkcuttree.test.cpp
  - test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp
documentation_of: linkcuttree/path.cpp
layout: document
redirect_from:
- /library/linkcuttree/path.cpp
- /library/linkcuttree/path.cpp.html
title: linkcuttree/path.cpp
---
