---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/extgcd.cpp
    title: math/extgcd.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/combination.cpp
    title: math/combination.cpp
  - icon: ':heavy_check_mark:'
    path: math/linearcongruence.cpp
    title: math/linearcongruence.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2659.test.cpp
    title: test/aoj/2659.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2970.test.cpp
    title: test/aoj/2970.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ mod/inverse.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../math/extgcd.cpp\"\n#undef call_from_test\n\
    \n#endif\n//BEGIN CUT HERE\n// a, MOD coprime\ntemplate<typename T>\nT mod_inverse(T\
    \ a,const T MOD){\n  T x,y;\n  extgcd(a,MOD,x,y);\n  return (x%MOD+MOD)%MOD;\n\
    }\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn:
  - math/extgcd.cpp
  isVerificationFile: false
  path: mod/inverse.cpp
  requiredBy:
  - math/combination.cpp
  - math/linearcongruence.cpp
  timestamp: '2021-06-20 16:57:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2970.test.cpp
  - test/aoj/2659.test.cpp
documentation_of: mod/inverse.cpp
layout: document
redirect_from:
- /library/mod/inverse.cpp
- /library/mod/inverse.cpp.html
title: mod/inverse.cpp
---
