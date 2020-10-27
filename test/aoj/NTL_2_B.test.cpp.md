---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/bigint.cpp
    title: tools/bigint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_2_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_2_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ tools/bigint.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_2_B\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../tools/bigint.cpp\"\n#undef call_from_test\n\nsigned main(){\n  bigint\
    \ a,b;\n  cin>>a>>b;\n  cout<<a-b<<endl;\n  return 0;\n}\n"
  dependsOn:
  - tools/bigint.cpp
  isVerificationFile: true
  path: test/aoj/NTL_2_B.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 12:55:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_2_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_2_B.test.cpp
- /verify/test/aoj/NTL_2_B.test.cpp.html
title: test/aoj/NTL_2_B.test.cpp
---
