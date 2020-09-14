---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0596.test.cpp
    title: test/aoj/0596.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"graph/bfs.cpp\"\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\nvector<int> bfs(int s,vector<\
    \ vector<int> > G){\n  int n=G.size();\n  vector<int> dp(n,-1);\n  queue<int>\
    \ que;\n  dp[s]=0;\n  que.emplace(s);\n  while(!que.empty()){\n    int v=que.front();que.pop();\n\
    \    for(int u:G[v]){\n      if(~dp[u]) continue;\n      dp[u]=dp[v]+1;\n    \
    \  que.emplace(u);\n    }\n  }\n  return dp;\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\nvector<int> bfs(int s,vector< vector<int> >\
    \ G){\n  int n=G.size();\n  vector<int> dp(n,-1);\n  queue<int> que;\n  dp[s]=0;\n\
    \  que.emplace(s);\n  while(!que.empty()){\n    int v=que.front();que.pop();\n\
    \    for(int u:G[v]){\n      if(~dp[u]) continue;\n      dp[u]=dp[v]+1;\n    \
    \  que.emplace(u);\n    }\n  }\n  return dp;\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/bfs.cpp
  requiredBy: []
  timestamp: '2020-05-07 17:24:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0596.test.cpp
documentation_of: graph/bfs.cpp
layout: document
redirect_from:
- /library/graph/bfs.cpp
- /library/graph/bfs.cpp.html
title: graph/bfs.cpp
---
