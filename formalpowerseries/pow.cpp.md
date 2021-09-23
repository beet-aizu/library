---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/base.cpp
    title: formalpowerseries/base.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/diff.cpp
    title: formalpowerseries/diff.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/exp.cpp
    title: formalpowerseries/exp.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/integral.cpp
    title: formalpowerseries/integral.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/inv.cpp
    title: formalpowerseries/inv.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/log.cpp
    title: formalpowerseries/log.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: includes/formalpowerseries.h
    title: includes/formalpowerseries.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3084.test.cpp
    title: test/aoj/3084.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/pow_of_formal_power_series.test.cpp
    title: test/yosupo/pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/5633.test.cpp
    title: test/yukicoder/5633.test.cpp
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
    \ formalpowerseries/pow.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../combinatorics/enumeration.cpp\"\n#include\
    \ \"base.cpp\"\n#include \"inv.cpp\"\n#include \"diff.cpp\"\n#include \"integral.cpp\"\
    \n#include \"log.cpp\"\n#include \"exp.cpp\"\n#undef call_from_test\n\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename M>\nvector<M> FormalPowerSeries<M>::pow(Poly\
    \ as,long long k,int deg){\n  if(is_zero(as)) return Poly(deg,M(0));\n  shrink(as);\n\
    \n  int cnt=0;\n  while(as[cnt]==M(0)) cnt++;\n  if(cnt*k>=deg) return Poly(deg,M(0));\n\
    \  as.erase(as.begin(),as.begin()+cnt);\n  deg-=cnt*k;\n\n  M c=as[0];\n  Poly\
    \ zs(cnt*k,M(0));\n  Poly rs=mul(exp(mul(log(mul(as,c.inv()),deg),M(k)),deg),c.pow(k));\n\
    \  zs.insert(zs.end(),rs.begin(),rs.end());\n  return pre(zs,deg+cnt*k);\n}\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn:
  - combinatorics/enumeration.cpp
  - formalpowerseries/base.cpp
  - formalpowerseries/inv.cpp
  - formalpowerseries/diff.cpp
  - formalpowerseries/integral.cpp
  - formalpowerseries/log.cpp
  - formalpowerseries/exp.cpp
  isVerificationFile: false
  path: formalpowerseries/pow.cpp
  requiredBy:
  - includes/formalpowerseries.h
  timestamp: '2021-03-25 09:21:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3084.test.cpp
  - test/yosupo/pow_of_formal_power_series.test.cpp
  - test/yukicoder/5633.test.cpp
documentation_of: formalpowerseries/pow.cpp
layout: document
redirect_from:
- /library/formalpowerseries/pow.cpp
- /library/formalpowerseries/pow.cpp.html
title: formalpowerseries/pow.cpp
---
