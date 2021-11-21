---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2725.linecontainer.test.cpp
    title: test MaxLineContainer
  - icon: ':heavy_check_mark:'
    path: test/aoj/3069.test.cpp
    title: test MinLineContainer
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convexhulltrick/linecontainer.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\nenum Objective{\n  MAXIMIZE =\
    \ +1,\n  MINIMIZE = -1,\n};\n\ntemplate<typename T>\nstruct Line {\n  mutable\
    \ T k,m,p;\n  bool operator<(const Line&o)const{return k<o.k;}\n  bool operator<(T\
    \ x)const{return p<x;}\n};\n\ntemplate<typename T> T lc_inf(){return numeric_limits<T>::max();}\n\
    template<> double lc_inf<double>(){return 1/.0;}\n\ntemplate<typename T> T lc_div(T\
    \ a,T b){return a/b-((a^b)<0 and a%b);}\ntemplate<> double lc_div(double a,double\
    \ b){return a/b;};\n\ntemplate<typename T, Objective objective>\nstruct LineContainer\
    \ : multiset<Line<T>, less<>>{\n  using super = multiset<Line<T>, less<>>;\n \
    \ using super::begin,super::end,super::insert,super::erase;\n  using super::empty,super::lower_bound;\n\
    \  const T inf = lc_inf<T>();\n  bool insect(typename super::iterator x,typename\
    \ super::iterator y){\n    if(y==end()) return x->p=inf,false;\n    if(x->k==y->k)\
    \ x->p=(x->m>y->m?inf:-inf);\n    else x->p=lc_div(y->m-x->m,x->k-y->k);\n   \
    \ return x->p>=y->p;\n  }\n  void add(T k,T m){\n    auto z=insert({k*objective,m*objective,0}),y=z++,x=y;\n\
    \    while(insect(y,z)) z=erase(z);\n    if(x!=begin() and insect(--x,y)) insect(x,y=erase(y));\n\
    \    while((y=x)!=begin() and (--x)->p>=y->p) insect(x,erase(y));\n  }\n  T query(T\
    \ x){\n    assert(!empty());\n    auto l=*lower_bound(x);\n    return (l.k*x+l.m)*objective;\n\
    \  }\n};\ntemplate<typename T>\nusing MinLineContainer = LineContainer<T, Objective::MINIMIZE>;\n\
    template<typename T>\nusing MaxLineContainer = LineContainer<T, Objective::MAXIMIZE>;\n\
    //END CUT HERE\n\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nenum Objective{\n  MAXIMIZE = +1,\n  MINIMIZE = -1,\n};\n\n\
    template<typename T>\nstruct Line {\n  mutable T k,m,p;\n  bool operator<(const\
    \ Line&o)const{return k<o.k;}\n  bool operator<(T x)const{return p<x;}\n};\n\n\
    template<typename T> T lc_inf(){return numeric_limits<T>::max();}\ntemplate<>\
    \ double lc_inf<double>(){return 1/.0;}\n\ntemplate<typename T> T lc_div(T a,T\
    \ b){return a/b-((a^b)<0 and a%b);}\ntemplate<> double lc_div(double a,double\
    \ b){return a/b;};\n\ntemplate<typename T, Objective objective>\nstruct LineContainer\
    \ : multiset<Line<T>, less<>>{\n  using super = multiset<Line<T>, less<>>;\n \
    \ using super::begin,super::end,super::insert,super::erase;\n  using super::empty,super::lower_bound;\n\
    \  const T inf = lc_inf<T>();\n  bool insect(typename super::iterator x,typename\
    \ super::iterator y){\n    if(y==end()) return x->p=inf,false;\n    if(x->k==y->k)\
    \ x->p=(x->m>y->m?inf:-inf);\n    else x->p=lc_div(y->m-x->m,x->k-y->k);\n   \
    \ return x->p>=y->p;\n  }\n  void add(T k,T m){\n    auto z=insert({k*objective,m*objective,0}),y=z++,x=y;\n\
    \    while(insect(y,z)) z=erase(z);\n    if(x!=begin() and insect(--x,y)) insect(x,y=erase(y));\n\
    \    while((y=x)!=begin() and (--x)->p>=y->p) insect(x,erase(y));\n  }\n  T query(T\
    \ x){\n    assert(!empty());\n    auto l=*lower_bound(x);\n    return (l.k*x+l.m)*objective;\n\
    \  }\n};\ntemplate<typename T>\nusing MinLineContainer = LineContainer<T, Objective::MINIMIZE>;\n\
    template<typename T>\nusing MaxLineContainer = LineContainer<T, Objective::MAXIMIZE>;\n\
    //END CUT HERE\n\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: convexhulltrick/linecontainer.cpp
  requiredBy: []
  timestamp: '2020-10-03 18:22:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3069.test.cpp
  - test/aoj/2725.linecontainer.test.cpp
documentation_of: convexhulltrick/linecontainer.cpp
layout: document
redirect_from:
- /library/convexhulltrick/linecontainer.cpp
- /library/convexhulltrick/linecontainer.cpp.html
title: convexhulltrick/linecontainer.cpp
---
