---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/6680.test.cpp
    title: test/yukicoder/6680.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/grid.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename F>\nstruct Grid{\n  const\
    \ int h,w;\n  const F f;\n  Grid(int h_,int w_,F f_):h(h_),w(w_),f(f_){}\n  int\
    \ idx(int y,int x){return y*w+x;}\n  using T = typename invoke_result<F, int,\
    \ int>::type;\n  T operator[](int k){return f(k/w,k%w);}\n  decltype(auto) edges(){\n\
    \    vector<pair<int, int>> es;\n    for(int i=0;i<h;i++){\n      for(int j=0;j<w;j++){\n\
    \        if(i+1<h) es.emplace_back(idx(i,j),idx(i+1,j));\n        if(j+1<w) es.emplace_back(idx(i,j),idx(i,j+1));\n\
    \      }\n    }\n    return es;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename F>\nstruct Grid{\n  const int h,w;\n\
    \  const F f;\n  Grid(int h_,int w_,F f_):h(h_),w(w_),f(f_){}\n  int idx(int y,int\
    \ x){return y*w+x;}\n  using T = typename invoke_result<F, int, int>::type;\n\
    \  T operator[](int k){return f(k/w,k%w);}\n  decltype(auto) edges(){\n    vector<pair<int,\
    \ int>> es;\n    for(int i=0;i<h;i++){\n      for(int j=0;j<w;j++){\n        if(i+1<h)\
    \ es.emplace_back(idx(i,j),idx(i+1,j));\n        if(j+1<w) es.emplace_back(idx(i,j),idx(i,j+1));\n\
    \      }\n    }\n    return es;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/grid.cpp
  requiredBy: []
  timestamp: '2021-08-06 23:06:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/6680.test.cpp
documentation_of: graph/grid.cpp
layout: document
redirect_from:
- /library/graph/grid.cpp
- /library/graph/grid.cpp.html
title: graph/grid.cpp
---
