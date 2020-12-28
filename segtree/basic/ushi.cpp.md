---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0367.test.cpp
    title: test/aoj/0367.test.cpp
  - icon: ':x:'
    path: test/aoj/2644.test.cpp
    title: test/aoj/2644.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2969.test.cpp
    title: test/aoj/2969.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.test.cpp
    title: test/aoj/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_set_range_composite.test.cpp
    title: test/yosupo/point_set_range_composite.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://atcoder.jp/contests/kupc2013/tasks/kupc2013_d
  bundledCode: "#line 1 \"segtree/basic/ushi.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate <typename T>\nstruct SegmentTree{\n\
    \  using F = function<T(T,T)>;\n  int n;\n  F f;\n  T ti;\n  vector<T> dat;\n\n\
    \  SegmentTree(F f,T ti):f(f),ti(ti){}\n\n  void init(int n_){\n    n=1;\n   \
    \ while(n<n_) n<<=1;\n    dat.assign(n<<1,ti);\n  }\n\n  void build(const vector<T>\
    \ &v){\n    int n_=v.size();\n    init(n_);\n    for(int i=0;i<n_;i++) dat[n+i]=v[i];\n\
    \    for(int i=n-1;i;i--)\n      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);\n  }\n\
    \n  void set_val(int k,T x){\n    dat[k+=n]=x;\n    while(k>>=1)\n      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);\n\
    \  }\n\n  T query(int a,int b){\n    if(a>=b) return ti;\n    T vl=ti,vr=ti;\n\
    \    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {\n      if(l&1) vl=f(vl,dat[l++]);\n\
    \      if(r&1) vr=f(dat[--r],vr);\n    }\n    return f(vl,vr);\n  }\n\n  template<typename\
    \ C>\n  int find(int st,C &check,T &acc,int k,int l,int r){\n    if(l+1==r){\n\
    \      acc=f(acc,dat[k]);\n      return check(acc)?k-n:-1;\n    }\n    int m=(l+r)>>1;\n\
    \    if(m<=st) return find(st,check,acc,(k<<1)|1,m,r);\n    if(st<=l and !check(f(acc,dat[k]))){\n\
    \      acc=f(acc,dat[k]);\n      return -1;\n    }\n    int vl=find(st,check,acc,(k<<1)|0,l,m);\n\
    \    if(~vl) return vl;\n    return find(st,check,acc,(k<<1)|1,m,r);\n  }\n\n\
    \  template<typename C>\n  int find(int st,C &check){\n    T acc=ti;\n    return\
    \ find(st,check,acc,1,0,n);\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    \n// find with non-invertible monoid\nsigned KUPC2013_D(){\n  int n;\n  scanf(\"\
    %d\",&n);\n  vector<int> as(n+2,0);\n  for(int i=1;i<=n;i++) scanf(\"%d\",&as[i]);\n\
    \n  const int INF = 1.1e9;\n  auto f=[](int a,int b){return min(a,b);};\n  SegmentTree<int>\
    \ seg(f,INF);\n  seg.build(as);\n\n  using P = pair<int, int>;\n  set<P> sp;\n\
    \  for(int k=0;k<2;k++){\n    for(int i=1;i<=n;i++){\n      auto check=[&](int\
    \ x){return x<as[i];};\n      int l=seg.find(i,check);\n      sp.emplace(k?n+2-l:l,as[i]);\n\
    \    }\n    reverse(as.begin(),as.end());\n    seg.build(as);\n  }\n\n  printf(\"\
    %d\\n\",(int)sp.size()/2);\n  return 0;\n}\n/*\n  verified on 2019/12/26\n  https://atcoder.jp/contests/kupc2013/tasks/kupc2013_d\n\
    */\n\nsigned main(){\n  //KUPC2013_D();\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate <typename T>\nstruct SegmentTree{\n  using\
    \ F = function<T(T,T)>;\n  int n;\n  F f;\n  T ti;\n  vector<T> dat;\n\n  SegmentTree(F\
    \ f,T ti):f(f),ti(ti){}\n\n  void init(int n_){\n    n=1;\n    while(n<n_) n<<=1;\n\
    \    dat.assign(n<<1,ti);\n  }\n\n  void build(const vector<T> &v){\n    int n_=v.size();\n\
    \    init(n_);\n    for(int i=0;i<n_;i++) dat[n+i]=v[i];\n    for(int i=n-1;i;i--)\n\
    \      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);\n  }\n\n  void set_val(int k,T x){\n\
    \    dat[k+=n]=x;\n    while(k>>=1)\n      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);\n\
    \  }\n\n  T query(int a,int b){\n    if(a>=b) return ti;\n    T vl=ti,vr=ti;\n\
    \    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {\n      if(l&1) vl=f(vl,dat[l++]);\n\
    \      if(r&1) vr=f(dat[--r],vr);\n    }\n    return f(vl,vr);\n  }\n\n  template<typename\
    \ C>\n  int find(int st,C &check,T &acc,int k,int l,int r){\n    if(l+1==r){\n\
    \      acc=f(acc,dat[k]);\n      return check(acc)?k-n:-1;\n    }\n    int m=(l+r)>>1;\n\
    \    if(m<=st) return find(st,check,acc,(k<<1)|1,m,r);\n    if(st<=l and !check(f(acc,dat[k]))){\n\
    \      acc=f(acc,dat[k]);\n      return -1;\n    }\n    int vl=find(st,check,acc,(k<<1)|0,l,m);\n\
    \    if(~vl) return vl;\n    return find(st,check,acc,(k<<1)|1,m,r);\n  }\n\n\
    \  template<typename C>\n  int find(int st,C &check){\n    T acc=ti;\n    return\
    \ find(st,check,acc,1,0,n);\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    \n// find with non-invertible monoid\nsigned KUPC2013_D(){\n  int n;\n  scanf(\"\
    %d\",&n);\n  vector<int> as(n+2,0);\n  for(int i=1;i<=n;i++) scanf(\"%d\",&as[i]);\n\
    \n  const int INF = 1.1e9;\n  auto f=[](int a,int b){return min(a,b);};\n  SegmentTree<int>\
    \ seg(f,INF);\n  seg.build(as);\n\n  using P = pair<int, int>;\n  set<P> sp;\n\
    \  for(int k=0;k<2;k++){\n    for(int i=1;i<=n;i++){\n      auto check=[&](int\
    \ x){return x<as[i];};\n      int l=seg.find(i,check);\n      sp.emplace(k?n+2-l:l,as[i]);\n\
    \    }\n    reverse(as.begin(),as.end());\n    seg.build(as);\n  }\n\n  printf(\"\
    %d\\n\",(int)sp.size()/2);\n  return 0;\n}\n/*\n  verified on 2019/12/26\n  https://atcoder.jp/contests/kupc2013/tasks/kupc2013_d\n\
    */\n\nsigned main(){\n  //KUPC2013_D();\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: segtree/basic/ushi.cpp
  requiredBy: []
  timestamp: '2020-10-27 18:08:33+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/point_set_range_composite.test.cpp
  - test/aoj/2644.test.cpp
  - test/aoj/2969.test.cpp
  - test/aoj/DSL_2_A.test.cpp
  - test/aoj/0367.test.cpp
documentation_of: segtree/basic/ushi.cpp
layout: document
redirect_from:
- /library/segtree/basic/ushi.cpp
- /library/segtree/basic/ushi.cpp.html
title: segtree/basic/ushi.cpp
---
