---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1205/problem/B
  bundledCode: "#line 1 \"graph/girth.cpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n//BEGIN CUT HERE\n// size of minimum cycle\nint girth(vector< vector<int>\
    \ > G){\n  int n=G.size();\n  int res=n+1;\n  vector<int> dp(n),pr(n);\n  for(int\
    \ s=0;s<n;s++){\n    fill(dp.begin(),dp.end(),-1);\n    fill(pr.begin(),pr.end(),-1);\n\
    \    queue<int> que;\n    dp[s]=0;\n    que.emplace(s);\n    while(!que.empty()){\n\
    \      int v=que.front();que.pop();\n      if(res<=dp[v]*2) break;\n      for(int\
    \ u:G[v]){\n        if(u==pr[v]) continue;\n        if(~dp[u]){\n          res=min(res,dp[u]+dp[v]+1);\n\
    \          continue;\n        }\n        dp[u]=dp[v]+1;\n        pr[u]=v;\n  \
    \      que.emplace(u);\n      }\n    }\n  }\n  if(res>n) res=-1;\n  return res;\n\
    }\n//END CUT HERE\n//INSERT ABOVE HERE\n\nsigned CFR580_B(){\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n  using ll = long long;\n\n  int n;\n  cin>>n;\n\
    \  vector<ll> as(n);\n  for(int i=0;i<n;i++) cin>>as[i];\n  sort(as.rbegin(),as.rend());\n\
    \n  if(as[0]==0){\n    cout<<-1<<endl;\n    return 0;\n  }\n\n  while(as.back()==0)\
    \ as.pop_back();\n  n=as.size();\n\n  if(n>=200){\n    cout<<3<<endl;\n    return\
    \ 0;\n  }\n\n  vector< vector<int> > G(n);\n  for(int i=0;i<n;i++)\n    for(int\
    \ j=0;j<n;j++)\n      if((i!=j)&&(as[i]&as[j]))\n        G[i].emplace_back(j);\n\
    \n  cout<<girth(G)<<endl;\n  return 0;\n}\n/*\n  verified on 2019/08/21\n  https://codeforces.com/contest/1205/problem/B\n\
    */\n\nsigned main(){\n  CFR580_B();\n  return 0;\n}\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n//BEGIN CUT HERE\n// size\
    \ of minimum cycle\nint girth(vector< vector<int> > G){\n  int n=G.size();\n \
    \ int res=n+1;\n  vector<int> dp(n),pr(n);\n  for(int s=0;s<n;s++){\n    fill(dp.begin(),dp.end(),-1);\n\
    \    fill(pr.begin(),pr.end(),-1);\n    queue<int> que;\n    dp[s]=0;\n    que.emplace(s);\n\
    \    while(!que.empty()){\n      int v=que.front();que.pop();\n      if(res<=dp[v]*2)\
    \ break;\n      for(int u:G[v]){\n        if(u==pr[v]) continue;\n        if(~dp[u]){\n\
    \          res=min(res,dp[u]+dp[v]+1);\n          continue;\n        }\n     \
    \   dp[u]=dp[v]+1;\n        pr[u]=v;\n        que.emplace(u);\n      }\n    }\n\
    \  }\n  if(res>n) res=-1;\n  return res;\n}\n//END CUT HERE\n//INSERT ABOVE HERE\n\
    \nsigned CFR580_B(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  using ll =\
    \ long long;\n\n  int n;\n  cin>>n;\n  vector<ll> as(n);\n  for(int i=0;i<n;i++)\
    \ cin>>as[i];\n  sort(as.rbegin(),as.rend());\n\n  if(as[0]==0){\n    cout<<-1<<endl;\n\
    \    return 0;\n  }\n\n  while(as.back()==0) as.pop_back();\n  n=as.size();\n\n\
    \  if(n>=200){\n    cout<<3<<endl;\n    return 0;\n  }\n\n  vector< vector<int>\
    \ > G(n);\n  for(int i=0;i<n;i++)\n    for(int j=0;j<n;j++)\n      if((i!=j)&&(as[i]&as[j]))\n\
    \        G[i].emplace_back(j);\n\n  cout<<girth(G)<<endl;\n  return 0;\n}\n/*\n\
    \  verified on 2019/08/21\n  https://codeforces.com/contest/1205/problem/B\n*/\n\
    \nsigned main(){\n  CFR580_B();\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/girth.cpp
  requiredBy: []
  timestamp: '2019-12-17 21:51:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/girth.cpp
layout: document
redirect_from:
- /library/graph/girth.cpp
- /library/graph/girth.cpp.html
title: graph/girth.cpp
---
