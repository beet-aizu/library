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
    \ mod/tetration.cpp: line 8: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define call_from_test\n#include \"../math/totient.cpp\"\n#undef call_from_test\n\
    \n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nT mpow(T a,T n,T m,T &f){\n\
    \  using ull = unsigned long long;\n  if(a==1||n==0) return 1;\n  ull v=1,x=a,z=m;\n\
    \  f|=x>=z;\n  x%=m;\n  while(1){\n    if(n&1) v*=x;\n    if(v>=z) f=1,v%=m;\n\
    \    n>>=1;\n    if(!n) break;\n    x=x*x;\n    if(x>=z) f=1,x%=m;\n  }\n  return\
    \ v;\n}\n\ntemplate<typename T>\nT tetration(T a,T n,T m,T &f){\n  if(a==0) return\
    \ ~n&1;\n  if(m==1) return f=1;\n  if(a==1||n==0) return 1;\n  if(n==1){\n   \
    \ f|=a>=m;\n    return a%m+f*m;\n  }\n  T z=tetration(a,n-1,totient(m),f);\n \
    \ T r=mpow(a,z,m,f);\n  return r+f*m;\n}\n\ntemplate<typename T>\nT tetration(T\
    \ a,T n,T m){\n  T f=0;\n  return tetration(a,n,m,f)%m;\n}\n//END CUT HERE\n#ifndef\
    \ call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - math/totient.cpp
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/totient.cpp
    title: math/totient.cpp
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/tetration_mod.test.cpp
    title: test/yosupo/tetration_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0472.test.cpp
    title: test/yukicoder/0472.test.cpp
  isVerificationFile: false
  path: mod/tetration.cpp
  requiredBy: []
  timestamp: '2020-03-12 17:15:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - test/yosupo/tetration_mod.test.cpp
  - test/yukicoder/0472.test.cpp
documentation_of: mod/tetration.cpp
layout: document
redirect_from:
- /library/mod/tetration.cpp
- /library/mod/tetration.cpp.html
title: mod/tetration.cpp
---
