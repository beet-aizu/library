---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_1000000007
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 58, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ convolution/arbitrarymod.cpp: line 8: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../mod/mint.cpp\"\n#define double long double\n#include \"../../convolution/fastfouriertransform.cpp\"\
    \n#undef double\n#include \"../../convolution/arbitrarymod.cpp\"\n#undef call_from_test\n\
    \nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,m;\n  cin>>n>>m;\n\
    \n  using M = Mint<int>;\n  ArbitraryMod<M> arb;\n\n  vector<M> as(n),bs(m);\n\
    \  for(int i=0;i<n;i++) cin>>as[i].v;\n  for(int i=0;i<m;i++) cin>>bs[i].v;\n\
    \  auto cs=arb.multiply(as,bs);\n  for(int i=0;i<(int)cs.size();i++){\n    if(i)\
    \ cout<<\" \";\n    cout<<cs[i];\n  }\n  cout<<endl;\n  return 0;\n}\n"
  dependsOn:
  - mod/mint.cpp
  - convolution/fastfouriertransform.cpp
  - convolution/arbitrarymod.cpp
  extendedDependsOn:
  - icon: ':warning:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  - icon: ':warning:'
    path: convolution/fastfouriertransform.cpp
    title: convolution/fastfouriertransform.cpp
  - icon: ':warning:'
    path: convolution/arbitrarymod.cpp
    title: convolution/arbitrarymod.cpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: test/yosupo/convolution_mod_1000000007.test.cpp
  requiredBy: []
  timestamp: '2020-03-12 17:02:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: test/yosupo/convolution_mod_1000000007.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/convolution_mod_1000000007.test.cpp
- /verify/test/yosupo/convolution_mod_1000000007.test.cpp.html
title: test/yosupo/convolution_mod_1000000007.test.cpp
---
