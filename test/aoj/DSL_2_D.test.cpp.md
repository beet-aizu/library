---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
  bundledCode: "#line 1 \"test/aoj/DSL_2_D.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #line 1 \"segtree/basic/dual.cpp\"\n\n#line 3 \"segtree/basic/dual.cpp\"\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate <typename E>\nstruct SegmentTree{\n\
    \  using H = function<E(E,E)>;\n  int n,height;\n  H h;\n  E ei;\n  vector<E>\
    \ laz;\n\n  SegmentTree(H h,E ei):h(h),ei(ei){}\n\n  void init(int n_){\n    n=1;height=0;\n\
    \    while(n<n_) n<<=1,height++;\n    laz.assign(2*n,ei);\n  }\n\n  inline void\
    \ propagate(int k){\n    if(laz[k]==ei) return;\n    laz[(k<<1)|0]=h(laz[(k<<1)|0],laz[k]);\n\
    \    laz[(k<<1)|1]=h(laz[(k<<1)|1],laz[k]);\n    laz[k]=ei;\n  }\n\n  inline void\
    \ thrust(int k){\n    for(int i=height;i;i--) propagate(k>>i);\n  }\n\n  void\
    \ update(int a,int b,E x){\n    if(a>=b) return;\n    thrust(a+=n);\n    thrust(b+=n-1);\n\
    \    for(int l=a,r=b+1;l<r;l>>=1,r>>=1){\n      if(l&1) laz[l]=h(laz[l],x),l++;\n\
    \      if(r&1) --r,laz[r]=h(laz[r],x);\n    }\n  }\n\n  E get_val(int a){\n  \
    \  thrust(a+=n);\n    return laz[a];\n  }\n\n  void set_val(int a,E x){\n    thrust(a+=n);\n\
    \    laz[a]=x;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE\
    \ HERE\nsigned main(){\n  return 0;\n}\n#endif\n#line 8 \"test/aoj/DSL_2_D.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,q;\n  cin>>n>>q;\n\n  auto h=[](int a,int b){(void)a;return b;};\n \
    \ int ei=INT_MAX;\n  SegmentTree<int> seg(h,ei);\n  seg.init(n);\n\n  for(int\
    \ i=0;i<q;i++){\n    int tp;\n    cin>>tp;\n    if(tp==0){\n      int s,t,x;\n\
    \      cin>>s>>t>>x;\n      seg.update(s,t+1,x);\n    }\n    if(tp==1){\n    \
    \  int s;\n      cin>>s;\n      cout<<seg.get_val(s)<<\"\\n\";\n    }\n  }\n \
    \ cout<<flush;\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../segtree/basic/dual.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,q;\n  cin>>n>>q;\n\n  auto\
    \ h=[](int a,int b){(void)a;return b;};\n  int ei=INT_MAX;\n  SegmentTree<int>\
    \ seg(h,ei);\n  seg.init(n);\n\n  for(int i=0;i<q;i++){\n    int tp;\n    cin>>tp;\n\
    \    if(tp==0){\n      int s,t,x;\n      cin>>s>>t>>x;\n      seg.update(s,t+1,x);\n\
    \    }\n    if(tp==1){\n      int s;\n      cin>>s;\n      cout<<seg.get_val(s)<<\"\
    \\n\";\n    }\n  }\n  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - segtree/basic/dual.cpp
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segtree/basic/dual.cpp
    title: segtree/basic/dual.cpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: test/aoj/DSL_2_D.test.cpp
  requiredBy: []
  timestamp: '2020-05-07 20:09:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: test/aoj/DSL_2_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_D.test.cpp
- /verify/test/aoj/DSL_2_D.test.cpp.html
title: test/aoj/DSL_2_D.test.cpp
---
