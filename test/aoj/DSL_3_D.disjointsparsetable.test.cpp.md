---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: datastructure/disjointsparsetable.cpp
    title: datastructure/disjointsparsetable.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
  bundledCode: "#line 1 \"test/aoj/DSL_3_D.disjointsparsetable.test.cpp\"\n// verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#line\
    \ 1 \"datastructure/disjointsparsetable.cpp\"\n\n#line 3 \"datastructure/disjointsparsetable.cpp\"\
    \nusing namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct\
    \ DisjointSparseTable{\n  using F = function<T(T, T)>;\n  vector< vector<T> >\
    \ dat;\n  vector<int> ht;\n  const F f;\n\n  DisjointSparseTable(F f):f(f){}\n\
    \n  void build(const vector<T> &vs){\n    int n=vs.size(),h=1;\n    while((1<<h)<=n)\
    \ h++;\n    dat.assign(h,vector<T>(n));\n    ht.assign((1<<h)+1,0);\n    for(int\
    \ j=2;j<(1<<h)+1;j++) ht[j]=ht[j>>1]+1;\n\n    for(int j=0;j<n;j++) dat[0][j]=vs[j];\n\
    \    for(int i=1;i<h;i++){\n      int s=1<<i;\n      for(int j=0;j<n;j+=s<<1){\n\
    \        int t=min(j+s,n);\n        dat[i][t-1]=vs[t-1];\n        for(int k=t-2;k>=j;k--)\
    \ dat[i][k]=f(vs[k],dat[i][k+1]);\n        if(n<=t) break;\n        dat[i][t]=vs[t];\n\
    \        int r=min(t+s,n);\n        for(int k=t+1;k<r;k++) dat[i][k]=f(dat[i][k-1],vs[k]);\n\
    \      }\n    }\n  }\n\n  T query(int l,int r){\n    if(l>=--r) return dat[0][l];\n\
    \    return f(dat[ht[l^r]][l],dat[ht[l^r]][r]);\n  }\n\n};\n//END CUT HERE\n#ifndef\
    \ call_from_test\n\n// find with non-idempotent monoid\nsigned CODECHEF_SEGPROD(){\n\
    \  int T;\n  scanf(\"%d\",&T);\n\n  int p;\n  auto f=[&](int a,int b)->int{return\
    \ (long long)a*b%p;};\n  DisjointSparseTable<int> dst(f);\n\n  for(int t=1;t<=T;t++){\n\
    \    int n,q;\n    scanf(\"%d %d %d\",&n,&p,&q);\n    vector<int> v(n);\n    for(int\
    \ i=0;i<n;i++) scanf(\"%d\",&v[i]),v[i]%=p;\n    vector<int> b(q/64+2);\n    for(int\
    \ i=0;i<(q/64+2);i++) scanf(\"%d\",&b[i]);\n\n    dst.build(v);\n\n    int x=0,l=0,r=0;\n\
    \    for(int i=0;i<q;i++){\n      if(i%64==0){\n        l=(b[i/64]+x)%n;\n   \
    \     r=(b[i/64+1]+x)%n;\n      }else{\n        l=(l+x)%n;\n        r=(r+x)%n;\n\
    \      }\n      if(l>r) swap(l,r);\n      x=dst.query(l,r+1)+1;\n      if(x>=p)\
    \ x-=p;\n    }\n    printf(\"%d\\n\",x);\n  }\n  return 0;\n}\n/*\n  verified\
    \ on 2019/10/29\n  https://www.codechef.com/problems/SEGPROD\n*/\n\n//INSERT ABOVE\
    \ HERE\nsigned main(){\n  //CODECHEF_SEGPROD();\n  return 0;\n}\n#endif\n#line\
    \ 8 \"test/aoj/DSL_3_D.disjointsparsetable.test.cpp\"\n#undef call_from_test\n\
    \nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,l;\n  cin>>n>>l;\n\
    \  vector<int> as(n);\n  for(int i=0;i<n;i++) cin>>as[i];\n\n  auto f=[](int a,int\
    \ b){return min(a,b);};\n  DisjointSparseTable<int> st(f);\n  st.build(as);\n\n\
    \  for(int i=0;i+l<=n;i++){\n    if(i) cout<<\" \";\n    cout<<st.query(i,i+l);\n\
    \  }\n  cout<<endl;\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../datastructure/disjointsparsetable.cpp\"\n#undef call_from_test\n\nsigned\
    \ main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,l;\n  cin>>n>>l;\n\
    \  vector<int> as(n);\n  for(int i=0;i<n;i++) cin>>as[i];\n\n  auto f=[](int a,int\
    \ b){return min(a,b);};\n  DisjointSparseTable<int> st(f);\n  st.build(as);\n\n\
    \  for(int i=0;i+l<=n;i++){\n    if(i) cout<<\" \";\n    cout<<st.query(i,i+l);\n\
    \  }\n  cout<<endl;\n  return 0;\n}\n"
  dependsOn:
  - datastructure/disjointsparsetable.cpp
  isVerificationFile: true
  path: test/aoj/DSL_3_D.disjointsparsetable.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 19:32:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_3_D.disjointsparsetable.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_3_D.disjointsparsetable.test.cpp
- /verify/test/aoj/DSL_3_D.disjointsparsetable.test.cpp.html
title: test/aoj/DSL_3_D.disjointsparsetable.test.cpp
---
