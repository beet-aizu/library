---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/garner.cpp
    title: convolution/garner.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/998244353.cpp
    title: formalpowerseries/998244353.cpp
  - icon: ':heavy_check_mark:'
    path: mod/factorial.cpp
    title: mod/factorial.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2560.test.cpp
    title: test/aoj/2560.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2959.test.cpp
    title: test/aoj/2959.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2977.test.cpp
    title: test/aoj/2977.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2985.garner.test.cpp
    title: test/aoj/2985.garner.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3072.test.cpp
    title: test/aoj/3072.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3074.test.cpp
    title: test/aoj/3074.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3084.test.cpp
    title: test/aoj/3084.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bernoulli_number.test.cpp
    title: test/yosupo/bernoulli_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod.test.cpp
    title: test/yosupo/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod_1000000007.garner.test.cpp
    title: test/yosupo/convolution_mod_1000000007.garner.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/exp_of_formal_power_series.test.cpp
    title: test/yosupo/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
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
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sharp_p_subset_sum.test.cpp
    title: test/yosupo/sharp_p_subset_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sqrt_of_formal_power_series.test.cpp
    title: test/yosupo/sqrt_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/stirling_number_of_the_first_kind.test.cpp
    title: test/yosupo/stirling_number_of_the_first_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/stirling_number_of_the_second_kind.test.cpp
    title: test/yosupo/stirling_number_of_the_second_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1504.test.cpp
    title: test/yukicoder/1504.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/5633.test.cpp
    title: test/yukicoder/5633.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ convolution/numbertheoretictransform.cpp: line 6: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../mod/mint.cpp\"\n#undef call_from_test\n\n\
    #endif\n//BEGIN CUT HERE\nconstexpr int bmds(int x){\n  const int v[] = {1012924417,\
    \ 924844033, 998244353,\n                   897581057, 645922817};\n  return v[x];\n\
    }\nconstexpr int brts(int x){\n  const int v[] = {5, 5, 3, 3, 3};\n  return v[x];\n\
    }\n\ntemplate<int X>\nstruct NTT{\n  inline static constexpr int md = bmds(X);\n\
    \  inline static constexpr int rt = brts(X);\n  using M = Mint<int, md>;\n  vector<\
    \ vector<M> > rts,rrts;\n\n  void ensure_base(int n){\n    if((int)rts.size()>=n)\
    \ return;\n    rts.resize(n);rrts.resize(n);\n    for(int i=1;i<n;i<<=1){\n  \
    \    if(!rts[i].empty()) continue;\n      M w=M(rt).pow((md-1)/(i<<1));\n    \
    \  M rw=w.inv();\n      rts[i].resize(i);rrts[i].resize(i);\n      rts[i][0]=M(1);rrts[i][0]=M(1);\n\
    \      for(int k=1;k<i;k++){\n        rts[i][k]=rts[i][k-1]*w;\n        rrts[i][k]=rrts[i][k-1]*rw;\n\
    \      }\n    }\n  }\n\n  void ntt(vector<M> &as,bool f){\n    int n=as.size();\n\
    \    assert((n&(n-1))==0);\n    ensure_base(n);\n\n    for(int i=0,j=1;j+1<n;j++){\n\
    \      for(int k=n>>1;k>(i^=k);k>>=1);\n      if(i>j) swap(as[i],as[j]);\n   \
    \ }\n\n    for(int i=1;i<n;i<<=1){\n      for(int j=0;j<n;j+=i*2){\n        for(int\
    \ k=0;k<i;k++){\n          M z=as[i+j+k]*(f?rrts[i][k]:rts[i][k]);\n         \
    \ as[i+j+k]=as[j+k]-z;\n          as[j+k]+=z;\n        }\n      }\n    }\n\n \
    \   if(f){\n      M tmp=M(n).inv();\n      for(int i=0;i<n;i++) as[i]*=tmp;\n\
    \    }\n  }\n\n  vector<M> multiply(vector<M> as,vector<M> bs){\n    int need=as.size()+bs.size()-1;\n\
    \    int sz=1;\n    while(sz<need) sz<<=1;\n    as.resize(sz,M(0));\n    bs.resize(sz,M(0));\n\
    \n    ntt(as,0);ntt(bs,0);\n    for(int i=0;i<sz;i++) as[i]*=bs[i];\n    ntt(as,1);\n\
    \n    as.resize(need);\n    return as;\n  }\n\n  vector<int> multiply(vector<int>\
    \ as,vector<int> bs){\n    vector<M> am(as.size()),bm(bs.size());\n    for(int\
    \ i=0;i<(int)am.size();i++) am[i]=M(as[i]);\n    for(int i=0;i<(int)bm.size();i++)\
    \ bm[i]=M(bs[i]);\n    vector<M> cm=multiply(am,bm);\n    vector<int> cs(cm.size());\n\
    \    for(int i=0;i<(int)cs.size();i++) cs[i]=cm[i].v;\n    return cs;\n  }\n};\n\
    //END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - mod/mint.cpp
  isVerificationFile: false
  path: convolution/numbertheoretictransform.cpp
  requiredBy:
  - convolution/garner.cpp
  - mod/factorial.cpp
  - formalpowerseries/998244353.cpp
  timestamp: '2021-03-25 09:46:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/sharp_p_subset_sum.test.cpp
  - test/yosupo/partition_function.test.cpp
  - test/yosupo/stirling_number_of_the_first_kind.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
  - test/yosupo/inv_of_formal_power_series.test.cpp
  - test/yosupo/polynomial_interpolation.test.cpp
  - test/yosupo/bernoulli_number.test.cpp
  - test/yosupo/polynomial_taylor_shift.test.cpp
  - test/yosupo/pow_of_formal_power_series.test.cpp
  - test/yosupo/convolution_mod_1000000007.garner.test.cpp
  - test/yosupo/multipoint_evaluation.test.cpp
  - test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
  - test/yosupo/convolution_mod.test.cpp
  - test/yosupo/sqrt_of_formal_power_series.test.cpp
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/yosupo/stirling_number_of_the_second_kind.test.cpp
  - test/yukicoder/5633.test.cpp
  - test/yukicoder/1504.test.cpp
  - test/aoj/2959.test.cpp
  - test/aoj/3084.test.cpp
  - test/aoj/2985.garner.test.cpp
  - test/aoj/3074.test.cpp
  - test/aoj/2560.test.cpp
  - test/aoj/3072.test.cpp
  - test/aoj/2977.test.cpp
documentation_of: convolution/numbertheoretictransform.cpp
layout: document
redirect_from:
- /library/convolution/numbertheoretictransform.cpp
- /library/convolution/numbertheoretictransform.cpp.html
title: convolution/numbertheoretictransform.cpp
---
