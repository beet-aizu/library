---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  - icon: ':question:'
    path: formalpowerseries/base.cpp
    title: formalpowerseries/base.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/div.cpp
    title: formalpowerseries/div.cpp
  - icon: ':question:'
    path: formalpowerseries/inv.cpp
    title: formalpowerseries/inv.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/mod.cpp
    title: formalpowerseries/mod.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: polynomial/interpolate.cpp
    title: polynomial/interpolate.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/multipoint_evaluation.test.cpp
    title: test/yosupo/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/polynomial_interpolation.test.cpp
    title: test/yosupo/polynomial_interpolation.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ polynomial/multieval.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../combinatorics/enumeration.cpp\"\n#include\
    \ \"../formalpowerseries/base.cpp\"\n#include \"../formalpowerseries/inv.cpp\"\
    \n#include \"../formalpowerseries/div.cpp\"\n#include \"../formalpowerseries/mod.cpp\"\
    \n#undef call_from_test\n\n#endif\n//BEGIN CUT HERE\n// O(N log^2 N)\ntemplate<typename\
    \ T>\nstruct MultiEval{\n  FormalPowerSeries<T> FPS;\n  using Poly = typename\
    \ FormalPowerSeries<T>::Poly;\n  using Conv = typename FormalPowerSeries<T>::Conv;\n\
    \n  MultiEval(Conv conv):FPS(conv){}\n\n  using P = pair<int, int>;\n  map<P,\
    \ Poly> mem;\n  void dfs(const vector<T> &cs,int l,int r){\n    if(l+1==r){\n\
    \      mem[{l,r}]=Poly({-cs[l],T(1)});\n      return;\n    }\n    int m=(l+r)>>1;\n\
    \    dfs(cs,l,m);\n    dfs(cs,m,r);\n    mem[{l,r}]=FPS.mul(mem[{l,m}],mem[{m,r}]);\n\
    \  }\n\n  void multi_eval(Poly ps,vector<T> &ws,int l,int r){\n    if(l+1==r){\n\
    \      ws[l]=FPS.mod(ps,mem[{l,r}])[0];\n      return;\n    }\n    int m=(l+r)>>1;\n\
    \    multi_eval(FPS.mod(ps,mem[{l,m}]),ws,l,m);\n    multi_eval(FPS.mod(ps,mem[{m,r}]),ws,m,r);\n\
    \  }\n\n  vector<T> build(Poly ps,const vector<T> &cs){\n    int n=cs.size();\n\
    \    mem.clear();\n    dfs(cs,0,n);\n    vector<T> ws(n);\n    multi_eval(ps,ws,0,n);\n\
    \    return ws;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn:
  - combinatorics/enumeration.cpp
  - formalpowerseries/base.cpp
  - formalpowerseries/inv.cpp
  - formalpowerseries/div.cpp
  - formalpowerseries/mod.cpp
  isVerificationFile: false
  path: polynomial/multieval.cpp
  requiredBy:
  - polynomial/interpolate.cpp
  timestamp: '2021-03-25 09:21:12+09:00'
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
