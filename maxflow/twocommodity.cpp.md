---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: maxflow/dinic.cpp
    title: "\u6700\u5927\u6D41"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2979.test.cpp
    title: test/aoj/2979.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ maxflow/twocommodity.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"./dinic.cpp\"\n#undef call_from_test\n\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename Flow, bool directed>\nstruct TwoCommodity{\n\
    \  Dinic<Flow, directed> G,H;\n  int S,T;\n  TwoCommodity(int n):G(n+2),H(n+2),S(n),T(n+1){}\n\
    \n  void add_edge(int src,int dst,Flow cap){\n    G.add_edge(src,dst,cap);\n \
    \   H.add_edge(src,dst,cap);\n  }\n\n  // maximize sum of two flows (s -> t) and\
    \ (u -> v)\n  Flow build(int s,int t,int u,int v){\n    const Flow INF = numeric_limits<Flow>::max()/4;\n\
    \n    G.add_edge(S,s,INF);\n    G.add_edge(S,u,INF);\n    G.add_edge(t,T,INF);\n\
    \    G.add_edge(v,T,INF);\n\n    H.add_edge(S,s,INF);\n    H.add_edge(S,v,INF);\n\
    \    H.add_edge(t,T,INF);\n    H.add_edge(u,T,INF);\n\n    return min(G.flow(S,T),H.flow(S,T));\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - maxflow/dinic.cpp
  isVerificationFile: false
  path: maxflow/twocommodity.cpp
  requiredBy: []
  timestamp: '2020-10-27 18:08:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2979.test.cpp
documentation_of: maxflow/twocommodity.cpp
layout: document
title: "\u6700\u5927\u4E8C\u54C1\u7A2E\u6D41"
---

## 解説記事
[多品種流の話](http://www.kurims.kyoto-u.ac.jp/~kenkyubu/kokai-koza/hirai.pdf)
