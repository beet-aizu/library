---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_5_D.test.cpp
    title: test/aoj/GRL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.test.cpp
    title: test/aoj/DSL_2_B.test.cpp
  - icon: ':x:'
    path: test/aoj/0343.test.cpp
    title: test/aoj/0343.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1732.test.cpp
    title: test/yukicoder/1732.test.cpp
  - icon: ':x:'
    path: test/yukicoder/4852.test.cpp
    title: test/yukicoder/4852.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2125.test.cpp
    title: test/yukicoder/2125.test.cpp
  - icon: ':x:'
    path: test/yosupo/vertex_add_path_sum.test.cpp
    title: test/yosupo/vertex_add_path_sum.test.cpp
  - icon: ':x:'
    path: test/yosupo/vertex_add_subtree_sum.test.cpp
    title: test/yosupo/vertex_add_subtree_sum.test.cpp
  - icon: ':x:'
    path: test/yosupo/point_add_range_sum.test.cpp
    title: test/yosupo/point_add_range_sum.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"datastructure/binaryindexedtree.cpp\"\n\n#ifndef call_from_test\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename\
    \ T>\nclass BIT{\nprivate: // 1-indexed\n  T sum_impl(int i){\n    T s(0);\n \
    \   for(int x=i;x>0;x-=(x&-x))\n      s+=bit[x];\n    return s;\n  }\n  void add_impl(int\
    \ i,T a){\n    if(i==0) return;\n    for(int x=i;x<=n;x+=(x&-x))\n      bit[x]+=a;\n\
    \  }\npublic: // 0-indexed\n  int n;\n  vector<T> bit;\n  BIT(int n_):n(n_+1),bit(n+1,0){}\n\
    \n  // min({i | sum(i) >= w})\n  int lower_bound(int w){\n    if(w<=0) return\
    \ 0;\n    int x=0,r=1;\n    while(r<n) r<<=1;\n    for(int k=r;k>0;k>>=1){\n \
    \     if(x+k<=n&&bit[x+k]<w){\n        w-=bit[x+k];\n        x+=k;\n      }\n\
    \    }\n    return x;\n  }\n\n  T sum(int i){return sum_impl(i+1);}\n  void add(int\
    \ i,T a){add_impl(i+1,a);}\n  T query(int l,int r){return sum_impl(r)-sum_impl(l);}\n\
    };\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename T>\nclass BIT{\nprivate:\
    \ // 1-indexed\n  T sum_impl(int i){\n    T s(0);\n    for(int x=i;x>0;x-=(x&-x))\n\
    \      s+=bit[x];\n    return s;\n  }\n  void add_impl(int i,T a){\n    if(i==0)\
    \ return;\n    for(int x=i;x<=n;x+=(x&-x))\n      bit[x]+=a;\n  }\npublic: //\
    \ 0-indexed\n  int n;\n  vector<T> bit;\n  BIT(int n_):n(n_+1),bit(n+1,0){}\n\n\
    \  // min({i | sum(i) >= w})\n  int lower_bound(int w){\n    if(w<=0) return 0;\n\
    \    int x=0,r=1;\n    while(r<n) r<<=1;\n    for(int k=r;k>0;k>>=1){\n      if(x+k<=n&&bit[x+k]<w){\n\
    \        w-=bit[x+k];\n        x+=k;\n      }\n    }\n    return x;\n  }\n\n \
    \ T sum(int i){return sum_impl(i+1);}\n  void add(int i,T a){add_impl(i+1,a);}\n\
    \  T query(int l,int r){return sum_impl(r)-sum_impl(l);}\n};\n//END CUT HERE\n\
    #ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/binaryindexedtree.cpp
  requiredBy: []
  timestamp: '2020-09-15 23:17:07+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/GRL_5_D.test.cpp
  - test/aoj/DSL_2_B.test.cpp
  - test/aoj/0343.test.cpp
  - test/yukicoder/1732.test.cpp
  - test/yukicoder/4852.test.cpp
  - test/yukicoder/2125.test.cpp
  - test/yosupo/vertex_add_path_sum.test.cpp
  - test/yosupo/vertex_add_subtree_sum.test.cpp
  - test/yosupo/point_add_range_sum.test.cpp
documentation_of: ./datastructure/binaryindexedtree.cpp
layout: document
title: Binary Indexed Tree
---

## できること
- sum
-- $i$ 番目までの要素の和 (inclusive) を求める
- add
-- $i$ 番目の要素に $a$ を加算する
- lower_bound
-- 非負要素からなる列に対し、$\min \lbrace i \mid \rm{sum}(i) \ge w \rbrace$ を求める

## verify 用問題一覧
- lower_bound
-- [AOJ 0343](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0343)
