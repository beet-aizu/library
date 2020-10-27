---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_E
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_E
  bundledCode: "#line 1 \"test/aoj/DPL_5_E.test.cpp\"\n// verification-helper: PROBLEM\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_E\n\n#include<bits/stdc++.h>\n\
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
    #ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n#line 8 \"test/aoj/DPL_5_E.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  int n,k;\n  scanf(\"%d %d\",&n,&k);\n\
    \  printf(\"%d\\n\",Mint<int>::comb(k,n).v);\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_E\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../mod/mint.cpp\"\n#undef call_from_test\n\nsigned main(){\n  int n,k;\n\
    \  scanf(\"%d %d\",&n,&k);\n  printf(\"%d\\n\",Mint<int>::comb(k,n).v);\n  return\
    \ 0;\n}\n"
  dependsOn:
  - mod/mint.cpp
  isVerificationFile: true
  path: test/aoj/DPL_5_E.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 13:13:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_5_E.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_5_E.test.cpp
- /verify/test/aoj/DPL_5_E.test.cpp.html
title: test/aoj/DPL_5_E.test.cpp
---
