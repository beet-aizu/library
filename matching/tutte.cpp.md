---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2983.test.cpp
    title: test/aoj/2983.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ matching/tutte.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../mod/mint.cpp\"\n#undef call_from_test\n\n\
    #endif\n//BEGIN CUT HERE\nint maximal_matching(vector< vector<int> > G){\n  int\
    \ n=G.size();\n\n  random_device rd;\n  mt19937 mt(rd());\n  using M = Mint<int>;\n\
    \  uniform_int_distribution<int> ud(1,M::mod-1);\n\n  vector< vector<M> > H(n,vector<M>(n,0));\n\
    \  for(int v=0;v<n;v++){\n    for(int u:G[v]){\n      if(u>=v) continue;\n   \
    \   M val(ud(mt));\n      H[u][v]= val;\n      H[v][u]=-val;\n    }\n  }\n\n \
    \ int res=0;\n  for(int i=0,j=0;i<n;i++){\n    while(j<n and H[i][j]==M(0)){\n\
    \      int p=i;\n      for(int k=i+1;k<n;k++)\n        if(H[k][j]!=M(0)) p=k;\n\
    \      if(i!=p) swap(H[i],H[p]);\n      else j++;\n    }\n    if(j==n) break;\n\
    \    M tmp=H[i][j].inv();\n    for(int s=j;s<n;s++) H[i][s]*=tmp;\n    for(int\
    \ k=i+1;k<n;k++)\n      for(int s=n-1;s>=j;s--)\n        H[k][s]-=H[k][j]*H[i][s];\n\
    \n    j++;res++;\n  }\n  return (res+1)/2;\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - mod/mint.cpp
  isVerificationFile: false
  path: matching/tutte.cpp
  requiredBy: []
  timestamp: '2021-03-25 09:46:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2983.test.cpp
documentation_of: matching/tutte.cpp
layout: document
redirect_from:
- /library/matching/tutte.cpp
- /library/matching/tutte.cpp.html
title: matching/tutte.cpp
---
