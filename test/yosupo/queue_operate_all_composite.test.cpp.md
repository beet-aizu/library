---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/slidingwindowaggregation.cpp
    title: datastructure/slidingwindowaggregation.cpp
  - icon: ':heavy_check_mark:'
    path: math/linearfunction.cpp
    title: math/linearfunction.cpp
  - icon: ':question:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/slidingwindowaggregation.cpp: line 47: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/queue_operate_all_composite\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../mod/mint.cpp\"\n#include \"../../math/linearfunction.cpp\"\n#include\
    \ \"../../datastructure/slidingwindowaggregation.cpp\"\n#undef call_from_test\n\
    \nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  using M = Mint<int,\
    \ 998244353>;\n  using T = LinearFunction<M>;\n  auto f=[](T a,T b){return a*b;};\n\
    \  SWAG<T, T> swag(f,T::mul_identity());\n\n  int q;\n  cin>>q;\n  for(int i=0;i<q;i++){\n\
    \    int t;\n    cin>>t;\n    if(t==0){\n      int a,b;\n      cin>>a>>b;\n  \
    \    swag.push(T(M(a),M(b)));\n    }\n    if(t==1){\n      swag.pop();\n    }\n\
    \    if(t==2){\n      int x;\n      cin>>x;\n      swag.fold([&](T a,T b){cout<<f(a,b)(x)<<\"\
    \\n\";});\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - mod/mint.cpp
  - math/linearfunction.cpp
  - datastructure/slidingwindowaggregation.cpp
  isVerificationFile: true
  path: test/yosupo/queue_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2021-03-25 09:46:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/queue_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/queue_operate_all_composite.test.cpp
- /verify/test/yosupo/queue_operate_all_composite.test.cpp.html
title: test/yosupo/queue_operate_all_composite.test.cpp
---
