---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_triangles
  bundledCode: "#line 1 \"test/yosupo/enumerate_triangles.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/enumerate_triangles\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 2 \"graph/triangle.cpp\"\
    \n\n#ifndef call_from_test\n#line 5 \"graph/triangle.cpp\"\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\nstruct Triangle{\n  // if not simple, use vector<set<int>>\n\
    \  vector<vector<int>> G;\n  Triangle(int n):G(n){}\n\n  void add_edge(int u,int\
    \ v){\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n  }\n\n  template<typename\
    \ F>\n  void build(F f){\n    int n=G.size();\n    using P = pair<int, int>;\n\
    \    vector<P> vp(n);\n    for(int i=0;i<n;i++) vp[i]=P(G[i].size(),i);\n\n  \
    \  vector<vector<int>> H(n);\n    for(int i=0;i<n;i++)\n      for(int j:G[i])\n\
    \        if(vp[i]>vp[j])\n          H[i].emplace_back(j);\n\n    vector<int> used(n,0);\n\
    \    // x->y->z\n    for(int x=0;x<n;x++){\n      for(int z:H[x]) used[z]=1;\n\
    \      for(int y:H[x])\n        for(int z:H[y])\n          if(used[z]) f(x,y,z);\n\
    \      for(int z:H[x]) used[z]=0;\n    }\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n#line 8 \"test/yosupo/enumerate_triangles.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using ll = long long;\n\n  int n,m;\n  cin>>n>>m;\n  vector<ll> xs(n);\n  for(int\
    \ i=0;i<n;i++) cin>>xs[i];\n\n  Triangle G(n);\n  for(int i=0;i<m;i++){\n    int\
    \ u,v;\n    cin>>u>>v;\n    G.add_edge(u,v);\n  }\n\n  const ll mod = 998244353;\n\
    \  ll ans=0;\n  auto f=[&](int x,int y,int z){\n    ans+=xs[x]*xs[y]%mod*xs[z]%mod;\n\
    \    ans%=mod;\n  };\n  G.build(f);\n\n  cout<<ans<<endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_triangles\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../graph/triangle.cpp\"\n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n  using ll = long long;\n\n  int n,m;\n  cin>>n>>m;\n\
    \  vector<ll> xs(n);\n  for(int i=0;i<n;i++) cin>>xs[i];\n\n  Triangle G(n);\n\
    \  for(int i=0;i<m;i++){\n    int u,v;\n    cin>>u>>v;\n    G.add_edge(u,v);\n\
    \  }\n\n  const ll mod = 998244353;\n  ll ans=0;\n  auto f=[&](int x,int y,int\
    \ z){\n    ans+=xs[x]*xs[y]%mod*xs[z]%mod;\n    ans%=mod;\n  };\n  G.build(f);\n\
    \n  cout<<ans<<endl;\n  return 0;\n}\n"
  dependsOn:
  - graph/triangle.cpp
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/triangle.cpp
    title: graph/triangle.cpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: test/yosupo/enumerate_triangles.test.cpp
  requiredBy: []
  timestamp: '2020-05-07 17:33:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: test/yosupo/enumerate_triangles.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/enumerate_triangles.test.cpp
- /verify/test/yosupo/enumerate_triangles.test.cpp.html
title: test/yosupo/enumerate_triangles.test.cpp
---
