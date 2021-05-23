---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/3354.test.cpp
    title: test/yukicoder/3354.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4117.test.cpp
    title: test/yukicoder/4117.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"io/yesno.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n\n//BEGIN CUT HERE\nstruct BoolPrinter{\n  const string a,b;\n\
    \  BoolPrinter(string a_,string b_):a(a_),b(b_){}\n  string operator[](int k){return\
    \ k?a:b;}\n};\nBoolPrinter yesno(\"yes\",\"no\");\nBoolPrinter YesNo(\"Yes\",\"\
    No\");\nBoolPrinter YESNO(\"YES\",\"NO\");\n//END CUT HERE\n#ifndef call_from_test\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n\n//BEGIN CUT HERE\nstruct BoolPrinter{\n  const string a,b;\n  BoolPrinter(string\
    \ a_,string b_):a(a_),b(b_){}\n  string operator[](int k){return k?a:b;}\n};\n\
    BoolPrinter yesno(\"yes\",\"no\");\nBoolPrinter YesNo(\"Yes\",\"No\");\nBoolPrinter\
    \ YESNO(\"YES\",\"NO\");\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: io/yesno.cpp
  requiredBy: []
  timestamp: '2021-02-20 22:51:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/3354.test.cpp
  - test/yukicoder/4117.test.cpp
documentation_of: io/yesno.cpp
layout: document
redirect_from:
- /library/io/yesno.cpp
- /library/io/yesno.cpp.html
title: io/yesno.cpp
---
