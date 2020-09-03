---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"tree/diameterforvertex.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct DiameterForVertex{\n\
    \  vector<T> vs,dp;\n  vector<vector<int> > G;\n  DiameterForVertex(int n):dp(n),G(n){}\n\
    \  DiameterForVertex(vector<T> vs):vs(vs),dp(vs.size()),G(vs.size()){}\n\n  void\
    \ add_edge(int u,int v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n\
    \  }\n\n  void dfs(int v,int p,int &s){\n    if(p<0) dp[v]=T(0);\n    dp[v]+=vs[v];\n\
    \    if(dp[s]<dp[v]) s=v;\n    for(int u:G[v]){\n      if(u==p) continue;\n  \
    \    dp[u]=dp[v];\n      dfs(u,v,s);\n    }\n  }\n\n  T build(){\n    assert(!vs.empty());\n\
    \    int s=0;\n    dfs(s,-1,s);\n    dfs(s,-1,s);\n    return dp[s];\n  }\n\n\
    \  T build(vector<T> us){\n    assert(us.size()==dp.size());\n    vs=us;\n   \
    \ return build();\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\n// test\
    \ build with argument vector<T>\nsigned ARC097_F(){\n  int n;\n  cin>>n;\n  DiameterForVertex<int>\
    \ G(n);\n  vector<int> deg(n,0);\n  for(int i=1;i<n;i++){\n    int x,y;\n    cin>>x>>y;\n\
    \    x--;y--;\n    G.add_edge(x,y);\n    deg[x]++;\n    deg[y]++;\n  }\n\n  string\
    \ s;\n  cin>>s;\n\n  int cnt=(n-1)*2,num=0;\n  queue<int> que;\n  vector<int>\
    \ dead(n,0);\n  for(int i=0;i<n;i++){\n    num+=(s[i]=='W');\n    if((deg[i]==1)&&(s[i]=='B')){\n\
    \      dead[i]=1;\n      que.emplace(i);\n    }\n  }\n\n  while(!que.empty()){\n\
    \    int v=que.front();que.pop();\n    cnt-=2;\n    for(int u:G.G[v]){\n     \
    \ if(dead[u]) continue;\n      deg[u]--;\n      if(deg[u]==1&&(s[u]=='B')){\n\
    \        dead[u]=1;\n        que.emplace(u);\n      }\n    }\n  }\n\n  if(num<=1){\n\
    \    cout<<num<<endl;\n    return 0;\n  }\n\n  vector<int> vs(n,0);\n  for(int\
    \ i=0;i<n;i++){\n    if(dead[i]) continue;\n    vs[i]=deg[i]+(s[i]=='W');\n  \
    \  vs[i]%=2;\n    cnt+=vs[i];\n  }\n\n  cout<<cnt-G.build(vs)*2<<endl;\n  return\
    \ 0;\n}\n/*\n  verified on 2019/12/27\n  https://atcoder.jp/contests/arc097/tasks/arc097_d\n\
    */\n\nsigned main(){\n  //ARC097_F();\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename T>\nstruct DiameterForVertex{\n  vector<T>\
    \ vs,dp;\n  vector<vector<int> > G;\n  DiameterForVertex(int n):dp(n),G(n){}\n\
    \  DiameterForVertex(vector<T> vs):vs(vs),dp(vs.size()),G(vs.size()){}\n\n  void\
    \ add_edge(int u,int v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n\
    \  }\n\n  void dfs(int v,int p,int &s){\n    if(p<0) dp[v]=T(0);\n    dp[v]+=vs[v];\n\
    \    if(dp[s]<dp[v]) s=v;\n    for(int u:G[v]){\n      if(u==p) continue;\n  \
    \    dp[u]=dp[v];\n      dfs(u,v,s);\n    }\n  }\n\n  T build(){\n    assert(!vs.empty());\n\
    \    int s=0;\n    dfs(s,-1,s);\n    dfs(s,-1,s);\n    return dp[s];\n  }\n\n\
    \  T build(vector<T> us){\n    assert(us.size()==dp.size());\n    vs=us;\n   \
    \ return build();\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\n// test\
    \ build with argument vector<T>\nsigned ARC097_F(){\n  int n;\n  cin>>n;\n  DiameterForVertex<int>\
    \ G(n);\n  vector<int> deg(n,0);\n  for(int i=1;i<n;i++){\n    int x,y;\n    cin>>x>>y;\n\
    \    x--;y--;\n    G.add_edge(x,y);\n    deg[x]++;\n    deg[y]++;\n  }\n\n  string\
    \ s;\n  cin>>s;\n\n  int cnt=(n-1)*2,num=0;\n  queue<int> que;\n  vector<int>\
    \ dead(n,0);\n  for(int i=0;i<n;i++){\n    num+=(s[i]=='W');\n    if((deg[i]==1)&&(s[i]=='B')){\n\
    \      dead[i]=1;\n      que.emplace(i);\n    }\n  }\n\n  while(!que.empty()){\n\
    \    int v=que.front();que.pop();\n    cnt-=2;\n    for(int u:G.G[v]){\n     \
    \ if(dead[u]) continue;\n      deg[u]--;\n      if(deg[u]==1&&(s[u]=='B')){\n\
    \        dead[u]=1;\n        que.emplace(u);\n      }\n    }\n  }\n\n  if(num<=1){\n\
    \    cout<<num<<endl;\n    return 0;\n  }\n\n  vector<int> vs(n,0);\n  for(int\
    \ i=0;i<n;i++){\n    if(dead[i]) continue;\n    vs[i]=deg[i]+(s[i]=='W');\n  \
    \  vs[i]%=2;\n    cnt+=vs[i];\n  }\n\n  cout<<cnt-G.build(vs)*2<<endl;\n  return\
    \ 0;\n}\n/*\n  verified on 2019/12/27\n  https://atcoder.jp/contests/arc097/tasks/arc097_d\n\
    */\n\nsigned main(){\n  //ARC097_F();\n  return 0;\n}\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0415.test.cpp
    title: test/aoj/0415.test.cpp
  isVerificationFile: false
  path: tree/diameterforvertex.cpp
  requiredBy: []
  timestamp: '2019-12-27 09:03:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - test/aoj/0415.test.cpp
documentation_of: tree/diameterforvertex.cpp
layout: document
redirect_from:
- /library/tree/diameterforvertex.cpp
- /library/tree/diameterforvertex.cpp.html
title: tree/diameterforvertex.cpp
---
