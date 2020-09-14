---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: flow/bimatch.cpp
    title: flow/bimatch.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A
  bundledCode: "#line 1 \"test/aoj/GRL_7_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #line 1 \"flow/bimatch.cpp\"\n\n#line 3 \"flow/bimatch.cpp\"\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\nstruct BiMatch{\n  int n,time;\n  vector<vector<int>>\
    \ G;\n  vector<int> match,used,dead;\n\n  BiMatch(){}\n  BiMatch(int n):n(n),time(0),G(n),\n\
    \                 match(n,-1),used(n,-1),dead(n,0){}\n\n  void add_edge(int u,int\
    \ v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n  }\n\n  int dfs(int\
    \ v){\n    used[v]=time;\n    for(int u:G[v]){\n      if(dead[u]) continue;\n\
    \      int w=match[u];\n      if((w<0)||(used[w]<time&&dfs(w))){\n        match[v]=u;\n\
    \        match[u]=v;\n        return 1;\n      }\n    }\n    return 0;\n  }\n\n\
    \  int build(){\n    int res=0;\n    for(int v=0;v<n;v++){\n      if(dead[v])\
    \ continue;\n      if(match[v]<0){\n        time++;\n        res+=dfs(v);\n  \
    \    }\n    }\n    return res;\n  }\n\n  int disable(int v){\n    assert(!dead[v]);\n\
    \    int u=match[v];\n    if(~u) match[u]=-1;\n    match[v]=-1;\n    dead[v]=1;\n\
    \    time++;\n    return ~u?dfs(u)-1:0;\n  }\n\n  int enable(int v){\n    assert(dead[v]);\n\
    \    dead[v]=0;\n    time++;\n    return dfs(v);\n  }\n};\n//END CUT HERE\n#ifndef\
    \ call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n#line 8 \"test/aoj/GRL_7_A.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int X,Y,E;\n  cin>>X>>Y>>E;\n  BiMatch bm(X+Y);\n  for(int i=0;i<E;i++){\n\
    \    int x,y;\n    cin>>x>>y;\n    bm.add_edge(x,X+y);\n  }\n  cout<<bm.build()<<endl;\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../flow/bimatch.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int X,Y,E;\n  cin>>X>>Y>>E;\n\
    \  BiMatch bm(X+Y);\n  for(int i=0;i<E;i++){\n    int x,y;\n    cin>>x>>y;\n \
    \   bm.add_edge(x,X+y);\n  }\n  cout<<bm.build()<<endl;\n  return 0;\n}\n"
  dependsOn:
  - flow/bimatch.cpp
  isVerificationFile: true
  path: test/aoj/GRL_7_A.test.cpp
  requiredBy: []
  timestamp: '2019-12-10 15:04:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_7_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_7_A.test.cpp
- /verify/test/aoj/GRL_7_A.test.cpp.html
title: test/aoj/GRL_7_A.test.cpp
---
