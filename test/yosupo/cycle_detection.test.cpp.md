---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/cycle.cpp
    title: graph/cycle.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/cycle_detection
    links:
    - https://judge.yosupo.jp/problem/cycle_detection
  bundledCode: "#line 1 \"test/yosupo/cycle_detection.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/cycle_detection\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"graph/cycle.cpp\"\n\n\
    #line 3 \"graph/cycle.cpp\"\nusing namespace std;\n#endif\n//BEGIN CUT HERE\n\
    template<bool directed>\nstruct Cycle{\n  vector<int> used;\n  vector<vector<int>>\
    \ G;\n  Cycle(int n_):used(n_,0),G(n_){}\n\n  void add_edge(int u,int v){\n  \
    \  G[u].emplace_back(v);\n    if(not directed) G[v].emplace_back(u);\n  }\n\n\
    \  vector<int> vs;\n  int dfs(int v,int p){\n    used[v]=1;\n    vs.emplace_back(v);\n\
    \    for(int u:G[v]){\n      if((not directed) and u==p) continue;\n      if(used[u]==2)\
    \ continue;\n      if(used[u]==1) return u;\n      int res=dfs(u,v);\n      if(~res)\
    \ return res;\n    }\n    used[v]=2;\n    vs.pop_back();\n    return -1;\n  }\n\
    \n  vector<int> build(){\n    for(int i=0;i<(int)G.size();i++){\n      if(used[i])\
    \ continue;\n      int start=dfs(i,-1);\n      if(start<0) continue;\n      vs.erase(vs.begin(),find(vs.begin(),vs.end(),start));\n\
    \      return vs;\n    }\n    return {};\n  }\n};\nusing DirectedCycle = Cycle<true>;\n\
    using UndirectedCycle = Cycle<false>;\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n#line 8 \"test/yosupo/cycle_detection.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,m;\n  cin>>n>>m;\n\n  DirectedCycle G(n);\n  vector<map<int, int>> I(n);\n\
    \n  for(int i=0;i<m;i++){\n    int u,v;\n    cin>>u>>v;\n    G.add_edge(u,v);\n\
    \    I[u][v]=i;\n  }\n\n  auto vs=G.build();\n\n  if(vs.empty()){\n    cout<<-1<<endl;\n\
    \    return 0;\n  }\n\n  int l=vs.size();\n  cout<<l<<endl;\n  for(int i=0;i<l;i++)\n\
    \    cout<<I[vs[i]][vs[(i+1)%l]]<<'\\n';\n\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/cycle_detection\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../graph/cycle.cpp\"\n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n\n  int n,m;\n  cin>>n>>m;\n\n  DirectedCycle G(n);\n\
    \  vector<map<int, int>> I(n);\n\n  for(int i=0;i<m;i++){\n    int u,v;\n    cin>>u>>v;\n\
    \    G.add_edge(u,v);\n    I[u][v]=i;\n  }\n\n  auto vs=G.build();\n\n  if(vs.empty()){\n\
    \    cout<<-1<<endl;\n    return 0;\n  }\n\n  int l=vs.size();\n  cout<<l<<endl;\n\
    \  for(int i=0;i<l;i++)\n    cout<<I[vs[i]][vs[(i+1)%l]]<<'\\n';\n\n  return 0;\n\
    }\n"
  dependsOn:
  - graph/cycle.cpp
  isVerificationFile: true
  path: test/yosupo/cycle_detection.test.cpp
  requiredBy: []
  timestamp: '2021-01-03 18:39:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/cycle_detection.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/cycle_detection.test.cpp
- /verify/test/yosupo/cycle_detection.test.cpp.html
title: test/yosupo/cycle_detection.test.cpp
---
