---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/discrete_logarithm_mod.test.cpp
    title: test/yosupo/discrete_logarithm_mod.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"mod/log.cpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\n// find x s.t. a^x = b (x >= 0)\ntemplate<typename\
    \ T>\nT mod_log(T a,T b,T mod){\n  using ll = long long;\n  ll g=1;\n  {\n   \
    \ ll m=mod;\n    while(m){\n      g=(ll)g*a%mod;\n      m>>=1;\n    }\n  }\n \
    \ g=__gcd(g,(ll)mod);\n  ll c=0,t=1;\n  while(t%g){\n    if(t==b) return c;\n\
    \    t=t*a%mod;\n    c++;\n  }\n  // not found\n  if(b%g) return mod;\n  t/=g;b/=g;\n\
    \  const ll n=mod/g;\n  ll h=0,gs=1;\n  while(h*h<n){\n    gs=gs*a%n;\n    ++h;\n\
    \  }\n  unordered_map<ll, ll> bs;\n  {\n    ll s=0,e=b;\n    while(s<h){\n   \
    \   e=e*a%n;\n      bs[e]=++s;\n    }\n  }\n  {\n    ll s=0,e=t;\n    while(s<n){\n\
    \      e=e*gs%n;\n      s+=h;\n      if(bs.count(e))\n        return c+s-bs[e];\n\
    \    }\n  }\n  // not found\n  return mod;\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\n// find x s.t. a^x = b (x >= 0)\ntemplate<typename T>\nT mod_log(T\
    \ a,T b,T mod){\n  using ll = long long;\n  ll g=1;\n  {\n    ll m=mod;\n    while(m){\n\
    \      g=(ll)g*a%mod;\n      m>>=1;\n    }\n  }\n  g=__gcd(g,(ll)mod);\n  ll c=0,t=1;\n\
    \  while(t%g){\n    if(t==b) return c;\n    t=t*a%mod;\n    c++;\n  }\n  // not\
    \ found\n  if(b%g) return mod;\n  t/=g;b/=g;\n  const ll n=mod/g;\n  ll h=0,gs=1;\n\
    \  while(h*h<n){\n    gs=gs*a%n;\n    ++h;\n  }\n  unordered_map<ll, ll> bs;\n\
    \  {\n    ll s=0,e=b;\n    while(s<h){\n      e=e*a%n;\n      bs[e]=++s;\n   \
    \ }\n  }\n  {\n    ll s=0,e=t;\n    while(s<n){\n      e=e*gs%n;\n      s+=h;\n\
    \      if(bs.count(e))\n        return c+s-bs[e];\n    }\n  }\n  // not found\n\
    \  return mod;\n}\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/log.cpp
  requiredBy: []
  timestamp: '2019-12-26 23:42:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/discrete_logarithm_mod.test.cpp
documentation_of: mod/log.cpp
layout: document
redirect_from:
- /library/mod/log.cpp
- /library/mod/log.cpp.html
title: mod/log.cpp
---
