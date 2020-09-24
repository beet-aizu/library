---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mincostflow/primaldual.cpp
    title: mincostflow/primaldual.cpp
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
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ mincostflow/negativeedge.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"primaldual.cpp\"\n#undef call_from_test\n\n\
    #endif\n//BEGIN CUT HERE\n// O((F+F') E log V), F': sum of caps with negative\
    \ cost\ntemplate<typename TF,typename TC>\nstruct NegativeEdge{\n  PrimalDual<TF,\
    \ TC> G;\n  vector<TF> fs;\n  TC sum;\n  int S,T;\n  NegativeEdge(){}\n  NegativeEdge(int\
    \ n):G(n+2),fs(n+2,0),sum(0),S(n),T(n+1){}\n\n  void use_edge(int u,int v,TF cap,TC\
    \ cost){\n    fs[u]-=cap;\n    fs[v]+=cap;\n    sum=sum+cost*cap;\n  }\n\n  void\
    \ add_edge(int u,int v,TF cap,TC cost){\n    if(cost<TC(0)){\n      use_edge(u,v,cap,cost);\n\
    \      swap(u,v);\n      cost=-cost;\n    }\n    G.add_edge(u,v,cap,cost);\n \
    \ }\n\n  TC flow(int &ok){\n    TF f=0;\n    for(int i=0;i<S;i++){\n      if(fs[i]>0){\n\
    \        f+=fs[i];\n        G.add_edge(S,i,+fs[i],TC(0));\n      }\n      if(fs[i]<0){\n\
    \        G.add_edge(i,T,-fs[i],TC(0));\n      }\n    }\n    return sum+G.flow(S,T,f,ok);\n\
    \  }\n\n  TC flow(int ts,int tt,TF tf,int &ok){\n    fs[ts]+=tf;\n    fs[tt]-=tf;\n\
    \    return flow(ok);\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT\
    \ ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - mincostflow/primaldual.cpp
  isVerificationFile: false
  path: mincostflow/negativeedge.cpp
  requiredBy: []
  timestamp: '2020-09-24 12:58:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2230.test.cpp
  - test/aoj/2627.test.cpp
  - test/aoj/2872.test.cpp
documentation_of: mincostflow/negativeedge.cpp
layout: document
redirect_from:
- /library/mincostflow/negativeedge.cpp
- /library/mincostflow/negativeedge.cpp.html
title: mincostflow/negativeedge.cpp
---
