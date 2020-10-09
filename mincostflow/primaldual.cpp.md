---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: mincostflow/negativeedge.cpp
    title: "\u6700\u5C0F\u8CBB\u7528\u6D41\u306E\u8CA0\u8FBA\u9664\u53BB"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2290.test.cpp
    title: test/aoj/2290.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2627.test.cpp
    title: test/aoj/2627.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2679.test.cpp
    title: lexicographical cost
  - icon: ':heavy_check_mark:'
    path: test/aoj/2736.test.cpp
    title: test/aoj/2736.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_B.test.cpp
    title: test/aoj/GRL_6_B.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mincostflow/primaldual.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\n// O(F E \\log V)\ntemplate<typename\
    \ Flow, typename Cost>\nstruct PrimalDual{\n  struct Edge{\n    int dst;\n   \
    \ Flow cap;\n    Cost cost;\n    int rev;\n    Edge(int dst,Flow cap,Cost cost,int\
    \ rev):\n      dst(dst),cap(cap),cost(cost),rev(rev){}\n  };\n\n  vector<vector<Edge>>\
    \ G;\n  vector<Cost> h,dist;\n  vector<int> prevv,preve;\n\n  PrimalDual(int n):G(n),h(n),dist(n),prevv(n),preve(n){}\n\
    \n  void add_edge(int u,int v,Flow cap,Cost cost){\n    int e=G[u].size();\n \
    \   int r=(u==v?e+1:G[v].size());\n    G[u].emplace_back(v,cap,cost,r);\n    G[v].emplace_back(u,0,-cost,e);\n\
    \  }\n\n  Cost residual_cost(int src,Edge &e){\n    return e.cost+h[src]-h[e.dst];\n\
    \  }\n\n  void dijkstra(int s){\n    struct P{\n      Cost first;\n      int second;\n\
    \      P(Cost first,int second):first(first),second(second){}\n      bool operator<(const\
    \ P&a) const{return first>a.first;}\n    };\n    priority_queue<P> pq;\n\n   \
    \ dist[s]=0;\n    pq.emplace(dist[s],s);\n    while(!pq.empty()){\n      P p=pq.top();pq.pop();\n\
    \      int v=p.second;\n      if(dist[v]<p.first) continue;\n      for(int i=0;i<(int)G[v].size();i++){\n\
    \        Edge &e=G[v][i];\n        if(e.cap==0) continue;\n        if(!(dist[v]+residual_cost(v,e)<dist[e.dst]))\
    \ continue;\n        dist[e.dst]=dist[v]+e.cost+h[v]-h[e.dst];\n        prevv[e.dst]=v;\n\
    \        preve[e.dst]=i;\n        pq.emplace(dist[e.dst],e.dst);\n      }\n  \
    \  }\n  }\n\n  Cost res;\n\n  bool build(int s,int t,Flow f,\n             function<void(decltype(h)&)>\
    \ init=[](decltype(h) &p){\n               fill(p.begin(),p.end(),0);\n      \
    \       }){\n    res=0;\n    init(h);\n    const Cost INF = numeric_limits<Cost>::max();\n\
    \    while(f>0){\n      fill(dist.begin(),dist.end(),INF);\n      dijkstra(s);\n\
    \      if(dist[t]==INF) return false;\n\n      for(int v=0;v<(int)h.size();v++)\n\
    \        if(dist[v]<INF) h[v]=h[v]+dist[v];\n\n      Flow d=f;\n      for(int\
    \ v=t;v!=s;v=prevv[v])\n        d=min(d,G[prevv[v]][preve[v]].cap);\n\n      f-=d;\n\
    \      res=res+h[t]*d;\n      for(int v=t;v!=s;v=prevv[v]){\n        Edge &e=G[prevv[v]][preve[v]];\n\
    \        e.cap-=d;\n        G[v][e.rev].cap+=d;\n      }\n    }\n    return true;\n\
    \  }\n\n  Cost get_cost(){return res;}\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\n// O(F E \\log V)\ntemplate<typename Flow, typename Cost>\n\
    struct PrimalDual{\n  struct Edge{\n    int dst;\n    Flow cap;\n    Cost cost;\n\
    \    int rev;\n    Edge(int dst,Flow cap,Cost cost,int rev):\n      dst(dst),cap(cap),cost(cost),rev(rev){}\n\
    \  };\n\n  vector<vector<Edge>> G;\n  vector<Cost> h,dist;\n  vector<int> prevv,preve;\n\
    \n  PrimalDual(int n):G(n),h(n),dist(n),prevv(n),preve(n){}\n\n  void add_edge(int\
    \ u,int v,Flow cap,Cost cost){\n    int e=G[u].size();\n    int r=(u==v?e+1:G[v].size());\n\
    \    G[u].emplace_back(v,cap,cost,r);\n    G[v].emplace_back(u,0,-cost,e);\n \
    \ }\n\n  Cost residual_cost(int src,Edge &e){\n    return e.cost+h[src]-h[e.dst];\n\
    \  }\n\n  void dijkstra(int s){\n    struct P{\n      Cost first;\n      int second;\n\
    \      P(Cost first,int second):first(first),second(second){}\n      bool operator<(const\
    \ P&a) const{return first>a.first;}\n    };\n    priority_queue<P> pq;\n\n   \
    \ dist[s]=0;\n    pq.emplace(dist[s],s);\n    while(!pq.empty()){\n      P p=pq.top();pq.pop();\n\
    \      int v=p.second;\n      if(dist[v]<p.first) continue;\n      for(int i=0;i<(int)G[v].size();i++){\n\
    \        Edge &e=G[v][i];\n        if(e.cap==0) continue;\n        if(!(dist[v]+residual_cost(v,e)<dist[e.dst]))\
    \ continue;\n        dist[e.dst]=dist[v]+e.cost+h[v]-h[e.dst];\n        prevv[e.dst]=v;\n\
    \        preve[e.dst]=i;\n        pq.emplace(dist[e.dst],e.dst);\n      }\n  \
    \  }\n  }\n\n  Cost res;\n\n  bool build(int s,int t,Flow f,\n             function<void(decltype(h)&)>\
    \ init=[](decltype(h) &p){\n               fill(p.begin(),p.end(),0);\n      \
    \       }){\n    res=0;\n    init(h);\n    const Cost INF = numeric_limits<Cost>::max();\n\
    \    while(f>0){\n      fill(dist.begin(),dist.end(),INF);\n      dijkstra(s);\n\
    \      if(dist[t]==INF) return false;\n\n      for(int v=0;v<(int)h.size();v++)\n\
    \        if(dist[v]<INF) h[v]=h[v]+dist[v];\n\n      Flow d=f;\n      for(int\
    \ v=t;v!=s;v=prevv[v])\n        d=min(d,G[prevv[v]][preve[v]].cap);\n\n      f-=d;\n\
    \      res=res+h[t]*d;\n      for(int v=t;v!=s;v=prevv[v]){\n        Edge &e=G[prevv[v]][preve[v]];\n\
    \        e.cap-=d;\n        G[v][e.rev].cap+=d;\n      }\n    }\n    return true;\n\
    \  }\n\n  Cost get_cost(){return res;}\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: mincostflow/primaldual.cpp
  requiredBy:
  - mincostflow/negativeedge.cpp
  timestamp: '2020-10-06 13:10:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_6_B.test.cpp
  - test/aoj/2736.test.cpp
  - test/aoj/2627.test.cpp
  - test/aoj/2679.test.cpp
  - test/aoj/2290.test.cpp
documentation_of: mincostflow/primaldual.cpp
layout: document
title: "\u6700\u5C0F\u8CBB\u7528\u6D41"
---

## 解説記事
[最小費用流の双対について](https://beet-aizu.hatenablog.com/entry/2019/10/20/150649)
