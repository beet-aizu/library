---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 2 \"tree/sack.cpp\"\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n\n/**\n * @see https://codeforces.com/blog/entry/44351\n\
    \ */\n//BEGIN CUT HERE\nstruct Sack{\n  using F = function<void(int)>;\n\n  vector<int>\
    \ sub,hvy,big;\n  vector< vector<int> > G,Q;\n  F expand,shrink,query;\n\n  Sack(int\
    \ n,F expand,F shrink,F query):\n    sub(n,1),hvy(n,-1),big(n,0),G(n),Q(n),\n\
    \    expand(expand),shrink(shrink),query(query){}\n\n  void add_edge(int u,int\
    \ v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n  }\n\n  void add_query(int\
    \ v,int k){\n    Q[v].emplace_back(k);\n  }\n\n  void add(int v,int p,int x){\n\
    \    if(x==1) expand(v);\n    else shrink(v);\n    for(int u:G[v])\n      if(u!=p&&!big[u])\
    \ add(u,v,x);\n  }\n\n  void dfs(int v=0,int p=-1,bool k=0){\n    for(int u:G[v])\n\
    \      if(u!=p&&u!=hvy[v]) dfs(u,v,0);\n    if(~hvy[v]){\n      dfs(hvy[v],v,1);\n\
    \      big[hvy[v]]=1;\n    }\n    add(v,p,1);\n    for(int k:Q[v]) query(k);\n\
    \    if(~hvy[v]) big[hvy[v]]=0;\n    if(!k) add(v,p,0);\n  }\n\n  void build(int\
    \ v=0,int p=-1){\n    for(int u:G[v]){\n      if(u==p) continue;\n      build(u,v);\n\
    \      if(hvy[v]<0||sub[hvy[v]]<sub[u]) hvy[v]=u;\n      sub[v]+=sub[u];\n   \
    \ }\n    if(p==-1) dfs(v,p);\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n\n/**\n * @see https://codeforces.com/blog/entry/44351\n */\n\
    //BEGIN CUT HERE\nstruct Sack{\n  using F = function<void(int)>;\n\n  vector<int>\
    \ sub,hvy,big;\n  vector< vector<int> > G,Q;\n  F expand,shrink,query;\n\n  Sack(int\
    \ n,F expand,F shrink,F query):\n    sub(n,1),hvy(n,-1),big(n,0),G(n),Q(n),\n\
    \    expand(expand),shrink(shrink),query(query){}\n\n  void add_edge(int u,int\
    \ v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n  }\n\n  void add_query(int\
    \ v,int k){\n    Q[v].emplace_back(k);\n  }\n\n  void add(int v,int p,int x){\n\
    \    if(x==1) expand(v);\n    else shrink(v);\n    for(int u:G[v])\n      if(u!=p&&!big[u])\
    \ add(u,v,x);\n  }\n\n  void dfs(int v=0,int p=-1,bool k=0){\n    for(int u:G[v])\n\
    \      if(u!=p&&u!=hvy[v]) dfs(u,v,0);\n    if(~hvy[v]){\n      dfs(hvy[v],v,1);\n\
    \      big[hvy[v]]=1;\n    }\n    add(v,p,1);\n    for(int k:Q[v]) query(k);\n\
    \    if(~hvy[v]) big[hvy[v]]=0;\n    if(!k) add(v,p,0);\n  }\n\n  void build(int\
    \ v=0,int p=-1){\n    for(int u:G[v]){\n      if(u==p) continue;\n      build(u,v);\n\
    \      if(hvy[v]<0||sub[hvy[v]]<sub[u]) hvy[v]=u;\n      sub[v]+=sub[u];\n   \
    \ }\n    if(p==-1) dfs(v,p);\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2995.test.cpp
    title: test/aoj/2995.test.cpp
  extendedVerifiedWith: []
  isVerificationFile: false
  path: tree/sack.cpp
  requiredBy:
  - test/aoj/2995.test.cpp
  timestamp: '2020-09-02 13:08:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: tree/sack.cpp
layout: document
redirect_from:
- /library/tree/sack.cpp
- /library/tree/sack.cpp.html
title: tree/sack.cpp
---
