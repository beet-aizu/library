---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segtree/basic/ushi.cpp
    title: segtree/basic/ushi.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "#line 1 \"test/aoj/DSL_2_A.test.cpp\"\n// verification-helper: PROBLEM\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#line 1 \"\
    segtree/basic/ushi.cpp\"\n\n#line 3 \"segtree/basic/ushi.cpp\"\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate <typename T>\nstruct SegmentTree{\n\
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
    #ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n#line 8 \"test/aoj/DSL_2_A.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,q;\n  cin>>n>>q;\n  auto f=[](int a,int b){return min(a,b);};\n  SegmentTree<int>\
    \ rmq(f,INT_MAX);\n  rmq.init(n);\n\n  for(int i=0;i<q;i++){\n    int c,x,y;\n\
    \    cin>>c>>x>>y;\n    if(c) cout<<rmq.query(x,y+1)<<\"\\n\";\n    else rmq.set_val(x,y);\n\
    \  }\n  cout<<flush;\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../segtree/basic/ushi.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,q;\n  cin>>n>>q;\n  auto\
    \ f=[](int a,int b){return min(a,b);};\n  SegmentTree<int> rmq(f,INT_MAX);\n \
    \ rmq.init(n);\n\n  for(int i=0;i<q;i++){\n    int c,x,y;\n    cin>>c>>x>>y;\n\
    \    if(c) cout<<rmq.query(x,y+1)<<\"\\n\";\n    else rmq.set_val(x,y);\n  }\n\
    \  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - segtree/basic/ushi.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_A.test.cpp
  requiredBy: []
  timestamp: '2021-02-05 14:59:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_A.test.cpp
- /verify/test/aoj/DSL_2_A.test.cpp.html
title: test/aoj/DSL_2_A.test.cpp
---
