---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: maxflow/fordfulkerson.cpp
    title: maxflow/fordfulkerson.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "#line 1 \"test/aoj/GRL_6_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #line 1 \"maxflow/fordfulkerson.cpp\"\n\n#line 3 \"maxflow/fordfulkerson.cpp\"\
    \nusing namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T,bool directed>\n\
    struct FordFulkerson{\n  struct edge{\n    int to;\n    T cap;\n    int rev;\n\
    \    edge(){}\n    edge(int to,T cap,int rev):to(to),cap(cap),rev(rev){}\n  };\n\
    \n  vector< vector<edge> > G;\n  vector<int> used;\n\n  FordFulkerson(){}\n  FordFulkerson(int\
    \ n):G(n),used(n){}\n\n  void add_edge(int from,int to,T cap){\n    G[from].emplace_back(to,cap,G[to].size());\n\
    \    G[to].emplace_back(from,directed?0:cap,G[from].size()-1);\n  }\n\n  T dfs(int\
    \ v,int t,T f){\n    if(v==t) return f;\n    used[v]=true;\n    for(int i=0;i<(int)G[v].size();i++){\n\
    \      edge &e=G[v][i];\n      if(!used[e.to]&&e.cap>0){\n        T d=dfs(e.to,t,min(f,e.cap));\n\
    \        if(d==0) continue;\n        e.cap-=d;\n        G[e.to][e.rev].cap+=d;\n\
    \        return d;\n      }\n    }\n    return 0;\n  }\n\n  T flow(int s,int t,T\
    \ lim){\n    T fl=0;\n    while(1){\n      fill(used.begin(),used.end(),0);\n\
    \      T f=dfs(s,t,lim);\n      if(f==0) break;\n      fl+=f;\n      lim-=f;\n\
    \    }\n    return fl;\n  }\n\n  T flow(int s,int t){\n    return flow(s,t,numeric_limits<T>::max()/2);\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n\
    }\n#endif\n#line 8 \"test/aoj/GRL_6_A.test.cpp\"\n#undef call_from_test\n\nint\
    \ main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int V,E;\n  cin>>V>>E;\n\
    \  FordFulkerson<int, true> G(V);\n  for(int i=0;i<E;i++){\n    int u,v,c;\n \
    \   cin>>u>>v>>c;\n    G.add_edge(u,v,c);\n  }\n  cout<<G.flow(0,V-1)<<endl;\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../maxflow/fordfulkerson.cpp\"\n#undef call_from_test\n\nint main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int V,E;\n  cin>>V>>E;\n  FordFulkerson<int,\
    \ true> G(V);\n  for(int i=0;i<E;i++){\n    int u,v,c;\n    cin>>u>>v>>c;\n  \
    \  G.add_edge(u,v,c);\n  }\n  cout<<G.flow(0,V-1)<<endl;\n  return 0;\n}\n"
  dependsOn:
  - maxflow/fordfulkerson.cpp
  isVerificationFile: true
  path: test/aoj/GRL_6_A.test.cpp
  requiredBy: []
  timestamp: '2020-09-24 12:58:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_6_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_A.test.cpp
- /verify/test/aoj/GRL_6_A.test.cpp.html
title: test/aoj/GRL_6_A.test.cpp
---
