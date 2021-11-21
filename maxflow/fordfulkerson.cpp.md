---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3183.test.cpp
    title: test/aoj/3183.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_A.test.cpp
    title: test/aoj/GRL_6_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"maxflow/fordfulkerson.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\n// O(F E)\ntemplate<typename Flow,\
    \ bool directed>\nstruct FordFulkerson{\n  struct Edge{\n    int dst;\n    Flow\
    \ cap;\n    int rev;\n    Edge(int dst,Flow cap,int rev):dst(dst),cap(cap),rev(rev){}\n\
    \  };\n\n  vector< vector<Edge> > G;\n  vector<int> used;\n\n  FordFulkerson(int\
    \ n):G(n),used(n){}\n\n  int add_edge(int src,int dst,Flow cap){\n    int e=G[src].size();\n\
    \    int r=(src==dst?e+1:G[dst].size());\n    G[src].emplace_back(dst,cap,r);\n\
    \    G[dst].emplace_back(src,directed?0:cap,e);\n    return e;\n  }\n\n  Flow\
    \ dfs(int v,int t,Flow f){\n    if(v==t) return f;\n    used[v]=true;\n    for(Edge\
    \ &e:G[v]){\n      if(used[e.dst] or e.cap==0) continue;\n      Flow d=dfs(e.dst,t,min(f,e.cap));\n\
    \      if(d==0) continue;\n      e.cap-=d;\n      G[e.dst][e.rev].cap+=d;\n  \
    \    return d;\n    }\n    return 0;\n  }\n\n  Flow flow(int s,int t,Flow lim){\n\
    \    Flow res=0;\n    while(1){\n      fill(used.begin(),used.end(),0);\n    \
    \  Flow f=dfs(s,t,lim);\n      if(f==0) break;\n      res+=f;\n      lim-=f;\n\
    \    }\n    return res;\n  }\n\n  Flow flow(int s,int t){\n    return flow(s,t,numeric_limits<Flow>::max()/2);\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n\
    }\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\n// O(F E)\ntemplate<typename Flow, bool directed>\nstruct FordFulkerson{\n\
    \  struct Edge{\n    int dst;\n    Flow cap;\n    int rev;\n    Edge(int dst,Flow\
    \ cap,int rev):dst(dst),cap(cap),rev(rev){}\n  };\n\n  vector< vector<Edge> >\
    \ G;\n  vector<int> used;\n\n  FordFulkerson(int n):G(n),used(n){}\n\n  int add_edge(int\
    \ src,int dst,Flow cap){\n    int e=G[src].size();\n    int r=(src==dst?e+1:G[dst].size());\n\
    \    G[src].emplace_back(dst,cap,r);\n    G[dst].emplace_back(src,directed?0:cap,e);\n\
    \    return e;\n  }\n\n  Flow dfs(int v,int t,Flow f){\n    if(v==t) return f;\n\
    \    used[v]=true;\n    for(Edge &e:G[v]){\n      if(used[e.dst] or e.cap==0)\
    \ continue;\n      Flow d=dfs(e.dst,t,min(f,e.cap));\n      if(d==0) continue;\n\
    \      e.cap-=d;\n      G[e.dst][e.rev].cap+=d;\n      return d;\n    }\n    return\
    \ 0;\n  }\n\n  Flow flow(int s,int t,Flow lim){\n    Flow res=0;\n    while(1){\n\
    \      fill(used.begin(),used.end(),0);\n      Flow f=dfs(s,t,lim);\n      if(f==0)\
    \ break;\n      res+=f;\n      lim-=f;\n    }\n    return res;\n  }\n\n  Flow\
    \ flow(int s,int t){\n    return flow(s,t,numeric_limits<Flow>::max()/2);\n  }\n\
    };\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: maxflow/fordfulkerson.cpp
  requiredBy: []
  timestamp: '2020-10-27 18:08:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3183.test.cpp
  - test/aoj/GRL_6_A.test.cpp
documentation_of: maxflow/fordfulkerson.cpp
layout: document
title: "\u6700\u5927\u6D41 (\u8A08\u7B97\u91CF\u304C\u6D41\u91CF\u4F9D\u5B58)"
---
