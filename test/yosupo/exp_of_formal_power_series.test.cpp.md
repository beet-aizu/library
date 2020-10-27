---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  - icon: ':heavy_check_mark:'
    path: convolution/numbertheoretictransform.cpp
    title: convolution/numbertheoretictransform.cpp
  - icon: ':question:'
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
  - icon: ':question:'
    path: formalpowerseries/inv.cpp
    title: formalpowerseries/inv.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/log.cpp
    title: formalpowerseries/log.cpp
  - icon: ':question:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/exp_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/exp_of_formal_power_series
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ convolution/numbertheoretictransform.cpp: line 6: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/exp_of_formal_power_series\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../mod/mint.cpp\"\n#include \"../../convolution/numbertheoretictransform.cpp\"\
    \n#include \"../../combinatorics/enumeration.cpp\"\n#include \"../../formalpowerseries/base.cpp\"\
    \n#include \"../../formalpowerseries/inv.cpp\"\n#include \"../../formalpowerseries/integral.cpp\"\
    \n#include \"../../formalpowerseries/diff.cpp\"\n#include \"../../formalpowerseries/log.cpp\"\
    \n#include \"../../formalpowerseries/exp.cpp\"\n#undef call_from_test\n\nsigned\
    \ main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n;\n  cin>>n;\n\n\
    \  NTT<2> ntt;\n  using M = NTT<2>::M;\n  auto conv=[&](auto as,auto bs){return\
    \ ntt.multiply(as,bs);};\n  FormalPowerSeries<M> FPS(conv);\n\n  vector<M> as(n);\n\
    \  for(int i=0;i<n;i++) cin>>as[i].v;\n\n  auto bs=FPS.exp(as,n);\n  for(int i=0;i<n;i++){\n\
    \    if(i) cout<<\" \";\n    cout<<bs[i];\n  }\n  cout<<endl;\n  return 0;\n}\n"
  dependsOn:
  - mod/mint.cpp
  - convolution/numbertheoretictransform.cpp
  - combinatorics/enumeration.cpp
  - formalpowerseries/base.cpp
  - formalpowerseries/inv.cpp
  - formalpowerseries/integral.cpp
  - formalpowerseries/diff.cpp
  - formalpowerseries/log.cpp
  - formalpowerseries/exp.cpp
  isVerificationFile: true
  path: test/yosupo/exp_of_formal_power_series.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 17:04:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/exp_of_formal_power_series.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/exp_of_formal_power_series.test.cpp
- /verify/test/yosupo/exp_of_formal_power_series.test.cpp.html
title: test/yosupo/exp_of_formal_power_series.test.cpp
---
