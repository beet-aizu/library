---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_C.test.cpp
    title: test/aoj/DPL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_I.test.cpp
    title: test/aoj/DPL_5_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2772.test.cpp
    title: test/yukicoder/2772.test.cpp
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
    \ combinatorics/surjection.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"enumeration.cpp\"\n#undef call_from_test\n\n\
    #endif\n//BEGIN CUT HERE\n// put n distinct balls into k distinct boxes\ntemplate<typename\
    \ M>\nM surjection(int n,int k){\n  using E = Enumeration<M>;\n  E::init(k);\n\
    \  M res(0);\n  for(int i=1;i<=k;i++){\n    M tmp=E::C(k,i)*M(i).pow(n);\n   \
    \ if((k-i)&1) res-=tmp;\n    else res+=tmp;\n  }\n  return res;\n}\n//END CUT\
    \ HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - combinatorics/enumeration.cpp
  isVerificationFile: false
  path: combinatorics/surjection.cpp
  requiredBy: []
  timestamp: '2020-10-27 13:13:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/2772.test.cpp
  - test/aoj/DPL_5_C.test.cpp
  - test/aoj/DPL_5_I.test.cpp
documentation_of: combinatorics/surjection.cpp
layout: document
redirect_from:
- /library/combinatorics/surjection.cpp
- /library/combinatorics/surjection.cpp.html
title: combinatorics/surjection.cpp
---
