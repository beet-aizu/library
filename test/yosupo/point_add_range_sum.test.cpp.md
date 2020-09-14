---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/binaryindexedtree.cpp
    title: Binary Indexed Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/yosupo/point_add_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 2 \"datastructure/binaryindexedtree.cpp\"\
    \n\n#ifndef call_from_test\n#line 5 \"datastructure/binaryindexedtree.cpp\"\n\
    using namespace std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct\
    \ BIT{\n  int n;\n  vector<T> bit;\n  // 1-indexed\n  BIT(int n_):n(n_+1),bit(n+1,0){}\n\
    \n  T sum(int i){\n    T s(0);\n    for(int x=i;x>0;x-=(x&-x))\n      s+=bit[x];\n\
    \    return s;\n  }\n\n  void add(int i,T a){\n    if(i==0) return;\n    for(int\
    \ x=i;x<=n;x+=(x&-x))\n      bit[x]+=a;\n  }\n\n  // [l, r)\n  T query(int l,int\
    \ r){\n    return sum(r-1)-sum(l-1);\n  }\n\n  int lower_bound(int w){\n    if(w<=0)\
    \ return 0;\n    int x=0,r=1;\n    while(r<n) r<<=1;\n    for(int k=r;k>0;k>>=1){\n\
    \      if(x+k<=n&&bit[x+k]<w){\n        w-=bit[x+k];\n        x+=k;\n      }\n\
    \    }\n    return x+1;\n  }\n\n  // 0-indexed\n  T sum0(int i){return sum(i+1);}\n\
    \  void add0(int i,T a){add(i+1,a);}\n  T query0(int l,int r){return sum(r)-sum(l);}\n\
    };\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n\
    #line 8 \"test/yosupo/point_add_range_sum.test.cpp\"\n#undef call_from_test\n\n\
    signed main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,q;\n  cin>>n>>q;\n\
    \n  vector<int> as(n);\n  for(int i=0;i<n;i++) cin>>as[i];\n\n  BIT<long long>\
    \ bit(n);\n  for(int i=0;i<n;i++) bit.add0(i,as[i]);\n\n  for(int i=0;i<q;i++){\n\
    \    int t;\n    cin>>t;\n    if(t==0){\n      int p,x;\n      cin>>p>>x;\n  \
    \    bit.add0(p,x);\n    }\n    if(t==1){\n      int l,r;\n      cin>>l>>r;\n\
    \      cout<<bit.query0(l,r)<<\"\\n\";\n    }\n  }\n  cout<<flush;\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../datastructure/binaryindexedtree.cpp\"\n#undef call_from_test\n\nsigned\
    \ main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,q;\n  cin>>n>>q;\n\
    \n  vector<int> as(n);\n  for(int i=0;i<n;i++) cin>>as[i];\n\n  BIT<long long>\
    \ bit(n);\n  for(int i=0;i<n;i++) bit.add0(i,as[i]);\n\n  for(int i=0;i<q;i++){\n\
    \    int t;\n    cin>>t;\n    if(t==0){\n      int p,x;\n      cin>>p>>x;\n  \
    \    bit.add0(p,x);\n    }\n    if(t==1){\n      int l,r;\n      cin>>l>>r;\n\
    \      cout<<bit.query0(l,r)<<\"\\n\";\n    }\n  }\n  cout<<flush;\n  return 0;\n\
    }\n"
  dependsOn:
  - datastructure/binaryindexedtree.cpp
  isVerificationFile: true
  path: test/yosupo/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2020-09-14 22:28:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_add_range_sum.test.cpp
- /verify/test/yosupo/point_add_range_sum.test.cpp.html
title: test/yosupo/point_add_range_sum.test.cpp
---
