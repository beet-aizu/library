---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: toptree/toptree.cpp
    title: Top Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3143.test.cpp
    title: Farthest (with index)
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ toptree/farthest.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"toptree.cpp\"\n#undef call_from_test\n\n#endif\n\
    //BEGIN CUT HERE\nstruct Vertex{\n  void* handle;\n  Vertex():handle(nullptr){}\n\
    };\n\ntemplate<typename T>\nstruct Farthest{\n  struct pi{\n    T dist;\n    int\
    \ idx;\n    pi():dist(0),idx(-1){}\n    pi(T dist,int idx):dist(dist),idx(idx){}\n\
    \    bool operator<(const pi &o)const{return dist<o.dist;}\n    pi operator+(const\
    \ T e)const{return pi(dist+e,idx);}\n  };\n  pi md,lf,rg;\n  T len;\n  Farthest():lf(0,-1),rg(0,-1),len(0){}\n\
    \  Farthest(T d,int f,int t):lf(d,t),rg(d,f),len(d){}\n  Farthest(pi md,pi lf,pi\
    \ rg,T len):md(md),lf(lf),rg(rg),len(len){}\n  void toggle(){swap(lf,rg);}\n \
    \ static Farthest compress(Farthest &x,Vertex*,Farthest &y){\n    return Farthest(\n\
    \      max(x.rg,y.lf),\n      max(x.lf,y.lf+x.len),\n      max(y.rg,x.rg+y.len),\n\
    \      x.len+y.len);\n  }\n  static Farthest rake(Farthest &x,Farthest &y){\n\
    \    return Farthest(pi(),max(x.lf,y.rg+x.len),max(x.rg,y.rg),x.len);\n  }\n};\n\
    \ntemplate<typename T, size_t N>\nvector<int> get_all_farthests(TopTree<Vertex,\
    \ Farthest<T>, N> &G,Vertex* v){\n  using TT = typename remove_reference<decltype(G)>::type;\n\
    \  using Node = typename TT::Node;\n  using Type = typename TT::Type;\n  vector<int>\
    \ fs;\n  auto dist=G.get_subtree(v).md.dist;\n  if(dist==T(0)) return {};\n  auto\
    \ dfs=[&](auto dfs,Node* rt,T d,bool left)->void{\n    if(!rt) return;\n    G.propagate(rt);\n\
    \n    auto cur=left?(rt->dat.lf):(rt->dat.rg);\n    if(d+cur.dist!=dist) return;\n\
    \n    if(rt->type==Type::Edge){\n      if(~cur.idx) fs.emplace_back(cur.idx);\n\
    \      return;\n    }\n    if(rt->type==Type::Rake){\n      assert(!left);\n \
    \     dfs(dfs,rt->ch[0],d,false);\n      dfs(dfs,rt->ch[1],d,false);\n      return;\n\
    \    }\n    if(rt->type==Type::Compress){\n      T mid=rt->ch[left?0:1]->dat.len;\n\
    \      dfs(dfs,rt->ch[left?0:1],d,left);\n      dfs(dfs,rt->ch[left?1:0],d+mid,left);\n\
    \      dfs(dfs,rt->q,d+mid,false);\n      return;\n    }\n    abort();\n  };\n\
    \  auto rt=G.expose(v);\n  assert(rt->type==Type::Compress);\n  dfs(dfs,rt->ch[0],T(0),false);\n\
    \  dfs(dfs,rt->ch[1],T(0),true);\n  dfs(dfs,rt->q,T(0),false);\n  return fs;\n\
    }\n\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn:
  - toptree/toptree.cpp
  isVerificationFile: false
  path: toptree/farthest.cpp
  requiredBy: []
  timestamp: '2021-08-14 16:12:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3143.test.cpp
documentation_of: toptree/farthest.cpp
layout: document
redirect_from:
- /library/toptree/farthest.cpp
- /library/toptree/farthest.cpp.html
title: toptree/farthest.cpp
---
