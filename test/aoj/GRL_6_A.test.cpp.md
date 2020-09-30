---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: maxflow/fordfulkerson.cpp
    title: "\u6700\u5927\u6D41 (\u8A08\u7B97\u91CF\u304C\u6D41\u91CF\u4F9D\u5B58)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "#line 1 \"test/aoj/GRL_6_A.test.cpp\"\n// verification-helper: PROBLEM\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#line 1 \"\
    maxflow/fordfulkerson.cpp\"\n\n#line 3 \"maxflow/fordfulkerson.cpp\"\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\n// O(F E)\ntemplate<typename Flow, bool directed>\n\
    struct FordFulkerson{\n  struct Edge{\n    int dst;\n    Flow cap;\n    int rev;\n\
    \    Edge(int dst,Flow cap,int rev):dst(dst),cap(cap),rev(rev){}\n  };\n\n  vector<\
    \ vector<Edge> > G;\n  vector<int> used;\n\n  FordFulkerson(){}\n  FordFulkerson(int\
    \ n):G(n),used(n){}\n\n  int add_edge(int src,int dst,Flow cap){\n    int e=G[src].size();\n\
    \    int r=(src==dst?e+1:G[dst].size());\n    G[src].emplace_back(dst,cap,r);\n\
    \    G[dst].emplace_back(src,directed?0:cap,e);\n    return e;\n  }\n\n  Flow\
    \ dfs(int v,int t,Flow f){\n    if(v==t) return f;\n    used[v]=true;\n    for(int\
    \ i=0;i<(int)G[v].size();i++){\n      Edge &e=G[v][i];\n      if(!used[e.dst]\
    \ and e.cap>0){\n        Flow d=dfs(e.dst,t,min(f,e.cap));\n        if(d==0) continue;\n\
    \        e.cap-=d;\n        G[e.dst][e.rev].cap+=d;\n        return d;\n     \
    \ }\n    }\n    return 0;\n  }\n\n  Flow flow(int s,int t,Flow lim){\n    Flow\
    \ fl=0;\n    while(1){\n      fill(used.begin(),used.end(),0);\n      Flow f=dfs(s,t,lim);\n\
    \      if(f==0) break;\n      fl+=f;\n      lim-=f;\n    }\n    return fl;\n \
    \ }\n\n  Flow flow(int s,int t){\n    return flow(s,t,numeric_limits<Flow>::max()/2);\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n\
    }\n#endif\n#line 8 \"test/aoj/GRL_6_A.test.cpp\"\n#undef call_from_test\n\nint\
    \ main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int V,E;\n  cin>>V>>E;\n\
    \  FordFulkerson<int, true> G(V);\n  for(int i=0;i<E;i++){\n    int u,v,c;\n \
    \   cin>>u>>v>>c;\n    G.add_edge(u,v,c);\n  }\n  cout<<G.flow(0,V-1)<<endl;\n\
    \  return 0;\n}\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../maxflow/fordfulkerson.cpp\"\n#undef call_from_test\n\nint main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int V,E;\n  cin>>V>>E;\n  FordFulkerson<int,\
    \ true> G(V);\n  for(int i=0;i<E;i++){\n    int u,v,c;\n    cin>>u>>v>>c;\n  \
    \  G.add_edge(u,v,c);\n  }\n  cout<<G.flow(0,V-1)<<endl;\n  return 0;\n}\n"
  dependsOn:
  - maxflow/fordfulkerson.cpp
  isVerificationFile: true
  path: test/aoj/GRL_6_A.test.cpp
  requiredBy: []
  timestamp: '2020-09-30 16:50:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_6_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_A.test.cpp
- /verify/test/aoj/GRL_6_A.test.cpp.html
title: test/aoj/GRL_6_A.test.cpp
---
