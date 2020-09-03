---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ combinatorics/surjection.cpp: line 8: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define call_from_test\n#include \"enumeration.cpp\"\n#undef call_from_test\n\
    \n#endif\n//BEGIN CUT HERE\n// put n distinct balls into k distinct boxes\ntemplate<typename\
    \ M>\nM surjection(int n,int k){\n  using E = Enumeration<M>;\n  E::init(k);\n\
    \  M res(0);\n  for(int i=1;i<=k;i++){\n    M tmp=E::C(k,i)*M(i).pow(n);\n   \
    \ if((k-i)&1) res-=tmp;\n    else res+=tmp;\n  }\n  return res;\n}\n//END CUT\
    \ HERE\n\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - combinatorics/enumeration.cpp
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_I.test.cpp
    title: test/aoj/DPL_5_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_C.test.cpp
    title: test/aoj/DPL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2772.test.cpp
    title: test/yukicoder/2772.test.cpp
  isVerificationFile: false
  path: combinatorics/surjection.cpp
  requiredBy: []
  timestamp: '2020-03-12 17:02:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - test/aoj/DPL_5_I.test.cpp
  - test/aoj/DPL_5_C.test.cpp
  - test/yukicoder/2772.test.cpp
documentation_of: combinatorics/surjection.cpp
layout: document
redirect_from:
- /library/combinatorics/surjection.cpp
- /library/combinatorics/surjection.cpp.html
title: combinatorics/surjection.cpp
---
