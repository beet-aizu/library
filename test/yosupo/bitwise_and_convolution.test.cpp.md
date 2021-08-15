---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/bitwise/and.cpp
    title: convolution/bitwise/and.cpp
  - icon: ':heavy_check_mark:'
    path: convolution/bitwise/fwht.cpp
    title: convolution/bitwise/fwht.cpp
  - icon: ':heavy_check_mark:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_and_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_and_convolution
  bundledCode: "#line 1 \"test/yosupo/bitwise_and_convolution.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/bitwise_and_convolution\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#line 1 \"\
    mod/mint.cpp\"\n\n#line 3 \"mod/mint.cpp\"\nusing namespace std;\n#endif\n\n//BEGIN\
    \ CUT HERE\ntemplate<typename T, T MOD = 1000000007>\nstruct Mint{\n  inline static\
    \ constexpr T mod = MOD;\n  T v;\n  Mint():v(0){}\n  Mint(signed v):v(v){}\n \
    \ Mint(long long t){v=t%MOD;if(v<0) v+=MOD;}\n\n  Mint pow(long long k){\n   \
    \ Mint res(1),tmp(v);\n    while(k){\n      if(k&1) res*=tmp;\n      tmp*=tmp;\n\
    \      k>>=1;\n    }\n    return res;\n  }\n\n  static Mint add_identity(){return\
    \ Mint(0);}\n  static Mint mul_identity(){return Mint(1);}\n\n  Mint inv(){return\
    \ pow(MOD-2);}\n\n  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}\n\
    \  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}\n  Mint&\
    \ operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}\n  Mint& operator/=(Mint a){return\
    \ (*this)*=a.inv();}\n\n  Mint operator+(Mint a) const{return Mint(v)+=a;}\n \
    \ Mint operator-(Mint a) const{return Mint(v)-=a;}\n  Mint operator*(Mint a) const{return\
    \ Mint(v)*=a;}\n  Mint operator/(Mint a) const{return Mint(v)/=a;}\n\n  Mint operator+()\
    \ const{return *this;}\n  Mint operator-() const{return v?Mint(MOD-v):Mint(v);}\n\
    \n  bool operator==(const Mint a)const{return v==a.v;}\n  bool operator!=(const\
    \ Mint a)const{return v!=a.v;}\n\n  static Mint comb(long long n,int k){\n   \
    \ Mint num(1),dom(1);\n    for(int i=0;i<k;i++){\n      num*=Mint(n-i);\n    \
    \  dom*=Mint(i+1);\n    }\n    return num/dom;\n  }\n};\ntemplate<typename T,\
    \ T MOD>\nostream& operator<<(ostream &os,Mint<T, MOD> m){os<<m.v;return os;}\n\
    //END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n\
    #line 1 \"convolution/bitwise/fwht.cpp\"\n\n#line 3 \"convolution/bitwise/fwht.cpp\"\
    \nusing namespace std;\n#endif\n// https://kazuma8128.hatenablog.com/entry/2018/05/31/144519\n\
    //BEGIN CUT HERE\n// O(n \\log n)\ntemplate<typename T, typename F>\nvoid fwht(vector<T>\
    \ &as,F f){\n  int n=as.size();\n  for(int d=1;d<n;d<<=1)\n    for(int m=d<<1,i=0;i<n;i+=m)\n\
    \      for(int j=0;j<d;j++)\n        f(as[i+j],as[i+j+d]);\n}\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n#line 1 \"convolution/bitwise/and.cpp\"\n\n#line 3 \"convolution/bitwise/and.cpp\"\
    \nusing namespace std;\n#endif\n//BEGIN CUT HERE\nauto zeta=[](auto& lo,auto&\
    \ hi){lo+=hi;};\nauto moebius=[](auto& lo,auto& hi){lo-=hi;};\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n#line 10 \"test/yosupo/bitwise_and_convolution.test.cpp\"\n#undef call_from_test\n\
    \nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n;\n  cin>>n;\n\
    \n  using M = Mint<int, 998244353>;\n\n  int sz=1<<n;\n  vector<M> as(sz),bs(sz);\n\
    \  for(int i=0;i<sz;i++) cin>>as[i].v;\n  for(int i=0;i<sz;i++) cin>>bs[i].v;\n\
    \n  fwht(as,zeta);\n  fwht(bs,zeta);\n\n  for(int i=0;i<sz;i++) as[i]*=bs[i];\n\
    \n  fwht(as,moebius);\n\n  for(int i=0;i<sz;i++){\n    if(i) cout<<' ';\n    cout<<as[i];\n\
    \  }\n  cout<<endl;\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/bitwise_and_convolution\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../mod/mint.cpp\"\n#include \"../../convolution/bitwise/fwht.cpp\"\n#include\
    \ \"../../convolution/bitwise/and.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n;\n  cin>>n;\n\n  using M\
    \ = Mint<int, 998244353>;\n\n  int sz=1<<n;\n  vector<M> as(sz),bs(sz);\n  for(int\
    \ i=0;i<sz;i++) cin>>as[i].v;\n  for(int i=0;i<sz;i++) cin>>bs[i].v;\n\n  fwht(as,zeta);\n\
    \  fwht(bs,zeta);\n\n  for(int i=0;i<sz;i++) as[i]*=bs[i];\n\n  fwht(as,moebius);\n\
    \n  for(int i=0;i<sz;i++){\n    if(i) cout<<' ';\n    cout<<as[i];\n  }\n  cout<<endl;\n\
    \  return 0;\n}\n"
  dependsOn:
  - mod/mint.cpp
  - convolution/bitwise/fwht.cpp
  - convolution/bitwise/and.cpp
  isVerificationFile: true
  path: test/yosupo/bitwise_and_convolution.test.cpp
  requiredBy: []
  timestamp: '2021-03-25 09:46:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/bitwise_and_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/bitwise_and_convolution.test.cpp
- /verify/test/yosupo/bitwise_and_convolution.test.cpp.html
title: test/yosupo/bitwise_and_convolution.test.cpp
---
