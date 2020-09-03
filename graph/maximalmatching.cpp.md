---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 58, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/maximalmatching.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../mod/mint.cpp\"\n#undef call_from_test\n\n\
    #endif\n//BEGIN CUT HERE\nint maximal_matching(vector< vector<int> > G){\n  int\
    \ n=G.size();\n\n  random_device rd;\n  mt19937 mt(rd());\n  using M = Mint<int>;\n\
    \  uniform_int_distribution<int> ud(1,M::mod-1);\n\n  vector< vector<M> > H(n,vector<M>(n,0));\n\
    \  for(int v=0;v<n;v++){\n    for(int u:G[v]){\n      if(u>=v) continue;\n   \
    \   M val(ud(mt));\n      H[u][v]= val;\n      H[v][u]=-val;\n    }\n  }\n\n \
    \ int res=0;\n  for(int i=0,j=0;i<n;i++){\n    while(j<n&&H[i][j]==M(0)){\n  \
    \    int p=i;\n      for(int k=i+1;k<n;k++)\n        if(H[k][j]!=M(0)) p=k;\n\
    \      if(i!=p) swap(H[i],H[p]);\n      else j++;\n    }\n    if(j==n) break;\n\
    \    M tmp=H[i][j].inv();\n    for(int s=j;s<n;s++) H[i][s]*=tmp;\n    for(int\
    \ k=i+1;k<n;k++)\n      for(int s=n-1;s>=j;s--)\n        H[k][s]-=H[k][j]*H[i][s];\n\
    \n    j++;res++;\n  }\n  return (res+1)/2;\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - mod/mint.cpp
  extendedDependsOn:
  - icon: ':warning:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2983.test.cpp
    title: test/aoj/2983.test.cpp
  extendedVerifiedWith: []
  isVerificationFile: false
  path: graph/maximalmatching.cpp
  requiredBy:
  - test/aoj/2983.test.cpp
  timestamp: '2020-03-12 17:02:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: graph/maximalmatching.cpp
layout: document
redirect_from:
- /library/graph/maximalmatching.cpp
- /library/graph/maximalmatching.cpp.html
title: graph/maximalmatching.cpp
---
