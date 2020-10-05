---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/mo.cpp
    title: algorithm/mo.cpp
  - icon: ':heavy_check_mark:'
    path: tree/eulertourforedge.cpp
    title: tree/eulertourforedge.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2270.test.cpp
    title: test/aoj/2270.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ tree/mo_on_tree.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../algorithm/mo.cpp\"\n#include \"../tree/eulertourforedge.cpp\"\
    \n#undef call_from_test\n\n#endif\n//BEGIN CUT HERE\nstruct MoOnTree{\n  Mo* mo;\n\
    \  using F = Mo::F;\n  EulerTourForEdge et;\n  vector<int> app,idx;\n  int width;\n\
    \  F expand,shrink;\n  MoOnTree(int n,int width,F expand,F shrink):\n    et(n),app(n,0),idx(n),width(width),expand(expand),shrink(shrink){}\n\
    \  vector<pair<int,int>> es,qs;\n  void add_edge(int u,int v){\n    es.emplace_back(u,v);\n\
    \    et.add_edge(u,v);\n  }\n  void add_query(int u,int v){\n    qs.emplace_back(u,v);\n\
    \  }\n  void build(){\n    et.build();\n    int num=0;\n    for(auto[u,v]:es)\
    \ idx[et.child(u,v)]=num++;\n    F exec=[&](int k){\n      int v=et.bottom(k);\n\
    \      int e=idx[v];\n      app[v]^=1;\n      if(app[v]) expand(e);\n      else\
    \ shrink(e);\n    };\n    int n=et.G.size();\n    mo=new Mo(2*n,width,exec,exec);\n\
    \    auto f=[&](int l,int r){mo->add(min(l,r),max(l,r));};\n    for(auto[u,v]:qs)\
    \ et.query(u,v,f);\n    mo->build();\n  }\n  int process(){return mo->process();}\n\
    };\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn:
  - algorithm/mo.cpp
  - tree/eulertourforedge.cpp
  isVerificationFile: false
  path: tree/mo_on_tree.cpp
  requiredBy: []
  timestamp: '2020-10-05 17:05:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2270.test.cpp
documentation_of: tree/mo_on_tree.cpp
layout: document
redirect_from:
- /library/tree/mo_on_tree.cpp
- /library/tree/mo_on_tree.cpp.html
title: tree/mo_on_tree.cpp
---
