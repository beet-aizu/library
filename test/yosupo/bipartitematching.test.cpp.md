---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: maxflow/hopcroft_karp.cpp
    title: maxflow/hopcroft_karp.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"test/yosupo/bipartitematching.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"maxflow/hopcroft_karp.cpp\"\
    \n\n#line 3 \"maxflow/hopcroft_karp.cpp\"\nusing namespace std;\n#endif\n//BEGIN\
    \ CUT HERE\nstruct BiMatch{\n  int L,R;\n  vector<vector<int> > G;\n  vector<int>\
    \ match,level;\n\n  BiMatch(){}\n  BiMatch(int L,int R):L(L),R(R),G(L+R),match(L+R,-1),level(L+R){}\n\
    \n  void add_edge(int u,int v){\n    G[u].emplace_back(v+L);\n    G[v+L].emplace_back(u);\n\
    \  }\n\n  bool bfs(){\n    fill(level.begin(),level.end(),-1);\n    queue<int>\
    \ que;\n    for(int i=0;i<L;i++){\n      if(~match[i]) continue;\n      level[i]=0;\n\
    \      que.emplace(i);\n    }\n    bool found=false;\n    while(!que.empty()){\n\
    \      int v=que.front();que.pop();\n      for(int u:G[v]){\n        if(~level[u])\
    \ continue;\n        level[u]=level[v]+1;\n        int w=match[u];\n        if(w==-1){\n\
    \          found=true;\n          continue;\n        }\n        if(~level[w])\
    \ continue;\n        level[w]=level[u]+1;\n        que.emplace(w);\n      }\n\
    \    }\n    return found;\n  }\n\n  bool dfs(int v){\n    for(int u:G[v]){\n \
    \     if(level[v]+1!=level[u]) continue;\n      level[u]=-1;\n      int w=match[u];\n\
    \      if(w<0||dfs(w)){\n        match[v]=u;\n        match[u]=v;\n        level[v]=-1;\n\
    \        return true;\n      }\n    }\n    level[v]=-1;\n    return false;\n \
    \ }\n\n  int build(){\n    int res=0;\n    while(bfs())\n      for(int i=0;i<L;i++)\n\
    \        if(match[i]<0&&dfs(i))\n          res++;\n    return res;\n  }\n\n};\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n#line 8 \"test/yosupo/bipartitematching.test.cpp\"\n\
    #undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int L,R,M;\n  cin>>L>>R>>M;\n  BiMatch G(L,R);\n  for(int i=0;i<M;i++){\n\
    \    int a,b;\n    cin>>a>>b;\n    G.add_edge(a,b);\n  }\n\n  cout<<G.build()<<endl;\n\
    \n  for(int i=0;i<L;i++)\n    if(~G.match[i])\n      cout<<i<<\" \"<<G.match[i]-L<<\"\
    \\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n\
    #include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../maxflow/hopcroft_karp.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int L,R,M;\n  cin>>L>>R>>M;\n\
    \  BiMatch G(L,R);\n  for(int i=0;i<M;i++){\n    int a,b;\n    cin>>a>>b;\n  \
    \  G.add_edge(a,b);\n  }\n\n  cout<<G.build()<<endl;\n\n  for(int i=0;i<L;i++)\n\
    \    if(~G.match[i])\n      cout<<i<<\" \"<<G.match[i]-L<<\"\\n\";\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - maxflow/hopcroft_karp.cpp
  isVerificationFile: true
  path: test/yosupo/bipartitematching.test.cpp
  requiredBy: []
  timestamp: '2020-09-24 12:58:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/bipartitematching.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/bipartitematching.test.cpp
- /verify/test/yosupo/bipartitematching.test.cpp.html
title: test/yosupo/bipartitematching.test.cpp
---
