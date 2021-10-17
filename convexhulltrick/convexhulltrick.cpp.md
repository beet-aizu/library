---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2725.test.cpp
    title: test/aoj/2725.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2975.test.cpp
    title: test/aoj/2975.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/arc128/tasks/arc128_c
  bundledCode: "#line 1 \"convexhulltrick/convexhulltrick.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\nenum Objective{\n  MINIMIZE =\
    \ +1,\n  MAXIMIZE = -1,\n};\n\ntemplate<typename T> struct Line {\n  T k,m;\n\
    \  T operator()(const T x)const{return k*x+m;}\n};\n\ntemplate <typename T, Objective\
    \ objective>\nstruct ConvexHullTrick : deque<Line<T>>{\n  inline int sgn(T x){return\
    \ x==0?0:(x<0?-1:1);}\n\n  using D = long double;\n  inline bool check(const Line<T>\
    \ &a,const Line<T> &b,const Line<T> &c){\n    if(b.m==a.m or c.m==b.m)\n     \
    \ return sgn(b.k-a.k)*sgn(c.m-b.m) >= sgn(c.k-b.k)*sgn(b.m-a.m);\n    // return\
    \ (b.k-a.k)*(c.m-b.m) >= (b.m-a.m)*(c.k-b.k);\n    return\n      D(b.k-a.k)*sgn(c.m-b.m)/D(abs(b.m-a.m))\
    \ >=\n      D(c.k-b.k)*sgn(b.m-a.m)/D(abs(c.m-b.m));\n  }\n\n  using super = deque<Line<T>>;\n\
    \  using super::empty,super::size,super::front,super::back;\n  using super::emplace_front,super::emplace_back;\n\
    \  using super::pop_front,super::pop_back;\n  const Line<T> at(int i) const{return\
    \ (*this)[i];}\n\n  void add(T k_,T m_){\n    Line<T> l({k_*objective,m_*objective});\n\
    \    if(empty()){\n      emplace_front(l);\n      return;\n    }\n    if(front().k<=l.k){\n\
    \      if(front().k==l.k){\n        if(front().m<=l.m) return;\n        pop_front();\n\
    \      }\n      while(size()>=2 and check(l,at(0),at(1))) pop_front();\n     \
    \ emplace_front(l);\n    }else{\n      assert(l.k<=back().k);\n      if(back().k==l.k){\n\
    \        if(back().m<=l.m) return;\n        pop_back();\n      }\n      while(size()>=2\
    \ and check(at(size()-2),at(size()-1),l)) pop_back();\n      emplace_back(l);\n\
    \    }\n  }\n\n  T query(T x){\n    assert(!empty());\n    int l=-1,r=size()-1;\n\
    \    while(l+1<r){\n      int m=(l+r)>>1;\n      if(at(m)(x)>=at(m+1)(x)) l=m;\n\
    \      else r=m;\n    }\n    return at(r)(x)*objective;\n  }\n\n  T queryMonotoneInc(T\
    \ x){\n    assert(!empty());\n    while(size()>=2 and at(0)(x)>=at(1)(x)) pop_front();\n\
    \    return front()(x)*objective;\n  }\n\n  T queryMonotoneDec(T x){\n    assert(!empty());\n\
    \    while(size()>=2 and at(size()-1)(x)>=at(size()-2)(x)) pop_back();\n    return\
    \ back()(x)*objective;\n  }\n\n  vector<pair<T, T>> getVertices(){\n    vector<pair<T,\
    \ T>> res;\n    for(int i=0;i+1<(int)size();i++){\n      auto l0=at(i+0),l1=at(i+1);\n\
    \      assert(l0.k!=l1.k);\n      T x=(l1.m-l0.m)/(l0.k-l1.k);\n      res.emplace_back(x,at(i)(x)*objective);\n\
    \    }\n    return res;\n  }\n};\ntemplate<typename T>\nusing MinConvexHullTrick\
    \ = ConvexHullTrick<T, Objective::MINIMIZE>;\ntemplate<typename T>\nusing MaxConvexHullTrick\
    \ = ConvexHullTrick<T, Objective::MAXIMIZE>;\n\n// minimize_{y0, y1 >=0} p0 y0\
    \ + p1 y1\n// such that as[i] * y0 + bs[i] * y1 >= cs[i]\n// assume all inputs\
    \ are non-negative, as[i] > 0\n// O(n \\log n) (n = as.size())\ntemplate<typename\
    \ T>\nT solve_lp(T p0,T p1,vector<T> as,vector<T> bs,vector<T> cs){\n  auto calc=[&](T\
    \ y0,T y1){return max<T>(y0,0)*p0+max<T>(y1,0)*p1;};\n  MaxConvexHullTrick<T>\
    \ cht;\n  T yy=cs[0]/as[0];\n  for(int i=0;i<(int)as.size();i++){\n    yy=max(yy,cs[i]/as[i]);\n\
    \    cht.add(-bs[i]/as[i],cs[i]/as[i]);\n  }\n  T res=calc(yy,0);\n  for(auto[y1,y0]:cht.getVertices())\
    \ res=min(res,calc(y0,y1));\n  return res;\n}\n\n//END CUT HERE\n#ifndef call_from_test\n\
    \nsigned ARC128_C(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,m,s;\n\
    \  cin>>n>>m>>s;\n\n  using D = double;\n  vector<D> as(n);\n  for(int i=0;i<n;i++)\
    \ cin>>as[i];\n\n  vector<D> bs(n+1,0),cs(n+1,0);\n  for(int i=0;i<=n;i++) bs[i]=n-i;\n\
    \  for(int i=n;i>0;i--) cs[i-1]=as[i-1]+cs[i];\n\n  D ans=solve_lp<D>(m,s,vector<D>(n+1,1),bs,cs);\n\
    \  cout<<fixed<<setprecision(12)<<ans<<endl;\n  return 0;\n}\n/*\n  verified on\
    \ 2021/10/17\n  https://atcoder.jp/contests/arc128/tasks/arc128_c\n*/\n\nsigned\
    \ main(){\n  ARC128_C();\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nenum Objective{\n  MINIMIZE = +1,\n  MAXIMIZE = -1,\n};\n\n\
    template<typename T> struct Line {\n  T k,m;\n  T operator()(const T x)const{return\
    \ k*x+m;}\n};\n\ntemplate <typename T, Objective objective>\nstruct ConvexHullTrick\
    \ : deque<Line<T>>{\n  inline int sgn(T x){return x==0?0:(x<0?-1:1);}\n\n  using\
    \ D = long double;\n  inline bool check(const Line<T> &a,const Line<T> &b,const\
    \ Line<T> &c){\n    if(b.m==a.m or c.m==b.m)\n      return sgn(b.k-a.k)*sgn(c.m-b.m)\
    \ >= sgn(c.k-b.k)*sgn(b.m-a.m);\n    // return (b.k-a.k)*(c.m-b.m) >= (b.m-a.m)*(c.k-b.k);\n\
    \    return\n      D(b.k-a.k)*sgn(c.m-b.m)/D(abs(b.m-a.m)) >=\n      D(c.k-b.k)*sgn(b.m-a.m)/D(abs(c.m-b.m));\n\
    \  }\n\n  using super = deque<Line<T>>;\n  using super::empty,super::size,super::front,super::back;\n\
    \  using super::emplace_front,super::emplace_back;\n  using super::pop_front,super::pop_back;\n\
    \  const Line<T> at(int i) const{return (*this)[i];}\n\n  void add(T k_,T m_){\n\
    \    Line<T> l({k_*objective,m_*objective});\n    if(empty()){\n      emplace_front(l);\n\
    \      return;\n    }\n    if(front().k<=l.k){\n      if(front().k==l.k){\n  \
    \      if(front().m<=l.m) return;\n        pop_front();\n      }\n      while(size()>=2\
    \ and check(l,at(0),at(1))) pop_front();\n      emplace_front(l);\n    }else{\n\
    \      assert(l.k<=back().k);\n      if(back().k==l.k){\n        if(back().m<=l.m)\
    \ return;\n        pop_back();\n      }\n      while(size()>=2 and check(at(size()-2),at(size()-1),l))\
    \ pop_back();\n      emplace_back(l);\n    }\n  }\n\n  T query(T x){\n    assert(!empty());\n\
    \    int l=-1,r=size()-1;\n    while(l+1<r){\n      int m=(l+r)>>1;\n      if(at(m)(x)>=at(m+1)(x))\
    \ l=m;\n      else r=m;\n    }\n    return at(r)(x)*objective;\n  }\n\n  T queryMonotoneInc(T\
    \ x){\n    assert(!empty());\n    while(size()>=2 and at(0)(x)>=at(1)(x)) pop_front();\n\
    \    return front()(x)*objective;\n  }\n\n  T queryMonotoneDec(T x){\n    assert(!empty());\n\
    \    while(size()>=2 and at(size()-1)(x)>=at(size()-2)(x)) pop_back();\n    return\
    \ back()(x)*objective;\n  }\n\n  vector<pair<T, T>> getVertices(){\n    vector<pair<T,\
    \ T>> res;\n    for(int i=0;i+1<(int)size();i++){\n      auto l0=at(i+0),l1=at(i+1);\n\
    \      assert(l0.k!=l1.k);\n      T x=(l1.m-l0.m)/(l0.k-l1.k);\n      res.emplace_back(x,at(i)(x)*objective);\n\
    \    }\n    return res;\n  }\n};\ntemplate<typename T>\nusing MinConvexHullTrick\
    \ = ConvexHullTrick<T, Objective::MINIMIZE>;\ntemplate<typename T>\nusing MaxConvexHullTrick\
    \ = ConvexHullTrick<T, Objective::MAXIMIZE>;\n\n// minimize_{y0, y1 >=0} p0 y0\
    \ + p1 y1\n// such that as[i] * y0 + bs[i] * y1 >= cs[i]\n// assume all inputs\
    \ are non-negative, as[i] > 0\n// O(n \\log n) (n = as.size())\ntemplate<typename\
    \ T>\nT solve_lp(T p0,T p1,vector<T> as,vector<T> bs,vector<T> cs){\n  auto calc=[&](T\
    \ y0,T y1){return max<T>(y0,0)*p0+max<T>(y1,0)*p1;};\n  MaxConvexHullTrick<T>\
    \ cht;\n  T yy=cs[0]/as[0];\n  for(int i=0;i<(int)as.size();i++){\n    yy=max(yy,cs[i]/as[i]);\n\
    \    cht.add(-bs[i]/as[i],cs[i]/as[i]);\n  }\n  T res=calc(yy,0);\n  for(auto[y1,y0]:cht.getVertices())\
    \ res=min(res,calc(y0,y1));\n  return res;\n}\n\n//END CUT HERE\n#ifndef call_from_test\n\
    \nsigned ARC128_C(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,m,s;\n\
    \  cin>>n>>m>>s;\n\n  using D = double;\n  vector<D> as(n);\n  for(int i=0;i<n;i++)\
    \ cin>>as[i];\n\n  vector<D> bs(n+1,0),cs(n+1,0);\n  for(int i=0;i<=n;i++) bs[i]=n-i;\n\
    \  for(int i=n;i>0;i--) cs[i-1]=as[i-1]+cs[i];\n\n  D ans=solve_lp<D>(m,s,vector<D>(n+1,1),bs,cs);\n\
    \  cout<<fixed<<setprecision(12)<<ans<<endl;\n  return 0;\n}\n/*\n  verified on\
    \ 2021/10/17\n  https://atcoder.jp/contests/arc128/tasks/arc128_c\n*/\n\nsigned\
    \ main(){\n  ARC128_C();\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: convexhulltrick/convexhulltrick.cpp
  requiredBy: []
  timestamp: '2021-10-17 15:41:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2725.test.cpp
  - test/aoj/2975.test.cpp
documentation_of: convexhulltrick/convexhulltrick.cpp
layout: document
redirect_from:
- /library/convexhulltrick/convexhulltrick.cpp
- /library/convexhulltrick/convexhulltrick.cpp.html
title: convexhulltrick/convexhulltrick.cpp
---
