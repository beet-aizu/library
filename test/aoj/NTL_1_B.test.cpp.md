---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/pow.cpp
    title: mod/pow.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
  bundledCode: "#line 1 \"test/aoj/NTL_1_B.test.cpp\"\n// verification-helper: PROBLEM\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#line 1 \"\
    mod/pow.cpp\"\n\n#line 3 \"mod/pow.cpp\"\nusing namespace std;\n#endif\n//BEGIN\
    \ CUT HERE\n// MOD can be composite numbers\ntemplate<typename T>\nT mod_pow(T\
    \ a,long long n,const T MOD){\n  using ll = long long;\n  T res(1);\n  while(n){\n\
    \    if(n&1) res=(ll)res*a%MOD;\n    a=(ll)a*a%MOD;\n    n>>=1;\n  }\n  return\
    \ res;\n}\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n#line 8 \"test/aoj/NTL_1_B.test.cpp\"\n#undef\
    \ call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,m;\n  cin>>n>>m;\n\n  const int MOD = 1e9+7;\n  cout<<mod_pow(n,m,MOD)<<endl;\n\
    \  return 0;\n}\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../mod/pow.cpp\"\n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n\n  int n,m;\n  cin>>n>>m;\n\n  const int MOD = 1e9+7;\n\
    \  cout<<mod_pow(n,m,MOD)<<endl;\n  return 0;\n}\n"
  dependsOn:
  - mod/pow.cpp
  isVerificationFile: true
  path: test/aoj/NTL_1_B.test.cpp
  requiredBy: []
  timestamp: '2020-11-13 17:57:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_B.test.cpp
- /verify/test/aoj/NTL_1_B.test.cpp.html
title: test/aoj/NTL_1_B.test.cpp
---
