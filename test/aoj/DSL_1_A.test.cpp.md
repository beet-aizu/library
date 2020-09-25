---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/unionfind.cpp
    title: datastructure/unionfind.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
  bundledCode: "#line 1 \"test/aoj/DSL_1_A.test.cpp\"\n// verification-helper: PROBLEM\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#line 1 \"\
    datastructure/unionfind.cpp\"\n\n#line 3 \"datastructure/unionfind.cpp\"\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\nstruct UnionFind{\n  int num;\n  vector<int>\
    \ rs,ps;\n  UnionFind(){}\n  UnionFind(int n):num(n),rs(n,1),ps(n,0){iota(ps.begin(),ps.end(),0);}\n\
    \  int find(int x){\n    return (x==ps[x]?x:ps[x]=find(ps[x]));\n  }\n  bool same(int\
    \ x,int y){\n    return find(x)==find(y);\n  }\n  void unite(int x,int y){\n \
    \   x=find(x);y=find(y);\n    if(x==y) return;\n    if(rs[x]<rs[y]) swap(x,y);\n\
    \    rs[x]+=rs[y];\n    ps[y]=x;\n    num--;\n  }\n  int size(int x){\n    return\
    \ rs[find(x)];\n  }\n  int count() const{\n    return num;\n  }\n};\n//END CUT\
    \ HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n#line 8 \"test/aoj/DSL_1_A.test.cpp\"\n#undef call_from_test\n\
    \nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,q;\n  cin>>n>>q;\n\
    \  UnionFind uf(n);\n  for(int i=0;i<q;i++){\n    int c,x,y;\n    cin>>c>>x>>y;\n\
    \    if(c) cout<<uf.same(x,y)<<\"\\n\";\n    else uf.unite(x,y);\n  }\n  cout<<flush;\n\
    \  return 0;\n}\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../datastructure/unionfind.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,q;\n  cin>>n>>q;\n  UnionFind\
    \ uf(n);\n  for(int i=0;i<q;i++){\n    int c,x,y;\n    cin>>c>>x>>y;\n    if(c)\
    \ cout<<uf.same(x,y)<<\"\\n\";\n    else uf.unite(x,y);\n  }\n  cout<<flush;\n\
    \  return 0;\n}\n"
  dependsOn:
  - datastructure/unionfind.cpp
  isVerificationFile: true
  path: test/aoj/DSL_1_A.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 14:47:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_1_A.test.cpp
- /verify/test/aoj/DSL_1_A.test.cpp.html
title: test/aoj/DSL_1_A.test.cpp
---
