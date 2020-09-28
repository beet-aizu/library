---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2328.test.cpp
    title: test/aoj/2328.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1300.test.cpp
    title: test/aoj/1300.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/split.cpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\nvector<string> split(string& s,char c){\n  int\
    \ n=s.size();\n  vector<string> res;\n  for(int i=0;i<n;i++){\n    if(s[i]==c)\
    \ continue;\n    string t;\n    while(i<n&&s[i]!=c) t.push_back(s[i++]);\n   \
    \ res.push_back(t);\n  }\n  return res;\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nvector<string> split(string& s,char c){\n  int n=s.size();\n\
    \  vector<string> res;\n  for(int i=0;i<n;i++){\n    if(s[i]==c) continue;\n \
    \   string t;\n    while(i<n&&s[i]!=c) t.push_back(s[i++]);\n    res.push_back(t);\n\
    \  }\n  return res;\n}\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: string/split.cpp
  requiredBy: []
  timestamp: '2019-12-26 22:51:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2328.test.cpp
  - test/aoj/1300.test.cpp
documentation_of: string/split.cpp
layout: document
redirect_from:
- /library/string/split.cpp
- /library/string/split.cpp.html
title: string/split.cpp
---
