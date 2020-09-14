---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2563.test.cpp
    title: test/aoj/2563.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 2 \"vector/zip.cpp\"\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename ...Ts>\ndecltype(auto)\
    \ zip(vector<Ts>... args){\n  vector<decltype(make_tuple(args[0]...))> res;\n\
    \  int n=min({args.size()...});\n  res.reserve(n);\n  for(int i=0;i<n;i++) res.emplace_back(args[i]...);\n\
    \  return res;\n}\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  vector<int>\
    \ as({1,2,3});\n  vector<string> bs({\"a\",\"b\",\"c\"});\n  auto zs=zip(as,bs);\n\
    \  for(auto [x,y]:zs) cout<<x<<\" \"<<y<<endl;\n  return 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename ...Ts>\ndecltype(auto) zip(vector<Ts>...\
    \ args){\n  vector<decltype(make_tuple(args[0]...))> res;\n  int n=min({args.size()...});\n\
    \  res.reserve(n);\n  for(int i=0;i<n;i++) res.emplace_back(args[i]...);\n  return\
    \ res;\n}\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  vector<int>\
    \ as({1,2,3});\n  vector<string> bs({\"a\",\"b\",\"c\"});\n  auto zs=zip(as,bs);\n\
    \  for(auto [x,y]:zs) cout<<x<<\" \"<<y<<endl;\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: vector/zip.cpp
  requiredBy: []
  timestamp: '2020-04-18 17:56:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2563.test.cpp
documentation_of: vector/zip.cpp
layout: document
redirect_from:
- /library/vector/zip.cpp
- /library/vector/zip.cpp.html
title: vector/zip.cpp
---
