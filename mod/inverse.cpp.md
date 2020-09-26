---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/extgcd.cpp
    title: math/extgcd.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/linearcongruence.cpp
    title: math/linearcongruence.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2970.test.cpp
    title: test/aoj/2970.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2659.test.cpp
    title: test/aoj/2659.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ mod/inverse.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../math/extgcd.cpp\"\n#undef call_from_test\n\
    \n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nT mod_inverse(T a,T mod){\n\
    \  T x,y;\n  extgcd(a,mod,x,y);\n  return (x%mod+mod)%mod;\n}\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  dependsOn:
  - math/extgcd.cpp
  isVerificationFile: false
  path: mod/inverse.cpp
  requiredBy:
  - math/linearcongruence.cpp
  timestamp: '2020-09-21 00:38:13+09:00'
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
