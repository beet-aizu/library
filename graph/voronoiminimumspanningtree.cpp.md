---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.cpp
    title: graph/kruskal.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/cf17-final/tasks/cf17_final_j
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/voronoiminimumspanningtree.cpp: line 63: unable to process #include in\
    \ #if / #ifdef / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct VoronoiMST{\n  int n;\n\
    \  using E = pair<int, T>;\n  using P = pair<T, int>;\n  vector<vector<E> > G;\n\
    \  VoronoiMST(vector<T> &x){\n    n=x.size();\n    G.assign(n<<1,vector<E>());\n\
    \    for(int i=0;i<n;i++) G[i].emplace_back(n+i,x[i]);\n  }\n  void add_edge(int\
    \ u,int v,T c){\n    G[u+n].emplace_back(v+n,c);\n    G[v+n].emplace_back(u+n,c);\n\
    \  }\n  vector<vector<E> > build(){\n    priority_queue<P, vector<P>, greater<P>\
    \ > pq;\n    const T INF = numeric_limits<T>::max();\n    vector<T> dist(n<<1,INF);\n\
    \    vector<int> from(n<<1,-1);\n    for(int i=0;i<n;i++){\n      dist[i]=0;from[i]=i;\n\
    \      pq.emplace(dist[i],i);\n    }\n    while(!pq.empty()){\n      T d;\n  \
    \    int v;\n      tie(d,v)=pq.top();pq.pop();\n      if(dist[v]<d) continue;\n\
    \      for(E e:G[v]){\n        int u=e.first;\n        T c=e.second;\n       \
    \ if(dist[u]<=dist[v]+c) continue;\n        dist[u]=dist[v]+c;\n        from[u]=from[v];\n\
    \        pq.emplace(dist[u],u);\n      }\n    }\n    vector<vector<E> > H(n);\n\
    \    for(int v=0;v<(n<<1);v++){\n      for(E e:G[v]){\n        int u=e.first;\n\
    \        T c=e.second;\n        if(from[v]==from[u]) continue;\n        int x=from[v],y=from[u];\n\
    \        T z=dist[v]+dist[u]+c;\n        H[x].emplace_back(y,z);\n        H[y].emplace_back(x,z);\n\
    \      }\n    }\n    return H;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    \n#define call_from_test\n#include \"kruskal.cpp\"\n#undef call_from_test\n\n\
    //INSERT ABOVE HERE\nsigned CF17FINAL_J(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  using ll = long long;\n  int n;\n  cin>>n;\n  vector<ll> x(n);\n  for(int\
    \ i=0;i<n;i++) cin>>x[i];\n  VoronoiMST<ll> vo(x);\n  for(int i=1;i<n;i++){\n\
    \    int a,b,c;\n    cin>>a>>b>>c;\n    a--;b--;\n    vo.add_edge(a,b,c);\n  }\n\
    \  auto G=vo.build();\n  Kruskal<ll> ks(n);\n  for(int v=0;v<n;v++){\n    for(auto\
    \ e:G[v]){\n      int u=e.first;\n      ll c=e.second;\n      if(v<u) ks.add_edge(v,u,c);\n\
    \    }\n  }\n  cout<<ks.build()<<endl;\n  return 0;\n}\n/*\n  verified on 2020/05/07\n\
    \  https://atcoder.jp/contests/cf17-final/tasks/cf17_final_j\n*/\nsigned main(){\n\
    \  CF17FINAL_J();\n  return 0;\n}\n#endif\n"
  dependsOn:
  - graph/kruskal.cpp
  isVerificationFile: false
  path: graph/voronoiminimumspanningtree.cpp
  requiredBy: []
  timestamp: '2020-10-27 16:52:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/voronoiminimumspanningtree.cpp
layout: document
redirect_from:
- /library/graph/voronoiminimumspanningtree.cpp
- /library/graph/voronoiminimumspanningtree.cpp.html
title: graph/voronoiminimumspanningtree.cpp
---
