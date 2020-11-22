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
  - icon: ':heavy_check_mark:'
    path: test/yosupo/partition_function.test.cpp
    title: test/yosupo/partition_function.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ combinatorics/partition.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"enumeration.cpp\"\n#include \"../formalpowerseries/base.cpp\"\
    \n#include \"../formalpowerseries/inv.cpp\"\n#undef call_from_test\n\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename M_>\nstruct Partition : FormalPowerSeries<M_>{\n\
    \  using M = M_;\n  using super = FormalPowerSeries<M>;\n  using Poly = typename\
    \ super::Poly;\n  using super::super;\n\n  Poly rs;\n  void build(int n){\n  \
    \  rs.resize(n+1);\n    rs[0]=M(1);\n    for(int k=1;k<=n;k++){\n      if(1LL*k*(3*k+1)/2<=n)\
    \ rs[k*(3*k+1)/2]+=k%2?-M(1):M(1);\n      if(1LL*k*(3*k-1)/2<=n) rs[k*(3*k-1)/2]+=k%2?-M(1):M(1);\n\
    \    }\n    rs=super::inv(rs,n+1);\n  }\n\n  M operator[](int k)const{return rs[k];}\n\
    };\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn:
  - combinatorics/enumeration.cpp
  - formalpowerseries/base.cpp
  - formalpowerseries/inv.cpp
  isVerificationFile: false
  path: combinatorics/partition.cpp
  requiredBy: []
  timestamp: '2020-11-22 16:25:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/partition_function.test.cpp
documentation_of: combinatorics/partition.cpp
layout: document
redirect_from:
- /library/combinatorics/partition.cpp
- /library/combinatorics/partition.cpp.html
title: combinatorics/partition.cpp
---
