---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2235.test.cpp
    title: test/aoj/2235.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/dynamicconnectivity.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\nstruct PersistentUnionFind{\n\
    \  using T = pair<int, int>;\n  vector<int> rs,ps;\n  stack<T> st;\n  PersistentUnionFind(){}\n\
    \  PersistentUnionFind(int n):\n    rs(n,1),ps(n,0){iota(ps.begin(),ps.end(),0);}\n\
    \  int find(int x){\n    return x==ps[x]?ps[x]:find(ps[x]);\n  }\n  bool same(int\
    \ x,int y){\n    return find(x)==find(y);\n  }\n  void unite(int x,int y){\n \
    \   x=find(x);y=find(y);\n    st.emplace(-1,-1);\n    if(x==y) return;\n    if(rs[x]<rs[y])\
    \ swap(x,y);\n    rs[x]+=rs[y];\n    ps[y]=x;\n    st.top()=T(x,y);\n  }\n  void\
    \ undo(int t=1){\n    for(int i=0;i<t;i++){\n      int x,y;\n      tie(x,y)=st.top();st.pop();\n\
    \      if(x<0) continue;\n      rs[x]-=rs[y];\n      ps[y]=y;\n    }\n  }\n};\n\
    \nstruct DynamicConnectivity{\n  using edge = pair<int, int>;\n  using range =\
    \ pair<int, int>;\n\n  int q;\n  PersistentUnionFind puf;\n  vector< vector<edge>\
    \ > edges;\n  vector <pair<range, edge> > prc;\n  map<edge, int> cnt,app;\n\n\
    \  DynamicConnectivity(){}\n  DynamicConnectivity(int n,int q_):q(1),puf(n){\n\
    \    while(q<q_) q<<=1;\n    edges.resize(q*2);\n  }\n\n  void insert(int t,int\
    \ u,int v){\n    edge e=minmax(u,v);\n    if(cnt[e]++==0) app[e]=t;\n  }\n\n \
    \ void erase(int t,int u,int v){\n    edge e=minmax(u,v);\n    if(--cnt[e]==0)\
    \ prc.emplace_back(range(app[e],t),e);\n  }\n\n  void add(int a,int b,edge e,int\
    \ k,int l,int r){\n    if(r<=a or b<=l) return;\n    if(a<=l and r<=b){\n    \
    \  edges[k].emplace_back(e);\n      return;\n    }\n    int m=(l+r)>>1;\n    add(a,b,e,(k<<1)|0,l,m);\n\
    \    add(a,b,e,(k<<1)|1,m,r);\n  }\n\n  void add(range r,edge e){\n    add(r.first,r.second,e,1,0,q);\n\
    \  }\n\n  void build(){\n    for(auto &e:cnt){\n      if(!e.second) continue;\n\
    \      prc.emplace_back(range(app[e.first],q),e.first);\n    }\n    for(auto &s:prc)\n\
    \      add(s.first,s.second);\n  }\n\n  template<typename F>\n  void exec(const\
    \ F &f,int k=1){\n    for(auto &e:edges[k])\n      puf.unite(e.first,e.second);\n\
    \n    if(k<q){\n      exec(f,(k<<1)|0);\n      exec(f,(k<<1)|1);\n    }else{\n\
    \      f(k-q);\n    }\n\n    puf.undo(edges[k].size());\n  }\n};\n//END CUT HERE\n\
    #ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\nstruct PersistentUnionFind{\n  using T = pair<int, int>;\n\
    \  vector<int> rs,ps;\n  stack<T> st;\n  PersistentUnionFind(){}\n  PersistentUnionFind(int\
    \ n):\n    rs(n,1),ps(n,0){iota(ps.begin(),ps.end(),0);}\n  int find(int x){\n\
    \    return x==ps[x]?ps[x]:find(ps[x]);\n  }\n  bool same(int x,int y){\n    return\
    \ find(x)==find(y);\n  }\n  void unite(int x,int y){\n    x=find(x);y=find(y);\n\
    \    st.emplace(-1,-1);\n    if(x==y) return;\n    if(rs[x]<rs[y]) swap(x,y);\n\
    \    rs[x]+=rs[y];\n    ps[y]=x;\n    st.top()=T(x,y);\n  }\n  void undo(int t=1){\n\
    \    for(int i=0;i<t;i++){\n      int x,y;\n      tie(x,y)=st.top();st.pop();\n\
    \      if(x<0) continue;\n      rs[x]-=rs[y];\n      ps[y]=y;\n    }\n  }\n};\n\
    \nstruct DynamicConnectivity{\n  using edge = pair<int, int>;\n  using range =\
    \ pair<int, int>;\n\n  int q;\n  PersistentUnionFind puf;\n  vector< vector<edge>\
    \ > edges;\n  vector <pair<range, edge> > prc;\n  map<edge, int> cnt,app;\n\n\
    \  DynamicConnectivity(){}\n  DynamicConnectivity(int n,int q_):q(1),puf(n){\n\
    \    while(q<q_) q<<=1;\n    edges.resize(q*2);\n  }\n\n  void insert(int t,int\
    \ u,int v){\n    edge e=minmax(u,v);\n    if(cnt[e]++==0) app[e]=t;\n  }\n\n \
    \ void erase(int t,int u,int v){\n    edge e=minmax(u,v);\n    if(--cnt[e]==0)\
    \ prc.emplace_back(range(app[e],t),e);\n  }\n\n  void add(int a,int b,edge e,int\
    \ k,int l,int r){\n    if(r<=a or b<=l) return;\n    if(a<=l and r<=b){\n    \
    \  edges[k].emplace_back(e);\n      return;\n    }\n    int m=(l+r)>>1;\n    add(a,b,e,(k<<1)|0,l,m);\n\
    \    add(a,b,e,(k<<1)|1,m,r);\n  }\n\n  void add(range r,edge e){\n    add(r.first,r.second,e,1,0,q);\n\
    \  }\n\n  void build(){\n    for(auto &e:cnt){\n      if(!e.second) continue;\n\
    \      prc.emplace_back(range(app[e.first],q),e.first);\n    }\n    for(auto &s:prc)\n\
    \      add(s.first,s.second);\n  }\n\n  template<typename F>\n  void exec(const\
    \ F &f,int k=1){\n    for(auto &e:edges[k])\n      puf.unite(e.first,e.second);\n\
    \n    if(k<q){\n      exec(f,(k<<1)|0);\n      exec(f,(k<<1)|1);\n    }else{\n\
    \      f(k-q);\n    }\n\n    puf.undo(edges[k].size());\n  }\n};\n//END CUT HERE\n\
    #ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dynamicconnectivity.cpp
  requiredBy: []
  timestamp: '2020-10-27 15:54:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2235.test.cpp
documentation_of: graph/dynamicconnectivity.cpp
layout: document
redirect_from:
- /library/graph/dynamicconnectivity.cpp
- /library/graph/dynamicconnectivity.cpp.html
title: graph/dynamicconnectivity.cpp
---
