---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
  bundledCode: "#line 1 \"test/aoj/NTL_1_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #line 1 \"math/factorize.cpp\"\n\n#line 3 \"math/factorize.cpp\"\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nmap<T, int> factorize(T\
    \ x){\n  map<T, int> res;\n  for(int i=2;i*i<=x;i++){\n    while(x%i==0){\n  \
    \    x/=i;\n      res[i]++;\n    }\n  }\n  if(x!=1) res[x]++;\n  return res;\n\
    }\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n#line 8 \"test/aoj/NTL_1_A.test.cpp\"\n#undef call_from_test\n\
    \nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n;\n  cin>>n;\n\
    \n  auto mp=factorize(n);\n\n  cout<<n<<\":\";\n  for(auto p:mp)\n    for(int\
    \ i=0;i<p.second;i++)\n      cout<<\" \"<<p.first;\n  cout<<endl;\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../math/factorize.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n;\n  cin>>n;\n\n  auto mp=factorize(n);\n\
    \n  cout<<n<<\":\";\n  for(auto p:mp)\n    for(int i=0;i<p.second;i++)\n     \
    \ cout<<\" \"<<p.first;\n  cout<<endl;\n  return 0;\n}\n"
  dependsOn:
  - math/factorize.cpp
  extendedDependsOn:
  - icon: ':warning:'
    path: math/factorize.cpp
    title: math/factorize.cpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: test/aoj/NTL_1_A.test.cpp
  requiredBy: []
  timestamp: '2020-05-06 18:02:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: test/aoj/NTL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_A.test.cpp
- /verify/test/aoj/NTL_1_A.test.cpp.html
title: test/aoj/NTL_1_A.test.cpp
---
