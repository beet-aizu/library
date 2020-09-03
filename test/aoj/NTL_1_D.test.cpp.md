---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
  bundledCode: "#line 1 \"test/aoj/NTL_1_D.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #line 2 \"math/totient.cpp\"\n\n#ifndef call_from_test\n#line 5 \"math/totient.cpp\"\
    \nusing namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nT totient(T\
    \ n){\n  T res=n;\n  for(T i=2;i*i<=n;i++){\n    if(n%i==0){\n      res=res/i*(i-1);\n\
    \      for(;n%i==0;n/=i);\n    }\n  }\n  if(n!=1) res=res/n*(n-1);\n  return res;\n\
    }\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n\
    #line 8 \"test/aoj/NTL_1_D.test.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  using ll = long long;\n  ll n;\n  cin>>n;\n  cout<<totient(n)<<endl;\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../math/totient.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  using ll = long long;\n  ll n;\n  cin>>n;\n  cout<<totient(n)<<endl;\n  return\
    \ 0;\n}\n"
  dependsOn:
  - math/totient.cpp
  extendedDependsOn:
  - icon: ':warning:'
    path: math/totient.cpp
    title: math/totient.cpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: test/aoj/NTL_1_D.test.cpp
  requiredBy: []
  timestamp: '2020-03-12 17:02:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: test/aoj/NTL_1_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_D.test.cpp
- /verify/test/aoj/NTL_1_D.test.cpp.html
title: test/aoj/NTL_1_D.test.cpp
---
