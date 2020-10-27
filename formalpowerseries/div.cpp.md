---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  - icon: ':question:'
    path: formalpowerseries/base.cpp
    title: formalpowerseries/base.cpp
  - icon: ':question:'
    path: formalpowerseries/inv.cpp
    title: formalpowerseries/inv.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/mod.cpp
    title: formalpowerseries/mod.cpp
  - icon: ':heavy_check_mark:'
    path: polynomial/interpolate.cpp
    title: polynomial/interpolate.cpp
  - icon: ':heavy_check_mark:'
    path: polynomial/multieval.cpp
    title: polynomial/multieval.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/multipoint_evaluation.test.cpp
    title: test/yosupo/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/polynomial_interpolation.test.cpp
    title: test/yosupo/polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0444.test.cpp
    title: test/yukicoder/0444.test.cpp
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
    \ formalpowerseries/div.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../combinatorics/enumeration.cpp\"\n#include\
    \ \"base.cpp\"\n#include \"inv.cpp\"\n#undef call_from_test\n\n#endif\n//BEGIN\
    \ CUT HERE\ntemplate<typename M>\nvector<M> FormalPowerSeries<M>::div(Poly as,Poly\
    \ bs){\n  while(as.back()==M(0)) as.pop_back();\n  while(bs.back()==M(0)) bs.pop_back();\n\
    \  if(bs.size()>as.size()) return Poly();\n  reverse(as.begin(),as.end());\n \
    \ reverse(bs.begin(),bs.end());\n  int need=as.size()-bs.size()+1;\n  Poly ds=pre(mul(as,inv(bs,need)),need);\n\
    \  reverse(ds.begin(),ds.end());\n  return ds;\n}\n\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - combinatorics/enumeration.cpp
  - formalpowerseries/base.cpp
  - formalpowerseries/inv.cpp
  isVerificationFile: false
  path: formalpowerseries/div.cpp
  requiredBy:
  - polynomial/interpolate.cpp
  - polynomial/multieval.cpp
  - formalpowerseries/mod.cpp
  timestamp: '2020-10-27 13:13:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/0444.test.cpp
  - test/yosupo/polynomial_interpolation.test.cpp
  - test/yosupo/multipoint_evaluation.test.cpp
documentation_of: formalpowerseries/div.cpp
layout: document
redirect_from:
- /library/formalpowerseries/div.cpp
- /library/formalpowerseries/div.cpp.html
title: formalpowerseries/div.cpp
---
