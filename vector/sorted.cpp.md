---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2969.test.cpp
    title: test/aoj/2969.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"vector/sorted.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename T>\nvector<T> sorted(vector<T>\
    \ vs){\n  sort(vs.begin(),vs.end());\n  return vs;\n}\n//END CUT HERE\n#ifndef\
    \ call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n\n//BEGIN CUT HERE\ntemplate<typename T>\nvector<T> sorted(vector<T> vs){\n\
    \  sort(vs.begin(),vs.end());\n  return vs;\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: vector/sorted.cpp
  requiredBy: []
  timestamp: '2020-11-15 18:05:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2969.test.cpp
documentation_of: vector/sorted.cpp
layout: document
redirect_from:
- /library/vector/sorted.cpp
- /library/vector/sorted.cpp.html
title: vector/sorted.cpp
---
