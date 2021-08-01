---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/stronglyconnectedcomponent.cpp
    title: graph/stronglyconnectedcomponent.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2309.tarjan.test.cpp
    title: test/aoj/2309.tarjan.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2309.test.cpp
    title: test/aoj/2309.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2647.test.cpp
    title: test/aoj/2647.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_B.test.cpp
    title: test/aoj/GRL_2_B.test.cpp
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
    \ graph/arborescence_edmond.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"stronglyconnectedcomponent.cpp\"\n#undef call_from_test\n\
    \n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct Arborescence{\n  struct\
    \ edge{\n    int to;\n    T cost;\n    edge(int to,T cost):to(to),cost(cost){}\n\
    \  };\n  vector<vector<edge>> B;\n\n  Arborescence(int n):B(n){}\n\n  void add_edge(int\
    \ u,int v,T cost){\n    assert(u!=v);\n    B[u].emplace_back(v,cost);\n  }\n\n\
    \  T build(int r){\n    T res=0;\n    auto G=B;\n    const T INF = numeric_limits<T>::max()/2;\n\
    \    while(1){\n      int n=G.size();\n      vector<T> ws(n,INF);\n      vector<int>\
    \ rs(n,-1);\n      for(int v=0;v<n;v++){\n        for(edge &e:G[v]){\n       \
    \   if(e.cost<ws[e.to]){\n            ws[e.to]=e.cost;\n            rs[e.to]=v;\n\
    \          }\n        }\n      }\n      SCC scc(n);\n      for(int i=0;i<n;i++){\n\
    \        if(i==r) continue;\n        scc.add_edge(rs[i],i);\n        res+=ws[i];\n\
    \      }\n      int m=scc.build();\n      if(m==n) break;\n      vector<vector<edge>>\
    \ H(m);\n      for(int v=0;v<n;v++){\n        for(auto &e:G[v]){\n          if(scc[v]==scc[e.to])\
    \ continue;\n          H[scc[v]].emplace_back(scc[e.to],e.cost-ws[e.to]);\n  \
    \      }\n      }\n      r=scc[r];\n      G=H;\n    }\n    return res;\n  }\n\
    };\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn:
  - graph/stronglyconnectedcomponent.cpp
  isVerificationFile: false
  path: graph/arborescence_edmond.cpp
  requiredBy: []
  timestamp: '2020-10-27 18:08:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2647.test.cpp
  - test/aoj/2309.test.cpp
  - test/aoj/2309.tarjan.test.cpp
  - test/aoj/GRL_2_B.test.cpp
documentation_of: graph/arborescence_edmond.cpp
layout: document
redirect_from:
- /library/graph/arborescence_edmond.cpp
- /library/graph/arborescence_edmond.cpp.html
title: graph/arborescence_edmond.cpp
---
