---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segtree/basic/ushi.cpp
    title: segtree/basic/ushi.cpp
  - icon: ':heavy_check_mark:'
    path: tools/chminmax.cpp
    title: tools/chminmax.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ segtree/2d/ushi.cpp: line 103: unable to process #include in #if / #ifdef /\
    \ #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename SegmentTree>\nstruct SegmentTree2D{\n\
    \  using F = typename SegmentTree::F;\n  using T = typename F::result_type;\n\
    \  const F f;\n  const T ti;\n  SegmentTree2D(F f_,T ti_):f(f_),ti(ti_){}\n\n\
    \  vector<pair<int, int>> vp;\n  void preupdate(int p,int q){\n    vp.emplace_back(p,q);\n\
    \  }\n\n  void compress(vector<int> &vs){\n    sort(vs.begin(),vs.end());\n  \
    \  vs.erase(unique(vs.begin(),vs.end()),vs.end());\n  }\n\n  int idx(int v,const\
    \ vector<int> &vs){\n    return lower_bound(vs.begin(),vs.end(),v)-vs.begin();\n\
    \  }\n\n  int sz;\n  vector<int> ps;\n  vector<vector<int>> I,L,R;\n  vector<SegmentTree>\
    \ seg;\n  void build(){\n    for(auto[p,q]:vp) ps.emplace_back(p);\n    compress(ps);\n\
    \n    sz=1;\n    while(sz<(int)ps.size()) sz<<=1;\n\n    I.resize(sz<<1);\n  \
    \  for(auto[p,q]:vp) I[sz+idx(p,ps)].emplace_back(q);\n    for(int k=(int)I.size()-1;k>=sz;k--)\
    \ compress(I[k]);\n\n    L.resize(sz);\n    R.resize(sz);\n    for(int k=sz-1;k>0;k--){\n\
    \      auto& cur=I[k],lft=I[(k<<1)|0],rgh=I[(k<<1)|1];\n      cur.resize(lft.size()+rgh.size());\n\
    \      merge(lft.begin(),lft.end(),rgh.begin(),rgh.end(),cur.begin());\n     \
    \ cur.erase(unique(cur.begin(),cur.end()),cur.end());\n      L[k].resize(cur.size()+1);\n\
    \      R[k].resize(cur.size()+1);\n      int tl=0,tr=0;\n      for(int i=0;i<(int)cur.size();i++){\n\
    \        while(tl<(int)lft.size() and lft[tl]<cur[i]) tl++;\n        while(tr<(int)rgh.size()\
    \ and rgh[tr]<cur[i]) tr++;\n        L[k][i]=tl;R[k][i]=tr;\n      }\n      L[k][cur.size()]=lft.size();\n\
    \      R[k][cur.size()]=rgh.size();\n    }\n    for(int k=0;k<(int)I.size();k++){\n\
    \      seg.emplace_back(f,ti);\n      seg.back().build(vector<T>(I[k].size(),ti));\n\
    \    }\n  }\n\n  void update(int p,int q,T v,int k,int l,int r){\n    if(r<=p||p+1<=l)\
    \ return;\n    if(p<=l&&r<=p+1) return seg[k].set_val(q,v);\n    int m=(l+r)>>1;\n\
    \    update(p,L[k][q],v,(k<<1)|0,l,m);\n    update(p,R[k][q],v,(k<<1)|1,m,r);\n\
    \    T res=ti;\n    const auto& cur=I[k],lft=I[(k<<1)|0],rgh=I[(k<<1)|1];\n  \
    \  if(L[k][q]<(int)lft.size() and cur[q]==lft[L[k][q]])\n      res=f(res,seg[(k<<1)|0].query(L[k][q],L[k][q]+1));\n\
    \    if(R[k][q]<(int)rgh.size() and cur[q]==rgh[R[k][q]])\n      res=f(res,seg[(k<<1)|1].query(R[k][q],R[k][q]+1));\n\
    \    seg[k].set_val(q,res);\n  }\n\n  void update(int p,int q,T v){\n    update(idx(p,ps),idx(q,I[1]),v,1,0,sz);\n\
    \  }\n\n  T query(int pa,int pb,int qa,int qb,int k,int l,int r){\n    if(r<=pa||pb<=l)\
    \ return ti;\n    if(pa<=l&&r<=pb) return seg[k].query(qa,qb);\n    int m=(l+r)>>1;\n\
    \    return f(query(pa,pb,L[k][qa],L[k][qb],(k<<1)|0,l,m),\n             query(pa,pb,R[k][qa],R[k][qb],(k<<1)|1,m,r));\n\
    \  }\n\n  // [pa, pb) x [qa, qb)\n  T query(int pa,int pb,int qa,int qb){\n  \
    \  return query(idx(pa,ps),idx(pb,ps),idx(qa,I[1]),idx(qb,I[1]),1,0,sz);\n  }\n\
    };\n//END CUT HERE\n#ifndef call_from_test\n\n#define call_from_test\n#include\
    \ \"../basic/ushi.cpp\"\n#include \"../../tools/chminmax.cpp\"\n#undef call_from_test\n\
    \nsigned ACPC2021DAY2_H(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int\
    \ n,m;\n  cin>>n>>m;\n  map<pair<int, int>, int> mp;\n  for(int i=0;i<m;i++){\n\
    \    int y,x,a;\n    cin>>y>>x>>a;\n    mp[{y,x}]=a;\n  }\n\n  const int INF =\
    \ 1e9+7;\n  using P = pair<int, int>;\n  auto f1=[&](int a,int b){return min(a,b);};\n\
    \  auto f2=[&](int a,int b){return a+b;};\n  auto f=[&](P a,P b){return P(f1(a.first,b.first),f2(a.second,b.second));};\n\
    \n  SegmentTree2D<SegmentTree<P>> seg(f,P(INF,0));\n\n  for(auto[pos,a]:mp){\n\
    \    auto[y,x]=pos;\n    seg.preupdate(y,x);\n  }\n  seg.build();\n\n  for(auto[pos,a]:mp){\n\
    \    auto[y,x]=pos;\n    seg.update(y,x,P(a,1));\n  }\n\n  int q;\n  cin>>q;\n\
    \  for(int i=0;i<q;i++){\n    using ll = long long;\n    ll u,d,l,r;\n    cin>>u>>d>>l>>r;\n\
    \    d++;r++;\n    P res=seg.query(u,d,l,r);\n    ll num=(d-u)*(r-l);\n    if(res.second<num)\
    \ chmin(res.first,0);\n    cout<<res.first<<'\\n';\n  }\n  return 0;\n}\n\nsigned\
    \ main(){\n  ACPC2021DAY2_H();\n  return 0;\n}\n#endif\n"
  dependsOn:
  - segtree/basic/ushi.cpp
  - tools/chminmax.cpp
  isVerificationFile: false
  path: segtree/2d/ushi.cpp
  requiredBy: []
  timestamp: '2021-09-26 13:21:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segtree/2d/ushi.cpp
layout: document
redirect_from:
- /library/segtree/2d/ushi.cpp
- /library/segtree/2d/ushi.cpp.html
title: segtree/2d/ushi.cpp
---
