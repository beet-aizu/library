---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3506.test.cpp
    title: test/aoj/3506.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4387.test.cpp
    title: test/yukicoder/4387.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656
  bundledCode: "#line 2 \"graph/rangetorange.cpp\"\n\n#ifndef call_from_test\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#endif\n\n/*\n * @see https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656\n\
    \ */\n\n//BEGIN CUT HERE\nstruct RangeToRange{\n  const int n;\n  int ptr;\n \
    \ RangeToRange(int n):n(n),ptr(3*n){}\n\n  // (0n, 2n) : top segtree (to)\n  //\
    \ (2n, 4n) : bottom segtree (from)\n\n  // map [3n, 4n) -> [n, 2n)\n  template<typename\
    \ F>\n  void add_edge(int u,int v,F f){\n    if(3*n<=u and u<4*n) u-=2*n;\n  \
    \  f(u,v);\n  }\n\n  template<typename F>\n  void init(F f){\n    for(int i=1;i<n;i++){\n\
    \      int l=(i<<1)|0;\n      int r=(i<<1)|1;\n      add_edge(0*n+i,0*n+l,f);\n\
    \      add_edge(0*n+i,0*n+r,f);\n      add_edge(2*n+l,2*n+i,f);\n      add_edge(2*n+r,2*n+i,f);\n\
    \    }\n  }\n\n  // [l1, r1) -> [l2, r2)\n  template<typename F,typename G>\n\
    \  void add_edge(int l1,int r1,int l2,int r2,F f,G g){\n    int k=ptr++;\n   \
    \ for(l1+=n,r1+=n;l1<r1;l1>>=1,r1>>=1){\n      if(l1&1) add_edge(2*n+(l1++),k,f);\n\
    \      if(r1&1) add_edge(2*n+(--r1),k,f);\n    }\n    for(l2+=n,r2+=n;l2<r2;l2>>=1,r2>>=1){\n\
    \      if(l2&1) g(k,l2++);\n      if(r2&1) g(k,--r2);\n    }\n  }\n  int idx(int\
    \ v)const{return 1*n+v;}\n  size_t size()const{return ptr;}\n};\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n\n/*\n * @see https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656\n\
    \ */\n\n//BEGIN CUT HERE\nstruct RangeToRange{\n  const int n;\n  int ptr;\n \
    \ RangeToRange(int n):n(n),ptr(3*n){}\n\n  // (0n, 2n) : top segtree (to)\n  //\
    \ (2n, 4n) : bottom segtree (from)\n\n  // map [3n, 4n) -> [n, 2n)\n  template<typename\
    \ F>\n  void add_edge(int u,int v,F f){\n    if(3*n<=u and u<4*n) u-=2*n;\n  \
    \  f(u,v);\n  }\n\n  template<typename F>\n  void init(F f){\n    for(int i=1;i<n;i++){\n\
    \      int l=(i<<1)|0;\n      int r=(i<<1)|1;\n      add_edge(0*n+i,0*n+l,f);\n\
    \      add_edge(0*n+i,0*n+r,f);\n      add_edge(2*n+l,2*n+i,f);\n      add_edge(2*n+r,2*n+i,f);\n\
    \    }\n  }\n\n  // [l1, r1) -> [l2, r2)\n  template<typename F,typename G>\n\
    \  void add_edge(int l1,int r1,int l2,int r2,F f,G g){\n    int k=ptr++;\n   \
    \ for(l1+=n,r1+=n;l1<r1;l1>>=1,r1>>=1){\n      if(l1&1) add_edge(2*n+(l1++),k,f);\n\
    \      if(r1&1) add_edge(2*n+(--r1),k,f);\n    }\n    for(l2+=n,r2+=n;l2<r2;l2>>=1,r2>>=1){\n\
    \      if(l2&1) g(k,l2++);\n      if(r2&1) g(k,--r2);\n    }\n  }\n  int idx(int\
    \ v)const{return 1*n+v;}\n  size_t size()const{return ptr;}\n};\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/rangetorange.cpp
  requiredBy: []
  timestamp: '2020-08-20 15:14:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3506.test.cpp
  - test/yukicoder/4387.test.cpp
documentation_of: graph/rangetorange.cpp
layout: document
redirect_from:
- /library/graph/rangetorange.cpp
- /library/graph/rangetorange.cpp.html
title: graph/rangetorange.cpp
---
