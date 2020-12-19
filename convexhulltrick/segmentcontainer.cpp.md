---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/line_add_get_min.test.cpp
    title: test/yosupo/line_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/segment_add_get_min.test.cpp
    title: test/yosupo/segment_add_get_min.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convexhulltrick/segmentcontainer.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\nenum Objective{\n  MINIMIZE =\
    \ +1,\n  MAXIMIZE = -1,\n};\n\ntemplate <typename T,Objective objective>\nstruct\
    \ SegmentContainer{\n  const T INF = numeric_limits<T>::max() / 2;\n  struct Segment{\n\
    \    T a,b;\n    T operator()(T x) const{return a*x+b;}\n  };\n\n  int n;\n  vector<T>\
    \ xs;\n  vector<Segment> dat;\n  SegmentContainer(const vector<T> &xs_):xs(xs_){\n\
    \    sort(xs.begin(),xs.end());\n    xs.erase(unique(xs.begin(),xs.end()),xs.end());\n\
    \    n=xs.size();\n    dat.assign(n<<1,Segment({T(0),INF}));\n  }\n\n  inline\
    \ int index(T x) const{\n    return lower_bound(xs.begin(),xs.end(),x)-xs.begin();\n\
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
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\nenum Objective{\n  MINIMIZE = +1,\n  MAXIMIZE = -1,\n\
    };\n\ntemplate <typename T,Objective objective>\nstruct SegmentContainer{\n  const\
    \ T INF = numeric_limits<T>::max() / 2;\n  struct Segment{\n    T a,b;\n    T\
    \ operator()(T x) const{return a*x+b;}\n  };\n\n  int n;\n  vector<T> xs;\n  vector<Segment>\
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
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: convexhulltrick/segmentcontainer.cpp
  requiredBy: []
  timestamp: '2020-11-22 19:37:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/segment_add_get_min.test.cpp
  - test/yosupo/line_add_get_min.test.cpp
documentation_of: convexhulltrick/segmentcontainer.cpp
layout: document
redirect_from:
- /library/convexhulltrick/segmentcontainer.cpp
- /library/convexhulltrick/segmentcontainer.cpp.html
title: convexhulltrick/segmentcontainer.cpp
---
