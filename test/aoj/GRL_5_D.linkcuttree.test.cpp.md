---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: linkcuttree/base.cpp
    title: linkcuttree/base.cpp
  - icon: ':question:'
    path: linkcuttree/path.cpp
    title: linkcuttree/path.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ linkcuttree/path.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../linkcuttree/base.cpp\"\n#include \"../../linkcuttree/path.cpp\"\n#undef\
    \ call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n;\n  cin>>n;\n\n  using Node = NodeBase<int, int>;\n  constexpr size_t\
    \ LIM = 1e5+100;\n  using LCT = Path<Node, LIM>;\n\n  auto f=[](int a,int b){return\
    \ a+b;};\n  LCT lct(f,f,f,0);\n\n  for(int i=0;i<n;i++) lct.create(0);\n  for(int\
    \ i=0;i<n;i++){\n    int k;\n    cin>>k;\n    for(int j=0;j<k;j++){\n      int\
    \ c;\n      cin>>c;\n      lct.link(lct[i],lct[c]);\n    }\n  }\n\n  int q;\n\
    \  cin>>q;\n  for(int i=0;i<q;i++){\n    int t;\n    cin>>t;\n    if(t==0){\n\
    \      int a,b;\n      cin>>a>>b;\n      lct.expose(lct[a]);\n      lct[a]->val+=b;\n\
    \      lct.pushup(lct[a]);\n    }\n    if(t==1){\n      int a;\n      cin>>a;\n\
    \      cout<<lct.query(lct[a])<<\"\\n\";\n    }\n  }\n  cout<<flush;\n  return\
    \ 0;\n}\n"
  dependsOn:
  - linkcuttree/base.cpp
  - linkcuttree/path.cpp
  isVerificationFile: true
  path: test/aoj/GRL_5_D.linkcuttree.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 19:04:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_5_D.linkcuttree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_D.linkcuttree.test.cpp
- /verify/test/aoj/GRL_5_D.linkcuttree.test.cpp.html
title: test/aoj/GRL_5_D.linkcuttree.test.cpp
---
