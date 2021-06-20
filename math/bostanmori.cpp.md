---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0168.test.cpp
    title: test/aoj/0168.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0104.test.cpp
    title: test/yukicoder/0104.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0444.test.cpp
    title: test/yukicoder/0444.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a
  bundledCode: "#line 1 \"math/bostanmori.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n// ref. https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a\n\
    //BEGIN CUT HERE\n// Find k-th term of linear recurrence\n// execute `conv` O(\\\
    log k) times\ntemplate<typename T>\nstruct BostanMori{\n  using Poly = vector<T>;\n\
    \  using Conv = function<Poly(Poly, Poly)>;\n\n  Conv conv;\n  BostanMori(Conv\
    \ conv_):conv(conv_){}\n\n  Poly sub(Poly as,int odd){\n    Poly bs((as.size()+!odd)/2);\n\
    \    for(int i=odd;i<(int)as.size();i+=2) bs[i/2]=as[i];\n    return bs;\n  }\n\
    \n  // as: initial values\n  // cs: monic polynomial\n  T build(long long k,Poly\
    \ as,Poly cs){\n    reverse(cs.begin(),cs.end());\n    assert(cs[0]==T(1));\n\
    \    int n=cs.size()-1;\n    as.resize(n,0);\n    Poly bs=conv(as,cs);\n    bs.resize(n);\n\
    \    while(k){\n      Poly ds(cs);\n      for(int i=1;i<(int)ds.size();i+=2) ds[i]=-ds[i];\n\
    \      bs=sub(conv(bs,ds),k&1);\n      cs=sub(conv(cs,ds),0);\n      k>>=1;\n\
    \    }\n    return bs[0];\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT\
    \ ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n// ref. https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a\n//BEGIN CUT\
    \ HERE\n// Find k-th term of linear recurrence\n// execute `conv` O(\\log k) times\n\
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
  dependsOn: []
  isVerificationFile: false
  path: math/bostanmori.cpp
  requiredBy: []
  timestamp: '2020-12-20 13:43:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/0444.test.cpp
  - test/yukicoder/0104.test.cpp
  - test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
  - test/aoj/0168.test.cpp
documentation_of: math/bostanmori.cpp
layout: document
redirect_from:
- /library/math/bostanmori.cpp
- /library/math/bostanmori.cpp.html
title: math/bostanmori.cpp
---
