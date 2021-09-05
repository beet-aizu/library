---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/5061.test.cpp
    title: test/yukicoder/5061.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8
  bundledCode: "#line 1 \"datastructure/slope.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\n// https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8\n\
    template<typename T>\nstruct Slope{\n\n  template<template<typename> typename\
    \ Comp_>\n  struct PQ{\n    template<typename X> using Comp = Comp_<X>;\n    inline\
    \ static constexpr Comp<T> comp{};\n    using P = pair<T, T>;\n    priority_queue<P,\
    \ vector<P>, Comp<P>> pq;\n    bool empty()const{return pq.empty();}\n\n    T\
    \ offset;\n    PQ():offset(0){}\n    bool compare(T a){return comp(a,pq.top().first+offset);}\n\
    \n    // f_{new}(x) =  f_{old}(x - diff)\n    void shift(T diff){offset+=diff;}\n\
    \n    void push(T pos,T num){\n      if(num!=T(0)) pq.emplace(pos-offset,num);\n\
    \    }\n\n    P pop(){\n      auto[pos,num]=pq.top();pq.pop();\n      return P(pos+offset,num);\n\
    \    }\n  };\n\n  PQ<less> L;\n  PQ<greater> R;\n  T entire;\n  Slope():entire(0){}\n\
    \n  inline T relu(T x){return max<T>(0,x);}\n\n  template<typename From,typename\
    \ To>\n  void fix(T a,T cnt,From &from,To &to){\n    T use(0);\n    while(use<cnt\
    \ and not from.empty() and from.compare(a)){\n      auto[pos,num]=from.pop();\n\
    \      T tmp=min(cnt-use,num);\n      to.push(pos,tmp);\n      from.push(pos,relu(num-tmp));\n\
    \      from.push(a,tmp);\n      entire+=max(a-pos,pos-a)*tmp;\n      use+=tmp;\n\
    \    }\n    to.push(a,cnt-use);\n  }\n\n  // _/\n  void add_x_minus_a(T a,T cnt=T(1)){\n\
    \    fix(a,cnt,L,R);\n  }\n\n  // \\_\n  void add_a_minus_x(T a,T cnt=T(1)){\n\
    \    fix(a,cnt,R,L);\n  }\n\n  // f_{new}(x) =  \\min_{x-b<=y<=x-a} f_{old}(y)\n\
    \  void shift(T a,T b){\n    assert(a<=b);\n    L.shift(a);\n    R.shift(b);\n\
    \  }\n\n  // f_{new}(x) = f_{old}(x - a)\n  void shift(T a){shift(a,a);}\n\n \
    \ // f_{new}(x) = min_{y<=x} f_{old}(y)\n  void apply_cumulative_min(){\n    while(!R.empty())\
    \ R.pop();\n  }\n\n  T get_min(){return entire;}\n\n  T get_val(T x){\n    T res=entire;\n\
    \    auto vectorize=[](auto pq){\n      vector<pair<T, T>> vp;\n      vp.reserve(pq.pq.size());\n\
    \      while(!pq.empty()) vp.emplace_back(pq.pop());\n      return vp;\n    };\n\
    \    for(auto[pos,num]:vectorize(L)) res+=relu(pos-x)*num;\n    for(auto[pos,num]:vectorize(R))\
    \ res+=relu(x-pos)*num;\n    return res;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\n\n// test shift(a, b)\nsigned ABC217_H(){\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n\n  using ll = long long;\n  Slope<ll> S;\n  S.add_a_minus_x(0,1e9);\n\
    \  S.add_x_minus_a(0,1e9);\n\n  ll n;\n  cin>>n;\n  ll l=0;\n  for(ll i=0;i<n;i++){\n\
    \    ll t,d,x;\n    cin>>t>>d>>x;\n    S.shift(l-t,t-l);\n    l=t;\n    if(d==0)\
    \ S.add_a_minus_x(x);\n    if(d==1) S.add_x_minus_a(x);\n  }\n\n  cout<<S.get_min()<<endl;\n\
    \  return 0;\n}\n\nsigned main(){\n  ABC217_H();\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\n// https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8\n\
    template<typename T>\nstruct Slope{\n\n  template<template<typename> typename\
    \ Comp_>\n  struct PQ{\n    template<typename X> using Comp = Comp_<X>;\n    inline\
    \ static constexpr Comp<T> comp{};\n    using P = pair<T, T>;\n    priority_queue<P,\
    \ vector<P>, Comp<P>> pq;\n    bool empty()const{return pq.empty();}\n\n    T\
    \ offset;\n    PQ():offset(0){}\n    bool compare(T a){return comp(a,pq.top().first+offset);}\n\
    \n    // f_{new}(x) =  f_{old}(x - diff)\n    void shift(T diff){offset+=diff;}\n\
    \n    void push(T pos,T num){\n      if(num!=T(0)) pq.emplace(pos-offset,num);\n\
    \    }\n\n    P pop(){\n      auto[pos,num]=pq.top();pq.pop();\n      return P(pos+offset,num);\n\
    \    }\n  };\n\n  PQ<less> L;\n  PQ<greater> R;\n  T entire;\n  Slope():entire(0){}\n\
    \n  inline T relu(T x){return max<T>(0,x);}\n\n  template<typename From,typename\
    \ To>\n  void fix(T a,T cnt,From &from,To &to){\n    T use(0);\n    while(use<cnt\
    \ and not from.empty() and from.compare(a)){\n      auto[pos,num]=from.pop();\n\
    \      T tmp=min(cnt-use,num);\n      to.push(pos,tmp);\n      from.push(pos,relu(num-tmp));\n\
    \      from.push(a,tmp);\n      entire+=max(a-pos,pos-a)*tmp;\n      use+=tmp;\n\
    \    }\n    to.push(a,cnt-use);\n  }\n\n  // _/\n  void add_x_minus_a(T a,T cnt=T(1)){\n\
    \    fix(a,cnt,L,R);\n  }\n\n  // \\_\n  void add_a_minus_x(T a,T cnt=T(1)){\n\
    \    fix(a,cnt,R,L);\n  }\n\n  // f_{new}(x) =  \\min_{x-b<=y<=x-a} f_{old}(y)\n\
    \  void shift(T a,T b){\n    assert(a<=b);\n    L.shift(a);\n    R.shift(b);\n\
    \  }\n\n  // f_{new}(x) = f_{old}(x - a)\n  void shift(T a){shift(a,a);}\n\n \
    \ // f_{new}(x) = min_{y<=x} f_{old}(y)\n  void apply_cumulative_min(){\n    while(!R.empty())\
    \ R.pop();\n  }\n\n  T get_min(){return entire;}\n\n  T get_val(T x){\n    T res=entire;\n\
    \    auto vectorize=[](auto pq){\n      vector<pair<T, T>> vp;\n      vp.reserve(pq.pq.size());\n\
    \      while(!pq.empty()) vp.emplace_back(pq.pop());\n      return vp;\n    };\n\
    \    for(auto[pos,num]:vectorize(L)) res+=relu(pos-x)*num;\n    for(auto[pos,num]:vectorize(R))\
    \ res+=relu(x-pos)*num;\n    return res;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\n\n// test shift(a, b)\nsigned ABC217_H(){\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n\n  using ll = long long;\n  Slope<ll> S;\n  S.add_a_minus_x(0,1e9);\n\
    \  S.add_x_minus_a(0,1e9);\n\n  ll n;\n  cin>>n;\n  ll l=0;\n  for(ll i=0;i<n;i++){\n\
    \    ll t,d,x;\n    cin>>t>>d>>x;\n    S.shift(l-t,t-l);\n    l=t;\n    if(d==0)\
    \ S.add_a_minus_x(x);\n    if(d==1) S.add_x_minus_a(x);\n  }\n\n  cout<<S.get_min()<<endl;\n\
    \  return 0;\n}\n\nsigned main(){\n  ABC217_H();\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/slope.cpp
  requiredBy: []
  timestamp: '2021-09-05 12:24:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/5061.test.cpp
documentation_of: datastructure/slope.cpp
layout: document
redirect_from:
- /library/datastructure/slope.cpp
- /library/datastructure/slope.cpp.html
title: datastructure/slope.cpp
---
