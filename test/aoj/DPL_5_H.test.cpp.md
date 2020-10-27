---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  - icon: ':question:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_H
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_H
  bundledCode: "#line 1 \"test/aoj/DPL_5_H.test.cpp\"\n// verification-helper: PROBLEM\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_H\n\n#include<bits/stdc++.h>\n\
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
    #ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n#line 1 \"combinatorics/enumeration.cpp\"\
    \n\n#line 3 \"combinatorics/enumeration.cpp\"\nusing namespace std;\n#endif\n\n\
    //BEGIN CUT HERE\ntemplate<typename M_>\nclass Enumeration{\n  using M = M_;\n\
    protected:\n  static vector<M> fact,finv,invs;\npublic:\n  static void init(int\
    \ n){\n    n=min<decltype(M::mod)>(n,M::mod-1);\n\n    int m=fact.size();\n  \
    \  if(n<m) return;\n\n    fact.resize(n+1,1);\n    finv.resize(n+1,1);\n    invs.resize(n+1,1);\n\
    \n    if(m==0) m=1;\n    for(int i=m;i<=n;i++) fact[i]=fact[i-1]*M(i);\n    finv[n]=M(1)/fact[n];\n\
    \    for(int i=n;i>=m;i--) finv[i-1]=finv[i]*M(i);\n    for(int i=m;i<=n;i++)\
    \ invs[i]=finv[i]*fact[i-1];\n  }\n\n  static M Fact(int n){\n    init(n);\n \
    \   return fact[n];\n  }\n  static M Finv(int n){\n    init(n);\n    return finv[n];\n\
    \  }\n  static M Invs(int n){\n    init(n);\n    return invs[n];\n  }\n\n  static\
    \ M C(int n,int k){\n    if(n<k or k<0) return M(0);\n    init(n);\n    return\
    \ fact[n]*finv[n-k]*finv[k];\n  }\n\n  static M P(int n,int k){\n    if(n<k or\
    \ k<0) return M(0);\n    init(n);\n    return fact[n]*finv[n-k];\n  }\n\n  //\
    \ put n identical balls into k distinct boxes\n  static M H(int n,int k){\n  \
    \  if(n<0 or k<0) return M(0);\n    if(!n and !k) return M(1);\n    init(n+k);\n\
    \    return C(n+k-1,n);\n  }\n};\ntemplate<typename M>\nvector<M> Enumeration<M>::fact=vector<M>();\n\
    template<typename M>\nvector<M> Enumeration<M>::finv=vector<M>();\ntemplate<typename\
    \ M>\nvector<M> Enumeration<M>::invs=vector<M>();\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n#line 9 \"test/aoj/DPL_5_H.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  int n,k;\n  scanf(\"%d %d\",&n,&k);\n\
    \  printf(\"%d\\n\",(n<=k));\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_H\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../mod/mint.cpp\"\n#include \"../../combinatorics/enumeration.cpp\"\n#undef\
    \ call_from_test\n\nsigned main(){\n  int n,k;\n  scanf(\"%d %d\",&n,&k);\n  printf(\"\
    %d\\n\",(n<=k));\n  return 0;\n}\n"
  dependsOn:
  - mod/mint.cpp
  - combinatorics/enumeration.cpp
  isVerificationFile: true
  path: test/aoj/DPL_5_H.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 13:13:52+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DPL_5_H.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_5_H.test.cpp
- /verify/test/aoj/DPL_5_H.test.cpp.html
title: test/aoj/DPL_5_H.test.cpp
---
