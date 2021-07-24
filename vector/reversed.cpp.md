---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/3211.test.cpp
    title: test/yukicoder/3211.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"vector/reversed.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename T>\nvector<T>\
    \ reversed(vector<T> vs){\n  reverse(vs.begin(),vs.end());\n  return vs;\n}\n\
    //END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n\n//BEGIN CUT HERE\ntemplate<typename T>\nvector<T> reversed(vector<T>\
    \ vs){\n  reverse(vs.begin(),vs.end());\n  return vs;\n}\n//END CUT HERE\n#ifndef\
    \ call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: vector/reversed.cpp
  requiredBy: []
  timestamp: '2021-07-24 22:40:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/3211.test.cpp
documentation_of: vector/reversed.cpp
layout: document
redirect_from:
- /library/vector/reversed.cpp
- /library/vector/reversed.cpp.html
title: vector/reversed.cpp
---
