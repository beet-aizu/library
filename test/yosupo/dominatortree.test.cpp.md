---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dominatortree.cpp
    title: graph/dominatortree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/dominatortree
    links:
    - https://judge.yosupo.jp/problem/dominatortree
  bundledCode: "#line 1 \"test/yosupo/dominatortree.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/dominatortree\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"graph/dominatortree.cpp\"\
    \n\n#line 3 \"graph/dominatortree.cpp\"\nusing namespace std;\n#endif\n//BEGIN\
    \ CUT HERE\nstruct DominatorTree{\n  struct UnionFind{\n    vector<int> &semi;\n\
    \    vector<int> ps,ms;\n    UnionFind(vector<int> &semi):\n      semi(semi),ps(semi.size()),ms(semi.size()){\n\
    \      iota(ps.begin(),ps.end(),0);\n      iota(ms.begin(),ms.end(),0);\n    }\n\
    \    int find(int v){\n      if(ps[v]==v) return v;\n      int r=find(ps[v]);\n\
    \      if(semi[ms[v]]>semi[ms[ps[v]]]) ms[v]=ms[ps[v]];\n      return ps[v]=r;\n\
    \    }\n    int eval(int v){\n      find(v);\n      return ms[v];\n    }\n   \
    \ void link(int p,int v){ps[v]=p;}\n  };\n\n  vector< vector<int> > G,R;\n  vector<int>\
    \ ord,par,idom,semi;\n  DominatorTree(int n):\n    G(n),R(n),par(n),idom(n,-1),semi(n,-1){\n\
    \    ord.reserve(n);\n  }\n\n  void add_edge(int u,int v){\n    G[u].emplace_back(v);\n\
    \    R[v].emplace_back(u);\n  }\n\n  void dfs(int v){\n    semi[v]=ord.size();\n\
    \    ord.emplace_back(v);\n    for(int u:G[v]){\n      if(~semi[u]) continue;\n\
    \      par[u]=v;\n      dfs(u);\n    }\n  }\n\n  void build(int rt){\n    int\
    \ n=G.size();\n    dfs(rt);\n\n    vector< vector<int> > bkt(n);\n    UnionFind\
    \ uf(semi);\n    vector<int> us(n);\n\n    for(int i=(int)ord.size()-1;i>=0;i--){\n\
    \      int v=ord[i];\n      for(int u:R[v]){\n        if(semi[u]<0) continue;\n\
    \        u=uf.eval(u);\n        if(semi[v]>semi[u]) semi[v]=semi[u];\n      }\n\
    \      bkt[ord[semi[v]]].emplace_back(v);\n      for(int u:bkt[par[v]]) us[u]=uf.eval(u);\n\
    \      bkt[par[v]].clear();\n      uf.link(par[v],v);\n    }\n\n    for(int i=1;i<(int)ord.size();i++){\n\
    \      int v=ord[i],u=us[v];\n      idom[v]=(semi[v]==semi[u]?semi[v]:idom[u]);\n\
    \    }\n\n    for(int i=1;i<(int)ord.size();i++){\n      int v=ord[i];\n     \
    \ idom[v]=ord[idom[v]];\n    }\n\n    idom[rt]=rt;\n  }\n\n  int operator[](int\
    \ k){return idom[k];}\n};\n//END CUT HERE\n#ifndef call_from_test\nint main(){\n\
    \  return 0;\n}\n#endif\n#line 8 \"test/yosupo/dominatortree.test.cpp\"\n#undef\
    \ call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,m,s;\n  cin>>n>>m>>s;\n  DominatorTree G(n);\n  for(int i=0;i<m;i++){\n\
    \    int a,b;\n    cin>>a>>b;\n    G.add_edge(a,b);\n  }\n  G.build(s);\n  for(int\
    \ i=0;i<n;i++){\n    if(i) cout<<\" \";\n    cout<<G[i];\n  }\n  cout<<endl;\n\
    \  return 0;\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/dominatortree\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../graph/dominatortree.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,m,s;\n  cin>>n>>m>>s;\n\
    \  DominatorTree G(n);\n  for(int i=0;i<m;i++){\n    int a,b;\n    cin>>a>>b;\n\
    \    G.add_edge(a,b);\n  }\n  G.build(s);\n  for(int i=0;i<n;i++){\n    if(i)\
    \ cout<<\" \";\n    cout<<G[i];\n  }\n  cout<<endl;\n  return 0;\n}\n"
  dependsOn:
  - graph/dominatortree.cpp
  isVerificationFile: true
  path: test/yosupo/dominatortree.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 15:33:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/dominatortree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/dominatortree.test.cpp
- /verify/test/yosupo/dominatortree.test.cpp.html
title: test/yosupo/dominatortree.test.cpp
---
