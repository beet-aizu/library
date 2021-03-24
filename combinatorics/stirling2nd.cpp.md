---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/base.cpp
    title: formalpowerseries/base.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/stirling_number_of_the_second_kind.test.cpp
    title: test/yosupo/stirling_number_of_the_second_kind.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ combinatorics/stirling2nd.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"enumeration.cpp\"\n#include \"../formalpowerseries/base.cpp\"\
    \n#undef call_from_test\n\n#endif\n//BEGIN CUT HERE\ntemplate<typename M_>\nstruct\
    \ Stirling2nd : FormalPowerSeries<M_>{\n  using M = M_;\n  using super = FormalPowerSeries<M>;\n\
    \  using Poly = typename super::Poly;\n  using super::super, super::finv;\n\n\
    \  Poly rs;\n  void build(int n){\n    super::init(n+1);\n    Poly as(n+1),bs(n+1);\n\
    \    for(int i=0;i<=n;i++){\n      as[i]=M(i).pow(n)*finv[i];\n      bs[i]=(i&1?-M(1):M(1))*finv[i];\n\
    \    }\n    rs=super::pre(super::mul(as,bs),n+1);\n  }\n\n  M operator[](int k)const{return\
    \ rs[k];}\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - combinatorics/enumeration.cpp
  - formalpowerseries/base.cpp
  isVerificationFile: false
  path: combinatorics/stirling2nd.cpp
  requiredBy: []
  timestamp: '2020-11-22 16:25:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/stirling_number_of_the_second_kind.test.cpp
documentation_of: combinatorics/stirling2nd.cpp
layout: document
redirect_from:
- /library/combinatorics/stirling2nd.cpp
- /library/combinatorics/stirling2nd.cpp.html
title: combinatorics/stirling2nd.cpp
---
