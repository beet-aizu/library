---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/levelancestor.cpp
    title: tree/levelancestor.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/3405.test.cpp
    title: test/yukicoder/3405.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ tree/eulertourforbfs.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"levelancestor.cpp\"\n#undef call_from_test\n\
    \n#endif\n\n//BEGIN CUT HERE\nstruct EulerTourForBFS : LevelAncestor{\n  using\
    \ super = LevelAncestor;\n  vector<int> ls;\n  vector<vector<int>> H;\n  EulerTourForBFS(int\
    \ n):super(n),ls(n),H(n){}\n\n  using super::par;\n  using super::dep;\n  void\
    \ build(int r=0){\n    super::build(r);\n    int pos=0;\n    queue<int> que;\n\
    \    que.emplace(r);\n    while(!que.empty()){\n      int v=que.front();que.pop();\n\
    \      ls[v]=pos++;\n      H[dep[v]].emplace_back(v);\n      for(int u:super::G[v]){\n\
    \        if(u==par[0][v]) continue;\n        que.emplace(u);\n      }\n    }\n\
    \  }\n\n  int idx(int v){return ls[v];}\n\n  int find(int v,int d,int a){\n  \
    \  int l=-1,r=H[d].size();\n    while(l+1<r){\n      int m=(l+r)>>1;\n      int\
    \ p=super::up(H[d][m],d-dep[v]);\n      if(ls[v]+a<=ls[p]) r=m;\n      else l=m;\n\
    \    }\n    return ls[H[d][0]]+r;\n  }\n\n  template<typename F>\n  void exec(int\
    \ v,int d,F f){\n    if(dep[v]+d>=(int)H.size()) return;\n    if(H[dep[v]+d].empty())\
    \ return;\n    int l=find(v,dep[v]+d,0);\n    int r=find(v,dep[v]+d,1);\n    if(l<r)\
    \ f(l,r);\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n \
    \ return 0;\n}\n#endif\n"
  dependsOn:
  - tree/levelancestor.cpp
  isVerificationFile: false
  path: tree/eulertourforbfs.cpp
  requiredBy: []
  timestamp: '2020-11-02 16:08:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/3405.test.cpp
documentation_of: tree/eulertourforbfs.cpp
layout: document
redirect_from:
- /library/tree/eulertourforbfs.cpp
- /library/tree/eulertourforbfs.cpp.html
title: tree/eulertourforbfs.cpp
---
