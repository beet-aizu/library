---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 58, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ mod/order.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../math/factorize.cpp\"\n#include \"pow.cpp\"\
    \n#undef call_from_test\n\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nT order(T\
    \ x,T MOD){\n  static map<T, vector<T>> dp;\n  vector<T> &ps=dp[MOD];\n  if(ps.empty()){\n\
    \    auto fs=factorize(MOD-1);\n    for(auto p:fs) ps.emplace_back(p.first);\n\
    \  }\n  T res=MOD-1;\n  for(T p:ps){\n    while(res%p==0){\n      if(mod_pow(x,res/p,MOD)!=1)\
    \ break;\n      res/=p;\n    }\n  }\n  return res;\n}\n//END CUT HERE\n#ifndef\
    \ call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - math/factorize.cpp
  - mod/pow.cpp
  extendedDependsOn:
  - icon: ':warning:'
    path: math/factorize.cpp
    title: math/factorize.cpp
  - icon: ':warning:'
    path: mod/pow.cpp
    title: mod/pow.cpp
  extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3062.test.cpp
    title: test/aoj/3062.test.cpp
  extendedVerifiedWith: []
  isVerificationFile: false
  path: mod/order.cpp
  requiredBy:
  - test/aoj/3062.test.cpp
  timestamp: '2020-03-05 21:15:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: mod/order.cpp
layout: document
redirect_from:
- /library/mod/order.cpp
- /library/mod/order.cpp.html
title: mod/order.cpp
---
