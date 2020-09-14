---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://codeforces.com/contest/1137/problem/E
  bundledCode: "#line 1 \"datastructure/convexhulltrickwithindex.cpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n//BEGIN CUT HERE\n// index siyou kimattenai\ntemplate <typename\
    \ T,bool isMin>\nstruct ConvexHullTrickWithIndex {\n  struct P{\n    T m,b;\n\
    \    int idx;\n    P(T m,T b,int idx):m(m),b(b),idx(idx){};\n    bool operator<(const\
    \ P &a){\n      return m!=a.m?m<a.m:b<a.b;\n    }\n  };\n\n  deque<P> H;\n  bool\
    \ empty()const{return H.empty();}\n  void clear(){H.clear();}\n\n  inline int\
    \ sgn(T x){return x==0?0:(x<0?-1:1);}\n\n  using D = long double;\n  inline bool\
    \ check(const P &a,const P &b,const P &c){\n    if(b.b==a.b||c.b==b.b)\n     \
    \ return sgn(b.m-a.m)*sgn(c.b-b.b) >= sgn(c.m-b.m)*sgn(b.b-a.b);\n    return D(b.m-a.m)*sgn(c.b-b.b)/D(abs(b.b-a.b))\n\
    \      >= D(c.m-b.m)*sgn(b.b-a.b)/D(abs(c.b-b.b));\n  }\n\n  void addLine(T m,T\
    \ b,int idx){\n    if(!isMin) m*=-1,b*=-1;\n    P line(m,b,idx);\n    if(empty()){\n\
    \      H.emplace_front(line);\n      return;\n    }\n\n    if(empty()||H.front().m<=m){\n\
    \      if(H.front().m==m){\n        if(H.front().b<=b) return;\n        H.pop_front();\n\
    \      }\n      while(H.size()>=2&&check(line,H.front(),H[1])) H.pop_front();\n\
    \      H.emplace_front(line);\n    }else{\n      assert(m<=H.back().m);\n    \
    \  if(H.back().m==m){\n        if(H.back().b<=b) return;\n        H.pop_back();\n\
    \      }\n      while(H.size()>=2&&check(H[H.size()-2],H.back(),line)) H.pop_back();\n\
    \      H.emplace_back(line);\n    }\n  }\n\n  inline pair<T, int> getY(const P\
    \ &a,const T &x){\n    return make_pair(a.m*x+a.b,a.idx);\n  }\n\n  pair<T, int>\
    \ query(T x){\n    assert(!empty());\n    int l=-1,r=H.size()-1;\n    while(l+1<r){\n\
    \      int m=(l+r)>>1;\n      if(getY(H[m],x)>=getY(H[m+1],x)) l=m;\n      else\
    \ r=m;\n    }\n    if(isMin) return getY(H[r],x);\n    return make_pair(-getY(H[r],x).first,H[r].idx);\n\
    \  }\n\n  pair<T, int> queryMonotoneInc(T x){\n    assert(!empty());\n    while(H.size()>=2&&getY(H.front(),x)>=getY(H[1],x))\
    \ H.pop_front();\n    if(isMin) return getY(H.front(),x);\n    return make_pair(-getY(H.front(),x).first,H.front().idx);\n\
    \  }\n\n  pair<T, int> queryMonotoneDec(T x){\n    assert(!empty());\n    while(H.size()>=2&&getY(H.back(),x)>=getY(H[H.size()-2],x))\
    \ H.pop_back();\n    if(isMin) return getY(H.back(),x);\n    return make_pair(-getY(H.back(),x).first,H.back().idx);\n\
    \  }\n};\n//END CUT HERE\n//INSERT ABOVE HERE\nsigned main(){\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n\n  using ll = long long;\n  ll n,m;\n  cin>>n>>m;\n\
    \n  using CHT = ConvexHullTrickWithIndex<ll, true>;\n\n  CHT cht;\n  ll bs=0,ss=0,len=n;\n\
    \  cht.addLine(0,-bs,0);\n\n  for(int i=0;i<m;i++){\n    int t;\n    cin>>t;\n\
    \    if(t==1){\n      ll k;\n      cin>>k;\n      cht.clear();\n      cht.addLine(0,-bs,0);\n\
    \      len+=k;\n    }\n    if(t==2){\n      ll k;\n      cin>>k;\n      cht.addLine(len,-(bs+len*ss),len);\n\
    \      len+=k;\n    }\n    if(t==3){\n      ll b,s;\n      cin>>b>>s;\n      bs+=b;\n\
    \      ss+=s;\n    }\n    auto p=cht.queryMonotoneInc(ss);\n    cout<<p.second+1<<\"\
    \ \"<<bs+p.first<<\"\\n\";\n  }\n  cout<<flush;\n  return 0;\n}\n/*\n  verified\
    \ on 2019/05/14\n  https://codeforces.com/contest/1137/problem/E\n*/\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n//BEGIN CUT HERE\n// index\
    \ siyou kimattenai\ntemplate <typename T,bool isMin>\nstruct ConvexHullTrickWithIndex\
    \ {\n  struct P{\n    T m,b;\n    int idx;\n    P(T m,T b,int idx):m(m),b(b),idx(idx){};\n\
    \    bool operator<(const P &a){\n      return m!=a.m?m<a.m:b<a.b;\n    }\n  };\n\
    \n  deque<P> H;\n  bool empty()const{return H.empty();}\n  void clear(){H.clear();}\n\
    \n  inline int sgn(T x){return x==0?0:(x<0?-1:1);}\n\n  using D = long double;\n\
    \  inline bool check(const P &a,const P &b,const P &c){\n    if(b.b==a.b||c.b==b.b)\n\
    \      return sgn(b.m-a.m)*sgn(c.b-b.b) >= sgn(c.m-b.m)*sgn(b.b-a.b);\n    return\
    \ D(b.m-a.m)*sgn(c.b-b.b)/D(abs(b.b-a.b))\n      >= D(c.m-b.m)*sgn(b.b-a.b)/D(abs(c.b-b.b));\n\
    \  }\n\n  void addLine(T m,T b,int idx){\n    if(!isMin) m*=-1,b*=-1;\n    P line(m,b,idx);\n\
    \    if(empty()){\n      H.emplace_front(line);\n      return;\n    }\n\n    if(empty()||H.front().m<=m){\n\
    \      if(H.front().m==m){\n        if(H.front().b<=b) return;\n        H.pop_front();\n\
    \      }\n      while(H.size()>=2&&check(line,H.front(),H[1])) H.pop_front();\n\
    \      H.emplace_front(line);\n    }else{\n      assert(m<=H.back().m);\n    \
    \  if(H.back().m==m){\n        if(H.back().b<=b) return;\n        H.pop_back();\n\
    \      }\n      while(H.size()>=2&&check(H[H.size()-2],H.back(),line)) H.pop_back();\n\
    \      H.emplace_back(line);\n    }\n  }\n\n  inline pair<T, int> getY(const P\
    \ &a,const T &x){\n    return make_pair(a.m*x+a.b,a.idx);\n  }\n\n  pair<T, int>\
    \ query(T x){\n    assert(!empty());\n    int l=-1,r=H.size()-1;\n    while(l+1<r){\n\
    \      int m=(l+r)>>1;\n      if(getY(H[m],x)>=getY(H[m+1],x)) l=m;\n      else\
    \ r=m;\n    }\n    if(isMin) return getY(H[r],x);\n    return make_pair(-getY(H[r],x).first,H[r].idx);\n\
    \  }\n\n  pair<T, int> queryMonotoneInc(T x){\n    assert(!empty());\n    while(H.size()>=2&&getY(H.front(),x)>=getY(H[1],x))\
    \ H.pop_front();\n    if(isMin) return getY(H.front(),x);\n    return make_pair(-getY(H.front(),x).first,H.front().idx);\n\
    \  }\n\n  pair<T, int> queryMonotoneDec(T x){\n    assert(!empty());\n    while(H.size()>=2&&getY(H.back(),x)>=getY(H[H.size()-2],x))\
    \ H.pop_back();\n    if(isMin) return getY(H.back(),x);\n    return make_pair(-getY(H.back(),x).first,H.back().idx);\n\
    \  }\n};\n//END CUT HERE\n//INSERT ABOVE HERE\nsigned main(){\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n\n  using ll = long long;\n  ll n,m;\n  cin>>n>>m;\n\
    \n  using CHT = ConvexHullTrickWithIndex<ll, true>;\n\n  CHT cht;\n  ll bs=0,ss=0,len=n;\n\
    \  cht.addLine(0,-bs,0);\n\n  for(int i=0;i<m;i++){\n    int t;\n    cin>>t;\n\
    \    if(t==1){\n      ll k;\n      cin>>k;\n      cht.clear();\n      cht.addLine(0,-bs,0);\n\
    \      len+=k;\n    }\n    if(t==2){\n      ll k;\n      cin>>k;\n      cht.addLine(len,-(bs+len*ss),len);\n\
    \      len+=k;\n    }\n    if(t==3){\n      ll b,s;\n      cin>>b>>s;\n      bs+=b;\n\
    \      ss+=s;\n    }\n    auto p=cht.queryMonotoneInc(ss);\n    cout<<p.second+1<<\"\
    \ \"<<bs+p.first<<\"\\n\";\n  }\n  cout<<flush;\n  return 0;\n}\n/*\n  verified\
    \ on 2019/05/14\n  https://codeforces.com/contest/1137/problem/E\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/convexhulltrickwithindex.cpp
  requiredBy: []
  timestamp: '2019-12-17 21:51:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/convexhulltrickwithindex.cpp
layout: document
redirect_from:
- /library/datastructure/convexhulltrickwithindex.cpp
- /library/datastructure/convexhulltrickwithindex.cpp.html
title: datastructure/convexhulltrickwithindex.cpp
---
