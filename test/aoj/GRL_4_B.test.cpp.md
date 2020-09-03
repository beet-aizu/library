---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
  bundledCode: "#line 1 \"test/aoj/GRL_4_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #line 1 \"graph/topologicalsort.cpp\"\n\n#line 3 \"graph/topologicalsort.cpp\"\
    \nusing namespace std;\n#endif\n//BEGIN CUT HERE\nstruct TopologicalSort{\n  vector<\
    \ set<int> > G;\n  vector<int> used,indeg,ps;\n\n  TopologicalSort(){}\n  TopologicalSort(int\
    \ n):G(n),used(n,0),indeg(n,0){}\n\n  void add_edge(int s,int t){\n    G[s].emplace(t);\n\
    \    indeg[t]++;\n  }\n\n  void bfs(int s){\n    queue<int> que;\n    que.emplace(s);\n\
    \    used[s]=1;\n    while(!que.empty()){\n      int v=que.front();que.pop();\n\
    \      ps.emplace_back(v);\n      for(int u:G[v]){\n        indeg[u]--;\n    \
    \    if(indeg[u]==0&&!used[u]){\n          used[u]=1;\n          que.emplace(u);\n\
    \        }\n      }\n    }\n  }\n\n  vector<int> build(){\n    int n=G.size();\n\
    \    for(int i=0;i<n;i++)\n      if(indeg[i]==0&&!used[i]) bfs(i);\n    return\
    \ ps;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n#endif\n#line 8 \"test/aoj/GRL_4_B.test.cpp\"\
    \n#undef call_from_test\n\n#define IGNORE\n/**\n * @ignore\n */\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,e;\n  cin>>n>>e;\n  TopologicalSort\
    \ ts(n);\n  for(int i=0;i<e;i++){\n    int s,t;\n    cin>>s>>t;\n    ts.add_edge(s,t);\n\
    \  }\n\n  auto ps=ts.build();\n  for(int i:ps) cout<<i<<endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../graph/topologicalsort.cpp\"\n#undef call_from_test\n\n#define\
    \ IGNORE\n/**\n * @ignore\n */\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,e;\n  cin>>n>>e;\n  TopologicalSort ts(n);\n  for(int i=0;i<e;i++){\n\
    \    int s,t;\n    cin>>s>>t;\n    ts.add_edge(s,t);\n  }\n\n  auto ps=ts.build();\n\
    \  for(int i:ps) cout<<i<<endl;\n  return 0;\n}\n"
  dependsOn:
  - graph/topologicalsort.cpp
  extendedDependsOn:
  - icon: ':warning:'
    path: graph/topologicalsort.cpp
    title: graph/topologicalsort.cpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: test/aoj/GRL_4_B.test.cpp
  requiredBy: []
  timestamp: '2020-05-07 20:34:49+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verificationStatusIcon: ':x:'
  verifiedWith: []
documentation_of: test/aoj/GRL_4_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_4_B.test.cpp
- /verify/test/aoj/GRL_4_B.test.cpp.html
title: test/aoj/GRL_4_B.test.cpp
---
