---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"graph/semikernel.cpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n//BEGIN CUT HERE\n// https://link.springer.com/content/pdf/10.1007%2FBFb0066192.pdf\n\
    struct SemiKernel{\n  int n;\n  vector<vector<int> > G,R;\n  vector<int> used,dp,S;\n\
    \  SemiKernel(int n):n(n),G(n),R(n),used(n,0),dp(n){}\n\n  void add_edge(int u,int\
    \ v){\n    G[u].emplace_back(v);\n    R[v].emplace_back(u);\n  }\n\n  void dfs(int\
    \ v){\n    if(v==n) return;\n    if(used[v]){\n      dfs(v+1);\n      return;\n\
    \    }\n    used[v]=1;\n    for(int u:G[v]) used[u]=1;\n    dfs(v+1);\n    dp[v]=1;\n\
    \    for(int u:R[v]) dp[v]&=!dp[u];\n    if(dp[v]) S.emplace_back(v);\n  }\n\n\
    \  vector<int> build(){\n    dfs(0);\n    reverse(S.begin(),S.end());\n    return\
    \ S;\n  }\n};\n//END CUT HERE\n//INSERT ABOVE HERE\nsigned CFR503_C(){\n  int\
    \ n,m;\n  scanf(\"%d %d\",&n,&m);\n\n  SemiKernel sk(n);\n\n  for(int i=0;i<m;i++){\n\
    \    int a,b;\n    scanf(\"%d %d\",&a,&b);\n    a--;b--;\n    sk.add_edge(a,b);\n\
    \  }\n\n  auto ans=sk.build();\n  printf(\"%d\\n\",(int)ans.size());\n  for(int\
    \ i=0;i<(int)ans.size();i++){\n    if(i) printf(\" \");\n    printf(\"%d\",ans[i]+1);\n\
    \  }\n  puts(\"\");\n  return 0;\n}\n/*\n  verified on 2018/08/12\n  http://codeforces.com/contest/1019/problem/C\n\
    */\n\nsigned main(){\n  CFR503_C();\n  return 0;\n}\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n//BEGIN CUT HERE\n// https://link.springer.com/content/pdf/10.1007%2FBFb0066192.pdf\n\
    struct SemiKernel{\n  int n;\n  vector<vector<int> > G,R;\n  vector<int> used,dp,S;\n\
    \  SemiKernel(int n):n(n),G(n),R(n),used(n,0),dp(n){}\n\n  void add_edge(int u,int\
    \ v){\n    G[u].emplace_back(v);\n    R[v].emplace_back(u);\n  }\n\n  void dfs(int\
    \ v){\n    if(v==n) return;\n    if(used[v]){\n      dfs(v+1);\n      return;\n\
    \    }\n    used[v]=1;\n    for(int u:G[v]) used[u]=1;\n    dfs(v+1);\n    dp[v]=1;\n\
    \    for(int u:R[v]) dp[v]&=!dp[u];\n    if(dp[v]) S.emplace_back(v);\n  }\n\n\
    \  vector<int> build(){\n    dfs(0);\n    reverse(S.begin(),S.end());\n    return\
    \ S;\n  }\n};\n//END CUT HERE\n//INSERT ABOVE HERE\nsigned CFR503_C(){\n  int\
    \ n,m;\n  scanf(\"%d %d\",&n,&m);\n\n  SemiKernel sk(n);\n\n  for(int i=0;i<m;i++){\n\
    \    int a,b;\n    scanf(\"%d %d\",&a,&b);\n    a--;b--;\n    sk.add_edge(a,b);\n\
    \  }\n\n  auto ans=sk.build();\n  printf(\"%d\\n\",(int)ans.size());\n  for(int\
    \ i=0;i<(int)ans.size();i++){\n    if(i) printf(\" \");\n    printf(\"%d\",ans[i]+1);\n\
    \  }\n  puts(\"\");\n  return 0;\n}\n/*\n  verified on 2018/08/12\n  http://codeforces.com/contest/1019/problem/C\n\
    */\n\nsigned main(){\n  CFR503_C();\n  return 0;\n}\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: graph/semikernel.cpp
  requiredBy: []
  timestamp: '2019-12-17 21:51:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: graph/semikernel.cpp
layout: document
redirect_from:
- /library/graph/semikernel.cpp
- /library/graph/semikernel.cpp.html
title: graph/semikernel.cpp
---
