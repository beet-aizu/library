---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/stronglyconnectedcomponent.cpp
    title: graph/stronglyconnectedcomponent.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/yosupo/scc.test.cpp\"\n// verification-helper: PROBLEM\
    \ https://judge.yosupo.jp/problem/scc\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define call_from_test\n#line 1 \"graph/stronglyconnectedcomponent.cpp\"\
    \n\n#line 3 \"graph/stronglyconnectedcomponent.cpp\"\nusing namespace std;\n#endif\n\
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
    \          H[blg[v]].emplace_back(blg[u]);\n\n    if(uniq){\n      for(int i=0;i<k;i++){\n\
    \        sort(H[i].begin(),H[i].end());\n        H[i].erase(unique(H[i].begin(),H[i].end()),H[i].end());\n\
    \      }\n    }\n    return k;\n  }\n\n  int operator[](int k) const{return blg[k];}\n\
    };\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n\
    #line 8 \"test/yosupo/scc.test.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,m;\n  cin>>n>>m;\n  SCC\
    \ G(n);\n  for(int i=0;i<m;i++){\n    int a,b;\n    cin>>a>>b;\n    G.add_edge(a,b);\n\
    \  }\n  int k=G.build();\n  cout<<k<<endl;\n  for(int i=0;i<k;i++){\n    cout<<G.C[i].size();\n\
    \    for(int v:G.C[i]) cout<<\" \"<<v;\n    cout<<\"\\n\";\n  }\n  cout<<flush;\n\
    \  return 0;\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/scc\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#include \"../../graph/stronglyconnectedcomponent.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,m;\n  cin>>n>>m;\n  SCC G(n);\n  for(int i=0;i<m;i++){\n    int a,b;\n\
    \    cin>>a>>b;\n    G.add_edge(a,b);\n  }\n  int k=G.build();\n  cout<<k<<endl;\n\
    \  for(int i=0;i<k;i++){\n    cout<<G.C[i].size();\n    for(int v:G.C[i]) cout<<\"\
    \ \"<<v;\n    cout<<\"\\n\";\n  }\n  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - graph/stronglyconnectedcomponent.cpp
  isVerificationFile: true
  path: test/yosupo/scc.test.cpp
  requiredBy: []
  timestamp: '2020-10-25 17:34:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/scc.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/scc.test.cpp
- /verify/test/yosupo/scc.test.cpp.html
title: test/yosupo/scc.test.cpp
---
