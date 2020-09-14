---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segtree/basic/chien.cpp
    title: segtree/basic/chien.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
  bundledCode: "#line 1 \"test/aoj/DSL_2_F.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #line 1 \"segtree/basic/chien.cpp\"\n\n#line 3 \"segtree/basic/chien.cpp\"\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate <typename T,typename E>\n\
    struct SegmentTree{\n  using F = function<T(T,T)>;\n  using G = function<T(T,E)>;\n\
    \  using H = function<E(E,E)>;\n  int n,height;\n  F f;\n  G g;\n  H h;\n  T ti;\n\
    \  E ei;\n  vector<T> dat;\n  vector<E> laz;\n  SegmentTree(F f,G g,H h,T ti,E\
    \ ei):\n    f(f),g(g),h(h),ti(ti),ei(ei){}\n\n  void init(int n_){\n    n=1;height=0;\n\
    \    while(n<n_) n<<=1,height++;\n    dat.assign(2*n,ti);\n    laz.assign(2*n,ei);\n\
    \  }\n\n  void build(const vector<T> &v){\n    int n_=v.size();\n    init(n_);\n\
    \    for(int i=0;i<n_;i++) dat[n+i]=v[i];\n    for(int i=n-1;i;i--)\n      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);\n\
    \  }\n\n  inline T reflect(int k){\n    return laz[k]==ei?dat[k]:g(dat[k],laz[k]);\n\
    \  }\n\n  inline void propagate(int k){\n    if(laz[k]==ei) return;\n    laz[(k<<1)|0]=h(laz[(k<<1)|0],laz[k]);\n\
    \    laz[(k<<1)|1]=h(laz[(k<<1)|1],laz[k]);\n    dat[k]=reflect(k);\n    laz[k]=ei;\n\
    \  }\n\n  inline void thrust(int k){\n    for(int i=height;i;i--) propagate(k>>i);\n\
    \  }\n\n  inline void recalc(int k){\n    while(k>>=1)\n      dat[k]=f(reflect((k<<1)|0),reflect((k<<1)|1));\n\
    \  }\n\n  void update(int a,int b,E x){\n    if(a>=b) return;\n    thrust(a+=n);\n\
    \    thrust(b+=n-1);\n    for(int l=a,r=b+1;l<r;l>>=1,r>>=1){\n      if(l&1) laz[l]=h(laz[l],x),l++;\n\
    \      if(r&1) --r,laz[r]=h(laz[r],x);\n    }\n    recalc(a);\n    recalc(b);\n\
    \  }\n\n  void set_val(int a,T x){\n    thrust(a+=n);\n    dat[a]=x;laz[a]=ei;\n\
    \    recalc(a);\n  }\n\n  T query(int a,int b){\n    if(a>=b) return ti;\n   \
    \ thrust(a+=n);\n    thrust(b+=n-1);\n    T vl=ti,vr=ti;\n    for(int l=a,r=b+1;l<r;l>>=1,r>>=1)\
    \ {\n      if(l&1) vl=f(vl,reflect(l++));\n      if(r&1) vr=f(reflect(--r),vr);\n\
    \    }\n    return f(vl,vr);\n  }\n\n  template<typename C>\n  int find(int st,C\
    \ &check,T &acc,int k,int l,int r){\n    if(l+1==r){\n      acc=f(acc,reflect(k));\n\
    \      return check(acc)?k-n:-1;\n    }\n    propagate(k);\n    int m=(l+r)>>1;\n\
    \    if(m<=st) return find(st,check,acc,(k<<1)|1,m,r);\n    if(st<=l&&!check(f(acc,dat[k]))){\n\
    \      acc=f(acc,dat[k]);\n      return -1;\n    }\n    int vl=find(st,check,acc,(k<<1)|0,l,m);\n\
    \    if(~vl) return vl;\n    return find(st,check,acc,(k<<1)|1,m,r);\n  }\n\n\
    \  template<typename C>\n  int find(int st,C &check){\n    T acc=ti;\n    return\
    \ find(st,check,acc,1,0,n);\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    \nsigned CFR569_C(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,m;\n\
    \  cin>>n>>m;\n  vector<int> as(n),bs(m);\n  for(int i=0;i<n;i++) cin>>as[i];\n\
    \  for(int i=0;i<m;i++) cin>>bs[i];\n\n  auto f=[](int a,int b){return max(a,b);};\n\
    \  auto g=[](int a,int b){return a+b;};\n  int ti=0,ei=0;\n  SegmentTree<int,\
    \ int> seg(f,g,g,ti,ei);\n\n  const int sz = 1<<20;\n  seg.build(vector<int>(sz,0));\n\
    \n  for(int i=0;i<n;i++) seg.update(sz-as[i],sz,+1);\n  for(int i=0;i<m;i++) seg.update(sz-bs[i],sz,-1);\n\
    \n  int q;\n  cin>>q;\n  auto check=[](int d){return d>0;};\n  for(int i=0;i<q;i++){\n\
    \    int t,k,v;\n    cin>>t>>k>>v;\n    k--;\n    if(t==1){\n      seg.update(sz-as[k],sz,-1);\n\
    \      as[k]=v;\n      seg.update(sz-as[k],sz,+1);\n    }\n    if(t==2){\n   \
    \   seg.update(sz-bs[k],sz,+1);\n      bs[k]=v;\n      seg.update(sz-bs[k],sz,-1);\n\
    \    }\n    int pos=seg.find(0,check);\n    cout<<(pos<0?pos:sz-pos)<<\"\\n\"\
    ;\n  }\n  cout<<flush;\n  return 0;\n}\n/*\n  verified on 2019/10/28\n  https://codeforces.com/contest/1179/problem/C\n\
    */\n\nsigned main(){\n  CFR569_C();\n  return 0;\n}\n#endif\n#line 8 \"test/aoj/DSL_2_F.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,q;\n  cin>>n>>q;\n\n  auto f=[](int a,int b){return min(a,b);};\n  auto\
    \ g=[](int a,int b){(void)a;return b;};\n  SegmentTree<int, int> seg(f,g,g,INT_MAX,-1);\n\
    \  seg.build(vector<int>(n,INT_MAX));\n\n  for(int i=0;i<q;i++){\n    int c;\n\
    \    cin>>c;\n    if(c==0){\n      int s,t,x;\n      cin>>s>>t>>x;\n      seg.update(s,t+1,x);\n\
    \    }\n    if(c==1){\n      int s,t;\n      cin>>s>>t;\n      cout<<seg.query(s,t+1)<<\"\
    \\n\";\n    }\n  }\n  cout<<flush;\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../segtree/basic/chien.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,q;\n  cin>>n>>q;\n\n  auto\
    \ f=[](int a,int b){return min(a,b);};\n  auto g=[](int a,int b){(void)a;return\
    \ b;};\n  SegmentTree<int, int> seg(f,g,g,INT_MAX,-1);\n  seg.build(vector<int>(n,INT_MAX));\n\
    \n  for(int i=0;i<q;i++){\n    int c;\n    cin>>c;\n    if(c==0){\n      int s,t,x;\n\
    \      cin>>s>>t>>x;\n      seg.update(s,t+1,x);\n    }\n    if(c==1){\n     \
    \ int s,t;\n      cin>>s>>t;\n      cout<<seg.query(s,t+1)<<\"\\n\";\n    }\n\
    \  }\n  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - segtree/basic/chien.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_F.test.cpp
  requiredBy: []
  timestamp: '2020-05-07 20:09:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_F.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_F.test.cpp
- /verify/test/aoj/DSL_2_F.test.cpp.html
title: test/aoj/DSL_2_F.test.cpp
---
