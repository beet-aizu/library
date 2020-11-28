---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/fastio.cpp
    title: tools/fastio.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_A.test.cpp
    title: test/aoj/GRL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/tree_diameter.test.cpp
    title: test/yosupo/tree_diameter.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/yahoo-procon2019-final/tasks/yahoo_procon2019_final_b
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ tree/diameterforedge.cpp: line 64: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename T>\nstruct DiameterForEdge{\n  using Edge\
    \ = pair<int, T>;\n  vector<T> dp,ps;\n  vector<vector<Edge> > G;\n  DiameterForEdge(int\
    \ n):dp(n),ps(n),G(n){}\n  void add_edge(int u,int v,T c){\n    G[u].emplace_back(v,c);\n\
    \    G[v].emplace_back(u,c);\n  }\n  void dfs(int v,int p,int &s){\n    ps[v]=p;\n\
    \    if(p<0) dp[v]=T(0);\n    if(dp[s]<dp[v]) s=v;\n    for(Edge e:G[v]){\n  \
    \    int u=e.first;\n      if(u==p) continue;\n      dp[u]=dp[v]+e.second;\n \
    \     dfs(u,v,s);\n    }\n  }\n  pair<int, int> endPoints(){\n    int s=0;\n \
    \   dfs(s,-1,s);\n    int t=s;\n    dfs(t,-1,t);\n    return make_pair(s,t);\n\
    \  }\n  T build(){\n    int t=endPoints().second;\n    return dp[t];\n  }\n  vector<int>\
    \ restore(){\n    int t=endPoints().second;\n    vector<int> seq;\n    while(~t){\n\
    \      seq.emplace_back(t);\n      t=ps[t];\n    }\n    return seq;\n  }\n  vector<T>\
    \ distance(int v){\n    dfs(v,-1,v);\n    return dp;\n  }\n  vector<T> farthest(){\n\
    \    int t=endPoints().second;\n    auto ds=dp;\n    auto dt=distance(t);\n  \
    \  for(int i=0;i<(int)ds.size();i++)\n      if(ds[i]<dt[i]) ds[i]=dt[i];\n   \
    \ return ds;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\n#define call_from_test\n\
    #include \"../tools/fastio.cpp\"\n#undef call_from_test\n\n// test farthest\n\
    signed YAHOO2019_FINAL_B(){\n  int n;\n  cin>>n;\n  DiameterForEdge<int> G(n);\n\
    \  for(int i=1;i<n;i++){\n    int x,y;\n    cin>>x>>y;\n    x--;y--;\n    G.add_edge(x,y,1);\n\
    \  }\n\n  int m;\n  cin>>m;\n  DiameterForEdge<int> H(m);\n  for(int i=1;i<m;i++){\n\
    \    int x,y;\n    cin>>x>>y;\n    x--;y--;\n    H.add_edge(x,y,1);\n  }\n\n \
    \ auto dp1=G.farthest();\n  auto dp2=H.farthest();\n  sort(dp1.begin(),dp1.end());\n\
    \  sort(dp2.begin(),dp2.end());\n\n  using ll = long long;\n  vector<ll> s(m+1,0);\n\
    \  for(int i=0;i<m;i++) s[i+1]=s[i]+dp2[i];\n\n  ll ans=0;\n  ll di=max(dp1.back(),dp2.back());\n\
    \n  for(ll x:dp1){\n    ll y=lower_bound(dp2.begin(),dp2.end(),di-(x+1))-dp2.begin();\n\
    \    ans+=di*y;\n    ans+=(s[m]-s[y])+(m-y)*(x+1);\n  }\n\n  cout<<ans<<endl;\n\
    \  return 0;\n}\n/*\n  verified on 2019/12/17\n  https://atcoder.jp/contests/yahoo-procon2019-final/tasks/yahoo_procon2019_final_b\n\
    */\n\nsigned main(){\n  //YAHOO2019_FINAL_B();\n  return 0;\n}\n#endif\n"
  dependsOn:
  - tools/fastio.cpp
  isVerificationFile: false
  path: tree/diameterforedge.cpp
  requiredBy: []
  timestamp: '2020-10-27 12:29:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_5_A.test.cpp
  - test/yosupo/tree_diameter.test.cpp
documentation_of: tree/diameterforedge.cpp
layout: document
redirect_from:
- /library/tree/diameterforedge.cpp
- /library/tree/diameterforedge.cpp.html
title: tree/diameterforedge.cpp
---
