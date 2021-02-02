---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/fastio.cpp
    title: tools/fastio.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/many_aplusb
    links:
    - https://judge.yosupo.jp/problem/many_aplusb
  bundledCode: "#line 1 \"test/yosupo/many_aplusb.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/many_aplusb\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"tools/fastio.cpp\"\n\
    \n#line 3 \"tools/fastio.cpp\"\nusing namespace std;\n#endif\n//BEGIN CUT HERE\n\
    struct FastIO{\n  FastIO(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n \
    \ }\n}fastio_beet;\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n \
    \ return 0;\n}\n#endif\n#line 8 \"test/yosupo/many_aplusb.test.cpp\"\n#undef call_from_test\n\
    \nsigned main(){\n  const char newl = '\\n';\n  int t;\n  cin>>t;\n  for(int i=0;i<t;i++){\n\
    \    long long a,b;\n    cin>>a>>b;\n    cout<<a+b<<newl;\n  }\n  return 0;\n\
    }\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/many_aplusb\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../tools/fastio.cpp\"\n#undef call_from_test\n\nsigned main(){\n  const\
    \ char newl = '\\n';\n  int t;\n  cin>>t;\n  for(int i=0;i<t;i++){\n    long long\
    \ a,b;\n    cin>>a>>b;\n    cout<<a+b<<newl;\n  }\n  return 0;\n}\n"
  dependsOn:
  - tools/fastio.cpp
  isVerificationFile: true
  path: test/yosupo/many_aplusb.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 12:29:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/many_aplusb.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/many_aplusb.test.cpp
- /verify/test/yosupo/many_aplusb.test.cpp.html
title: test/yosupo/many_aplusb.test.cpp
---
