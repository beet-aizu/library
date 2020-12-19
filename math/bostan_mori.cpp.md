---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0168.test.cpp
    title: test/aoj/0168.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/bostan_mori.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\n// Find k-th term of linear recurrence\n\
    template<typename T>\nstruct BostanMori{\n  using Poly = vector<T>;\n  using Conv\
    \ = function<Poly(Poly, Poly)>;\n\n  Conv conv;\n  BostanMori(Conv conv_):conv(conv_){}\n\
    \n  Poly sub(Poly as,int odd){\n    Poly bs((as.size()+!odd)/2);\n    for(int\
    \ i=odd;i<(int)as.size();i+=2) bs[i/2]=as[i];\n    return bs;\n  }\n\n  // as:\
    \ initial values\n  // cs: monic polynomial\n  T build(long long k,Poly as,Poly\
    \ cs){\n    reverse(cs.begin(),cs.end());\n    assert(cs[0]==T(1));\n    int n=cs.size()-1;\n\
    \    as.resize(n,0);\n    Poly bs=conv(as,cs);\n    bs.resize(n);\n    while(k){\n\
    \      Poly ds(cs);\n      for(int i=1;i<(int)ds.size();i+=2) ds[i]=-ds[i];\n\
    \      bs=sub(conv(bs,ds),k&1);\n      cs=sub(conv(cs,ds),0);\n      k>>=1;\n\
    \    }\n    return bs[0];\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT\
    \ ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\n// Find k-th term of linear recurrence\ntemplate<typename\
    \ T>\nstruct BostanMori{\n  using Poly = vector<T>;\n  using Conv = function<Poly(Poly,\
    \ Poly)>;\n\n  Conv conv;\n  BostanMori(Conv conv_):conv(conv_){}\n\n  Poly sub(Poly\
    \ as,int odd){\n    Poly bs((as.size()+!odd)/2);\n    for(int i=odd;i<(int)as.size();i+=2)\
    \ bs[i/2]=as[i];\n    return bs;\n  }\n\n  // as: initial values\n  // cs: monic\
    \ polynomial\n  T build(long long k,Poly as,Poly cs){\n    reverse(cs.begin(),cs.end());\n\
    \    assert(cs[0]==T(1));\n    int n=cs.size()-1;\n    as.resize(n,0);\n    Poly\
    \ bs=conv(as,cs);\n    bs.resize(n);\n    while(k){\n      Poly ds(cs);\n    \
    \  for(int i=1;i<(int)ds.size();i+=2) ds[i]=-ds[i];\n      bs=sub(conv(bs,ds),k&1);\n\
    \      cs=sub(conv(cs,ds),0);\n      k>>=1;\n    }\n    return bs[0];\n  }\n};\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: math/bostan_mori.cpp
  requiredBy: []
  timestamp: '2020-12-19 16:10:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0168.test.cpp
documentation_of: math/bostan_mori.cpp
layout: document
redirect_from:
- /library/math/bostan_mori.cpp
- /library/math/bostan_mori.cpp.html
title: math/bostan_mori.cpp
---
