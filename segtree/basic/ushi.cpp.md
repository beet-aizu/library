---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0367.test.cpp
    title: test/aoj/0367.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2644.test.cpp
    title: test/aoj/2644.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2969.test.cpp
    title: test/aoj/2969.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_set_range_composite.test.cpp
    title: test/yosupo/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/3277.test.cpp
    title: test/yukicoder/3277.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segtree/basic/ushi.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate <typename T>\nstruct SegmentTree{\n\
    \  using F = function<T(T,T)>;\n  int n;\n  F f;\n  T ti;\n  vector<T> dat;\n\n\
    \  SegmentTree(F f,T ti):f(f),ti(ti){}\n\n  void init(int n_){\n    n=1;\n   \
    \ while(n<n_) n<<=1;\n    dat.assign(n<<1,ti);\n  }\n\n  void build(const vector<T>\
    \ &v){\n    int n_=v.size();\n    init(n_);\n    for(int i=0;i<n_;i++) dat[n+i]=v[i];\n\
    \    for(int i=n-1;i;i--)\n      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);\n  }\n\
    \n  void set_val(int k,T x){\n    dat[k+=n]=x;\n    while(k>>=1)\n      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);\n\
    \  }\n\n  T query(int a,int b){\n    if(a>=b) return ti;\n    T vl=ti,vr=ti;\n\
    \    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {\n      if(l&1) vl=f(vl,dat[l++]);\n\
    \      if(r&1) vr=f(dat[--r],vr);\n    }\n    return f(vl,vr);\n  }\n\n  template<typename\
    \ C>\n  int max_right(int s,C &check,T &acc,int k,int l,int r){\n    if(l+1==r){\n\
    \      acc=f(acc,dat[k]);\n      return check(acc)?-1:k-n;\n    }\n    int m=(l+r)>>1;\n\
    \    if(m<=s) return max_right(s,check,acc,(k<<1)|1,m,r);\n    if(s<=l and check(f(acc,dat[k]))){\n\
    \      acc=f(acc,dat[k]);\n      return -1;\n    }\n    int vl=max_right(s,check,acc,(k<<1)|0,l,m);\n\
    \    if(~vl) return vl;\n    return max_right(s,check,acc,(k<<1)|1,m,r);\n  }\n\
    \n  // max t s.t. check(query(s,t))\n  // O(\\log N)\n  template<typename C>\n\
    \  int max_right(int s,C &check){\n    assert(s<n and check(ti) and not check(query(s,n)));\n\
    \    T acc=ti;\n    return max_right(s,check,acc,1,0,n);\n  }\n};\n//END CUT HERE\n\
    #ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate <typename T>\nstruct SegmentTree{\n  using\
    \ F = function<T(T,T)>;\n  int n;\n  F f;\n  T ti;\n  vector<T> dat;\n\n  SegmentTree(F\
    \ f,T ti):f(f),ti(ti){}\n\n  void init(int n_){\n    n=1;\n    while(n<n_) n<<=1;\n\
    \    dat.assign(n<<1,ti);\n  }\n\n  void build(const vector<T> &v){\n    int n_=v.size();\n\
    \    init(n_);\n    for(int i=0;i<n_;i++) dat[n+i]=v[i];\n    for(int i=n-1;i;i--)\n\
    \      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);\n  }\n\n  void set_val(int k,T x){\n\
    \    dat[k+=n]=x;\n    while(k>>=1)\n      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);\n\
    \  }\n\n  T query(int a,int b){\n    if(a>=b) return ti;\n    T vl=ti,vr=ti;\n\
    \    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {\n      if(l&1) vl=f(vl,dat[l++]);\n\
    \      if(r&1) vr=f(dat[--r],vr);\n    }\n    return f(vl,vr);\n  }\n\n  template<typename\
    \ C>\n  int max_right(int s,C &check,T &acc,int k,int l,int r){\n    if(l+1==r){\n\
    \      acc=f(acc,dat[k]);\n      return check(acc)?-1:k-n;\n    }\n    int m=(l+r)>>1;\n\
    \    if(m<=s) return max_right(s,check,acc,(k<<1)|1,m,r);\n    if(s<=l and check(f(acc,dat[k]))){\n\
    \      acc=f(acc,dat[k]);\n      return -1;\n    }\n    int vl=max_right(s,check,acc,(k<<1)|0,l,m);\n\
    \    if(~vl) return vl;\n    return max_right(s,check,acc,(k<<1)|1,m,r);\n  }\n\
    \n  // max t s.t. check(query(s,t))\n  // O(\\log N)\n  template<typename C>\n\
    \  int max_right(int s,C &check){\n    assert(s<n and check(ti) and not check(query(s,n)));\n\
    \    T acc=ti;\n    return max_right(s,check,acc,1,0,n);\n  }\n};\n//END CUT HERE\n\
    #ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: segtree/basic/ushi.cpp
  requiredBy: []
  timestamp: '2021-02-05 14:59:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/point_set_range_composite.test.cpp
  - test/yukicoder/3277.test.cpp
  - test/aoj/2969.test.cpp
  - test/aoj/2644.test.cpp
  - test/aoj/0367.test.cpp
documentation_of: segtree/basic/ushi.cpp
layout: document
redirect_from:
- /library/segtree/basic/ushi.cpp
- /library/segtree/basic/ushi.cpp.html
title: segtree/basic/ushi.cpp
---
