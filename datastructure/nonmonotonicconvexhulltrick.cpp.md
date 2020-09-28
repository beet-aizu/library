---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2725.nonmonotonicconvexhulltrick.test.cpp
    title: test/aoj/2725.nonmonotonicconvexhulltrick.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3069.test.cpp
    title: test/aoj/3069.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructure/nonmonotonicconvexhulltrick.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T, bool isMin,\
    \ typename number = double>\nstruct NonmonotonicConvexHullTrick {\n  static constexpr\
    \ number INF = numeric_limits<T>::max();\n  struct Line {\n    T m,b,val;\n  \
    \  number x;\n    bool q;\n    Line(T m=0,T b=0):m(m),b(b),val(0),x(-INF),q(false){}\n\
    \n    T eval(T x) const{return m*x+b;}\n    bool parallel(const Line &l) const{return\
    \ m==l.m;}\n    number intersect(const Line &l) const{\n      return parallel(l)?number(INF):number(l.b-b)/number(m-l.m);\n\
    \    }\n    bool operator<(const Line &l) const{\n      if(l.q) return x<l.val;\n\
    \      return m<l.m;\n    }\n  };\n\n  set<Line> hull;\n  using iter = typename\
    \ set<Line>::iterator;\n\n  bool cPrev(iter it){return it!=hull.begin();}\n  bool\
    \ cNext(iter it){return it!=hull.end()&&next(it)!=hull.end();}\n\n  bool bad(const\
    \ Line &l1,const Line &l2,const Line &l3){\n    return l1.intersect(l3) <= l1.intersect(l2);\n\
    \  }\n  bool bad(iter it){\n    return cPrev(it)&&cNext(it)&&bad(*prev(it),*it,*next(it));\n\
    \  }\n\n  iter update(iter it){\n    if(!cPrev(it)) return it;\n    number x=it->intersect(*prev(it));\n\
    \    Line tmp(*it);\n    tmp.x=x;\n    it=hull.erase(it);\n    return hull.insert(it,tmp);\n\
    \  }\n\n  void addLine(T m,T b){\n    if(isMin) m=-m,b=-b;\n    Line l(m,b);\n\
    \    iter it=hull.lower_bound(l);\n    if(it!=hull.end()&&l.parallel(*it)){\n\
    \      if(it->b<b) it=hull.erase(it);\n      else return;\n    }\n    it=hull.insert(it,l);\n\
    \    if(bad(it)){\n      hull.erase(it);\n      return;\n    }\n    while(cPrev(it)&&bad(prev(it)))\
    \ hull.erase(prev(it));\n    while(cNext(it)&&bad(next(it))) hull.erase(next(it));\n\
    \n    it=update(it);\n    if(cPrev(it)) update(prev(it));\n    if(cNext(it)) update(next(it));\n\
    \  }\n\n  bool empty() const{\n    return hull.empty();\n  }\n\n  T query(T x){\n\
    \    assert(!empty());\n    Line q;\n    q.val=x;q.q=1;\n    iter it=--hull.lower_bound(q);\n\
    \    if(isMin) return -(it->eval(x));\n    return it->eval(x);\n  }\n} ;\n//END\
    \ CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename T, bool isMin, typename number = double>\n\
    struct NonmonotonicConvexHullTrick {\n  static constexpr number INF = numeric_limits<T>::max();\n\
    \  struct Line {\n    T m,b,val;\n    number x;\n    bool q;\n    Line(T m=0,T\
    \ b=0):m(m),b(b),val(0),x(-INF),q(false){}\n\n    T eval(T x) const{return m*x+b;}\n\
    \    bool parallel(const Line &l) const{return m==l.m;}\n    number intersect(const\
    \ Line &l) const{\n      return parallel(l)?number(INF):number(l.b-b)/number(m-l.m);\n\
    \    }\n    bool operator<(const Line &l) const{\n      if(l.q) return x<l.val;\n\
    \      return m<l.m;\n    }\n  };\n\n  set<Line> hull;\n  using iter = typename\
    \ set<Line>::iterator;\n\n  bool cPrev(iter it){return it!=hull.begin();}\n  bool\
    \ cNext(iter it){return it!=hull.end()&&next(it)!=hull.end();}\n\n  bool bad(const\
    \ Line &l1,const Line &l2,const Line &l3){\n    return l1.intersect(l3) <= l1.intersect(l2);\n\
    \  }\n  bool bad(iter it){\n    return cPrev(it)&&cNext(it)&&bad(*prev(it),*it,*next(it));\n\
    \  }\n\n  iter update(iter it){\n    if(!cPrev(it)) return it;\n    number x=it->intersect(*prev(it));\n\
    \    Line tmp(*it);\n    tmp.x=x;\n    it=hull.erase(it);\n    return hull.insert(it,tmp);\n\
    \  }\n\n  void addLine(T m,T b){\n    if(isMin) m=-m,b=-b;\n    Line l(m,b);\n\
    \    iter it=hull.lower_bound(l);\n    if(it!=hull.end()&&l.parallel(*it)){\n\
    \      if(it->b<b) it=hull.erase(it);\n      else return;\n    }\n    it=hull.insert(it,l);\n\
    \    if(bad(it)){\n      hull.erase(it);\n      return;\n    }\n    while(cPrev(it)&&bad(prev(it)))\
    \ hull.erase(prev(it));\n    while(cNext(it)&&bad(next(it))) hull.erase(next(it));\n\
    \n    it=update(it);\n    if(cPrev(it)) update(prev(it));\n    if(cNext(it)) update(next(it));\n\
    \  }\n\n  bool empty() const{\n    return hull.empty();\n  }\n\n  T query(T x){\n\
    \    assert(!empty());\n    Line q;\n    q.val=x;q.q=1;\n    iter it=--hull.lower_bound(q);\n\
    \    if(isMin) return -(it->eval(x));\n    return it->eval(x);\n  }\n} ;\n//END\
    \ CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/nonmonotonicconvexhulltrick.cpp
  requiredBy: []
  timestamp: '2019-12-27 08:27:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3069.test.cpp
  - test/aoj/2725.nonmonotonicconvexhulltrick.test.cpp
documentation_of: datastructure/nonmonotonicconvexhulltrick.cpp
layout: document
redirect_from:
- /library/datastructure/nonmonotonicconvexhulltrick.cpp
- /library/datastructure/nonmonotonicconvexhulltrick.cpp.html
title: datastructure/nonmonotonicconvexhulltrick.cpp
---
