---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3086.test.cpp
    title: test/aoj/3086.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_3_D.sparsetable.test.cpp
    title: test/aoj/DSL_3_D.sparsetable.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/staticrmq.sparsetable.test.cpp
    title: test/yosupo/staticrmq.sparsetable.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructure/sparsetable.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct SparseTable{\n\
    \  using F = function<T(T, T)>;\n  vector< vector<T> > dat;\n  vector<int> ht;\n\
    \  const F f;\n\n  SparseTable(F f):f(f){}\n\n  void build(const vector<T> &v){\n\
    \    int n=v.size(),h=1;\n    while((1<<h)<=n) h++;\n    dat.assign(h,vector<T>(n));\n\
    \    ht.assign(n+1,0);\n    for(int j=2;j<=n;j++) ht[j]=ht[j>>1]+1;\n\n    for(int\
    \ j=0;j<n;j++) dat[0][j]=v[j];\n    for(int i=1,p=1;i<h;i++,p<<=1)\n      for(int\
    \ j=0;j<n;j++)\n        dat[i][j]=f(dat[i-1][j],dat[i-1][min(j+p,n-1)]);\n  };\n\
    \n  T query(int a,int b){\n    int l=b-a;\n    return f(dat[ht[l]][a],dat[ht[l]][b-(1<<ht[l])]);\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n\
    }\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct SparseTable{\n  using F\
    \ = function<T(T, T)>;\n  vector< vector<T> > dat;\n  vector<int> ht;\n  const\
    \ F f;\n\n  SparseTable(F f):f(f){}\n\n  void build(const vector<T> &v){\n   \
    \ int n=v.size(),h=1;\n    while((1<<h)<=n) h++;\n    dat.assign(h,vector<T>(n));\n\
    \    ht.assign(n+1,0);\n    for(int j=2;j<=n;j++) ht[j]=ht[j>>1]+1;\n\n    for(int\
    \ j=0;j<n;j++) dat[0][j]=v[j];\n    for(int i=1,p=1;i<h;i++,p<<=1)\n      for(int\
    \ j=0;j<n;j++)\n        dat[i][j]=f(dat[i-1][j],dat[i-1][min(j+p,n-1)]);\n  };\n\
    \n  T query(int a,int b){\n    int l=b-a;\n    return f(dat[ht[l]][a],dat[ht[l]][b-(1<<ht[l])]);\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n\
    }\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/sparsetable.cpp
  requiredBy: []
  timestamp: '2020-10-27 19:32:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3086.test.cpp
  - test/aoj/DSL_3_D.sparsetable.test.cpp
  - test/yosupo/staticrmq.sparsetable.test.cpp
documentation_of: datastructure/sparsetable.cpp
layout: document
redirect_from:
- /library/datastructure/sparsetable.cpp
- /library/datastructure/sparsetable.cpp.html
title: datastructure/sparsetable.cpp
---
