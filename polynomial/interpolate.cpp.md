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
    path: formalpowerseries/diff.cpp
    title: formalpowerseries/diff.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/div.cpp
    title: formalpowerseries/div.cpp
  - icon: ':question:'
    path: formalpowerseries/inv.cpp
    title: formalpowerseries/inv.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/mod.cpp
    title: formalpowerseries/mod.cpp
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
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ polynomial/interpolate.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../combinatorics/enumeration.cpp\"\n#include\
    \ \"../formalpowerseries/base.cpp\"\n#include \"../formalpowerseries/inv.cpp\"\
    \n#include \"../formalpowerseries/div.cpp\"\n#include \"../formalpowerseries/mod.cpp\"\
    \n#include \"../formalpowerseries/diff.cpp\"\n#include \"multieval.cpp\"\n#undef\
    \ call_from_test\n\n#endif\n//BEGIN CUT HERE\n// O(N log^2 N)\ntemplate<typename\
    \ T>\nstruct Interpolate : MultiEval<T>{\n  using super = MultiEval<T>;\n  using\
    \ typename super::Poly;\n  using super::super, super::FPS, super::mem;\n\n  Poly\
    \ interpolate(const vector<T> &xs,const vector<T> &ws,int l,int r){\n    if(l+1==r)\
    \ return Poly({ws[l]});\n    int m=(l+r)>>1;\n    return FPS.add(FPS.mul(interpolate(xs,ws,l,m),mem[{m,r}]),\n\
    \                   FPS.mul(interpolate(xs,ws,m,r),mem[{l,m}]));\n  }\n\n  vector<T>\
    \ build(const vector<T> &xs,const vector<T> &ys){\n    int n=xs.size();\n    mem.clear();\n\
    \    super::dfs(xs,0,n);\n    auto ls=FPS.diff(mem[{0,n}]);\n    ls.resize(n,T(0));\n\
    \    vector<T> ws(n);\n    super::multi_eval(ls,ws,0,n);\n    for(int i=0;i<n;i++)\
    \ ws[i]=ys[i]/ws[i];\n    return interpolate(xs,ws,0,n);\n  }\n};\n//END CUT HERE\n\
    #ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - combinatorics/enumeration.cpp
  - formalpowerseries/base.cpp
  - formalpowerseries/inv.cpp
  - formalpowerseries/div.cpp
  - formalpowerseries/mod.cpp
  - formalpowerseries/diff.cpp
  - polynomial/multieval.cpp
  isVerificationFile: false
  path: polynomial/interpolate.cpp
  requiredBy: []
  timestamp: '2020-10-27 13:13:52+09:00'
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
