---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/bitwise/fwht.cpp
    title: convolution/bitwise/fwht.cpp
  - icon: ':question:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0402.test.cpp
    title: test/aoj/0402.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/contest/1119/problem/H
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ convolution/bitwise/xor.cpp: line 32: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename T>\nauto divide_by_two(T x)\n  ->enable_if_t<!is_class<T>::value,\
    \ T>{\n  return x/T(2);\n}\n\ntemplate<typename T>\nauto divide_by_two(T x)\n\
    \  ->enable_if_t< is_class<T>::value, T>{\n  static const T inv = T(2).inv();\n\
    \  return x*inv;\n}\nauto zeta=[](auto& lo,auto& hi){\n  auto x=lo+hi,y=lo-hi;\n\
    \  lo=x;\n  hi=y;\n};\nauto moebius=[](auto& lo,auto& hi){\n  auto x=lo+hi,y=lo-hi;\n\
    \  lo=divide_by_two(x);\n  hi=divide_by_two(y);\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    \n#define call_from_test\n#include \"fwht.cpp\"\n#include \"../../mod/mint.cpp\"\
    \n#undef call_from_test\n\nsigned CGR002_H(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  using ll = long long;\n  const int MOD = 998244353;\n  using M = Mint<int,\
    \ MOD>;\n\n  int n,k;\n  cin>>n>>k;\n\n  ll p,q,r;\n  cin>>p>>q>>r;\n\n  int ofs=0;\n\
    \  vector<int> a(n),b(n),c(n);\n  for(int i=0;i<n;i++){\n    cin>>a[i]>>b[i]>>c[i];\n\
    \    ofs^=a[i];\n    b[i]^=a[i];\n    c[i]^=a[i];\n    a[i]=0;\n  }\n\n  vector<vector<ll>\
    \ > vm((1<<k),vector<ll>(4,0));\n  for(int t=0;t<4;t++){\n    vector<ll> vs(1<<k,0);\n\
    \    for(int i=0;i<n;i++){\n      vs[a[i]]+=(t==0);\n      vs[b[i]]+=(t==1);\n\
    \      vs[c[i]]+=(t==2);\n      vs[b[i]^c[i]]+=(t==3);\n    }\n    fwht(vs,zeta);\n\
    \    for(int i=0;i<(1<<k);i++) vm[i][t]=vs[i];\n  }\n\n  vector<M> vs(1<<k,1);\n\
    \  for(int i=0;i<(1<<k);i++){\n    ll x=(vm[i][0]+vm[i][1]+vm[i][2]+vm[i][3])/4;\n\
    \    ll y=(vm[i][0]+vm[i][1]-vm[i][2]-vm[i][3])/4;\n    ll z=(vm[i][0]-vm[i][1]+vm[i][2]-vm[i][3])/4;\n\
    \    ll w=(vm[i][0]-vm[i][1]-vm[i][2]+vm[i][3])/4;\n\n    vs[i]*=M(p+q+r).pow(x);\n\
    \    vs[i]*=M(p+q-r).pow(y);\n    vs[i]*=M(p-q+r).pow(z);\n    vs[i]*=M(p-q-r).pow(w);\n\
    \  }\n\n  fwht(vs,moebius);\n  for(int i=0;i<(1<<k);i++){\n    if(i) cout<<\"\
    \ \";\n    cout<<vs[ofs^i].v;\n  }\n  cout<<endl;\n  return 0;\n}\n/*\n  verified\
    \ on 2020/11/15\n  https://codeforces.com/contest/1119/problem/H\n*/\n\n//INSERT\
    \ ABOVE HERE\nsigned main(){\n  // CGR002_H();\n  return 0;\n}\n#endif\n"
  dependsOn:
  - convolution/bitwise/fwht.cpp
  - mod/mint.cpp
  isVerificationFile: false
  path: convolution/bitwise/xor.cpp
  requiredBy: []
  timestamp: '2020-11-15 18:54:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0402.test.cpp
documentation_of: convolution/bitwise/xor.cpp
layout: document
redirect_from:
- /library/convolution/bitwise/xor.cpp
- /library/convolution/bitwise/xor.cpp.html
title: convolution/bitwise/xor.cpp
---
