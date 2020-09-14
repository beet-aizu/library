---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/stronglyconnectedcomponent.cpp
    title: graph/stronglyconnectedcomponent.cpp
  - icon: ':heavy_check_mark:'
    path: graph/twosatisfiability.cpp
    title: graph/twosatisfiability.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 189, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/twosatisfiability.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#include \"../../graph/stronglyconnectedcomponent.cpp\"\
    \n#include \"../../graph/twosatisfiability.cpp\"\n#undef call_from_test\n\nsigned\
    \ main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  string s;\n  cin>>s;\n\
    \  cin>>s;\n\n  int n,m;\n  cin>>n>>m;\n\n  TwoSat ts(n+1);\n  for(int i=0;i<m;i++){\n\
    \    int a,b,c;\n    cin>>a>>b>>c;\n    if(a<0) a=ts.negate(abs(a));\n    if(b<0)\
    \ b=ts.negate(abs(b));\n    ts.add_or(a,b);\n  }\n\n  auto res=ts.build();\n \
    \ if(res.empty()){\n    cout<<\"s UNSATISFIABLE\"<<endl;\n    return 0;\n  }\n\
    \n  cout<<\"s SATISFIABLE\"<<endl;\n  cout<<\"v\";\n  for(int i=1;i<=n;i++)\n\
    \    cout<<\" \"<<(res[i]?i:-i);\n  cout<<\" \"<<0<<endl;\n  return 0;\n}\n"
  dependsOn:
  - graph/stronglyconnectedcomponent.cpp
  - graph/twosatisfiability.cpp
  isVerificationFile: true
  path: test/yosupo/two_sat.test.cpp
  requiredBy: []
  timestamp: '2020-03-05 21:02:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/two_sat.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/two_sat.test.cpp
- /verify/test/yosupo/two_sat.test.cpp.html
title: test/yosupo/two_sat.test.cpp
---
