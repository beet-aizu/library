---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1630.test.cpp
    title: test/aoj/1630.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2971.test.cpp
    title: test/aoj/2971.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/bitflyer2018-final/tasks/bitflyer2018_final_f
    - https://atcoder.jp/contests/jag2018summer-day2/tasks/jag2018summer_day2_f
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ polynomial/hash.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../mod/mint.cpp\"\n#undef call_from_test\n\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename T,typename M1,typename M2,typename\
    \ M3>\nstruct PolynomialHash{\n  struct V{\n    M1 v1;\n    M2 v2;\n    M3 v3;\n\
    \    V(int x):v1(x),v2(x),v3(x){}\n    V(long long x):v1(x),v2(x),v3(x){}\n  \
    \  V(M1 v1,M2 v2,M3 v3):v1(v1),v2(v2),v3(v3){}\n\n    V& operator+=(V a){v1+=a.v1;v2+=a.v2;v3+=a.v3;;return\
    \ *this;}\n    V& operator-=(V a){v1-=a.v1;v2-=a.v2;v3-=a.v3;;return *this;}\n\
    \    V& operator*=(V a){v1*=a.v1;v2*=a.v2;v3*=a.v3;;return *this;}\n    V& operator/=(V\
    \ a){v1/=a.v1;v2/=a.v2;v3/=a.v3;;return *this;}\n\n    V operator+(V a) const{return\
    \ V(*this)+=a;}\n    V operator-(V a) const{return V(*this)-=a;}\n    V operator*(V\
    \ a) const{return V(*this)*=a;}\n    V operator/(V a) const{return V(*this)/=a;}\n\
    \n    tuple<M1, M2, M3> norm() const{return make_tuple(v1,v2,v3);}\n\n    bool\
    \ operator==(const V a)const{return norm()==a.norm();}\n    bool operator!=(const\
    \ V a)const{return norm()!=a.norm();}\n    bool operator <(const V a)const{return\
    \ norm() <a.norm();}\n  };\n  const T BASE = 1777771;\n\n  vector<M1> po1,op1;\n\
    \  vector<M2> po2,op2;\n  vector<M3> po3,op3;\n\n  template<typename M>\n  void\
    \ init(int n,vector<M>& po,vector<M>& op){\n    po.assign(n+1,1);\n    op.assign(n+1,1);\n\
    \    M x(BASE);\n    M y=M(x).inv();\n    for(int i=1;i<=(int)n;i++) po[i]=po[i-1]*x;\n\
    \    for(int i=1;i<=(int)n;i++) op[i]=op[i-1]*y;\n  }\n\n  PolynomialHash(size_t\
    \ n){\n    init(n,po1,op1);\n    init(n,po2,op2);\n    init(n,po3,op3);\n  }\n\
    \n  V build(const vector<T> &v){\n    int n=v.size();\n    M1 r1;M2 r2;M3 r3;\n\
    \    for(int i=0;i<n;i++){\n      r1+=M1(v[i])*po1[i];\n      r2+=M2(v[i])*po2[i];\n\
    \      r3+=M3(v[i])*po3[i];\n    }\n    return V(r1,r2,r3);\n  }\n\n  V term(size_t\
    \ x,T k){\n    M1 a1=po1[x]*M1((long long)k);\n    M2 a2=po2[x]*M2((long long)k);\n\
    \    M3 a3=po3[x]*M3((long long)k);\n    return V(a1,a2,a3);\n  }\n};\n//END CUT\
    \ HERE\n#ifndef call_from_test\n\ntemplate<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}\n\
    \n//INSERT ABOVE HERE\nsigned CODEFLYER2018_F(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  const int MAX = 2020;\n  using BS = bitset<MAX>;\n\n  int h,w,q;\n  cin>>h>>w>>q;\n\
    \n  vector<string> s(h);\n  for(int i=0;i<h;i++) cin>>s[i];\n\n  vector<BS> rs(h),cs(w);\n\
    \  for(int i=0;i<h;i++){\n    for(int j=0;j<w;j++){\n      rs[i][j]=(s[i][j]=='#');\n\
    \      cs[j][i]=(s[i][j]=='#');\n    }\n  }\n\n  auto conv=\n    [&](BS &v,int\
    \ k){\n      vector<int> a(k);\n      for(int i=0;i<k;i++) a[i]=v[i];\n      return\
    \ a;\n    };\n\n  using M1 = Mint<int, int(1e9+7)>;\n  using M2 = Mint<int, int(1e9+9)>;\n\
    \  using M3 = Mint<int, int(1e8+7)>;\n\n  PolynomialHash<int, M1, M2, M3> ph(MAX);\n\
    \  using V = decltype(ph)::V;\n\n  vector<V> vrs(h,0),vcs(w,0);\n  vector<int>\
    \ tmp(w,1);\n  V ri=ph.build(tmp);\n  tmp.assign(h,1);\n  V ci=ph.build(tmp);\n\
    \n  for(int i=0;i<h;i++){\n    auto v=conv(rs[i],w);\n    vrs[i]=ph.build(v);\n\
    \    if(rs[i][0]) vrs[i]=ri-vrs[i];\n  }\n\n  for(int j=0;j<w;j++){\n    auto\
    \ v=conv(cs[j],h);\n    vcs[j]=ph.build(v);\n    if(cs[j][0]) vcs[j]=ci-vcs[j];\n\
    \  }\n\n  map<V, set<int> > mrs, mcs;\n  for(int i=0;i<h;i++) mrs[vrs[i]].emplace(i);\n\
    \  for(int j=0;j<w;j++) mcs[vcs[j]].emplace(j);\n\n  auto print=[&](string s){cout<<s<<\"\
    \\n\";};\n\n  auto check=\n    [&](){\n      int a1=-1,b1=-1,c1=-1,d1=-1;\n  \
    \    int a2=-1,b2=-1,c2=-1,d2=-1;\n\n      int A,B,C,D;\n\n      {\n        auto\
    \ latte=mrs.begin();\n        set<int> &s=latte->second;\n        latte++;\n \
    \       set<int> &t=latte->second;\n        if(*--s.end()-*s.begin()+1==(int)s.size()){\n\
    \          a1=*s.begin();\n          b1=*--s.end();\n        }\n        if(*--t.end()-*t.begin()+1==(int)t.size()){\n\
    \          a2=*t.begin();\n          b2=*--t.end();\n        }\n        A=*s.begin();\n\
    \        B=*t.begin();\n      }\n      if(a1<0 and a2<0){\n        print(\"No\"\
    );\n        return;\n      }\n\n      {\n        auto latte=mcs.begin();\n   \
    \     set<int> &s=latte->second;\n        latte++;\n        set<int> &t=latte->second;\n\
    \        if(*--s.end()-*s.begin()+1==(int)s.size()){\n          c1=*s.begin();\n\
    \          d1=*--s.end();\n        }\n        if(*--t.end()-*t.begin()+1==(int)t.size()){\n\
    \          c2=*t.begin();\n          d2=*--t.end();\n        }\n        C=*s.begin();\n\
    \        D=*t.begin();\n      }\n\n      if(c1<0 and c2<0){\n        print(\"\
    No\");\n        return;\n      }\n\n      {\n        int flg=0;\n        if(~c1){\n\
    \          BS r=rs[A]^rs[B];\n          r>>=c1;\n          int k=r.count();\n\
    \          r>>=(d1-c1+1);\n          k-=r.count();\n          flg|=(d1-c1+1)==k;\n\
    \        }\n        if(~c1){\n          BS r=rs[A]^~rs[B];\n          r>>=c1;\n\
    \          int k=r.count();\n          r>>=(d1-c1+1);\n          k-=r.count();\n\
    \          flg|=(d1-c1+1)==k;\n        }\n        if(~c2){\n          BS r=rs[A]^rs[B];\n\
    \          r>>=c2;\n          int k=r.count();\n          r>>=(d2-c2+1);\n   \
    \       k-=r.count();\n          flg|=(d2-c2+1)==k;\n        }\n        if(~c2){\n\
    \          BS r=rs[A]^~rs[B];\n          r>>=c2;\n          int k=r.count();\n\
    \          r>>=(d2-c2+1);\n          k-=r.count();\n          flg|=(d2-c2+1)==k;\n\
    \        }\n        if(!flg){\n          print(\"No\");\n          return;\n \
    \       }\n      }\n\n      {\n        int flg=0;\n        if(~a1){\n        \
    \  BS r=cs[C]^cs[D];\n          r>>=a1;\n          int k=r.count();\n        \
    \  r>>=(b1-a1+1);\n          k-=r.count();\n          flg|=(b1-a1+1)==k;\n   \
    \     }\n        if(~a1){\n          BS r=cs[C]^~cs[D];\n          r>>=a1;\n \
    \         int k=r.count();\n          r>>=(b1-a1+1);\n          k-=r.count();\n\
    \          flg|=(b1-a1+1)==k;\n        }\n        if(~a2){\n          BS r=cs[C]^cs[D];\n\
    \          r>>=a2;\n          int k=r.count();\n          r>>=(b2-a2+1);\n   \
    \       k-=r.count();\n          flg|=(b2-a2+1)==k;\n        }\n        if(~a2){\n\
    \          BS r=cs[C]^~cs[D];\n          r>>=a2;\n          int k=r.count();\n\
    \          r>>=(b2-a2+1);\n          k-=r.count();\n          flg|=(b2-a2+1)==k;\n\
    \        }\n        if(!flg){\n          print(\"No\");\n          return;\n \
    \       }\n      }\n\n      print(\"Yes\");\n    };\n\n  auto calc=\n    [&](){\n\
    \      if(mrs.size()>2u or mcs.size()>2u){\n        print(\"No\");\n        return;\n\
    \      }\n      if(mrs.size()==1u or mcs.size()==1u){\n        print(\"Yes\");\n\
    \        return;\n      }\n\n      if(mrs.size()==2u or mcs.size()==2u){\n   \
    \     check();\n        return;\n      }\n      print(\"No\");\n    };\n\n  calc();\n\
    \n  for(int i=1;i<q;i++){\n    int r,c;\n    cin>>r>>c;\n    r--;c--;\n\n    mrs[vrs[r]].erase(r);\n\
    \    if(mrs[vrs[r]].empty()) mrs.erase(vrs[r]);\n    mcs[vcs[c]].erase(c);\n \
    \   if(mcs[vcs[c]].empty()) mcs.erase(vcs[c]);\n\n    if(rs[r][0]) vrs[r]=ri-vrs[r];\n\
    \    if(cs[c][0]) vcs[c]=ci-vcs[c];\n\n    if(rs[r][c]){\n      vrs[r]-=ph.term(c,1);\n\
    \      vcs[c]-=ph.term(r,1);\n    }else{\n      vrs[r]+=ph.term(c,1);\n      vcs[c]+=ph.term(r,1);\n\
    \    }\n\n    rs[r][c].flip();\n    cs[c][r].flip();\n\n    if(rs[r][0]) vrs[r]=ri-vrs[r];\n\
    \    if(cs[c][0]) vcs[c]=ci-vcs[c];\n\n    mrs[vrs[r]].emplace(r);\n    mcs[vcs[c]].emplace(c);\n\
    \n    calc();\n  }\n\n  cout<<flush;\n  return 0;\n}\n/*\n  verified on 2019/10/15\n\
    \  https://atcoder.jp/contests/bitflyer2018-final/tasks/bitflyer2018_final_f\n\
    */\n\nusing M1 = Mint<int, int(1e9+7)>;\nusing M2 = Mint<int, int(1e9+9)>;\nusing\
    \ M3 = Mint<int, int(1e8+7)>;\n\nPolynomialHash<int, M1, M2, M3> ph(2000);\nusing\
    \ V = decltype(ph)::V;\n\nstruct Point{\n  V x,y;\n  Point():x(0),y(0){}\n  Point(V\
    \ x,V y):x(x),y(y){}\n};\n\nusing Vector = Point;\n\nPoint getP(){\n  int x,y;\n\
    \  cin>>x>>y;\n  return Point(V((long long)x),V((long long)y));\n}\n\nsigned JAG2018SUMMER_DAY2_F(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n;\n  cin>>n;\n  Point d=getP();\n\
    \n  vector<Point> a(n),b(n),c(n);\n  for(int i=0;i<n;i++){\n    a[i]=getP();\n\
    \    b[i]=getP();\n    c[i]=getP();\n  }\n\n  for(int i=0;i<n;i++){\n    if(c[i].x==d.x\
    \ and c[i].y==d.y) drop(i);\n\n    if(a[i].x==b[i].x and c[i].x==d.x) drop(i);\n\
    \n    if(a[i].x==b[i].x){\n      V nx=a[i].x;\n      V ny=c[i].y;\n      ny+=(nx-c[i].x)/(d.x-c[i].x)*(d.y-c[i].y);\n\
    \      d=Point(nx,ny);\n      continue;\n    }\n\n    if(c[i].x==d.x){\n     \
    \ V nx=c[i].x;\n      V ny=a[i].y;\n      ny+=(nx-a[i].x)/(b[i].x-a[i].x)*(b[i].y-a[i].y);\n\
    \      d=Point(nx,ny);\n      continue;\n    }\n\n    V al=(b[i].y-a[i].y)/(b[i].x-a[i].x);\n\
    \    V bt=(d.y-c[i].y)/(d.x-c[i].x);\n\n    if(al==bt) drop(i);\n\n    V nx=al*a[i].x;\n\
    \    nx-=bt*c[i].x;\n    nx-=a[i].y;\n    nx+=c[i].y;\n    nx/=al-bt;\n\n    V\
    \ ny=al*nx;\n    ny-=al*a[i].x;\n    ny+=a[i].y;\n\n    d=Point(nx,ny);\n  }\n\
    \  cout<<n<<endl;\n  return 0;\n}\n/*\n  verified on 2019/10/15\n  https://atcoder.jp/contests/jag2018summer-day2/tasks/jag2018summer_day2_f\n\
    */\n\n\nsigned main(){\n  //CODEFLYER2018_F();\n  //JAG2018SUMMER_DAY2_F();\n\
    \  return 0;\n}\n#endif\n"
  dependsOn:
  - mod/mint.cpp
  isVerificationFile: false
  path: polynomial/hash.cpp
  requiredBy: []
  timestamp: '2020-10-27 17:58:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1630.test.cpp
  - test/aoj/2971.test.cpp
documentation_of: polynomial/hash.cpp
layout: document
redirect_from:
- /library/polynomial/hash.cpp
- /library/polynomial/hash.cpp.html
title: polynomial/hash.cpp
---
