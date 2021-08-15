---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  - icon: ':heavy_check_mark:'
    path: datastructure/unionfind.cpp
    title: datastructure/unionfind.cpp
  - icon: ':question:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_A.test.cpp
    title: test/aoj/GRL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_B.test.cpp
    title: test/aoj/GRL_3_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/arc045/tasks/arc045_d
    - https://atcoder.jp/contests/arc062/tasks/arc062_d
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/lowlink.cpp: line 110: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\nstruct LowLink{\n  int n,pos;\n  vector<int> ord,low,par,blg,num;\n\
    \  vector<vector<int> > G,C,T;\n  vector<vector<pair<int, int> > > E;\n\n  vector<int>\
    \ ap;\n  vector<pair<int, int> > bs,cand;\n\n  LowLink(int n):n(n),pos(0),ord(n,-1),low(n),\n\
    \                 par(n,-1),blg(n,-1),num(n,1),G(n){}\n\n  void add_edge(int u,int\
    \ v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n  }\n\n  bool is_bridge(int\
    \ u,int v){\n    if(ord[u]>ord[v]) swap(u,v);\n    return ord[u]<low[v];\n  }\n\
    \n  void dfs(int v){\n    ord[v]=low[v]=pos++;\n    int dup=0;\n    for(int u:G[v]){\n\
    \      if(u==par[v]){\n        if(dup) low[v]=min(low[v],ord[u]);\n        dup=1;\n\
    \        continue;\n      }\n      if(ord[u]<ord[v])\n        cand.emplace_back(min(u,v),max(u,v));\n\
    \      if(~ord[u]){\n        low[v]=min(low[v],ord[u]);\n        continue;\n \
    \     }\n      par[u]=v;\n      dfs(u);\n      num[v]+=num[u];\n      low[v]=min(low[v],low[u]);\n\
    \      if(is_bridge(u,v)) bs.emplace_back(u,v);\n      if(low[u]>=ord[v]){\n \
    \       E.emplace_back();\n        while(1){\n          auto e=cand.back();\n\
    \          cand.pop_back();\n          E.back().emplace_back(e);\n          if(make_pair(min(u,v),max(u,v))==e)\
    \ break;\n        }\n      }\n    }\n  }\n\n  void fill_component(int v){\n  \
    \  C[blg[v]].emplace_back(v);\n    for(int u:G[v]){\n      if(~blg[u] or is_bridge(u,v))\
    \ continue;\n      blg[u]=blg[v];\n      fill_component(u);\n    }\n  }\n\n  void\
    \ add_component(int v,int &k){\n    if(~blg[v]) return;\n    blg[v]=k++;\n   \
    \ C.emplace_back();\n    fill_component(v);\n  }\n\n  int build(){\n    for(int\
    \ i=0;i<n;i++)\n      if(ord[i]<0) dfs(i);\n\n    vector<int> cnt(n,0);\n    for(int\
    \ i=0;i<n;i++){\n      int p=par[i];\n      if(p<0) continue;\n      if(par[p]<0)\
    \ cnt[p]++;\n      else if(ord[p]<=low[i]) ap.emplace_back(p);\n    }\n\n    for(int\
    \ i=0;i<n;i++)\n      if(cnt[i]>1) ap.emplace_back(i);\n\n    sort(ap.begin(),ap.end());\n\
    \    ap.erase(unique(ap.begin(),ap.end()),ap.end());\n\n    int k=0;\n    for(int\
    \ i=0;i<n;i++) add_component(i,k);\n\n    T.assign(k,vector<int>());\n    for(auto\
    \ e:bs){\n      int u=blg[e.first],v=blg[e.second];\n      T[u].emplace_back(v);\n\
    \      T[v].emplace_back(u);\n    }\n    return k;\n  }\n};\n//END CUT HERE\n\
    #ifndef call_from_test\n\n#define call_from_test\n#include \"../datastructure/unionfind.cpp\"\
    \n#include \"../mod/mint.cpp\"\n#include \"../combinatorics/enumeration.cpp\"\n\
    #undef call_from_test\n\n\n//INSERT ABOVE HERE\n// test num\nsigned ARC045_D(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n;\n  cin>>n;\n  vector<int>\
    \ xs(2*n+1),ys(2*n+1);\n  for(int i=0;i<2*n+1;i++) cin>>xs[i]>>ys[i];\n\n  vector<vector<int>\
    \ > R(2*n+2),C(2*n+2);\n  for(int i=0;i<2*n+1;i++) R[xs[i]].emplace_back(i);\n\
    \  for(int i=0;i<2*n+1;i++) C[ys[i]].emplace_back(i);\n\n  UnionFind uf(2*n+1);\n\
    \  for(auto &v:R)\n    for(auto u:v) uf.unite(v[0],u);\n  for(auto &v:C)\n   \
    \ for(auto u:v) uf.unite(v[0],u);\n\n  vector<int> vs;\n  for(int i=0;i<2*n+1;i++){\n\
    \    if(uf.find(i)!=i) continue;\n    if(uf.size(i)&1) vs.emplace_back(i);\n \
    \ }\n  assert(!vs.empty());\n\n  if(vs.size()>1u){\n    for(int i=0;i<2*n+1;i++)\
    \ cout<<\"NG\\n\";\n    cout<<flush;\n    return 0;\n  }\n\n  LowLink G(2*n+1);\n\
    \  auto add_edge=\n    [&](auto &V)->void{\n      for(auto &v:V){\n        if(v.empty())\
    \ continue;\n        if(!uf.same(vs[0],v[0])) continue;\n        if(v.size()>0u)\
    \ for(auto u:v) G.add_edge(v[0],u);\n        if(v.size()>1u) for(auto u:v) G.add_edge(v[1],u);\n\
    \      }\n    };\n  add_edge(R);\n  add_edge(C);\n\n  G.build();\n  auto ap=G.ap;\n\
    \n  vector<int> ans(2*n+1,0);\n  for(int i=0;i<2*n+1;i++)\n    if(uf.same(vs[0],i))\
    \ ans[i]=1;\n\n  for(int v:ap){\n    if(!uf.same(vs[0],v)) continue;\n    for(int\
    \ u:G.G[v]){\n      if(G.par[u]!=v) continue;\n      if(~G.par[v] and G.ord[v]>G.low[u])\
    \ continue;\n      if(G.num[u]&1) ans[v]=0;\n    }\n  }\n\n  for(int i=0;i<2*n+1;i++)\
    \ cout<<(ans[i]?\"OK\\n\":\"NG\\n\");\n  cout<<flush;\n  return 0;\n}\n/*\n  verified\
    \ on 2019/10/25\n  https://atcoder.jp/contests/arc045/tasks/arc045_d\n*/\n\n\n\
    signed ARC062_F(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,m,k;\n\
    \  cin>>n>>m>>k;\n\n  using P = pair<int, int>;\n  map<P, int> idx;\n\n  LowLink\
    \ G(n);\n  for(int i=0;i<m;i++){\n    int a,b;\n    cin>>a>>b;\n    a--;b--;\n\
    \    G.add_edge(a,b);\n    idx[P(a,b)]=idx[P(b,a)]=i;\n  }\n\n  G.build();\n\n\
    \  UnionFind uf(m);\n  for(auto vs:G.E)\n    for(auto p:vs) uf.unite(idx[p],idx[vs[0]]);\n\
    \n  vector<set<int>> cnt(m);\n  for(auto vs:G.E){\n    for(auto p:vs){\n     \
    \ cnt[uf.find(idx[p])].emplace(p.first);\n      cnt[uf.find(idx[p])].emplace(p.second);\n\
    \    }\n  }\n\n  using M = Mint<int>;\n  using E = Enumeration<M>;\n  E::init(1000);\n\
    \n  auto calc1=\n    [&](int x)->M{\n      M res{0};\n\n      for(int i=0;i<x;i++)\n\
    \        res+=M(k).pow(__gcd(i,x));\n\n      res*=E::Invs(x);\n      return res;\n\
    \    };\n\n  M ans{1};\n  for(int i=0;i<m;i++){\n    if(uf.find(i)!=i) continue;\n\
    \    if(uf.size(i)< (int)cnt[i].size()) ans*=M(k).pow(uf.size(i));\n    if(uf.size(i)==(int)cnt[i].size())\
    \ ans*=calc1(uf.size(i));\n    if(uf.size(i)> (int)cnt[i].size()) ans*=E::H(uf.size(i),k);\n\
    \  }\n  cout<<ans.v<<endl;\n  return 0;\n}\n/*\n  verified on 2020/02/19\n  https://atcoder.jp/contests/arc062/tasks/arc062_d\n\
    */\n\n\nsigned main(){\n  //ARC045_D();\n  //ARC062_F();\n  return 0;\n}\n#endif\n"
  dependsOn:
  - datastructure/unionfind.cpp
  - mod/mint.cpp
  - combinatorics/enumeration.cpp
  isVerificationFile: false
  path: graph/lowlink.cpp
  requiredBy: []
  timestamp: '2021-03-25 09:46:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_3_A.test.cpp
  - test/aoj/GRL_3_B.test.cpp
documentation_of: graph/lowlink.cpp
layout: document
redirect_from:
- /library/graph/lowlink.cpp
- /library/graph/lowlink.cpp.html
title: graph/lowlink.cpp
---
