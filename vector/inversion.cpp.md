---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/binaryindexedtree.cpp
    title: Binary Indexed Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_5_D.test.cpp
    title: test/aoj/ALDS1_5_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ vector/inversion.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../datastructure/binaryindexedtree.cpp\"\n\
    #undef call_from_test\n\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename T>\nlong\
    \ long inversion(vector<T> vs){\n  int n=vs.size();\n  long long res=0;\n  BIT<T>\
    \ bit(n);\n  for(T v:vs){\n    assert(v<=n);\n    res+=bit.query(v+1,n+1);\n \
    \   bit.add(v,1);\n  }\n  return res;\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - datastructure/binaryindexedtree.cpp
  isVerificationFile: false
  path: vector/inversion.cpp
  requiredBy: []
  timestamp: '2021-05-01 12:56:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_5_D.test.cpp
documentation_of: vector/inversion.cpp
layout: document
redirect_from:
- /library/vector/inversion.cpp
- /library/vector/inversion.cpp.html
title: vector/inversion.cpp
---
