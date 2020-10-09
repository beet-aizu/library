---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/arborescence_edmond.cpp
    title: graph/arborescence_edmond.cpp
  - icon: ':heavy_check_mark:'
    path: graph/twosatisfiability.cpp
    title: graph/twosatisfiability.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2222.test.cpp
    title: test/aoj/2222.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2309.tarjan.test.cpp
    title: test/aoj/2309.tarjan.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2309.test.cpp
    title: test/aoj/2309.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2647.test.cpp
    title: test/aoj/2647.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3102.test.cpp
    title: test/aoj/3102.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3183.test.cpp
    title: test/aoj/3183.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_B.test.cpp
    title: test/aoj/GRL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/scc.test.cpp
    title: test/yosupo/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_sat.test.cpp
    title: test/yosupo/two_sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4387.test.cpp
    title: test/yukicoder/4387.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/stronglyconnectedcomponent.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\nstruct SCC{\n  vector< vector<int>\
    \ > G,R,H,C;\n  vector<int> vs,used,blg;\n  SCC(){}\n  SCC(int n):G(n),R(n),used(n),blg(n){}\n\
    \n  void add_edge(int u,int v){\n    G[u].emplace_back(v);\n    R[v].emplace_back(u);\n\
    \  }\n\n  void dfs(int v){\n    used[v]=1;\n    for(int u:G[v])\n      if(!used[u])\
    \ dfs(u);\n    vs.emplace_back(v);\n  }\n\n  void rdfs(int v,int k){\n    used[v]=1;\n\
    \    blg[v]=k;\n    C[k].emplace_back(v);\n    for(int u:R[v])\n      if(!used[u])\
    \ rdfs(u,k);\n  }\n\n  int build(bool uniq=true){\n    int n=G.size();\n    for(int\
    \ v=0;v<n;v++)\n      if(!used[v]) dfs(v);\n\n    fill(used.begin(),used.end(),0);\n\
    \    int k=0;\n    for(int i=n-1;i>=0;i--){\n      if(!used[vs[i]]){\n       \
    \ H.emplace_back();\n        C.emplace_back();\n        rdfs(vs[i],k++);\n   \
    \   }\n    }\n\n    for(int v=0;v<n;v++)\n      for(int u:G[v])\n        if(blg[v]!=blg[u])\n\
    \          H[blg[v]].push_back(blg[u]);\n\n    if(uniq){\n      for(int i=0;i<k;i++){\n\
    \        sort(H[i].begin(),H[i].end());\n        H[i].erase(unique(H[i].begin(),H[i].end()),H[i].end());\n\
    \      }\n    }\n    return k;\n  }\n\n  int operator[](int k) const{return blg[k];}\n\
    };\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nstruct SCC{\n  vector< vector<int> > G,R,H,C;\n  vector<int>\
    \ vs,used,blg;\n  SCC(){}\n  SCC(int n):G(n),R(n),used(n),blg(n){}\n\n  void add_edge(int\
    \ u,int v){\n    G[u].emplace_back(v);\n    R[v].emplace_back(u);\n  }\n\n  void\
    \ dfs(int v){\n    used[v]=1;\n    for(int u:G[v])\n      if(!used[u]) dfs(u);\n\
    \    vs.emplace_back(v);\n  }\n\n  void rdfs(int v,int k){\n    used[v]=1;\n \
    \   blg[v]=k;\n    C[k].emplace_back(v);\n    for(int u:R[v])\n      if(!used[u])\
    \ rdfs(u,k);\n  }\n\n  int build(bool uniq=true){\n    int n=G.size();\n    for(int\
    \ v=0;v<n;v++)\n      if(!used[v]) dfs(v);\n\n    fill(used.begin(),used.end(),0);\n\
    \    int k=0;\n    for(int i=n-1;i>=0;i--){\n      if(!used[vs[i]]){\n       \
    \ H.emplace_back();\n        C.emplace_back();\n        rdfs(vs[i],k++);\n   \
    \   }\n    }\n\n    for(int v=0;v<n;v++)\n      for(int u:G[v])\n        if(blg[v]!=blg[u])\n\
    \          H[blg[v]].push_back(blg[u]);\n\n    if(uniq){\n      for(int i=0;i<k;i++){\n\
    \        sort(H[i].begin(),H[i].end());\n        H[i].erase(unique(H[i].begin(),H[i].end()),H[i].end());\n\
    \      }\n    }\n    return k;\n  }\n\n  int operator[](int k) const{return blg[k];}\n\
    };\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/stronglyconnectedcomponent.cpp
  requiredBy:
  - graph/twosatisfiability.cpp
  - graph/arborescence_edmond.cpp
  timestamp: '2020-09-28 13:04:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/4387.test.cpp
  - test/aoj/2309.test.cpp
  - test/aoj/2222.test.cpp
  - test/aoj/3102.test.cpp
  - test/aoj/2309.tarjan.test.cpp
  - test/aoj/2647.test.cpp
  - test/aoj/3183.test.cpp
  - test/aoj/GRL_2_B.test.cpp
  - test/yosupo/two_sat.test.cpp
  - test/yosupo/scc.test.cpp
documentation_of: graph/stronglyconnectedcomponent.cpp
layout: document
redirect_from:
- /library/graph/stronglyconnectedcomponent.cpp
- /library/graph/stronglyconnectedcomponent.cpp.html
title: graph/stronglyconnectedcomponent.cpp
---
