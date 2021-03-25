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
  - icon: ':question:'
    path: formalpowerseries/diff.cpp
    title: formalpowerseries/diff.cpp
  - icon: ':x:'
    path: formalpowerseries/div.cpp
    title: formalpowerseries/div.cpp
  - icon: ':question:'
    path: formalpowerseries/inv.cpp
    title: formalpowerseries/inv.cpp
  - icon: ':x:'
    path: formalpowerseries/mod.cpp
    title: formalpowerseries/mod.cpp
  - icon: ':question:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  - icon: ':x:'
    path: polynomial/interpolate.cpp
    title: polynomial/interpolate.cpp
  - icon: ':x:'
    path: polynomial/multieval.cpp
    title: polynomial/multieval.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/polynomial_interpolation
    links:
    - https://judge.yosupo.jp/problem/polynomial_interpolation
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
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/polynomial_interpolation\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../mod/mint.cpp\"\n#include \"../../convolution/numbertheoretictransform.cpp\"\
    \n#include \"../../combinatorics/enumeration.cpp\"\n#include \"../../formalpowerseries/base.cpp\"\
    \n#include \"../../formalpowerseries/inv.cpp\"\n#include \"../../formalpowerseries/div.cpp\"\
    \n#include \"../../formalpowerseries/mod.cpp\"\n#include \"../../formalpowerseries/diff.cpp\"\
    \n#include \"../../polynomial/multieval.cpp\"\n#include \"../../polynomial/interpolate.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n;\n  cin>>n;\n\n  NTT<2> ntt;\n  using M = NTT<2>::M;\n  auto conv=[&](auto\
    \ as,auto bs){return ntt.multiply(as,bs);};\n  Interpolate<M> ip(conv);\n\n  vector<M>\
    \ xs(n),ys(n);\n  for(int i=0;i<n;i++) cin>>xs[i].v;\n  for(int i=0;i<n;i++) cin>>ys[i].v;\n\
    \n  auto ans=ip.build(xs,ys);\n  for(int i=0;i<n;i++){\n    if(i) cout<<\" \"\
    ;\n    cout<<ans[i];\n  }\n  cout<<endl;\n  return 0;\n}\n"
  dependsOn:
  - mod/mint.cpp
  - convolution/numbertheoretictransform.cpp
  - combinatorics/enumeration.cpp
  - formalpowerseries/base.cpp
  - formalpowerseries/inv.cpp
  - formalpowerseries/div.cpp
  - formalpowerseries/mod.cpp
  - formalpowerseries/diff.cpp
  - polynomial/multieval.cpp
  - polynomial/interpolate.cpp
  isVerificationFile: true
  path: test/yosupo/polynomial_interpolation.test.cpp
  requiredBy: []
  timestamp: '2021-03-25 09:21:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/polynomial_interpolation.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/polynomial_interpolation.test.cpp
- /verify/test/yosupo/polynomial_interpolation.test.cpp.html
title: test/yosupo/polynomial_interpolation.test.cpp
---
