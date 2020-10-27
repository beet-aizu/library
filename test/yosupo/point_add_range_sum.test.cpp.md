---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: datastructure/binaryindexedtree.cpp
    title: Binary Indexed Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/yosupo/point_add_range_sum.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/point_add_range_sum\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"datastructure/binaryindexedtree.cpp\"\
    \n\n#line 3 \"datastructure/binaryindexedtree.cpp\"\nusing namespace std;\n#endif\n\
    \n//BEGIN CUT HERE\ntemplate<typename T>\nclass BIT{\nprivate:\n  // \\sum_{j\
    \ < i}  v[j]\n  T sum(int i){\n    T s(0);\n    for(int x=i;x>0;x-=(x&-x))\n \
    \     s+=bit[x];\n    return s;\n  }\npublic:\n  int n;\n  vector<T> bit;\n  BIT(int\
    \ n_):n(n_+1),bit(n+1,0){}\n\n  // v[i] += a\n  void add(int i,T a){\n    for(int\
    \ x=++i;x<=n;x+=(x&-x))\n      bit[x]+=a;\n  }\n  // \\sum_{l <= i < r} v[i]\n\
    \  T query(int l,int r){return sum(r)-sum(l);}\n\n  // min({x | sum(x) >= w})\n\
    \  int lower_bound(const T w){\n    if(w<=0) return 0;\n    T r=w;\n    int x=0,p=1;\n\
    \    while(p<n) p<<=1;\n    for(int k=p;k>0;k>>=1){\n      if(x+k<=n and bit[x+k]<r){\n\
    \        r-=bit[x+k];\n        x+=k;\n      }\n    }\n    x++;\n    assert(sum(x-1)<w\
    \ and sum(x)>=w);\n    return x;\n  }\n\n  // min({x | sum(x) > w})\n  int upper_bound(T\
    \ w){return lower_bound(w+1);}\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n#line 8 \"test/yosupo/point_add_range_sum.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,q;\n  cin>>n>>q;\n\n  vector<int> as(n);\n  for(int i=0;i<n;i++) cin>>as[i];\n\
    \n  BIT<long long> bit(n);\n  for(int i=0;i<n;i++) bit.add(i,as[i]);\n\n  for(int\
    \ i=0;i<q;i++){\n    int t;\n    cin>>t;\n    if(t==0){\n      int p,x;\n    \
    \  cin>>p>>x;\n      bit.add(p,x);\n    }\n    if(t==1){\n      int l,r;\n   \
    \   cin>>l>>r;\n      cout<<bit.query(l,r)<<'\\n';\n    }\n  }\n  return 0;\n\
    }\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/point_add_range_sum\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../datastructure/binaryindexedtree.cpp\"\n#undef call_from_test\n\nsigned\
    \ main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,q;\n  cin>>n>>q;\n\
    \n  vector<int> as(n);\n  for(int i=0;i<n;i++) cin>>as[i];\n\n  BIT<long long>\
    \ bit(n);\n  for(int i=0;i<n;i++) bit.add(i,as[i]);\n\n  for(int i=0;i<q;i++){\n\
    \    int t;\n    cin>>t;\n    if(t==0){\n      int p,x;\n      cin>>p>>x;\n  \
    \    bit.add(p,x);\n    }\n    if(t==1){\n      int l,r;\n      cin>>l>>r;\n \
    \     cout<<bit.query(l,r)<<'\\n';\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - datastructure/binaryindexedtree.cpp
  isVerificationFile: true
  path: test/yosupo/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 12:55:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_add_range_sum.test.cpp
- /verify/test/yosupo/point_add_range_sum.test.cpp.html
title: test/yosupo/point_add_range_sum.test.cpp
---
