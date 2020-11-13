---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  - icon: ':heavy_check_mark:'
    path: convolution/numbertheoretictransform.cpp
    title: convolution/numbertheoretictransform.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/base.cpp
    title: formalpowerseries/base.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/inv.cpp
    title: formalpowerseries/inv.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/sqrt.cpp
    title: formalpowerseries/sqrt.cpp
  - icon: ':heavy_check_mark:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  - icon: ':heavy_check_mark:'
    path: mod/sqrt.cpp
    title: mod/sqrt.cpp
  - icon: ':heavy_check_mark:'
    path: tools/drop.cpp
    title: tools/drop.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/sqrt_of_formal_power_series
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ convolution/numbertheoretictransform.cpp: line 6: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/sqrt_of_formal_power_series\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../tools/drop.cpp\"\n#include \"../../mod/sqrt.cpp\"\n#include \"../../mod/mint.cpp\"\
    \n#include \"../../convolution/numbertheoretictransform.cpp\"\n#include \"../../combinatorics/enumeration.cpp\"\
    \n#include \"../../formalpowerseries/base.cpp\"\n#include \"../../formalpowerseries/inv.cpp\"\
    \n#include \"../../formalpowerseries/sqrt.cpp\"\n#undef call_from_test\n\nsigned\
    \ main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n;\n  cin>>n;\n\n\
    \  NTT<2> ntt;\n  using M = NTT<2>::M;\n  auto conv=[&](auto as,auto bs){return\
    \ ntt.multiply(as,bs);};\n  FormalPowerSeries<M> FPS(conv);\n\n  deque<int> as(n);\n\
    \  for(int i=0;i<n;i++) cin>>as[i];\n\n  while(!as.empty()&&as.front()==0) as.pop_front();\n\
    \n  if(as.empty()){\n    for(int i=0;i<n;i++){\n      if(i) cout<<\" \";\n   \
    \   cout<<0;\n    }\n    cout<<endl;\n    return 0;\n  }\n\n  int m=as.size();\n\
    \  if((n-m)&1) drop(-1);\n\n  auto ss=mod_sqrt(as[0],ntt.md);\n  if(ss.empty())\
    \ drop(-1);\n\n  vector<M> ps(n,M(0));\n  for(int i=0;i<m;i++) ps[i]=M(as[i])/M(as[0]);\n\
    \n  auto bs=FPS.sqrt(ps,n);\n  bs.insert(bs.begin(),(n-m)/2,M(0));\n  for(int\
    \ i=0;i<n;i++){\n    if(i) cout<<\" \";\n    cout<<bs[i]*ss[0];\n  }\n  cout<<endl;\n\
    \  return 0;\n}\n"
  dependsOn:
  - tools/drop.cpp
  - mod/sqrt.cpp
  - mod/mint.cpp
  - convolution/numbertheoretictransform.cpp
  - combinatorics/enumeration.cpp
  - formalpowerseries/base.cpp
  - formalpowerseries/inv.cpp
  - formalpowerseries/sqrt.cpp
  isVerificationFile: true
  path: test/yosupo/sqrt_of_formal_power_series.test.cpp
  requiredBy: []
  timestamp: '2020-11-13 20:22:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sqrt_of_formal_power_series.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sqrt_of_formal_power_series.test.cpp
- /verify/test/yosupo/sqrt_of_formal_power_series.test.cpp.html
title: test/yosupo/sqrt_of_formal_power_series.test.cpp
---
