---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/kruskal.cpp
    title: graph/kruskal.cpp
  - icon: ':x:'
    path: graph/manhattanmst.cpp
    title: graph/manhattanmst.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/manhattanmst
    links:
    - https://judge.yosupo.jp/problem/manhattanmst
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/kruskal.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/manhattanmst\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../graph/manhattanmst.cpp\"\n#include \"../../graph/kruskal.cpp\"\n#undef\
    \ call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  const char newl = '\\n';\n\n  using ll = long long;\n\n  int n;\n  cin>>n;\n\
    \  vector<ll> xs(n),ys(n);\n  for(int i=0;i<n;i++) cin>>xs[i]>>ys[i];\n\n  Kruskal<ll>\
    \ mst(n);\n  for(auto[u,v]:manhattanmst(xs,ys))\n    mst.add_edge(u,v,abs(xs[u]-xs[v])+abs(ys[u]-ys[v]));\n\
    \n  cout<<mst.build()<<newl;\n  for(auto e:mst.es)\n    if(e.used) cout<<e.src<<'\
    \ '<<e.dst<<newl;\n  return 0;\n}\n"
  dependsOn:
  - graph/manhattanmst.cpp
  - graph/kruskal.cpp
  isVerificationFile: true
  path: test/yosupo/manhattanmst.test.cpp
  requiredBy: []
  timestamp: '2020-10-09 14:11:38+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/manhattanmst.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/manhattanmst.test.cpp
- /verify/test/yosupo/manhattanmst.test.cpp.html
title: test/yosupo/manhattanmst.test.cpp
---
