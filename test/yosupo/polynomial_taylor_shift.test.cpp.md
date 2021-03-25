---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  - icon: ':question:'
    path: convolution/numbertheoretictransform.cpp
    title: convolution/numbertheoretictransform.cpp
  - icon: ':question:'
    path: formalpowerseries/base.cpp
    title: formalpowerseries/base.cpp
  - icon: ':x:'
    path: formalpowerseries/shift.cpp
    title: formalpowerseries/shift.cpp
  - icon: ':question:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/polynomial_taylor_shift
    links:
    - https://judge.yosupo.jp/problem/polynomial_taylor_shift
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ convolution/numbertheoretictransform.cpp: line 6: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/polynomial_taylor_shift\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../mod/mint.cpp\"\n#include \"../../convolution/numbertheoretictransform.cpp\"\
    \n#include \"../../combinatorics/enumeration.cpp\"\n#include \"../../formalpowerseries/base.cpp\"\
    \n#include \"../../formalpowerseries/shift.cpp\"\n#undef call_from_test\n\nsigned\
    \ main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,c;\n  cin>>n>>c;\n\
    \n  NTT<2> ntt;\n  using M = NTT<2>::M;\n  auto conv=[&](auto as,auto bs){return\
    \ ntt.multiply(as,bs);};\n  FormalPowerSeries<M> FPS(conv);\n\n  vector<M> as(n);\n\
    \  for(int i=0;i<n;i++) cin>>as[i].v;\n\n  auto bs=FPS.shift(as,M(c));\n  for(int\
    \ i=0;i<n;i++){\n    if(i) cout<<\" \";\n    cout<<bs[i];\n  }\n  cout<<endl;\n\
    \  return 0;\n}\n"
  dependsOn:
  - mod/mint.cpp
  - convolution/numbertheoretictransform.cpp
  - combinatorics/enumeration.cpp
  - formalpowerseries/base.cpp
  - formalpowerseries/shift.cpp
  isVerificationFile: true
  path: test/yosupo/polynomial_taylor_shift.test.cpp
  requiredBy: []
  timestamp: '2021-03-25 09:21:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/polynomial_taylor_shift.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/polynomial_taylor_shift.test.cpp
- /verify/test/yosupo/polynomial_taylor_shift.test.cpp.html
title: test/yosupo/polynomial_taylor_shift.test.cpp
---
