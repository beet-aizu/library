---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tetration_mod
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ mod/tetration.cpp: line 8: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tetration_mod\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#include \"../../math/totient.cpp\"\
    \n#include \"../../mod/tetration.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int T;\n  cin>>T;\n  for(int t=0;t<T;t++){\n\
    \    int a,b,m;\n    cin>>a>>b>>m;\n    cout<<tetration(a,b,m)<<\"\\n\";\n  }\n\
    \  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - math/totient.cpp
  - mod/tetration.cpp
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/totient.cpp
    title: math/totient.cpp
  - icon: ':heavy_check_mark:'
    path: mod/tetration.cpp
    title: mod/tetration.cpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: test/yosupo/tetration_mod.test.cpp
  requiredBy: []
  timestamp: '2020-03-12 17:15:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: test/yosupo/tetration_mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/tetration_mod.test.cpp
- /verify/test/yosupo/tetration_mod.test.cpp.html
title: test/yosupo/tetration_mod.test.cpp
---