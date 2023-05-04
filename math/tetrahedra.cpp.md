---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: linearalgebra/matrix.cpp
    title: linearalgebra/matrix.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2060.test.cpp
    title: test/aoj/2060.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/tetrahedra.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../linearalgebra/matrix.cpp\"\n#undef call_from_test\n\
    \n#endif\n//BEGIN CUT HERE\nbool isTriangle(double a1,double a2,double a3){\n\
    \  if(a1+a2<=a3 or a2+a3<=a1 or a3+a1<=a2) return 0;\n  return 1;\n}\n\ndouble\
    \ tetrahedra(double OA,double OB,double OC,\n                  double AB,double\
    \ AC,double BC){\n  if(!isTriangle(OA,OB,AB)) return 0;\n  if(!isTriangle(OB,OC,BC))\
    \ return 0;\n  if(!isTriangle(OC,OA,AC)) return 0;\n  if(!isTriangle(AB,AC,BC))\
    \ return 0;\n  Matrix<double> A(5,5);\n  A[0][0]=    0;A[0][1]=AB*AB;A[0][2]=AC*AC;A[0][3]=OA*OA;A[0][4]=1;\n\
    \  A[1][0]=AB*AB;A[1][1]=    0;A[1][2]=BC*BC;A[1][3]=OB*OB;A[1][4]=1;\n  A[2][0]=AC*AC;A[2][1]=BC*BC;A[2][2]=\
    \    0;A[2][3]=OC*OC;A[2][4]=1;\n  A[3][0]=OA*OA;A[3][1]=OB*OB;A[3][2]=OC*OC;A[3][3]=\
    \    0;A[3][4]=1;\n  A[4][0]=    1;A[4][1]=    1;A[4][2]=    1;A[4][3]=    1;A[4][4]=0;\n\
    \  double res=A.determinant();\n  if(res<=0) return 0;\n  return sqrt(res/288.0);\n\
    }\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - linearalgebra/matrix.cpp
  isVerificationFile: false
  path: math/tetrahedra.cpp
  requiredBy: []
  timestamp: '2021-09-23 21:21:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2060.test.cpp
documentation_of: math/tetrahedra.cpp
layout: document
redirect_from:
- /library/math/tetrahedra.cpp
- /library/math/tetrahedra.cpp.html
title: math/tetrahedra.cpp
---
