---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: flow/leastflow.cpp
    title: "\u6700\u5C0F\u6D41\u91CF\u5236\u9650\u4ED8\u304D\u6700\u5927\u6D41"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2313.test.cpp
    title: test/aoj/2313.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3047.test.cpp
    title: test/aoj/3047.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2328.test.cpp
    title: test/aoj/2328.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1599.test.cpp
    title: test/aoj/1599.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1615.test.cpp
    title: test/aoj/1615.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3058.test.cpp
    title: test/aoj/3058.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_A.test.cpp
    title: test/aoj/GRL_6_A.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"flow/dinic.cpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T,bool directed>\nstruct Dinic{\n\
    \  struct edge {\n    int to;\n    T cap;\n    int rev;\n    edge(){}\n    edge(int\
    \ to,T cap,int rev):to(to),cap(cap),rev(rev){}\n  };\n\n  vector< vector<edge>\
    \ > G;\n  vector<int> level,iter;\n\n  Dinic(){}\n  Dinic(int n):G(n),level(n),iter(n){}\n\
    \n  int add_edge(int from,int to,T cap){\n    G[from].emplace_back(to,cap,G[to].size());\n\
    \    G[to].emplace_back(from,directed?0:cap,G[from].size()-1);\n    return G[to].back().rev;\n\
    \  }\n\n  void bfs(int s){\n    fill(level.begin(),level.end(),-1);\n    queue<int>\
    \ que;\n    level[s]=0;\n    que.emplace(s);\n    while(!que.empty()){\n     \
    \ int v=que.front();que.pop();\n      for(int i=0;i<(int)G[v].size();i++){\n \
    \       edge &e=G[v][i];\n        if(e.cap>0&&level[e.to]<0){\n          level[e.to]=level[v]+1;\n\
    \          que.emplace(e.to);\n        }\n      }\n    }\n  }\n\n  T dfs(int v,int\
    \ t,T f){\n    if(v==t) return f;\n    for(int &i=iter[v];i<(int)G[v].size();i++){\n\
    \      edge &e=G[v][i];\n      if(e.cap>0&&level[v]<level[e.to]){\n        T d=dfs(e.to,t,min(f,e.cap));\n\
    \        if(d==0) continue;\n        e.cap-=d;\n        G[e.to][e.rev].cap+=d;\n\
    \        return d;\n      }\n    }\n    return 0;\n  }\n\n  T flow(int s,int t,T\
    \ lim){\n    T fl=0;\n    while(1){\n      bfs(s);\n      if(level[t]<0||lim==0)\
    \ break;\n      fill(iter.begin(),iter.end(),0);\n\n      while(1){\n        T\
    \ f=dfs(s,t,lim);\n        if(f==0) break;\n        fl+=f;\n        lim-=f;\n\
    \      }\n    }\n    return fl;\n  }\n\n  T flow(int s,int t){\n    return flow(s,t,numeric_limits<T>::max()/2);\n\
    \  }\n\n  T cut(int s,int t,int x,int a){\n    static_assert(directed, \"must\
    \ be directed\");\n    auto &e=G[x][a];\n    int y=e.to;\n    T cr=G[y][e.rev].cap;\n\
    \    if(cr==0) return e.cap=0;\n    e.cap=G[y][e.rev].cap=0;\n    T cap=cr-flow(x,y,cr);\n\
    \    if(x!=s&&cap!=0) flow(x,s,cap);\n    if(t!=y&&cap!=0) flow(t,y,cap);\n  \
    \  return cap;\n  }\n\n  T link(int s,int t,int x,int a,T f){\n    auto &e=G[x][a];\n\
    \    e.cap+=f;\n    return flow(s,t,f);\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename T,bool directed>\nstruct Dinic{\n  struct\
    \ edge {\n    int to;\n    T cap;\n    int rev;\n    edge(){}\n    edge(int to,T\
    \ cap,int rev):to(to),cap(cap),rev(rev){}\n  };\n\n  vector< vector<edge> > G;\n\
    \  vector<int> level,iter;\n\n  Dinic(){}\n  Dinic(int n):G(n),level(n),iter(n){}\n\
    \n  int add_edge(int from,int to,T cap){\n    G[from].emplace_back(to,cap,G[to].size());\n\
    \    G[to].emplace_back(from,directed?0:cap,G[from].size()-1);\n    return G[to].back().rev;\n\
    \  }\n\n  void bfs(int s){\n    fill(level.begin(),level.end(),-1);\n    queue<int>\
    \ que;\n    level[s]=0;\n    que.emplace(s);\n    while(!que.empty()){\n     \
    \ int v=que.front();que.pop();\n      for(int i=0;i<(int)G[v].size();i++){\n \
    \       edge &e=G[v][i];\n        if(e.cap>0&&level[e.to]<0){\n          level[e.to]=level[v]+1;\n\
    \          que.emplace(e.to);\n        }\n      }\n    }\n  }\n\n  T dfs(int v,int\
    \ t,T f){\n    if(v==t) return f;\n    for(int &i=iter[v];i<(int)G[v].size();i++){\n\
    \      edge &e=G[v][i];\n      if(e.cap>0&&level[v]<level[e.to]){\n        T d=dfs(e.to,t,min(f,e.cap));\n\
    \        if(d==0) continue;\n        e.cap-=d;\n        G[e.to][e.rev].cap+=d;\n\
    \        return d;\n      }\n    }\n    return 0;\n  }\n\n  T flow(int s,int t,T\
    \ lim){\n    T fl=0;\n    while(1){\n      bfs(s);\n      if(level[t]<0||lim==0)\
    \ break;\n      fill(iter.begin(),iter.end(),0);\n\n      while(1){\n        T\
    \ f=dfs(s,t,lim);\n        if(f==0) break;\n        fl+=f;\n        lim-=f;\n\
    \      }\n    }\n    return fl;\n  }\n\n  T flow(int s,int t){\n    return flow(s,t,numeric_limits<T>::max()/2);\n\
    \  }\n\n  T cut(int s,int t,int x,int a){\n    static_assert(directed, \"must\
    \ be directed\");\n    auto &e=G[x][a];\n    int y=e.to;\n    T cr=G[y][e.rev].cap;\n\
    \    if(cr==0) return e.cap=0;\n    e.cap=G[y][e.rev].cap=0;\n    T cap=cr-flow(x,y,cr);\n\
    \    if(x!=s&&cap!=0) flow(x,s,cap);\n    if(t!=y&&cap!=0) flow(t,y,cap);\n  \
    \  return cap;\n  }\n\n  T link(int s,int t,int x,int a,T f){\n    auto &e=G[x][a];\n\
    \    e.cap+=f;\n    return flow(s,t,f);\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/dinic.cpp
  requiredBy:
  - flow/leastflow.cpp
  timestamp: '2019-12-26 22:42:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2313.test.cpp
  - test/aoj/3047.test.cpp
  - test/aoj/2328.test.cpp
  - test/aoj/1599.test.cpp
  - test/aoj/1615.test.cpp
  - test/aoj/3058.test.cpp
  - test/aoj/GRL_6_A.test.cpp
documentation_of: flow/dinic.cpp
layout: document
redirect_from:
- /library/flow/dinic.cpp
- /library/flow/dinic.cpp.html
title: flow/dinic.cpp
---
