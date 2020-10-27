---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  - icon: ':question:'
    path: formalpowerseries/base.cpp
    title: formalpowerseries/base.cpp
  - icon: ':question:'
    path: formalpowerseries/inv.cpp
    title: formalpowerseries/inv.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/bernoulli_number.test.cpp
    title: test/yosupo/bernoulli_number.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ combinatorics/bernoulli.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"enumeration.cpp\"\n#include \"../formalpowerseries/base.cpp\"\
    \n#include \"../formalpowerseries/inv.cpp\"\n#undef call_from_test\n\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename M_>\nstruct Bernoulli : FormalPowerSeries<M_>{\n\
    \  using M = M_;\n  using super = FormalPowerSeries<M>;\n  using Poly = typename\
    \ super::Poly;\n  using super::super, super::fact, super::finv;\n\n  Poly rs;\n\
    \  void build(int n){\n    super::init(n+2);\n    rs.assign(n+1,M(1));\n    for(int\
    \ i=1;i<=n;i++) rs[i]=finv[i+1];\n    rs=super::inv(rs,n+1);\n    for(int i=1;i<=n;i++)\
    \ rs[i]*=fact[i];\n  }\n\n  M operator[](int k)const{return rs[k];}\n};\n//END\
    \ CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  dependsOn:
  - combinatorics/enumeration.cpp
  - formalpowerseries/base.cpp
  - formalpowerseries/inv.cpp
  isVerificationFile: false
  path: combinatorics/bernoulli.cpp
  requiredBy: []
  timestamp: '2020-10-27 13:13:52+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/bernoulli_number.test.cpp
documentation_of: combinatorics/bernoulli.cpp
layout: document
redirect_from:
- /library/combinatorics/bernoulli.cpp
- /library/combinatorics/bernoulli.cpp.html
title: combinatorics/bernoulli.cpp
---
