---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_10_C.test.cpp
    title: test/aoj/ALDS1_10_C.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/dp/tasks/dp_f
  bundledCode: "#line 1 \"string/longestcommonsubstring.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\n// O(nm)\nstring longest_common_substring(string\
    \ s,string t){\n  int n=s.size(),m=t.size();\n  s+='$';t+='%';\n  vector< vector<int>\
    \ > dp(n+2,vector<int>(m+2,-(n+m)));\n  dp[0][0]=0;\n\n  auto chmax=[&](int &a,int\
    \ b){if(a<b) a=b;};\n  for(int i=0;i<=n;i++){\n    for(int j=0;j<=m;j++){\n  \
    \    chmax(dp[i+1][j],dp[i][j]);\n      chmax(dp[i][j+1],dp[i][j]);\n      chmax(dp[i+1][j+1],dp[i][j]+(s[i]==t[j]));\n\
    \    }\n  }\n  if(dp[n][m]==0) return \"\"s;\n  string ans;\n  int i=n,j=m;\n\
    \  while(dp[i][j]){\n    if((dp[i][j]==dp[i-1][j-1]+1) and (s[i-1]==t[j-1])){\n\
    \      ans+=s[i-1];\n      i--;j--;\n    }else if(dp[i][j]==dp[i-1][j]) i--;\n\
    \    else j--;\n  }\n  reverse(ans.begin(),ans.end());\n  return ans;\n}\n//END\
    \ CUT HERE\n//INSERT ABOVE HERE\n#ifndef call_from_test\nsigned DP_F(){\n  string\
    \ s,t;\n  cin>>s>>t;\n  cout<<longest_common_substring(s,t)<<endl;\n  return 0;\n\
    }\n/*\n  verified on 2020/12/21\n  https://atcoder.jp/contests/dp/tasks/dp_f\n\
    */\n\nsigned main(){\n  DP_F();\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\n// O(nm)\nstring longest_common_substring(string s,string\
    \ t){\n  int n=s.size(),m=t.size();\n  s+='$';t+='%';\n  vector< vector<int> >\
    \ dp(n+2,vector<int>(m+2,-(n+m)));\n  dp[0][0]=0;\n\n  auto chmax=[&](int &a,int\
    \ b){if(a<b) a=b;};\n  for(int i=0;i<=n;i++){\n    for(int j=0;j<=m;j++){\n  \
    \    chmax(dp[i+1][j],dp[i][j]);\n      chmax(dp[i][j+1],dp[i][j]);\n      chmax(dp[i+1][j+1],dp[i][j]+(s[i]==t[j]));\n\
    \    }\n  }\n  if(dp[n][m]==0) return \"\"s;\n  string ans;\n  int i=n,j=m;\n\
    \  while(dp[i][j]){\n    if((dp[i][j]==dp[i-1][j-1]+1) and (s[i-1]==t[j-1])){\n\
    \      ans+=s[i-1];\n      i--;j--;\n    }else if(dp[i][j]==dp[i-1][j]) i--;\n\
    \    else j--;\n  }\n  reverse(ans.begin(),ans.end());\n  return ans;\n}\n//END\
    \ CUT HERE\n//INSERT ABOVE HERE\n#ifndef call_from_test\nsigned DP_F(){\n  string\
    \ s,t;\n  cin>>s>>t;\n  cout<<longest_common_substring(s,t)<<endl;\n  return 0;\n\
    }\n/*\n  verified on 2020/12/21\n  https://atcoder.jp/contests/dp/tasks/dp_f\n\
    */\n\nsigned main(){\n  DP_F();\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: string/longestcommonsubstring.cpp
  requiredBy: []
  timestamp: '2020-12-21 13:22:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_10_C.test.cpp
documentation_of: string/longestcommonsubstring.cpp
layout: document
redirect_from:
- /library/string/longestcommonsubstring.cpp
- /library/string/longestcommonsubstring.cpp.html
title: string/longestcommonsubstring.cpp
---
