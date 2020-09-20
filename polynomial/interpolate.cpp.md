---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: polynomial/formalpowerseries.cpp
    title: polynomial/formalpowerseries.cpp
  - icon: ':heavy_check_mark:'
    path: polynomial/multieval.cpp
    title: polynomial/multieval.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/polynomial_interpolation.test.cpp
    title: test/yosupo/polynomial_interpolation.test.cpp
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
    \ polynomial/interpolate.cpp: line 8: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define call_from_test\n#include \"formalpowerseries.cpp\"\n#include\
    \ \"multieval.cpp\"\n#undef call_from_test\n\n#endif\n//BEGIN CUT HERE\n// O(N\
    \ log^2 N)\ntemplate<typename T>\nstruct Interpolate : MultiEval<T>{\n  using\
    \ super=MultiEval<T>;\n  using super::super;\n\n  using typename super::Poly;\n\
    \  using super::FPS;\n  using super::mem;\n\n  Poly interpolate(const vector<T>\
    \ &xs,const vector<T> &ws,int l,int r){\n    if(l+1==r) return Poly({ws[l]});\n\
    \    int m=(l+r)>>1;\n    return FPS.add(FPS.mul(interpolate(xs,ws,l,m),mem[{m,r}]),\n\
    \                   FPS.mul(interpolate(xs,ws,m,r),mem[{l,m}]));\n  }\n\n  vector<T>\
    \ build(const vector<T> &xs,const vector<T> &ys){\n    int n=xs.size();\n    mem.clear();\n\
    \    super::dfs(xs,0,n);\n    auto ls=FPS.diff(mem[{0,n}]);\n    ls.resize(n,T(0));\n\
    \    vector<T> ws(n);\n    super::multi_eval(ls,ws,0,n);\n    for(int i=0;i<n;i++)\
    \ ws[i]=ys[i]/ws[i];\n    return interpolate(xs,ws,0,n);\n  }\n};\n//END CUT HERE\n\
    #ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - polynomial/formalpowerseries.cpp
  - polynomial/multieval.cpp
  isVerificationFile: false
  path: polynomial/interpolate.cpp
  requiredBy: []
  timestamp: '2020-05-16 18:51:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/polynomial_interpolation.test.cpp
documentation_of: polynomial/interpolate.cpp
layout: document
redirect_from:
- /library/polynomial/interpolate.cpp
- /library/polynomial/interpolate.cpp.html
title: polynomial/interpolate.cpp
---
