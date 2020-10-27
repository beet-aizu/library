---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: linearalgebra/matrix.cpp
    title: linearalgebra/matrix.cpp
  - icon: ':question:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"test/yosupo/matrix_det.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/matrix_det\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"mod/mint.cpp\"\n\n#line\
    \ 3 \"mod/mint.cpp\"\nusing namespace std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename\
    \ T, T MOD = 1000000007>\nstruct Mint{\n  static constexpr T mod = MOD;\n  T v;\n\
    \  Mint():v(0){}\n  Mint(signed v):v(v){}\n  Mint(long long t){v=t%MOD;if(v<0)\
    \ v+=MOD;}\n\n  Mint pow(long long k){\n    Mint res(1),tmp(v);\n    while(k){\n\
    \      if(k&1) res*=tmp;\n      tmp*=tmp;\n      k>>=1;\n    }\n    return res;\n\
    \  }\n\n  static Mint add_identity(){return Mint(0);}\n  static Mint mul_identity(){return\
    \ Mint(1);}\n\n  Mint inv(){return pow(MOD-2);}\n\n  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return\
    \ *this;}\n  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}\n\
    \  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}\n  Mint& operator/=(Mint\
    \ a){return (*this)*=a.inv();}\n\n  Mint operator+(Mint a) const{return Mint(v)+=a;}\n\
    \  Mint operator-(Mint a) const{return Mint(v)-=a;}\n  Mint operator*(Mint a)\
    \ const{return Mint(v)*=a;}\n  Mint operator/(Mint a) const{return Mint(v)/=a;}\n\
    \n  Mint operator-() const{return v?Mint(MOD-v):Mint(v);}\n\n  bool operator==(const\
    \ Mint a)const{return v==a.v;}\n  bool operator!=(const Mint a)const{return v!=a.v;}\n\
    \  bool operator <(const Mint a)const{return v <a.v;}\n\n  static Mint comb(long\
    \ long n,int k){\n    Mint num(1),dom(1);\n    for(int i=0;i<k;i++){\n      num*=Mint(n-i);\n\
    \      dom*=Mint(i+1);\n    }\n    return num/dom;\n  }\n};\ntemplate<typename\
    \ T, T MOD> constexpr T Mint<T, MOD>::mod;\ntemplate<typename T, T MOD>\nostream&\
    \ operator<<(ostream &os,Mint<T, MOD> m){os<<m.v;return os;}\n//END CUT HERE\n\
    #ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n#line 1 \"linearalgebra/matrix.cpp\"\
    \n\n#line 3 \"linearalgebra/matrix.cpp\"\nusing namespace std;\n#endif\n//BEGIN\
    \ CUT HERE\ntemplate<typename K>\nstruct Matrix{\n  typedef vector<K> arr;\n \
    \ typedef vector<arr> mat;\n  mat dat;\n\n  Matrix(size_t r,size_t c):dat(r,arr(c,K())){}\n\
    \  Matrix(mat dat):dat(dat){}\n\n  size_t size() const{return dat.size();}\n \
    \ bool empty() const{return size()==0;}\n  arr& operator[](size_t k){return dat[k];}\n\
    \  const arr& operator[](size_t k) const {return dat[k];}\n\n  static Matrix cross(const\
    \ Matrix &A,const Matrix &B){\n    Matrix res(A.size(),B[0].size());\n    for(int\
    \ i=0;i<(int)A.size();i++)\n      for(int j=0;j<(int)B[0].size();j++)\n      \
    \  for(int k=0;k<(int)B.size();k++)\n          res[i][j]+=A[i][k]*B[k][j];\n \
    \   return res;\n  }\n\n  static Matrix identity(size_t n){\n    Matrix res(n,n);\n\
    \    for(int i=0;i<(int)n;i++) res[i][i]=K(1);\n    return res;\n  }\n\n  Matrix\
    \ pow(long long n) const{\n    Matrix a(dat),res=identity(size());\n    while(n){\n\
    \      if(n&1) res=cross(res,a);\n      a=cross(a,a);\n      n>>=1;\n    }\n \
    \   return res;\n  }\n\n  template<typename T>\n  using ET = enable_if<is_floating_point<T>::value>;\n\
    \  template<typename T>\n  using EF = enable_if<!is_floating_point<T>::value>;\n\
    \n  template<typename T, typename ET<T>::type* = nullptr>\n  static bool is_zero(T\
    \ x){return abs(x)<1e-8;}\n  template<typename T, typename EF<T>::type* = nullptr>\n\
    \  static bool is_zero(T x){return x==T(0);}\n\n  template<typename T, typename\
    \ ET<T>::type* = nullptr>\n  static bool compare(T x,T y){return abs(x)<abs(y);}\n\
    \  template<typename T, typename EF<T>::type* = nullptr>\n  static bool compare(T\
    \ x,T y){(void)x;return y!=T(0);}\n\n  // assume regularity\n  static Matrix gauss_jordan(const\
    \ Matrix &A,const Matrix &B){\n    int n=A.size(),l=B[0].size();\n    Matrix C(n,n+l);\n\
    \    for(int i=0;i<n;i++){\n      for(int j=0;j<n;j++)\n        C[i][j]=A[i][j];\n\
    \      for(int j=0;j<l;j++)\n        C[i][n+j]=B[i][j];\n    }\n    for(int i=0;i<n;i++){\n\
    \      int p=i;\n      for(int j=i;j<n;j++)\n        if(compare(C[p][i],C[j][i]))\
    \ p=j;\n      swap(C[i],C[p]);\n      if(is_zero(C[i][i])) return Matrix(0,0);\n\
    \      for(int j=i+1;j<n+l;j++) C[i][j]/=C[i][i];\n      for(int j=0;j<n;j++){\n\
    \        if(i==j) continue;\n        for(int k=i+1;k<n+l;k++)\n          C[j][k]-=C[j][i]*C[i][k];\n\
    \      }\n    }\n    Matrix res(n,l);\n    for(int i=0;i<n;i++)\n      for(int\
    \ j=0;j<l;j++)\n        res[i][j]=C[i][n+j];\n    return res;\n  }\n\n  Matrix\
    \ inv() const{\n    Matrix B=identity(size());\n    return gauss_jordan(*this,B);\n\
    \  }\n\n  static arr linear_equations(const Matrix &A,const arr &b){\n    Matrix\
    \ B(b.size(),1);\n    for(int i=0;i<(int)b.size();i++) B[i][0]=b[i];\n    Matrix\
    \ tmp=gauss_jordan(A,B);\n    arr res(tmp.size());\n    for(int i=0;i<(int)tmp.size();i++)\
    \ res[i]=tmp[i][0];\n    return res;\n  }\n\n  K determinant() const{\n    Matrix\
    \ A(dat);\n    K res(1);\n    int n=size();\n    for(int i=0;i<n;i++){\n     \
    \ int p=i;\n      for(int j=i;j<n;j++)\n        if(compare(A[p][i],A[j][i])) p=j;\n\
    \      if(i!=p) swap(A[i],A[p]),res=-res;\n      if(is_zero(A[i][i])) return K(0);\n\
    \      res*=A[i][i];\n      for(int j=i+1;j<n;j++) A[i][j]/=A[i][i];\n      for(int\
    \ j=i+1;j<n;j++)\n        for(int k=i+1;k<n;k++)\n          A[j][k]-=A[j][i]*A[i][k];\n\
    \    }\n    return res;\n  }\n\n  static K sigma(K x,long long n){\n    Matrix\
    \ A(2,2);\n    A[0][0]=x;A[0][1]=0;\n    A[1][0]=1;A[1][1]=1;\n    return A.pow(n)[1][0];\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\ntemplate<typename T>\nstruct\
    \ Mint{\n  static T MOD;\n  T v;\n  Mint():v(0){}\n  Mint(signed v):v(v){}\n \
    \ Mint(long long t){v=t%MOD;if(v<0) v+=MOD;}\n\n  Mint pow(long long k){\n   \
    \ Mint res(1),tmp(v);\n    while(k){\n      if(k&1) res*=tmp;\n      tmp*=tmp;\n\
    \      k>>=1;\n    }\n    return res;\n  }\n\n  Mint inv(){return pow(MOD-2);}\n\
    \n  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}\n  Mint& operator-=(Mint\
    \ a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}\n  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return\
    \ *this;}\n  Mint& operator/=(Mint a){return (*this)*=a.inv();}\n\n  Mint operator+(Mint\
    \ a) const{return Mint(v)+=a;};\n  Mint operator-(Mint a) const{return Mint(v)-=a;};\n\
    \  Mint operator*(Mint a) const{return Mint(v)*=a;};\n  Mint operator/(Mint a)\
    \ const{return Mint(v)/=a;};\n\n  Mint operator-(){return v?MOD-v:v;}\n\n  bool\
    \ operator==(const Mint a)const{return v==a.v;}\n  bool operator!=(const Mint\
    \ a)const{return v!=a.v;}\n  bool operator <(const Mint a)const{return v <a.v;};\n\
    };\ntemplate<typename T> Mint<T> abs(Mint<T> a){return a;};\ntemplate<typename\
    \ T> T Mint<T>::MOD = 1e9+7;\n\n\nsigned ARC050_C(){\n  using ll = long long;\n\
    \  using M = Mint<ll>;\n  using MM = Matrix<M>;\n  ll a,b,m;\n  scanf(\"%lld %lld\
    \ %lld\",&a,&b,&m);\n  M::MOD = m;\n  ll c=__gcd(a,b);\n  M x=M((ll)10).pow(c);\n\
    \  M ans=MM::sigma(x,a/c)*MM::sigma(M((ll)10),b);\n  printf(\"%lld\\n\",ans.v);\n\
    \  return 0;\n}\n/*\n  verified on 2018/10/17\n  https://atcoder.jp/contests/arc050/tasks/arc050_c\n\
    */\n\nsigned SPOJ_MIFF(){\n  int first=1;\n  int n,p;\n  while(scanf(\"%d %d\"\
    ,&n,&p),n){\n    if(!first) puts(\"\");\n    first=0;\n    using M = Mint<int>;\n\
    \    M::MOD = p;\n    using MM = Matrix<M>;\n    MM A(n,n);\n    for(int i=0;i<n;i++)\n\
    \      for(int j=0;j<n;j++)\n        scanf(\"%d\",&A[i][j].v);\n    MM B=A.inv();\n\
    \    if(B.empty()) puts(\"singular\");\n    else{\n      for(int i=0;i<n;i++){\n\
    \        for(int j=0;j<n;j++){\n          if(j) printf(\" \");\n          printf(\"\
    %d\",B[i][j].v);\n        }\n        puts(\"\");\n      }\n    }\n  }\n  return\
    \ 0;\n}\n/*\n  verified on 2018/10/17\n  https://www.spoj.com/problems/MIFF/\n\
    */\n\nsigned SPOJ_MPOW(){\n  int T;\n  scanf(\"%d\",&T);\n  while(T--){\n    int\
    \ n,p;\n    scanf(\"%d %d\",&n,&p);\n    using M = Mint<int>;\n    M::MOD = 1e9+7;\n\
    \    using MM = Matrix<M>;\n    MM A(n,n);\n    for(int i=0;i<n;i++)\n      for(int\
    \ j=0;j<n;j++)\n        scanf(\"%d\",&A[i][j].v);\n    MM B=A.pow(p);\n    for(int\
    \ i=0;i<n;i++){\n      for(int j=0;j<n;j++){\n        if(j) printf(\" \");\n \
    \       printf(\"%d\",B[i][j].v);\n      }\n      puts(\"\");\n    }\n  }\n  return\
    \ 0;\n}\n/*\n  verified on 2018/10/17\n  https://www.spoj.com/problems/MPOW/\n\
    */\n\nsigned main(){\n  //ARC050_C();\n  //SPOJ_MIFF();\n  //SPOJ_MPOW();\n  return\
    \ 0;\n}\n#endif\n#line 9 \"test/yosupo/matrix_det.test.cpp\"\n#undef call_from_test\n\
    \nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  using M = Mint<int,\
    \ 998244353>;\n  using Mat = Matrix<M>;\n  int n;\n  cin>>n;\n\n  Mat A(n,n);\n\
    \  for(int i=0;i<n;i++)\n    for(int j=0;j<n;j++)\n      cin>>A[i][j].v;\n\n \
    \ cout<<A.determinant()<<endl;\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/matrix_det\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../mod/mint.cpp\"\n#include \"../../linearalgebra/matrix.cpp\"\n#undef\
    \ call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  using M = Mint<int, 998244353>;\n  using Mat = Matrix<M>;\n  int n;\n  cin>>n;\n\
    \n  Mat A(n,n);\n  for(int i=0;i<n;i++)\n    for(int j=0;j<n;j++)\n      cin>>A[i][j].v;\n\
    \n  cout<<A.determinant()<<endl;\n  return 0;\n}\n"
  dependsOn:
  - mod/mint.cpp
  - linearalgebra/matrix.cpp
  isVerificationFile: true
  path: test/yosupo/matrix_det.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 13:13:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/matrix_det.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/matrix_det.test.cpp
- /verify/test/yosupo/matrix_det.test.cpp.html
title: test/yosupo/matrix_det.test.cpp
---
