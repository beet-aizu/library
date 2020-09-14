---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 2 \"math/totient.cpp\"\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nT totient(T\
    \ n){\n  T res=n;\n  for(T i=2;i*i<=n;i++){\n    if(n%i==0){\n      res=res/i*(i-1);\n\
    \      for(;n%i==0;n/=i);\n    }\n  }\n  if(n!=1) res=res/n*(n-1);\n  return res;\n\
    }\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nT totient(T n){\n  T res=n;\n\
    \  for(T i=2;i*i<=n;i++){\n    if(n%i==0){\n      res=res/i*(i-1);\n      for(;n%i==0;n/=i);\n\
    \    }\n  }\n  if(n!=1) res=res/n*(n-1);\n  return res;\n}\n//END CUT HERE\n#ifndef\
    \ call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: mod/tetration.cpp
    title: mod/tetration.cpp
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_D.test.cpp
    title: test/aoj/NTL_1_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0472.test.cpp
    title: test/yukicoder/0472.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/tetration_mod.test.cpp
    title: test/yosupo/tetration_mod.test.cpp
  isVerificationFile: false
  path: math/totient.cpp
  requiredBy:
  - mod/tetration.cpp
  timestamp: '2020-03-12 17:02:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - test/aoj/NTL_1_D.test.cpp
  - test/yukicoder/0472.test.cpp
  - test/yosupo/tetration_mod.test.cpp
documentation_of: math/totient.cpp
layout: document
redirect_from:
- /library/math/totient.cpp
- /library/math/totient.cpp.html
title: math/totient.cpp
---
