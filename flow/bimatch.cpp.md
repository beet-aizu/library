---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"flow/bimatch.cpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\nstruct BiMatch{\n  int n,time;\n  vector<vector<int>>\
    \ G;\n  vector<int> match,used,dead;\n\n  BiMatch(){}\n  BiMatch(int n):n(n),time(0),G(n),\n\
    \                 match(n,-1),used(n,-1),dead(n,0){}\n\n  void add_edge(int u,int\
    \ v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n  }\n\n  int dfs(int\
    \ v){\n    used[v]=time;\n    for(int u:G[v]){\n      if(dead[u]) continue;\n\
    \      int w=match[u];\n      if((w<0)||(used[w]<time&&dfs(w))){\n        match[v]=u;\n\
    \        match[u]=v;\n        return 1;\n      }\n    }\n    return 0;\n  }\n\n\
    \  int build(){\n    int res=0;\n    for(int v=0;v<n;v++){\n      if(dead[v])\
    \ continue;\n      if(match[v]<0){\n        time++;\n        res+=dfs(v);\n  \
    \    }\n    }\n    return res;\n  }\n\n  int disable(int v){\n    assert(!dead[v]);\n\
    \    int u=match[v];\n    if(~u) match[u]=-1;\n    match[v]=-1;\n    dead[v]=1;\n\
    \    time++;\n    return ~u?dfs(u)-1:0;\n  }\n\n  int enable(int v){\n    assert(dead[v]);\n\
    \    dead[v]=0;\n    time++;\n    return dfs(v);\n  }\n};\n//END CUT HERE\n#ifndef\
    \ call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nstruct BiMatch{\n  int n,time;\n  vector<vector<int>> G;\n \
    \ vector<int> match,used,dead;\n\n  BiMatch(){}\n  BiMatch(int n):n(n),time(0),G(n),\n\
    \                 match(n,-1),used(n,-1),dead(n,0){}\n\n  void add_edge(int u,int\
    \ v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n  }\n\n  int dfs(int\
    \ v){\n    used[v]=time;\n    for(int u:G[v]){\n      if(dead[u]) continue;\n\
    \      int w=match[u];\n      if((w<0)||(used[w]<time&&dfs(w))){\n        match[v]=u;\n\
    \        match[u]=v;\n        return 1;\n      }\n    }\n    return 0;\n  }\n\n\
    \  int build(){\n    int res=0;\n    for(int v=0;v<n;v++){\n      if(dead[v])\
    \ continue;\n      if(match[v]<0){\n        time++;\n        res+=dfs(v);\n  \
    \    }\n    }\n    return res;\n  }\n\n  int disable(int v){\n    assert(!dead[v]);\n\
    \    int u=match[v];\n    if(~u) match[u]=-1;\n    match[v]=-1;\n    dead[v]=1;\n\
    \    time++;\n    return ~u?dfs(u)-1:0;\n  }\n\n  int enable(int v){\n    assert(dead[v]);\n\
    \    dead[v]=0;\n    time++;\n    return dfs(v);\n  }\n};\n//END CUT HERE\n#ifndef\
    \ call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2513.test.cpp
    title: test/aoj/2513.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_7_A.test.cpp
    title: test/aoj/GRL_7_A.test.cpp
  extendedVerifiedWith: []
  isVerificationFile: false
  path: flow/bimatch.cpp
  requiredBy:
  - test/aoj/2513.test.cpp
  - test/aoj/GRL_7_A.test.cpp
  timestamp: '2019-12-10 15:04:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: flow/bimatch.cpp
layout: document
redirect_from:
- /library/flow/bimatch.cpp
- /library/flow/bimatch.cpp.html
title: flow/bimatch.cpp
---
