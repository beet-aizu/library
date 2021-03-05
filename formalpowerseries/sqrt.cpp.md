---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/base.cpp
    title: formalpowerseries/base.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/inv.cpp
    title: formalpowerseries/inv.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: includes/formalpowerseries.h
    title: includes/formalpowerseries.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sqrt_of_formal_power_series.test.cpp
    title: test/yosupo/sqrt_of_formal_power_series.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ formalpowerseries/sqrt.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../combinatorics/enumeration.cpp\"\n#include\
    \ \"base.cpp\"\n#include \"inv.cpp\"\n#undef call_from_test\n\n#endif\n//BEGIN\
    \ CUT HERE\ntemplate<typename M>\nvector<M> FormalPowerSeries<M>::sqrt(Poly as,int\
    \ deg){\n  assert(as[0]==M(1));\n  M inv2=M(1)/M(2);\n  Poly ss({M(1)});\n  for(int\
    \ i=1;i<deg;i<<=1){\n    ss=pre(add(ss,mul(pre(as,i<<1),inv(ss,i<<1))),i<<1);\n\
    \    for(M &x:ss) x*=inv2;\n  }\n  return ss;\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - combinatorics/enumeration.cpp
  - formalpowerseries/base.cpp
  - formalpowerseries/inv.cpp
  isVerificationFile: false
  path: formalpowerseries/sqrt.cpp
  requiredBy:
  - includes/formalpowerseries.h
  timestamp: '2020-11-22 16:25:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/sqrt_of_formal_power_series.test.cpp
documentation_of: formalpowerseries/sqrt.cpp
layout: document
redirect_from:
- /library/formalpowerseries/sqrt.cpp
- /library/formalpowerseries/sqrt.cpp.html
title: formalpowerseries/sqrt.cpp
---
