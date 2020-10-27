---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: datastructure/unionfind.cpp
    title: datastructure/unionfind.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/yosupo/unionfind.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/unionfind\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"datastructure/unionfind.cpp\"\
    \n\n#line 3 \"datastructure/unionfind.cpp\"\nusing namespace std;\n#endif\n//BEGIN\
    \ CUT HERE\nstruct UnionFind{\n  int num;\n  vector<int> rs,ps;\n  UnionFind(int\
    \ n):num(n),rs(n,1),ps(n,0){\n    iota(ps.begin(),ps.end(),0);\n  }\n  int find(int\
    \ x){\n    return (x==ps[x]?x:ps[x]=find(ps[x]));\n  }\n  bool same(int x,int\
    \ y){\n    return find(x)==find(y);\n  }\n  void unite(int x,int y){\n    x=find(x);y=find(y);\n\
    \    if(x==y) return;\n    if(rs[x]<rs[y]) swap(x,y);\n    rs[x]+=rs[y];\n   \
    \ ps[y]=x;\n    num--;\n  }\n  int size(int x){\n    return rs[find(x)];\n  }\n\
    \  int count() const{\n    return num;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n#line 8 \"test/yosupo/unionfind.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  const char newl = '\\n';\n\n  int n,q;\n  cin>>n>>q;\n\n  UnionFind uf(n);\n\
    \  for(int i=0;i<q;i++){\n    int t,u,v;\n    cin>>t>>u>>v;\n    if(t==0) uf.unite(u,v);\n\
    \    if(t==1) cout<<uf.same(u,v)<<newl;\n  }\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/unionfind\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../datastructure/unionfind.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n  const char newl = '\\n';\n\n  int\
    \ n,q;\n  cin>>n>>q;\n\n  UnionFind uf(n);\n  for(int i=0;i<q;i++){\n    int t,u,v;\n\
    \    cin>>t>>u>>v;\n    if(t==0) uf.unite(u,v);\n    if(t==1) cout<<uf.same(u,v)<<newl;\n\
    \  }\n  return 0;\n}\n"
  dependsOn:
  - datastructure/unionfind.cpp
  isVerificationFile: true
  path: test/yosupo/unionfind.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 19:32:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/unionfind.test.cpp
- /verify/test/yosupo/unionfind.test.cpp.html
title: test/yosupo/unionfind.test.cpp
---
