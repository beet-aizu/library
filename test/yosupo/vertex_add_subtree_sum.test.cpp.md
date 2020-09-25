---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tree/eulertourforvertex.cpp
    title: tree/eulertourforvertex.cpp
  - icon: ':question:'
    path: datastructure/binaryindexedtree.cpp
    title: Binary Indexed Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/yosupo/vertex_add_subtree_sum.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/vertex_add_subtree_sum\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"tree/eulertourforvertex.cpp\"\
    \n\n#line 3 \"tree/eulertourforvertex.cpp\"\nusing namespace std;\n#endif\n//BEGIN\
    \ CUT HERE\nclass EulerTourForVertex{\nprivate:\n  vector<int> ls,rs;\n  int pos;\n\
    \n  void dfs(int v,int p){\n    ls[v]=pos++;\n    for(int u:G[v])\n      if(u!=p)\
    \ dfs(u,v);\n    rs[v]=pos;\n  }\n\npublic:\n  vector< vector<int> > G;\n\n  EulerTourForVertex(){}\n\
    \  EulerTourForVertex(int n):ls(n),rs(n),G(n){}\n\n  void add_edge(int u,int v){\n\
    \    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n  }\n\n  void build(int\
    \ r=0){\n    pos=0;\n    dfs(r,-1);\n  }\n\n  int idx(int v){return ls[v];}\n\n\
    \  template<typename F>\n  void exec(int v,F f){\n    f(ls[v],rs[v]);\n  }\n};\n\
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
    \ main(){\n  return 0;\n}\n#endif\n#line 9 \"test/yosupo/vertex_add_subtree_sum.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,q;\n  cin>>n>>q;\n  vector<int> as(n);\n  for(int i=0;i<n;i++) cin>>as[i];\n\
    \n  EulerTourForVertex G(n);\n  for(int i=1;i<n;i++){\n    int p;\n    cin>>p;\n\
    \    G.add_edge(p,i);\n  }\n  G.build(0);\n\n  BIT<long long> bit(n);\n  for(int\
    \ i=0;i<n;i++)\n    bit.add(G.idx(i),as[i]);\n\n  for(int i=0;i<q;i++){\n    int\
    \ t;\n    cin>>t;\n    if(t==0){\n      int u,x;\n      cin>>u>>x;\n      bit.add(G.idx(u),x);\n\
    \    }\n    if(t==1){\n      int u;\n      cin>>u;\n      G.exec(u,[&](int l,int\
    \ r){cout<<bit.query(l,r)<<\"\\n\";});\n    }\n  }\n  cout<<flush;\n  return 0;\n\
    }\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/vertex_add_subtree_sum\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../tree/eulertourforvertex.cpp\"\n#include \"../../datastructure/binaryindexedtree.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,q;\n  cin>>n>>q;\n  vector<int> as(n);\n  for(int i=0;i<n;i++) cin>>as[i];\n\
    \n  EulerTourForVertex G(n);\n  for(int i=1;i<n;i++){\n    int p;\n    cin>>p;\n\
    \    G.add_edge(p,i);\n  }\n  G.build(0);\n\n  BIT<long long> bit(n);\n  for(int\
    \ i=0;i<n;i++)\n    bit.add(G.idx(i),as[i]);\n\n  for(int i=0;i<q;i++){\n    int\
    \ t;\n    cin>>t;\n    if(t==0){\n      int u,x;\n      cin>>u>>x;\n      bit.add(G.idx(u),x);\n\
    \    }\n    if(t==1){\n      int u;\n      cin>>u;\n      G.exec(u,[&](int l,int\
    \ r){cout<<bit.query(l,r)<<\"\\n\";});\n    }\n  }\n  cout<<flush;\n  return 0;\n\
    }\n"
  dependsOn:
  - tree/eulertourforvertex.cpp
  - datastructure/binaryindexedtree.cpp
  isVerificationFile: true
  path: test/yosupo/vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 16:01:41+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/vertex_add_subtree_sum.test.cpp
- /verify/test/yosupo/vertex_add_subtree_sum.test.cpp.html
title: test/yosupo/vertex_add_subtree_sum.test.cpp
---
