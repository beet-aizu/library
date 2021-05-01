---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/5061.test.cpp
    title: test/yukicoder/5061.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8
  bundledCode: "#line 1 \"datastructure/slope.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\n// https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8\n\
    template<typename T>\nstruct Slope{\n  using P = pair<T, T>;\n  priority_queue<P,\
    \ vector<P>, less<P>> L;\n  priority_queue<P, vector<P>, greater<P>> R;\n  T offset,entire;\n\
    \  Slope():offset(0),entire(0){}\n\n  inline T relu(T x){return max<T>(0,x);}\n\
    \n  template<typename PQ>\n  inline void push(PQ &pq,T pos,T num){\n    if(num!=T(0))\
    \ pq.emplace(pos,num);\n  }\n\n  template<typename From,typename To,typename Compare>\n\
    \  void fix(T a,T cnt,From &from,To &to,Compare comp){\n    T use(0);\n    while(use<cnt\
    \ and not from.empty() and comp(a,from.top().first)){\n      auto[pos,num]=from.top();from.pop();\n\
    \      T tmp=min(cnt-use,num);\n      push(to,pos,tmp);\n      push(from,pos,relu(num-tmp));\n\
    \      push(from,a,tmp);\n      entire+=max(a-pos,pos-a)*tmp;\n      use+=tmp;\n\
    \    }\n    push(to,a,cnt-use);\n  }\n\n  void add_x_minus_a(T a,T cnt=T(1)){\n\
    \    a-=offset;\n    fix(a,cnt,L,R,[](T x,T y){return x<y;});\n  }\n\n  void add_a_minus_x(T\
    \ a,T cnt=T(1)){\n    a-=offset;\n    fix(a,cnt,R,L,[](T x,T y){return x>y;});\n\
    \  }\n\n  // f_{new}(x) =  f_{old}(x + diff)\n  void shift(T diff){offset-=diff;}\n\
    \n  // f_{new}(x) = min_{y<=x} f_{old}(y)\n  void apply_cumulative_min(){\n  \
    \  while(!R.empty()) R.pop();\n  }\n\n  T get_val(T x){\n    x-=offset;\n    T\
    \ res=entire;\n    auto vectorize=[](auto pq){\n      vector<P> vp;\n      vp.reserve(pq.size());\n\
    \      while(!pq.empty()) vp.emplace_back(pq.top()),pq.pop();\n      return vp;\n\
    \    };\n    for(auto[pos,num]:vectorize(L)) res+=relu(pos-x)*num;\n    for(auto[pos,num]:vectorize(R))\
    \ res+=relu(x-pos)*num;\n    return res;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\n// https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8\n\
    template<typename T>\nstruct Slope{\n  using P = pair<T, T>;\n  priority_queue<P,\
    \ vector<P>, less<P>> L;\n  priority_queue<P, vector<P>, greater<P>> R;\n  T offset,entire;\n\
    \  Slope():offset(0),entire(0){}\n\n  inline T relu(T x){return max<T>(0,x);}\n\
    \n  template<typename PQ>\n  inline void push(PQ &pq,T pos,T num){\n    if(num!=T(0))\
    \ pq.emplace(pos,num);\n  }\n\n  template<typename From,typename To,typename Compare>\n\
    \  void fix(T a,T cnt,From &from,To &to,Compare comp){\n    T use(0);\n    while(use<cnt\
    \ and not from.empty() and comp(a,from.top().first)){\n      auto[pos,num]=from.top();from.pop();\n\
    \      T tmp=min(cnt-use,num);\n      push(to,pos,tmp);\n      push(from,pos,relu(num-tmp));\n\
    \      push(from,a,tmp);\n      entire+=max(a-pos,pos-a)*tmp;\n      use+=tmp;\n\
    \    }\n    push(to,a,cnt-use);\n  }\n\n  void add_x_minus_a(T a,T cnt=T(1)){\n\
    \    a-=offset;\n    fix(a,cnt,L,R,[](T x,T y){return x<y;});\n  }\n\n  void add_a_minus_x(T\
    \ a,T cnt=T(1)){\n    a-=offset;\n    fix(a,cnt,R,L,[](T x,T y){return x>y;});\n\
    \  }\n\n  // f_{new}(x) =  f_{old}(x + diff)\n  void shift(T diff){offset-=diff;}\n\
    \n  // f_{new}(x) = min_{y<=x} f_{old}(y)\n  void apply_cumulative_min(){\n  \
    \  while(!R.empty()) R.pop();\n  }\n\n  T get_val(T x){\n    x-=offset;\n    T\
    \ res=entire;\n    auto vectorize=[](auto pq){\n      vector<P> vp;\n      vp.reserve(pq.size());\n\
    \      while(!pq.empty()) vp.emplace_back(pq.top()),pq.pop();\n      return vp;\n\
    \    };\n    for(auto[pos,num]:vectorize(L)) res+=relu(pos-x)*num;\n    for(auto[pos,num]:vectorize(R))\
    \ res+=relu(x-pos)*num;\n    return res;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/slope.cpp
  requiredBy: []
  timestamp: '2021-04-04 22:56:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/5061.test.cpp
documentation_of: datastructure/slope.cpp
layout: document
redirect_from:
- /library/datastructure/slope.cpp
- /library/datastructure/slope.cpp.html
title: datastructure/slope.cpp
---
