---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/unionfind.cpp
    title: datastructure/unionfind.cpp
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.cpp
    title: graph/kruskal.cpp
  - icon: ':heavy_check_mark:'
    path: graph/manhattanmst.cpp
    title: graph/manhattanmst.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/manhattanmst
    links:
    - https://judge.yosupo.jp/problem/manhattanmst
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/kruskal.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/manhattanmst\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include \"\
    ../../graph/manhattanmst.cpp\"\n#include \"../../datastructure/unionfind.cpp\"\
    \n#include \"../../graph/kruskal.cpp\"\n#undef call_from_test\n\n#ifdef SANITIZE\n\
    #define IGNORE\n#endif\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  const char newl = '\\n';\n\n  using ll = long long;\n\n  int n;\n  cin>>n;\n\
    \  vector<ll> xs(n),ys(n);\n  for(int i=0;i<n;i++) cin>>xs[i]>>ys[i];\n\n  Kruskal<ll>\
    \ mst(n);\n  for(auto[u,v]:manhattanmst(xs,ys))\n    mst.add_edge(u,v,abs(xs[u]-xs[v])+abs(ys[u]-ys[v]));\n\
    \n  cout<<mst.build()<<newl;\n  for(auto e:mst.es)\n    if(e.used) cout<<e.src<<'\
    \ '<<e.dst<<newl;\n  return 0;\n}\n"
  dependsOn:
  - graph/manhattanmst.cpp
  - datastructure/unionfind.cpp
  - graph/kruskal.cpp
  isVerificationFile: true
  path: test/yosupo/manhattanmst.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 19:32:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/manhattanmst.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/manhattanmst.test.cpp
- /verify/test/yosupo/manhattanmst.test.cpp.html
title: test/yosupo/manhattanmst.test.cpp
---
