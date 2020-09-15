---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: datastructure/binaryindexedtree.cpp
    title: Binary Indexed Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"test/aoj/DSL_2_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #line 2 \"datastructure/binaryindexedtree.cpp\"\n\n#ifndef call_from_test\n#line\
    \ 5 \"datastructure/binaryindexedtree.cpp\"\nusing namespace std;\n#endif\n\n\
    //BEGIN CUT HERE\ntemplate<typename T>\nclass BIT{\nprivate: // 1-indexed\n  T\
    \ sum_impl(int i){\n    T s(0);\n    for(int x=i;x>0;x-=(x&-x))\n      s+=bit[x];\n\
    \    return s;\n  }\n  void add_impl(int i,T a){\n    if(i==0) return;\n    for(int\
    \ x=i;x<=n;x+=(x&-x))\n      bit[x]+=a;\n  }\npublic: // 0-indexed\n  int n;\n\
    \  vector<T> bit;\n  BIT(int n_):n(n_+1),bit(n+1,0){}\n\n  // min({i | sum(i)\
    \ >= w})\n  int lower_bound(int w){\n    if(w<=0) return 0;\n    int x=0,r=1;\n\
    \    while(r<n) r<<=1;\n    for(int k=r;k>0;k>>=1){\n      if(x+k<=n&&bit[x+k]<w){\n\
    \        w-=bit[x+k];\n        x+=k;\n      }\n    }\n    return x;\n  }\n\n \
    \ T sum(int i){return sum_impl(i+1);}\n  void add(int i,T a){add_impl(i+1,a);}\n\
    \  T query(int l,int r){return sum_impl(r+1)-sum_impl(l+1);}\n};\n//END CUT HERE\n\
    #ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n#line 8 \"test/aoj/DSL_2_B.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,q;\n  cin>>n>>q;\n  BIT<long long> bit(n+100);\n  for(int i=0;i<q;i++){\n\
    \    int c,x,y;\n    cin>>c>>x>>y;\n    if(c==0) bit.add(x,y);\n    if(c==1) cout<<bit.query(x,y+1)<<\"\
    \\n\";\n  }\n  cout<<flush;\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../datastructure/binaryindexedtree.cpp\"\n#undef call_from_test\n\
    \nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,q;\n  cin>>n>>q;\n\
    \  BIT<long long> bit(n+100);\n  for(int i=0;i<q;i++){\n    int c,x,y;\n    cin>>c>>x>>y;\n\
    \    if(c==0) bit.add(x,y);\n    if(c==1) cout<<bit.query(x,y+1)<<\"\\n\";\n \
    \ }\n  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - datastructure/binaryindexedtree.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_B.test.cpp
  requiredBy: []
  timestamp: '2020-09-15 23:04:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL_2_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_B.test.cpp
- /verify/test/aoj/DSL_2_B.test.cpp.html
title: test/aoj/DSL_2_B.test.cpp
---
