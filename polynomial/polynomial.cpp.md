---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 2 \"polynomial/polynomial.cpp\"\n\n#ifndef call_from_test\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename\
    \ T>\nstruct Polynomial{\n  using P = Polynomial;\n  vector<T> co;\n  Polynomial():co(1,T(1)){}\n\
    \  Polynomial(int sz):co(sz,0){}\n  Polynomial(vector<T> co):co(co){}\n\n  size_t\
    \ size() const{\n    return co.size();\n  };\n\n  void shrink(){\n    while(co.size()>1u&&!co.back())\n\
    \      co.pop_back();\n  }\n\n  void reduce(){\n    T g=abs(co.back());\n    if(!g)\
    \ return;\n    for(T c:co)\n      if(c!=0) g=__gcd(g,abs(c));\n    if(co.back()<0)\
    \ g*=-1;\n    for(T &c:co) c/=g;\n  }\n\n  void print(){\n    shrink();\n    reduce();\n\
    \    int n=size(),flg=0;\n    for(int i=n-1;i>0;i--){\n      if(!co[i]) continue;\n\
    \      flg=1;\n      if(i!=n-1&&co[i]>0) cout<<\"+\";\n      if(co[i]==-1) cout<<\"\
    -\";\n      else if(co[i]!=1) cout<<co[i];\n\n      cout<<\"x\";\n      if(i!=1)\
    \ cout<<\"^\"<<i;\n    }\n    if(co[0]){\n      if(flg&&co[0]>0) cout<<\"+\";\n\
    \      cout<<co[0];\n    }\n    cout<<endl;\n  }\n\n  T operator[](int i) const{\n\
    \    return co[i];\n  }\n\n  T &operator[](int i){\n    return co[i];\n  }\n\n\
    \  P operator-() const{\n    P res=*this;\n    for(T &c:res.co) c*=-1;\n    return\
    \ res;\n  }\n\n  P operator+(const P &a) const{\n    int n=size(),m=a.size();\n\
    \    P res(max(n,m));\n    for(int i=0;i<n;i++) res[i]+=co[i];\n    for(int i=0;i<m;i++)\
    \ res[i]+=a[i];\n    return res;\n  }\n\n  P operator-(const P &a) const{return\
    \ *this+(-a);};\n\n  P operator*(const P &a) const{\n    int n=size(),m=a.size();\n\
    \    P res(n+m);\n    for(int i=0;i<n;i++)\n      for(int j=0;j<m;j++)\n     \
    \   res[i+j]+=co[i]*a[j];\n    res.shrink();\n    return res;\n  }\n\n  P pow(const\
    \ P &a,int k) const{\n    P res;\n    for(int i=0;i<k;i++) res=res*a;\n    return\
    \ res;\n  }\n\n  pair<P, P> divide(const P &a) const{\n    int n=size(),m=a.size(),s=n-m+1;\n\
    \    if(s<0) return make_pair(P(1),*this);\n    P div(s);\n    P rest=*this;\n\
    \    for(int i=0;i<s;i++){\n      if(rest[n-(i+1)]%a[m-1]!=0)\n        for(T &c:rest.co)\
    \ c*=a[m-1];\n      T d=rest[n-(i+1)]/a[m-1];\n      div[s-(i+1)]=d;\n      for(int\
    \ j=m;j>0;j--) rest[n-(i+j)]-=a[m-j]*d;\n    }\n    return make_pair(div,rest);\n\
    \  }\n\n  P operator/(const P &a) const{return divide(a).first;};\n  P operator%(const\
    \ P &a) const{return divide(a).second;};\n};\n\ntemplate<typename T>\nPolynomial<T>\
    \ gcd(Polynomial<T> a,Polynomial<T> b){\n  a.shrink();a.reduce();\n  b.shrink();b.reduce();\n\
    \  if(a.size()<b.size()) swap(a,b);\n  if(b.size()==1u&&!b[0]) return a;\n  return\
    \ gcd(b,a%b);\n}\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct Polynomial{\n \
    \ using P = Polynomial;\n  vector<T> co;\n  Polynomial():co(1,T(1)){}\n  Polynomial(int\
    \ sz):co(sz,0){}\n  Polynomial(vector<T> co):co(co){}\n\n  size_t size() const{\n\
    \    return co.size();\n  };\n\n  void shrink(){\n    while(co.size()>1u&&!co.back())\n\
    \      co.pop_back();\n  }\n\n  void reduce(){\n    T g=abs(co.back());\n    if(!g)\
    \ return;\n    for(T c:co)\n      if(c!=0) g=__gcd(g,abs(c));\n    if(co.back()<0)\
    \ g*=-1;\n    for(T &c:co) c/=g;\n  }\n\n  void print(){\n    shrink();\n    reduce();\n\
    \    int n=size(),flg=0;\n    for(int i=n-1;i>0;i--){\n      if(!co[i]) continue;\n\
    \      flg=1;\n      if(i!=n-1&&co[i]>0) cout<<\"+\";\n      if(co[i]==-1) cout<<\"\
    -\";\n      else if(co[i]!=1) cout<<co[i];\n\n      cout<<\"x\";\n      if(i!=1)\
    \ cout<<\"^\"<<i;\n    }\n    if(co[0]){\n      if(flg&&co[0]>0) cout<<\"+\";\n\
    \      cout<<co[0];\n    }\n    cout<<endl;\n  }\n\n  T operator[](int i) const{\n\
    \    return co[i];\n  }\n\n  T &operator[](int i){\n    return co[i];\n  }\n\n\
    \  P operator-() const{\n    P res=*this;\n    for(T &c:res.co) c*=-1;\n    return\
    \ res;\n  }\n\n  P operator+(const P &a) const{\n    int n=size(),m=a.size();\n\
    \    P res(max(n,m));\n    for(int i=0;i<n;i++) res[i]+=co[i];\n    for(int i=0;i<m;i++)\
    \ res[i]+=a[i];\n    return res;\n  }\n\n  P operator-(const P &a) const{return\
    \ *this+(-a);};\n\n  P operator*(const P &a) const{\n    int n=size(),m=a.size();\n\
    \    P res(n+m);\n    for(int i=0;i<n;i++)\n      for(int j=0;j<m;j++)\n     \
    \   res[i+j]+=co[i]*a[j];\n    res.shrink();\n    return res;\n  }\n\n  P pow(const\
    \ P &a,int k) const{\n    P res;\n    for(int i=0;i<k;i++) res=res*a;\n    return\
    \ res;\n  }\n\n  pair<P, P> divide(const P &a) const{\n    int n=size(),m=a.size(),s=n-m+1;\n\
    \    if(s<0) return make_pair(P(1),*this);\n    P div(s);\n    P rest=*this;\n\
    \    for(int i=0;i<s;i++){\n      if(rest[n-(i+1)]%a[m-1]!=0)\n        for(T &c:rest.co)\
    \ c*=a[m-1];\n      T d=rest[n-(i+1)]/a[m-1];\n      div[s-(i+1)]=d;\n      for(int\
    \ j=m;j>0;j--) rest[n-(i+j)]-=a[m-j]*d;\n    }\n    return make_pair(div,rest);\n\
    \  }\n\n  P operator/(const P &a) const{return divide(a).first;};\n  P operator%(const\
    \ P &a) const{return divide(a).second;};\n};\n\ntemplate<typename T>\nPolynomial<T>\
    \ gcd(Polynomial<T> a,Polynomial<T> b){\n  a.shrink();a.reduce();\n  b.shrink();b.reduce();\n\
    \  if(a.size()<b.size()) swap(a,b);\n  if(b.size()==1u&&!b[0]) return a;\n  return\
    \ gcd(b,a%b);\n}\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1293.test.cpp
    title: test/aoj/1293.test.cpp
  extendedVerifiedWith: []
  isVerificationFile: false
  path: polynomial/polynomial.cpp
  requiredBy:
  - test/aoj/1293.test.cpp
  timestamp: '2020-03-12 17:15:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: polynomial/polynomial.cpp
layout: document
redirect_from:
- /library/polynomial/polynomial.cpp
- /library/polynomial/polynomial.cpp.html
title: polynomial/polynomial.cpp
---
