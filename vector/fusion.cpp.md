---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2563.test.cpp
    title: test/aoj/2563.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2359.test.cpp
    title: test/aoj/2359.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"vector/fusion.cpp\"\n\n#ifndef call_from_test\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename\
    \ T, typename ...Ts>\nvector<T> fusion(vector<T> bs,Ts... ts){\n  auto append=[&](auto\
    \ vs){for(auto v:vs) bs.emplace_back(v);};\n  initializer_list<int>{(void(append(ts)),0)...};\n\
    \  return bs;\n}\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename T, typename ...Ts>\nvector<T>\
    \ fusion(vector<T> bs,Ts... ts){\n  auto append=[&](auto vs){for(auto v:vs) bs.emplace_back(v);};\n\
    \  initializer_list<int>{(void(append(ts)),0)...};\n  return bs;\n}\n//END CUT\
    \ HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: vector/fusion.cpp
  requiredBy: []
  timestamp: '2020-04-18 17:56:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2563.test.cpp
  - test/aoj/2359.test.cpp
documentation_of: vector/fusion.cpp
layout: document
redirect_from:
- /library/vector/fusion.cpp
- /library/vector/fusion.cpp.html
title: vector/fusion.cpp
---
