---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0222.test.cpp
    title: test/yukicoder/0222.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/iskado.cpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nbool is_kado(T a,T b,T\
    \ c){\n  if(a==b or b==c or c==a) return 0;\n  if(a<b and b>c) return 1;\n  if(a>b\
    \ and b<c) return 1;\n  return 0;\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename T>\nbool is_kado(T a,T b,T c){\n  if(a==b\
    \ or b==c or c==a) return 0;\n  if(a<b and b>c) return 1;\n  if(a>b and b<c) return\
    \ 1;\n  return 0;\n}\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/iskado.cpp
  requiredBy: []
  timestamp: '2020-09-30 16:50:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/0222.test.cpp
documentation_of: tools/iskado.cpp
layout: document
redirect_from:
- /library/tools/iskado.cpp
- /library/tools/iskado.cpp.html
title: tools/iskado.cpp
---
