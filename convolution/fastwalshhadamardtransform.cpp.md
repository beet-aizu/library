---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1119/problem/H
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ convolution/fastwalshhadamardtransform.cpp: line 46: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nvoid FWT(vector<T> &as){\n\
    \  int n=as.size();\n  for(int d=1;d<n;d<<=1){\n    for(int m=d<<1,i=0;i<n;i+=m){\n\
    \      for(int j=0;j<d;j++){\n        T x=as[i+j],y=as[i+j+d];\n        as[i+j+0]=x+y;\n\
    \        as[i+j+d]=x-y;\n      }\n    }\n  }\n}\n\ntemplate<typename T>\nvoid\
    \ multiply(vector<T> &as,const vector<T> &bs){\n  for(int i=0;i<(int)as.size();i++)\n\
    \    as[i]=as[i]*bs[i];\n}\n\ntemplate<typename T>\nvoid UFWT(vector<T> &as){\n\
    \  T inv2=T(2).inv();\n  int n=as.size();\n  for(int d=1;d<n;d<<=1){\n    for(int\
    \ m=d<<1,i=0;i<n;i+=m){\n      for(int j=0;j<d;j++){\n        T x=as[i+j],y=as[i+j+d];\n\
    \        as[i+j+0]=(x+y)*inv2;\n        as[i+j+d]=(x-y)*inv2;\n      }\n    }\n\
    \  }\n}\n//END CUT HERE\n#ifndef call_from_test\n\n#define call_from_test\n#include\
    \ \"../mod/mint.cpp\"\n#undef call_from_test\n\n//INSERT ABOVE HERE\nsigned CGR002_H(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  using ll = long long;\n  const\
    \ int MOD = 998244353;\n  using M = Mint<int, MOD>;\n\n  int n,k;\n  cin>>n>>k;\n\
    \n  ll p,q,r;\n  cin>>p>>q>>r;\n\n  int ofs=0;\n  vector<int> a(n),b(n),c(n);\n\
    \  for(int i=0;i<n;i++){\n    cin>>a[i]>>b[i]>>c[i];\n    ofs^=a[i];\n    b[i]^=a[i];\n\
    \    c[i]^=a[i];\n    a[i]=0;\n  }\n\n  vector<vector<ll> > vm((1<<k),vector<ll>(4,0));\n\
    \  for(int t=0;t<4;t++){\n    vector<ll> vs(1<<k,0);\n    for(int i=0;i<n;i++){\n\
    \      vs[a[i]]+=(t==0);\n      vs[b[i]]+=(t==1);\n      vs[c[i]]+=(t==2);\n \
    \     vs[b[i]^c[i]]+=(t==3);\n    }\n    FWT(vs);\n    for(int i=0;i<(1<<k);i++)\
    \ vm[i][t]=vs[i];\n  }\n\n  vector<M> vs(1<<k,1);\n  for(int i=0;i<(1<<k);i++){\n\
    \    ll x=(vm[i][0]+vm[i][1]+vm[i][2]+vm[i][3])/4;\n    ll y=(vm[i][0]+vm[i][1]-vm[i][2]-vm[i][3])/4;\n\
    \    ll z=(vm[i][0]-vm[i][1]+vm[i][2]-vm[i][3])/4;\n    ll w=(vm[i][0]-vm[i][1]-vm[i][2]+vm[i][3])/4;\n\
    \n    vs[i]*=M(p+q+r).pow(x);\n    vs[i]*=M(p+q-r).pow(y);\n    vs[i]*=M(p-q+r).pow(z);\n\
    \    vs[i]*=M(p-q-r).pow(w);\n  }\n\n  UFWT(vs);\n  for(int i=0;i<(1<<k);i++){\n\
    \    if(i) cout<<\" \";\n    cout<<vs[ofs^i].v;\n  }\n  cout<<endl;\n  return\
    \ 0;\n}\n/*\n  verified on 2020/05/07\n  https://codeforces.com/contest/1119/problem/H\n\
    */\n\nsigned main(){\n  CGR002_H();\n  return 0;\n}\n#endif\n"
  dependsOn:
  - mod/mint.cpp
  isVerificationFile: false
  path: convolution/fastwalshhadamardtransform.cpp
  requiredBy: []
  timestamp: '2020-05-07 20:21:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/fastwalshhadamardtransform.cpp
layout: document
redirect_from:
- /library/convolution/fastwalshhadamardtransform.cpp
- /library/convolution/fastwalshhadamardtransform.cpp.html
title: convolution/fastwalshhadamardtransform.cpp
---
