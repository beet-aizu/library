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
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ linkcuttree/path.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../linkcuttree/base.cpp\"\n#include \"../../linkcuttree/path.cpp\"\n#undef\
    \ call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  using ll = long long;\n\n  int n;\n  cin>>n;\n\n  using P = pair<ll, ll>;\n\
    \  using Node = NodeBase<P, ll>;\n  constexpr size_t LIM = 1e5+100;\n  using LCT\
    \ = Path<Node, LIM>;\n\n  auto f=[](P a,P b){return P(a.first+b.first,a.second+b.second);};\n\
    \  auto g=[](P a,int b){return P(a.first+b*a.second,a.second);};\n  auto h=[](ll\
    \ a,ll b){return a+b;};\n  LCT lct(f,g,h,0);\n\n  for(int i=0;i<n;i++) lct.create(P(0,1));\n\
    \  for(int i=0;i<n;i++){\n    int k;\n    cin>>k;\n    for(int j=0;j<k;j++){\n\
    \      int c;\n      cin>>c;\n      lct.link(lct[i],lct[c]);\n    }\n  }\n\n \
    \ int q;\n  cin>>q;\n  ll sum=0;\n  for(int i=0;i<q;i++){\n    int t;\n    cin>>t;\n\
    \    if(t==0){\n      int a,b;\n      cin>>a>>b;\n      lct.update(lct[a],b);\n\
    \      sum+=b;\n    }\n    if(t==1){\n      int a;\n      cin>>a;\n      cout<<lct.query(lct[a]).first-sum<<\"\
    \\n\";\n    }\n  }\n  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - linkcuttree/base.cpp
  - linkcuttree/path.cpp
  isVerificationFile: true
  path: test/aoj/GRL_5_E.linkcuttree.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 15:10:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_5_E.linkcuttree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_E.linkcuttree.test.cpp
- /verify/test/aoj/GRL_5_E.linkcuttree.test.cpp.html
title: test/aoj/GRL_5_E.linkcuttree.test.cpp
---
