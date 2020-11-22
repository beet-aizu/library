---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2230.test.cpp
    title: test/aoj/2230.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2872.test.cpp
    title: test/aoj/2872.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/assignment.test.cpp
    title: test/yosupo/assignment.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/min_cost_b_flow.test.cpp
    title: test/yosupo/min_cost_b_flow.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"bflow/capacityscaling.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\n// O(m^2 \\log m \\log U)\n//\
    \ U: maximum capacity\nenum Objective{\n  MINIMIZE = +1,\n  MAXIMIZE = -1,\n};\n\
    template<typename Flow, typename Cost,\n         Objective objective = Objective::MINIMIZE>\n\
    struct MinCostFlow{\n  template<typename T> inline void chmin(T &x,T y){x=min(x,y);}\n\
    \n  struct Edge{\n    int src,dst;\n    Flow flow,cap;\n    Cost cost;\n    int\
    \ rev;\n    Edge(int src,int dst,Flow cap,Cost cost,int rev):\n      src(src),dst(dst),flow(0),cap(cap),cost(cost),rev(rev){}\n\
    \    Flow residual_cap()const{return cap-flow;}\n  };\n\n  struct EdgePtr{\n \
    \   int v,e;\n    EdgePtr(int v,int e):v(v),e(e){}\n  };\n\n  int n;\n  vector<vector<Edge>>\
    \ G;\n  vector<Flow> b;\n  vector<Cost> p;\n\n  MinCostFlow(int n):n(n),G(n),b(n,0){}\n\
    \n  EdgePtr add_edge(int src,int dst,Flow lower,Flow upper,Cost cost){\n    int\
    \ e=G[src].size();\n    int r=(src==dst?e+1:G[dst].size());\n    assert(lower<=upper);\n\
    \    G[src].emplace_back(src,dst,+upper,+cost*objective,r);\n    G[dst].emplace_back(dst,src,-lower,-cost*objective,e);\n\
    \    return EdgePtr(src,e);\n  }\n\n  const Edge &get_edge(EdgePtr ep)const{return\
    \ G[ep.v][ep.e];}\n\n  void push(Edge &e,Flow amount){\n    e.flow+=amount;\n\
    \    G[e.dst][e.rev].flow-=amount;\n  }\n\n  void add_supply(int v,Flow amount){b[v]+=amount;}\n\
    \  void add_demand(int v,Flow amount){b[v]-=amount;}\n\n  Cost residual_cost(const\
    \ Edge &e){\n    return e.cost+p[e.src]-p[e.dst];\n  }\n\n  vector<int> excess_vs,deficit_vs;\n\
    \  void saturate_negative(const Flow delta){\n    for(auto &es:G){\n      for(auto\
    \ &e:es){\n        Flow cap=e.residual_cap();\n        cap-=cap%delta;\n     \
    \   if(cap<0 or residual_cost(e)<0){\n          push(e,cap);\n          b[e.src]-=cap;\n\
    \          b[e.dst]+=cap;\n        }\n      }\n    }\n\n    excess_vs.clear();\n\
    \    deficit_vs.clear();\n    for(int v=0;v<n;v++){\n      if(b[v]>0) excess_vs.emplace_back(v);\n\
    \      if(b[v]<0) deficit_vs.emplace_back(v);\n    }\n  }\n\n  const Cost unreachable\
    \ = std::numeric_limits<Cost>::max();\n  Cost farthest;\n  vector<Cost> dist;\n\
    \  vector<Edge*> parent;\n\n  struct P{\n    Cost first;\n    int second;\n  \
    \  P(Cost first,int second):first(first),second(second){}\n    bool operator<(const\
    \ P o)const{return first>o.first;}\n  };\n\n  priority_queue<P> pq;\n\n  template<typename\
    \ Predicate>\n  void eliminate(vector<int> &vs,Predicate predicate){\n    vs.erase(remove_if(begin(vs),end(vs),predicate),end(vs));\n\
    \  }\n\n  bool dual(const Flow delta){\n    eliminate(excess_vs, [&](int v){return\
    \ b[v]<+delta;});\n    eliminate(deficit_vs,[&](int v){return b[v]>-delta;});\n\
    \n    dist.assign(n,unreachable);\n    for(int v:excess_vs) pq.emplace(dist[v]=0,v);\n\
    \n    parent.assign(n,nullptr);\n    auto emplace=[&](Edge& e){\n      if(e.residual_cap()<delta)\
    \ return;\n      Cost nxt=dist[e.src]+residual_cost(e);\n      if(nxt>=dist[e.dst])\
    \ return;\n      pq.emplace(dist[e.dst]=nxt,e.dst);\n      parent[e.dst]=&e;\n\
    \    };\n\n    farthest=0;\n    int deficit_count=0;\n    while(!pq.empty()){\n\
    \      Cost d=pq.top().first;\n      int v=pq.top().second;\n      pq.pop();\n\
    \      if(dist[v]<d) continue;\n      farthest=d;\n\n      if(b[v]<=-delta) deficit_count++;\n\
    \      if(deficit_count>=(int)deficit_vs.size()) break;\n\n      for(auto &e:G[v])\
    \ emplace(e);\n    }\n    pq=decltype(pq)();\n\n    for(int v=0;v<n;v++)\n   \
    \   p[v]+=min(dist[v],farthest);\n\n    return deficit_count>0;\n  }\n\n  void\
    \ primal(const Flow delta){\n    for(int t:deficit_vs){\n      if(dist[t]>farthest)\
    \ continue;\n      Flow f=-b[t];\n      int v;\n      for(v=t;parent[v];v=parent[v]->src)\n\
    \        chmin(f,parent[v]->residual_cap());\n      chmin(f,b[v]);\n\n      f-=f%delta;\n\
    \      if(f<=0) continue;\n\n      for(v=t;parent[v];){\n        auto &e=*parent[v];\n\
    \        push(e,f);\n        int u=parent[v]->src;\n        if(e.residual_cap()<=0)\
    \ parent[v]=nullptr;\n        v=u;\n      }\n      b[t]+=f;\n      b[v]-=f;\n\
    \    }\n  }\n\n  template<Flow SCALING_FACTOR=2>\n  bool build(){\n    p.resize(n);\n\
    \    Flow max_flow=1;\n    for(auto t:b) max_flow=max({max_flow,t,-t});\n    for(auto\
    \ &es:G)\n      for(auto &e:es)\n        max_flow=max({max_flow,e.residual_cap(),-e.residual_cap()});\n\
    \n    Flow delta=1;\n    while(delta<max_flow) delta*=SCALING_FACTOR;\n    for(;delta;delta/=SCALING_FACTOR){\n\
    \      saturate_negative(delta);\n      while(dual(delta)) primal(delta);\n  \
    \  }\n\n    return excess_vs.empty() and deficit_vs.empty();\n  }\n\n  template<typename\
    \ T=Cost>\n  T get_cost(){\n    T res=0;\n    for(auto &es:G)\n      for(auto\
    \ &e:es)\n        res+=T(e.flow)*T(e.cost)/T(objective);\n    return res/T(2);\n\
    \  }\n  template<typename T=Cost> T get_gain(){return get_cost();}\n\n  vector<Cost>\
    \ get_potential(){\n    fill(p.begin(),p.end(),0);\n    for(int i=0;i<n;i++)\n\
    \      for(auto &es:G)\n        for(auto &e:es)\n          if(e.residual_cap()>0)\n\
    \            chmin(p[e.dst],p[e.src]+e.cost);\n    return p;\n  }\n};\n\ntemplate<typename\
    \ Flow, typename Cost>\nusing MaxGainFlow = MinCostFlow<Flow, Cost, Objective::MAXIMIZE>;\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\n// O(m^2 \\log m \\log U)\n// U: maximum capacity\n\
    enum Objective{\n  MINIMIZE = +1,\n  MAXIMIZE = -1,\n};\ntemplate<typename Flow,\
    \ typename Cost,\n         Objective objective = Objective::MINIMIZE>\nstruct\
    \ MinCostFlow{\n  template<typename T> inline void chmin(T &x,T y){x=min(x,y);}\n\
    \n  struct Edge{\n    int src,dst;\n    Flow flow,cap;\n    Cost cost;\n    int\
    \ rev;\n    Edge(int src,int dst,Flow cap,Cost cost,int rev):\n      src(src),dst(dst),flow(0),cap(cap),cost(cost),rev(rev){}\n\
    \    Flow residual_cap()const{return cap-flow;}\n  };\n\n  struct EdgePtr{\n \
    \   int v,e;\n    EdgePtr(int v,int e):v(v),e(e){}\n  };\n\n  int n;\n  vector<vector<Edge>>\
    \ G;\n  vector<Flow> b;\n  vector<Cost> p;\n\n  MinCostFlow(int n):n(n),G(n),b(n,0){}\n\
    \n  EdgePtr add_edge(int src,int dst,Flow lower,Flow upper,Cost cost){\n    int\
    \ e=G[src].size();\n    int r=(src==dst?e+1:G[dst].size());\n    assert(lower<=upper);\n\
    \    G[src].emplace_back(src,dst,+upper,+cost*objective,r);\n    G[dst].emplace_back(dst,src,-lower,-cost*objective,e);\n\
    \    return EdgePtr(src,e);\n  }\n\n  const Edge &get_edge(EdgePtr ep)const{return\
    \ G[ep.v][ep.e];}\n\n  void push(Edge &e,Flow amount){\n    e.flow+=amount;\n\
    \    G[e.dst][e.rev].flow-=amount;\n  }\n\n  void add_supply(int v,Flow amount){b[v]+=amount;}\n\
    \  void add_demand(int v,Flow amount){b[v]-=amount;}\n\n  Cost residual_cost(const\
    \ Edge &e){\n    return e.cost+p[e.src]-p[e.dst];\n  }\n\n  vector<int> excess_vs,deficit_vs;\n\
    \  void saturate_negative(const Flow delta){\n    for(auto &es:G){\n      for(auto\
    \ &e:es){\n        Flow cap=e.residual_cap();\n        cap-=cap%delta;\n     \
    \   if(cap<0 or residual_cost(e)<0){\n          push(e,cap);\n          b[e.src]-=cap;\n\
    \          b[e.dst]+=cap;\n        }\n      }\n    }\n\n    excess_vs.clear();\n\
    \    deficit_vs.clear();\n    for(int v=0;v<n;v++){\n      if(b[v]>0) excess_vs.emplace_back(v);\n\
    \      if(b[v]<0) deficit_vs.emplace_back(v);\n    }\n  }\n\n  const Cost unreachable\
    \ = std::numeric_limits<Cost>::max();\n  Cost farthest;\n  vector<Cost> dist;\n\
    \  vector<Edge*> parent;\n\n  struct P{\n    Cost first;\n    int second;\n  \
    \  P(Cost first,int second):first(first),second(second){}\n    bool operator<(const\
    \ P o)const{return first>o.first;}\n  };\n\n  priority_queue<P> pq;\n\n  template<typename\
    \ Predicate>\n  void eliminate(vector<int> &vs,Predicate predicate){\n    vs.erase(remove_if(begin(vs),end(vs),predicate),end(vs));\n\
    \  }\n\n  bool dual(const Flow delta){\n    eliminate(excess_vs, [&](int v){return\
    \ b[v]<+delta;});\n    eliminate(deficit_vs,[&](int v){return b[v]>-delta;});\n\
    \n    dist.assign(n,unreachable);\n    for(int v:excess_vs) pq.emplace(dist[v]=0,v);\n\
    \n    parent.assign(n,nullptr);\n    auto emplace=[&](Edge& e){\n      if(e.residual_cap()<delta)\
    \ return;\n      Cost nxt=dist[e.src]+residual_cost(e);\n      if(nxt>=dist[e.dst])\
    \ return;\n      pq.emplace(dist[e.dst]=nxt,e.dst);\n      parent[e.dst]=&e;\n\
    \    };\n\n    farthest=0;\n    int deficit_count=0;\n    while(!pq.empty()){\n\
    \      Cost d=pq.top().first;\n      int v=pq.top().second;\n      pq.pop();\n\
    \      if(dist[v]<d) continue;\n      farthest=d;\n\n      if(b[v]<=-delta) deficit_count++;\n\
    \      if(deficit_count>=(int)deficit_vs.size()) break;\n\n      for(auto &e:G[v])\
    \ emplace(e);\n    }\n    pq=decltype(pq)();\n\n    for(int v=0;v<n;v++)\n   \
    \   p[v]+=min(dist[v],farthest);\n\n    return deficit_count>0;\n  }\n\n  void\
    \ primal(const Flow delta){\n    for(int t:deficit_vs){\n      if(dist[t]>farthest)\
    \ continue;\n      Flow f=-b[t];\n      int v;\n      for(v=t;parent[v];v=parent[v]->src)\n\
    \        chmin(f,parent[v]->residual_cap());\n      chmin(f,b[v]);\n\n      f-=f%delta;\n\
    \      if(f<=0) continue;\n\n      for(v=t;parent[v];){\n        auto &e=*parent[v];\n\
    \        push(e,f);\n        int u=parent[v]->src;\n        if(e.residual_cap()<=0)\
    \ parent[v]=nullptr;\n        v=u;\n      }\n      b[t]+=f;\n      b[v]-=f;\n\
    \    }\n  }\n\n  template<Flow SCALING_FACTOR=2>\n  bool build(){\n    p.resize(n);\n\
    \    Flow max_flow=1;\n    for(auto t:b) max_flow=max({max_flow,t,-t});\n    for(auto\
    \ &es:G)\n      for(auto &e:es)\n        max_flow=max({max_flow,e.residual_cap(),-e.residual_cap()});\n\
    \n    Flow delta=1;\n    while(delta<max_flow) delta*=SCALING_FACTOR;\n    for(;delta;delta/=SCALING_FACTOR){\n\
    \      saturate_negative(delta);\n      while(dual(delta)) primal(delta);\n  \
    \  }\n\n    return excess_vs.empty() and deficit_vs.empty();\n  }\n\n  template<typename\
    \ T=Cost>\n  T get_cost(){\n    T res=0;\n    for(auto &es:G)\n      for(auto\
    \ &e:es)\n        res+=T(e.flow)*T(e.cost)/T(objective);\n    return res/T(2);\n\
    \  }\n  template<typename T=Cost> T get_gain(){return get_cost();}\n\n  vector<Cost>\
    \ get_potential(){\n    fill(p.begin(),p.end(),0);\n    for(int i=0;i<n;i++)\n\
    \      for(auto &es:G)\n        for(auto &e:es)\n          if(e.residual_cap()>0)\n\
    \            chmin(p[e.dst],p[e.src]+e.cost);\n    return p;\n  }\n};\n\ntemplate<typename\
    \ Flow, typename Cost>\nusing MaxGainFlow = MinCostFlow<Flow, Cost, Objective::MAXIMIZE>;\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: bflow/capacityscaling.cpp
  requiredBy: []
  timestamp: '2020-10-27 16:41:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2872.test.cpp
  - test/aoj/2230.test.cpp
  - test/yosupo/min_cost_b_flow.test.cpp
  - test/yosupo/assignment.test.cpp
documentation_of: bflow/capacityscaling.cpp
layout: document
title: Minimum Cost Flow with Capacity Scaling
---

## `INF` の決め方
### 上限
`m * INF` がオーバーフローすると死ぬことがある
### 下限
`max - INF < min` を満たしていないと区別できない
### 結論
`max - min < INF < 2^w / m`

`w` はビット幅

## 解説記事
[Are there any learning materials of polynomial minimum cost flow algorithms?](https://codeforces.com/blog/entry/70740)

[ぼくの考えたさいきょうのフローライブラリ](http://misawa.github.io/others/flow/library_design.html)

[最小費用流の双対について](https://beet-aizu.hatenablog.com/entry/2019/10/20/150649)

[b-flow と双対](https://beet-aizu.hatenablog.com/entry/2020/09/24/152856)
