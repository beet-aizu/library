---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/enumerate_triangles.test.cpp
    title: test/yosupo/enumerate_triangles.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/triangle.cpp\"\n\n#ifndef call_from_test\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#endif\n//BEGIN CUT HERE\nstruct Triangle{\n\
    \  // if not simple, use vector<set<int>>\n  vector<vector<int>> G;\n  Triangle(int\
    \ n):G(n){}\n\n  void add_edge(int u,int v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n\
    \  }\n\n  template<typename F>\n  void build(F f){\n    int n=G.size();\n    using\
    \ P = pair<int, int>;\n    vector<P> vp(n);\n    for(int i=0;i<n;i++) vp[i]=P(G[i].size(),i);\n\
    \n    vector<vector<int>> H(n);\n    for(int i=0;i<n;i++)\n      for(int j:G[i])\n\
    \        if(vp[i]>vp[j])\n          H[i].emplace_back(j);\n\n    vector<int> used(n,0);\n\
    \    // x->y->z\n    for(int x=0;x<n;x++){\n      for(int z:H[x]) used[z]=1;\n\
    \      for(int y:H[x])\n        for(int z:H[y])\n          if(used[z]) f(x,y,z);\n\
    \      for(int z:H[x]) used[z]=0;\n    }\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\nstruct Triangle{\n  // if not simple, use vector<set<int>>\n\
    \  vector<vector<int>> G;\n  Triangle(int n):G(n){}\n\n  void add_edge(int u,int\
    \ v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n  }\n\n  template<typename\
    \ F>\n  void build(F f){\n    int n=G.size();\n    using P = pair<int, int>;\n\
    \    vector<P> vp(n);\n    for(int i=0;i<n;i++) vp[i]=P(G[i].size(),i);\n\n  \
    \  vector<vector<int>> H(n);\n    for(int i=0;i<n;i++)\n      for(int j:G[i])\n\
    \        if(vp[i]>vp[j])\n          H[i].emplace_back(j);\n\n    vector<int> used(n,0);\n\
    \    // x->y->z\n    for(int x=0;x<n;x++){\n      for(int z:H[x]) used[z]=1;\n\
    \      for(int y:H[x])\n        for(int z:H[y])\n          if(used[z]) f(x,y,z);\n\
    \      for(int z:H[x]) used[z]=0;\n    }\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/triangle.cpp
  requiredBy: []
  timestamp: '2020-05-07 17:33:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/enumerate_triangles.test.cpp
documentation_of: graph/triangle.cpp
layout: document
redirect_from:
- /library/graph/triangle.cpp
- /library/graph/triangle.cpp.html
title: graph/triangle.cpp
---
