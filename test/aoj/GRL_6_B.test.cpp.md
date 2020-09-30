---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mincostflow/primaldual.cpp
    title: Primal Dual
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
  bundledCode: "#line 1 \"test/aoj/GRL_6_B.test.cpp\"\n// verification-helper: PROBLEM\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"mincostflow/primaldual.cpp\"\
    \n\n#line 3 \"mincostflow/primaldual.cpp\"\nusing namespace std;\n#endif\n//BEGIN\
    \ CUT HERE\n// O(F E \\log V)\ntemplate<typename Flow, typename Cost>\nstruct\
    \ PrimalDual{\n  struct Edge{\n    int dst;\n    Flow cap;\n    Cost cost;\n \
    \   int rev;\n    Edge(int dst,Flow cap,Cost cost,int rev):\n      dst(dst),cap(cap),cost(cost),rev(rev){}\n\
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
    \        Edge &e=G[v][i];\n        if(e.cap==0) continue;\n        if(dist[v]+residual_cost(v,e)<dist[e.dst]){\n\
    \          dist[e.dst]=dist[v]+e.cost+h[v]-h[e.dst];\n          prevv[e.dst]=v;\n\
    \          preve[e.dst]=i;\n          pq.emplace(dist[e.dst],e.dst);\n       \
    \ }\n      }\n    }\n  }\n\n  Cost res;\n\n  bool build(int s,int t,Flow f,\n\
    \             function<void(decltype(h)&)> init=[](decltype(h) &p){\n        \
    \       fill(p.begin(),p.end(),0);\n             }){\n    res=0;\n    init(h);\n\
    \    const Cost INF = numeric_limits<Cost>::max();\n    while(f>0){\n      fill(dist.begin(),dist.end(),INF);\n\
    \      dijkstra(s);\n      if(dist[t]==INF) return false;\n\n      for(int v=0;v<(int)h.size();v++)\n\
    \        if(dist[v]<INF) h[v]=h[v]+dist[v];\n\n      Flow d=f;\n      for(int\
    \ v=t;v!=s;v=prevv[v])\n        d=min(d,G[prevv[v]][preve[v]].cap);\n\n      f-=d;\n\
    \      res=res+h[t]*d;\n      for(int v=t;v!=s;v=prevv[v]){\n        Edge &e=G[prevv[v]][preve[v]];\n\
    \        e.cap-=d;\n        G[v][e.rev].cap+=d;\n      }\n    }\n    return true;\n\
    \  }\n\n  Cost get_cost(){return res;}\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n#line 8 \"test/aoj/GRL_6_B.test.cpp\"\
    \n#undef call_from_test\n\nint main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int v,e,f;\n  cin>>v>>e>>f;\n\n  PrimalDual<int, int> G(v);\n  for(int i=0;i<e;i++){\n\
    \    int u,v,c,d;\n    cin>>u>>v>>c>>d;\n    G.add_edge(u,v,c,d);\n  }\n\n  if(!G.build(0,v-1,f))\n\
    \    cout<<-1<<endl;\n  else\n    cout<<G.get_cost()<<endl;\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../mincostflow/primaldual.cpp\"\n#undef call_from_test\n\nint main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int v,e,f;\n  cin>>v>>e>>f;\n\n\
    \  PrimalDual<int, int> G(v);\n  for(int i=0;i<e;i++){\n    int u,v,c,d;\n   \
    \ cin>>u>>v>>c>>d;\n    G.add_edge(u,v,c,d);\n  }\n\n  if(!G.build(0,v-1,f))\n\
    \    cout<<-1<<endl;\n  else\n    cout<<G.get_cost()<<endl;\n  return 0;\n}\n"
  dependsOn:
  - mincostflow/primaldual.cpp
  isVerificationFile: true
  path: test/aoj/GRL_6_B.test.cpp
  requiredBy: []
  timestamp: '2020-09-30 12:54:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_6_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_B.test.cpp
- /verify/test/aoj/GRL_6_B.test.cpp.html
title: test/aoj/GRL_6_B.test.cpp
---