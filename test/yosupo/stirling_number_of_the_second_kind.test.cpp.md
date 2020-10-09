---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  - icon: ':heavy_check_mark:'
    path: combinatorics/stirling2nd.cpp
    title: combinatorics/stirling2nd.cpp
  - icon: ':heavy_check_mark:'
    path: convolution/numbertheoretictransform.cpp
    title: convolution/numbertheoretictransform.cpp
  - icon: ':heavy_check_mark:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  - icon: ':heavy_check_mark:'
    path: polynomial/formalpowerseries.cpp
    title: polynomial/formalpowerseries.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind
    links:
    - https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ convolution/numbertheoretictransform.cpp: line 8: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../mod/mint.cpp\"\n#include \"../../convolution/numbertheoretictransform.cpp\"\
    \n#include \"../../combinatorics/enumeration.cpp\"\n#include \"../../polynomial/formalpowerseries.cpp\"\
    \n#include \"../../combinatorics/stirling2nd.cpp\"\n#undef call_from_test\n\n\
    signed main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n;\n  cin>>n;\n\
    \n  NTT<2> ntt;\n  using M = NTT<2>::M;\n  auto conv=[&](auto as,auto bs){return\
    \ ntt.multiply(as,bs);};\n  Stirling2nd<M> ss(conv);\n\n  ss.build(n);\n  for(int\
    \ i=0;i<=n;i++){\n    if(i) cout<<\" \";\n    cout<<ss[i];\n  }\n  cout<<endl;\n\
    \  return 0;\n}\n"
  dependsOn:
  - mod/mint.cpp
  - convolution/numbertheoretictransform.cpp
  - combinatorics/enumeration.cpp
  - polynomial/formalpowerseries.cpp
  - combinatorics/stirling2nd.cpp
  isVerificationFile: true
  path: test/yosupo/stirling_number_of_the_second_kind.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 16:01:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/stirling_number_of_the_second_kind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/stirling_number_of_the_second_kind.test.cpp
- /verify/test/yosupo/stirling_number_of_the_second_kind.test.cpp.html
title: test/yosupo/stirling_number_of_the_second_kind.test.cpp
---
