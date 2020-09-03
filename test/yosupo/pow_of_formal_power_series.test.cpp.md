---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/pow_of_formal_power_series
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 58, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ convolution/numbertheoretictransform.cpp: line 8: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../mod/mint.cpp\"\n#include \"../../convolution/numbertheoretictransform.cpp\"\
    \n#include \"../../combinatorics/enumeration.cpp\"\n#include \"../../polynomial/formalpowerseries.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,m;\n  cin>>n>>m;\n\n  NTT<2> ntt;\n  using M = NTT<2>::M;\n  auto conv=[&](auto\
    \ as,auto bs){return ntt.multiply(as,bs);};\n  FormalPowerSeries<M> FPS(conv);\n\
    \n  vector<M> as(n);\n  for(int i=0;i<n;i++) cin>>as[i].v;\n\n  auto bs=FPS.pow(as,m,n);\n\
    \  for(int i=0;i<n;i++){\n    if(i) cout<<\" \";\n    cout<<bs[i];\n  }\n  cout<<endl;\n\
    \  return 0;\n}\n"
  dependsOn:
  - mod/mint.cpp
  - convolution/numbertheoretictransform.cpp
  - combinatorics/enumeration.cpp
  - polynomial/formalpowerseries.cpp
  extendedDependsOn:
  - icon: ':warning:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  - icon: ':warning:'
    path: convolution/numbertheoretictransform.cpp
    title: convolution/numbertheoretictransform.cpp
  - icon: ':warning:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  - icon: ':warning:'
    path: polynomial/formalpowerseries.cpp
    title: polynomial/formalpowerseries.cpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: test/yosupo/pow_of_formal_power_series.test.cpp
  requiredBy: []
  timestamp: '2020-05-16 18:51:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: test/yosupo/pow_of_formal_power_series.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/pow_of_formal_power_series.test.cpp
- /verify/test/yosupo/pow_of_formal_power_series.test.cpp.html
title: test/yosupo/pow_of_formal_power_series.test.cpp
---
