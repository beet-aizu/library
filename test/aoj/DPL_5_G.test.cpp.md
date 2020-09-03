---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 58, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ combinatorics/bell.cpp: line 8: unable to process #include in #if / #ifdef /\
    \ #ifndef other than include guards\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../mod/mint.cpp\"\n#include \"../../combinatorics/enumeration.cpp\"\
    \n#include \"../../combinatorics/bell.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  int n,k;\n  scanf(\"%d %d\",&n,&k);\n  printf(\"%d\\n\",bell<Mint<int>>(n,k).v);\n\
    \  return 0;\n}\n"
  dependsOn:
  - mod/mint.cpp
  - combinatorics/enumeration.cpp
  - combinatorics/bell.cpp
  extendedDependsOn:
  - icon: ':warning:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  - icon: ':warning:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  - icon: ':warning:'
    path: combinatorics/bell.cpp
    title: combinatorics/bell.cpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: test/aoj/DPL_5_G.test.cpp
  requiredBy: []
  timestamp: '2020-03-12 17:02:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: test/aoj/DPL_5_G.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_5_G.test.cpp
- /verify/test/aoj/DPL_5_G.test.cpp.html
title: test/aoj/DPL_5_G.test.cpp
---
