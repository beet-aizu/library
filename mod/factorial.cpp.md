---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/garner.cpp
    title: convolution/garner.cpp
  - icon: ':heavy_check_mark:'
    path: convolution/numbertheoretictransform.cpp
    title: convolution/numbertheoretictransform.cpp
  - icon: ':heavy_check_mark:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  - icon: ':heavy_check_mark:'
    path: mod/rint.cpp
    title: mod/rint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1504.test.cpp
    title: test/yukicoder/1504.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ mod/factorial.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../mod/mint.cpp\"\n#include \"../convolution/numbertheoretictransform.cpp\"\
    \n#include \"../convolution/garner.cpp\"\n#include \"../mod/rint.cpp\"\n#undef\
    \ call_from_test\n\n#endif\n//BEGIN CUT HERE\n// MOD: prime\nint factorial(long\
    \ long n,const int MOD){\n  if(n>=MOD) return 0;\n  Garner arb;\n  using R = Rint<int>;\n\
    \  R::set_mod(MOD);\n\n  int d=1<<15;\n  vector<R> fact(d*2+1,1),finv(d*2+1,1);\n\
    \  for(int i=1;i<=d*2;i++) fact[i]=fact[i-1]*R(i);\n  finv[d*2]=fact[d*2].inv();\n\
    \  for(int i=d*2-1;i>=0;i--) finv[i]=finv[i+1]*R(i+1);\n\n  vector<R> seq({1,d+1});\n\
    \  seq.reserve(d+1);\n\n  int sz=1;\n  while(sz<d){\n    vector<R> aux(sz,1);\n\
    \    vector<R> f(sz*4,0),g(sz*4,0);\n    for(int i=0;i<=sz;i++){\n      f[i]=finv[i]*finv[sz-i]*seq[i];\n\
    \      if(((sz+i)&1) and (f[i].v!=0)) f[i]=-f[i];\n    }\n\n    vector<R> pf(f);\n\
    \    vector<R> as;\n    as.emplace_back(R(sz+1));\n    as.emplace_back(R(sz)/R(d));\n\
    \    as.emplace_back(R(sz)/R(d)+R(sz+1));\n\n    for(int idx=0;idx<3;idx++){\n\
    \      for(int i=0;i<sz*4;i++) f[i]=pf[i];\n      for(int i=1;i<sz*2+2;i++)\n\
    \        g[i]=(as[idx]-R(sz-i+1)).inv();\n      f=arb.multiply(f,g);\n      f.resize(sz*4);\n\
    \n      R prod=1;\n      for(int i=0;i<=sz;i++) prod*=as[idx]-R(i);\n\n      for(int\
    \ i=0;i<=sz;i++){\n        f[sz+i+1]*=prod;\n        prod*=as[idx]+R(i+1);\n \
    \       prod/=as[idx]-R(sz-i);\n      }\n      if(idx==0){\n        for(int i=0;i<sz;i++)\n\
    \          aux[i]=f[sz+i+1];\n      }\n      if(idx==1){\n        for(int i=0;i<=sz;i++)\n\
    \          seq[i]*=f[sz+i+1];\n      }\n      if(idx==2){\n        for(int i=0;i<sz;i++)\n\
    \          aux[i]*=f[sz+i+1];\n      }\n    }\n    for(R x:aux) seq.emplace_back(x);\n\
    \    sz<<=1;\n  }\n\n  using ll = long long;\n  R res=1;\n  int l=min((ll)d,(n+1)/d);\n\
    \  for(ll i=0;i<l;i++) res*=seq[i];\n  for(ll i=l*d+1;i<=n;i++) res*=R(i);\n \
    \ return res.v;\n}\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - mod/mint.cpp
  - convolution/numbertheoretictransform.cpp
  - convolution/garner.cpp
  - mod/rint.cpp
  isVerificationFile: false
  path: mod/factorial.cpp
  requiredBy: []
  timestamp: '2021-03-25 09:46:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1504.test.cpp
documentation_of: mod/factorial.cpp
layout: document
redirect_from:
- /library/mod/factorial.cpp
- /library/mod/factorial.cpp.html
title: mod/factorial.cpp
---
