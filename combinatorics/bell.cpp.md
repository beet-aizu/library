---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_G.test.cpp
    title: test/aoj/DPL_5_G.test.cpp
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
    \ combinatorics/bell.cpp: line 6: unable to process #include in #if / #ifdef /\
    \ #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"enumeration.cpp\"\n#undef call_from_test\n\n\
    #endif\n//BEGIN CUT HERE\n// put n distinct balls into at most k identical boxes\n\
    template<typename M>\nM bell(int n,int k){\n  if(n==0) return M(1);\n\n  using\
    \ E = Enumeration<M>;\n  k=min(k,n);\n  E::init(k);\n\n  vector<M> dp(k+1);\n\
    \  dp[0]=M(1);\n  for(int i=1;i<=k;i++)\n    dp[i]=dp[i-1]+((i&1)?-E::Finv(i):E::Finv(i));\n\
    \n  M res(0);\n  for(int i=1;i<=k;i++)\n    res+=M(i).pow(n)*E::Finv(i)*dp[k-i];\n\
    \  return res;\n}\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  dependsOn:
  - combinatorics/enumeration.cpp
  isVerificationFile: false
  path: combinatorics/bell.cpp
  requiredBy: []
  timestamp: '2021-03-25 09:21:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_5_G.test.cpp
documentation_of: combinatorics/bell.cpp
layout: document
redirect_from:
- /library/combinatorics/bell.cpp
- /library/combinatorics/bell.cpp.html
title: combinatorics/bell.cpp
---
