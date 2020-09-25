---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/montmort.cpp
    title: mod/montmort.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/montmort_number_mod
    links:
    - https://judge.yosupo.jp/problem/montmort_number_mod
  bundledCode: "#line 1 \"test/yosupo/montmort_number_mod.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/montmort_number_mod\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"mod/montmort.cpp\"\n\
    \n#line 3 \"mod/montmort.cpp\"\nusing namespace std;\n#endif\n//BEGIN CUT HERE\n\
    // number of permutations with p_i != i\ntemplate<typename T>\nstruct Montmort{\n\
    \  using ll = long long;\n  vector<T> dp;\n\n  Montmort(int n,int mod):dp(n+1,0){\n\
    \    for(int k=2;k<=n;k++){\n      dp[k]=(ll)dp[k-1]*k%mod;\n      if(~k&1) dp[k]+=1;\n\
    \      else dp[k]+=mod-1;\n      if(dp[k]>=mod) dp[k]-=mod;\n    }\n  }\n\n  T\
    \ operator[](int n){return dp[n];}\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    signed main(){\n  return 0;\n}\n#endif\n#line 8 \"test/yosupo/montmort_number_mod.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,m;\n  cin>>n>>m;\n  Montmort<int> mm(n,m);\n  for(int i=1;i<=n;i++){\n\
    \    if(i) cout<<\" \";\n    cout<<mm[i];\n  }\n  cout<<endl;\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/montmort_number_mod\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../mod/montmort.cpp\"\n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n\n  int n,m;\n  cin>>n>>m;\n  Montmort<int> mm(n,m);\n\
    \  for(int i=1;i<=n;i++){\n    if(i) cout<<\" \";\n    cout<<mm[i];\n  }\n  cout<<endl;\n\
    \  return 0;\n}\n"
  dependsOn:
  - mod/montmort.cpp
  isVerificationFile: true
  path: test/yosupo/montmort_number_mod.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 15:47:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/montmort_number_mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/montmort_number_mod.test.cpp
- /verify/test/yosupo/montmort_number_mod.test.cpp.html
title: test/yosupo/montmort_number_mod.test.cpp
---
