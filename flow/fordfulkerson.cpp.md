---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_A.fordfulkerson.test.cpp
    title: test/aoj/GRL_6_A.fordfulkerson.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"flow/fordfulkerson.cpp\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T,bool directed>\n\
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
    }\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename T,bool directed>\nstruct FordFulkerson{\n\
    \  struct edge{\n    int to;\n    T cap;\n    int rev;\n    edge(){}\n    edge(int\
    \ to,T cap,int rev):to(to),cap(cap),rev(rev){}\n  };\n\n  vector< vector<edge>\
    \ > G;\n  vector<int> used;\n\n  FordFulkerson(){}\n  FordFulkerson(int n):G(n),used(n){}\n\
    \n  void add_edge(int from,int to,T cap){\n    G[from].emplace_back(to,cap,G[to].size());\n\
    \    G[to].emplace_back(from,directed?0:cap,G[from].size()-1);\n  }\n\n  T dfs(int\
    \ v,int t,T f){\n    if(v==t) return f;\n    used[v]=true;\n    for(int i=0;i<(int)G[v].size();i++){\n\
    \      edge &e=G[v][i];\n      if(!used[e.to]&&e.cap>0){\n        T d=dfs(e.to,t,min(f,e.cap));\n\
    \        if(d==0) continue;\n        e.cap-=d;\n        G[e.to][e.rev].cap+=d;\n\
    \        return d;\n      }\n    }\n    return 0;\n  }\n\n  T flow(int s,int t,T\
    \ lim){\n    T fl=0;\n    while(1){\n      fill(used.begin(),used.end(),0);\n\
    \      T f=dfs(s,t,lim);\n      if(f==0) break;\n      fl+=f;\n      lim-=f;\n\
    \    }\n    return fl;\n  }\n\n  T flow(int s,int t){\n    return flow(s,t,numeric_limits<T>::max()/2);\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n\
    }\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/fordfulkerson.cpp
  requiredBy: []
  timestamp: '2019-12-10 15:04:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_6_A.fordfulkerson.test.cpp
documentation_of: flow/fordfulkerson.cpp
layout: document
redirect_from:
- /library/flow/fordfulkerson.cpp
- /library/flow/fordfulkerson.cpp.html
title: flow/fordfulkerson.cpp
---
