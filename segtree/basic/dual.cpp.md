---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2359.test.cpp
    title: test/aoj/2359.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3112.test.cpp
    title: test query
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_D.test.cpp
    title: test/aoj/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_E.test.cpp
    title: test/aoj/DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/3912.test.cpp
    title: test/yukicoder/3912.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segtree/basic/dual.cpp\"\n\n#include<bits/stdc++.h>\nusing\
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
    \ HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate <typename E>\nstruct SegmentTree{\n  using H = function<E(E,E)>;\n\
    \  int n,height;\n  H h;\n  E ei;\n  vector<E> laz;\n\n  SegmentTree(H h,E ei):h(h),ei(ei){}\n\
    \n  void init(int n_){\n    n=1;height=0;\n    while(n<n_) n<<=1,height++;\n \
    \   laz.assign(2*n,ei);\n  }\n\n  inline void propagate(int k){\n    if(laz[k]==ei)\
    \ return;\n    laz[(k<<1)|0]=h(laz[(k<<1)|0],laz[k]);\n    laz[(k<<1)|1]=h(laz[(k<<1)|1],laz[k]);\n\
    \    laz[k]=ei;\n  }\n\n  inline void thrust(int k){\n    for(int i=height;i;i--)\
    \ propagate(k>>i);\n  }\n\n  void update(int a,int b,E x){\n    if(a>=b) return;\n\
    \    thrust(a+=n);\n    thrust(b+=n-1);\n    for(int l=a,r=b+1;l<r;l>>=1,r>>=1){\n\
    \      if(l&1) laz[l]=h(laz[l],x),l++;\n      if(r&1) --r,laz[r]=h(laz[r],x);\n\
    \    }\n  }\n\n  E get_val(int a){\n    thrust(a+=n);\n    return laz[a];\n  }\n\
    \n  void set_val(int a,E x){\n    thrust(a+=n);\n    laz[a]=x;\n  }\n};\n//END\
    \ CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: segtree/basic/dual.cpp
  requiredBy: []
  timestamp: '2019-12-17 13:36:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/3912.test.cpp
  - test/aoj/3112.test.cpp
  - test/aoj/2359.test.cpp
  - test/aoj/DSL_2_E.test.cpp
  - test/aoj/DSL_2_D.test.cpp
documentation_of: segtree/basic/dual.cpp
layout: document
redirect_from:
- /library/segtree/basic/dual.cpp
- /library/segtree/basic/dual.cpp.html
title: segtree/basic/dual.cpp
---
