---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segtree/cht/lichao.cpp
    title: segtree/cht/lichao.cpp
  - icon: ':heavy_check_mark:'
    path: vector/compress.cpp
    title: vector/compress.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/yosupo/line_add_get_min.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 2 \"vector/compress.cpp\"\
    \n\n#ifndef call_from_test\n#line 5 \"vector/compress.cpp\"\nusing namespace std;\n\
    #endif\n\n//BEGIN CUT HERE\ntemplate<typename V>\nV compress(V vs){\n  sort(vs.begin(),vs.end());\n\
    \  vs.erase(unique(vs.begin(),vs.end()),vs.end());\n  return vs;\n}\ntemplate<typename\
    \ T>\nmap<T, int> dict(const vector<T> &vs){\n  map<T, int> res;\n  for(int i=0;i<(int)vs.size();i++)\n\
    \    res[vs[i]]=i;\n  return res;\n}\nmap<char, int> dict(const string &s){\n\
    \  return dict(vector<char>(s.begin(),s.end()));\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n#line 1 \"segtree/cht/lichao.cpp\"\
    \n\n#line 3 \"segtree/cht/lichao.cpp\"\nusing namespace std;\n#endif\n//BEGIN\
    \ CUT HERE\ntemplate <typename T, bool isMin>\nstruct LiChao{\n  const T INF =\
    \ numeric_limits<T>::max();\n  struct Line{\n    T a,b;\n    Line(T a,T b):a(isMin?a:-a),b(isMin?b:-b){}\n\
    \    T operator()(T x) const{return a*x+b;}\n  };\n\n  int n;\n  vector<T> xs;\n\
    \  vector<Line> dat;\n  LiChao(const vector<T> &xs_):xs(xs_){\n    sort(xs.begin(),xs.end());\n\
    \    xs.erase(unique(xs.begin(),xs.end()),xs.end());\n    n=xs.size();\n    dat.assign(n<<1,Line(T(0),INF));\n\
    \  }\n\n  int index(T x) const{\n    return lower_bound(xs.begin(),xs.end(),x)-xs.begin();\n\
    \  }\n\n  T get(T x){\n    T res=INF;\n    for(int i=index(x)+n;i;i>>=1) res=min(res,dat[i](x));\n\
    \    return isMin?res:-res;\n  }\n\n  // [xl, xr)\n  void add_segment(T a,T b,T\
    \ xl,T xr){\n    Line g(a,b);\n    for(int l=index(xl)+n,r=index(xr)+n;l<r;l>>=1,r>>=1){\n\
    \      if(l&1) update(g,l++);\n      if(r&1) update(g,--r);\n    }\n  }\n\n  void\
    \ update(Line g,int i){\n    int l=i,r=i+1;\n    while(l<n) l<<=1,r<<=1;\n   \
    \ while(l<r){\n      int m=(l+r)>>1;\n      T xl=xs[l-n],xr=xs[r-1-n],xm=xs[m-n];\n\
    \      Line &f=dat[i];\n      if(f(xl)<=g(xl) and f(xr)<=g(xr)) return;\n    \
    \  if(f(xl)>=g(xl) and f(xr)>=g(xr)) return (void)(f=g);\n      if(f(xm)>g(xm))\
    \ swap(f,g);\n      if(f(xl)>g(xl)) i=(i<<1)|0,r=m;\n      else i=(i<<1)|1,l=m;\n\
    \    }\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\
    signed main(){\n  return 0;\n}\n#endif\n#line 9 \"test/yosupo/line_add_get_min.test.cpp\"\
    \n#undef call_from_test\n\n#ifdef SANITIZE\n#define IGNORE\n#endif\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  using ll = long long;\n  int n,q;\n\
    \  cin>>n>>q;\n  vector<ll> as(n),bs(n);\n  for(int i=0;i<n;i++) cin>>as[i]>>bs[i];\n\
    \n  vector<ll> ts(q),xs(q),ys(q);\n  vector<ll> ps;\n  for(int i=0;i<q;i++){\n\
    \    cin>>ts[i];\n    if(ts[i]==0) cin>>xs[i]>>ys[i];\n    if(ts[i]==1) cin>>xs[i];\n\
    \    ps.emplace_back(xs[i]);\n  }\n  int lb=-1e9,ub=+1e9;\n  ps.emplace_back(lb);\n\
    \  ps.emplace_back(ub);\n  LiChao<ll, true> seg(ps);\n\n  for(int i=0;i<n;i++)\
    \ seg.add_segment(as[i],bs[i],lb,ub);\n  for(int i=0;i<q;i++){\n    if(ts[i]==0)\
    \ seg.add_segment(xs[i],ys[i],lb,ub);\n    if(ts[i]==1) cout<<seg.get(xs[i])<<\"\
    \\n\";\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../vector/compress.cpp\"\n#include \"../../segtree/cht/lichao.cpp\"\n#undef\
    \ call_from_test\n\n#ifdef SANITIZE\n#define IGNORE\n#endif\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  using ll = long long;\n  int n,q;\n\
    \  cin>>n>>q;\n  vector<ll> as(n),bs(n);\n  for(int i=0;i<n;i++) cin>>as[i]>>bs[i];\n\
    \n  vector<ll> ts(q),xs(q),ys(q);\n  vector<ll> ps;\n  for(int i=0;i<q;i++){\n\
    \    cin>>ts[i];\n    if(ts[i]==0) cin>>xs[i]>>ys[i];\n    if(ts[i]==1) cin>>xs[i];\n\
    \    ps.emplace_back(xs[i]);\n  }\n  int lb=-1e9,ub=+1e9;\n  ps.emplace_back(lb);\n\
    \  ps.emplace_back(ub);\n  LiChao<ll, true> seg(ps);\n\n  for(int i=0;i<n;i++)\
    \ seg.add_segment(as[i],bs[i],lb,ub);\n  for(int i=0;i<q;i++){\n    if(ts[i]==0)\
    \ seg.add_segment(xs[i],ys[i],lb,ub);\n    if(ts[i]==1) cout<<seg.get(xs[i])<<\"\
    \\n\";\n  }\n  return 0;\n}\n"
  dependsOn:
  - vector/compress.cpp
  - segtree/cht/lichao.cpp
  isVerificationFile: true
  path: test/yosupo/line_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2020-10-02 23:55:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/line_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/line_add_get_min.test.cpp
- /verify/test/yosupo/line_add_get_min.test.cpp.html
title: test/yosupo/line_add_get_min.test.cpp
---
