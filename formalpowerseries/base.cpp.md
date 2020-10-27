---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: combinatorics/bernoulli.cpp
    title: combinatorics/bernoulli.cpp
  - icon: ':heavy_check_mark:'
    path: combinatorics/partition.cpp
    title: combinatorics/partition.cpp
  - icon: ':x:'
    path: combinatorics/stirling1st.cpp
    title: combinatorics/stirling1st.cpp
  - icon: ':x:'
    path: combinatorics/stirling2nd.cpp
    title: combinatorics/stirling2nd.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/diff.cpp
    title: formalpowerseries/diff.cpp
  - icon: ':question:'
    path: formalpowerseries/div.cpp
    title: formalpowerseries/div.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/exp.cpp
    title: formalpowerseries/exp.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/integral.cpp
    title: formalpowerseries/integral.cpp
  - icon: ':question:'
    path: formalpowerseries/inv.cpp
    title: formalpowerseries/inv.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/log.cpp
    title: formalpowerseries/log.cpp
  - icon: ':question:'
    path: formalpowerseries/mod.cpp
    title: formalpowerseries/mod.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/pow.cpp
    title: formalpowerseries/pow.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/shift.cpp
    title: formalpowerseries/shift.cpp
  - icon: ':x:'
    path: formalpowerseries/sqrt.cpp
    title: formalpowerseries/sqrt.cpp
  - icon: ':heavy_check_mark:'
    path: polynomial/interpolate.cpp
    title: polynomial/interpolate.cpp
  - icon: ':heavy_check_mark:'
    path: polynomial/multieval.cpp
    title: polynomial/multieval.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2985.garner.test.cpp
    title: test/aoj/2985.garner.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2985.test.cpp
    title: test/aoj/2985.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3072.test.cpp
    title: test/aoj/3072.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3084.test.cpp
    title: test/aoj/3084.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bernoulli_number.test.cpp
    title: test/yosupo/bernoulli_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/exp_of_formal_power_series.test.cpp
    title: test/yosupo/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/log_of_formal_power_series.test.cpp
    title: test/yosupo/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/multipoint_evaluation.test.cpp
    title: test/yosupo/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/partition_function.test.cpp
    title: test/yosupo/partition_function.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/polynomial_interpolation.test.cpp
    title: test/yosupo/polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/polynomial_taylor_shift.test.cpp
    title: test/yosupo/polynomial_taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/pow_of_formal_power_series.test.cpp
    title: test/yosupo/pow_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/sqrt_of_formal_power_series.test.cpp
    title: test/yosupo/sqrt_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/stirling_number_of_the_first_kind.test.cpp
    title: test/yosupo/stirling_number_of_the_first_kind.test.cpp
  - icon: ':x:'
    path: test/yosupo/stirling_number_of_the_second_kind.test.cpp
    title: test/yosupo/stirling_number_of_the_second_kind.test.cpp
  - icon: ':x:'
    path: test/yukicoder/0444.test.cpp
    title: test/yukicoder/0444.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2744.test.cpp
    title: test/yukicoder/2744.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - http://beet-aizu.hatenablog.com/entry/2019/09/27/224701
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ formalpowerseries/base.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../combinatorics/enumeration.cpp\"\n#undef\
    \ call_from_test\n\n#endif\n// http://beet-aizu.hatenablog.com/entry/2019/09/27/224701\n\
    //BEGIN CUT HERE\ntemplate<typename M_>\nstruct FormalPowerSeries : Enumeration<M_>\
    \ {\n  using M = M_;\n  using super = Enumeration<M>;\n  using super::fact;\n\
    \  using super::finv;\n  using super::invs;\n\n  using Poly = vector<M>;\n  using\
    \ Conv = function<Poly(Poly, Poly)>;\n  Conv conv;\n  FormalPowerSeries(Conv conv):conv(conv){}\n\
    \n  Poly pre(const Poly &as,int deg){\n    return Poly(as.begin(),as.begin()+min((int)as.size(),deg));\n\
    \  }\n\n  Poly add(Poly as,Poly bs){\n    int sz=max(as.size(),bs.size());\n \
    \   Poly cs(sz,M(0));\n    for(int i=0;i<(int)as.size();i++) cs[i]+=as[i];\n \
    \   for(int i=0;i<(int)bs.size();i++) cs[i]+=bs[i];\n    return cs;\n  }\n\n \
    \ Poly sub(Poly as,Poly bs){\n    int sz=max(as.size(),bs.size());\n    Poly cs(sz,M(0));\n\
    \    for(int i=0;i<(int)as.size();i++) cs[i]+=as[i];\n    for(int i=0;i<(int)bs.size();i++)\
    \ cs[i]-=bs[i];\n    return cs;\n  }\n\n  Poly mul(Poly as,Poly bs){\n    return\
    \ conv(as,bs);\n  }\n\n  Poly mul(Poly as,M k){\n    for(auto &a:as) a*=k;\n \
    \   return as;\n  }\n\n  // F(0) must not be 0\n  Poly inv(Poly as,int deg);\n\
    \n  // not zero\n  Poly div(Poly as,Poly bs);\n\n  // not zero\n  Poly mod(Poly\
    \ as,Poly bs);\n\n  // F(0) must be 1\n  Poly sqrt(Poly as,int deg);\n\n  Poly\
    \ diff(Poly as);\n  Poly integral(Poly as);\n\n  // F(0) must be 1\n  Poly log(Poly\
    \ as,int deg);\n\n  // F(0) must be 0\n  Poly exp(Poly as,int deg);\n\n  // not\
    \ zero\n  Poly pow(Poly as,long long k,int deg);\n\n  // x <- x + c\n  Poly shift(Poly\
    \ as,M c);\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - combinatorics/enumeration.cpp
  isVerificationFile: false
  path: formalpowerseries/base.cpp
  requiredBy:
  - polynomial/interpolate.cpp
  - polynomial/multieval.cpp
  - combinatorics/stirling1st.cpp
  - combinatorics/partition.cpp
  - combinatorics/stirling2nd.cpp
  - combinatorics/bernoulli.cpp
  - formalpowerseries/integral.cpp
  - formalpowerseries/shift.cpp
  - formalpowerseries/sqrt.cpp
  - formalpowerseries/div.cpp
  - formalpowerseries/diff.cpp
  - formalpowerseries/log.cpp
  - formalpowerseries/exp.cpp
  - formalpowerseries/inv.cpp
  - formalpowerseries/mod.cpp
  - formalpowerseries/pow.cpp
  timestamp: '2020-10-27 13:13:52+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/2744.test.cpp
  - test/yukicoder/0444.test.cpp
  - test/aoj/3072.test.cpp
  - test/aoj/3084.test.cpp
  - test/aoj/2985.garner.test.cpp
  - test/aoj/2985.test.cpp
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/yosupo/pow_of_formal_power_series.test.cpp
  - test/yosupo/polynomial_taylor_shift.test.cpp
  - test/yosupo/stirling_number_of_the_second_kind.test.cpp
  - test/yosupo/inv_of_formal_power_series.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
  - test/yosupo/stirling_number_of_the_first_kind.test.cpp
  - test/yosupo/polynomial_interpolation.test.cpp
  - test/yosupo/multipoint_evaluation.test.cpp
  - test/yosupo/partition_function.test.cpp
  - test/yosupo/bernoulli_number.test.cpp
  - test/yosupo/sqrt_of_formal_power_series.test.cpp
documentation_of: formalpowerseries/base.cpp
layout: document
redirect_from:
- /library/formalpowerseries/base.cpp
- /library/formalpowerseries/base.cpp.html
title: formalpowerseries/base.cpp
---
