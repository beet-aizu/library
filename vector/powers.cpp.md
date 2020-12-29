---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/5633.test.cpp
    title: test/yukicoder/5633.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"vector/powers.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n\n//BEGIN CUT HERE\n// [0, n]\ntemplate<typename T>\nvector<T>\
    \ powers(int n,T x){\n  vector<T> po(n+1,T(1));\n  for(int i=0;i<n;i++) po[i+1]=po[i]*x;\n\
    \  return po;\n}\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n\n//BEGIN CUT HERE\n// [0, n]\ntemplate<typename T>\nvector<T> powers(int\
    \ n,T x){\n  vector<T> po(n+1,T(1));\n  for(int i=0;i<n;i++) po[i+1]=po[i]*x;\n\
    \  return po;\n}\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: vector/powers.cpp
  requiredBy: []
  timestamp: '2020-12-29 11:19:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/5633.test.cpp
documentation_of: vector/powers.cpp
layout: document
redirect_from:
- /library/vector/powers.cpp
- /library/vector/powers.cpp.html
title: vector/powers.cpp
---
