---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2370.test.cpp
    title: test/aoj/2370.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/partialsum.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\n// O(n sqrt(n) / w)\n// w: wordsize\n\
    template<size_t N>\nbitset<N+1> partial_sum(vector<int> vs){\n  int sum=0;\n \
    \ for(int v:vs) sum+=v;\n  assert(sum<=N);\n  vector<int> cnt(sum+1,0);\n  for(int\
    \ v:vs) cnt[v]++;\n  for(int i=1;i*2<=sum;i++){\n    int num=(cnt[i]-1)/2;\n \
    \   cnt[i]-=num*2;\n    cnt[i*2]+=num;\n  }\n  bitset<N+1> dp;\n  dp[0]=1;\n \
    \ for(int i=1;i<=sum;i++)\n    for(int t=0;t<cnt[i];t++)\n      dp|=dp<<i;\n \
    \ return dp;\n}\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\n// O(n sqrt(n) / w)\n// w: wordsize\ntemplate<size_t\
    \ N>\nbitset<N+1> partial_sum(vector<int> vs){\n  int sum=0;\n  for(int v:vs)\
    \ sum+=v;\n  assert(sum<=N);\n  vector<int> cnt(sum+1,0);\n  for(int v:vs) cnt[v]++;\n\
    \  for(int i=1;i*2<=sum;i++){\n    int num=(cnt[i]-1)/2;\n    cnt[i]-=num*2;\n\
    \    cnt[i*2]+=num;\n  }\n  bitset<N+1> dp;\n  dp[0]=1;\n  for(int i=1;i<=sum;i++)\n\
    \    for(int t=0;t<cnt[i];t++)\n      dp|=dp<<i;\n  return dp;\n}\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/partialsum.cpp
  requiredBy: []
  timestamp: '2021-07-23 12:56:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2370.test.cpp
documentation_of: algorithm/partialsum.cpp
layout: document
redirect_from:
- /library/algorithm/partialsum.cpp
- /library/algorithm/partialsum.cpp.html
title: algorithm/partialsum.cpp
---
