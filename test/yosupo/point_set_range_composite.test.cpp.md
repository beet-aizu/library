---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/yosupo/point_set_range_composite.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 2 \"mod/mint.cpp\"\n\n#ifndef\
    \ call_from_test\n#line 5 \"mod/mint.cpp\"\nusing namespace std;\n#endif\n\n//BEGIN\
    \ CUT HERE\ntemplate<typename T,T MOD = 1000000007>\nstruct Mint{\n  static constexpr\
    \ T mod = MOD;\n  T v;\n  Mint():v(0){}\n  Mint(signed v):v(v){}\n  Mint(long\
    \ long t){v=t%MOD;if(v<0) v+=MOD;}\n\n  Mint pow(long long k){\n    Mint res(1),tmp(v);\n\
    \    while(k){\n      if(k&1) res*=tmp;\n      tmp*=tmp;\n      k>>=1;\n    }\n\
    \    return res;\n  }\n\n  static Mint add_identity(){return Mint(0);}\n  static\
    \ Mint mul_identity(){return Mint(1);}\n\n  Mint inv(){return pow(MOD-2);}\n\n\
    \  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}\n  Mint& operator-=(Mint\
    \ a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}\n  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return\
    \ *this;}\n  Mint& operator/=(Mint a){return (*this)*=a.inv();}\n\n  Mint operator+(Mint\
    \ a) const{return Mint(v)+=a;}\n  Mint operator-(Mint a) const{return Mint(v)-=a;}\n\
    \  Mint operator*(Mint a) const{return Mint(v)*=a;}\n  Mint operator/(Mint a)\
    \ const{return Mint(v)/=a;}\n\n  Mint operator-() const{return v?Mint(MOD-v):Mint(v);}\n\
    \n  bool operator==(const Mint a)const{return v==a.v;}\n  bool operator!=(const\
    \ Mint a)const{return v!=a.v;}\n  bool operator <(const Mint a)const{return v\
    \ <a.v;}\n\n  static Mint comb(long long n,int k){\n    Mint num(1),dom(1);\n\
    \    for(int i=0;i<k;i++){\n      num*=Mint(n-i);\n      dom*=Mint(i+1);\n   \
    \ }\n    return num/dom;\n  }\n};\ntemplate<typename T,T MOD> constexpr T Mint<T,\
    \ MOD>::mod;\ntemplate<typename T,T MOD>\nostream& operator<<(ostream &os,Mint<T,\
    \ MOD> m){os<<m.v;return os;}\n//END CUT HERE\n#ifndef call_from_test\n\n//INSERT\
    \ ABOVE HERE\nsigned ABC127_E(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n\
    \  int h,w,k;\n  cin>>h>>w>>k;\n  using M = Mint<int>;\n\n  M ans{0};\n  for(int\
    \ d=1;d<h;d++)\n    ans+=M(d)*M(h-d)*M(w)*M(w);\n\n  for(int d=1;d<w;d++)\n  \
    \  ans+=M(d)*M(w-d)*M(h)*M(h);\n\n  ans*=M::comb(h*w-2,k-2);\n  cout<<ans<<endl;\n\
    \  return 0;\n}\n/*\n  verified on 2019/06/12\n  https://atcoder.jp/contests/abc127/tasks/abc127_e\n\
    */\n\nsigned main(){\n  //ABC127_E();\n  return 0;\n}\n#endif\n#line 1 \"segtree/basic/ushi.cpp\"\
    \n\n#line 3 \"segtree/basic/ushi.cpp\"\nusing namespace std;\n#endif\n//BEGIN\
    \ CUT HERE\ntemplate <typename T>\nstruct SegmentTree{\n  using F = function<T(T,T)>;\n\
    \  int n;\n  F f;\n  T ti;\n  vector<T> dat;\n\n  SegmentTree(){}\n  SegmentTree(F\
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
    \    if(m<=st) return find(st,check,acc,(k<<1)|1,m,r);\n    if(st<=l&&!check(f(acc,dat[k]))){\n\
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
    */\n\nsigned main(){\n  //KUPC2013_D();\n  return 0;\n}\n#endif\n#line 9 \"test/yosupo/point_set_range_composite.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  using M = Mint<int, 998244353>;\n  int n,q;\n  cin>>n>>q;\n\n  vector<int>\
    \ as(n),bs(n);\n  for(int i=0;i<n;i++) cin>>as[i]>>bs[i];\n\n  struct T{\n   \
    \ M a,b;\n    T(M a,M b):a(a),b(b){}\n  };\n\n  auto f=[&](T x,T y){return T(x.a*y.a,x.b*y.a+y.b);};\n\
    \  T ti(M(1),M(0));\n  SegmentTree<T> seg(f,ti);\n  vector<T> vt;\n  for(int i=0;i<n;i++)\
    \ vt.emplace_back(as[i],bs[i]);\n  seg.build(vt);\n\n  for(int i=0;i<q;i++){\n\
    \    int t;\n    cin>>t;\n    if(t==0){\n      int p,c,d;\n      cin>>p>>c>>d;\n\
    \      seg.set_val(p,T(M(c),M(d)));\n    }\n    if(t==1){\n      int l,r,x;\n\
    \      cin>>l>>r>>x;\n      T res=seg.query(l,r);\n      cout<<res.a*M(x)+res.b<<\"\
    \\n\";\n    }\n  }\n  cout<<flush;\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../mod/mint.cpp\"\n#include \"../../segtree/basic/ushi.cpp\"\n#undef\
    \ call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  using M = Mint<int, 998244353>;\n  int n,q;\n  cin>>n>>q;\n\n  vector<int>\
    \ as(n),bs(n);\n  for(int i=0;i<n;i++) cin>>as[i]>>bs[i];\n\n  struct T{\n   \
    \ M a,b;\n    T(M a,M b):a(a),b(b){}\n  };\n\n  auto f=[&](T x,T y){return T(x.a*y.a,x.b*y.a+y.b);};\n\
    \  T ti(M(1),M(0));\n  SegmentTree<T> seg(f,ti);\n  vector<T> vt;\n  for(int i=0;i<n;i++)\
    \ vt.emplace_back(as[i],bs[i]);\n  seg.build(vt);\n\n  for(int i=0;i<q;i++){\n\
    \    int t;\n    cin>>t;\n    if(t==0){\n      int p,c,d;\n      cin>>p>>c>>d;\n\
    \      seg.set_val(p,T(M(c),M(d)));\n    }\n    if(t==1){\n      int l,r,x;\n\
    \      cin>>l>>r>>x;\n      T res=seg.query(l,r);\n      cout<<res.a*M(x)+res.b<<\"\
    \\n\";\n    }\n  }\n  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - mod/mint.cpp
  - segtree/basic/ushi.cpp
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  - icon: ':heavy_check_mark:'
    path: segtree/basic/ushi.cpp
    title: segtree/basic/ushi.cpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: test/yosupo/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2020-03-12 17:02:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: test/yosupo/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_set_range_composite.test.cpp
- /verify/test/yosupo/point_set_range_composite.test.cpp.html
title: test/yosupo/point_set_range_composite.test.cpp
---
