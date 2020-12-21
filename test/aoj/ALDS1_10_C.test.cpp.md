---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/longestcommonsubstring.cpp
    title: string/longestcommonsubstring.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C
  bundledCode: "#line 1 \"test/aoj/ALDS1_10_C.test.cpp\"\n// verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#line\
    \ 1 \"string/longestcommonsubstring.cpp\"\n\n#line 3 \"string/longestcommonsubstring.cpp\"\
    \nusing namespace std;\n#endif\n//BEGIN CUT HERE\nstring longest_common_substring(string\
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
    */\n\nsigned main(){\n  DP_F();\n  return 0;\n}\n#endif\n#line 8 \"test/aoj/ALDS1_10_C.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int q;\n  cin>>q;\n  while(q--){\n    string s,t;\n    cin>>s>>t;\n    cout<<longest_common_substring(s,t).size()<<'\\\
    n';\n  }\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../string/longestcommonsubstring.cpp\"\n#undef call_from_test\n\nsigned\
    \ main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int q;\n  cin>>q;\n\
    \  while(q--){\n    string s,t;\n    cin>>s>>t;\n    cout<<longest_common_substring(s,t).size()<<'\\\
    n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - string/longestcommonsubstring.cpp
  isVerificationFile: true
  path: test/aoj/ALDS1_10_C.test.cpp
  requiredBy: []
  timestamp: '2020-12-21 13:19:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_10_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_10_C.test.cpp
- /verify/test/aoj/ALDS1_10_C.test.cpp.html
title: test/aoj/ALDS1_10_C.test.cpp
---
