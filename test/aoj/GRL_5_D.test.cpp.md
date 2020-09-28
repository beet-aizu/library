---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/binaryindexedtree.cpp
    title: Binary Indexed Tree
  - icon: ':heavy_check_mark:'
    path: tree/eulertourforedge.cpp
    title: tree/eulertourforedge.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D
  bundledCode: "#line 1 \"test/aoj/GRL_5_D.test.cpp\"\n// verification-helper: PROBLEM\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#line 1 \"\
    tree/eulertourforedge.cpp\"\n\n#line 3 \"tree/eulertourforedge.cpp\"\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\nclass EulerTourForEdge{\nprivate:\n  vector<int>\
    \ ds,us,dep,btm;\n\n  void dfs(int v,int p,int d){\n    dep[v]=d;\n    for(int\
    \ u:G[v]){\n      if(u==p) continue;\n      ds[u]=btm.size();\n      btm.emplace_back(u);\n\
    \      dfs(u,v,d+1);\n      us[u]=btm.size();\n      btm.emplace_back(u);\n  \
    \  }\n  }\npublic:\n  vector< vector<int> > G;\n\n  EulerTourForEdge(){}\n  EulerTourForEdge(int\
    \ n):\n    ds(n),us(n),dep(n),G(n){}\n\n  void add_edge(int u,int v){\n    G[u].emplace_back(v);\n\
    \    G[v].emplace_back(u);\n  }\n\n  void build(int r=0){\n    btm.clear();\n\
    \    ds[r]=btm.size();\n    btm.emplace_back(r);\n    dfs(r,-1,0);\n    us[r]=btm.size();\n\
    \    btm.emplace_back(r);\n  }\n\n  int child(int u,int v){\n    return dep[u]<dep[v]?v:u;\n\
    \  }\n\n  int bottom(int e){\n    return btm[e];\n  }\n\n  // lca(u, v) must be\
    \ u or v\n  template<typename F>\n  void query(int u,int v,F f){\n    if(dep[u]>dep[v])\
    \ swap(u,v);\n    f(ds[u]+1,ds[v]+1);\n  }\n\n  template<typename T,typename G>\n\
    \  void update(int v,T x,G g){\n    g(ds[v], x);\n    g(us[v],-x);\n  }\n};\n\
    //END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n\
    #line 2 \"datastructure/binaryindexedtree.cpp\"\n\n#ifndef call_from_test\n#line\
    \ 5 \"datastructure/binaryindexedtree.cpp\"\nusing namespace std;\n#endif\n\n\
    //BEGIN CUT HERE\ntemplate<typename T>\nclass BIT{\nprivate:\n  // \\sum_{j <\
    \ i}  v[j]\n  T sum(int i){\n    T s(0);\n    for(int x=i;x>0;x-=(x&-x))\n   \
    \   s+=bit[x];\n    return s;\n  }\npublic:\n  int n;\n  vector<T> bit;\n  BIT(int\
    \ n_):n(n_+1),bit(n+1,0){}\n\n  // v[i] += a\n  void add(int i,T a){\n    for(int\
    \ x=++i;x<=n;x+=(x&-x))\n      bit[x]+=a;\n  }\n  // \\sum_{l <= i < r} v[i]\n\
    \  T query(int l,int r){return sum(r)-sum(l);}\n\n  // min({x | sum(x) >= w})\n\
    \  int lower_bound(const T w){\n    if(w<=0) return 0;\n    T r=w;\n    int x=0,p=1;\n\
    \    while(p<n) p<<=1;\n    for(int k=p;k>0;k>>=1){\n      if(x+k<=n&&bit[x+k]<r){\n\
    \        r-=bit[x+k];\n        x+=k;\n      }\n    }\n    x++;\n    assert(sum(x-1)<w\
    \ and sum(x)>=w);\n    return x;\n  }\n\n  // min({x | sum(x) > w})\n  int upper_bound(T\
    \ w){return lower_bound(w+1);}\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n#line 9 \"test/aoj/GRL_5_D.test.cpp\"\n#undef\
    \ call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n;\n  cin>>n;\n  EulerTourForEdge et(n);\n  for(int i=0;i<n;i++){\n  \
    \  int k;\n    cin>>k;\n    for(int j=0;j<k;j++){\n      int c;\n      cin>>c;\n\
    \      et.add_edge(i,c);\n    }\n  }\n  et.build();\n\n  BIT<int> bit(2*n);\n\
    \  int q;\n  cin>>q;\n  for(int i=0;i<q;i++){\n    int t;\n    cin>>t;\n    if(t==0){\n\
    \      int v,w;\n      cin>>v>>w;\n      auto g=[&](int k,int d){bit.add(k,d);};\n\
    \      et.update(v,w,g);\n    }\n    if(t==1){\n      int u;\n      cin>>u;\n\
    \      int res=0;\n      et.query(0,u,[&](int l,int r){res+=bit.query(l,r);});\n\
    \      cout<<res<<\"\\n\";\n    }\n  }\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../tree/eulertourforedge.cpp\"\n#include \"../../datastructure/binaryindexedtree.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n;\n  cin>>n;\n  EulerTourForEdge et(n);\n  for(int i=0;i<n;i++){\n  \
    \  int k;\n    cin>>k;\n    for(int j=0;j<k;j++){\n      int c;\n      cin>>c;\n\
    \      et.add_edge(i,c);\n    }\n  }\n  et.build();\n\n  BIT<int> bit(2*n);\n\
    \  int q;\n  cin>>q;\n  for(int i=0;i<q;i++){\n    int t;\n    cin>>t;\n    if(t==0){\n\
    \      int v,w;\n      cin>>v>>w;\n      auto g=[&](int k,int d){bit.add(k,d);};\n\
    \      et.update(v,w,g);\n    }\n    if(t==1){\n      int u;\n      cin>>u;\n\
    \      int res=0;\n      et.query(0,u,[&](int l,int r){res+=bit.query(l,r);});\n\
    \      cout<<res<<\"\\n\";\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - tree/eulertourforedge.cpp
  - datastructure/binaryindexedtree.cpp
  isVerificationFile: true
  path: test/aoj/GRL_5_D.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 15:10:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_5_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_D.test.cpp
- /verify/test/aoj/GRL_5_D.test.cpp.html
title: test/aoj/GRL_5_D.test.cpp
---
