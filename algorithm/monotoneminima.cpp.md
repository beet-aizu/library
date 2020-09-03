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
    \ algorithm/monotoneminima.cpp: line 35: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\nnamespace MonotoneMinima{\n  template<typename\
    \ T,typename F>\n  void induce(int l,int r,int a,int b,vector<int> &dp,F dist){\n\
    \    if(l==r) return;\n    int m=(l+r)>>1;\n    int &idx=(dp[m]=a);\n    T res=dist(m,idx);\n\
    \    for(int i=a;i<b;i++){\n      T tmp=dist(m,i);\n      if(tmp<res) res=tmp,idx=i;\n\
    \    }\n    induce<T>(l,m,a,idx+1,dp,dist);\n    induce<T>(m+1,r,idx,b,dp,dist);\n\
    \  }\n\n  // p < q -> argmin f(p, *) < argmin f(q, *)\n  template<typename T,typename\
    \ F>\n  vector<int> args(int n,int m,F dist){\n    vector<int> dp(n,-1);\n   \
    \ induce<T>(0,n,0,m,dp,dist);\n    return dp;\n  }\n}\n//END CUT HERE\n#ifndef\
    \ call_from_test\n\n#define call_from_test\n#include \"../tools/fastio.cpp\"\n\
    #undef call_from_test\n\n//INSERT ABOVE HERE\nsigned COLOPL2018FINAL_C(){\n  using\
    \ ll = long long;\n\n  int n;\n  cin>>n;\n  vector<ll> as(n);\n  for(int i=0;i<n;i++)\
    \ cin>>as[i];\n\n  auto dist=[&](int i,int j){return as[j]+(ll)(i-j)*(i-j);};\n\
    \  auto res=MonotoneMinima::args<ll>(n,n,dist);\n\n  for(int i=0;i<n;i++) cout<<dist(i,res[i])<<\"\
    \\n\";\n  cout<<flush;\n  return 0;\n}\n/*\n  verified on 2019/12/17\n  https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c\n\
    */\n\nsigned main(){\n  //COLOPL2018FINAL_C();\n  return 0;\n}\n#endif\n"
  dependsOn:
  - tools/fastio.cpp
  extendedDependsOn:
  - icon: ':warning:'
    path: tools/fastio.cpp
    title: tools/fastio.cpp
  extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2603.test.cpp
    title: test/aoj/2603.test.cpp
  extendedVerifiedWith: []
  isVerificationFile: false
  path: algorithm/monotoneminima.cpp
  requiredBy:
  - test/aoj/2603.test.cpp
  timestamp: '2020-05-07 20:09:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: algorithm/monotoneminima.cpp
layout: document
redirect_from:
- /library/algorithm/monotoneminima.cpp
- /library/algorithm/monotoneminima.cpp.html
title: algorithm/monotoneminima.cpp
---
