---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: formalpowerseries/diff.cpp
    title: formalpowerseries/diff.cpp
  - icon: ':warning:'
    path: formalpowerseries/div.cpp
    title: formalpowerseries/div.cpp
  - icon: ':warning:'
    path: formalpowerseries/exp.cpp
    title: formalpowerseries/exp.cpp
  - icon: ':warning:'
    path: formalpowerseries/integral.cpp
    title: formalpowerseries/integral.cpp
  - icon: ':warning:'
    path: formalpowerseries/inv.cpp
    title: formalpowerseries/inv.cpp
  - icon: ':warning:'
    path: formalpowerseries/log.cpp
    title: formalpowerseries/log.cpp
  - icon: ':warning:'
    path: formalpowerseries/mod.cpp
    title: formalpowerseries/mod.cpp
  - icon: ':warning:'
    path: formalpowerseries/pow.cpp
    title: formalpowerseries/pow.cpp
  - icon: ':warning:'
    path: formalpowerseries/shift.cpp
    title: formalpowerseries/shift.cpp
  - icon: ':warning:'
    path: formalpowerseries/sqrt.cpp
    title: formalpowerseries/sqrt.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://beet-aizu.hatenablog.com/entry/2019/09/27/224701
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ formalpowerseries/base.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../combinatorics/enumeration.cpp\"\n#undef\
    \ call_from_test\n\n#endif\n// http://beet-aizu.hatenablog.com/entry/2019/09/27/224701\n\
    //BEGIN CUT HERE\ntemplate<typename M_>\nstruct FormalPowerSeries : Enumeration<M_>\
    \ {\n  using M = M_;\n  using super = Enumeration<M>;\n  using super::fact;\n\
    \  using super::finv;\n  using super::invs;\n\n  using Poly = vector<M>;\n  using\
    \ Conv = function<Poly(Poly, Poly)>;\n  Conv conv;\n  FormalPowerSeries(Conv conv):conv(conv){}\n\
    \n  Poly pre(const Poly &as,int deg){\n    return Poly(as.begin(),as.begin()+min((int)as.size(),deg));\n\
    \  }\n\n  Poly add(Poly as,Poly bs){\n    int sz=max(as.size(),bs.size());\n \
    \   Poly cs(sz,M(0));\n    for(int i=0;i<(int)as.size();i++) cs[i]+=as[i];\n \
    \   for(int i=0;i<(int)bs.size();i++) cs[i]+=bs[i];\n    return cs;\n  }\n\n \
    \ Poly sub(Poly as,Poly bs){\n    int sz=max(as.size(),bs.size());\n    Poly cs(sz,M(0));\n\
    \    for(int i=0;i<(int)as.size();i++) cs[i]+=as[i];\n    for(int i=0;i<(int)bs.size();i++)\
    \ cs[i]-=bs[i];\n    return cs;\n  }\n\n  Poly mul(Poly as,Poly bs){\n    return\
    \ conv(as,bs);\n  }\n\n  Poly mul(Poly as,M k){\n    for(auto &a:as) a*=k;\n \
    \   return as;\n  }\n\n  // F(0) must not be 0\n  Poly inv(Poly as,int deg);\n\
    \n  // not zero\n  Poly div(Poly as,Poly bs);\n\n  // not zero\n  Poly mod(Poly\
    \ as,Poly bs);\n\n  // F(0) must be 1\n  Poly sqrt(Poly as,int deg);\n\n  Poly\
    \ diff(Poly as);\n  Poly integral(Poly as);\n\n  // F(0) must be 1\n  Poly log(Poly\
    \ as,int deg);\n\n  // F(0) must be 0\n  Poly exp(Poly as,int deg);\n\n  // not\
    \ zero\n  Poly pow(Poly as,long long k,int deg);\n\n  // x <- x + c\n  Poly shift(Poly\
    \ as,M c);\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - combinatorics/enumeration.cpp
  isVerificationFile: false
  path: formalpowerseries/base.cpp
  requiredBy:
  - formalpowerseries/pow.cpp
  - formalpowerseries/log.cpp
  - formalpowerseries/exp.cpp
  - formalpowerseries/div.cpp
  - formalpowerseries/integral.cpp
  - formalpowerseries/inv.cpp
  - formalpowerseries/mod.cpp
  - formalpowerseries/sqrt.cpp
  - formalpowerseries/shift.cpp
  - formalpowerseries/diff.cpp
  timestamp: '2020-10-13 15:11:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: formalpowerseries/base.cpp
layout: document
redirect_from:
- /library/formalpowerseries/base.cpp
- /library/formalpowerseries/base.cpp.html
title: formalpowerseries/base.cpp
---
