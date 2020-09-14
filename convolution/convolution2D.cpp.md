---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 2 \"convolution/convolution2D.cpp\"\n\n#ifndef call_from_test\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename\
    \ T,typename Transformer>\nstruct Convolution2D{\n  using Matrix = vector< vector<T>\
    \ >;\n  const Transformer tran;\n  Convolution2D(Transformer tran):tran(tran){}\n\
    \n  void transpose(Matrix &as){\n    int n=as.size(),m=as[0].size();\n    Matrix\
    \ cs(as);\n    as.assign(m,vector<T>(n));\n    for(int i=0;i<n;i++)\n      for(int\
    \ j=0;j<m;j++)\n        as[j][i]=cs[i][j];\n  }\n\n  void transform(Matrix &as,bool\
    \ f){\n    for(int t=0;t<2;t++){\n      for(auto &a:as) tran(a,f);\n      transpose(as);\n\
    \    }\n  }\n\n  Matrix multiply(Matrix as,Matrix bs){\n    int nt=as.size()+bs.size()-1;\n\
    \    int mt=as[0].size()+bs[0].size()-1;\n    int n=1,m=1;\n    while(n<nt) n<<=1;\n\
    \    while(m<mt) m<<=1;\n    as.resize(n);bs.resize(n);\n    for(int i=0;i<n;i++){\n\
    \      as[i].resize(m,T(0));\n      bs[i].resize(m,T(0));\n    }\n    transform(as,0);transform(bs,0);\n\
    \    for(int i=0;i<n;i++)\n      for(int j=0;j<m;j++)\n        as[i][j]*=bs[i][j];\n\
    \    transform(as,1);\n    return as;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T,typename Transformer>\n\
    struct Convolution2D{\n  using Matrix = vector< vector<T> >;\n  const Transformer\
    \ tran;\n  Convolution2D(Transformer tran):tran(tran){}\n\n  void transpose(Matrix\
    \ &as){\n    int n=as.size(),m=as[0].size();\n    Matrix cs(as);\n    as.assign(m,vector<T>(n));\n\
    \    for(int i=0;i<n;i++)\n      for(int j=0;j<m;j++)\n        as[j][i]=cs[i][j];\n\
    \  }\n\n  void transform(Matrix &as,bool f){\n    for(int t=0;t<2;t++){\n    \
    \  for(auto &a:as) tran(a,f);\n      transpose(as);\n    }\n  }\n\n  Matrix multiply(Matrix\
    \ as,Matrix bs){\n    int nt=as.size()+bs.size()-1;\n    int mt=as[0].size()+bs[0].size()-1;\n\
    \    int n=1,m=1;\n    while(n<nt) n<<=1;\n    while(m<mt) m<<=1;\n    as.resize(n);bs.resize(n);\n\
    \    for(int i=0;i<n;i++){\n      as[i].resize(m,T(0));\n      bs[i].resize(m,T(0));\n\
    \    }\n    transform(as,0);transform(bs,0);\n    for(int i=0;i<n;i++)\n     \
    \ for(int j=0;j<m;j++)\n        as[i][j]*=bs[i][j];\n    transform(as,1);\n  \
    \  return as;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE\
    \ HERE\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3074.test.cpp
    title: test/aoj/3074.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2977.test.cpp
    title: test/aoj/2977.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2560.test.cpp
    title: test/aoj/2560.test.cpp
  isVerificationFile: false
  path: convolution/convolution2D.cpp
  requiredBy: []
  timestamp: '2020-03-12 17:02:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - test/aoj/3074.test.cpp
  - test/aoj/2977.test.cpp
  - test/aoj/2560.test.cpp
documentation_of: convolution/convolution2D.cpp
layout: document
redirect_from:
- /library/convolution/convolution2D.cpp
- /library/convolution/convolution2D.cpp.html
title: convolution/convolution2D.cpp
---
