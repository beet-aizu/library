---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/centroid.cpp
    title: tree/centroid.cpp
  - icon: ':heavy_check_mark:'
    path: tools/fixpoint.cpp
    title: tools/fixpoint.cpp
  - icon: ':heavy_check_mark:'
    path: convolution/fastfouriertransform.cpp
    title: convolution/fastfouriertransform.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
  bundledCode: "#line 1 \"test/yosupo/frequency_table_of_tree_distance.test.cpp\"\n\
    // verification-helper: PROBLEM https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#line\
    \ 1 \"tree/centroid.cpp\"\n\n#line 3 \"tree/centroid.cpp\"\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\nstruct Centroid{\n  vector<int> sz,dead;\n  vector<\
    \ vector<int> > G;\n  Centroid(){}\n  Centroid(int n):sz(n,1),dead(n,0),G(n){}\n\
    \n  void add_edge(int u,int v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n\
    \  }\n\n  int dfs(int v,int p){\n    sz[v]=1;\n    for(int u:G[v])\n      if(u!=p&&!dead[u])\
    \ sz[v]+=dfs(u,v);\n    return sz[v];\n  }\n\n  void find(int v,int p,int tmp,vector<int>\
    \ &cs) {\n    int ok=1;\n    for (int u:G[v]){\n      if(u==p||dead[u]) continue;\n\
    \      find(u,v,tmp,cs);\n      ok&=(sz[u]<=tmp/2);\n    }\n    ok&=(tmp-sz[v]<=tmp/2);\n\
    \    if(ok) cs.emplace_back(v);\n  }\n\n  vector<int> build(int r) {\n    int\
    \ tmp=dfs(r,-1);\n    vector<int> cs;\n    find(r,-1,tmp,cs);\n    return cs;\n\
    \  }\n\n  const vector<int>& operator[](int k)const{return G[k];}\n  void disable(int\
    \ v){dead[v]=1;}\n  void  enable(int v){dead[v]=0;}\n  int alive(int v){return\
    \ !dead[v];}\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n#line 1 \"tools/fixpoint.cpp\"\n\n#line 3 \"tools/fixpoint.cpp\"\
    \nusing namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename F>\nstruct\
    \ FixPoint : F{\n  FixPoint(F&& f):F(forward<F>(f)){}\n  template<typename...\
    \ Args>\n  decltype(auto) operator()(Args&&... args) const{\n    return F::operator()(*this,forward<Args>(args)...);\n\
    \  }\n};\ntemplate<typename F>\ninline decltype(auto) MFP(F&& f){\n  return FixPoint<F>{forward<F>(f)};\n\
    }\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n#line 1 \"convolution/fastfouriertransform.cpp\"\n\n\
    #line 3 \"convolution/fastfouriertransform.cpp\"\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nnamespace FFT{\n  using dbl = double;\n\n  struct num{\n   \
    \ dbl x,y;\n    num(){x=y=0;}\n    num(dbl x,dbl y):x(x),y(y){}\n  };\n\n  inline\
    \ num operator+(num a,num b){\n    return num(a.x+b.x,a.y+b.y);\n  }\n  inline\
    \ num operator-(num a,num b){\n    return num(a.x-b.x,a.y-b.y);\n  }\n  inline\
    \ num operator*(num a,num b){\n    return num(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);\n\
    \  }\n  inline num conj(num a){\n    return num(a.x,-a.y);\n  }\n\n  int base=1;\n\
    \  vector<num> rts={{0,0},{1,0}};\n  vector<int> rev={0,1};\n\n  const dbl PI=asinl(1)*2;\n\
    \n  void ensure_base(int nbase){\n    if(nbase<=base) return;\n\n    rev.resize(1<<nbase);\n\
    \    for(int i=0;i<(1<<nbase);i++)\n      rev[i]=(rev[i>>1]>>1)+((i&1)<<(nbase-1));\n\
    \n    rts.resize(1<<nbase);\n    while(base<nbase){\n      dbl angle=2*PI/(1<<(base+1));\n\
    \      for(int i=1<<(base-1);i<(1<<base);i++){\n        rts[i<<1]=rts[i];\n  \
    \      dbl angle_i=angle*(2*i+1-(1<<base));\n        rts[(i<<1)+1]=num(cos(angle_i),sin(angle_i));\n\
    \      }\n      base++;\n    }\n  }\n\n  void fft(vector<num> &as){\n    int n=as.size();\n\
    \    assert((n&(n-1))==0);\n\n    int zeros=__builtin_ctz(n);\n    ensure_base(zeros);\n\
    \    int shift=base-zeros;\n    for(int i=0;i<n;i++)\n      if(i<(rev[i]>>shift))\n\
    \        swap(as[i],as[rev[i]>>shift]);\n\n    for(int k=1;k<n;k<<=1){\n     \
    \ for(int i=0;i<n;i+=2*k){\n        for(int j=0;j<k;j++){\n          num z=as[i+j+k]*rts[j+k];\n\
    \          as[i+j+k]=as[i+j]-z;\n          as[i+j]=as[i+j]+z;\n        }\n   \
    \   }\n    }\n  }\n\n  template<typename T>\n  vector<long long> multiply(vector<T>\
    \ &as,vector<T> &bs){\n    int need=as.size()+bs.size()-1;\n    int nbase=0;\n\
    \    while((1<<nbase)<need) nbase++;\n    ensure_base(nbase);\n\n    int sz=1<<nbase;\n\
    \    vector<num> fa(sz);\n    for(int i=0;i<sz;i++){\n      T x=(i<(int)as.size()?as[i]:0);\n\
    \      T y=(i<(int)bs.size()?bs[i]:0);\n      fa[i]=num(x,y);\n    }\n    fft(fa);\n\
    \n    num r(0,-0.25/sz);\n    for(int i=0;i<=(sz>>1);i++){\n      int j=(sz-i)&(sz-1);\n\
    \      num z=(fa[j]*fa[j]-conj(fa[i]*fa[i]))*r;\n      if(i!=j)\n        fa[j]=(fa[i]*fa[i]-conj(fa[j]*fa[j]))*r;\n\
    \      fa[i]=z;\n    }\n    fft(fa);\n\n    vector<long long> res(need);\n   \
    \ for(int i=0;i<need;i++)\n      res[i]=round(fa[i].x);\n\n    return res;\n \
    \ }\n\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n\
    }\n#endif\n#line 10 \"test/yosupo/frequency_table_of_tree_distance.test.cpp\"\n\
    #undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n;\n  cin>>n;\n  Centroid G(n);\n  for(int i=1;i<n;i++){\n    int a,b;\n\
    \    cin>>a>>b;\n    G.add_edge(a,b);\n  }\n\n  queue<int> que;\n  que.emplace(G.build(0)[0]);\n\
    \n  using ll = long long;\n  vector<ll> ans(n,0);\n  while(!que.empty()){\n  \
    \  int r=que.front();que.pop();\n\n    vector<ll> cnt;\n    cnt.emplace_back(1);\n\
    \    for(int c:G[r]){\n      if(!G.alive(c)) continue;\n      vector<ll> num;\n\
    \      MFP([&](auto dfs,int v,int p,int d)->void{\n        while((int)cnt.size()<=d)\n\
    \          cnt.emplace_back(0);\n        while((int)num.size()<=d)\n         \
    \ num.emplace_back(0);\n        cnt[d]++;\n        num[d]++;\n        for(int\
    \ u:G[v]){\n          if(u==p or !G.alive(u)) continue;\n          dfs(u,v,d+1);\n\
    \        }\n      })(c,r,1);\n      auto ns=FFT::multiply(num,num);\n      for(int\
    \ i=0;i<(int)ns.size();i++) ans[i]-=ns[i];\n    }\n    auto cs=FFT::multiply(cnt,cnt);\n\
    \    for(int i=0;i<(int)cs.size();i++) ans[i]+=cs[i];\n\n    G.disable(r);\n \
    \   for(int c:G[r])\n      if(G.alive(c))\n        que.emplace(G.build(c)[0]);\n\
    \  }\n\n  for(int i=1;i<n;i++){\n    if(i!=1) cout<<' ';\n    cout<<ans[i]/2;\n\
    \  }\n  cout<<endl;\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../tree/centroid.cpp\"\n#include \"../../tools/fixpoint.cpp\"\n#include\
    \ \"../../convolution/fastfouriertransform.cpp\"\n#undef call_from_test\n\nsigned\
    \ main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n;\n  cin>>n;\n\
    \  Centroid G(n);\n  for(int i=1;i<n;i++){\n    int a,b;\n    cin>>a>>b;\n   \
    \ G.add_edge(a,b);\n  }\n\n  queue<int> que;\n  que.emplace(G.build(0)[0]);\n\n\
    \  using ll = long long;\n  vector<ll> ans(n,0);\n  while(!que.empty()){\n   \
    \ int r=que.front();que.pop();\n\n    vector<ll> cnt;\n    cnt.emplace_back(1);\n\
    \    for(int c:G[r]){\n      if(!G.alive(c)) continue;\n      vector<ll> num;\n\
    \      MFP([&](auto dfs,int v,int p,int d)->void{\n        while((int)cnt.size()<=d)\n\
    \          cnt.emplace_back(0);\n        while((int)num.size()<=d)\n         \
    \ num.emplace_back(0);\n        cnt[d]++;\n        num[d]++;\n        for(int\
    \ u:G[v]){\n          if(u==p or !G.alive(u)) continue;\n          dfs(u,v,d+1);\n\
    \        }\n      })(c,r,1);\n      auto ns=FFT::multiply(num,num);\n      for(int\
    \ i=0;i<(int)ns.size();i++) ans[i]-=ns[i];\n    }\n    auto cs=FFT::multiply(cnt,cnt);\n\
    \    for(int i=0;i<(int)cs.size();i++) ans[i]+=cs[i];\n\n    G.disable(r);\n \
    \   for(int c:G[r])\n      if(G.alive(c))\n        que.emplace(G.build(c)[0]);\n\
    \  }\n\n  for(int i=1;i<n;i++){\n    if(i!=1) cout<<' ';\n    cout<<ans[i]/2;\n\
    \  }\n  cout<<endl;\n  return 0;\n}\n"
  dependsOn:
  - tree/centroid.cpp
  - tools/fixpoint.cpp
  - convolution/fastfouriertransform.cpp
  isVerificationFile: true
  path: test/yosupo/frequency_table_of_tree_distance.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 15:33:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/frequency_table_of_tree_distance.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/frequency_table_of_tree_distance.test.cpp
- /verify/test/yosupo/frequency_table_of_tree_distance.test.cpp.html
title: test/yosupo/frequency_table_of_tree_distance.test.cpp
---
