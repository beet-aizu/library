---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
  bundledCode: "#line 1 \"test/aoj/NTL_1_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #line 1 \"mod/pow.cpp\"\n\n#line 3 \"mod/pow.cpp\"\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename T>\nT mod_pow(T a,long long n,T mod){\n  using\
    \ ll = long long;\n  T res(1);\n  while(n){\n    if(n&1) res=(ll)res*a%mod;\n\
    \    a=(ll)a*a%mod;\n    n>>=1;\n  }\n  return res;\n}\n//END CUT HERE\n#ifndef\
    \ call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n\
    #line 8 \"test/aoj/NTL_1_B.test.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,m;\n  cin>>n>>m;\n\n  const\
    \ int MOD = 1e9+7;\n  cout<<mod_pow(n,m,MOD)<<endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../mod/pow.cpp\"\n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n\n  int n,m;\n  cin>>n>>m;\n\n  const int MOD = 1e9+7;\n\
    \  cout<<mod_pow(n,m,MOD)<<endl;\n  return 0;\n}\n"
  dependsOn:
  - mod/pow.cpp
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/pow.cpp
    title: mod/pow.cpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: test/aoj/NTL_1_B.test.cpp
  requiredBy: []
  timestamp: '2020-05-06 18:02:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: test/aoj/NTL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_B.test.cpp
- /verify/test/aoj/NTL_1_B.test.cpp.html
title: test/aoj/NTL_1_B.test.cpp
---
