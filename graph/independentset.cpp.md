---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2948.test.cpp
    title: test/aoj/2948.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/maximum_independent_set.test.cpp
    title: test/yosupo/maximum_independent_set.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/independentset.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\nstruct IndependentSet{\n  int\
    \ n;\n  vector<int> deg,used,dead,pre,ans;\n  vector<vector<int> > G;\n\n  IndependentSet(int\
    \ n):\n    n(n),deg(n),used(n,0),dead(n,0),G(n){}\n\n  void add_edge(int u,int\
    \ v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n  }\n\n  int res,cnt,alive;\n\
    \  void dfs(){\n    if(cnt+alive<=res) return;\n\n    int v=-1;\n    for(int i=0;i<n;i++){\n\
    \      if(used[i] or dead[i]) continue;\n      if(deg[i]<=1){\n        v=i;\n\
    \        break;\n      }\n      if(v<0 or deg[v]<deg[i]) v=i;\n    }\n    if(v<0)\
    \ return;\n\n    if(deg[v]!=1){\n      dead[v]=1;\n      alive--;\n      for(int\
    \ u:G[v]) deg[u]--;\n\n      dfs();\n\n      dead[v]=0;\n      alive++;\n    \
    \  for(int u:G[v]) deg[u]++;\n    }\n    {\n      used[v]=1;\n      alive--;\n\
    \      for(int u:G[v])\n        if(0==dead[u]++) alive-=!used[u];\n      cnt++;\n\
    \      if(res<cnt) pre=used;\n      res=max(res,cnt);\n\n      dfs();\n\n    \
    \  used[v]=0;\n      alive++;\n      for(int u:G[v])\n        if(--dead[u]==0)\
    \ alive+=!used[u];\n      cnt--;\n    }\n  }\n\n  int build(){\n    for(int i=0;i<n;i++)\
    \ deg[i]=G[i].size();\n    res=0,cnt=0,alive=n;\n    dfs();\n    for(int i=0;i<n;i++)\n\
    \      if(pre[i]) ans.emplace_back(i);\n    return res;\n  }\n};\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\nstruct IndependentSet{\n  int n;\n  vector<int> deg,used,dead,pre,ans;\n\
    \  vector<vector<int> > G;\n\n  IndependentSet(int n):\n    n(n),deg(n),used(n,0),dead(n,0),G(n){}\n\
    \n  void add_edge(int u,int v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n\
    \  }\n\n  int res,cnt,alive;\n  void dfs(){\n    if(cnt+alive<=res) return;\n\n\
    \    int v=-1;\n    for(int i=0;i<n;i++){\n      if(used[i] or dead[i]) continue;\n\
    \      if(deg[i]<=1){\n        v=i;\n        break;\n      }\n      if(v<0 or\
    \ deg[v]<deg[i]) v=i;\n    }\n    if(v<0) return;\n\n    if(deg[v]!=1){\n    \
    \  dead[v]=1;\n      alive--;\n      for(int u:G[v]) deg[u]--;\n\n      dfs();\n\
    \n      dead[v]=0;\n      alive++;\n      for(int u:G[v]) deg[u]++;\n    }\n \
    \   {\n      used[v]=1;\n      alive--;\n      for(int u:G[v])\n        if(0==dead[u]++)\
    \ alive-=!used[u];\n      cnt++;\n      if(res<cnt) pre=used;\n      res=max(res,cnt);\n\
    \n      dfs();\n\n      used[v]=0;\n      alive++;\n      for(int u:G[v])\n  \
    \      if(--dead[u]==0) alive+=!used[u];\n      cnt--;\n    }\n  }\n\n  int build(){\n\
    \    for(int i=0;i<n;i++) deg[i]=G[i].size();\n    res=0,cnt=0,alive=n;\n    dfs();\n\
    \    for(int i=0;i<n;i++)\n      if(pre[i]) ans.emplace_back(i);\n    return res;\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/independentset.cpp
  requiredBy: []
  timestamp: '2020-10-27 15:54:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/maximum_independent_set.test.cpp
  - test/aoj/2948.test.cpp
documentation_of: graph/independentset.cpp
layout: document
redirect_from:
- /library/graph/independentset.cpp
- /library/graph/independentset.cpp.html
title: graph/independentset.cpp
---
