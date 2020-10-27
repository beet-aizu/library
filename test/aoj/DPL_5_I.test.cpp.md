---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  - icon: ':question:'
    path: combinatorics/surjection.cpp
    title: combinatorics/surjection.cpp
  - icon: ':question:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_I
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_I
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ combinatorics/surjection.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_I\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../mod/mint.cpp\"\n#include \"../../combinatorics/enumeration.cpp\"\n#include\
    \ \"../../combinatorics/surjection.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  int n,k;\n  scanf(\"%d %d\",&n,&k);\n  using M = Mint<int>;\n  M res=surjection<M>(n,k);\n\
    \  for(int i=1;i<=k;i++) res/=M(i);\n  printf(\"%d\\n\",res.v);\n  return 0;\n\
    }\n"
  dependsOn:
  - mod/mint.cpp
  - combinatorics/enumeration.cpp
  - combinatorics/surjection.cpp
  isVerificationFile: true
  path: test/aoj/DPL_5_I.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 13:13:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_5_I.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_5_I.test.cpp
- /verify/test/aoj/DPL_5_I.test.cpp.html
title: test/aoj/DPL_5_I.test.cpp
---
