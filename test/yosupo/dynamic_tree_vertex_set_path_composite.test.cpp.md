---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ linkcuttree/path.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../mod/mint.cpp\"\n#include \"../../linkcuttree/base.cpp\"\n#include\
    \ \"../../linkcuttree/path.cpp\"\n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n  const char newl = '\\n';\n\n  int n,q;\n  cin>>n>>q;\n\
    \  vector<int> as(n),bs(n);\n  for(int i=0;i<n;i++) cin>>as[i]>>bs[i];\n\n  using\
    \ M = Mint<int, 998244353>;\n\n  struct T{\n    M a,b;\n    T(int a=0,int b=0):a(a),b(b){}\n\
    \    T(M a,M b):a(a),b(b){}\n  };\n\n  auto f=[&](T x,T y){return T(x.a*y.a,x.b*y.a+y.b);};\n\
    \n  using P = pair<T, T>;\n  using Node = NodeBase<P, int>;\n  auto ff=[&](P a,P\
    \ b){return P(f(a.first,b.first),f(b.second,a.second));};\n  auto gg=[&](P a,int){return\
    \ a;};\n  auto hh=[&](int a,int){return a;};\n  auto flip=[&](P a){return P(a.second,a.first);};\n\
    \n  constexpr size_t LIM = 2e5+100;\n  using LCT = Path<Node, LIM>;\n  LCT lct(ff,gg,hh,flip,0);\n\
    \n  for(int i=0;i<n;i++) lct.create(P(T(as[i],bs[i]),T(as[i],bs[i])));\n\n  for(int\
    \ i=1;i<n;i++){\n    int u,v;\n    cin>>u>>v;\n    lct.evert(lct[v]);\n    lct.link(lct[u],lct[v]);\n\
    \  }\n\n  for(int i=0;i<q;i++){\n    int t;\n    cin>>t;\n\n    if(t==0){\n  \
    \    int u,v,w,x;\n      cin>>u>>v>>w>>x;\n\n      lct.evert(lct[u]);\n      lct.cut(lct[v]);\n\
    \n      lct.evert(lct[x]);\n      lct.link(lct[w],lct[x]);\n    }\n\n    if(t==1){\n\
    \      int p,c,d;\n      cin>>p>>c>>d;\n      lct.set_val(lct[p],P(T(c,d),T(c,d)));\n\
    \    }\n\n    if(t==2){\n      int u,v,x;\n      cin>>u>>v>>x;\n      lct.evert(lct[u]);\n\
    \      auto res=lct.query(lct[v]).first;\n      cout<<(res.a*M(x)+res.b).v<<newl;\n\
    \    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - mod/mint.cpp
  - linkcuttree/base.cpp
  - linkcuttree/path.cpp
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  - icon: ':heavy_check_mark:'
    path: linkcuttree/base.cpp
    title: linkcuttree/base.cpp
  - icon: ':heavy_check_mark:'
    path: linkcuttree/path.cpp
    title: linkcuttree/path.cpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '2020-07-27 11:09:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
- /verify/test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp.html
title: test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
---
