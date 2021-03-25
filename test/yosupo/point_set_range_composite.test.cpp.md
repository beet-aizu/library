---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/linearfunction.cpp
    title: math/linearfunction.cpp
  - icon: ':question:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  - icon: ':question:'
    path: segtree/basic/ushi.cpp
    title: segtree/basic/ushi.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/yosupo/point_set_range_composite.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/point_set_range_composite\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"mod/mint.cpp\"\n\n#line\
    \ 3 \"mod/mint.cpp\"\nusing namespace std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename\
    \ T, T MOD = 1000000007>\nstruct Mint{\n  inline static constexpr T mod = MOD;\n\
    \  T v;\n  Mint():v(0){}\n  Mint(signed v):v(v){}\n  Mint(long long t){v=t%MOD;if(v<0)\
    \ v+=MOD;}\n\n  Mint pow(long long k){\n    Mint res(1),tmp(v);\n    while(k){\n\
    \      if(k&1) res*=tmp;\n      tmp*=tmp;\n      k>>=1;\n    }\n    return res;\n\
    \  }\n\n  static Mint add_identity(){return Mint(0);}\n  static Mint mul_identity(){return\
    \ Mint(1);}\n\n  Mint inv(){return pow(MOD-2);}\n\n  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return\
    \ *this;}\n  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}\n\
    \  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}\n  Mint& operator/=(Mint\
    \ a){return (*this)*=a.inv();}\n\n  Mint operator+(Mint a) const{return Mint(v)+=a;}\n\
    \  Mint operator-(Mint a) const{return Mint(v)-=a;}\n  Mint operator*(Mint a)\
    \ const{return Mint(v)*=a;}\n  Mint operator/(Mint a) const{return Mint(v)/=a;}\n\
    \n  Mint operator+() const{return *this;}\n  Mint operator-() const{return v?Mint(MOD-v):Mint(v);}\n\
    \n  bool operator==(const Mint a)const{return v==a.v;}\n  bool operator!=(const\
    \ Mint a)const{return v!=a.v;}\n\n  static Mint comb(long long n,int k){\n   \
    \ Mint num(1),dom(1);\n    for(int i=0;i<k;i++){\n      num*=Mint(n-i);\n    \
    \  dom*=Mint(i+1);\n    }\n    return num/dom;\n  }\n};\ntemplate<typename T,\
    \ T MOD>\nostream& operator<<(ostream &os,Mint<T, MOD> m){os<<m.v;return os;}\n\
    //END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n\
    #line 1 \"math/linearfunction.cpp\"\n\n#line 3 \"math/linearfunction.cpp\"\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\n// a * x + b\ntemplate<typename T>\n\
    struct LinearFunction{\n  T a,b;\n  LinearFunction():a(0),b(0){}\n  LinearFunction(T\
    \ a,T b):a(a),b(b){}\n\n  using LF = LinearFunction;\n  static LF add_identity(){return\
    \ LF(T(0),T(0));}\n  static LF mul_identity(){return LF(T(1),T(0));}\n  LF& operator+=(const\
    \ LF &o){\n    a+=o.a;b+=o.b;\n    return *this;\n  }\n  LF& operator*=(const\
    \ LF &o){\n    a=a*o.a;\n    b=b*o.a+o.b;\n    return *this;\n  }\n  LF operator+(const\
    \ LF &o)const{return LF(*this)+=o;}\n  LF operator*(const LF &o)const{return LF(*this)*=o;}\n\
    \n  T operator()(T x) const{return a*x+b;}\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n#line 1 \"segtree/basic/ushi.cpp\"\
    \n\n#line 3 \"segtree/basic/ushi.cpp\"\nusing namespace std;\n#endif\n//BEGIN\
    \ CUT HERE\ntemplate <typename T>\nstruct SegmentTree{\n  using F = function<T(T,T)>;\n\
    \  int n;\n  F f;\n  T ti;\n  vector<T> dat;\n\n  SegmentTree(F f,T ti):f(f),ti(ti){}\n\
    \n  void init(int n_){\n    n=1;\n    while(n<n_) n<<=1;\n    dat.assign(n<<1,ti);\n\
    \  }\n\n  void build(const vector<T> &v){\n    int n_=v.size();\n    init(n_);\n\
    \    for(int i=0;i<n_;i++) dat[n+i]=v[i];\n    for(int i=n-1;i;i--)\n      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);\n\
    \  }\n\n  void set_val(int k,T x){\n    dat[k+=n]=x;\n    while(k>>=1)\n     \
    \ dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);\n  }\n\n  T query(int a,int b){\n   \
    \ if(a>=b) return ti;\n    T vl=ti,vr=ti;\n    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1)\
    \ {\n      if(l&1) vl=f(vl,dat[l++]);\n      if(r&1) vr=f(dat[--r],vr);\n    }\n\
    \    return f(vl,vr);\n  }\n\n  template<typename C>\n  int max_right(int s,C\
    \ &check,T &acc,int k,int l,int r){\n    if(l+1==r){\n      acc=f(acc,dat[k]);\n\
    \      return check(acc)?-1:k-n;\n    }\n    int m=(l+r)>>1;\n    if(m<=s) return\
    \ max_right(s,check,acc,(k<<1)|1,m,r);\n    if(s<=l and check(f(acc,dat[k]))){\n\
    \      acc=f(acc,dat[k]);\n      return -1;\n    }\n    int vl=max_right(s,check,acc,(k<<1)|0,l,m);\n\
    \    if(~vl) return vl;\n    return max_right(s,check,acc,(k<<1)|1,m,r);\n  }\n\
    \n  // max t s.t. check(query(s,t))\n  // O(\\log N)\n  template<typename C>\n\
    \  int max_right(int s,C &check){\n    assert(s<n and check(ti) and not check(query(s,n)));\n\
    \    T acc=ti;\n    return max_right(s,check,acc,1,0,n);\n  }\n};\n//END CUT HERE\n\
    #ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n#line 10 \"test/yosupo/point_set_range_composite.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,q;\n  cin>>n>>q;\n\n  vector<int> as(n),bs(n);\n  for(int i=0;i<n;i++)\
    \ cin>>as[i]>>bs[i];\n\n  using M = Mint<int, 998244353>;\n  using T = LinearFunction<M>;\n\
    \  auto f=[&](T x,T y){return x*y;};\n  T ti=T::mul_identity();\n  SegmentTree<T>\
    \ seg(f,ti);\n\n  vector<T> vt;\n  for(int i=0;i<n;i++) vt.emplace_back(as[i],bs[i]);\n\
    \  seg.build(vt);\n\n  for(int i=0;i<q;i++){\n    int t;\n    cin>>t;\n    if(t==0){\n\
    \      int p,c,d;\n      cin>>p>>c>>d;\n      seg.set_val(p,T(M(c),M(d)));\n \
    \   }\n    if(t==1){\n      int l,r,x;\n      cin>>l>>r>>x;\n      cout<<seg.query(l,r)(x)<<\"\
    \\n\";\n    }\n  }\n  cout<<flush;\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/point_set_range_composite\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../mod/mint.cpp\"\n#include \"../../math/linearfunction.cpp\"\n#include\
    \ \"../../segtree/basic/ushi.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,q;\n  cin>>n>>q;\n\n  vector<int>\
    \ as(n),bs(n);\n  for(int i=0;i<n;i++) cin>>as[i]>>bs[i];\n\n  using M = Mint<int,\
    \ 998244353>;\n  using T = LinearFunction<M>;\n  auto f=[&](T x,T y){return x*y;};\n\
    \  T ti=T::mul_identity();\n  SegmentTree<T> seg(f,ti);\n\n  vector<T> vt;\n \
    \ for(int i=0;i<n;i++) vt.emplace_back(as[i],bs[i]);\n  seg.build(vt);\n\n  for(int\
    \ i=0;i<q;i++){\n    int t;\n    cin>>t;\n    if(t==0){\n      int p,c,d;\n  \
    \    cin>>p>>c>>d;\n      seg.set_val(p,T(M(c),M(d)));\n    }\n    if(t==1){\n\
    \      int l,r,x;\n      cin>>l>>r>>x;\n      cout<<seg.query(l,r)(x)<<\"\\n\"\
    ;\n    }\n  }\n  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - mod/mint.cpp
  - math/linearfunction.cpp
  - segtree/basic/ushi.cpp
  isVerificationFile: true
  path: test/yosupo/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2021-03-25 09:46:10+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_set_range_composite.test.cpp
- /verify/test/yosupo/point_set_range_composite.test.cpp.html
title: test/yosupo/point_set_range_composite.test.cpp
---
