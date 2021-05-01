---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/rollinghash.cpp
    title: string/rollinghash.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1312.test.cpp
    title: test/aoj/1312.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_C.test.cpp
    title: test/aoj/ALDS1_14_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/rectanglehash.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"rollinghash.cpp\"\n#undef call_from_test\n\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename T,T MOD,T B1,T B2>\nauto rectangle_hash(vector<string>\
    \ vs,int r,int c){\n  vector< RollingHash<T, MOD, B1> > hs;\n  for(string s:vs)\
    \ hs.emplace_back(s);\n\n  int h=vs.size(),w=vs[0].size();\n  vector< vector<T>\
    \ > res(h-r+1,vector<T>(w-c+1));\n\n  for(int j=0;j+c<=w;j++){\n    vector<T>\
    \ ts(h);\n    for(int i=0;i<h;i++)\n      ts[i]=hs[i].find(j,j+c);\n\n    RollingHash<T,\
    \ MOD, B2> rh(ts);\n    for(int i=0;i+r<=h;i++)\n      res[i][j]=rh.find(i,i+r);\n\
    \  }\n  return res;\n}\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn:
  - string/rollinghash.cpp
  isVerificationFile: false
  path: string/rectanglehash.cpp
  requiredBy: []
  timestamp: '2020-10-27 19:04:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1312.test.cpp
  - test/aoj/ALDS1_14_C.test.cpp
documentation_of: string/rectanglehash.cpp
layout: document
redirect_from:
- /library/string/rectanglehash.cpp
- /library/string/rectanglehash.cpp.html
title: string/rectanglehash.cpp
---
