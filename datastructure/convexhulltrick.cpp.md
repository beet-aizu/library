---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2975.test.cpp
    title: test/aoj/2975.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2725.test.cpp
    title: test/aoj/2725.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"datastructure/convexhulltrick.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate <typename T, bool isMin>\n\
    struct ConvexHullTrick {\n  #define F first\n  #define S second\n  using P = pair<T,\
    \ T>;\n  deque<P> H;\n  bool empty()const{return H.empty();}\n  void clear(){H.clear();}\n\
    \n  inline int sgn(T x){return x==0?0:(x<0?-1:1);}\n\n  using D = long double;\n\
    \  inline bool check(const P &a,const P &b,const P &c){\n    if(b.S==a.S||c.S==b.S)\n\
    \      return sgn(b.F-a.F)*sgn(c.S-b.S) >= sgn(c.F-b.F)*sgn(b.S-a.S);\n\n    //return\
    \ (b.F-a.F)*(c.S-b.S) >= (b.S-a.S)*(c.F-b.F);\n    return\n      D(b.F-a.F)*sgn(c.S-b.S)/D(abs(b.S-a.S))\
    \ >=\n      D(c.F-b.F)*sgn(b.S-a.S)/D(abs(c.S-b.S));\n  }\n\n  void addLine(T\
    \ m,T b){\n    if(!isMin) m*=-1,b*=-1;\n    P line(m,b);\n    if(empty()){\n \
    \     H.emplace_front(line);\n      return;\n    }\n    if(H.front().F<=m){\n\
    \      if(H.front().F==m){\n        if(H.front().S<=b) return;\n        H.pop_front();\n\
    \      }\n      while(H.size()>=2&&\n            check(line,H.front(),H[1])) H.pop_front();\n\
    \      H.emplace_front(line);\n    }else{\n      assert(m<=H.back().F);\n    \
    \  if(H.back().F==m){\n        if(H.back().S<=b) return;\n        H.pop_back();\n\
    \      }\n      while(H.size()>=2&&\n            check(H[H.size()-2],H.back(),line))\
    \ H.pop_back();\n      H.emplace_back(line);\n    }\n  }\n\n  inline T getY(const\
    \ P &a,const T &x){\n    return a.F*x+a.S;\n  }\n\n  T query(T x){\n    assert(!empty());\n\
    \    int l=-1,r=H.size()-1;\n    while(l+1<r){\n      int m=(l+r)>>1;\n      if(getY(H[m],x)>=getY(H[m+1],x))\
    \ l=m;\n      else r=m;\n    }\n    if(isMin) return getY(H[r],x);\n    return\
    \ -getY(H[r],x);\n  }\n\n  T queryMonotoneInc(T x){\n    assert(!empty());\n \
    \   while(H.size()>=2&&\n          getY(H.front(),x)>=getY(H[1],x)) H.pop_front();\n\
    \    if(isMin) return getY(H.front(),x);\n    return -getY(H.front(),x);\n  }\n\
    \n  T queryMonotoneDec(T x){\n    assert(!empty());\n    while(H.size()>=2&&\n\
    \          getY(H.back(),x)>=getY(H[H.size()-2],x)) H.pop_back();\n    if(isMin)\
    \ return getY(H.back(),x);\n    return -getY(H.back(),x);\n  }\n  #undef F\n \
    \ #undef S\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate <typename T, bool isMin>\nstruct ConvexHullTrick {\n\
    \  #define F first\n  #define S second\n  using P = pair<T, T>;\n  deque<P> H;\n\
    \  bool empty()const{return H.empty();}\n  void clear(){H.clear();}\n\n  inline\
    \ int sgn(T x){return x==0?0:(x<0?-1:1);}\n\n  using D = long double;\n  inline\
    \ bool check(const P &a,const P &b,const P &c){\n    if(b.S==a.S||c.S==b.S)\n\
    \      return sgn(b.F-a.F)*sgn(c.S-b.S) >= sgn(c.F-b.F)*sgn(b.S-a.S);\n\n    //return\
    \ (b.F-a.F)*(c.S-b.S) >= (b.S-a.S)*(c.F-b.F);\n    return\n      D(b.F-a.F)*sgn(c.S-b.S)/D(abs(b.S-a.S))\
    \ >=\n      D(c.F-b.F)*sgn(b.S-a.S)/D(abs(c.S-b.S));\n  }\n\n  void addLine(T\
    \ m,T b){\n    if(!isMin) m*=-1,b*=-1;\n    P line(m,b);\n    if(empty()){\n \
    \     H.emplace_front(line);\n      return;\n    }\n    if(H.front().F<=m){\n\
    \      if(H.front().F==m){\n        if(H.front().S<=b) return;\n        H.pop_front();\n\
    \      }\n      while(H.size()>=2&&\n            check(line,H.front(),H[1])) H.pop_front();\n\
    \      H.emplace_front(line);\n    }else{\n      assert(m<=H.back().F);\n    \
    \  if(H.back().F==m){\n        if(H.back().S<=b) return;\n        H.pop_back();\n\
    \      }\n      while(H.size()>=2&&\n            check(H[H.size()-2],H.back(),line))\
    \ H.pop_back();\n      H.emplace_back(line);\n    }\n  }\n\n  inline T getY(const\
    \ P &a,const T &x){\n    return a.F*x+a.S;\n  }\n\n  T query(T x){\n    assert(!empty());\n\
    \    int l=-1,r=H.size()-1;\n    while(l+1<r){\n      int m=(l+r)>>1;\n      if(getY(H[m],x)>=getY(H[m+1],x))\
    \ l=m;\n      else r=m;\n    }\n    if(isMin) return getY(H[r],x);\n    return\
    \ -getY(H[r],x);\n  }\n\n  T queryMonotoneInc(T x){\n    assert(!empty());\n \
    \   while(H.size()>=2&&\n          getY(H.front(),x)>=getY(H[1],x)) H.pop_front();\n\
    \    if(isMin) return getY(H.front(),x);\n    return -getY(H.front(),x);\n  }\n\
    \n  T queryMonotoneDec(T x){\n    assert(!empty());\n    while(H.size()>=2&&\n\
    \          getY(H.back(),x)>=getY(H[H.size()-2],x)) H.pop_back();\n    if(isMin)\
    \ return getY(H.back(),x);\n    return -getY(H.back(),x);\n  }\n  #undef F\n \
    \ #undef S\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/convexhulltrick.cpp
  requiredBy: []
  timestamp: '2019-12-27 08:27:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2975.test.cpp
  - test/aoj/2725.test.cpp
documentation_of: datastructure/convexhulltrick.cpp
layout: document
redirect_from:
- /library/datastructure/convexhulltrick.cpp
- /library/datastructure/convexhulltrick.cpp.html
title: datastructure/convexhulltrick.cpp
---
