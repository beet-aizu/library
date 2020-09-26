---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1950.test.cpp
    title: test/yukicoder/1950.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1948.test.cpp
    title: test/yukicoder/1948.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2113.test.cpp
    title: test/yukicoder/2113.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4862.test.cpp
    title: test/yukicoder/4862.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4569.test.cpp
    title: test/yukicoder/4569.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4387.test.cpp
    title: test/yukicoder/4387.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"io/single.cpp\"\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename T=int>\nvector<T>\
    \ read(size_t n){\n  vector<T> ts(n);\n  for(size_t i=0;i<n;i++) cin>>ts[i];\n\
    \  return ts;\n}\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename T=int>\nvector<T> read(size_t\
    \ n){\n  vector<T> ts(n);\n  for(size_t i=0;i<n;i++) cin>>ts[i];\n  return ts;\n\
    }\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: io/single.cpp
  requiredBy: []
  timestamp: '2020-08-07 15:47:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1950.test.cpp
  - test/yukicoder/1948.test.cpp
  - test/yukicoder/2113.test.cpp
  - test/yukicoder/4862.test.cpp
  - test/yukicoder/4569.test.cpp
  - test/yukicoder/4387.test.cpp
documentation_of: io/single.cpp
layout: document
redirect_from:
- /library/io/single.cpp
- /library/io/single.cpp.html
title: io/single.cpp
---
