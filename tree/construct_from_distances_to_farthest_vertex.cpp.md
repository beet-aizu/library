---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"tree/construct_from_distances_to_farthest_vertex.cpp\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#endif\n//BEGIN CUT HERE\nvector<\
    \ vector<int> >\nconstruct_from_distances_to_farthest_vertex(vector<int> ds){\n\
    \  int n=ds.size();\n  vector<vector<int>> G(n),NG;\n  for(int d:ds) if(d>=n)\
    \ return NG;\n\n  vector<int> ts(n,0);\n  vector<queue<int>> qs(n);\n  for(int\
    \ i=0;i<n;i++){\n    ts[ds[i]]++;\n    qs[ds[i]].emplace(i);\n  }\n\n  int dm=*max_element(ds.begin(),ds.end());\n\
    \n  for(int i=0;i<(dm+1)/2;i++)\n    if(ts[dm-i]<2) return NG;\n\n  if(ts[dm/2+(dm&1)]!=1+(dm&1))\
    \ return NG;\n\n  for(int d:ds)\n    if(d<(dm+1)/2) return NG;\n\n  auto add_edge=\n\
    \    [&](int x,int y){\n      G[x].emplace_back(y);\n      G[y].emplace_back(x);\n\
    \    };\n\n  vector<int> xs(n),ys(n);\n  for(int i=0;i<(dm+1)/2;i++){\n    xs[dm-i]=qs[dm-i].front();qs[dm-i].pop();\n\
    \    ys[dm-i]=qs[dm-i].front();qs[dm-i].pop();\n    if(i){\n      add_edge(xs[dm-i+1],xs[dm-i]);\n\
    \      add_edge(ys[dm-i+1],ys[dm-i]);\n    }\n  }\n\n  if(dm&1){\n    add_edge(xs[dm/2+1],ys[dm/2+1]);\n\
    \  }else{\n    xs[dm/2]=qs[dm/2].front();qs[dm/2].pop();\n    add_edge(xs[dm/2+1],xs[dm/2]);\n\
    \    add_edge(ys[dm/2+1],xs[dm/2]);\n  }\n\n  for(int i=0;i<n;i++){\n    if(!G[i].empty())\
    \ continue;\n    add_edge(i,xs[ds[i]-1]);\n  }\n  return G;\n}\n//END CUT HERE\n\
    #ifndef call_from_test\nclass TreeDistanceConstruction {\npublic:\n  vector<int>\
    \ construct(vector<int> ds) {\n    auto G=construct_from_distances_to_farthest_vertex(ds);\n\
    \    if(G.empty()) return {};\n    vector<int> bs;\n    for(int i=0;i<(int)G.size();i++)\n\
    \      for(int j:G[i])\n        if(i<j) bs.emplace_back(i),bs.emplace_back(j);\n\
    \    return bs;\n  }\n};\n/*\n  verified on 2019/12/10\n  https://vjudge.net/problem/TopCoder-14468\n\
    */\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\nvector< vector<int> >\nconstruct_from_distances_to_farthest_vertex(vector<int>\
    \ ds){\n  int n=ds.size();\n  vector<vector<int>> G(n),NG;\n  for(int d:ds) if(d>=n)\
    \ return NG;\n\n  vector<int> ts(n,0);\n  vector<queue<int>> qs(n);\n  for(int\
    \ i=0;i<n;i++){\n    ts[ds[i]]++;\n    qs[ds[i]].emplace(i);\n  }\n\n  int dm=*max_element(ds.begin(),ds.end());\n\
    \n  for(int i=0;i<(dm+1)/2;i++)\n    if(ts[dm-i]<2) return NG;\n\n  if(ts[dm/2+(dm&1)]!=1+(dm&1))\
    \ return NG;\n\n  for(int d:ds)\n    if(d<(dm+1)/2) return NG;\n\n  auto add_edge=\n\
    \    [&](int x,int y){\n      G[x].emplace_back(y);\n      G[y].emplace_back(x);\n\
    \    };\n\n  vector<int> xs(n),ys(n);\n  for(int i=0;i<(dm+1)/2;i++){\n    xs[dm-i]=qs[dm-i].front();qs[dm-i].pop();\n\
    \    ys[dm-i]=qs[dm-i].front();qs[dm-i].pop();\n    if(i){\n      add_edge(xs[dm-i+1],xs[dm-i]);\n\
    \      add_edge(ys[dm-i+1],ys[dm-i]);\n    }\n  }\n\n  if(dm&1){\n    add_edge(xs[dm/2+1],ys[dm/2+1]);\n\
    \  }else{\n    xs[dm/2]=qs[dm/2].front();qs[dm/2].pop();\n    add_edge(xs[dm/2+1],xs[dm/2]);\n\
    \    add_edge(ys[dm/2+1],xs[dm/2]);\n  }\n\n  for(int i=0;i<n;i++){\n    if(!G[i].empty())\
    \ continue;\n    add_edge(i,xs[ds[i]-1]);\n  }\n  return G;\n}\n//END CUT HERE\n\
    #ifndef call_from_test\nclass TreeDistanceConstruction {\npublic:\n  vector<int>\
    \ construct(vector<int> ds) {\n    auto G=construct_from_distances_to_farthest_vertex(ds);\n\
    \    if(G.empty()) return {};\n    vector<int> bs;\n    for(int i=0;i<(int)G.size();i++)\n\
    \      for(int j:G[i])\n        if(i<j) bs.emplace_back(i),bs.emplace_back(j);\n\
    \    return bs;\n  }\n};\n/*\n  verified on 2019/12/10\n  https://vjudge.net/problem/TopCoder-14468\n\
    */\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: tree/construct_from_distances_to_farthest_vertex.cpp
  requiredBy: []
  timestamp: '2019-12-10 15:04:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: tree/construct_from_distances_to_farthest_vertex.cpp
layout: document
redirect_from:
- /library/tree/construct_from_distances_to_farthest_vertex.cpp
- /library/tree/construct_from_distances_to_farthest_vertex.cpp.html
title: tree/construct_from_distances_to_farthest_vertex.cpp
---
