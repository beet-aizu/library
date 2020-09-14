---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/twoedgeconnectedcomponents.cpp
    title: graph/twoedgeconnectedcomponents.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"test/yosupo/two_edge_connected_components.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\n\n\
    #include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#line\
    \ 2 \"graph/twoedgeconnectedcomponents.cpp\"\n\n#ifndef call_from_test\n#line\
    \ 5 \"graph/twoedgeconnectedcomponents.cpp\"\nusing namespace std;\n#endif\n//BEGIN\
    \ CUT HERE\n// work with multigraph\nstruct TwoEdgeConnectedComponents{\n  vector<int>\
    \ ord,low,par,blg,sz;\n  vector<vector<int>> G,C;\n\n  TwoEdgeConnectedComponents(int\
    \ n):\n    ord(n,-1),low(n),par(n,-1),blg(n,-1),sz(n,1),G(n){}\n\n  void add_edge(int\
    \ u,int v){\n    if(u==v) return;\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n\
    \  }\n\n  bool is_bridge(int u,int v){\n    if(ord[u]>ord[v]) swap(u,v);\n   \
    \ return ord[u]<low[v];\n  }\n\n  void dfs(int v,int &pos){\n    ord[v]=low[v]=pos++;\n\
    \    int dup=0;\n    for(int u:G[v]){\n      if(u==par[v] and !dup){\n       \
    \ dup=1;\n        continue;\n      }\n      if(~ord[u]){\n        low[v]=min(low[v],ord[u]);\n\
    \        continue;\n      }\n      par[u]=v;\n      dfs(u,pos);\n      sz[v]+=sz[u];\n\
    \      low[v]=min(low[v],low[u]);\n    }\n  }\n\n  void fill_component(int v){\n\
    \    C[blg[v]].emplace_back(v);\n    for(int u:G[v]){\n      if(~blg[u]||is_bridge(u,v))\
    \ continue;\n      blg[u]=blg[v];\n      fill_component(u);\n    }\n  }\n\n  void\
    \ add_component(int v,int &k){\n    if(~blg[v]) return;\n    blg[v]=k++;\n   \
    \ C.emplace_back();\n    fill_component(v);\n  }\n\n  int build(){\n    int n=G.size(),pos=0;\n\
    \    for(int i=0;i<n;i++)\n      if(ord[i]<0) dfs(i,pos);\n\n    int k=0;\n  \
    \  for(int i=0;i<n;i++) add_component(i,k);\n\n    return k;\n  }\n\n  const vector<int>&\
    \ operator[](int i)const{return C[i];}\n\n  vector<vector<int>> forest(){\n  \
    \  int n=G.size(),k=C.size();\n    vector<vector<int>> T(k);\n    for(int v=0;v<n;v++)\n\
    \      for(int u:G[v])\n        if(blg[v]!=blg[u])\n          T[blg[v]].emplace_back(blg[u]);\n\
    \    return T;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE\
    \ HERE\nsigned main(){\n  return 0;\n}\n#endif\n#line 8 \"test/yosupo/two_edge_connected_components.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,m;\n  cin>>n>>m;\n\n  TwoEdgeConnectedComponents C(n);\n  for(int i=0;i<m;i++){\n\
    \    int a,b;\n    cin>>a>>b;\n    C.add_edge(a,b);\n  }\n\n  int k=C.build();\n\
    \  cout<<k<<endl;\n  for(int i=0;i<k;i++){\n    cout<<C[i].size();\n    for(int\
    \ j=0;j<(int)C[i].size();j++) cout<<\" \"<<C[i][j];\n    cout<<\"\\n\";\n  }\n\
    \n  cout<<flush;\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../graph/twoedgeconnectedcomponents.cpp\"\n#undef call_from_test\n\
    \nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,m;\n  cin>>n>>m;\n\
    \n  TwoEdgeConnectedComponents C(n);\n  for(int i=0;i<m;i++){\n    int a,b;\n\
    \    cin>>a>>b;\n    C.add_edge(a,b);\n  }\n\n  int k=C.build();\n  cout<<k<<endl;\n\
    \  for(int i=0;i<k;i++){\n    cout<<C[i].size();\n    for(int j=0;j<(int)C[i].size();j++)\
    \ cout<<\" \"<<C[i][j];\n    cout<<\"\\n\";\n  }\n\n  cout<<flush;\n  return 0;\n\
    }\n"
  dependsOn:
  - graph/twoedgeconnectedcomponents.cpp
  isVerificationFile: true
  path: test/yosupo/two_edge_connected_components.test.cpp
  requiredBy: []
  timestamp: '2020-03-12 16:29:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/two_edge_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/two_edge_connected_components.test.cpp
- /verify/test/yosupo/two_edge_connected_components.test.cpp.html
title: test/yosupo/two_edge_connected_components.test.cpp
---
