---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2370.test.cpp
    title: test/aoj/2370.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/bipartitedecomposition.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\n// O(n)\nstruct BipartiteDecomposition{\n\
    \  vector<vector<int>> G;\n  BipartiteDecomposition(int n):G(n){}\n  void add_edge(int\
    \ u,int v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n  }\n  vector<pair<int,\
    \ int>> build(){\n    vector<pair<int, int>> res;\n    vector<int> used(G.size(),-1);\n\
    \    for(int i=0;i<(int)G.size();i++){\n      if(~used[i]) continue;\n      queue<int>\
    \ que;\n      used[i]=0;\n      que.emplace(i);\n      pair<int, int> cnt;\n \
    \     while(!que.empty()){\n        int v=que.front();que.pop();\n        if(used[v]==0)\
    \ cnt.first++;\n        else cnt.second++;\n        for(int u:G[v]){\n       \
    \   if(~used[u]){\n            if(used[u]==used[v]) return {};\n            continue;\n\
    \          }\n          used[u]=used[v]^1;\n          que.emplace(u);\n      \
    \  }\n      }\n      res.emplace_back(cnt);\n    }\n    return res;\n  }\n};\n\
    //END CUT HERE\n#ifndef call_from_test\nint main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\n// O(n)\nstruct BipartiteDecomposition{\n  vector<vector<int>>\
    \ G;\n  BipartiteDecomposition(int n):G(n){}\n  void add_edge(int u,int v){\n\
    \    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n  }\n  vector<pair<int,\
    \ int>> build(){\n    vector<pair<int, int>> res;\n    vector<int> used(G.size(),-1);\n\
    \    for(int i=0;i<(int)G.size();i++){\n      if(~used[i]) continue;\n      queue<int>\
    \ que;\n      used[i]=0;\n      que.emplace(i);\n      pair<int, int> cnt;\n \
    \     while(!que.empty()){\n        int v=que.front();que.pop();\n        if(used[v]==0)\
    \ cnt.first++;\n        else cnt.second++;\n        for(int u:G[v]){\n       \
    \   if(~used[u]){\n            if(used[u]==used[v]) return {};\n            continue;\n\
    \          }\n          used[u]=used[v]^1;\n          que.emplace(u);\n      \
    \  }\n      }\n      res.emplace_back(cnt);\n    }\n    return res;\n  }\n};\n\
    //END CUT HERE\n#ifndef call_from_test\nint main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/bipartitedecomposition.cpp
  requiredBy: []
  timestamp: '2021-07-23 12:56:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2370.test.cpp
documentation_of: graph/bipartitedecomposition.cpp
layout: document
redirect_from:
- /library/graph/bipartitedecomposition.cpp
- /library/graph/bipartitedecomposition.cpp.html
title: graph/bipartitedecomposition.cpp
---
