---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3208.test.cpp
    title: test/aoj/3208.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/topologicalsort.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\nstruct TopologicalSort{\n  vector<vector<int>>\
    \ G;\n  vector<int> indeg;\n  TopologicalSort(int n):G(n),indeg(n,0){}\n\n  void\
    \ add_edge(int s,int t){\n    G[s].emplace_back(t);\n    indeg[t]++;\n  }\n\n\
    \  vector<int> build(){\n    int n=G.size();\n\n    queue<int> que;\n    vector<int>\
    \ used(n,0);\n    auto push=[&](int v){\n      if(used[v]) return;\n      que.emplace(v);\n\
    \      used[v]=1;\n    };\n\n    for(int i=0;i<n;i++)\n      if(indeg[i]==0) push(i);\n\
    \n    vector<int> ps;\n    while(!que.empty()){\n      int v=que.front();que.pop();\n\
    \      ps.emplace_back(v);\n      for(int u:G[v]){\n        indeg[u]--;\n    \
    \    if(indeg[u]==0) push(u);\n      }\n    }\n\n    if(n!=(int)ps.size()) return\
    \ {};\n    return ps;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\nstruct TopologicalSort{\n  vector<vector<int>> G;\n\
    \  vector<int> indeg;\n  TopologicalSort(int n):G(n),indeg(n,0){}\n\n  void add_edge(int\
    \ s,int t){\n    G[s].emplace_back(t);\n    indeg[t]++;\n  }\n\n  vector<int>\
    \ build(){\n    int n=G.size();\n\n    queue<int> que;\n    vector<int> used(n,0);\n\
    \    auto push=[&](int v){\n      if(used[v]) return;\n      que.emplace(v);\n\
    \      used[v]=1;\n    };\n\n    for(int i=0;i<n;i++)\n      if(indeg[i]==0) push(i);\n\
    \n    vector<int> ps;\n    while(!que.empty()){\n      int v=que.front();que.pop();\n\
    \      ps.emplace_back(v);\n      for(int u:G[v]){\n        indeg[u]--;\n    \
    \    if(indeg[u]==0) push(u);\n      }\n    }\n\n    if(n!=(int)ps.size()) return\
    \ {};\n    return ps;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/topologicalsort.cpp
  requiredBy: []
  timestamp: '2020-10-30 12:18:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3208.test.cpp
documentation_of: graph/topologicalsort.cpp
layout: document
redirect_from:
- /library/graph/topologicalsort.cpp
- /library/graph/topologicalsort.cpp.html
title: graph/topologicalsort.cpp
---
