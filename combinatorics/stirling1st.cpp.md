---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  - icon: ':question:'
    path: formalpowerseries/base.cpp
    title: formalpowerseries/base.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/stirling_number_of_the_first_kind.test.cpp
    title: test/yosupo/stirling_number_of_the_first_kind.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ combinatorics/stirling1st.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"enumeration.cpp\"\n#include \"../formalpowerseries/base.cpp\"\
    \n#undef call_from_test\n\n#endif\n//BEGIN CUT HERE\ntemplate<typename M_>\nstruct\
    \ Stirling1st : FormalPowerSeries<M_>{\n  using M = M_;\n  using super = FormalPowerSeries<M>;\n\
    \  using Poly = typename super::Poly;\n  using super::super, super::fact, super::finv,\
    \ super::mul;\n\n  Poly rs;\n  void build(int n){\n    super::init(n+1);\n   \
    \ if(n==0){\n      rs={M(1)};\n      return;\n    }\n    int m=1;\n    rs=Poly({M(0),M(1)});\n\
    \    for(int e=31-__builtin_clz(n)-1;e>=0;e--){\n      Poly as(m+1),bs(m+1);\n\
    \      for(int i=0;i<=m;i++) as[i]=fact[i]*rs[i];\n      bs[m-0]=M(1);\n     \
    \ for(int i=1;i<=m;i++) bs[m-i]=bs[m-(i-1)]*-M(m);\n      for(int i=0;i<=m;i++)\
    \ bs[m-i]*=finv[i];\n      Poly cs=mul(as,bs);\n      Poly ds(m+1);\n      for(int\
    \ i=0;i<=m;i++) ds[i]=finv[i]*cs[m+i];\n      rs=mul(rs,ds);\n      m<<=1;\n \
    \     if((n>>e)&1){\n        Poly ts(m+1+1,M(0));\n        for(int i=0;i<=m;i++){\n\
    \          ts[i+0]+=rs[i]*-M(m);\n          ts[i+1]+=rs[i];\n        }\n     \
    \   rs=ts;\n        m|=1;\n      }\n    }\n    assert(m==n);\n  }\n\n  M operator[](int\
    \ k)const{return rs[k];}\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT\
    \ ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - combinatorics/enumeration.cpp
  - formalpowerseries/base.cpp
  isVerificationFile: false
  path: combinatorics/stirling1st.cpp
  requiredBy: []
  timestamp: '2020-10-13 15:39:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/stirling_number_of_the_first_kind.test.cpp
documentation_of: combinatorics/stirling1st.cpp
layout: document
redirect_from:
- /library/combinatorics/stirling1st.cpp
- /library/combinatorics/stirling1st.cpp.html
title: combinatorics/stirling1st.cpp
---
