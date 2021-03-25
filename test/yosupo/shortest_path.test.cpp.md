---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.cpp
    title: graph/dijkstra.cpp
  - icon: ':question:'
    path: tools/drop.cpp
    title: tools/drop.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/yosupo/shortest_path.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/shortest_path\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"tools/drop.cpp\"\n\n\
    #line 3 \"tools/drop.cpp\"\nusing namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename\
    \ T> void drop(const T &x){cout<<x<<endl;exit(0);}\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n#line 1 \"graph/dijkstra.cpp\"\
    \n\n#line 3 \"graph/dijkstra.cpp\"\nusing namespace std;\n#endif\n//BEGIN CUT\
    \ HERE\ntemplate<typename T>\nstruct Dijkstra{\n  struct Edge{\n    int to;\n\
    \    T cost;\n    Edge(int to,T cost):to(to),cost(cost){}\n    bool operator<(const\
    \ Edge &o)const{return cost>o.cost;}\n  };\n\n  vector< vector<Edge> > G;\n  vector<T>\
    \ ds;\n  vector<int> bs;\n  Dijkstra(int n):G(n){}\n\n  void add_edge(int u,int\
    \ v,T c){\n    G[u].emplace_back(v,c);\n  }\n\n  void build(int s){\n    int n=G.size();\n\
    \    ds.assign(n,numeric_limits<T>::max());\n    bs.assign(n,-1);\n\n    priority_queue<Edge>\
    \ pq;\n    ds[s]=0;\n    pq.emplace(s,ds[s]);\n\n    while(!pq.empty()){\n   \
    \   auto p=pq.top();pq.pop();\n      int v=p.to;\n      if(ds[v]<p.cost) continue;\n\
    \      for(auto e:G[v]){\n        if(ds[e.to]>ds[v]+e.cost){\n          ds[e.to]=ds[v]+e.cost;\n\
    \          bs[e.to]=v;\n          pq.emplace(e.to,ds[e.to]);\n        }\n    \
    \  }\n    }\n  }\n\n  T operator[](int k){return ds[k];}\n\n  vector<int> restore(int\
    \ to){\n    vector<int> res;\n    if(bs[to]<0) return res;\n    while(~to) res.emplace_back(to),to=bs[to];\n\
    \    reverse(res.begin(),res.end());\n    return res;\n  }\n};\n//END CUT HERE\n\
    #ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n#line 9 \"test/yosupo/shortest_path.test.cpp\"\
    \n#undef call_from_test\n\n#ifdef SANITIZE\n#define IGNORE\n#endif\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n  const char newl = '\\n';\n\n  int\
    \ n,m,s,t;\n  cin>>n>>m>>s>>t;\n\n  using ll = long long;\n  Dijkstra<ll> G(n);\n\
    \  for(int i=0;i<m;i++){\n    int a,b,c;\n    cin>>a>>b>>c;\n    G.add_edge(a,b,c);\n\
    \  }\n\n  G.build(s);\n  auto ps=G.restore(t);\n  if(ps.empty()) drop(-1);\n\n\
    \  int y=ps.size()-1;\n  cout<<G[t]<<' '<<y<<newl;\n  for(int i=0;i<y;i++) cout<<ps[i]<<'\
    \ '<<ps[i+1]<<newl;\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include \"\
    ../../tools/drop.cpp\"\n#include \"../../graph/dijkstra.cpp\"\n#undef call_from_test\n\
    \n#ifdef SANITIZE\n#define IGNORE\n#endif\n\nsigned main(){\n  cin.tie(0);\n \
    \ ios::sync_with_stdio(0);\n  const char newl = '\\n';\n\n  int n,m,s,t;\n  cin>>n>>m>>s>>t;\n\
    \n  using ll = long long;\n  Dijkstra<ll> G(n);\n  for(int i=0;i<m;i++){\n   \
    \ int a,b,c;\n    cin>>a>>b>>c;\n    G.add_edge(a,b,c);\n  }\n\n  G.build(s);\n\
    \  auto ps=G.restore(t);\n  if(ps.empty()) drop(-1);\n\n  int y=ps.size()-1;\n\
    \  cout<<G[t]<<' '<<y<<newl;\n  for(int i=0;i<y;i++) cout<<ps[i]<<' '<<ps[i+1]<<newl;\n\
    \  return 0;\n}\n"
  dependsOn:
  - tools/drop.cpp
  - graph/dijkstra.cpp
  isVerificationFile: true
  path: test/yosupo/shortest_path.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 18:28:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/shortest_path.test.cpp
- /verify/test/yosupo/shortest_path.test.cpp.html
title: test/yosupo/shortest_path.test.cpp
---
