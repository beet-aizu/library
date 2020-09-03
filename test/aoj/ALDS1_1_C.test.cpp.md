---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
  bundledCode: "#line 1 \"test/aoj/ALDS1_1_C.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #line 1 \"math/isprime.cpp\"\n\n#line 3 \"math/isprime.cpp\"\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nint isprime(T x){\n  if(x<=1)\
    \ return 0;\n  for(T i=2;i*i<=x;i++)\n    if(x%i==0) return 0;\n  return 1;\n\
    }\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n\
    #line 8 \"test/aoj/ALDS1_1_C.test.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  int n;\n  cin>>n;\n  int ans=0;\n  for(int i=0;i<n;i++){\n    int x;\n    cin>>x;\n\
    \    ans+=isprime(x);\n  }\n  cout<<ans<<endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../math/isprime.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  int n;\n  cin>>n;\n  int ans=0;\n  for(int i=0;i<n;i++){\n    int x;\n    cin>>x;\n\
    \    ans+=isprime(x);\n  }\n  cout<<ans<<endl;\n  return 0;\n}\n"
  dependsOn:
  - math/isprime.cpp
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/isprime.cpp
    title: math/isprime.cpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: test/aoj/ALDS1_1_C.test.cpp
  requiredBy: []
  timestamp: '2020-02-11 11:14:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: test/aoj/ALDS1_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_1_C.test.cpp
- /verify/test/aoj/ALDS1_1_C.test.cpp.html
title: test/aoj/ALDS1_1_C.test.cpp
---
