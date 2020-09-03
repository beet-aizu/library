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
    \ combinatorics/partition.cpp: line 8: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define call_from_test\n#include \"enumeration.cpp\"\n#include \"../polynomial/formalpowerseries.cpp\"\
    \n#undef call_from_test\n\n#endif\n//BEGIN CUT HERE\ntemplate<typename M_>\nstruct\
    \ Partition : FormalPowerSeries<M_>{\n  using M = M_;\n  using super = FormalPowerSeries<M>;\n\
    \  using super::super;\n  using Poly = typename super::Poly;\n\n  Poly rs;\n \
    \ void build(int n){\n    rs.resize(n+1);\n    rs[0]=M(1);\n    for(int k=1;k<=n;k++){\n\
    \      if(1LL*k*(3*k+1)/2<=n) rs[k*(3*k+1)/2]+=k%2?-M(1):M(1);\n      if(1LL*k*(3*k-1)/2<=n)\
    \ rs[k*(3*k-1)/2]+=k%2?-M(1):M(1);\n    }\n    rs=super::inv(rs,n+1);\n  }\n\n\
    \  M operator[](int k)const{return rs[k];}\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - combinatorics/enumeration.cpp
  - polynomial/formalpowerseries.cpp
  extendedDependsOn:
  - icon: ':warning:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  - icon: ':warning:'
    path: polynomial/formalpowerseries.cpp
    title: polynomial/formalpowerseries.cpp
  extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/partition_function.test.cpp
    title: test/yosupo/partition_function.test.cpp
  extendedVerifiedWith: []
  isVerificationFile: false
  path: combinatorics/partition.cpp
  requiredBy:
  - test/yosupo/partition_function.test.cpp
  timestamp: '2020-05-16 18:51:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: combinatorics/partition.cpp
layout: document
redirect_from:
- /library/combinatorics/partition.cpp
- /library/combinatorics/partition.cpp.html
title: combinatorics/partition.cpp
---
