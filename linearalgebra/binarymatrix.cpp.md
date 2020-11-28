---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/fastio.cpp
    title: tools/fastio.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1308.test.cpp
    title: test/aoj/1308.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2624.test.cpp
    title: test/aoj/2624.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://codeforces.com/contest/736/problem/D
    - https://atcoder.jp/contests/arc054/tasks/arc054_c
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ linearalgebra/binarymatrix.cpp: line 82: unable to process #include in #if /\
    \ #ifdef / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\nconst int MAX = 2002;\nusing BS = bitset<MAX*2>;\nusing\
    \ mat = vector<BS>;\n\nvoid gauss(mat &v){\n  int n=v.size();\n  for(int i=0;i<n;i++){\n\
    \    for(int k=i;k<n;k++){\n      if(v[k][i]){\n        swap(v[i],v[k]);\n   \
    \     break;\n      }\n    }\n    for(int k=0;k<n;k++)\n      if(i!=k and v[k][i])\
    \ v[k]^=v[i];\n  }\n}\n\nint mrank(mat v,int m){\n  int n=v.size();\n  int r=0,c=0;\n\
    \  for(int i=0;i<n;i++){\n    int s=-1;\n    while(c<m){\n      for(int j=i;j<n;j++){\n\
    \        if(v[j][c]){\n          s=j;\n          break;\n        }\n      }\n\
    \      if(~s) break;\n      c++;\n    }\n    if(c>=m) break;\n\n    swap(v[i],v[s]);\n\
    \    for(int j=0;j<n;j++)\n      if(i!=j and v[j][c]) v[j]^=v[i];\n\n    r++;c++;\n\
    \  }\n  return r;\n}\n\nmat mul(const mat &a,const mat &b){\n  int n=a.size();\n\
    \  vector<vector<int> > tmp(n,vector<int>(n,0));\n  mat res(n,BS(0));\n  for(int\
    \ i=0;i<n;i++)\n    for(int j=0;j<n;j++)\n      for(int k=0;k<n;k++)\n       \
    \ tmp[i][j]+=(a[i][k]&b[k][j]);\n\n  for(int i=0;i<n;i++)\n    for(int j=0;j<n;j++)\n\
    \      res[i][j]=tmp[i][j]&1;\n\n  return res;\n}\n\nmat mat_pow(mat v,long long\
    \ k){\n  int n=v.size();\n  mat res(n,BS(0));\n  for(int i=0;i<n;i++)\n    res[i][i]=1;\n\
    \  while(k){\n    if(k&1) res=mul(res,v);\n    v=mul(v,v);\n    k>>=1;\n  }\n\
    \  return res;\n}\n//END CUT HERE\n#ifndef call_from_test\n\n#define call_from_test\n\
    #include \"../tools/fastio.cpp\"\n#undef call_from_test\n\nsigned CFR382_D(){\n\
    \  int n,m;\n  cin>>n>>m;\n  mat v(n,BS(0));\n  for(int i=0;i<n;i++) v[i][n+i]=1;\n\
    \  vector<int> as(m),bs(m);\n  for(int i=0;i<m;i++){\n    cin>>as[i]>>bs[i];\n\
    \    as[i]--;bs[i]--;\n    v[as[i]][bs[i]]=1;\n  }\n  gauss(v);\n  for(int i=0;i<m;i++)\n\
    \    cout<<(v[bs[i]][as[i]+n]?\"NO\":\"YES\")<<\"\\n\";\n  cout<<flush;\n  return\
    \ 0;\n}\n/*\n  verified on 2019/12/17\n  http://codeforces.com/contest/736/problem/D\n\
    */\n\nsigned ARC054_D(){\n  int n;\n  cin>>n;\n  mat v(n,BS(0));\n  for(int i=0;i<n;i++){\n\
    \    for(int j=0;j<n;j++){\n      char c;\n      cin>>c;\n      v[i][j]=c-'0';\n\
    \    }\n  }\n  int ans=mrank(v,n);\n  cout<<(ans==n?\"Odd\":\"Even\")<<endl;\n\
    \  return 0;\n}\n/*\n  verified on 2019/12/17\n  https://atcoder.jp/contests/arc054/tasks/arc054_c\n\
    */\n\nsigned main(){\n  //CFR382_D();\n  //ARC054_D();\n  return 0;\n}\n\n#endif\n"
  dependsOn:
  - tools/fastio.cpp
  isVerificationFile: false
  path: linearalgebra/binarymatrix.cpp
  requiredBy: []
  timestamp: '2020-10-27 16:01:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2624.test.cpp
  - test/aoj/1308.test.cpp
documentation_of: linearalgebra/binarymatrix.cpp
layout: document
redirect_from:
- /library/linearalgebra/binarymatrix.cpp
- /library/linearalgebra/binarymatrix.cpp.html
title: linearalgebra/binarymatrix.cpp
---
