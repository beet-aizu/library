---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: toptree/toptree.cpp
    title: Top Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2636.test.cpp
    title: Distance Sum
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2587.test.cpp
    title: test/yukicoder/2587.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4862.test.cpp
    title: test/yukicoder/4862.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ toptree/distancesum.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"toptree.cpp\"\n#undef call_from_test\n\n#endif\n\
    //BEGIN CUT HERE\n\nstruct Vertex{\n  void* handle;\n  // 0: dead, 1: alive\n\
    \  int color;\n  Vertex(int color=0):handle(nullptr),color(color){}\n};\n\ntemplate<typename\
    \ T>\nstruct DistanceSum{\n  struct pi{\n    T cnt;\n    Vertex* ptr;\n    pi():cnt(-1),ptr(nullptr){}\n\
    \    pi(T cnt,Vertex* ptr):cnt(cnt),ptr(ptr){}\n    bool operator<(const pi &o)const{return\
    \ cnt<o.cnt;}\n  };\n\n  T len,cnt,chd,ans;\n  T sum_l,sum_r;\n  pi md;\n\n  DistanceSum(T\
    \ len=0):len(len),cnt(0),chd(0),ans(0),sum_l(0),sum_r(0){}\n\n  void toggle(){swap(sum_l,sum_r);}\n\
    \n  static DistanceSum compress(\n    const DistanceSum& x,Vertex *v,const DistanceSum&\
    \ y){\n    DistanceSum nxt;\n    nxt.len=x.len+y.len;\n    nxt.cnt=x.cnt+x.chd+(v->color)+y.cnt;\n\
    \    nxt.chd=0;\n    assert(y.chd==0);\n\n    nxt.ans=x.sum_l+y.sum_r;\n\n   \
    \ nxt.sum_l+=x.sum_l;\n    nxt.sum_l+=y.sum_l;\n    nxt.sum_l+=(x.cnt+x.chd+(v->color))*y.len;\n\
    \n    nxt.sum_r+=x.sum_r;\n    nxt.sum_r+=y.sum_r;\n    nxt.sum_r+=(x.chd+(v->color)+y.cnt)*x.len;\n\
    \n    nxt.md=pi(nxt.cnt,v);\n\n    return nxt;\n  }\n\n  static DistanceSum rake(const\
    \ DistanceSum& x,const DistanceSum& y){\n    DistanceSum nxt;\n    nxt.len=x.len;\n\
    \    nxt.cnt=x.cnt;\n    nxt.chd=x.chd+y.cnt+y.chd;\n\n    nxt.ans=x.sum_l+y.sum_l;\n\
    \n    nxt.sum_l+=x.sum_l;\n    nxt.sum_l+=y.sum_l;\n\n    nxt.sum_r+=x.sum_r;\n\
    \    nxt.sum_r+=y.sum_l;\n\n    nxt.md=max(x.md,y.md);\n\n    return nxt;\n  }\n\
    };\n\ntemplate<typename T, size_t N>\nVertex* centroid(TopTree<Vertex, DistanceSum<T>,\
    \ N> &G, Vertex* v){\n  using TT = typename remove_reference<decltype(G)>::type;\n\
    \  using Node = typename TT::Node;\n  using Type = typename TT::Type;\n\n  Node*\
    \ rt=G.expose(v);\n  if(rt->type==Type::Edge) return v;\n\n  Node* cc=rt;\n  Vertex*\
    \ ctr=nullptr;\n\n  T lv=0,rv=0,sum=rt->dat.cnt;\n  while(cc->type==Type::Compress){\n\
    \    G.propagate(cc);\n\n    Node* ll=cc->ch[0];\n    if((ll->dat.cnt+lv)*2>sum){\n\
    \      assert(ll->type!=Type::Edge);\n      rv+=cc->dat.md.cnt-ll->dat.cnt;\n\
    \      cc=ll;\n      continue;\n    }\n\n    Node* rr=cc->ch[1];\n    if((rr->dat.cnt+rv)*2>sum){\n\
    \      assert(rr->type!=Type::Edge);\n      lv+=cc->dat.md.cnt-rr->dat.cnt;\n\
    \      cc=rr;\n      continue;\n    }\n\n    Node* mm=cc->q;\n    if(mm and mm->dat.md.cnt*2>sum){\n\
    \      assert(mm->type!=Type::Edge);\n      rv+=lv;lv=0;\n      rv+=cc->dat.md.cnt-mm->dat.md.cnt;\n\
    \      cc=(decltype(cc))mm->dat.md.ptr->handle;\n      continue;\n    }\n\n  \
    \  ctr=cc->dat.md.ptr;\n    break;\n  }\n  return ctr;\n}\n\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  dependsOn:
  - toptree/toptree.cpp
  isVerificationFile: false
  path: toptree/distancesum.cpp
  requiredBy: []
  timestamp: '2021-09-25 22:06:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/4862.test.cpp
  - test/yukicoder/2587.test.cpp
  - test/aoj/2636.test.cpp
documentation_of: toptree/distancesum.cpp
layout: document
redirect_from:
- /library/toptree/distancesum.cpp
- /library/toptree/distancesum.cpp.html
title: toptree/distancesum.cpp
---
