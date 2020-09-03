---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"math/fraction.cpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct fraction{\n  T\
    \ num,dom;\n  fraction(){}\n  fraction(T n,T d):num(n),dom(d){\n    assert(dom!=0);\n\
    \    if(dom<0) num*=-1,dom*=-1;\n    T tmp=__gcd(abs(num),abs(dom));\n    num/=tmp;\n\
    \    dom/=tmp;\n  }\n  fraction operator+(const fraction a) const{\n    return\
    \ fraction(num*a.dom+a.num*dom,dom*a.dom);\n  }\n  fraction operator-(const fraction\
    \ a) const{\n    return fraction(num*a.dom-a.num*dom,dom*a.dom);\n  }\n  fraction\
    \ operator*(const fraction a) const{\n    return fraction(num*a.num,dom*a.dom);\n\
    \  }\n  fraction operator/(const fraction a){\n    return fraction(num*a.dom,dom*a.num);\n\
    \  }\n  fraction operator*(T k) const{return fraction(num*k,dom);}\n  fraction\
    \ operator/(T k) const{return fraction(num,dom*k);}\n  bool operator<(const fraction\
    \ a)const{\n    return num*a.dom<a.num*dom;\n  }\n  bool operator>(const fraction\
    \ a)const{\n    return num*a.dom>a.num*dom;\n  }\n  bool operator==(const fraction\
    \ a)const{\n    return num*a.dom==a.num*dom;\n  }\n  bool operator!=(const fraction\
    \ a)const{\n    return num*a.dom!=a.num*dom;\n  }\n  bool operator<=(const fraction\
    \ a)const{\n    return num*a.dom<=a.num*dom;\n  }\n  bool operator>=(const fraction\
    \ a)const{\n    return num*a.dom>=a.num*dom;\n  }\n};\n//END CUT HERE\n#ifndef\
    \ call_from_test\nstruct FastIO{\n  FastIO(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n\
    \  }\n}fastio_beet;\n\n//INSERT ABOVE HERE\nsigned CPSCO2019_Session3_G(){\n \
    \ using ll = long long;\n\n  int n,x;\n  cin>>n>>x;\n\n  vector<ll> as(n);\n \
    \ for(int i=0;i<n;i++) cin>>as[i];\n\n  using F = fraction<ll>;\n  using T = tuple<F,\
    \ int, int>;\n  priority_queue<T> pq;\n\n  int sum=0;\n  for(int i=0;i<n;i++)\
    \ sum+=as[i];\n\n  for(int i=0;i<n;i++){\n    int p=x*as[i]/sum;\n    pq.emplace(F(1,as[i]),i,p);\n\
    \    if((x*as[i])%sum!=0)\n      pq.emplace(F(2*x,sum)-F(2*p+1,as[i]),i,1);\n\
    \    pq.emplace(F(-1,as[i]),i,x+1);\n  }\n\n  vector<int> bs(n,0);\n  int k=x;\n\
    \  while(k>0){\n    int i,l;\n    tie(ignore,i,l)=pq.top();pq.pop();\n\n    int\
    \ t=min(k,l);\n    bs[i]+=t;\n    k-=t;\n  }\n\n  for(int i=0;i<n;i++) cout<<bs[i]<<\"\
    \\n\";\n  cout<<flush;\n  return 0;\n}\n/*\n  verified on 2019/12/17\n  https://atcoder.jp/contests/cpsco2019-s3/tasks/cpsco2019_s3_g\n\
    */\n\nsigned main(){\n  //CPSCO2019_Session3_G();\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename T>\nstruct fraction{\n  T num,dom;\n  fraction(){}\n\
    \  fraction(T n,T d):num(n),dom(d){\n    assert(dom!=0);\n    if(dom<0) num*=-1,dom*=-1;\n\
    \    T tmp=__gcd(abs(num),abs(dom));\n    num/=tmp;\n    dom/=tmp;\n  }\n  fraction\
    \ operator+(const fraction a) const{\n    return fraction(num*a.dom+a.num*dom,dom*a.dom);\n\
    \  }\n  fraction operator-(const fraction a) const{\n    return fraction(num*a.dom-a.num*dom,dom*a.dom);\n\
    \  }\n  fraction operator*(const fraction a) const{\n    return fraction(num*a.num,dom*a.dom);\n\
    \  }\n  fraction operator/(const fraction a){\n    return fraction(num*a.dom,dom*a.num);\n\
    \  }\n  fraction operator*(T k) const{return fraction(num*k,dom);}\n  fraction\
    \ operator/(T k) const{return fraction(num,dom*k);}\n  bool operator<(const fraction\
    \ a)const{\n    return num*a.dom<a.num*dom;\n  }\n  bool operator>(const fraction\
    \ a)const{\n    return num*a.dom>a.num*dom;\n  }\n  bool operator==(const fraction\
    \ a)const{\n    return num*a.dom==a.num*dom;\n  }\n  bool operator!=(const fraction\
    \ a)const{\n    return num*a.dom!=a.num*dom;\n  }\n  bool operator<=(const fraction\
    \ a)const{\n    return num*a.dom<=a.num*dom;\n  }\n  bool operator>=(const fraction\
    \ a)const{\n    return num*a.dom>=a.num*dom;\n  }\n};\n//END CUT HERE\n#ifndef\
    \ call_from_test\nstruct FastIO{\n  FastIO(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n\
    \  }\n}fastio_beet;\n\n//INSERT ABOVE HERE\nsigned CPSCO2019_Session3_G(){\n \
    \ using ll = long long;\n\n  int n,x;\n  cin>>n>>x;\n\n  vector<ll> as(n);\n \
    \ for(int i=0;i<n;i++) cin>>as[i];\n\n  using F = fraction<ll>;\n  using T = tuple<F,\
    \ int, int>;\n  priority_queue<T> pq;\n\n  int sum=0;\n  for(int i=0;i<n;i++)\
    \ sum+=as[i];\n\n  for(int i=0;i<n;i++){\n    int p=x*as[i]/sum;\n    pq.emplace(F(1,as[i]),i,p);\n\
    \    if((x*as[i])%sum!=0)\n      pq.emplace(F(2*x,sum)-F(2*p+1,as[i]),i,1);\n\
    \    pq.emplace(F(-1,as[i]),i,x+1);\n  }\n\n  vector<int> bs(n,0);\n  int k=x;\n\
    \  while(k>0){\n    int i,l;\n    tie(ignore,i,l)=pq.top();pq.pop();\n\n    int\
    \ t=min(k,l);\n    bs[i]+=t;\n    k-=t;\n  }\n\n  for(int i=0;i<n;i++) cout<<bs[i]<<\"\
    \\n\";\n  cout<<flush;\n  return 0;\n}\n/*\n  verified on 2019/12/17\n  https://atcoder.jp/contests/cpsco2019-s3/tasks/cpsco2019_s3_g\n\
    */\n\nsigned main(){\n  //CPSCO2019_Session3_G();\n  return 0;\n}\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1338.test.cpp
    title: test/aoj/1338.test.cpp
  isVerificationFile: false
  path: math/fraction.cpp
  requiredBy: []
  timestamp: '2019-12-17 21:37:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - test/aoj/1338.test.cpp
documentation_of: math/fraction.cpp
layout: document
redirect_from:
- /library/math/fraction.cpp
- /library/math/fraction.cpp.html
title: math/fraction.cpp
---
