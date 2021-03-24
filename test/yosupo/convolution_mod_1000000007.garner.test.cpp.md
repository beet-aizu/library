---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/garner.cpp
    title: convolution/garner.cpp
  - icon: ':heavy_check_mark:'
    path: convolution/numbertheoretictransform.cpp
    title: convolution/numbertheoretictransform.cpp
  - icon: ':heavy_check_mark:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_1000000007
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_1000000007
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
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/convolution_mod_1000000007\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../mod/mint.cpp\"\n#include \"../../convolution/numbertheoretictransform.cpp\"\
    \n#include \"../../convolution/garner.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,m;\n  cin>>n>>m;\n\n  vector<int>\
    \ as(n),bs(m);\n  for(int i=0;i<n;i++) cin>>as[i];\n  for(int i=0;i<m;i++) cin>>bs[i];\n\
    \n  const int MOD = 1e9+7;\n  Garner arb;\n  auto cs=arb.multiply(as,bs,MOD);\n\
    \  for(int i=0;i<(int)cs.size();i++){\n    if(i) cout<<\" \";\n    cout<<cs[i];\n\
    \  }\n  cout<<endl;\n  return 0;\n}\n"
  dependsOn:
  - mod/mint.cpp
  - convolution/numbertheoretictransform.cpp
  - convolution/garner.cpp
  isVerificationFile: true
  path: test/yosupo/convolution_mod_1000000007.garner.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 17:04:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/convolution_mod_1000000007.garner.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/convolution_mod_1000000007.garner.test.cpp
- /verify/test/yosupo/convolution_mod_1000000007.garner.test.cpp.html
title: test/yosupo/convolution_mod_1000000007.garner.test.cpp
---
