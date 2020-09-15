---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/stronglyconnectedcomponent.cpp
    title: graph/stronglyconnectedcomponent.cpp
  - icon: ':heavy_check_mark:'
    path: graph/arborescence_edmond.cpp
    title: graph/arborescence_edmond.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/arborescence_edmond.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../graph/stronglyconnectedcomponent.cpp\"\n#include \"../../graph/arborescence_edmond.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,m,r;\n  cin>>n>>m>>r;\n\n  Arborescence<int> G(n);\n  for(int i=0;i<m;i++){\n\
    \    int s,t,w;\n    cin>>s>>t>>w;\n    G.add_edge(s,t,w);\n  }\n\n  cout<<G.build(r)<<endl;\n\
    \  return 0;\n}\n"
  dependsOn:
  - graph/stronglyconnectedcomponent.cpp
  - graph/arborescence_edmond.cpp
  isVerificationFile: true
  path: test/aoj/GRL_2_B.test.cpp
  requiredBy: []
  timestamp: '2020-05-07 20:21:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_2_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_2_B.test.cpp
- /verify/test/aoj/GRL_2_B.test.cpp.html
title: test/aoj/GRL_2_B.test.cpp
---