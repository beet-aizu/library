---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convexhulltrick/segmentcontainer.cpp
    title: convexhulltrick/segmentcontainer.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"test/yosupo/segment_add_get_min.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"convexhulltrick/segmentcontainer.cpp\"\
    \n\n#line 3 \"convexhulltrick/segmentcontainer.cpp\"\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nenum Objective{\n  MINIMIZE = +1,\n  MAXIMIZE = -1,\n};\n\n\
    template <typename T,Objective objective>\nstruct SegmentContainer{\n  const T\
    \ INF = numeric_limits<T>::max() / 2;\n  struct Segment{\n    T a,b;\n    T operator()(T\
    \ x) const{return a*x+b;}\n  };\n\n  int n;\n  vector<T> xs;\n  vector<Segment>\
    \ dat;\n  SegmentContainer(const vector<T> &xs_):xs(xs_){\n    sort(xs.begin(),xs.end());\n\
    \    xs.erase(unique(xs.begin(),xs.end()),xs.end());\n    n=xs.size();\n    dat.assign(n<<1,Segment({T(0),INF}));\n\
    \  }\n\n  inline int index(T x) const{\n    return lower_bound(xs.begin(),xs.end(),x)-xs.begin();\n\
    \  }\n\n  // [xl, xr)\n  void add(T a,T b,T xl,T xr){\n    Segment g({a*objective,b*objective});\n\
    \    for(int l=index(xl)+n,r=index(xr)+n;l<r;l>>=1,r>>=1){\n      if(l&1) update(g,l++);\n\
    \      if(r&1) update(g,--r);\n    }\n  }\n\n  void update(Segment g,int i){\n\
    \    int l=i,r=i+1;\n    while(l<n) l<<=1,r<<=1;\n    while(l<r){\n      int m=(l+r)>>1;\n\
    \      T xl=xs[l-n],xr=xs[r-1-n],xm=xs[m-n];\n      Segment &f=dat[i];\n     \
    \ if(f(xl)<=g(xl) and f(xr)<=g(xr)) return;\n      if(f(xl)>=g(xl) and f(xr)>=g(xr))\
    \ return (void)(f=g);\n      if(f(xm)>g(xm)) swap(f,g);\n      if(f(xl)>g(xl))\
    \ i=(i<<1)|0,r=m;\n      else i=(i<<1)|1,l=m;\n    }\n  }\n\n  T query(T x){\n\
    \    T res=INF;\n    for(int i=index(x)+n;i;i>>=1) res=min(res,dat[i](x));\n \
    \   return res*objective;\n  }\n};\ntemplate<typename T>\nusing MinSegmentContainer\
    \ = SegmentContainer<T, Objective::MINIMIZE>;\ntemplate<typename T>\nusing MaxSegmentContainer\
    \ = SegmentContainer<T, Objective::MAXIMIZE>;\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n#line 8 \"test/yosupo/segment_add_get_min.test.cpp\"\
    \n#undef call_from_test\n\n#ifdef SANITIZE\n#define IGNORE\n#endif\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  using ll = long long;\n  int n,q;\n\
    \  cin>>n>>q;\n  vector<ll> ls(n),rs(n),as(n),bs(n);\n  for(int i=0;i<n;i++) cin>>ls[i]>>rs[i]>>as[i]>>bs[i];\n\
    \n  vector<ll> ts(q),v0(q),v1(q),v2(q),v3(q);\n  for(int i=0;i<q;i++){\n    cin>>ts[i];\n\
    \    if(ts[i]==0) cin>>v0[i]>>v1[i]>>v2[i]>>v3[i];\n    if(ts[i]==1) cin>>v0[i];\n\
    \  }\n\n  vector<ll> ps;\n  for(int i=0;i<n;i++){\n    ps.emplace_back(ls[i]);\n\
    \    ps.emplace_back(rs[i]);\n  }\n  for(int i=0;i<q;i++){\n    ps.emplace_back(v0[i]);\n\
    \    ps.emplace_back(v1[i]);\n  }\n  MinSegmentContainer<ll> seg(ps);\n\n  for(int\
    \ i=0;i<n;i++) seg.add(as[i],bs[i],ls[i],rs[i]);\n  for(int i=0;i<q;i++){\n  \
    \  if(ts[i]==0) seg.add(v2[i],v3[i],v0[i],v1[i]);\n    if(ts[i]==1){\n      auto\
    \ res=seg.query(v0[i]);\n      if(res>2e18) cout<<\"INFINITY\"<<'\\n';\n     \
    \ else cout<<res<<\"\\n\";\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../convexhulltrick/segmentcontainer.cpp\"\n#undef call_from_test\n\n#ifdef\
    \ SANITIZE\n#define IGNORE\n#endif\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  using ll = long long;\n  int n,q;\n  cin>>n>>q;\n  vector<ll> ls(n),rs(n),as(n),bs(n);\n\
    \  for(int i=0;i<n;i++) cin>>ls[i]>>rs[i]>>as[i]>>bs[i];\n\n  vector<ll> ts(q),v0(q),v1(q),v2(q),v3(q);\n\
    \  for(int i=0;i<q;i++){\n    cin>>ts[i];\n    if(ts[i]==0) cin>>v0[i]>>v1[i]>>v2[i]>>v3[i];\n\
    \    if(ts[i]==1) cin>>v0[i];\n  }\n\n  vector<ll> ps;\n  for(int i=0;i<n;i++){\n\
    \    ps.emplace_back(ls[i]);\n    ps.emplace_back(rs[i]);\n  }\n  for(int i=0;i<q;i++){\n\
    \    ps.emplace_back(v0[i]);\n    ps.emplace_back(v1[i]);\n  }\n  MinSegmentContainer<ll>\
    \ seg(ps);\n\n  for(int i=0;i<n;i++) seg.add(as[i],bs[i],ls[i],rs[i]);\n  for(int\
    \ i=0;i<q;i++){\n    if(ts[i]==0) seg.add(v2[i],v3[i],v0[i],v1[i]);\n    if(ts[i]==1){\n\
    \      auto res=seg.query(v0[i]);\n      if(res>2e18) cout<<\"INFINITY\"<<'\\\
    n';\n      else cout<<res<<\"\\n\";\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - convexhulltrick/segmentcontainer.cpp
  isVerificationFile: true
  path: test/yosupo/segment_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2020-11-22 19:37:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/segment_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/segment_add_get_min.test.cpp
- /verify/test/yosupo/segment_add_get_min.test.cpp.html
title: test/yosupo/segment_add_get_min.test.cpp
---
