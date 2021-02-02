---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0109.test.cpp
    title: test/aoj/0109.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/parse.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\nint expression(string,int&);\nint term(string,int&);\n\
    int factor(string,int&);\nint number(string,int&);\n\nbool f;\n\nint expression(string\
    \ s,int& p){\n  int res=term(s,p);\n  while(p<(int)s.size()){\n    if(s[p]=='+'){\n\
    \      p++;\n      res+=term(s,p);\n      continue;\n    }\n    if(s[p]=='-'){\n\
    \      p++;\n      res-=term(s,p);\n      continue;\n    }\n    break;\n  }\n\
    \  return res;\n}\n\nint term(string s,int& p){\n  int res=factor(s,p);\n  while(p<(int)s.size()){\n\
    \    if(s[p]=='*'){\n      p++;\n      res*=factor(s,p);\n      continue;\n  \
    \  }\n    if(s[p]=='/'){\n      p++;\n      int tmp=factor(s,p);\n      if(tmp==0){\n\
    \        f=1;\n        break;\n      }\n      res/=tmp;\n      continue;\n   \
    \ }\n    break;\n  }\n  return res;\n}\n\nint factor(string s,int& p){\n  int\
    \ res;\n  if(s[p]=='('){\n    p++;\n    res=expression(s,p);\n    p++;\n  }else{\n\
    \    res=number(s,p);\n  }\n  return res;\n}\n\nint number(string s,int& p){\n\
    \  int res=0;\n  while(p<(int)s.size() and isdigit(s[p]))\n    res=res*10+s[p++]-'0';\n\
    \  return res;\n}\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\nint expression(string,int&);\nint term(string,int&);\n\
    int factor(string,int&);\nint number(string,int&);\n\nbool f;\n\nint expression(string\
    \ s,int& p){\n  int res=term(s,p);\n  while(p<(int)s.size()){\n    if(s[p]=='+'){\n\
    \      p++;\n      res+=term(s,p);\n      continue;\n    }\n    if(s[p]=='-'){\n\
    \      p++;\n      res-=term(s,p);\n      continue;\n    }\n    break;\n  }\n\
    \  return res;\n}\n\nint term(string s,int& p){\n  int res=factor(s,p);\n  while(p<(int)s.size()){\n\
    \    if(s[p]=='*'){\n      p++;\n      res*=factor(s,p);\n      continue;\n  \
    \  }\n    if(s[p]=='/'){\n      p++;\n      int tmp=factor(s,p);\n      if(tmp==0){\n\
    \        f=1;\n        break;\n      }\n      res/=tmp;\n      continue;\n   \
    \ }\n    break;\n  }\n  return res;\n}\n\nint factor(string s,int& p){\n  int\
    \ res;\n  if(s[p]=='('){\n    p++;\n    res=expression(s,p);\n    p++;\n  }else{\n\
    \    res=number(s,p);\n  }\n  return res;\n}\n\nint number(string s,int& p){\n\
    \  int res=0;\n  while(p<(int)s.size() and isdigit(s[p]))\n    res=res*10+s[p++]-'0';\n\
    \  return res;\n}\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: string/parse.cpp
  requiredBy: []
  timestamp: '2020-10-27 13:26:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0109.test.cpp
documentation_of: string/parse.cpp
layout: document
redirect_from:
- /library/string/parse.cpp
- /library/string/parse.cpp.html
title: string/parse.cpp
---
