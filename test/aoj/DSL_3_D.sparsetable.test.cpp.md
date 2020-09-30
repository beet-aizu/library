---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/sparsetable.cpp
    title: datastructure/sparsetable.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
  bundledCode: "#line 1 \"test/aoj/DSL_3_D.sparsetable.test.cpp\"\n// verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#line\
    \ 1 \"datastructure/sparsetable.cpp\"\n\n#line 3 \"datastructure/sparsetable.cpp\"\
    \nusing namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct\
    \ SparseTable{\n  using F = function<T(T, T)>;\n  vector< vector<T> > dat;\n \
    \ vector<int> ht;\n  const F f;\n\n  SparseTable(){}\n  SparseTable(F f):f(f){}\n\
    \n  void build(const vector<T> &v){\n    int n=v.size(),h=1;\n    while((1<<h)<=n)\
    \ h++;\n    dat.assign(h,vector<T>(n));\n    ht.assign(n+1,0);\n    for(int j=2;j<=n;j++)\
    \ ht[j]=ht[j>>1]+1;\n\n    for(int j=0;j<n;j++) dat[0][j]=v[j];\n    for(int i=1,p=1;i<h;i++,p<<=1)\n\
    \      for(int j=0;j<n;j++)\n        dat[i][j]=f(dat[i-1][j],dat[i-1][min(j+p,n-1)]);\n\
    \  };\n\n  T query(int a,int b){\n    int l=b-a;\n    return f(dat[ht[l]][a],dat[ht[l]][b-(1<<ht[l])]);\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n\
    }\n#endif\n#line 8 \"test/aoj/DSL_3_D.sparsetable.test.cpp\"\n#undef call_from_test\n\
    \nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,l;\n  cin>>n>>l;\n\
    \  vector<int> as(n);\n  for(int i=0;i<n;i++) cin>>as[i];\n\n  auto f=[](int a,int\
    \ b){return min(a,b);};\n  SparseTable<int> st(f);\n  st.build(as);\n\n  for(int\
    \ i=0;i+l<=n;i++){\n    if(i) cout<<\" \";\n    cout<<st.query(i,i+l);\n  }\n\
    \  cout<<endl;\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../datastructure/sparsetable.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,l;\n  cin>>n>>l;\n  vector<int>\
    \ as(n);\n  for(int i=0;i<n;i++) cin>>as[i];\n\n  auto f=[](int a,int b){return\
    \ min(a,b);};\n  SparseTable<int> st(f);\n  st.build(as);\n\n  for(int i=0;i+l<=n;i++){\n\
    \    if(i) cout<<\" \";\n    cout<<st.query(i,i+l);\n  }\n  cout<<endl;\n  return\
    \ 0;\n}\n"
  dependsOn:
  - datastructure/sparsetable.cpp
  isVerificationFile: true
  path: test/aoj/DSL_3_D.sparsetable.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 15:01:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_3_D.sparsetable.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_3_D.sparsetable.test.cpp
- /verify/test/aoj/DSL_3_D.sparsetable.test.cpp.html
title: test/aoj/DSL_3_D.sparsetable.test.cpp
---
