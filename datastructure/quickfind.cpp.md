---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"datastructure/quickfind.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\nstruct QuickFind{\n  int n;\n\
    \  vector<int> rs,ps;\n  vector<vector<int> > vs;\n  QuickFind(){}\n  QuickFind(int\
    \ sz):n(sz),rs(sz,1),ps(sz),vs(sz){\n    iota(ps.begin(),ps.end(),0);\n    for(int\
    \ i=0;i<n;i++) vs[i].assign(1,i);\n  }\n  int find(int x) const{return ps[x];}\n\
    \  bool same(int x,int y) const{\n    return find(x)==find(y);\n  }\n  void unite(int\
    \ x,int y){\n    x=ps[x];y=ps[y];\n    if(x==y) return;\n    if(rs[x]<rs[y]) swap(x,y);\n\
    \    rs[x]+=rs[y];\n    for(int e:vs[y]){\n      ps[e]=x;\n      vs[x].push_back(e);\n\
    \    }\n    vs[y].clear();\n    vs[y].shrink_to_fit();\n  }\n  const vector<int>&\
    \ elements(int x) const{return vs[x];}\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nstruct QuickFind{\n  int n;\n  vector<int> rs,ps;\n  vector<vector<int>\
    \ > vs;\n  QuickFind(){}\n  QuickFind(int sz):n(sz),rs(sz,1),ps(sz),vs(sz){\n\
    \    iota(ps.begin(),ps.end(),0);\n    for(int i=0;i<n;i++) vs[i].assign(1,i);\n\
    \  }\n  int find(int x) const{return ps[x];}\n  bool same(int x,int y) const{\n\
    \    return find(x)==find(y);\n  }\n  void unite(int x,int y){\n    x=ps[x];y=ps[y];\n\
    \    if(x==y) return;\n    if(rs[x]<rs[y]) swap(x,y);\n    rs[x]+=rs[y];\n   \
    \ for(int e:vs[y]){\n      ps[e]=x;\n      vs[x].push_back(e);\n    }\n    vs[y].clear();\n\
    \    vs[y].shrink_to_fit();\n  }\n  const vector<int>& elements(int x) const{return\
    \ vs[x];}\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_1_A.quickfind.test.cpp
    title: test/aoj/DSL_1_A.quickfind.test.cpp
  isVerificationFile: false
  path: datastructure/quickfind.cpp
  requiredBy: []
  timestamp: '2019-12-17 22:20:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - test/aoj/DSL_1_A.quickfind.test.cpp
documentation_of: datastructure/quickfind.cpp
layout: document
redirect_from:
- /library/datastructure/quickfind.cpp
- /library/datastructure/quickfind.cpp.html
title: datastructure/quickfind.cpp
---
