---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/enumerate_primes.cpp
    title: math/enumerate_primes.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"test/yosupo/enumerate_primes.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/enumerate_primes\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"math/enumerate_primes.cpp\"\
    \n\n#line 3 \"math/enumerate_primes.cpp\"\nusing namespace std;\n#endif\n//BEGIN\
    \ CUT HERE\n// O(n)\nvector<int> enumerate_primes(int n){\n  vector<bool> dp((n+1)/2,false);\n\
    \  vector<int> ps;\n  ps.reserve(n/10);\n  if(2<=n) ps.emplace_back(2);\n  for(int\
    \ i=3;i<=n;i+=2){\n    if(!dp[i/2]) ps.emplace_back(i);\n    for(int j=1;i*ps[j]<=n;j++){\n\
    \      dp[i*ps[j]/2]=1;\n      if(i%ps[j]==0) break;\n    }\n  }\n  return ps;\n\
    }\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n\
    #line 8 \"test/yosupo/enumerate_primes.test.cpp\"\n#undef call_from_test\n\nsigned\
    \ main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,a,b;\n  cin>>n>>a>>b;\n\
    \n  auto ps=enumerate_primes(n);\n  vector<int> qs;\n  for(int i=b;i<(int)ps.size();i+=a)\n\
    \    qs.emplace_back(ps[i]);\n\n  cout<<ps.size()<<' '<<qs.size()<<endl;\n  for(int\
    \ i=0;i<(int)qs.size();i++){\n    if(i) cout<<' ';\n    cout<<qs[i];\n  }\n  cout<<endl;\n\
    \  return 0;\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/enumerate_primes\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../math/enumerate_primes.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,a,b;\n  cin>>n>>a>>b;\n\n\
    \  auto ps=enumerate_primes(n);\n  vector<int> qs;\n  for(int i=b;i<(int)ps.size();i+=a)\n\
    \    qs.emplace_back(ps[i]);\n\n  cout<<ps.size()<<' '<<qs.size()<<endl;\n  for(int\
    \ i=0;i<(int)qs.size();i++){\n    if(i) cout<<' ';\n    cout<<qs[i];\n  }\n  cout<<endl;\n\
    \  return 0;\n}\n"
  dependsOn:
  - math/enumerate_primes.cpp
  isVerificationFile: true
  path: test/yosupo/enumerate_primes.test.cpp
  requiredBy: []
  timestamp: '2020-10-07 11:59:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/enumerate_primes.test.cpp
- /verify/test/yosupo/enumerate_primes.test.cpp.html
title: test/yosupo/enumerate_primes.test.cpp
---
