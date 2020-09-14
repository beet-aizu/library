---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
  bundledCode: "#line 1 \"tools/debug.cpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define IGNORE\n\n//BEGIN CUT HERE\nconst int DEBUG = 1;\ntemplate<typename\
    \ ...Ts>\nvoid debug(Ts... ts){\n  if(!DEBUG) return;\n  cout<<\"#:\";\n  auto\
    \ print=[](auto v){cout<<v<<\" \";};\n  initializer_list<int>{(void(print(ts)),0)...};\n\
    \  cout<<endl;\n}\n//END CUT HERE\n//INSERT ABOVE HERE\nsigned main(){\n  int\
    \ a=42;\n  string s=\"UKU\";\n  char c='$';\n  debug(a,100,s,c);\n  return 0;\n\
    }\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n\n#define IGNORE\n\n//BEGIN\
    \ CUT HERE\nconst int DEBUG = 1;\ntemplate<typename ...Ts>\nvoid debug(Ts... ts){\n\
    \  if(!DEBUG) return;\n  cout<<\"#:\";\n  auto print=[](auto v){cout<<v<<\" \"\
    ;};\n  initializer_list<int>{(void(print(ts)),0)...};\n  cout<<endl;\n}\n//END\
    \ CUT HERE\n//INSERT ABOVE HERE\nsigned main(){\n  int a=42;\n  string s=\"UKU\"\
    ;\n  char c='$';\n  debug(a,100,s,c);\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/debug.cpp
  requiredBy: []
  timestamp: '2019-12-10 14:46:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/debug.cpp
layout: document
redirect_from:
- /library/tools/debug.cpp
- /library/tools/debug.cpp.html
title: tools/debug.cpp
---
