---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: flow/primaldual.cpp
    title: flow/primaldual.cpp
  - icon: ':heavy_check_mark:'
    path: tools/fastio.cpp
    title: tools/fastio.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2230.test.cpp
    title: test/aoj/2230.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2627.test.cpp
    title: test/aoj/2627.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2872.test.cpp
    title: test/aoj/2872.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 67, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ flow/negativeedge.cpp: line 6: unable to process #include in #if / #ifdef /\
    \ #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"primaldual.cpp\"\n#undef call_from_test\n\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename TF,typename TC>\nstruct NegativeEdge{\n\
    \  PrimalDual<TF, TC> G;\n  vector<TF> fs;\n  TC sum;\n  int S,T;\n  NegativeEdge(){}\n\
    \  NegativeEdge(int n):G(n+2),fs(n+2,0),sum(0),S(n),T(n+1){}\n\n  void use_edge(int\
    \ u,int v,TF cap,TC cost){\n    fs[u]-=cap;\n    fs[v]+=cap;\n    sum=sum+cost*cap;\n\
    \  }\n\n  void add_edge(int u,int v,TF cap,TC cost){\n    if(cost<TC(0)){\n  \
    \    use_edge(u,v,cap,cost);\n      swap(u,v);\n      cost=-cost;\n    }\n   \
    \ G.add_edge(u,v,cap,cost);\n  }\n\n  TC flow(int &ok){\n    TF f=0;\n    for(int\
    \ i=0;i<S;i++){\n      if(fs[i]>0){\n        f+=fs[i];\n        G.add_edge(S,i,+fs[i],TC(0));\n\
    \      }\n      if(fs[i]<0){\n        G.add_edge(i,T,-fs[i],TC(0));\n      }\n\
    \    }\n    return sum+G.flow(S,T,f,ok);\n  }\n\n  TC flow(int ts,int tt,TF tf,int\
    \ &ok){\n    fs[ts]+=tf;\n    fs[tt]-=tf;\n    return flow(ok);\n  }\n};\n//END\
    \ CUT HERE\n#ifndef call_from_test\n\n#define call_from_test\n#include \"../tools/fastio.cpp\"\
    \n#undef call_from_test\n\n//INSERT ABOVE HERE\nsigned KUPC2019_H(){\n  int n,m;\n\
    \  cin>>n>>m;\n  NegativeEdge<int, int> G(n+2);\n\n  int cap=1;\n  for(int i=0;i<m;i++){\n\
    \    int u,v,l;\n    cin>>u>>v>>l;\n    u--;v--;\n    G.add_edge(v,u,1,l-1);\n\
    \    if(l==0) cap++;\n  }\n\n  for(int i=0;i<n;i++){\n    G.add_edge(n,i,cap,2);\n\
    \    G.add_edge(i,n,cap,0);\n  }\n\n  int ok=0;\n  cout<<-G.flow(n,n,0,ok)<<endl;\n\
    \  return 0;\n}\n/*\n  verified on 2019/12/26\n  https://atcoder.jp/contests/kupc2019/tasks/kupc2019_h\n\
    */\n\nsigned main(){\n  //KUPC2019_H();\n  return 0;\n}\n#endif\n"
  dependsOn:
  - flow/primaldual.cpp
  - tools/fastio.cpp
  isVerificationFile: false
  path: flow/negativeedge.cpp
  requiredBy: []
  timestamp: '2020-09-14 19:56:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2230.test.cpp
  - test/aoj/2627.test.cpp
  - test/aoj/2872.test.cpp
documentation_of: ./flow/negativeedge.cpp
layout: document
title: "\u8CA0\u8FBA\u9664\u53BB"
---

## 解説記事
https://snuke.hatenablog.com/entry/2017/06/07/115821
