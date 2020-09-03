---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"tree/eulertourforvertex.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\nclass EulerTourForVertex{\nprivate:\n\
    \  vector<int> ls,rs;\n  int pos;\n\n  void dfs(int v,int p){\n    ls[v]=pos++;\n\
    \    for(int u:G[v])\n      if(u!=p) dfs(u,v);\n    rs[v]=pos;\n  }\n\npublic:\n\
    \  vector< vector<int> > G;\n\n  EulerTourForVertex(){}\n  EulerTourForVertex(int\
    \ n):ls(n),rs(n),G(n){}\n\n  void add_edge(int u,int v){\n    G[u].emplace_back(v);\n\
    \    G[v].emplace_back(u);\n  }\n\n  void build(int r=0){\n    pos=0;\n    dfs(r,-1);\n\
    \  }\n\n  int idx(int v){return ls[v];}\n\n  template<typename F>\n  void exec(int\
    \ v,F f){\n    f(ls[v],rs[v]);\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nclass EulerTourForVertex{\nprivate:\n  vector<int> ls,rs;\n\
    \  int pos;\n\n  void dfs(int v,int p){\n    ls[v]=pos++;\n    for(int u:G[v])\n\
    \      if(u!=p) dfs(u,v);\n    rs[v]=pos;\n  }\n\npublic:\n  vector< vector<int>\
    \ > G;\n\n  EulerTourForVertex(){}\n  EulerTourForVertex(int n):ls(n),rs(n),G(n){}\n\
    \n  void add_edge(int u,int v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n\
    \  }\n\n  void build(int r=0){\n    pos=0;\n    dfs(r,-1);\n  }\n\n  int idx(int\
    \ v){return ls[v];}\n\n  template<typename F>\n  void exec(int v,F f){\n    f(ls[v],rs[v]);\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n\
    }\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy:
  - icon: ':warning:'
    path: tree/auxiliarytree.cpp
    title: tree/auxiliarytree.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2871.test.cpp
    title: test/aoj/2871.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_subtree_sum.test.cpp
    title: test/yosupo/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/3407.test.cpp
    title: test/yukicoder/3407.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4852.test.cpp
    title: test/yukicoder/4852.test.cpp
  extendedVerifiedWith: []
  isVerificationFile: false
  path: tree/eulertourforvertex.cpp
  requiredBy:
  - tree/auxiliarytree.cpp
  - test/aoj/2871.test.cpp
  - test/yosupo/vertex_add_subtree_sum.test.cpp
  - test/yukicoder/3407.test.cpp
  - test/yukicoder/4852.test.cpp
  timestamp: '2020-03-04 20:21:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: tree/eulertourforvertex.cpp
layout: document
redirect_from:
- /library/tree/eulertourforvertex.cpp
- /library/tree/eulertourforvertex.cpp.html
title: tree/eulertourforvertex.cpp
---
