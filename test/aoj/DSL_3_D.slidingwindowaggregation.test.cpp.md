---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/slidingwindowaggregation.cpp
    title: datastructure/slidingwindowaggregation.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/slidingwindowaggregation.cpp: line 47: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../datastructure/slidingwindowaggregation.cpp\"\n#undef call_from_test\n\
    \nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,l;\n  cin>>n>>l;\n\
    \  vector<int> as(n);\n  for(int i=0;i<n;i++) cin>>as[i];\n\n  auto f=[](int a,int\
    \ b){return min(a,b);};\n  SWAG<int, int> swag(f,INT_MAX);\n\n  for(int i=0;i<l;i++)\
    \ swag.push(as[i]);\n  for(int i=0;i+l<=n;i++){\n    if(i) cout<<\" \";\n    swag.fold([](int\
    \ a,int b){cout<<min(a,b);});\n    if(i+l<n){\n      swag.pop();\n      swag.push(as[i+l]);\n\
    \    }\n  }\n  cout<<endl;\n  return 0;\n}\n"
  dependsOn:
  - datastructure/slidingwindowaggregation.cpp
  isVerificationFile: true
  path: test/aoj/DSL_3_D.slidingwindowaggregation.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 15:01:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_3_D.slidingwindowaggregation.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_3_D.slidingwindowaggregation.test.cpp
- /verify/test/aoj/DSL_3_D.slidingwindowaggregation.test.cpp.html
title: test/aoj/DSL_3_D.slidingwindowaggregation.test.cpp
---
