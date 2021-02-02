---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/run.cpp
    title: string/run.cpp
  - icon: ':heavy_check_mark:'
    path: string/zalgorithm.cpp
    title: string/zalgorithm.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/runenumerate
    links:
    - https://judge.yosupo.jp/problem/runenumerate
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/run.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/runenumerate\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../string/zalgorithm.cpp\"\n#include \"../../string/run.cpp\"\n#undef call_from_test\n\
    \nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  string ss;\n\
    \  cin>>ss;\n  auto run=Run::enumerate(ss);\n\n  set<Run::P> vis;\n  vector<Run::T>\
    \ ans;\n  for(int t=1;t<=(int)ss.size();t++){\n    for(auto lr:run[t]){\n    \
    \  if(vis.count(lr)) continue;\n      vis.emplace(lr);\n      ans.emplace_back(t,lr.first,lr.second);\n\
    \    }\n  }\n\n  cout<<ans.size()<<endl;\n  for(auto tlr:ans){\n    int t,l,r;\n\
    \    tie(t,l,r)=tlr;\n    cout<<t<<\" \"<<l<<\" \"<<r<<\"\\n\";\n  }\n  cout<<flush;\n\
    \  return 0;\n}\n"
  dependsOn:
  - string/zalgorithm.cpp
  - string/run.cpp
  isVerificationFile: true
  path: test/yosupo/runenumerate.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 13:26:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/runenumerate.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/runenumerate.test.cpp
- /verify/test/yosupo/runenumerate.test.cpp.html
title: test/yosupo/runenumerate.test.cpp
---
