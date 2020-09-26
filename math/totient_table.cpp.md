---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2286.test.cpp
    title: test/aoj/2286.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1665.test.cpp
    title: test/yukicoder/1665.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/totient_table.cpp\"\n\n#ifndef call_from_test\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#endif\n//BEGIN CUT HERE\nvector<int>\
    \ totient_table(int n){\n  vector<int> ts(n+1);\n  iota(ts.begin(),ts.end(),0);\n\
    \  for(int i=2;i<=n;i++){\n    if(ts[i]!=i) continue;\n    for(int j=i;j<=n;j+=i)\
    \ ts[j]=ts[j]/i*(i-1);\n  }\n  return ts;\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\nvector<int> totient_table(int n){\n  vector<int>\
    \ ts(n+1);\n  iota(ts.begin(),ts.end(),0);\n  for(int i=2;i<=n;i++){\n    if(ts[i]!=i)\
    \ continue;\n    for(int j=i;j<=n;j+=i) ts[j]=ts[j]/i*(i-1);\n  }\n  return ts;\n\
    }\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: math/totient_table.cpp
  requiredBy: []
  timestamp: '2020-03-12 17:02:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2286.test.cpp
  - test/yukicoder/1665.test.cpp
documentation_of: math/totient_table.cpp
layout: document
redirect_from:
- /library/math/totient_table.cpp
- /library/math/totient_table.cpp.html
title: math/totient_table.cpp
---
