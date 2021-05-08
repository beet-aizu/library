---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/pow.cpp
    title: mod/pow.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3062.test.cpp
    title: test/aoj/3062.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4474.test.cpp
    title: test/yukicoder/4474.test.cpp
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
    \ mod/order.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"pow.cpp\"\n#undef call_from_test\n\n#endif\n\
    //BEGIN CUT HERE\n// mod can be composite numbers\ntemplate<typename T>\nT order(T\
    \ x,const T MOD){\n  static map<T, vector<T>> dp;\n  static map<T, T> phi;\n\n\
    \  vector<T> &ps=dp[MOD];\n  if(ps.empty()){\n    T res=MOD,n=MOD;\n    for(T\
    \ i=2;i*i<=n;i++){\n      if(n%i) continue;\n      while(n%i==0) n/=i;\n     \
    \ res=res/i*(i-1);\n    }\n    if(n!=1) res=res/n*(n-1);\n    phi[MOD]=res;\n\n\
    \    for(T i=2;i*i<=res;i++){\n      if(res%i) continue;\n      while(res%i==0)\
    \ res/=i;\n      ps.emplace_back(i);\n    }\n    if(res!=1) ps.emplace_back(res);\n\
    \  }\n\n  T res=phi[MOD];\n  for(T p:ps){\n    while(res%p==0){\n      if(mod_pow(x,res/p,MOD)!=1)\
    \ break;\n      res/=p;\n    }\n  }\n  return res;\n}\n//END CUT HERE\n#ifndef\
    \ call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - mod/pow.cpp
  isVerificationFile: false
  path: mod/order.cpp
  requiredBy: []
  timestamp: '2020-11-13 17:57:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3062.test.cpp
  - test/yukicoder/4474.test.cpp
documentation_of: mod/order.cpp
layout: document
redirect_from:
- /library/mod/order.cpp
- /library/mod/order.cpp.html
title: mod/order.cpp
---
