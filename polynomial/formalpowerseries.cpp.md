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
    \ polynomial/formalpowerseries.cpp: line 8: unable to process #include in #if\
    \ / #ifdef / #ifndef other than include guards\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define call_from_test\n#include \"../combinatorics/enumeration.cpp\"\
    \n#undef call_from_test\n\n#endif\n\n/*\n * @see http://beet-aizu.hatenablog.com/entry/2019/09/27/224701\n\
    \ */\n//BEGIN CUT HERE\ntemplate<typename M_>\nstruct FormalPowerSeries : Enumeration<M_>\
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
    \   return as;\n  }\n\n  // F(0) must not be 0\n  Poly inv(Poly as,int deg){\n\
    \    assert(as[0]!=M(0));\n    Poly rs({M(1)/as[0]});\n    for(int i=1;i<deg;i<<=1)\n\
    \      rs=pre(sub(add(rs,rs),mul(mul(rs,rs),pre(as,i<<1))),i<<1);\n    return\
    \ rs;\n  }\n\n  // not zero\n  Poly div(Poly as,Poly bs){\n    while(as.back()==M(0))\
    \ as.pop_back();\n    while(bs.back()==M(0)) bs.pop_back();\n    if(bs.size()>as.size())\
    \ return Poly();\n    reverse(as.begin(),as.end());\n    reverse(bs.begin(),bs.end());\n\
    \    int need=as.size()-bs.size()+1;\n    Poly ds=pre(mul(as,inv(bs,need)),need);\n\
    \    reverse(ds.begin(),ds.end());\n    return ds;\n  }\n\n  Poly mod(Poly as,Poly\
    \ bs){\n    if(as==Poly(as.size(),0)) return Poly({0});\n    as=sub(as,mul(div(as,bs),bs));\n\
    \    if(as==Poly(as.size(),0)) return Poly({0});\n    while(as.back()==M(0)) as.pop_back();\n\
    \    return as;\n  }\n\n  // F(0) must be 1\n  Poly sqrt(Poly as,int deg){\n \
    \   assert(as[0]==M(1));\n    M inv2=M(1)/M(2);\n    Poly ss({M(1)});\n    for(int\
    \ i=1;i<deg;i<<=1){\n      ss=pre(add(ss,mul(pre(as,i<<1),inv(ss,i<<1))),i<<1);\n\
    \      for(M &x:ss) x*=inv2;\n    }\n    return ss;\n  }\n\n  Poly diff(Poly as){\n\
    \    int n=as.size();\n    Poly rs(n-1);\n    for(int i=1;i<n;i++) rs[i-1]=as[i]*M(i);\n\
    \    return rs;\n  }\n\n  Poly integral(Poly as){\n    super::init(as.size()+1);\n\
    \    int n=as.size();\n    Poly rs(n+1);\n    rs[0]=M(0);\n    for(int i=0;i<n;i++)\
    \ rs[i+1]=as[i]*invs[i+1];\n    return rs;\n  }\n\n  // F(0) must be 1\n  Poly\
    \ log(Poly as,int deg){\n    return pre(integral(mul(diff(as),inv(as,deg))),deg);\n\
    \  }\n\n  // F(0) must be 0\n  Poly exp(Poly as,int deg){\n    Poly fs({M(1)});\n\
    \    as[0]+=M(1);\n    for(int i=1;i<deg;i<<=1)\n      fs=pre(mul(fs,sub(pre(as,i<<1),log(fs,i<<1))),i<<1);\n\
    \    return fs;\n  }\n\n  // not zero\n  Poly pow(Poly as,long long k,int deg){\n\
    \    if(as==Poly(as.size(),M(0))) return Poly(deg,M(0));\n\n    int cnt=0;\n \
    \   while(as[cnt]==M(0)) cnt++;\n    if(cnt*k>=deg) return Poly(deg,M(0));\n \
    \   as.erase(as.begin(),as.begin()+cnt);\n    deg-=cnt*k;\n\n    M c=as[0];\n\
    \    Poly zs(cnt*k,M(0));\n    Poly rs=mul(exp(mul(log(mul(as,c.inv()),deg),M(k)),deg),c.pow(k));\n\
    \    zs.insert(zs.end(),rs.begin(),rs.end());\n    return pre(zs,deg+cnt*k);\n\
    \  }\n\n  // x -> x + c\n  Poly shift(Poly as,M c){\n    super::init(as.size()+1);\n\
    \    int n=as.size();\n    for(int i=0;i<n;i++) as[i]*=fact[i];\n    reverse(as.begin(),as.end());\n\
    \    Poly bs(n,M(1));\n    for(int i=1;i<n;i++)\n      bs[i]=bs[i-1]*c*invs[i];\n\
    \    as=pre(mul(as,bs),n);\n    reverse(as.begin(),as.end());\n    for(int i=0;i<n;i++)\
    \ as[i]*=finv[i];\n    return as;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - combinatorics/enumeration.cpp
  extendedDependsOn:
  - icon: ':warning:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  extendedRequiredBy:
  - icon: ':warning:'
    path: polynomial/interpolate.cpp
    title: polynomial/interpolate.cpp
  - icon: ':warning:'
    path: polynomial/multieval.cpp
    title: polynomial/multieval.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3072.test.cpp
    title: test/aoj/3072.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2985.test.cpp
    title: test/aoj/2985.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2985.garner.test.cpp
    title: test/aoj/2985.garner.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/stirling_number_of_the_second_kind.test.cpp
    title: test/yosupo/stirling_number_of_the_second_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/polynomial_interpolation.test.cpp
    title: test/yosupo/polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/pow_of_formal_power_series.test.cpp
    title: test/yosupo/pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/log_of_formal_power_series.test.cpp
    title: test/yosupo/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bernoulli_number.test.cpp
    title: test/yosupo/bernoulli_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/polynomial_taylor_shift.test.cpp
    title: test/yosupo/polynomial_taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/partition_function.test.cpp
    title: test/yosupo/partition_function.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/multipoint_evaluation.test.cpp
    title: test/yosupo/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sqrt_of_formal_power_series.test.cpp
    title: test/yosupo/sqrt_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/stirling_number_of_the_first_kind.test.cpp
    title: test/yosupo/stirling_number_of_the_first_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/exp_of_formal_power_series.test.cpp
    title: test/yosupo/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0444.test.cpp
    title: test/yukicoder/0444.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2744.test.cpp
    title: test/yukicoder/2744.test.cpp
  - icon: ':warning:'
    path: combinatorics/stirling1st.cpp
    title: combinatorics/stirling1st.cpp
  - icon: ':warning:'
    path: combinatorics/partition.cpp
    title: combinatorics/partition.cpp
  - icon: ':warning:'
    path: combinatorics/stirling2nd.cpp
    title: combinatorics/stirling2nd.cpp
  - icon: ':warning:'
    path: combinatorics/bernoulli.cpp
    title: combinatorics/bernoulli.cpp
  extendedVerifiedWith: []
  isVerificationFile: false
  path: polynomial/formalpowerseries.cpp
  requiredBy:
  - polynomial/interpolate.cpp
  - polynomial/multieval.cpp
  - test/aoj/3072.test.cpp
  - test/aoj/2985.test.cpp
  - test/aoj/2985.garner.test.cpp
  - test/yosupo/stirling_number_of_the_second_kind.test.cpp
  - test/yosupo/polynomial_interpolation.test.cpp
  - test/yosupo/pow_of_formal_power_series.test.cpp
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/yosupo/inv_of_formal_power_series.test.cpp
  - test/yosupo/bernoulli_number.test.cpp
  - test/yosupo/polynomial_taylor_shift.test.cpp
  - test/yosupo/partition_function.test.cpp
  - test/yosupo/multipoint_evaluation.test.cpp
  - test/yosupo/sqrt_of_formal_power_series.test.cpp
  - test/yosupo/stirling_number_of_the_first_kind.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
  - test/yukicoder/0444.test.cpp
  - test/yukicoder/2744.test.cpp
  - combinatorics/stirling1st.cpp
  - combinatorics/partition.cpp
  - combinatorics/stirling2nd.cpp
  - combinatorics/bernoulli.cpp
  timestamp: '2020-05-16 18:51:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: polynomial/formalpowerseries.cpp
layout: document
redirect_from:
- /library/polynomial/formalpowerseries.cpp
- /library/polynomial/formalpowerseries.cpp.html
title: polynomial/formalpowerseries.cpp
---
