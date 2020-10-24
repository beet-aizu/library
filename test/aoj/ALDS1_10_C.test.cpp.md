---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/longestcommonsubstring.cpp
    title: string/longestcommonsubstring.cpp
  - icon: ':heavy_check_mark:'
    path: tools/chminmax.cpp
    title: tools/chminmax.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/longestcommonsubstring.cpp: line 6: unable to process #include in #if\
    \ / #ifdef / #ifndef other than include guards\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../tools/chminmax.cpp\"\n#include \"../../string/longestcommonsubstring.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int q;\n  cin>>q;\n  while(q--){\n    string s,t;\n    cin>>s>>t;\n    cout<<longest_common_substring(s,t)<<\"\
    \\n\";\n  }\n  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - tools/chminmax.cpp
  - string/longestcommonsubstring.cpp
  isVerificationFile: true
  path: test/aoj/ALDS1_10_C.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 14:33:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_10_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_10_C.test.cpp
- /verify/test/aoj/ALDS1_10_C.test.cpp.html
title: test/aoj/ALDS1_10_C.test.cpp
---
