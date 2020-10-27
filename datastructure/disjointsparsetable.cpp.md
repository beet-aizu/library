---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_3_D.disjointsparsetable.test.cpp
    title: test/aoj/DSL_3_D.disjointsparsetable.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/staticrmq.disjointsparsetable.test.cpp
    title: test/yosupo/staticrmq.disjointsparsetable.test.cpp
  - icon: ':x:'
    path: test/yukicoder/4072.test.cpp
    title: test/yukicoder/4072.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://www.codechef.com/problems/SEGPROD
  bundledCode: "#line 1 \"datastructure/disjointsparsetable.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct DisjointSparseTable{\n\
    \  using F = function<T(T, T)>;\n  vector< vector<T> > dat;\n  vector<int> ht;\n\
    \  const F f;\n\n  DisjointSparseTable(F f):f(f){}\n\n  void build(const vector<T>\
    \ &vs){\n    int n=vs.size(),h=1;\n    while((1<<h)<=n) h++;\n    dat.assign(h,vector<T>(n));\n\
    \    ht.assign((1<<h)+1,0);\n    for(int j=2;j<(1<<h)+1;j++) ht[j]=ht[j>>1]+1;\n\
    \n    for(int j=0;j<n;j++) dat[0][j]=vs[j];\n    for(int i=1;i<h;i++){\n     \
    \ int s=1<<i;\n      for(int j=0;j<n;j+=s<<1){\n        int t=min(j+s,n);\n  \
    \      dat[i][t-1]=vs[t-1];\n        for(int k=t-2;k>=j;k--) dat[i][k]=f(vs[k],dat[i][k+1]);\n\
    \        if(n<=t) break;\n        dat[i][t]=vs[t];\n        int r=min(t+s,n);\n\
    \        for(int k=t+1;k<r;k++) dat[i][k]=f(dat[i][k-1],vs[k]);\n      }\n   \
    \ }\n  }\n\n  T query(int l,int r){\n    if(l>=--r) return dat[0][l];\n    return\
    \ f(dat[ht[l^r]][l],dat[ht[l^r]][r]);\n  }\n\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    \n// find with non-idempotent monoid\nsigned CODECHEF_SEGPROD(){\n  int T;\n \
    \ scanf(\"%d\",&T);\n\n  int p;\n  auto f=[&](int a,int b)->int{return (long long)a*b%p;};\n\
    \  DisjointSparseTable<int> dst(f);\n\n  for(int t=1;t<=T;t++){\n    int n,q;\n\
    \    scanf(\"%d %d %d\",&n,&p,&q);\n    vector<int> v(n);\n    for(int i=0;i<n;i++)\
    \ scanf(\"%d\",&v[i]),v[i]%=p;\n    vector<int> b(q/64+2);\n    for(int i=0;i<(q/64+2);i++)\
    \ scanf(\"%d\",&b[i]);\n\n    dst.build(v);\n\n    int x=0,l=0,r=0;\n    for(int\
    \ i=0;i<q;i++){\n      if(i%64==0){\n        l=(b[i/64]+x)%n;\n        r=(b[i/64+1]+x)%n;\n\
    \      }else{\n        l=(l+x)%n;\n        r=(r+x)%n;\n      }\n      if(l>r)\
    \ swap(l,r);\n      x=dst.query(l,r+1)+1;\n      if(x>=p) x-=p;\n    }\n    printf(\"\
    %d\\n\",x);\n  }\n  return 0;\n}\n/*\n  verified on 2019/10/29\n  https://www.codechef.com/problems/SEGPROD\n\
    */\n\n//INSERT ABOVE HERE\nsigned main(){\n  //CODECHEF_SEGPROD();\n  return 0;\n\
    }\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct DisjointSparseTable{\n\
    \  using F = function<T(T, T)>;\n  vector< vector<T> > dat;\n  vector<int> ht;\n\
    \  const F f;\n\n  DisjointSparseTable(F f):f(f){}\n\n  void build(const vector<T>\
    \ &vs){\n    int n=vs.size(),h=1;\n    while((1<<h)<=n) h++;\n    dat.assign(h,vector<T>(n));\n\
    \    ht.assign((1<<h)+1,0);\n    for(int j=2;j<(1<<h)+1;j++) ht[j]=ht[j>>1]+1;\n\
    \n    for(int j=0;j<n;j++) dat[0][j]=vs[j];\n    for(int i=1;i<h;i++){\n     \
    \ int s=1<<i;\n      for(int j=0;j<n;j+=s<<1){\n        int t=min(j+s,n);\n  \
    \      dat[i][t-1]=vs[t-1];\n        for(int k=t-2;k>=j;k--) dat[i][k]=f(vs[k],dat[i][k+1]);\n\
    \        if(n<=t) break;\n        dat[i][t]=vs[t];\n        int r=min(t+s,n);\n\
    \        for(int k=t+1;k<r;k++) dat[i][k]=f(dat[i][k-1],vs[k]);\n      }\n   \
    \ }\n  }\n\n  T query(int l,int r){\n    if(l>=--r) return dat[0][l];\n    return\
    \ f(dat[ht[l^r]][l],dat[ht[l^r]][r]);\n  }\n\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    \n// find with non-idempotent monoid\nsigned CODECHEF_SEGPROD(){\n  int T;\n \
    \ scanf(\"%d\",&T);\n\n  int p;\n  auto f=[&](int a,int b)->int{return (long long)a*b%p;};\n\
    \  DisjointSparseTable<int> dst(f);\n\n  for(int t=1;t<=T;t++){\n    int n,q;\n\
    \    scanf(\"%d %d %d\",&n,&p,&q);\n    vector<int> v(n);\n    for(int i=0;i<n;i++)\
    \ scanf(\"%d\",&v[i]),v[i]%=p;\n    vector<int> b(q/64+2);\n    for(int i=0;i<(q/64+2);i++)\
    \ scanf(\"%d\",&b[i]);\n\n    dst.build(v);\n\n    int x=0,l=0,r=0;\n    for(int\
    \ i=0;i<q;i++){\n      if(i%64==0){\n        l=(b[i/64]+x)%n;\n        r=(b[i/64+1]+x)%n;\n\
    \      }else{\n        l=(l+x)%n;\n        r=(r+x)%n;\n      }\n      if(l>r)\
    \ swap(l,r);\n      x=dst.query(l,r+1)+1;\n      if(x>=p) x-=p;\n    }\n    printf(\"\
    %d\\n\",x);\n  }\n  return 0;\n}\n/*\n  verified on 2019/10/29\n  https://www.codechef.com/problems/SEGPROD\n\
    */\n\n//INSERT ABOVE HERE\nsigned main(){\n  //CODECHEF_SEGPROD();\n  return 0;\n\
    }\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/disjointsparsetable.cpp
  requiredBy: []
  timestamp: '2020-10-27 19:32:25+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/4072.test.cpp
  - test/aoj/DSL_3_D.disjointsparsetable.test.cpp
  - test/yosupo/staticrmq.disjointsparsetable.test.cpp
documentation_of: datastructure/disjointsparsetable.cpp
layout: document
redirect_from:
- /library/datastructure/disjointsparsetable.cpp
- /library/datastructure/disjointsparsetable.cpp.html
title: datastructure/disjointsparsetable.cpp
---
