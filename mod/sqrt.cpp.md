---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sqrt_mod.test.cpp
    title: test/yosupo/sqrt_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sqrt_of_formal_power_series.test.cpp
    title: test/yosupo/sqrt_of_formal_power_series.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mod/sqrt.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nint jacobi(T a,T m){\n\
    \  int s=1;\n  if(a<0) a=a%m+m;\n  while(m>1){\n    a%=m;\n    if(a==0) return\
    \ 0;\n    int r=__builtin_ctz(a);\n    if((r&1) and ((m+2)&4)) s=-s;\n    a>>=r;\n\
    \    if(a&m&2) s=-s;\n    swap(a,m);\n  }\n  return s;\n}\n\n// MOD: prime\ntemplate<typename\
    \ T>\nvector<T> mod_sqrt(T a,const T MOD){\n  if(MOD==2) return {a&1};\n  int\
    \ j=jacobi(a,MOD);\n  if(j== 0) return {0};\n  if(j==-1) return {};\n\n  using\
    \ ll = long long;\n  mt19937 mt;\n  ll b,d;\n  while(1){\n    b=mt()%MOD;\n  \
    \  d=(b*b-a)%MOD;\n    if(d<0) d+=MOD;\n    if(jacobi<ll>(d,MOD)==-1) break;\n\
    \  }\n\n  ll f0=b,f1=1,g0=1,g1=0;\n  for(ll e=(MOD+1)>>1;e;e>>=1){\n    if(e&1){\n\
    \      ll tmp=(g0*f0+d*((g1*f1)%MOD))%MOD;\n      g1=(g0*f1+g1*f0)%MOD;\n    \
    \  g0=tmp;\n    }\n    ll tmp=(f0*f0+d*((f1*f1)%MOD))%MOD;\n    f1=(2*f0*f1)%MOD;\n\
    \    f0=tmp;\n  }\n  if(g0>MOD-g0) g0=MOD-g0;\n  return {T(g0),T(MOD-g0)};\n}\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename T>\nint jacobi(T a,T m){\n  int s=1;\n\
    \  if(a<0) a=a%m+m;\n  while(m>1){\n    a%=m;\n    if(a==0) return 0;\n    int\
    \ r=__builtin_ctz(a);\n    if((r&1) and ((m+2)&4)) s=-s;\n    a>>=r;\n    if(a&m&2)\
    \ s=-s;\n    swap(a,m);\n  }\n  return s;\n}\n\n// MOD: prime\ntemplate<typename\
    \ T>\nvector<T> mod_sqrt(T a,const T MOD){\n  if(MOD==2) return {a&1};\n  int\
    \ j=jacobi(a,MOD);\n  if(j== 0) return {0};\n  if(j==-1) return {};\n\n  using\
    \ ll = long long;\n  mt19937 mt;\n  ll b,d;\n  while(1){\n    b=mt()%MOD;\n  \
    \  d=(b*b-a)%MOD;\n    if(d<0) d+=MOD;\n    if(jacobi<ll>(d,MOD)==-1) break;\n\
    \  }\n\n  ll f0=b,f1=1,g0=1,g1=0;\n  for(ll e=(MOD+1)>>1;e;e>>=1){\n    if(e&1){\n\
    \      ll tmp=(g0*f0+d*((g1*f1)%MOD))%MOD;\n      g1=(g0*f1+g1*f0)%MOD;\n    \
    \  g0=tmp;\n    }\n    ll tmp=(f0*f0+d*((f1*f1)%MOD))%MOD;\n    f1=(2*f0*f1)%MOD;\n\
    \    f0=tmp;\n  }\n  if(g0>MOD-g0) g0=MOD-g0;\n  return {T(g0),T(MOD-g0)};\n}\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/sqrt.cpp
  requiredBy: []
  timestamp: '2020-11-13 20:22:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/sqrt_of_formal_power_series.test.cpp
  - test/yosupo/sqrt_mod.test.cpp
documentation_of: mod/sqrt.cpp
layout: document
redirect_from:
- /library/mod/sqrt.cpp
- /library/mod/sqrt.cpp.html
title: mod/sqrt.cpp
---
