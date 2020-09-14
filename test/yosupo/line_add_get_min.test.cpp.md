---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: vector/compress.cpp
    title: vector/compress.cpp
  - icon: ':heavy_check_mark:'
    path: segtree/cht/lichao.cpp
    title: segtree/cht/lichao.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
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
    \ CUT HERE\ntemplate <typename T, bool isMin>\nstruct LiChao{\n  static constexpr\
    \ T INF = numeric_limits<T>::max();\n  struct Line{\n    T a,b;\n    Line(T a,T\
    \ b):a(a),b(b){}\n    T get(T x){return a*x+b;}\n  };\n\n  int n;\n  vector<T>\
    \ pos;\n  vector<Line> dat;\n  LiChao(int n){\n    pos.resize(n);\n    iota(pos.begin(),pos.end(),T(0));\n\
    \    init(n);\n  }\n\n  LiChao(const vector<T> &pos):pos(pos){init(pos.size());}\n\
    \n  void init(int n_){\n    n=1;\n    while(n<n_) n<<=1;\n    while((int)pos.size()<n)\n\
    \      pos.emplace_back(T(pos.back()+1));\n    dat.assign(2*n,Line(0,-INF));\n\
    \  }\n\n  void addLine(T a,T b){\n    if(isMin) a=-a,b=-b;\n    Line x(a,b);\n\
    \    update(1,0,n-1,x);\n  }\n\n  T query(T x){\n    int t=lower_bound(pos.begin(),pos.end(),x)-pos.begin();\n\
    \    if(isMin) return -query(1,0,n-1,t);\n    return query(1,0,n-1,t);\n  }\n\n\
    \  inline bool over(Line &a,Line &b,T lb,T ub){\n    return a.get(lb)>=b.get(lb)&&a.get(ub)>=b.get(ub);\n\
    \  }\n\n  void update(int k,int l,int r,Line &x){\n    T lb=pos[l],ub=pos[r];\n\
    \    if(over(dat[k],x,lb,ub)) return;\n    if(over(x,dat[k],lb,ub)){\n      dat[k]=x;\n\
    \      return;\n    }\n    int c=(l+r)>>1;\n    if(dat[k].get(pos[c])<x.get(pos[c]))\
    \ swap(dat[k],x);\n    if(dat[k].get(lb)<=x.get(lb)) update((k<<1)|0,l,c,x);\n\
    \    else update((k<<1)|1,c+1,r,x);\n  }\n\n  T query(int k,int l,int r,int t){\n\
    \    T res=dat[k].get(pos[t]);\n    if(l==r) return res;\n    int c=(l+r)>>1;\n\
    \    if(t<=c) return max(res,query((k<<1)|0,l,c,t));\n    return max(res,query((k<<1)|1,c+1,r,t));\n\
    \  }\n};\ntemplate <typename T, bool isMin>\nconstexpr T LiChao<T, isMin>::INF;\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n#line 9 \"test/yosupo/line_add_get_min.test.cpp\"\n#undef\
    \ call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  using ll = long long;\n  int n,q;\n  cin>>n>>q;\n  vector<ll> as(n),bs(n);\n\
    \  for(int i=0;i<n;i++) cin>>as[i]>>bs[i];\n\n  vector<ll> ts(q),xs(q),ys(q);\n\
    \  vector<ll> ps;\n  for(int i=0;i<q;i++){\n    cin>>ts[i];\n    if(ts[i]==0)\
    \ cin>>xs[i]>>ys[i];\n    if(ts[i]==1){\n      cin>>xs[i];\n      ps.emplace_back(xs[i]);\n\
    \    }\n  }\n\n  LiChao<ll, true> seg(compress(ps));\n  for(int i=0;i<n;i++) seg.addLine(as[i],bs[i]);\n\
    \  for(int i=0;i<q;i++){\n    if(ts[i]==0) seg.addLine(xs[i],ys[i]);\n    if(ts[i]==1)\
    \ cout<<seg.query(xs[i])<<\"\\n\";\n  }\n  cout<<flush;\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../vector/compress.cpp\"\n#include \"../../segtree/cht/lichao.cpp\"\n#undef\
    \ call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  using ll = long long;\n  int n,q;\n  cin>>n>>q;\n  vector<ll> as(n),bs(n);\n\
    \  for(int i=0;i<n;i++) cin>>as[i]>>bs[i];\n\n  vector<ll> ts(q),xs(q),ys(q);\n\
    \  vector<ll> ps;\n  for(int i=0;i<q;i++){\n    cin>>ts[i];\n    if(ts[i]==0)\
    \ cin>>xs[i]>>ys[i];\n    if(ts[i]==1){\n      cin>>xs[i];\n      ps.emplace_back(xs[i]);\n\
    \    }\n  }\n\n  LiChao<ll, true> seg(compress(ps));\n  for(int i=0;i<n;i++) seg.addLine(as[i],bs[i]);\n\
    \  for(int i=0;i<q;i++){\n    if(ts[i]==0) seg.addLine(xs[i],ys[i]);\n    if(ts[i]==1)\
    \ cout<<seg.query(xs[i])<<\"\\n\";\n  }\n  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - vector/compress.cpp
  - segtree/cht/lichao.cpp
  isVerificationFile: true
  path: test/yosupo/line_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2020-04-18 17:56:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/line_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/line_add_get_min.test.cpp
- /verify/test/yosupo/line_add_get_min.test.cpp.html
title: test/yosupo/line_add_get_min.test.cpp
---
