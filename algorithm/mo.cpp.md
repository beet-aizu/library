---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/fastio.cpp
    title: tools/fastio.cpp
  - icon: ':heavy_check_mark:'
    path: tree/eulertourforedge.cpp
    title: tree/eulertourforedge.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0425.test.cpp
    title: test/aoj/0425.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://atcoder.jp/contests/abc133/tasks/abc133_f
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 189, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ algorithm/mo.cpp: line 54: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\nstruct Mo{\n  using F = function<void(int)>;\n\
    \  vector<int> ls,rs,ord;\n  int n,width,nl,nr,ptr;\n  F expandL,expandR;\n  F\
    \ shrinkL,shrinkR;\n\n  Mo(int n,int width,F expandL,F expandR,F shrinkL,F shrinkR):\n\
    \    n(n),width(width),nl(0),nr(0),ptr(0),\n    expandL(expandL),expandR(expandR),\n\
    \    shrinkL(shrinkL),shrinkR(shrinkR){}\n\n  Mo(int n,int width,F expand,F shrink){\n\
    \    *this=Mo(n,width,expand,expand,shrink,shrink);\n  }\n\n  void add(int l,int\
    \ r){\n    ls.emplace_back(l);\n    rs.emplace_back(r);\n  }\n\n  void build(){\n\
    \    ord.resize(ls.size());\n    iota(ord.begin(),ord.end(),0);\n    sort(ord.begin(),ord.end(),\n\
    \         [&](int a,int b){\n           if(ls[a]/width!=ls[b]/width) return ls[a]<ls[b];\n\
    \           if(rs[a]==rs[b]) return ls[a]<ls[b];\n           return bool((rs[a]<rs[b])^((ls[a]/width)&1));\n\
    \         });\n  }\n\n  int process(){\n    if(ptr==(int)ord.size()) return -1;\n\
    \    const int idx=ord[ptr++];\n    while(nl>ls[idx]) expandL(--nl);\n    while(nr<rs[idx])\
    \ expandR(nr++);\n    while(nl<ls[idx]) shrinkL(nl++);\n    while(nr>rs[idx])\
    \ shrinkR(--nr);\n    return idx;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    \n#define call_from_test\n#include \"../tools/fastio.cpp\"\n#include \"../tree/eulertourforedge.cpp\"\
    \n#undef call_from_test\n\n//INSERT ABOVE HERE\n// Mo on Tree\nsigned ABC133_F(){\n\
    \  int n,q;\n  cin>>n>>q;\n  vector<int> as(n),bs(n),cs(n),ds(n);\n  vector<int>\
    \ xs(q),ys(q),us(q),vs(q);\n\n  EulerTourForEdge et(n);\n  for(int i=1;i<n;i++){\n\
    \    cin>>as[i]>>bs[i]>>cs[i]>>ds[i];\n    as[i]--;bs[i]--;\n    et.add_edge(as[i],bs[i]);\n\
    \  }\n  et.build();\n\n  vector<int> idx(n,0);\n  for(int i=1;i<n;i++)\n    idx[et.child(as[i],bs[i])]=i;\n\
    \n  for(int i=0;i<q;i++){\n    cin>>xs[i]>>ys[i]>>us[i]>>vs[i];\n    us[i]--;vs[i]--;\n\
    \  }\n\n  int all=0;\n  vector<int> cnt(n),sum(n),app(n,0);\n  auto exec=\n  \
    \  [&](int k){\n      int v=et.bottom(k);\n      int e=idx[v];\n      app[v]^=1;\n\
    \      if(app[v]){\n        all+=ds[e];\n        cnt[cs[e]]++;\n        sum[cs[e]]+=ds[e];\n\
    \      }else{\n        all-=ds[e];\n        cnt[cs[e]]--;\n        sum[cs[e]]-=ds[e];\n\
    \      }\n    };\n  Mo mo(n*2,400,exec,exec);\n\n  for(int i=0;i<q;i++){\n   \
    \ auto f=[&](int l,int r){mo.add(min(l,r),max(l,r));};\n    et.query(us[i],vs[i],f);\n\
    \  }\n  mo.build();\n\n  vector<int> ans(q,0);\n  for(int i=0;i<q;i++){\n    int\
    \ k=mo.process();\n    ans[k]=all-sum[xs[k]]+cnt[xs[k]]*ys[k];\n  }\n\n  for(int\
    \ i=0;i<q;i++) cout<<ans[i]<<\"\\n\";\n  cout<<flush;\n  return 0;\n}\n/*\n  verified\
    \ on 2019/11/12\n  https://atcoder.jp/contests/abc133/tasks/abc133_f\n*/\n\nsigned\
    \ main(){\n  //ABC133_F();\n  return 0;\n}\n#endif\n"
  dependsOn:
  - tools/fastio.cpp
  - tree/eulertourforedge.cpp
  isVerificationFile: false
  path: algorithm/mo.cpp
  requiredBy: []
  timestamp: '2020-05-07 20:09:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0425.test.cpp
documentation_of: algorithm/mo.cpp
layout: document
redirect_from:
- /library/algorithm/mo.cpp
- /library/algorithm/mo.cpp.html
title: algorithm/mo.cpp
---
