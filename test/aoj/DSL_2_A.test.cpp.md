---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segtree/basic/ushi.cpp
    title: segtree/basic/ushi.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "#line 1 \"test/aoj/DSL_2_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #line 1 \"segtree/basic/ushi.cpp\"\n\n#line 3 \"segtree/basic/ushi.cpp\"\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate <typename T>\nstruct SegmentTree{\n\
    \  using F = function<T(T,T)>;\n  int n;\n  F f;\n  T ti;\n  vector<T> dat;\n\n\
    \  SegmentTree(){}\n  SegmentTree(F f,T ti):f(f),ti(ti){}\n\n  void init(int n_){\n\
    \    n=1;\n    while(n<n_) n<<=1;\n    dat.assign(n<<1,ti);\n  }\n\n  void build(const\
    \ vector<T> &v){\n    int n_=v.size();\n    init(n_);\n    for(int i=0;i<n_;i++)\
    \ dat[n+i]=v[i];\n    for(int i=n-1;i;i--)\n      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);\n\
    \  }\n\n  void set_val(int k,T x){\n    dat[k+=n]=x;\n    while(k>>=1)\n     \
    \ dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);\n  }\n\n  T query(int a,int b){\n   \
    \ if(a>=b) return ti;\n    T vl=ti,vr=ti;\n    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1)\
    \ {\n      if(l&1) vl=f(vl,dat[l++]);\n      if(r&1) vr=f(dat[--r],vr);\n    }\n\
    \    return f(vl,vr);\n  }\n\n  template<typename C>\n  int find(int st,C &check,T\
    \ &acc,int k,int l,int r){\n    if(l+1==r){\n      acc=f(acc,dat[k]);\n      return\
    \ check(acc)?k-n:-1;\n    }\n    int m=(l+r)>>1;\n    if(m<=st) return find(st,check,acc,(k<<1)|1,m,r);\n\
    \    if(st<=l&&!check(f(acc,dat[k]))){\n      acc=f(acc,dat[k]);\n      return\
    \ -1;\n    }\n    int vl=find(st,check,acc,(k<<1)|0,l,m);\n    if(~vl) return\
    \ vl;\n    return find(st,check,acc,(k<<1)|1,m,r);\n  }\n\n  template<typename\
    \ C>\n  int find(int st,C &check){\n    T acc=ti;\n    return find(st,check,acc,1,0,n);\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\n// find with non-invertible\
    \ monoid\nsigned KUPC2013_D(){\n  int n;\n  scanf(\"%d\",&n);\n  vector<int> as(n+2,0);\n\
    \  for(int i=1;i<=n;i++) scanf(\"%d\",&as[i]);\n\n  const int INF = 1.1e9;\n \
    \ auto f=[](int a,int b){return min(a,b);};\n  SegmentTree<int> seg(f,INF);\n\
    \  seg.build(as);\n\n  using P = pair<int, int>;\n  set<P> sp;\n  for(int k=0;k<2;k++){\n\
    \    for(int i=1;i<=n;i++){\n      auto check=[&](int x){return x<as[i];};\n \
    \     int l=seg.find(i,check);\n      sp.emplace(k?n+2-l:l,as[i]);\n    }\n  \
    \  reverse(as.begin(),as.end());\n    seg.build(as);\n  }\n\n  printf(\"%d\\n\"\
    ,(int)sp.size()/2);\n  return 0;\n}\n/*\n  verified on 2019/12/26\n  https://atcoder.jp/contests/kupc2013/tasks/kupc2013_d\n\
    */\n\nsigned main(){\n  //KUPC2013_D();\n  return 0;\n}\n#endif\n#line 8 \"test/aoj/DSL_2_A.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,q;\n  cin>>n>>q;\n  auto f=[](int a,int b){return min(a,b);};\n  SegmentTree<int>\
    \ rmq(f,INT_MAX);\n  rmq.init(n);\n\n  for(int i=0;i<q;i++){\n    int c,x,y;\n\
    \    cin>>c>>x>>y;\n    if(c) cout<<rmq.query(x,y+1)<<\"\\n\";\n    else rmq.set_val(x,y);\n\
    \  }\n  cout<<flush;\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../segtree/basic/ushi.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,q;\n  cin>>n>>q;\n  auto\
    \ f=[](int a,int b){return min(a,b);};\n  SegmentTree<int> rmq(f,INT_MAX);\n \
    \ rmq.init(n);\n\n  for(int i=0;i<q;i++){\n    int c,x,y;\n    cin>>c>>x>>y;\n\
    \    if(c) cout<<rmq.query(x,y+1)<<\"\\n\";\n    else rmq.set_val(x,y);\n  }\n\
    \  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - segtree/basic/ushi.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_A.test.cpp
  requiredBy: []
  timestamp: '2020-05-07 20:09:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_A.test.cpp
- /verify/test/aoj/DSL_2_A.test.cpp.html
title: test/aoj/DSL_2_A.test.cpp
---
