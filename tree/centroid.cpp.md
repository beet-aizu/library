---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2790.test.cpp
    title: test/aoj/2790.test.cpp
  - icon: ':x:'
    path: test/aoj/3084.test.cpp
    title: test/aoj/3084.test.cpp
  - icon: ':x:'
    path: test/aoj/3142.test.cpp
    title: test/aoj/3142.test.cpp
  - icon: ':x:'
    path: test/yosupo/frequency_table_of_tree_distance.test.cpp
    title: test/yosupo/frequency_table_of_tree_distance.test.cpp
  - icon: ':x:'
    path: test/yukicoder/3912.test.cpp
    title: test/yukicoder/3912.test.cpp
  - icon: ':x:'
    path: test/yukicoder/3961.test.cpp
    title: test/yukicoder/3961.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/centroid.cpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\nstruct Centroid{\n  vector<int> sz,dead;\n \
    \ vector< vector<int> > G;\n  Centroid(){}\n  Centroid(int n):sz(n,1),dead(n,0),G(n){}\n\
    \n  void add_edge(int u,int v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n\
    \  }\n\n  int dfs(int v,int p){\n    sz[v]=1;\n    for(int u:G[v])\n      if(u!=p\
    \ and !dead[u]) sz[v]+=dfs(u,v);\n    return sz[v];\n  }\n\n  void find(int v,int\
    \ p,int tmp,vector<int> &cs) {\n    int ok=1;\n    for (int u:G[v]){\n      if(u==p\
    \ or dead[u]) continue;\n      find(u,v,tmp,cs);\n      ok&=(sz[u]<=tmp/2);\n\
    \    }\n    ok&=(tmp-sz[v]<=tmp/2);\n    if(ok) cs.emplace_back(v);\n  }\n\n \
    \ vector<int> build(int r) {\n    int tmp=dfs(r,-1);\n    vector<int> cs;\n  \
    \  find(r,-1,tmp,cs);\n    return cs;\n  }\n\n  const vector<int>& operator[](int\
    \ k)const{return G[k];}\n  void disable(int v){dead[v]=1;}\n  void  enable(int\
    \ v){dead[v]=0;}\n  int alive(int v){return !dead[v];}\n};\n//END CUT HERE\n#ifndef\
    \ call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nstruct Centroid{\n  vector<int> sz,dead;\n  vector< vector<int>\
    \ > G;\n  Centroid(){}\n  Centroid(int n):sz(n,1),dead(n,0),G(n){}\n\n  void add_edge(int\
    \ u,int v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n  }\n\n  int\
    \ dfs(int v,int p){\n    sz[v]=1;\n    for(int u:G[v])\n      if(u!=p and !dead[u])\
    \ sz[v]+=dfs(u,v);\n    return sz[v];\n  }\n\n  void find(int v,int p,int tmp,vector<int>\
    \ &cs) {\n    int ok=1;\n    for (int u:G[v]){\n      if(u==p or dead[u]) continue;\n\
    \      find(u,v,tmp,cs);\n      ok&=(sz[u]<=tmp/2);\n    }\n    ok&=(tmp-sz[v]<=tmp/2);\n\
    \    if(ok) cs.emplace_back(v);\n  }\n\n  vector<int> build(int r) {\n    int\
    \ tmp=dfs(r,-1);\n    vector<int> cs;\n    find(r,-1,tmp,cs);\n    return cs;\n\
    \  }\n\n  const vector<int>& operator[](int k)const{return G[k];}\n  void disable(int\
    \ v){dead[v]=1;}\n  void  enable(int v){dead[v]=0;}\n  int alive(int v){return\
    \ !dead[v];}\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/centroid.cpp
  requiredBy: []
  timestamp: '2020-09-30 16:50:39+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/3961.test.cpp
  - test/yukicoder/3912.test.cpp
  - test/aoj/3084.test.cpp
  - test/aoj/2790.test.cpp
  - test/aoj/3142.test.cpp
  - test/yosupo/frequency_table_of_tree_distance.test.cpp
documentation_of: tree/centroid.cpp
layout: document
redirect_from:
- /library/tree/centroid.cpp
- /library/tree/centroid.cpp.html
title: tree/centroid.cpp
---
