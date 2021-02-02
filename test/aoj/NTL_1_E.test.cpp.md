---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/extgcd.cpp
    title: math/extgcd.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
  bundledCode: "#line 1 \"test/aoj/NTL_1_E.test.cpp\"\n// verification-helper: PROBLEM\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"math/extgcd.cpp\"\n\n\
    #line 3 \"math/extgcd.cpp\"\nusing namespace std;\n#endif\n//BEGIN CUT HERE\n\
    // find (x, y) s.t. ax + by = gcd(a, b)\n// |x| <= b, |y| <= a\n// return gcd(a,\
    \ b)\ntemplate<typename T>\nT extgcd(T a,T b,T& x,T& y){\n  T d=a;\n  if(b!=0){\n\
    \    d=extgcd(b,a%b,y,x);\n    y-=(a/b)*x;\n  }else{\n    x=1;y=0;\n  }\n  return\
    \ d;\n}\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n#line 8 \"test/aoj/NTL_1_E.test.cpp\"\n#undef call_from_test\n\
    \nsigned main(){\n  int a,b;\n  cin>>a>>b;\n  int x,y;\n  extgcd(a,b,x,y);\n \
    \ cout<<x<<\" \"<<y<<endl;\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../math/extgcd.cpp\"\n#undef call_from_test\n\nsigned main(){\n  int a,b;\n\
    \  cin>>a>>b;\n  int x,y;\n  extgcd(a,b,x,y);\n  cout<<x<<\" \"<<y<<endl;\n  return\
    \ 0;\n}\n"
  dependsOn:
  - math/extgcd.cpp
  isVerificationFile: true
  path: test/aoj/NTL_1_E.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 16:41:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_E.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_E.test.cpp
- /verify/test/aoj/NTL_1_E.test.cpp.html
title: test/aoj/NTL_1_E.test.cpp
---
