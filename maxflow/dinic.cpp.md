---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: maxflow/leastflow.cpp
    title: "\u6700\u5C0F\u6D41\u91CF\u5236\u9650\u4ED8\u304D\u6700\u5927\u6D41"
  - icon: ':heavy_check_mark:'
    path: maxflow/twocommodity.cpp
    title: "\u6700\u5927\u4E8C\u54C1\u7A2E\u6D41"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1599.test.cpp
    title: test/aoj/1599.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1615.test.cpp
    title: test/aoj/1615.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2313.test.cpp
    title: test link cut
  - icon: ':heavy_check_mark:'
    path: test/aoj/2328.test.cpp
    title: test/aoj/2328.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2979.test.cpp
    title: test/aoj/2979.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3047.test.cpp
    title: test/aoj/3047.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3058.test.cpp
    title: test/aoj/3058.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"maxflow/dinic.cpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\n// O(E V^2)\n// O(E \\min(E^{1/2}, V^{2/3}))\
    \ if caps are constant\ntemplate<typename Flow,bool directed>\nstruct Dinic{\n\
    \  struct Edge {\n    int dst;\n    Flow cap;\n    int rev;\n    Edge(int dst,Flow\
    \ cap,int rev):dst(dst),cap(cap),rev(rev){}\n  };\n\n  vector< vector<Edge> >\
    \ G;\n  vector<int> level,iter;\n\n  Dinic(int n):G(n),level(n),iter(n){}\n\n\
    \  int add_edge(int src,int dst,Flow cap){\n    int e=G[src].size();\n    int\
    \ r=(src==dst?e+1:G[dst].size());\n    G[src].emplace_back(dst,cap,r);\n    G[dst].emplace_back(src,directed?0:cap,e);\n\
    \    return e;\n  }\n\n  void bfs(int s){\n    fill(level.begin(),level.end(),-1);\n\
    \    queue<int> que;\n    level[s]=0;\n    que.emplace(s);\n    while(!que.empty()){\n\
    \      int v=que.front();que.pop();\n      for(Edge &e : G[v]) {\n        if(e.cap>0\
    \ and level[e.dst]<0){\n          level[e.dst]=level[v]+1;\n          que.emplace(e.dst);\n\
    \        }\n      }\n    }\n  }\n\n  Flow dfs(int v,int t,Flow f){\n    if(v==t)\
    \ return f;\n    for(int &i=iter[v];i<(int)G[v].size();i++){\n      Edge &e=G[v][i];\n\
    \      if(e.cap>0 and level[v]<level[e.dst]){\n        Flow d=dfs(e.dst,t,min(f,e.cap));\n\
    \        if(d==0) continue;\n        e.cap-=d;\n        G[e.dst][e.rev].cap+=d;\n\
    \        return d;\n      }\n    }\n    return 0;\n  }\n\n  Flow flow(int s,int\
    \ t,Flow lim){\n    Flow fl=0;\n    while(1){\n      bfs(s);\n      if(level[t]<0\
    \ or lim==0) break;\n      fill(iter.begin(),iter.end(),0);\n\n      while(1){\n\
    \        Flow f=dfs(s,t,lim);\n        if(f==0) break;\n        fl+=f;\n     \
    \   lim-=f;\n      }\n    }\n    return fl;\n  }\n\n  Flow flow(int s,int t){\n\
    \    return flow(s,t,numeric_limits<Flow>::max()/2);\n  }\n\n  Flow cut(int s,int\
    \ t,int x,int a){\n    static_assert(directed, \"must be directed\");\n    auto\
    \ &e=G[x][a];\n    int y=e.dst;\n    Flow cr=G[y][e.rev].cap;\n    if(cr==0) return\
    \ e.cap=0;\n    e.cap=G[y][e.rev].cap=0;\n    Flow cap=cr-flow(x,y,cr);\n    if(x!=s\
    \ and cap!=0) flow(x,s,cap);\n    if(t!=y and cap!=0) flow(t,y,cap);\n    return\
    \ cap;\n  }\n\n  Flow link(int s,int t,int x,int a,Flow f){\n    auto &e=G[x][a];\n\
    \    e.cap+=f;\n    return flow(s,t,f);\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\n// O(E V^2)\n// O(E \\min(E^{1/2}, V^{2/3})) if caps are constant\n\
    template<typename Flow,bool directed>\nstruct Dinic{\n  struct Edge {\n    int\
    \ dst;\n    Flow cap;\n    int rev;\n    Edge(int dst,Flow cap,int rev):dst(dst),cap(cap),rev(rev){}\n\
    \  };\n\n  vector< vector<Edge> > G;\n  vector<int> level,iter;\n\n  Dinic(int\
    \ n):G(n),level(n),iter(n){}\n\n  int add_edge(int src,int dst,Flow cap){\n  \
    \  int e=G[src].size();\n    int r=(src==dst?e+1:G[dst].size());\n    G[src].emplace_back(dst,cap,r);\n\
    \    G[dst].emplace_back(src,directed?0:cap,e);\n    return e;\n  }\n\n  void\
    \ bfs(int s){\n    fill(level.begin(),level.end(),-1);\n    queue<int> que;\n\
    \    level[s]=0;\n    que.emplace(s);\n    while(!que.empty()){\n      int v=que.front();que.pop();\n\
    \      for(Edge &e : G[v]) {\n        if(e.cap>0 and level[e.dst]<0){\n      \
    \    level[e.dst]=level[v]+1;\n          que.emplace(e.dst);\n        }\n    \
    \  }\n    }\n  }\n\n  Flow dfs(int v,int t,Flow f){\n    if(v==t) return f;\n\
    \    for(int &i=iter[v];i<(int)G[v].size();i++){\n      Edge &e=G[v][i];\n   \
    \   if(e.cap>0 and level[v]<level[e.dst]){\n        Flow d=dfs(e.dst,t,min(f,e.cap));\n\
    \        if(d==0) continue;\n        e.cap-=d;\n        G[e.dst][e.rev].cap+=d;\n\
    \        return d;\n      }\n    }\n    return 0;\n  }\n\n  Flow flow(int s,int\
    \ t,Flow lim){\n    Flow fl=0;\n    while(1){\n      bfs(s);\n      if(level[t]<0\
    \ or lim==0) break;\n      fill(iter.begin(),iter.end(),0);\n\n      while(1){\n\
    \        Flow f=dfs(s,t,lim);\n        if(f==0) break;\n        fl+=f;\n     \
    \   lim-=f;\n      }\n    }\n    return fl;\n  }\n\n  Flow flow(int s,int t){\n\
    \    return flow(s,t,numeric_limits<Flow>::max()/2);\n  }\n\n  Flow cut(int s,int\
    \ t,int x,int a){\n    static_assert(directed, \"must be directed\");\n    auto\
    \ &e=G[x][a];\n    int y=e.dst;\n    Flow cr=G[y][e.rev].cap;\n    if(cr==0) return\
    \ e.cap=0;\n    e.cap=G[y][e.rev].cap=0;\n    Flow cap=cr-flow(x,y,cr);\n    if(x!=s\
    \ and cap!=0) flow(x,s,cap);\n    if(t!=y and cap!=0) flow(t,y,cap);\n    return\
    \ cap;\n  }\n\n  Flow link(int s,int t,int x,int a,Flow f){\n    auto &e=G[x][a];\n\
    \    e.cap+=f;\n    return flow(s,t,f);\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: maxflow/dinic.cpp
  requiredBy:
  - maxflow/twocommodity.cpp
  - maxflow/leastflow.cpp
  timestamp: '2020-10-27 18:08:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3047.test.cpp
  - test/aoj/2328.test.cpp
  - test/aoj/1599.test.cpp
  - test/aoj/3058.test.cpp
  - test/aoj/2313.test.cpp
  - test/aoj/1615.test.cpp
  - test/aoj/2979.test.cpp
documentation_of: maxflow/dinic.cpp
layout: document
title: "\u6700\u5927\u6D41"
---

## 解説記事
[Dinic 法と, その注意点](https://topcoder-g-hatena-ne-jp.jag-icpc.org/Mi_Sawa/20140311/1394730336.html)

[Dinic 法の速さ](https://topcoder-g-hatena-ne-jp.jag-icpc.org/Mi_Sawa/20140311/1394730337.html)
