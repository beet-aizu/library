---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2513.test.cpp
    title: test/aoj/2513.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3168.test.cpp
    title: test/aoj/3168.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3198.test.cpp
    title: test/aoj/3198.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_7_A.test.cpp
    title: test/aoj/GRL_7_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"matching/bipartite.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\n// O(N M)\nstruct Bipartite{\n  int\
    \ time;\n  vector< vector<int> > G;\n  vector<int> match,used,dead;\n\n  Bipartite(int\
    \ n):\n    time(0),G(n),match(n,-1),used(n,-1),dead(n,0){}\n\n  void add_edge(int\
    \ u,int v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n  }\n\n  int\
    \ dfs(int v){\n    used[v]=time;\n    for(int u:G[v]){\n      if(dead[u]) continue;\n\
    \      int w=match[u];\n      if((w<0) or (used[w]<time and dfs(w))){\n      \
    \  match[v]=u;\n        match[u]=v;\n        return 1;\n      }\n    }\n    return\
    \ 0;\n  }\n\n  int build(){\n    int res=0;\n    for(int v=0;v<(int)G.size();v++){\n\
    \      if(dead[v] or ~match[v]) continue;\n      time++;\n      res+=dfs(v);\n\
    \    }\n    return res;\n  }\n\n  int disable(int v){\n    assert(!dead[v]);\n\
    \    int u=match[v];\n    if(~u) match[u]=-1;\n    match[v]=-1;\n    dead[v]=1;\n\
    \    time++;\n    return ~u?dfs(u)-1:0;\n  }\n\n  int enable(int v){\n    assert(dead[v]);\n\
    \    dead[v]=0;\n    time++;\n    return dfs(v);\n  }\n\n  int cut_edge(int u,int\
    \ v){\n    assert(find(G[u].begin(),G[u].end(),v)!=G[u].end());\n    assert(find(G[v].begin(),G[v].end(),u)!=G[v].end());\n\
    \    G[u].erase(find(G[u].begin(),G[u].end(),v));\n    G[v].erase(find(G[v].begin(),G[v].end(),u));\n\
    \    if(match[u]==v){\n      match[u]=match[v]=-1;\n      return 1;\n    }\n \
    \   return 0;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\n// O(N M)\nstruct Bipartite{\n  int time;\n  vector<\
    \ vector<int> > G;\n  vector<int> match,used,dead;\n\n  Bipartite(int n):\n  \
    \  time(0),G(n),match(n,-1),used(n,-1),dead(n,0){}\n\n  void add_edge(int u,int\
    \ v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n  }\n\n  int dfs(int\
    \ v){\n    used[v]=time;\n    for(int u:G[v]){\n      if(dead[u]) continue;\n\
    \      int w=match[u];\n      if((w<0) or (used[w]<time and dfs(w))){\n      \
    \  match[v]=u;\n        match[u]=v;\n        return 1;\n      }\n    }\n    return\
    \ 0;\n  }\n\n  int build(){\n    int res=0;\n    for(int v=0;v<(int)G.size();v++){\n\
    \      if(dead[v] or ~match[v]) continue;\n      time++;\n      res+=dfs(v);\n\
    \    }\n    return res;\n  }\n\n  int disable(int v){\n    assert(!dead[v]);\n\
    \    int u=match[v];\n    if(~u) match[u]=-1;\n    match[v]=-1;\n    dead[v]=1;\n\
    \    time++;\n    return ~u?dfs(u)-1:0;\n  }\n\n  int enable(int v){\n    assert(dead[v]);\n\
    \    dead[v]=0;\n    time++;\n    return dfs(v);\n  }\n\n  int cut_edge(int u,int\
    \ v){\n    assert(find(G[u].begin(),G[u].end(),v)!=G[u].end());\n    assert(find(G[v].begin(),G[v].end(),u)!=G[v].end());\n\
    \    G[u].erase(find(G[u].begin(),G[u].end(),v));\n    G[v].erase(find(G[v].begin(),G[v].end(),u));\n\
    \    if(match[u]==v){\n      match[u]=match[v]=-1;\n      return 1;\n    }\n \
    \   return 0;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: matching/bipartite.cpp
  requiredBy: []
  timestamp: '2020-10-27 16:27:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2513.test.cpp
  - test/aoj/3168.test.cpp
  - test/aoj/3198.test.cpp
  - test/aoj/GRL_7_A.test.cpp
documentation_of: matching/bipartite.cpp
layout: document
redirect_from:
- /library/matching/bipartite.cpp
- /library/matching/bipartite.cpp.html
title: matching/bipartite.cpp
---
