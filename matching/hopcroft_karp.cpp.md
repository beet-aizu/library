---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0424.test.cpp
    title: test/aoj/0424.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bipartitematching.test.cpp
    title: test/yosupo/bipartitematching.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"matching/hopcroft_karp.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\n// O(E \\sqrt V)\nstruct HopcroftKarp{\n\
    \  int L,R;\n  vector< vector<int> > G;\n  vector<int> match,level;\n\n  HopcroftKarp(int\
    \ L,int R):\n    L(L),R(R),G(L+R),match(L+R,-1),level(L+R){}\n\n  void add_edge(int\
    \ u,int v){\n    G[u].emplace_back(v+L);\n    G[v+L].emplace_back(u);\n  }\n\n\
    \  bool bfs(){\n    fill(level.begin(),level.end(),-1);\n    queue<int> que;\n\
    \    for(int i=0;i<L;i++){\n      if(~match[i]) continue;\n      level[i]=0;\n\
    \      que.emplace(i);\n    }\n    bool found=false;\n    while(!que.empty()){\n\
    \      int v=que.front();que.pop();\n      for(int u:G[v]){\n        if(~level[u])\
    \ continue;\n        level[u]=level[v]+1;\n        int w=match[u];\n        if(w==-1){\n\
    \          found=true;\n          continue;\n        }\n        if(~level[w])\
    \ continue;\n        level[w]=level[u]+1;\n        que.emplace(w);\n      }\n\
    \    }\n    return found;\n  }\n\n  bool dfs(int v){\n    for(int u:G[v]){\n \
    \     if(level[v]+1!=level[u]) continue;\n      level[u]=-1;\n      int w=match[u];\n\
    \      if(w<0 or dfs(w)){\n        match[v]=u;\n        match[u]=v;\n        level[v]=-1;\n\
    \        return true;\n      }\n    }\n    level[v]=-1;\n    return false;\n \
    \ }\n\n  int build(){\n    int res=0;\n    while(bfs())\n      for(int i=0;i<L;i++)\n\
    \        if(match[i]<0 and dfs(i))\n          res++;\n    return res;\n  }\n\n\
    };\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\n// O(E \\sqrt V)\nstruct HopcroftKarp{\n  int L,R;\n\
    \  vector< vector<int> > G;\n  vector<int> match,level;\n\n  HopcroftKarp(int\
    \ L,int R):\n    L(L),R(R),G(L+R),match(L+R,-1),level(L+R){}\n\n  void add_edge(int\
    \ u,int v){\n    G[u].emplace_back(v+L);\n    G[v+L].emplace_back(u);\n  }\n\n\
    \  bool bfs(){\n    fill(level.begin(),level.end(),-1);\n    queue<int> que;\n\
    \    for(int i=0;i<L;i++){\n      if(~match[i]) continue;\n      level[i]=0;\n\
    \      que.emplace(i);\n    }\n    bool found=false;\n    while(!que.empty()){\n\
    \      int v=que.front();que.pop();\n      for(int u:G[v]){\n        if(~level[u])\
    \ continue;\n        level[u]=level[v]+1;\n        int w=match[u];\n        if(w==-1){\n\
    \          found=true;\n          continue;\n        }\n        if(~level[w])\
    \ continue;\n        level[w]=level[u]+1;\n        que.emplace(w);\n      }\n\
    \    }\n    return found;\n  }\n\n  bool dfs(int v){\n    for(int u:G[v]){\n \
    \     if(level[v]+1!=level[u]) continue;\n      level[u]=-1;\n      int w=match[u];\n\
    \      if(w<0 or dfs(w)){\n        match[v]=u;\n        match[u]=v;\n        level[v]=-1;\n\
    \        return true;\n      }\n    }\n    level[v]=-1;\n    return false;\n \
    \ }\n\n  int build(){\n    int res=0;\n    while(bfs())\n      for(int i=0;i<L;i++)\n\
    \        if(match[i]<0 and dfs(i))\n          res++;\n    return res;\n  }\n\n\
    };\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: matching/hopcroft_karp.cpp
  requiredBy: []
  timestamp: '2020-10-27 16:27:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0424.test.cpp
  - test/yosupo/bipartitematching.test.cpp
documentation_of: matching/hopcroft_karp.cpp
layout: document
redirect_from:
- /library/matching/hopcroft_karp.cpp
- /library/matching/hopcroft_karp.cpp.html
title: matching/hopcroft_karp.cpp
---
