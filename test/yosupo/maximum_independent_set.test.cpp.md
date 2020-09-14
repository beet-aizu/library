---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/independentset.cpp
    title: graph/independentset.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/maximum_independent_set
  bundledCode: "#line 1 \"test/yosupo/maximum_independent_set.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"graph/independentset.cpp\"\
    \n\n#line 3 \"graph/independentset.cpp\"\nusing namespace std;\n#endif\n//BEGIN\
    \ CUT HERE\nstruct IndependentSet{\n  int n;\n  vector<int> deg,used,dead,pre,ans;\n\
    \  vector<vector<int> > G;\n\n  IndependentSet(int n):\n    n(n),deg(n),used(n,0),dead(n,0),G(n){}\n\
    \n  void add_edge(int u,int v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n\
    \  }\n\n  int res,cnt,alive;\n  void dfs(){\n    if(cnt+alive<=res) return;\n\n\
    \    int v=-1;\n    for(int i=0;i<n;i++){\n      if(used[i]||dead[i]) continue;\n\
    \      if(deg[i]<=1){\n        v=i;\n        break;\n      }\n      if(v<0||deg[v]<deg[i])\
    \ v=i;\n    }\n    if(v<0) return;\n\n    if(deg[v]!=1){\n      dead[v]=1;\n \
    \     alive--;\n      for(int u:G[v]) deg[u]--;\n\n      dfs();\n\n      dead[v]=0;\n\
    \      alive++;\n      for(int u:G[v]) deg[u]++;\n    }\n    {\n      used[v]=1;\n\
    \      alive--;\n      for(int u:G[v])\n        if(0==dead[u]++) alive-=!used[u];\n\
    \      cnt++;\n      if(res<cnt) pre=used;\n      res=max(res,cnt);\n\n      dfs();\n\
    \n      used[v]=0;\n      alive++;\n      for(int u:G[v])\n        if(--dead[u]==0)\
    \ alive+=!used[u];\n      cnt--;\n    }\n  }\n\n  int build(){\n    for(int i=0;i<n;i++)\
    \ deg[i]=G[i].size();\n    res=0,cnt=0,alive=n;\n    dfs();\n    for(int i=0;i<n;i++)\n\
    \      if(pre[i]) ans.emplace_back(i);\n    return res;\n  }\n};\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n#line 8 \"test/yosupo/maximum_independent_set.test.cpp\"\n#undef call_from_test\n\
    \nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,m;\n  cin>>n>>m;\n\
    \  IndependentSet G(n);\n  for(int i=0;i<m;i++){\n    int u,v;\n    cin>>u>>v;\n\
    \    G.add_edge(u,v);\n  }\n  int X=G.build();\n  cout<<X<<endl;\n  for(int i=0;i<X;i++){\n\
    \    if(i) cout<<\" \";\n    cout<<G.ans[i];\n  }\n  cout<<endl;\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../graph/independentset.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,m;\n  cin>>n>>m;\n  IndependentSet\
    \ G(n);\n  for(int i=0;i<m;i++){\n    int u,v;\n    cin>>u>>v;\n    G.add_edge(u,v);\n\
    \  }\n  int X=G.build();\n  cout<<X<<endl;\n  for(int i=0;i<X;i++){\n    if(i)\
    \ cout<<\" \";\n    cout<<G.ans[i];\n  }\n  cout<<endl;\n  return 0;\n}\n"
  dependsOn:
  - graph/independentset.cpp
  isVerificationFile: true
  path: test/yosupo/maximum_independent_set.test.cpp
  requiredBy: []
  timestamp: '2020-03-05 21:02:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/maximum_independent_set.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/maximum_independent_set.test.cpp
- /verify/test/yosupo/maximum_independent_set.test.cpp.html
title: test/yosupo/maximum_independent_set.test.cpp
---
