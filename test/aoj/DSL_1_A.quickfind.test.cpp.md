---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/quickfind.cpp
    title: datastructure/quickfind.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
  bundledCode: "#line 1 \"test/aoj/DSL_1_A.quickfind.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#line 1 \"\
    datastructure/quickfind.cpp\"\n\n#line 3 \"datastructure/quickfind.cpp\"\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\nstruct QuickFind{\n  int n;\n  vector<int>\
    \ rs,ps;\n  vector<vector<int> > vs;\n  QuickFind(){}\n  QuickFind(int sz):n(sz),rs(sz,1),ps(sz),vs(sz){\n\
    \    iota(ps.begin(),ps.end(),0);\n    for(int i=0;i<n;i++) vs[i].assign(1,i);\n\
    \  }\n  int find(int x) const{return ps[x];}\n  bool same(int x,int y) const{\n\
    \    return find(x)==find(y);\n  }\n  void unite(int x,int y){\n    x=ps[x];y=ps[y];\n\
    \    if(x==y) return;\n    if(rs[x]<rs[y]) swap(x,y);\n    rs[x]+=rs[y];\n   \
    \ for(int e:vs[y]){\n      ps[e]=x;\n      vs[x].push_back(e);\n    }\n    vs[y].clear();\n\
    \    vs[y].shrink_to_fit();\n  }\n  const vector<int>& elements(int x) const{return\
    \ vs[x];}\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n#line 8 \"test/aoj/DSL_1_A.quickfind.test.cpp\"\n#undef call_from_test\n\
    \nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,q;\n  cin>>n>>q;\n\
    \  QuickFind qf(n);\n  for(int i=0;i<q;i++){\n    int c,x,y;\n    cin>>c>>x>>y;\n\
    \    if(c==0) qf.unite(x,y);\n    if(c==1) cout<<qf.same(x,y)<<\"\\n\";\n  }\n\
    \  cout<<flush;\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../datastructure/quickfind.cpp\"\n#undef call_from_test\n\nsigned\
    \ main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,q;\n  cin>>n>>q;\n\
    \  QuickFind qf(n);\n  for(int i=0;i<q;i++){\n    int c,x,y;\n    cin>>c>>x>>y;\n\
    \    if(c==0) qf.unite(x,y);\n    if(c==1) cout<<qf.same(x,y)<<\"\\n\";\n  }\n\
    \  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - datastructure/quickfind.cpp
  isVerificationFile: true
  path: test/aoj/DSL_1_A.quickfind.test.cpp
  requiredBy: []
  timestamp: '2020-05-07 20:09:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_1_A.quickfind.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_1_A.quickfind.test.cpp
- /verify/test/aoj/DSL_1_A.quickfind.test.cpp.html
title: test/aoj/DSL_1_A.quickfind.test.cpp
---
