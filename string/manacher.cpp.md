---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 2 \"string/manacher.cpp\"\n\n#ifndef call_from_test\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#endif\n/*\n * @see https://snuke.hatenablog.com/entry/2014/12/02/235837\n\
    \ */\n//BEGIN CUT HERE\nvector<int> manacher(string s){\n  int n=s.size();\n \
    \ vector<int> vs(n);\n  for(int i=0,j=0;i<n;){\n    while(i-j>=0&&i+j<n&&s[i-j]==s[i+j])\
    \ j++;\n    vs[i]=j;\n    int k=1;\n    while(i-k>=0&&i+k<n&&k+vs[i-k]<j) vs[i+k]=vs[i-k],k++;\n\
    \    i+=k;j-=k;\n  }\n  return vs;\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n/*\n * @see https://snuke.hatenablog.com/entry/2014/12/02/235837\n\
    \ */\n//BEGIN CUT HERE\nvector<int> manacher(string s){\n  int n=s.size();\n \
    \ vector<int> vs(n);\n  for(int i=0,j=0;i<n;){\n    while(i-j>=0&&i+j<n&&s[i-j]==s[i+j])\
    \ j++;\n    vs[i]=j;\n    int k=1;\n    while(i-k>=0&&i+k<n&&k+vs[i-k]<j) vs[i+k]=vs[i-k],k++;\n\
    \    i+=k;j-=k;\n  }\n  return vs;\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2934.test.cpp
    title: test/aoj/2934.test.cpp
  extendedVerifiedWith: []
  isVerificationFile: false
  path: string/manacher.cpp
  requiredBy:
  - test/aoj/2934.test.cpp
  timestamp: '2020-03-12 17:15:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: string/manacher.cpp
layout: document
redirect_from:
- /library/string/manacher.cpp
- /library/string/manacher.cpp.html
title: string/manacher.cpp
---
