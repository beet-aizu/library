---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  - icon: ':warning:'
    path: formalpowerseries/base.cpp
    title: formalpowerseries/base.cpp
  - icon: ':warning:'
    path: formalpowerseries/inv.cpp
    title: formalpowerseries/inv.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: formalpowerseries/exp.cpp
    title: formalpowerseries/exp.cpp
  - icon: ':warning:'
    path: formalpowerseries/pow.cpp
    title: formalpowerseries/pow.cpp
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
    \ formalpowerseries/log.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../combinatorics/enumeration.cpp\"\n#include\
    \ \"./base.cpp\"\n#include \"./inv.cpp\"\n#undef call_from_test\n\n#endif\n//BEGIN\
    \ CUT HERE\ntemplate<typename M>\nvector<M> FormalPowerSeries<M>::log(Poly as,int\
    \ deg){\n  return pre(integral(mul(diff(as),inv(as,deg))),deg);\n}\n//END CUT\
    \ HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  dependsOn:
  - combinatorics/enumeration.cpp
  - formalpowerseries/base.cpp
  - formalpowerseries/inv.cpp
  isVerificationFile: false
  path: formalpowerseries/log.cpp
  requiredBy:
  - formalpowerseries/pow.cpp
  - formalpowerseries/exp.cpp
  timestamp: '2020-10-13 15:11:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: formalpowerseries/log.cpp
layout: document
redirect_from:
- /library/formalpowerseries/log.cpp
- /library/formalpowerseries/log.cpp.html
title: formalpowerseries/log.cpp
---
