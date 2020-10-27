---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0343.test.cpp
    title: test/aoj/0343.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2270.test.cpp
    title: test/aoj/2270.test.cpp
  - icon: ':x:'
    path: test/aoj/GRL_5_D.test.cpp
    title: test/aoj/GRL_5_D.test.cpp
  - icon: ':x:'
    path: test/yosupo/point_add_range_sum.test.cpp
    title: test/yosupo/point_add_range_sum.test.cpp
  - icon: ':x:'
    path: test/yosupo/static_range_inversions_query.test.cpp
    title: test/yosupo/static_range_inversions_query.test.cpp
  - icon: ':x:'
    path: test/yosupo/vertex_add_path_sum.test.cpp
    title: test/yosupo/vertex_add_path_sum.test.cpp
  - icon: ':x:'
    path: test/yosupo/vertex_add_subtree_sum.test.cpp
    title: test/yosupo/vertex_add_subtree_sum.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1732.test.cpp
    title: test quantile
  - icon: ':x:'
    path: test/yukicoder/2125.test.cpp
    title: test/yukicoder/2125.test.cpp
  - icon: ':x:'
    path: test/yukicoder/4852.test.cpp
    title: test/yukicoder/4852.test.cpp
  - icon: ':x:'
    path: test/yukicoder/5223.test.cpp
    title: test/yukicoder/5223.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructure/binaryindexedtree.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename T>\nclass\
    \ BIT{\nprivate:\n  // \\sum_{j < i}  v[j]\n  T sum(int i){\n    T s(0);\n   \
    \ for(int x=i;x>0;x-=(x&-x))\n      s+=bit[x];\n    return s;\n  }\npublic:\n\
    \  int n;\n  vector<T> bit;\n  BIT(int n_):n(n_+1),bit(n+1,0){}\n\n  // v[i] +=\
    \ a\n  void add(int i,T a){\n    for(int x=++i;x<=n;x+=(x&-x))\n      bit[x]+=a;\n\
    \  }\n  // \\sum_{l <= i < r} v[i]\n  T query(int l,int r){return sum(r)-sum(l);}\n\
    \n  // min({x | sum(x) >= w})\n  int lower_bound(const T w){\n    if(w<=0) return\
    \ 0;\n    T r=w;\n    int x=0,p=1;\n    while(p<n) p<<=1;\n    for(int k=p;k>0;k>>=1){\n\
    \      if(x+k<=n and bit[x+k]<r){\n        r-=bit[x+k];\n        x+=k;\n     \
    \ }\n    }\n    x++;\n    assert(sum(x-1)<w and sum(x)>=w);\n    return x;\n \
    \ }\n\n  // min({x | sum(x) > w})\n  int upper_bound(T w){return lower_bound(w+1);}\n\
    };\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n\n//BEGIN CUT HERE\ntemplate<typename T>\nclass BIT{\nprivate:\n  // \\\
    sum_{j < i}  v[j]\n  T sum(int i){\n    T s(0);\n    for(int x=i;x>0;x-=(x&-x))\n\
    \      s+=bit[x];\n    return s;\n  }\npublic:\n  int n;\n  vector<T> bit;\n \
    \ BIT(int n_):n(n_+1),bit(n+1,0){}\n\n  // v[i] += a\n  void add(int i,T a){\n\
    \    for(int x=++i;x<=n;x+=(x&-x))\n      bit[x]+=a;\n  }\n  // \\sum_{l <= i\
    \ < r} v[i]\n  T query(int l,int r){return sum(r)-sum(l);}\n\n  // min({x | sum(x)\
    \ >= w})\n  int lower_bound(const T w){\n    if(w<=0) return 0;\n    T r=w;\n\
    \    int x=0,p=1;\n    while(p<n) p<<=1;\n    for(int k=p;k>0;k>>=1){\n      if(x+k<=n\
    \ and bit[x+k]<r){\n        r-=bit[x+k];\n        x+=k;\n      }\n    }\n    x++;\n\
    \    assert(sum(x-1)<w and sum(x)>=w);\n    return x;\n  }\n\n  // min({x | sum(x)\
    \ > w})\n  int upper_bound(T w){return lower_bound(w+1);}\n};\n//END CUT HERE\n\
    #ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/binaryindexedtree.cpp
  requiredBy: []
  timestamp: '2020-10-27 12:55:52+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/4852.test.cpp
  - test/yukicoder/2125.test.cpp
  - test/yukicoder/5223.test.cpp
  - test/yukicoder/1732.test.cpp
  - test/aoj/0343.test.cpp
  - test/aoj/2270.test.cpp
  - test/aoj/GRL_5_D.test.cpp
  - test/yosupo/point_add_range_sum.test.cpp
  - test/yosupo/vertex_add_path_sum.test.cpp
  - test/yosupo/vertex_add_subtree_sum.test.cpp
  - test/yosupo/static_range_inversions_query.test.cpp
documentation_of: datastructure/binaryindexedtree.cpp
layout: document
title: Binary Indexed Tree
---

## できること
- `add(i,a)`
-- $v_i := v_i + a$ とする
- `query(l,r)`
-- $\sum_{l \leq i \lt r} v_i$ を求める
- `lower_bound(w)`
-- $v_i \geq 0$ の仮定のもと、$\min (\lbrace i \mid \rm{sum}(i) \ge w \rbrace)$ を求める
- `upper_bound(w)`
-- $v_i \geq 0$ の仮定のもと、$\min (\lbrace i \mid \rm{sum}(i) \gt w \rbrace)$ を求める

## verify 用問題一覧
- lower_bound
-- [AOJ 0343](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0343)
