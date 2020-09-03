---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"test/yosupo/discrete_logarithm_mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"mod/log.cpp\"\n\n#line\
    \ 3 \"mod/log.cpp\"\nusing namespace std;\n#endif\n//BEGIN CUT HERE\n// find x\
    \ s.t. a^x = b (x >= 0)\ntemplate<typename T>\nT mod_log(T a,T b,T mod){\n  using\
    \ ll = long long;\n  ll g=1;\n  {\n    ll m=mod;\n    while(m){\n      g=(ll)g*a%mod;\n\
    \      m>>=1;\n    }\n  }\n  g=__gcd(g,(ll)mod);\n  ll c=0,t=1;\n  while(t%g){\n\
    \    if(t==b) return c;\n    t=t*a%mod;\n    c++;\n  }\n  // not found\n  if(b%g)\
    \ return mod;\n  t/=g;b/=g;\n  const ll n=mod/g;\n  ll h=0,gs=1;\n  while(h*h<n){\n\
    \    gs=gs*a%n;\n    ++h;\n  }\n  unordered_map<ll, ll> bs;\n  {\n    ll s=0,e=b;\n\
    \    while(s<h){\n      e=e*a%n;\n      bs[e]=++s;\n    }\n  }\n  {\n    ll s=0,e=t;\n\
    \    while(s<n){\n      e=e*gs%n;\n      s+=h;\n      if(bs.count(e))\n      \
    \  return c+s-bs[e];\n    }\n  }\n  // not found\n  return mod;\n}\n//END CUT\
    \ HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n#line\
    \ 8 \"test/yosupo/discrete_logarithm_mod.test.cpp\"\n#undef call_from_test\n\n\
    signed main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int t;\n  cin>>t;\n\
    \  while(t--){\n    int x,y,m;\n    cin>>x>>y>>m;\n    int l=mod_log(x,y,m);\n\
    \    if(l==m) l=-1;\n    cout<<l<<\"\\n\";\n  }\n  cout<<flush;\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../mod/log.cpp\"\n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n\n  int t;\n  cin>>t;\n  while(t--){\n    int x,y,m;\n\
    \    cin>>x>>y>>m;\n    int l=mod_log(x,y,m);\n    if(l==m) l=-1;\n    cout<<l<<\"\
    \\n\";\n  }\n  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - mod/log.cpp
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/log.cpp
    title: mod/log.cpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: test/yosupo/discrete_logarithm_mod.test.cpp
  requiredBy: []
  timestamp: '2020-03-05 21:02:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: test/yosupo/discrete_logarithm_mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/discrete_logarithm_mod.test.cpp
- /verify/test/yosupo/discrete_logarithm_mod.test.cpp.html
title: test/yosupo/discrete_logarithm_mod.test.cpp
---
