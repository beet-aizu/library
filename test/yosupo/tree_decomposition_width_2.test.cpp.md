---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/nicetree.cpp
    title: graph/nicetree.cpp
  - icon: ':heavy_check_mark:'
    path: tools/drop.cpp
    title: tools/drop.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/tree_decomposition_width_2
    links:
    - https://judge.yosupo.jp/problem/tree_decomposition_width_2
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/nicetree.cpp: line 226: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/tree_decomposition_width_2\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../tools/drop.cpp\"\n#include \"../../graph/nicetree.cpp\"\n#undef call_from_test\n\
    \nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  const char newl\
    \ = '\\n';\n\n  {string s;cin>>s;}\n  {string s;cin>>s;}\n\n  int n,m;\n  cin>>n>>m;\n\
    \  NiceTree G(n);\n  for(int i=0;i<m;i++){\n    int u,v;\n    cin>>u>>v;\n   \
    \ u--;v--;\n    G.add_edge(u,v);\n  }\n\n  G.build();\n  auto T=G.T;\n  if(T.empty())\
    \ drop(-1);\n\n  assert((int)T.size()<=3*n+m+10);\n  cout<<\"s td \"<<T.size()<<'\
    \ '<<2<<' '<<n<<newl;\n\n  for(int i=0;i<(int)T.size();i++){\n    cout<<\"b \"\
    <<i+1;\n    for(int v:T[i].bag) cout<<' '<<v+1;\n    cout<<newl;\n  }\n\n  for(int\
    \ i=0;i<(int)T.size();i++)\n    for(int j:T[i].child) cout<<i+1<<' '<<j+1<<newl;\n\
    \n  for(int i=1;i<(int)T.size();i++)\n    if(T[i].is_root) cout<<1<<' '<<i+1<<newl;\n\
    \  return 0;\n}\n"
  dependsOn:
  - tools/drop.cpp
  - graph/nicetree.cpp
  isVerificationFile: true
  path: test/yosupo/tree_decomposition_width_2.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 16:01:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/tree_decomposition_width_2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/tree_decomposition_width_2.test.cpp
- /verify/test/yosupo/tree_decomposition_width_2.test.cpp.html
title: test/yosupo/tree_decomposition_width_2.test.cpp
---
