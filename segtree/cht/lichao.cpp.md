---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/line_add_get_min.test.cpp
    title: test/yosupo/line_add_get_min.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segtree/cht/lichao.cpp\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate <typename T, bool isMin>\n\
    struct LiChao{\n  const T INF = numeric_limits<T>::max();\n  struct Line{\n  \
    \  T a,b;\n    Line(T a,T b):a(isMin?a:-a),b(isMin?b:-b){}\n    T operator()(T\
    \ x) const{return a*x+b;}\n  };\n\n  int n;\n  vector<T> xs;\n  vector<Line> dat;\n\
    \  LiChao(const vector<T> &xs_):xs(xs_){\n    sort(xs.begin(),xs.end());\n   \
    \ xs.erase(unique(xs.begin(),xs.end()),xs.end());\n    n=xs.size();\n    dat.assign(n<<1,Line(T(0),INF));\n\
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
    signed main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate <typename T, bool isMin>\nstruct LiChao{\n  const T\
    \ INF = numeric_limits<T>::max();\n  struct Line{\n    T a,b;\n    Line(T a,T\
    \ b):a(isMin?a:-a),b(isMin?b:-b){}\n    T operator()(T x) const{return a*x+b;}\n\
    \  };\n\n  int n;\n  vector<T> xs;\n  vector<Line> dat;\n  LiChao(const vector<T>\
    \ &xs_):xs(xs_){\n    sort(xs.begin(),xs.end());\n    xs.erase(unique(xs.begin(),xs.end()),xs.end());\n\
    \    n=xs.size();\n    dat.assign(n<<1,Line(T(0),INF));\n  }\n\n  int index(T\
    \ x) const{\n    return lower_bound(xs.begin(),xs.end(),x)-xs.begin();\n  }\n\n\
    \  T get(T x){\n    T res=INF;\n    for(int i=index(x)+n;i;i>>=1) res=min(res,dat[i](x));\n\
    \    return isMin?res:-res;\n  }\n\n  // [xl, xr)\n  void add_segment(T a,T b,T\
    \ xl,T xr){\n    Line g(a,b);\n    for(int l=index(xl)+n,r=index(xr)+n;l<r;l>>=1,r>>=1){\n\
    \      if(l&1) update(g,l++);\n      if(r&1) update(g,--r);\n    }\n  }\n\n  void\
    \ update(Line g,int i){\n    int l=i,r=i+1;\n    while(l<n) l<<=1,r<<=1;\n   \
    \ while(l<r){\n      int m=(l+r)>>1;\n      T xl=xs[l-n],xr=xs[r-1-n],xm=xs[m-n];\n\
    \      Line &f=dat[i];\n      if(f(xl)<=g(xl) and f(xr)<=g(xr)) return;\n    \
    \  if(f(xl)>=g(xl) and f(xr)>=g(xr)) return (void)(f=g);\n      if(f(xm)>g(xm))\
    \ swap(f,g);\n      if(f(xl)>g(xl)) i=(i<<1)|0,r=m;\n      else i=(i<<1)|1,l=m;\n\
    \    }\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: segtree/cht/lichao.cpp
  requiredBy: []
  timestamp: '2020-10-02 21:19:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/line_add_get_min.test.cpp
documentation_of: segtree/cht/lichao.cpp
layout: document
redirect_from:
- /library/segtree/cht/lichao.cpp
- /library/segtree/cht/lichao.cpp.html
title: segtree/cht/lichao.cpp
---
