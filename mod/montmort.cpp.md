---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"mod/montmort.cpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\n// number of permutations with p_i != i\ntemplate<typename\
    \ T>\nstruct Montmort{\n  using ll = long long;\n  vector<T> dp;\n\n  Montmort(int\
    \ n,int mod):dp(n+1,0){\n    for(int k=2;k<=n;k++){\n      dp[k]=(ll)dp[k-1]*k%mod;\n\
    \      if(~k&1) dp[k]+=1;\n      else dp[k]+=mod-1;\n      if(dp[k]>=mod) dp[k]-=mod;\n\
    \    }\n  }\n\n  T operator[](int n){return dp[n];}\n};\n//END CUT HERE\n#ifndef\
    \ call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\n// number of permutations with p_i != i\ntemplate<typename T>\n\
    struct Montmort{\n  using ll = long long;\n  vector<T> dp;\n\n  Montmort(int n,int\
    \ mod):dp(n+1,0){\n    for(int k=2;k<=n;k++){\n      dp[k]=(ll)dp[k-1]*k%mod;\n\
    \      if(~k&1) dp[k]+=1;\n      else dp[k]+=mod-1;\n      if(dp[k]>=mod) dp[k]-=mod;\n\
    \    }\n  }\n\n  T operator[](int n){return dp[n];}\n};\n//END CUT HERE\n#ifndef\
    \ call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/montmort_number_mod.test.cpp
    title: test/yosupo/montmort_number_mod.test.cpp
  extendedVerifiedWith: []
  isVerificationFile: false
  path: mod/montmort.cpp
  requiredBy:
  - test/yosupo/montmort_number_mod.test.cpp
  timestamp: '2019-12-26 23:22:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: mod/montmort.cpp
layout: document
redirect_from:
- /library/mod/montmort.cpp
- /library/mod/montmort.cpp.html
title: mod/montmort.cpp
---
