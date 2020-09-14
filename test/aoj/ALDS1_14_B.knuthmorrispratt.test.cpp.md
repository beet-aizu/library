---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/knuthmorrispratt.cpp
    title: string/knuthmorrispratt.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"test/aoj/ALDS1_14_B.knuthmorrispratt.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #line 2 \"string/knuthmorrispratt.cpp\"\n\n#ifndef call_from_test\n#line 5 \"\
    string/knuthmorrispratt.cpp\"\nusing namespace std;\n#endif\n/*\n * @see https://snuke.hatenablog.com/entry/2017/07/18/101026\n\
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
    */\n\nsigned main(){\n  ABC135_F();\n  return 0;\n}\n#endif\n#line 8 \"test/aoj/ALDS1_14_B.knuthmorrispratt.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  string t,p;\n  cin>>t>>p;\n\n  vector<int> res=pattern_match(p,t);\n  for(int\
    \ x:res) cout<<x<<\"\\n\";\n  cout<<flush;\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../string/knuthmorrispratt.cpp\"\n#undef call_from_test\n\nsigned\
    \ main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  string t,p;\n  cin>>t>>p;\n\
    \n  vector<int> res=pattern_match(p,t);\n  for(int x:res) cout<<x<<\"\\n\";\n\
    \  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - string/knuthmorrispratt.cpp
  isVerificationFile: true
  path: test/aoj/ALDS1_14_B.knuthmorrispratt.test.cpp
  requiredBy: []
  timestamp: '2020-08-20 15:23:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_B.knuthmorrispratt.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_B.knuthmorrispratt.test.cpp
- /verify/test/aoj/ALDS1_14_B.knuthmorrispratt.test.cpp.html
title: test/aoj/ALDS1_14_B.knuthmorrispratt.test.cpp
---
