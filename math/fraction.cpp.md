---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1338.test.cpp
    title: test/aoj/1338.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4941.test.cpp
    title: test/yukicoder/4941.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/fraction.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct fraction{\n  T\
    \ num,den;\n  fraction(T n,T d):num(n),den(d){\n    assert(den!=0);\n    if(den<0)\
    \ num*=-1,den*=-1;\n    T tmp=gcd(abs(num),abs(den));\n    num/=tmp;\n    den/=tmp;\n\
    \  }\n  const fraction operator+(const fraction& a) const{\n    return fraction(num*a.den+a.num*den,den*a.den);\n\
    \  }\n  const fraction operator-(const fraction& a) const{\n    return fraction(num*a.den-a.num*den,den*a.den);\n\
    \  }\n  const fraction operator*(const fraction& a) const{\n    return fraction(num*a.num,den*a.den);\n\
    \  }\n  const fraction operator/(const fraction& a) const{\n    return fraction(num*a.den,den*a.num);\n\
    \  }\n  const fraction operator*(T k) const{return fraction(num*k,den);}\n  const\
    \ fraction operator/(T k) const{return fraction(num,den*k);}\n#define define_cmp(op)\
    \ \\\n  bool operator op (const fraction& a) const{return num*a.den op a.num*den;}\n\
    \  define_cmp(==)\n  define_cmp(!=)\n  define_cmp(<)\n  define_cmp(>)\n  define_cmp(<=)\n\
    \  define_cmp(>=)\n#undef define_cmp\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct fraction{\n  T num,den;\n\
    \  fraction(T n,T d):num(n),den(d){\n    assert(den!=0);\n    if(den<0) num*=-1,den*=-1;\n\
    \    T tmp=gcd(abs(num),abs(den));\n    num/=tmp;\n    den/=tmp;\n  }\n  const\
    \ fraction operator+(const fraction& a) const{\n    return fraction(num*a.den+a.num*den,den*a.den);\n\
    \  }\n  const fraction operator-(const fraction& a) const{\n    return fraction(num*a.den-a.num*den,den*a.den);\n\
    \  }\n  const fraction operator*(const fraction& a) const{\n    return fraction(num*a.num,den*a.den);\n\
    \  }\n  const fraction operator/(const fraction& a) const{\n    return fraction(num*a.den,den*a.num);\n\
    \  }\n  const fraction operator*(T k) const{return fraction(num*k,den);}\n  const\
    \ fraction operator/(T k) const{return fraction(num,den*k);}\n#define define_cmp(op)\
    \ \\\n  bool operator op (const fraction& a) const{return num*a.den op a.num*den;}\n\
    \  define_cmp(==)\n  define_cmp(!=)\n  define_cmp(<)\n  define_cmp(>)\n  define_cmp(<=)\n\
    \  define_cmp(>=)\n#undef define_cmp\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: math/fraction.cpp
  requiredBy: []
  timestamp: '2021-05-23 16:26:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/4941.test.cpp
  - test/aoj/1338.test.cpp
documentation_of: math/fraction.cpp
layout: document
redirect_from:
- /library/math/fraction.cpp
- /library/math/fraction.cpp.html
title: math/fraction.cpp
---
