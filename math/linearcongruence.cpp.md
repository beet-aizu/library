---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/extgcd.cpp
    title: math/extgcd.cpp
  - icon: ':heavy_check_mark:'
    path: mod/inverse.cpp
    title: mod/inverse.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2659.test.cpp
    title: test/aoj/2659.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2970.test.cpp
    title: test/aoj/2970.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/linearcongruence.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"extgcd.cpp\"\n#include \"../mod/inverse.cpp\"\
    \n#undef call_from_test\n\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\npair<T,\
    \ T> linear_congruence(const vector<T> &A,\n                             const\
    \ vector<T> &B,\n                             const vector<T> &M){\n  T x=0,m=1;\n\
    \  for(int i=0;i<(int)A.size();i++){\n    T a=A[i]*m,b=B[i]-A[i]*x,d=__gcd(M[i],a);\n\
    \    if(b%d!=0) return make_pair(0,-1);\n    T t=b/d*mod_inverse(a/d,M[i]/d)%(M[i]/d);\n\
    \    x=x+m*t;\n    m*=M[i]/d;\n  }\n  return make_pair((x%m+m)%m,m);\n}\n//END\
    \ CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  dependsOn:
  - math/extgcd.cpp
  - mod/inverse.cpp
  isVerificationFile: false
  path: math/linearcongruence.cpp
  requiredBy: []
  timestamp: '2021-06-20 16:57:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2970.test.cpp
  - test/aoj/2659.test.cpp
documentation_of: math/linearcongruence.cpp
layout: document
redirect_from:
- /library/math/linearcongruence.cpp
- /library/math/linearcongruence.cpp.html
title: math/linearcongruence.cpp
---
