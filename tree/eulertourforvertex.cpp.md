---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2871.test.cpp
    title: test/aoj/2871.test.cpp
  - icon: ':x:'
    path: test/yosupo/vertex_add_subtree_sum.test.cpp
    title: test/yosupo/vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/eulertourforvertex.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\nclass EulerTourForVertex{\nprivate:\n\
    \  vector<int> ls,rs;\n  int pos;\n\n  void dfs(int v,int p){\n    ls[v]=pos++;\n\
    \    for(int u:G[v])\n      if(u!=p) dfs(u,v);\n    rs[v]=pos;\n  }\n\npublic:\n\
    \  vector< vector<int> > G;\n  EulerTourForVertex(int n):ls(n),rs(n),G(n){}\n\n\
    \  void add_edge(int u,int v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n\
    \  }\n\n  void build(int r=0){\n    pos=0;\n    dfs(r,-1);\n  }\n\n  int idx(int\
    \ v){return ls[v];}\n\n  template<typename F>\n  void exec(int v,F f){\n    f(ls[v],rs[v]);\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n\
    }\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nclass EulerTourForVertex{\nprivate:\n  vector<int> ls,rs;\n\
    \  int pos;\n\n  void dfs(int v,int p){\n    ls[v]=pos++;\n    for(int u:G[v])\n\
    \      if(u!=p) dfs(u,v);\n    rs[v]=pos;\n  }\n\npublic:\n  vector< vector<int>\
    \ > G;\n  EulerTourForVertex(int n):ls(n),rs(n),G(n){}\n\n  void add_edge(int\
    \ u,int v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n  }\n\n  void\
    \ build(int r=0){\n    pos=0;\n    dfs(r,-1);\n  }\n\n  int idx(int v){return\
    \ ls[v];}\n\n  template<typename F>\n  void exec(int v,F f){\n    f(ls[v],rs[v]);\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n\
    }\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/eulertourforvertex.cpp
  requiredBy: []
  timestamp: '2020-10-27 19:32:25+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/vertex_add_subtree_sum.test.cpp
  - test/aoj/2871.test.cpp
documentation_of: tree/eulertourforvertex.cpp
layout: document
redirect_from:
- /library/tree/eulertourforvertex.cpp
- /library/tree/eulertourforvertex.cpp.html
title: tree/eulertourforvertex.cpp
---
