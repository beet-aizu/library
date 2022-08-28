---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: linearalgebra/matrix.cpp
    title: linearalgebra/matrix.cpp
  - icon: ':heavy_check_mark:'
    path: mod/factorial.cpp
    title: mod/factorial.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0422.test.cpp
    title: test/aoj/0422.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1504.test.cpp
    title: test/yukicoder/1504.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4569.test.cpp
    title: test/yukicoder/4569.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mod/rint.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct Rint{\n  inline\
    \ static T mod;\n  static void set_mod(T nmod){mod=nmod;}\n\n  T v;\n  Rint():v(0){}\n\
    \  Rint(signed v):v(v){}\n  Rint(long long t){v=t%mod;if(v<0) v+=mod;}\n\n  Rint\
    \ pow(long long k){\n    Rint res(1),tmp(v);\n    while(k){\n      if(k&1) res*=tmp;\n\
    \      tmp*=tmp;\n      k>>=1;\n    }\n    return res;\n  }\n\n  static Rint add_identity(){return\
    \ Rint(0);}\n  static Rint mul_identity(){return Rint(1);}\n\n  Rint inv(){return\
    \ pow(mod-2);}\n\n  Rint& operator+=(Rint a){v+=a.v;if(v>=mod)v-=mod;return *this;}\n\
    \  Rint& operator-=(Rint a){v+=mod-a.v;if(v>=mod)v-=mod;return *this;}\n  Rint&\
    \ operator*=(Rint a){v=1LL*v*a.v%mod;return *this;}\n  Rint& operator/=(Rint a){return\
    \ (*this)*=a.inv();}\n\n  Rint operator+(Rint a) const{return Rint(v)+=a;}\n \
    \ Rint operator-(Rint a) const{return Rint(v)-=a;}\n  Rint operator*(Rint a) const{return\
    \ Rint(v)*=a;}\n  Rint operator/(Rint a) const{return Rint(v)/=a;}\n\n  Rint operator-()\
    \ const{return v?Rint(mod-v):Rint(v);}\n\n  bool operator==(const Rint a)const{return\
    \ v==a.v;}\n  bool operator!=(const Rint a)const{return v!=a.v;}\n  bool operator\
    \ <(const Rint a)const{return v <a.v;}\n};\ntemplate<typename T>\nostream& operator<<(ostream\
    \ &os,Rint<T> m){os<<m.v;return os;}\n//END CUT HERE\n#ifndef call_from_test\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct Rint{\n  inline static\
    \ T mod;\n  static void set_mod(T nmod){mod=nmod;}\n\n  T v;\n  Rint():v(0){}\n\
    \  Rint(signed v):v(v){}\n  Rint(long long t){v=t%mod;if(v<0) v+=mod;}\n\n  Rint\
    \ pow(long long k){\n    Rint res(1),tmp(v);\n    while(k){\n      if(k&1) res*=tmp;\n\
    \      tmp*=tmp;\n      k>>=1;\n    }\n    return res;\n  }\n\n  static Rint add_identity(){return\
    \ Rint(0);}\n  static Rint mul_identity(){return Rint(1);}\n\n  Rint inv(){return\
    \ pow(mod-2);}\n\n  Rint& operator+=(Rint a){v+=a.v;if(v>=mod)v-=mod;return *this;}\n\
    \  Rint& operator-=(Rint a){v+=mod-a.v;if(v>=mod)v-=mod;return *this;}\n  Rint&\
    \ operator*=(Rint a){v=1LL*v*a.v%mod;return *this;}\n  Rint& operator/=(Rint a){return\
    \ (*this)*=a.inv();}\n\n  Rint operator+(Rint a) const{return Rint(v)+=a;}\n \
    \ Rint operator-(Rint a) const{return Rint(v)-=a;}\n  Rint operator*(Rint a) const{return\
    \ Rint(v)*=a;}\n  Rint operator/(Rint a) const{return Rint(v)/=a;}\n\n  Rint operator-()\
    \ const{return v?Rint(mod-v):Rint(v);}\n\n  bool operator==(const Rint a)const{return\
    \ v==a.v;}\n  bool operator!=(const Rint a)const{return v!=a.v;}\n  bool operator\
    \ <(const Rint a)const{return v <a.v;}\n};\ntemplate<typename T>\nostream& operator<<(ostream\
    \ &os,Rint<T> m){os<<m.v;return os;}\n//END CUT HERE\n#ifndef call_from_test\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/rint.cpp
  requiredBy:
  - mod/factorial.cpp
  - linearalgebra/matrix.cpp
  timestamp: '2021-03-25 09:21:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1504.test.cpp
  - test/yukicoder/4569.test.cpp
  - test/aoj/0422.test.cpp
documentation_of: mod/rint.cpp
layout: document
redirect_from:
- /library/mod/rint.cpp
- /library/mod/rint.cpp.html
title: mod/rint.cpp
---
