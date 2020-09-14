---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: polynomial/formalpowerseries.cpp
    title: polynomial/formalpowerseries.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: polynomial/interpolate.cpp
    title: polynomial/interpolate.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/polynomial_interpolation.test.cpp
    title: test/yosupo/polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/multipoint_evaluation.test.cpp
    title: test/yosupo/multipoint_evaluation.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 189, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ polynomial/multieval.cpp: line 8: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define call_from_test\n#include \"formalpowerseries.cpp\"\n#undef call_from_test\n\
    \n#endif\n//BEGIN CUT HERE\n// O(N log^2 N)\ntemplate<typename T>\nstruct MultiEval{\n\
    \  FormalPowerSeries<T> FPS;\n  using Poly = typename FormalPowerSeries<T>::Poly;\n\
    \  using Conv = typename FormalPowerSeries<T>::Conv;\n\n  MultiEval(Conv conv):FPS(conv){}\n\
    \n  using P = pair<int, int>;\n  map<P, Poly> mem;\n  void dfs(const vector<T>\
    \ &cs,int l,int r){\n    if(l+1==r){\n      mem[{l,r}]=Poly({-cs[l],T(1)});\n\
    \      return;\n    }\n    int m=(l+r)>>1;\n    dfs(cs,l,m);\n    dfs(cs,m,r);\n\
    \    mem[{l,r}]=FPS.mul(mem[{l,m}],mem[{m,r}]);\n  }\n\n  void multi_eval(Poly\
    \ ps,vector<T> &ws,int l,int r){\n    if(l+1==r){\n      ws[l]=FPS.mod(ps,mem[{l,r}])[0];\n\
    \      return;\n    }\n    int m=(l+r)>>1;\n    multi_eval(FPS.mod(ps,mem[{l,m}]),ws,l,m);\n\
    \    multi_eval(FPS.mod(ps,mem[{m,r}]),ws,m,r);\n  }\n\n  vector<T> build(Poly\
    \ ps,const vector<T> &cs){\n    int n=cs.size();\n    mem.clear();\n    dfs(cs,0,n);\n\
    \    vector<T> ws(n);\n    multi_eval(ps,ws,0,n);\n    return ws;\n  }\n};\n//END\
    \ CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - polynomial/formalpowerseries.cpp
  isVerificationFile: false
  path: polynomial/multieval.cpp
  requiredBy:
  - polynomial/interpolate.cpp
  timestamp: '2020-05-16 18:51:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/polynomial_interpolation.test.cpp
  - test/yosupo/multipoint_evaluation.test.cpp
documentation_of: polynomial/multieval.cpp
layout: document
redirect_from:
- /library/polynomial/multieval.cpp
- /library/polynomial/multieval.cpp.html
title: polynomial/multieval.cpp
---
