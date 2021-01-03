---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2891.test.cpp
    title: test/aoj/2891.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/cycle_detection.test.cpp
    title: test/yosupo/cycle_detection.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/cycle.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<bool directed>\nstruct Cycle{\n  vector<int>\
    \ used;\n  vector<vector<int>> G;\n  Cycle(int n_):used(n_,0),G(n_){}\n\n  void\
    \ add_edge(int u,int v){\n    G[u].emplace_back(v);\n    if(not directed) G[v].emplace_back(u);\n\
    \  }\n\n  vector<int> vs;\n  int dfs(int v,int p){\n    used[v]=1;\n    vs.emplace_back(v);\n\
    \    for(int u:G[v]){\n      if((not directed) and u==p) continue;\n      if(used[u]==2)\
    \ continue;\n      if(used[u]==1) return u;\n      int res=dfs(u,v);\n      if(~res)\
    \ return res;\n    }\n    used[v]=2;\n    vs.pop_back();\n    return -1;\n  }\n\
    \n  vector<int> build(){\n    for(int i=0;i<(int)G.size();i++){\n      if(used[i])\
    \ continue;\n      int start=dfs(i,-1);\n      if(start<0) continue;\n      vs.erase(vs.begin(),find(vs.begin(),vs.end(),start));\n\
    \      return vs;\n    }\n    return {};\n  }\n};\nusing DirectedCycle = Cycle<true>;\n\
    using UndirectedCycle = Cycle<false>;\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<bool directed>\nstruct Cycle{\n  vector<int>\
    \ used;\n  vector<vector<int>> G;\n  Cycle(int n_):used(n_,0),G(n_){}\n\n  void\
    \ add_edge(int u,int v){\n    G[u].emplace_back(v);\n    if(not directed) G[v].emplace_back(u);\n\
    \  }\n\n  vector<int> vs;\n  int dfs(int v,int p){\n    used[v]=1;\n    vs.emplace_back(v);\n\
    \    for(int u:G[v]){\n      if((not directed) and u==p) continue;\n      if(used[u]==2)\
    \ continue;\n      if(used[u]==1) return u;\n      int res=dfs(u,v);\n      if(~res)\
    \ return res;\n    }\n    used[v]=2;\n    vs.pop_back();\n    return -1;\n  }\n\
    \n  vector<int> build(){\n    for(int i=0;i<(int)G.size();i++){\n      if(used[i])\
    \ continue;\n      int start=dfs(i,-1);\n      if(start<0) continue;\n      vs.erase(vs.begin(),find(vs.begin(),vs.end(),start));\n\
    \      return vs;\n    }\n    return {};\n  }\n};\nusing DirectedCycle = Cycle<true>;\n\
    using UndirectedCycle = Cycle<false>;\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/cycle.cpp
  requiredBy: []
  timestamp: '2021-01-03 18:39:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/cycle_detection.test.cpp
  - test/aoj/2891.test.cpp
documentation_of: graph/cycle.cpp
layout: document
redirect_from:
- /library/graph/cycle.cpp
- /library/graph/cycle.cpp.html
title: graph/cycle.cpp
---
