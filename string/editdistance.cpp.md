---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 58, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/editdistance.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../tools/chminmax.cpp\"\n#undef call_from_test\n\
    \n#endif\n//BEGIN CUT HERE\nint edit_distance(string s,string t){\n  int n=s.size(),m=t.size();\n\
    \  vector< vector<int> > dp(n+1,vector<int>(m+1,n+m+1));\n  dp[0][0]=0;\n  for(int\
    \ i=0;i<=n;i++){\n    for(int j=0;j<=m;j++){\n      if(i<n) chmin(dp[i+1][j],dp[i][j]+1);\n\
    \      if(j<m) chmin(dp[i][j+1],dp[i][j]+1);\n      if(i<n and j<m)\n        chmin(dp[i+1][j+1],dp[i][j]+(s[i]!=t[j]));\n\
    \    }\n  }\n  return dp[n][m];\n}\n//END CUT HERE\n//INSERT ABOVE HERE\n#ifndef\
    \ call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - tools/chminmax.cpp
  extendedDependsOn:
  - icon: ':warning:'
    path: tools/chminmax.cpp
    title: tools/chminmax.cpp
  extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_1_E.test.cpp
    title: test/aoj/DPL_1_E.test.cpp
  extendedVerifiedWith: []
  isVerificationFile: false
  path: string/editdistance.cpp
  requiredBy:
  - test/aoj/DPL_1_E.test.cpp
  timestamp: '2020-05-29 17:38:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: string/editdistance.cpp
layout: document
redirect_from:
- /library/string/editdistance.cpp
- /library/string/editdistance.cpp.html
title: string/editdistance.cpp
---
