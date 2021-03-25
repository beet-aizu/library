---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/5011.test.cpp
    title: test/yukicoder/5011.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/quotients.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\n// split [1, n] into ranges whose\
    \ elements have same quotients\ntemplate<typename T>\ndecltype(auto) quotients(T\
    \ n){\n  vector<pair<T, T>> vp;\n  T m;\n  for(m=1;m*m<=n;m++) vp.emplace_back(m,m);\n\
    \  for(T i=m;i>=1;i--){\n    T l=n/(i+1)+1,r=n/i;\n    if(l<=r and vp.back().second<l)\n\
    \      vp.emplace_back(l,r);\n  }\n  return vp;\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\n// split [1, n] into ranges whose elements have same\
    \ quotients\ntemplate<typename T>\ndecltype(auto) quotients(T n){\n  vector<pair<T,\
    \ T>> vp;\n  T m;\n  for(m=1;m*m<=n;m++) vp.emplace_back(m,m);\n  for(T i=m;i>=1;i--){\n\
    \    T l=n/(i+1)+1,r=n/i;\n    if(l<=r and vp.back().second<l)\n      vp.emplace_back(l,r);\n\
    \  }\n  return vp;\n}\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE\
    \ HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: math/quotients.cpp
  requiredBy: []
  timestamp: '2020-10-24 13:53:02+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/5011.test.cpp
documentation_of: math/quotients.cpp
layout: document
redirect_from:
- /library/math/quotients.cpp
- /library/math/quotients.cpp.html
title: math/quotients.cpp
---
