---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"graph/topologicalsort.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\nstruct TopologicalSort{\n  vector<\
    \ set<int> > G;\n  vector<int> used,indeg,ps;\n\n  TopologicalSort(){}\n  TopologicalSort(int\
    \ n):G(n),used(n,0),indeg(n,0){}\n\n  void add_edge(int s,int t){\n    G[s].emplace(t);\n\
    \    indeg[t]++;\n  }\n\n  void bfs(int s){\n    queue<int> que;\n    que.emplace(s);\n\
    \    used[s]=1;\n    while(!que.empty()){\n      int v=que.front();que.pop();\n\
    \      ps.emplace_back(v);\n      for(int u:G[v]){\n        indeg[u]--;\n    \
    \    if(indeg[u]==0&&!used[u]){\n          used[u]=1;\n          que.emplace(u);\n\
    \        }\n      }\n    }\n  }\n\n  vector<int> build(){\n    int n=G.size();\n\
    \    for(int i=0;i<n;i++)\n      if(indeg[i]==0&&!used[i]) bfs(i);\n    return\
    \ ps;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nstruct TopologicalSort{\n  vector< set<int> > G;\n  vector<int>\
    \ used,indeg,ps;\n\n  TopologicalSort(){}\n  TopologicalSort(int n):G(n),used(n,0),indeg(n,0){}\n\
    \n  void add_edge(int s,int t){\n    G[s].emplace(t);\n    indeg[t]++;\n  }\n\n\
    \  void bfs(int s){\n    queue<int> que;\n    que.emplace(s);\n    used[s]=1;\n\
    \    while(!que.empty()){\n      int v=que.front();que.pop();\n      ps.emplace_back(v);\n\
    \      for(int u:G[v]){\n        indeg[u]--;\n        if(indeg[u]==0&&!used[u]){\n\
    \          used[u]=1;\n          que.emplace(u);\n        }\n      }\n    }\n\
    \  }\n\n  vector<int> build(){\n    int n=G.size();\n    for(int i=0;i<n;i++)\n\
    \      if(indeg[i]==0&&!used[i]) bfs(i);\n    return ps;\n  }\n};\n//END CUT HERE\n\
    #ifndef call_from_test\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_4_B.test.cpp
    title: test/aoj/GRL_4_B.test.cpp
  isVerificationFile: false
  path: graph/topologicalsort.cpp
  requiredBy: []
  timestamp: '2019-12-17 21:51:08+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verificationStatusIcon: ':x:'
  verifiedWith:
  - test/aoj/GRL_4_B.test.cpp
documentation_of: graph/topologicalsort.cpp
layout: document
redirect_from:
- /library/graph/topologicalsort.cpp
- /library/graph/topologicalsort.cpp.html
title: graph/topologicalsort.cpp
---
