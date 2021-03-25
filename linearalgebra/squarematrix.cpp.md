---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2397.test.cpp
    title: test/aoj/2397.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3074.test.cpp
    title: test/aoj/3074.test.cpp
  - icon: ':x:'
    path: test/yukicoder/0831.test.cpp
    title: test/yukicoder/0831.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linearalgebra/squarematrix.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename R, size_t N>\n\
    struct SquareMatrix{\n  typedef array<R, N> arr;\n  typedef array<arr, N> mat;\n\
    \  mat dat;\n\n  SquareMatrix(){\n    for(size_t i=0;i<N;i++)\n      for(size_t\
    \ j=0;j<N;j++)\n        dat[i][j]=R::add_identity();\n  }\n\n  bool operator==(const\
    \ SquareMatrix& a) const{\n    return dat==a.dat;\n  }\n\n  size_t size() const{return\
    \ N;}\n  arr& operator[](size_t k){return dat[k];}\n  const arr& operator[](size_t\
    \ k) const {return dat[k];}\n\n  static SquareMatrix add_identity(){return SquareMatrix();}\n\
    \  static SquareMatrix mul_identity(){\n    SquareMatrix res;\n    for(size_t\
    \ i=0;i<N;i++) res[i][i]=R::mul_identity();\n    return res;\n  }\n\n  SquareMatrix\
    \ operator*(const SquareMatrix &B) const{\n    SquareMatrix res;\n    for(size_t\
    \ i=0;i<N;i++)\n      for(size_t j=0;j<N;j++)\n        for(size_t k=0;k<N;k++)\n\
    \          res[i][j]=res[i][j]+(dat[i][k]*B[k][j]);\n    return res;\n  }\n\n\
    \  SquareMatrix operator+(const SquareMatrix &B) const{\n    SquareMatrix res;\n\
    \    for(size_t i=0;i<N;i++)\n      for(size_t j=0;j<N;j++)\n        res[i][j]=dat[i][j]+B[i][j];\n\
    \    return res;\n  }\n\n  SquareMatrix pow(long long n) const{\n    SquareMatrix\
    \ a=*this,res=mul_identity();\n    while(n){\n      if(n&1) res=res*a;\n     \
    \ a=a*a;\n      n>>=1;\n    }\n    return res;\n  }\n};\n//END CUT HERE\n#ifndef\
    \ call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename R, size_t N>\nstruct SquareMatrix{\n  typedef\
    \ array<R, N> arr;\n  typedef array<arr, N> mat;\n  mat dat;\n\n  SquareMatrix(){\n\
    \    for(size_t i=0;i<N;i++)\n      for(size_t j=0;j<N;j++)\n        dat[i][j]=R::add_identity();\n\
    \  }\n\n  bool operator==(const SquareMatrix& a) const{\n    return dat==a.dat;\n\
    \  }\n\n  size_t size() const{return N;}\n  arr& operator[](size_t k){return dat[k];}\n\
    \  const arr& operator[](size_t k) const {return dat[k];}\n\n  static SquareMatrix\
    \ add_identity(){return SquareMatrix();}\n  static SquareMatrix mul_identity(){\n\
    \    SquareMatrix res;\n    for(size_t i=0;i<N;i++) res[i][i]=R::mul_identity();\n\
    \    return res;\n  }\n\n  SquareMatrix operator*(const SquareMatrix &B) const{\n\
    \    SquareMatrix res;\n    for(size_t i=0;i<N;i++)\n      for(size_t j=0;j<N;j++)\n\
    \        for(size_t k=0;k<N;k++)\n          res[i][j]=res[i][j]+(dat[i][k]*B[k][j]);\n\
    \    return res;\n  }\n\n  SquareMatrix operator+(const SquareMatrix &B) const{\n\
    \    SquareMatrix res;\n    for(size_t i=0;i<N;i++)\n      for(size_t j=0;j<N;j++)\n\
    \        res[i][j]=dat[i][j]+B[i][j];\n    return res;\n  }\n\n  SquareMatrix\
    \ pow(long long n) const{\n    SquareMatrix a=*this,res=mul_identity();\n    while(n){\n\
    \      if(n&1) res=res*a;\n      a=a*a;\n      n>>=1;\n    }\n    return res;\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: linearalgebra/squarematrix.cpp
  requiredBy: []
  timestamp: '2020-03-06 20:39:01+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/0831.test.cpp
  - test/aoj/3074.test.cpp
  - test/aoj/2397.test.cpp
documentation_of: linearalgebra/squarematrix.cpp
layout: document
redirect_from:
- /library/linearalgebra/squarematrix.cpp
- /library/linearalgebra/squarematrix.cpp.html
title: linearalgebra/squarematrix.cpp
---
