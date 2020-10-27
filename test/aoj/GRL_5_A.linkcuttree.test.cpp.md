---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: linkcuttree/base.cpp
    title: linkcuttree/base.cpp
  - icon: ':heavy_check_mark:'
    path: linkcuttree/farthest.cpp
    title: linkcuttree/farthest.cpp
  - icon: ':question:'
    path: tools/chminmax.cpp
    title: tools/chminmax.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ linkcuttree/farthest.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../tools/chminmax.cpp\"\n#include \"../../linkcuttree/base.cpp\"\n#include\
    \ \"../../linkcuttree/farthest.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  using Node = NodeBase<int>;\n\
    \  constexpr size_t LIM = 2e6 + 200;\n  using LCT = Farthest<Node, LIM>;\n  LCT\
    \ lct;\n\n  vector<LCT::Node*> vs(1e5+100);\n  vector<LCT::Node*> es(1e5+100);\n\
    \n  int n;\n  cin>>n;\n  for(int i=0;i<n;i++) vs[i]=lct.create(0);\n\n  for(int\
    \ i=1;i<n;i++){\n    int s,t,w;\n    cin>>s>>t>>w;\n    es[i]=lct.create(w);\n\
    \    lct.evert(vs[s]);\n    lct.evert(vs[t]);\n    lct.link(es[i],vs[s]);\n  \
    \  lct.link(es[i],vs[t]);\n  }\n\n  int ans=0;\n  for(int i=0;i<n;i++){\n    lct.evert(vs[i]);\n\
    \    chmax(ans,vs[i]->ld);\n  }\n\n  cout<<ans<<endl;\n  return 0;\n}\n"
  dependsOn:
  - tools/chminmax.cpp
  - linkcuttree/base.cpp
  - linkcuttree/farthest.cpp
  isVerificationFile: true
  path: test/aoj/GRL_5_A.linkcuttree.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 13:26:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_5_A.linkcuttree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_A.linkcuttree.test.cpp
- /verify/test/aoj/GRL_5_A.linkcuttree.test.cpp.html
title: test/aoj/GRL_5_A.linkcuttree.test.cpp
---
