---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convolution/fastfouriertransform.cpp
    title: convolution/fastfouriertransform.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2985.test.cpp
    title: test/aoj/2985.test.cpp
  - icon: ':x:'
    path: test/yosupo/convolution_mod_1000000007.test.cpp
    title: test/yosupo/convolution_mod_1000000007.test.cpp
  - icon: ':x:'
    path: test/yukicoder/0444.test.cpp
    title: test/yukicoder/0444.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2744.test.cpp
    title: test/yukicoder/2744.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ convolution/arbitrarymod.cpp: line 8: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define call_from_test\n#include \"fastfouriertransform.cpp\"\n#undef\
    \ call_from_test\n\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct ArbitraryMod{\n\
    \  using dbl=FFT::dbl;\n  using num=FFT::num;\n\n  vector<T> multiply(vector<T>\
    \ as,vector<T> bs){\n    int need=as.size()+bs.size()-1;\n    int sz=1;\n    while(sz<need)\
    \ sz<<=1;\n    vector<num> fa(sz),fb(sz);\n    for(int i=0;i<(int)as.size();i++)\n\
    \      fa[i]=num(as[i].v&((1<<15)-1),as[i].v>>15);\n    for(int i=0;i<(int)bs.size();i++)\n\
    \      fb[i]=num(bs[i].v&((1<<15)-1),bs[i].v>>15);\n\n    fft(fa);fft(fb);\n\n\
    \    dbl ratio=0.25/sz;\n    num r2(0,-1),r3(ratio,0),r4(0,-ratio),r5(0,1);\n\
    \    for(int i=0;i<=(sz>>1);i++){\n      int j=(sz-i)&(sz-1);\n      num a1=(fa[i]+conj(fa[j]));\n\
    \      num a2=(fa[i]-conj(fa[j]))*r2;\n      num b1=(fb[i]+conj(fb[j]))*r3;\n\
    \      num b2=(fb[i]-conj(fb[j]))*r4;\n      if(i!=j){\n        num c1=(fa[j]+conj(fa[i]));\n\
    \        num c2=(fa[j]-conj(fa[i]))*r2;\n        num d1=(fb[j]+conj(fb[i]))*r3;\n\
    \        num d2=(fb[j]-conj(fb[i]))*r4;\n        fa[i]=c1*d1+c2*d2*r5;\n     \
    \   fb[i]=c1*d2+c2*d1;\n      }\n      fa[j]=a1*b1+a2*b2*r5;\n      fb[j]=a1*b2+a2*b1;\n\
    \    }\n    fft(fa);fft(fb);\n\n    vector<T> cs(need);\n    using ll = long long;\n\
    \    for(int i=0;i<need;i++){\n      ll aa=T(llround(fa[i].x)).v;\n      ll bb=T(llround(fb[i].x)).v;\n\
    \      ll cc=T(llround(fa[i].y)).v;\n      cs[i]=T(aa+(bb<<15)+(cc<<30));\n  \
    \  }\n    return cs;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - convolution/fastfouriertransform.cpp
  isVerificationFile: false
  path: convolution/arbitrarymod.cpp
  requiredBy: []
  timestamp: '2020-03-12 17:02:32+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/2744.test.cpp
  - test/yukicoder/0444.test.cpp
  - test/aoj/2985.test.cpp
  - test/yosupo/convolution_mod_1000000007.test.cpp
documentation_of: convolution/arbitrarymod.cpp
layout: document
redirect_from:
- /library/convolution/arbitrarymod.cpp
- /library/convolution/arbitrarymod.cpp.html
title: convolution/arbitrarymod.cpp
---
