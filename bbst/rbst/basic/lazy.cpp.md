---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ bbst/rbst/basic/lazy.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"base.cpp\"\n#undef call_from_test\n\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename Tp, typename Ep>\nstruct NodeBase{\n  using\
    \ T = Tp;\n  using E = Ep;\n  NodeBase *l,*r,*p;\n  size_t cnt;\n  bool rev;\n\
    \  T val,dat;\n  E laz;\n  NodeBase():cnt(1),rev(0){l=r=p=nullptr;}\n  NodeBase(T\
    \ val,E laz):\n    cnt(1),rev(0),val(val),dat(val),laz(laz){l=r=p=nullptr;}\n\
    };\n\ntemplate<typename Node, size_t LIM>\nstruct Lazy : BBSTBase<Node, LIM>{\n\
    \  using super = BBSTBase<Node, LIM>;\n\n  using T = typename Node::T;\n  using\
    \ E = typename Node::E;\n\n  using F = function<T(T, T)>;\n  using G = function<T(T,\
    \ E)>;\n  using H = function<E(E, E)>;\n  using S = function<T(T)>;\n\n  F f;\n\
    \  G g;\n  H h;\n  S flip;\n  T ti;\n  E ei;\n\n  Lazy(F f,G g,H h,T ti,E ei):\n\
    \    super(),f(f),g(g),h(h),ti(ti),ei(ei){\n    flip=[](T a){return a;};\n  }\n\
    \n  Lazy(F f,G g,H h,S flip,T ti,E ei):\n    super(),f(f),g(g),h(h),flip(flip),ti(ti),ei(ei){}\n\
    \n  using super::create;\n  using super::merge;\n  using super::split;\n\n  T\
    \ query(const Node *a){\n    return a?a->dat:ti;\n  }\n\n  using super::count;\n\
    \  Node* recalc(Node *a){\n    a->cnt=count(a->l)+1+count(a->r);\n    a->dat=a->val;\n\
    \    if(a->l) a->dat=f(a->l->dat,a->dat);\n    if(a->r) a->dat=f(a->dat,a->r->dat);\n\
    \    return a;\n  }\n\n  void propagate(Node *a,E v){\n    a->laz=h(a->laz,v);\n\
    \    a->val=g(a->val,v);\n    a->dat=g(a->dat,v);\n  }\n\n  using super::toggle;\n\
    \  void toggle(Node *a){\n    swap(a->l,a->r);\n    a->val=flip(a->val);\n   \
    \ a->dat=flip(a->dat);\n    a->rev^=1;\n  }\n\n  // remove \"virtual\" for optimization\n\
    \  virtual Node* eval(Node* a){\n    if(a->laz!=ei){\n      if(a->l) propagate(a->l,a->laz);\n\
    \      if(a->r) propagate(a->r,a->laz);\n      a->laz=ei;\n    }\n    if(a->rev){\n\
    \      if(a->l) toggle(a->l);\n      if(a->r) toggle(a->r);\n      a->rev=false;\n\
    \    }\n    return recalc(a);\n  }\n\n  T query(Node *&a,size_t l,size_t r){\n\
    \    auto s=split(a,l);\n    auto t=split(s.second,r-l);\n    auto u=t.first;\n\
    \    T res=query(u);\n    a=merge(s.first,merge(u,t.second));\n    return res;\n\
    \  }\n\n  Node* update(Node *a,size_t l,size_t r,E x){\n    auto s=split(a,l);\n\
    \    auto t=split(s.second,r-l);\n    auto u=eval(t.first);\n    propagate(u,x);\n\
    \    return merge(s.first,merge(u,t.second));\n  }\n\n  Node* set_val(Node *a,size_t\
    \ k,T val){\n    assert(k<count(a));\n    a=eval(a);\n    size_t num=count(a->l);\n\
    \    if(k<num) a->l=set_val(a->l,k,val);\n    if(k>num) a->r=set_val(a->r,k-(num+1),val);\n\
    \    if(k==num) a->val=val;\n    return recalc(a);\n  }\n\n  T get_val(Node *a,size_t\
    \ k){\n    assert(k<count(a));\n    a=eval(a);\n    size_t num=count(a->l);\n\
    \    if(k<num) return get_val(a->l,k);\n    if(k>num) return get_val(a->r,k-(num+1));\n\
    \    return a->val;\n  }\n\n  void dump(Node* a,typename vector<T>::iterator it){\n\
    \    if(!count(a)) return;\n    a=eval(a);\n    dump(a->l,it);\n    *(it+count(a->l))=a->val;\n\
    \    dump(a->r,it+count(a->l)+1);\n  }\n\n  vector<T> dump(Node* a){\n    vector<T>\
    \ vs(count(a));\n    dump(a,vs.begin());\n    return vs;\n  }\n};\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nchar buf[114514];\nsigned CODEFESTIVAL2014EXHIBITION_B(){\n\
    \  int Q;\n  scanf(\"%d\",&Q);\n  scanf(\"%s\\n\",buf);\n  string S(buf);\n  using\
    \ T = tuple<int, int, int>;\n  using P = pair<int, int>;\n  auto f=[](T a,T b){\n\
    \           return T(min(get<0>(a),get<0>(b)),min(get<1>(a),get<1>(b)),0);\n \
    \        };\n  auto g=[](T a,P b){\n           return T(get<0>(a)+b.first,get<1>(a)+b.second,get<2>(a));\n\
    \         };\n  auto h=[](P a,P b){\n           return P(a.first+b.first,a.second+b.second);\n\
    \         };\n  const int INF = 1e9;\n\n  using Node = NodeBase<T, P>;\n  constexpr\
    \ size_t LIM = 1e6;\n  Lazy<Node, LIM> G(f,g,h,T(INF,INF,0),P(0,0));\n\n  vector<Node>\
    \ vs(S.size()+2);\n  for(int i=0;i<(int)S.size();i++)\n    vs[i+1].val=T(0,0,S[i]=='('?1:-1);\n\
    \n  auto rt=G.build(vs);\n  for(int i=1;i<=(int)S.size();i++){\n    int z=get<2>(G.get_val(rt,i));\n\
    \    rt=G.update(rt,i,G.count(rt),P(z,0));\n    rt=G.update(rt,0,i+1,P(0,-z));\n\
    \  }\n\n  for(int i=0;i<Q;i++){\n    char x;\n    int y,z;\n    scanf(\"%c %d\
    \ %d\\n\",&x,&y,&z);\n    z++;\n    if(x=='('||x==')'){\n      z=(x=='('?1:-1);\n\
    \      T prv=G.get_val(rt,y-1);\n      T nxt=G.get_val(rt,y);\n      T cur(get<0>(prv),get<1>(nxt),z);\n\
    \      rt=G.insert(rt,y,Node(cur,P(0,0)));\n      rt=G.update(rt,y,G.count(rt),P(z,0));\n\
    \      rt=G.update(rt,0,y+1,P(0,-z));\n    }\n\n    if(x=='D'){\n      z=get<2>(G.get_val(rt,y));\n\
    \      rt=G.erase(rt,y);\n      rt=G.update(rt,y,G.count(rt),P(-z,0));\n     \
    \ rt=G.update(rt,0,y,P(0,z));\n    }\n\n    if(x=='Q'){\n      T prv=G.get_val(rt,y-1);\n\
    \      T cur=G.query(rt,y,z);\n      T nxt=G.get_val(rt,z);\n      int ans=0;\n\
    \      if(get<0>(prv)>get<0>(cur)) ans+=get<0>(prv)-get<0>(cur);\n      if(get<1>(nxt)>get<1>(cur))\
    \ ans+=get<1>(nxt)-get<1>(cur);\n      printf(\"%d\\n\",ans);\n    }\n  }\n\n\
    \  return 0;\n}\n/*\n  verified on 2019/12/27\n  https://atcoder.jp/contests/code-festival-2014-exhibition-open/tasks/code_festival_exhibition_b\n\
    */\n\nsigned main(){\n  CODEFESTIVAL2014EXHIBITION_B();\n  return 0;\n}\n#endif\n"
  dependsOn:
  - bbst/rbst/basic/base.cpp
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/basic/base.cpp
    title: bbst/rbst/basic/base.cpp
  extendedRequiredBy:
  - icon: ':warning:'
    path: bbst/rbst/persistent/lazy.cpp
    title: bbst/rbst/persistent/lazy.cpp
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I.bbst.test.cpp
    title: test/aoj/DSL_2_I.bbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.bbst.test.cpp
    title: test/aoj/DSL_2_G.bbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H.bbst.test.cpp
    title: test/aoj/DSL_2_H.bbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.bbst.test.cpp
    title: test/aoj/DSL_2_F.bbst.test.cpp
  isVerificationFile: false
  path: bbst/rbst/basic/lazy.cpp
  requiredBy:
  - bbst/rbst/persistent/lazy.cpp
  timestamp: '2020-05-09 16:23:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - test/aoj/DSL_2_I.bbst.test.cpp
  - test/aoj/DSL_2_G.bbst.test.cpp
  - test/aoj/DSL_2_H.bbst.test.cpp
  - test/aoj/DSL_2_F.bbst.test.cpp
documentation_of: bbst/rbst/basic/lazy.cpp
layout: document
redirect_from:
- /library/bbst/rbst/basic/lazy.cpp
- /library/bbst/rbst/basic/lazy.cpp.html
title: bbst/rbst/basic/lazy.cpp
---
