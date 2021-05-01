---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tree/lowestcommonancestor.cpp
    title: tree/lowestcommonancestor.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
  bundledCode: "#line 1 \"test/aoj/GRL_5_C.test.cpp\"\n// verification-helper: PROBLEM\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"tree/lowestcommonancestor.cpp\"\
    \n\n#line 3 \"tree/lowestcommonancestor.cpp\"\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nstruct LowestCommonAncestor{\n  int h;\n  vector< vector<int>\
    \ > G,par;\n  vector<int> dep;\n  LowestCommonAncestor(int n):G(n),dep(n){\n \
    \   h=1;\n    while((1<<h)<=n) h++;\n    par.assign(h,vector<int>(n,-1));\n  }\n\
    \n  void add_edge(int u,int v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n\
    \  }\n\n  void dfs(int v,int p,int d){\n    par[0][v]=p;\n    dep[v]=d;\n    for(int\
    \ u:G[v])\n      if(u!=p) dfs(u,v,d+1);\n  }\n\n  void build(int r=0){\n    int\
    \ n=G.size();\n    dfs(r,-1,0);\n    for(int k=0;k+1<h;k++)\n      for(int v=0;v<n;v++)\n\
    \        if(~par[k][v])\n          par[k+1][v]=par[k][par[k][v]];\n  }\n\n  int\
    \ lca(int u,int v){\n    if(dep[u]>dep[v]) swap(u,v);\n    for(int k=0;k<h;k++)\n\
    \      if((dep[v]-dep[u])>>k&1)\n        v=par[k][v];\n\n    if(u==v) return u;\n\
    \n    for(int k=h-1;k>=0;k--)\n      if(par[k][u]!=par[k][v])\n        u=par[k][u],v=par[k][v];\n\
    \n    return par[0][u];\n  }\n\n  int distance(int u,int v){\n    return dep[u]+dep[v]-dep[lca(u,v)]*2;\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n\
    }\n#endif\n#line 8 \"test/aoj/GRL_5_C.test.cpp\"\n#undef call_from_test\n\nsigned\
    \ main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n;\n  cin>>n;\n\
    \  LowestCommonAncestor lca(n);\n  for(int i=0;i<n;i++){\n    int k;\n    cin>>k;\n\
    \    for(int j=0;j<k;j++){\n      int c;\n      cin>>c;\n      lca.add_edge(i,c);\n\
    \    }\n  }\n  lca.build();\n\n  int q;\n  cin>>q;\n  while(q--){\n    int u,v;\n\
    \    cin>>u>>v;\n    cout<<lca.lca(u,v)<<\"\\n\";\n  }\n  cout<<flush;\n  return\
    \ 0;\n}\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../tree/lowestcommonancestor.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n;\n  cin>>n;\n  LowestCommonAncestor\
    \ lca(n);\n  for(int i=0;i<n;i++){\n    int k;\n    cin>>k;\n    for(int j=0;j<k;j++){\n\
    \      int c;\n      cin>>c;\n      lca.add_edge(i,c);\n    }\n  }\n  lca.build();\n\
    \n  int q;\n  cin>>q;\n  while(q--){\n    int u,v;\n    cin>>u>>v;\n    cout<<lca.lca(u,v)<<\"\
    \\n\";\n  }\n  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - tree/lowestcommonancestor.cpp
  isVerificationFile: true
  path: test/aoj/GRL_5_C.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 19:32:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_5_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_C.test.cpp
- /verify/test/aoj/GRL_5_C.test.cpp.html
title: test/aoj/GRL_5_C.test.cpp
---
