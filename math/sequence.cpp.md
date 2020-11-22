---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/base.cpp
    title: formalpowerseries/base.cpp
  - icon: ':heavy_check_mark:'
    path: polynomial/berlekampmassey.cpp
    title: polynomial/berlekampmassey.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0444.test.cpp
    title: test/yukicoder/0444.test.cpp
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
    \ math/sequence.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../combinatorics/enumeration.cpp\"\n#include\
    \ \"../formalpowerseries/base.cpp\"\n#include \"../polynomial/berlekampmassey.cpp\"\
    \n#undef call_from_test\n\n#endif\n//BEGIN CUT HERE\ntemplate<typename M>\nstruct\
    \ Sequence : FormalPowerSeries<M>{\n  using FormalPowerSeries<M>::FormalPowerSeries;\n\
    \  using Poly = vector<M>;\n\n  struct Calculator{\n    const Poly as,cs;\n  \
    \  Sequence* seq;\n    Calculator(const Poly as_,const Poly cs_,Sequence *seq_):\n\
    \      as(as_),cs(cs_),seq(seq_){}\n    M operator()(long long n){\n      Poly\
    \ rs({M(1)}),ts({M(0),M(1)});\n      n--;\n      while(n){\n        if(n&1) rs=seq->mod(seq->mul(rs,ts),cs);\n\
    \        ts=seq->mod(seq->mul(ts,ts),cs);\n        n>>=1;\n      }\n      M res(0);\n\
    \      rs.resize(cs.size(),M(0));\n      for(int i=0;i<(int)cs.size();i++) res+=as[i]*rs[i];\n\
    \      return res;\n    }\n  };\n\n  Calculator build(vector<M> as){\n    return\
    \ Calculator(as,berlekamp_massey(as),this);\n  }\n};\n//END CUT HERE\n#ifndef\
    \ call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - combinatorics/enumeration.cpp
  - formalpowerseries/base.cpp
  - polynomial/berlekampmassey.cpp
  isVerificationFile: false
  path: math/sequence.cpp
  requiredBy: []
  timestamp: '2020-11-22 15:57:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/0444.test.cpp
documentation_of: math/sequence.cpp
layout: document
redirect_from:
- /library/math/sequence.cpp
- /library/math/sequence.cpp.html
title: math/sequence.cpp
---
