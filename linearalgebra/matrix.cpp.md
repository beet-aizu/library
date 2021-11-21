---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/rint.cpp
    title: mod/rint.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: linearalgebra/tree_theorem.cpp
    title: linearalgebra/tree_theorem.cpp
  - icon: ':heavy_check_mark:'
    path: math/tetrahedra.cpp
    title: math/tetrahedra.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0314.test.cpp
    title: test/aoj/0314.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1328.test.cpp
    title: test/aoj/1328.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2060.test.cpp
    title: test/aoj/2060.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/matrix_det.test.cpp
    title: test/yosupo/matrix_det.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://www.spoj.com/problems/MIFF/
    - https://www.spoj.com/problems/MPOW/
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ linearalgebra/matrix.cpp: line 128: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename K>\nstruct Matrix{\n  typedef vector<K> arr;\n\
    \  typedef vector<arr> mat;\n  mat dat;\n\n  Matrix(size_t r,size_t c):dat(r,arr(c,K())){}\n\
    \  Matrix(mat dat):dat(dat){}\n\n  size_t size() const{return dat.size();}\n \
    \ bool empty() const{return size()==0;}\n  arr& operator[](size_t k){return dat[k];}\n\
    \  const arr& operator[](size_t k) const {return dat[k];}\n\n  static Matrix matmul(const\
    \ Matrix &A,const Matrix &B){\n    Matrix res(A.size(),B[0].size());\n    for(int\
    \ i=0;i<(int)A.size();i++)\n      for(int j=0;j<(int)B[0].size();j++)\n      \
    \  for(int k=0;k<(int)B.size();k++)\n          res[i][j]+=A[i][k]*B[k][j];\n \
    \   return res;\n  }\n\n  static Matrix identity(size_t n){\n    Matrix res(n,n);\n\
    \    for(int i=0;i<(int)n;i++) res[i][i]=K(1);\n    return res;\n  }\n\n  Matrix\
    \ pow(long long n) const{\n    assert(n>=0);\n    assert(dat.size()==dat[0].size());\n\
    \    Matrix a(dat),res=identity(size());\n    while(n){\n      if(n&1) res=matmul(res,a);\n\
    \      a=matmul(a,a);\n      n>>=1;\n    }\n    return res;\n  }\n\n  template<typename\
    \ T>\n  using ET = enable_if<is_floating_point<T>::value>;\n  template<typename\
    \ T>\n  using EF = enable_if<!is_floating_point<T>::value>;\n\n  template<typename\
    \ T, typename ET<T>::type* = nullptr>\n  static bool is_zero(T x){return abs(x)<1e-8;}\n\
    \  template<typename T, typename EF<T>::type* = nullptr>\n  static bool is_zero(T\
    \ x){return x==T(0);}\n\n  template<typename T, typename ET<T>::type* = nullptr>\n\
    \  static bool compare(T x,T y){return abs(x)<abs(y);}\n  template<typename T,\
    \ typename EF<T>::type* = nullptr>\n  static bool compare(T,T y){return !is_zero(y);}\n\
    \n  // assume regularity\n  static Matrix gauss_jordan(const Matrix &A,const Matrix\
    \ &B){\n    int n=A.size(),l=B[0].size();\n    Matrix C(n,n+l);\n    for(int i=0;i<n;i++){\n\
    \      for(int j=0;j<n;j++)\n        C[i][j]=A[i][j];\n      for(int j=0;j<l;j++)\n\
    \        C[i][n+j]=B[i][j];\n    }\n    for(int i=0;i<n;i++){\n      int p=i;\n\
    \      for(int j=i;j<n;j++)\n        if(compare(C[p][i],C[j][i])) p=j;\n     \
    \ swap(C[i],C[p]);\n      if(is_zero(C[i][i])) return Matrix(0,0);\n      for(int\
    \ j=i+1;j<n+l;j++) C[i][j]/=C[i][i];\n      for(int j=0;j<n;j++){\n        if(i==j)\
    \ continue;\n        for(int k=i+1;k<n+l;k++)\n          C[j][k]-=C[j][i]*C[i][k];\n\
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
    \    }\n    return res;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n#define\
    \ call_from_test\n#include \"../mod/rint.cpp\"\n#undef call_from_test\n\n// test\
    \ inv\nsigned SPOJ_MIFF(){\n  int first=1;\n  int n,p;\n  while(scanf(\"%d %d\"\
    ,&n,&p),n){\n    if(!first) puts(\"\");\n    first=0;\n    using M = Rint<int>;\n\
    \    M::set_mod(p);\n    using MM = Matrix<M>;\n    MM A(n,n);\n    for(int i=0;i<n;i++)\n\
    \      for(int j=0;j<n;j++)\n        scanf(\"%d\",&A[i][j].v);\n    MM B=A.inv();\n\
    \    if(B.empty()) puts(\"singular\");\n    else{\n      for(int i=0;i<n;i++){\n\
    \        for(int j=0;j<n;j++){\n          if(j) printf(\" \");\n          printf(\"\
    %d\",B[i][j].v);\n        }\n        puts(\"\");\n      }\n    }\n  }\n  return\
    \ 0;\n}\n/*\n  verified on 2021/09/23\n  https://www.spoj.com/problems/MIFF/\n\
    */\n\n// test pow\nsigned SPOJ_MPOW(){\n  int T;\n  scanf(\"%d\",&T);\n  while(T--){\n\
    \    int n,p;\n    scanf(\"%d %d\",&n,&p);\n    using M = Rint<int>;\n    M::set_mod(1e9+7);\n\
    \    using MM = Matrix<M>;\n    MM A(n,n);\n    for(int i=0;i<n;i++)\n      for(int\
    \ j=0;j<n;j++)\n        scanf(\"%d\",&A[i][j].v);\n    MM B=A.pow(p);\n    for(int\
    \ i=0;i<n;i++){\n      for(int j=0;j<n;j++){\n        if(j) printf(\" \");\n \
    \       printf(\"%d\",B[i][j].v);\n      }\n      puts(\"\");\n    }\n  }\n  return\
    \ 0;\n}\n/*\n  verified on 2021/09/23\n  https://www.spoj.com/problems/MPOW/\n\
    */\n\nsigned main(){\n  //SPOJ_MIFF();\n  //SPOJ_MPOW();\n  return 0;\n}\n#endif\n"
  dependsOn:
  - mod/rint.cpp
  isVerificationFile: false
  path: linearalgebra/matrix.cpp
  requiredBy:
  - linearalgebra/tree_theorem.cpp
  - math/tetrahedra.cpp
  timestamp: '2021-09-23 21:21:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0314.test.cpp
  - test/aoj/1328.test.cpp
  - test/aoj/2060.test.cpp
  - test/yosupo/matrix_det.test.cpp
documentation_of: linearalgebra/matrix.cpp
layout: document
redirect_from:
- /library/linearalgebra/matrix.cpp
- /library/linearalgebra/matrix.cpp.html
title: linearalgebra/matrix.cpp
---
