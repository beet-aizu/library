---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/numbertheoretictransform.cpp
    title: convolution/numbertheoretictransform.cpp
  - icon: ':heavy_check_mark:'
    path: math/bostanmori.cpp
    title: math/bostanmori.cpp
  - icon: ':question:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
    links:
    - https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ convolution/numbertheoretictransform.cpp: line 6: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../mod/mint.cpp\"\n#include \"../../convolution/numbertheoretictransform.cpp\"\
    \n#include \"../../math/bostanmori.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  NTT<2> ntt;\n  using M = decltype(ntt)::M;\n\
    \  auto conv=[&](auto as,auto bs){return ntt.multiply(as,bs);};\n\n  int d;\n\
    \  cin>>d;\n\n  long long k;\n  cin>>k;\n\n  vector<M> as(d),cs(d);\n  for(int\
    \ i=0;i<d;i++) cin>>as[i].v;\n  for(int i=0;i<d;i++) cin>>cs[i].v;\n\n  reverse(cs.begin(),cs.end());\n\
    \  for(auto &c:cs) c=-c;\n  cs.emplace_back(1);\n\n  BostanMori<M> seq(conv);\n\
    \  cout<<seq.build(k,as,cs)<<endl;\n  return 0;\n}\n"
  dependsOn:
  - mod/mint.cpp
  - convolution/numbertheoretictransform.cpp
  - math/bostanmori.cpp
  isVerificationFile: true
  path: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
  requiredBy: []
  timestamp: '2021-03-25 09:46:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
- /verify/test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp.html
title: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
---
