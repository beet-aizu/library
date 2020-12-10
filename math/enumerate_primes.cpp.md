---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1642.test.cpp
    title: test/aoj/1642.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/enumerate_primes.test.cpp
    title: test/yosupo/enumerate_primes.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/enumerate_primes.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\n// O(n)\nvector<int> enumerate_primes(int\
    \ n){\n  vector<bool> dp((n+1)/2,false);\n  vector<int> ps;\n  ps.reserve(n/10);\n\
    \  if(2<=n) ps.emplace_back(2);\n  for(int i=3;i<=n;i+=2){\n    if(!dp[i/2]) ps.emplace_back(i);\n\
    \    for(int j=1;i*ps[j]<=n;j++){\n      dp[i*ps[j]/2]=1;\n      if(i%ps[j]==0)\
    \ break;\n    }\n  }\n  return ps;\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\n// O(n)\nvector<int> enumerate_primes(int n){\n  vector<bool>\
    \ dp((n+1)/2,false);\n  vector<int> ps;\n  ps.reserve(n/10);\n  if(2<=n) ps.emplace_back(2);\n\
    \  for(int i=3;i<=n;i+=2){\n    if(!dp[i/2]) ps.emplace_back(i);\n    for(int\
    \ j=1;i*ps[j]<=n;j++){\n      dp[i*ps[j]/2]=1;\n      if(i%ps[j]==0) break;\n\
    \    }\n  }\n  return ps;\n}\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: math/enumerate_primes.cpp
  requiredBy: []
  timestamp: '2020-10-07 11:59:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/enumerate_primes.test.cpp
  - test/aoj/1642.test.cpp
documentation_of: math/enumerate_primes.cpp
layout: document
redirect_from:
- /library/math/enumerate_primes.cpp
- /library/math/enumerate_primes.cpp.html
title: math/enumerate_primes.cpp
---
