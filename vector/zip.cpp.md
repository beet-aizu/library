---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2563.test.cpp
    title: test/aoj/2563.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2725.test.cpp
    title: test/aoj/2725.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2969.test.cpp
    title: test/aoj/2969.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"vector/zip.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename ...Ts>\ndecltype(auto) zip(vector<Ts>...\
    \ args){\n  vector<decltype(make_tuple(args[0]...))> res;\n  int n=min({args.size()...});\n\
    \  res.reserve(n);\n  for(int i=0;i<n;i++) res.emplace_back(args[i]...);\n  return\
    \ res;\n}\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n\
    }\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n\n//BEGIN CUT HERE\ntemplate<typename ...Ts>\ndecltype(auto) zip(vector<Ts>...\
    \ args){\n  vector<decltype(make_tuple(args[0]...))> res;\n  int n=min({args.size()...});\n\
    \  res.reserve(n);\n  for(int i=0;i<n;i++) res.emplace_back(args[i]...);\n  return\
    \ res;\n}\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n\
    }\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: vector/zip.cpp
  requiredBy: []
  timestamp: '2020-10-27 12:29:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2969.test.cpp
  - test/aoj/2725.test.cpp
  - test/aoj/2563.test.cpp
documentation_of: vector/zip.cpp
layout: document
redirect_from:
- /library/vector/zip.cpp
- /library/vector/zip.cpp.html
title: vector/zip.cpp
---
