---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/runenumerate
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 58, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/run.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/runenumerate\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#include \"../../string/zalgorithm.cpp\"\
    \n#include \"../../string/run.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  string ss;\n  cin>>ss;\n  auto\
    \ run=Run::enumerate(ss);\n\n  set<Run::P> vis;\n  vector<Run::T> ans;\n  for(int\
    \ t=1;t<=(int)ss.size();t++){\n    for(auto lr:run[t]){\n      if(vis.count(lr))\
    \ continue;\n      vis.emplace(lr);\n      ans.emplace_back(t,lr.first,lr.second);\n\
    \    }\n  }\n\n  cout<<ans.size()<<endl;\n  for(auto tlr:ans){\n    int t,l,r;\n\
    \    tie(t,l,r)=tlr;\n    cout<<t<<\" \"<<l<<\" \"<<r<<\"\\n\";\n  }\n  cout<<flush;\n\
    \  return 0;\n}\n"
  dependsOn:
  - string/zalgorithm.cpp
  - string/run.cpp
  extendedDependsOn:
  - icon: ':warning:'
    path: string/zalgorithm.cpp
    title: string/zalgorithm.cpp
  - icon: ':warning:'
    path: string/run.cpp
    title: string/run.cpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: test/yosupo/runenumerate.test.cpp
  requiredBy: []
  timestamp: '2020-03-05 21:02:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: test/yosupo/runenumerate.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/runenumerate.test.cpp
- /verify/test/yosupo/runenumerate.test.cpp.html
title: test/yosupo/runenumerate.test.cpp
---
