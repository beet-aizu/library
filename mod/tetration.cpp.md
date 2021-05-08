---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/totient.cpp
    title: math/totient.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/tetration_mod.test.cpp
    title: test/yosupo/tetration_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0472.test.cpp
    title: test/yukicoder/0472.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ mod/tetration.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../math/totient.cpp\"\n#undef call_from_test\n\
    \n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nT mpow(T a,T n,T m,T &f){\n\
    \  using ull = unsigned long long;\n  if(a==1 or n==0) return 1;\n  ull v=1,x=a,z=m;\n\
    \  f|=x>=z;\n  x%=m;\n  while(1){\n    if(n&1) v*=x;\n    if(v>=z) f=1,v%=m;\n\
    \    n>>=1;\n    if(!n) break;\n    x=x*x;\n    if(x>=z) f=1,x%=m;\n  }\n  return\
    \ v;\n}\n\n// a^a^a^... (repeat n times)\n// MOD can be composite numbers\ntemplate<typename\
    \ T>\nT tetration(T a,T n,const T MOD,T &f){\n  if(a==0) return ~n&1;\n  if(MOD==1)\
    \ return f=1;\n  if(a==1 or n==0) return 1;\n  if(n==1){\n    f|=a>=MOD;\n   \
    \ return a%MOD+f*MOD;\n  }\n  T z=tetration(a,n-1,totient(MOD),f);\n  T r=mpow(a,z,MOD,f);\n\
    \  return r+f*MOD;\n}\n\n// MOD can be composite numbers\ntemplate<typename T>\n\
    T tetration(T a,T n,const T MOD){\n  T f=0;\n  return tetration(a,n,MOD,f)%MOD;\n\
    }\n\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn:
  - math/totient.cpp
  isVerificationFile: false
  path: mod/tetration.cpp
  requiredBy: []
  timestamp: '2020-11-13 17:57:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/0472.test.cpp
  - test/yosupo/tetration_mod.test.cpp
documentation_of: mod/tetration.cpp
layout: document
redirect_from:
- /library/mod/tetration.cpp
- /library/mod/tetration.cpp.html
title: mod/tetration.cpp
---
