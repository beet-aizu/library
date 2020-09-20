---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/extgcd.cpp
    title: math/extgcd.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://atcoder.jp/contests/agc043/tasks/agc043_b
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/combination.cpp: line 8: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define call_from_test\n#include \"extgcd.cpp\"\n#undef call_from_test\n\
    \n#endif\n//BEGIN CUT HERE\ntemplate<typename T, size_t sz>\nstruct Combination{\n\
    \  using ll = long long;\n  array<T, sz> fact;\n\n  T mod;\n  Combination(T mod):mod(mod){init();}\n\
    \n  void init(){\n    fact[0]=1;\n    for(int i=1;i<(int)sz;i++)\n      fact[i]=(ll)fact[i-1]*i%mod;\n\
    \  }\n\n  T mod_fact(T n,T& e){\n    e=0;\n    if(n==0) return 1;\n    T res=mod_fact(n/mod,e);\n\
    \    e+=n/mod;\n    if(n/mod%2!=0)return res*(mod-fact[n%mod])%mod;\n    return\
    \ res*fact[n%mod]%mod;\n  }\n\n  T mod_comb(T n,T k){\n    if(n==k||k==0) return\
    \ 1;\n    T e1,e2,e3;\n    T a1=mod_fact(n,e1),a2=mod_fact(k,e2),a3=mod_fact(n-k,e3);\n\
    \    if(e1>e2+e3) return 0;\n    return a1*mod_inverse<ll>((ll)a2*a3%mod,mod)%mod;\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned\
    \ main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n;\n  cin>>n;\n\
    \  string s;\n  cin>>s;\n\n  vector<int> as(n);\n  for(int i=0;i<n;i++) as[i]=s[i]-'1';\n\
    \n  const int sz = 1e6+10;\n  Combination<int, sz> C(2);\n\n  int is_one=0;\n\
    \  for(int i=0;i<n;i++)\n    if(as[i]&1) is_one^=C.mod_comb(n-1,i);\n\n  if(is_one){\n\
    \    cout<<1<<endl;\n    return 0;\n  }\n\n  for(int i=0;i<n;i++){\n    if(as[i]==1){\n\
    \      cout<<0<<endl;\n      return 0;\n    }\n    as[i]/=2;\n  }\n\n  int is_two=0;\n\
    \  for(int i=0;i<n;i++)\n    if(as[i]&1) is_two^=C.mod_comb(n-1,i);\n\n  cout<<is_two*2<<endl;\n\
    \  return 0;\n}\n/*\n  verified on 2020/03/22\n  https://atcoder.jp/contests/agc043/tasks/agc043_b\n\
    */\n#endif\n"
  dependsOn:
  - math/extgcd.cpp
  isVerificationFile: false
  path: math/combination.cpp
  requiredBy: []
  timestamp: '2020-09-21 00:38:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/combination.cpp
layout: document
redirect_from:
- /library/math/combination.cpp
- /library/math/combination.cpp.html
title: math/combination.cpp
---
