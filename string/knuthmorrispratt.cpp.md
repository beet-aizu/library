---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 2 \"string/knuthmorrispratt.cpp\"\n\n#ifndef call_from_test\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#endif\n/*\n * @see https://snuke.hatenablog.com/entry/2017/07/18/101026\n\
    \ */\n//BEGIN CUT HERE\nvector<int> knuth_morris_pratt(const string &s){\n  int\
    \ n=s.size();\n  vector<int> kmp(n+1,-1);\n  for(int i=0,j=-1;i<n;i++){\n    while(~j&&s[i]!=s[j])\
    \ j=kmp[j];\n    kmp[i+1]=++j;\n    if(i+1<n&&s[i+1]==s[j]) kmp[i+1]=kmp[j];\n\
    \  }\n  return kmp;\n}\n// positions for t that match s\nvector<int> pattern_match(string\
    \ s,string t){\n  int n=s.size(),m=t.size();\n  vector<int> kmp=knuth_morris_pratt(s);\n\
    \n  vector<int> res;\n  int i=0,j=0;\n  while(i+j<m){\n    if(s[j]==t[i+j]){\n\
    \      if(++j!=n) continue;\n      res.emplace_back(i);\n    }\n    i+=j-kmp[j];\n\
    \    j=max(kmp[j],0);\n  }\n  return res;\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    \ntemplate<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}\n\
    template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}\n\
    \n//INSERT ABOVE HERE\n\n// test knuth_morris_pratt\nsigned ABC135_F(){\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n  string s,t;\n  cin>>s>>t;\n\n  int n=s.size(),m=t.size();\n\
    \n  string b;\n  while(b.size()<t.size()) b+=s;\n  auto kmp=knuth_morris_pratt(t+'$'+b+b);\n\
    \n  vector<int> match(n);\n  for(int i=m+1;i<=m+n;i++)\n    match[i-(m+1)]=kmp[i+m]==m;\n\
    \n  vector< vector<int> > G(n);\n  for(int i=0;i<n;i++)\n    if(match[i]) G[i].emplace_back((i+m)%n);\n\
    \n  vector<int> indeg(n,0);\n  for(int i=0;i<n;i++)\n    for(int j:G[i]) indeg[j]++;\n\
    \n  queue<int> que;\n  for(int i=0;i<n;i++)\n    if(indeg[i]==0) que.emplace(i);\n\
    \n  vector<int> dp(n,0);\n  while(!que.empty()){\n    int v=que.front();que.pop();\n\
    \    for(int u:G[v]){\n      chmax(dp[u],dp[v]+1);\n      indeg[u]--;\n      if(indeg[u]==0)\
    \ que.emplace(u);\n    }\n  }\n\n  for(int i=0;i<n;i++){\n    if(indeg[i]!=0){\n\
    \      cout<<-1<<endl;\n      return 0;\n    }\n  }\n\n  cout<<*max_element(dp.begin(),dp.end())<<endl;\n\
    \  return 0;\n}\n/*\n  verified on 2020/08/20\n  https://atcoder.jp/contests/abc135/tasks/abc135_f\n\
    */\n\nsigned main(){\n  ABC135_F();\n  return 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n/*\n * @see https://snuke.hatenablog.com/entry/2017/07/18/101026\n\
    \ */\n//BEGIN CUT HERE\nvector<int> knuth_morris_pratt(const string &s){\n  int\
    \ n=s.size();\n  vector<int> kmp(n+1,-1);\n  for(int i=0,j=-1;i<n;i++){\n    while(~j&&s[i]!=s[j])\
    \ j=kmp[j];\n    kmp[i+1]=++j;\n    if(i+1<n&&s[i+1]==s[j]) kmp[i+1]=kmp[j];\n\
    \  }\n  return kmp;\n}\n// positions for t that match s\nvector<int> pattern_match(string\
    \ s,string t){\n  int n=s.size(),m=t.size();\n  vector<int> kmp=knuth_morris_pratt(s);\n\
    \n  vector<int> res;\n  int i=0,j=0;\n  while(i+j<m){\n    if(s[j]==t[i+j]){\n\
    \      if(++j!=n) continue;\n      res.emplace_back(i);\n    }\n    i+=j-kmp[j];\n\
    \    j=max(kmp[j],0);\n  }\n  return res;\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    \ntemplate<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}\n\
    template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}\n\
    \n//INSERT ABOVE HERE\n\n// test knuth_morris_pratt\nsigned ABC135_F(){\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n  string s,t;\n  cin>>s>>t;\n\n  int n=s.size(),m=t.size();\n\
    \n  string b;\n  while(b.size()<t.size()) b+=s;\n  auto kmp=knuth_morris_pratt(t+'$'+b+b);\n\
    \n  vector<int> match(n);\n  for(int i=m+1;i<=m+n;i++)\n    match[i-(m+1)]=kmp[i+m]==m;\n\
    \n  vector< vector<int> > G(n);\n  for(int i=0;i<n;i++)\n    if(match[i]) G[i].emplace_back((i+m)%n);\n\
    \n  vector<int> indeg(n,0);\n  for(int i=0;i<n;i++)\n    for(int j:G[i]) indeg[j]++;\n\
    \n  queue<int> que;\n  for(int i=0;i<n;i++)\n    if(indeg[i]==0) que.emplace(i);\n\
    \n  vector<int> dp(n,0);\n  while(!que.empty()){\n    int v=que.front();que.pop();\n\
    \    for(int u:G[v]){\n      chmax(dp[u],dp[v]+1);\n      indeg[u]--;\n      if(indeg[u]==0)\
    \ que.emplace(u);\n    }\n  }\n\n  for(int i=0;i<n;i++){\n    if(indeg[i]!=0){\n\
    \      cout<<-1<<endl;\n      return 0;\n    }\n  }\n\n  cout<<*max_element(dp.begin(),dp.end())<<endl;\n\
    \  return 0;\n}\n/*\n  verified on 2020/08/20\n  https://atcoder.jp/contests/abc135/tasks/abc135_f\n\
    */\n\nsigned main(){\n  ABC135_F();\n  return 0;\n}\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.knuthmorrispratt.test.cpp
    title: test/aoj/ALDS1_14_B.knuthmorrispratt.test.cpp
  isVerificationFile: false
  path: string/knuthmorrispratt.cpp
  requiredBy: []
  timestamp: '2020-08-20 15:23:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - test/aoj/ALDS1_14_B.knuthmorrispratt.test.cpp
documentation_of: string/knuthmorrispratt.cpp
layout: document
redirect_from:
- /library/string/knuthmorrispratt.cpp
- /library/string/knuthmorrispratt.cpp.html
title: string/knuthmorrispratt.cpp
---
