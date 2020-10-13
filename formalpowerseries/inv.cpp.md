---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  - icon: ':warning:'
    path: formalpowerseries/base.cpp
    title: formalpowerseries/base.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: formalpowerseries/div.cpp
    title: formalpowerseries/div.cpp
  - icon: ':warning:'
    path: formalpowerseries/exp.cpp
    title: formalpowerseries/exp.cpp
  - icon: ':warning:'
    path: formalpowerseries/log.cpp
    title: formalpowerseries/log.cpp
  - icon: ':warning:'
    path: formalpowerseries/mod.cpp
    title: formalpowerseries/mod.cpp
  - icon: ':warning:'
    path: formalpowerseries/pow.cpp
    title: formalpowerseries/pow.cpp
  - icon: ':warning:'
    path: formalpowerseries/sqrt.cpp
    title: formalpowerseries/sqrt.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ formalpowerseries/inv.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../combinatorics/enumeration.cpp\"\n#include\
    \ \"./base.cpp\"\n#undef call_from_test\n\n#endif\n//BEGIN CUT HERE\ntemplate<typename\
    \ M>\nvector<M> FormalPowerSeries<M>::inv(Poly as,int deg){\n  assert(as[0]!=M(0));\n\
    \  Poly rs({M(1)/as[0]});\n  for(int i=1;i<deg;i<<=1)\n    rs=pre(sub(add(rs,rs),mul(mul(rs,rs),pre(as,i<<1))),i<<1);\n\
    \  return rs;\n}\n\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - combinatorics/enumeration.cpp
  - formalpowerseries/base.cpp
  isVerificationFile: false
  path: formalpowerseries/inv.cpp
  requiredBy:
  - formalpowerseries/pow.cpp
  - formalpowerseries/log.cpp
  - formalpowerseries/exp.cpp
  - formalpowerseries/div.cpp
  - formalpowerseries/mod.cpp
  - formalpowerseries/sqrt.cpp
  timestamp: '2020-10-13 15:11:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: formalpowerseries/inv.cpp
layout: document
redirect_from:
- /library/formalpowerseries/inv.cpp
- /library/formalpowerseries/inv.cpp.html
title: formalpowerseries/inv.cpp
---
