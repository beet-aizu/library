---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"segtree/cht/lichao.cpp\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate <typename T, bool isMin>\n\
    struct LiChao{\n  static constexpr T INF = numeric_limits<T>::max();\n  struct\
    \ Line{\n    T a,b;\n    Line(T a,T b):a(a),b(b){}\n    T get(T x){return a*x+b;}\n\
    \  };\n\n  int n;\n  vector<T> pos;\n  vector<Line> dat;\n  LiChao(int n){\n \
    \   pos.resize(n);\n    iota(pos.begin(),pos.end(),T(0));\n    init(n);\n  }\n\
    \n  LiChao(const vector<T> &pos):pos(pos){init(pos.size());}\n\n  void init(int\
    \ n_){\n    n=1;\n    while(n<n_) n<<=1;\n    while((int)pos.size()<n)\n     \
    \ pos.emplace_back(T(pos.back()+1));\n    dat.assign(2*n,Line(0,-INF));\n  }\n\
    \n  void addLine(T a,T b){\n    if(isMin) a=-a,b=-b;\n    Line x(a,b);\n    update(1,0,n-1,x);\n\
    \  }\n\n  T query(T x){\n    int t=lower_bound(pos.begin(),pos.end(),x)-pos.begin();\n\
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
    \  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate <typename T, bool isMin>\nstruct LiChao{\n  static\
    \ constexpr T INF = numeric_limits<T>::max();\n  struct Line{\n    T a,b;\n  \
    \  Line(T a,T b):a(a),b(b){}\n    T get(T x){return a*x+b;}\n  };\n\n  int n;\n\
    \  vector<T> pos;\n  vector<Line> dat;\n  LiChao(int n){\n    pos.resize(n);\n\
    \    iota(pos.begin(),pos.end(),T(0));\n    init(n);\n  }\n\n  LiChao(const vector<T>\
    \ &pos):pos(pos){init(pos.size());}\n\n  void init(int n_){\n    n=1;\n    while(n<n_)\
    \ n<<=1;\n    while((int)pos.size()<n)\n      pos.emplace_back(T(pos.back()+1));\n\
    \    dat.assign(2*n,Line(0,-INF));\n  }\n\n  void addLine(T a,T b){\n    if(isMin)\
    \ a=-a,b=-b;\n    Line x(a,b);\n    update(1,0,n-1,x);\n  }\n\n  T query(T x){\n\
    \    int t=lower_bound(pos.begin(),pos.end(),x)-pos.begin();\n    if(isMin) return\
    \ -query(1,0,n-1,t);\n    return query(1,0,n-1,t);\n  }\n\n  inline bool over(Line\
    \ &a,Line &b,T lb,T ub){\n    return a.get(lb)>=b.get(lb)&&a.get(ub)>=b.get(ub);\n\
    \  }\n\n  void update(int k,int l,int r,Line &x){\n    T lb=pos[l],ub=pos[r];\n\
    \    if(over(dat[k],x,lb,ub)) return;\n    if(over(x,dat[k],lb,ub)){\n      dat[k]=x;\n\
    \      return;\n    }\n    int c=(l+r)>>1;\n    if(dat[k].get(pos[c])<x.get(pos[c]))\
    \ swap(dat[k],x);\n    if(dat[k].get(lb)<=x.get(lb)) update((k<<1)|0,l,c,x);\n\
    \    else update((k<<1)|1,c+1,r,x);\n  }\n\n  T query(int k,int l,int r,int t){\n\
    \    T res=dat[k].get(pos[t]);\n    if(l==r) return res;\n    int c=(l+r)>>1;\n\
    \    if(t<=c) return max(res,query((k<<1)|0,l,c,t));\n    return max(res,query((k<<1)|1,c+1,r,t));\n\
    \  }\n};\ntemplate <typename T, bool isMin>\nconstexpr T LiChao<T, isMin>::INF;\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3069.lichao.test.cpp
    title: test/aoj/3069.lichao.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/line_add_get_min.test.cpp
    title: test/yosupo/line_add_get_min.test.cpp
  isVerificationFile: false
  path: segtree/cht/lichao.cpp
  requiredBy: []
  timestamp: '2020-03-05 21:15:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - test/aoj/3069.lichao.test.cpp
  - test/yosupo/line_add_get_min.test.cpp
documentation_of: segtree/cht/lichao.cpp
layout: document
redirect_from:
- /library/segtree/cht/lichao.cpp
- /library/segtree/cht/lichao.cpp.html
title: segtree/cht/lichao.cpp
---
