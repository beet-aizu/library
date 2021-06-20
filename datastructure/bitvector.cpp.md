---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/0206.test.cpp
    title: test/yukicoder/0206.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructure/bitvector.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n\n//BEGIN CUT HERE\n// half open interval [l, r)\n\
    template<typename T=unsigned long long>\nstruct BitVector{\n  inline static constexpr\
    \ size_t B = sizeof(T) * CHAR_BIT;\n  size_t n;\n  vector<T> dat;\n  BitVector(size_t\
    \ n_):n(n_),dat(n_/B+1,0){}\n\n  inline T get(size_t i)const{return (dat[i/B]>>(i%B))&T(1);}\n\
    \n  void set(size_t i,T v){\n    dat[i/B]&=~(T(1)<<(i%B));\n    dat[i/B]|=v<<(i%B);\n\
    \  }\n\n  // O(B + (r - l) / B)\n  BitVector get(size_t l,size_t r)const{\n  \
    \  BitVector res(r-l);\n    if(r-l<=B){\n      for(size_t i=l;i<r;i++) res.set(i-l,get(i));\n\
    \      return res;\n    }\n    size_t p=(l+B-1)/B*B,q=r/B*B;\n    // [l, p)\n\
    \    for(size_t i=l;i<p;i++) res.set(i-l,get(i));\n    // [p, q)\n    for(size_t\
    \ i=p;i<q;i+=B){\n      if(l%B==0) res.dat[(i-l)/B]=dat[i/B];\n      else{\n \
    \       res.dat[(i-l)/B+0]|=dat[i/B]<<(p-l);\n        res.dat[(i-l)/B+1]|=dat[i/B]>>(B-(p-l));\n\
    \      }\n    }\n    // [q, r)\n    for(size_t i=q;i<r;i++) res.set(i-l,get(i));\n\
    \    return res;\n  }\n\n  void set(size_t l,size_t r,const BitVector& bv){\n\
    \    if(r-l<=B){\n      for(size_t i=l;i<r;i++) set(i,bv.get(i-l));\n      return;\n\
    \    }\n    size_t p=(l+B-1)/B*B,q=r/B*B;\n    // [l, p)\n    for(size_t i=l;i<p;i++)\
    \ set(i,bv.get(i-l));\n    // [p, q)\n    for(size_t i=p;i<q;i+=B){\n      if(l%B==0)\
    \ dat[i/B]=bv.dat[(i-l)/B];\n      else dat[i/B]=(bv.dat[(i-l)/B+0]>>(p-l))|(bv.dat[(i-l)/B+1]<<(B-(p-l)));\n\
    \    }\n    // [q, r)\n    for(size_t i=q;i<r;i++) set(i,bv.get(i-l));\n  }\n\
    };\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n\n//BEGIN CUT HERE\n// half open interval [l, r)\ntemplate<typename T=unsigned\
    \ long long>\nstruct BitVector{\n  inline static constexpr size_t B = sizeof(T)\
    \ * CHAR_BIT;\n  size_t n;\n  vector<T> dat;\n  BitVector(size_t n_):n(n_),dat(n_/B+1,0){}\n\
    \n  inline T get(size_t i)const{return (dat[i/B]>>(i%B))&T(1);}\n\n  void set(size_t\
    \ i,T v){\n    dat[i/B]&=~(T(1)<<(i%B));\n    dat[i/B]|=v<<(i%B);\n  }\n\n  //\
    \ O(B + (r - l) / B)\n  BitVector get(size_t l,size_t r)const{\n    BitVector\
    \ res(r-l);\n    if(r-l<=B){\n      for(size_t i=l;i<r;i++) res.set(i-l,get(i));\n\
    \      return res;\n    }\n    size_t p=(l+B-1)/B*B,q=r/B*B;\n    // [l, p)\n\
    \    for(size_t i=l;i<p;i++) res.set(i-l,get(i));\n    // [p, q)\n    for(size_t\
    \ i=p;i<q;i+=B){\n      if(l%B==0) res.dat[(i-l)/B]=dat[i/B];\n      else{\n \
    \       res.dat[(i-l)/B+0]|=dat[i/B]<<(p-l);\n        res.dat[(i-l)/B+1]|=dat[i/B]>>(B-(p-l));\n\
    \      }\n    }\n    // [q, r)\n    for(size_t i=q;i<r;i++) res.set(i-l,get(i));\n\
    \    return res;\n  }\n\n  void set(size_t l,size_t r,const BitVector& bv){\n\
    \    if(r-l<=B){\n      for(size_t i=l;i<r;i++) set(i,bv.get(i-l));\n      return;\n\
    \    }\n    size_t p=(l+B-1)/B*B,q=r/B*B;\n    // [l, p)\n    for(size_t i=l;i<p;i++)\
    \ set(i,bv.get(i-l));\n    // [p, q)\n    for(size_t i=p;i<q;i+=B){\n      if(l%B==0)\
    \ dat[i/B]=bv.dat[(i-l)/B];\n      else dat[i/B]=(bv.dat[(i-l)/B+0]>>(p-l))|(bv.dat[(i-l)/B+1]<<(B-(p-l)));\n\
    \    }\n    // [q, r)\n    for(size_t i=q;i<r;i++) set(i,bv.get(i-l));\n  }\n\
    };\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/bitvector.cpp
  requiredBy: []
  timestamp: '2021-06-20 18:02:51+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/0206.test.cpp
documentation_of: datastructure/bitvector.cpp
layout: document
redirect_from:
- /library/datastructure/bitvector.cpp
- /library/datastructure/bitvector.cpp.html
title: datastructure/bitvector.cpp
---
