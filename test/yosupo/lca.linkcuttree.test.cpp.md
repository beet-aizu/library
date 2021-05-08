---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: linkcuttree/base.cpp
    title: linkcuttree/base.cpp
  - icon: ':heavy_check_mark:'
    path: linkcuttree/path.cpp
    title: linkcuttree/path.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ linkcuttree/path.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/lca\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#include \"../../linkcuttree/base.cpp\"\
    \n#include \"../../linkcuttree/path.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,q;\n  cin>>n>>q;\n\n  using\
    \ Node = NodeBase<int, int>;\n  constexpr size_t LIM = 1e6;\n  using LCT = Path<Node,\
    \ LIM>;\n\n  auto f=[](int a,int b){return a+b;};\n  LCT lct(f,f,f,0);\n  for(int\
    \ i=0;i<n;i++) lct.create(0);\n\n  for(int i=1;i<n;i++){\n    int p;\n    cin>>p;\n\
    \    lct.link(lct[p],lct[i]);\n  }\n\n  for(int i=0;i<q;i++){\n    int u,v;\n\
    \    cin>>u>>v;\n    cout<<lct.idx(lct.lca(lct[u],lct[v]))<<\"\\n\";\n  }\n  cout<<flush;\n\
    \  return 0;\n}\n"
  dependsOn:
  - linkcuttree/base.cpp
  - linkcuttree/path.cpp
  isVerificationFile: true
  path: test/yosupo/lca.linkcuttree.test.cpp
  requiredBy: []
  timestamp: '2021-03-25 09:21:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/lca.linkcuttree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/lca.linkcuttree.test.cpp
- /verify/test/yosupo/lca.linkcuttree.test.cpp.html
title: test/yosupo/lca.linkcuttree.test.cpp
---
