---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D
  bundledCode: "#line 1 \"test/aoj/GRL_5_D.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #line 1 \"tree/eulertourforedge.cpp\"\n\n#line 3 \"tree/eulertourforedge.cpp\"\
    \nusing namespace std;\n#endif\n//BEGIN CUT HERE\nclass EulerTourForEdge{\nprivate:\n\
    \  vector<int> ds,us,dep,btm;\n\n  void dfs(int v,int p,int d){\n    dep[v]=d;\n\
    \    for(int u:G[v]){\n      if(u==p) continue;\n      ds[u]=btm.size();\n   \
    \   btm.emplace_back(u);\n      dfs(u,v,d+1);\n      us[u]=btm.size();\n     \
    \ btm.emplace_back(u);\n    }\n  }\npublic:\n  vector< vector<int> > G;\n\n  EulerTourForEdge(){}\n\
    \  EulerTourForEdge(int n):\n    ds(n),us(n),dep(n),G(n){}\n\n  void add_edge(int\
    \ u,int v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n  }\n\n  void\
    \ build(int r=0){\n    btm.clear();\n    ds[r]=btm.size();\n    btm.emplace_back(r);\n\
    \    dfs(r,-1,0);\n    us[r]=btm.size();\n    btm.emplace_back(r);\n  }\n\n  int\
    \ child(int u,int v){\n    return dep[u]<dep[v]?v:u;\n  }\n\n  int bottom(int\
    \ e){\n    return btm[e];\n  }\n\n  // lca(u, v) must be u or v\n  template<typename\
    \ F>\n  void query(int u,int v,F f){\n    if(dep[u]>dep[v]) swap(u,v);\n    f(ds[u]+1,ds[v]+1);\n\
    \  }\n\n  template<typename T,typename G>\n  void update(int v,T x,G g){\n   \
    \ g(ds[v], x);\n    g(us[v],-x);\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    signed main(){\n  return 0;\n}\n#endif\n#line 1 \"datastructure/binaryindexedtree.cpp\"\
    \n\n#line 3 \"datastructure/binaryindexedtree.cpp\"\nusing namespace std;\n#endif\n\
    /*\n * @docs docs/binaryindexedtree.md\n */\n//BEGIN CUT HERE\ntemplate<typename\
    \ T>\nstruct BIT{\n  int n;\n  vector<T> bit;\n  // 1-indexed\n  BIT(int n_):n(n_+1),bit(n+1,0){}\n\
    \n  T sum(int i){\n    T s(0);\n    for(int x=i;x>0;x-=(x&-x))\n      s+=bit[x];\n\
    \    return s;\n  }\n\n  void add(int i,T a){\n    if(i==0) return;\n    for(int\
    \ x=i;x<=n;x+=(x&-x))\n      bit[x]+=a;\n  }\n\n  // [l, r)\n  T query(int l,int\
    \ r){\n    return sum(r-1)-sum(l-1);\n  }\n\n  int lower_bound(int w){\n    if(w<=0)\
    \ return 0;\n    int x=0,r=1;\n    while(r<n) r<<=1;\n    for(int k=r;k>0;k>>=1){\n\
    \      if(x+k<=n&&bit[x+k]<w){\n        w-=bit[x+k];\n        x+=k;\n      }\n\
    \    }\n    return x+1;\n  }\n\n  // 0-indexed\n  T sum0(int i){return sum(i+1);}\n\
    \  void add0(int i,T a){add(i+1,a);}\n  T query0(int l,int r){return sum(r)-sum(l);}\n\
    };\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n\
    #line 9 \"test/aoj/GRL_5_D.test.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n;\n  cin>>n;\n  EulerTourForEdge\
    \ et(n);\n  for(int i=0;i<n;i++){\n    int k;\n    cin>>k;\n    for(int j=0;j<k;j++){\n\
    \      int c;\n      cin>>c;\n      et.add_edge(i,c);\n    }\n  }\n  et.build();\n\
    \n  BIT<int> bit(n*2+100);\n  int q;\n  cin>>q;\n  for(int i=0;i<q;i++){\n   \
    \ int t;\n    cin>>t;\n    if(t==0){\n      int v,w;\n      cin>>v>>w;\n     \
    \ auto g=[&](int k,int d){bit.add0(k,d);};\n      et.update(v,w,g);\n    }\n \
    \   if(t==1){\n      int u;\n      cin>>u;\n      int res=0;\n      et.query(0,u,[&](int\
    \ l,int r){res+=bit.query0(l,r);});\n      cout<<res<<\"\\n\";\n    }\n  }\n \
    \ cout<<flush;\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../tree/eulertourforedge.cpp\"\n#include \"../../datastructure/binaryindexedtree.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n;\n  cin>>n;\n  EulerTourForEdge et(n);\n  for(int i=0;i<n;i++){\n  \
    \  int k;\n    cin>>k;\n    for(int j=0;j<k;j++){\n      int c;\n      cin>>c;\n\
    \      et.add_edge(i,c);\n    }\n  }\n  et.build();\n\n  BIT<int> bit(n*2+100);\n\
    \  int q;\n  cin>>q;\n  for(int i=0;i<q;i++){\n    int t;\n    cin>>t;\n    if(t==0){\n\
    \      int v,w;\n      cin>>v>>w;\n      auto g=[&](int k,int d){bit.add0(k,d);};\n\
    \      et.update(v,w,g);\n    }\n    if(t==1){\n      int u;\n      cin>>u;\n\
    \      int res=0;\n      et.query(0,u,[&](int l,int r){res+=bit.query0(l,r);});\n\
    \      cout<<res<<\"\\n\";\n    }\n  }\n  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - tree/eulertourforedge.cpp
  - datastructure/binaryindexedtree.cpp
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/eulertourforedge.cpp
    title: tree/eulertourforedge.cpp
  - icon: ':heavy_check_mark:'
    path: datastructure/binaryindexedtree.cpp
    title: datastructure/binaryindexedtree.cpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: test/aoj/GRL_5_D.test.cpp
  requiredBy: []
  timestamp: '2020-05-07 20:21:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: test/aoj/GRL_5_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_D.test.cpp
- /verify/test/aoj/GRL_5_D.test.cpp.html
title: test/aoj/GRL_5_D.test.cpp
---
