---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/sqrt.cpp
    title: mod/sqrt.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_mod
    links:
    - https://judge.yosupo.jp/problem/sqrt_mod
  bundledCode: "#line 1 \"test/yosupo/sqrt_mod.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/sqrt_mod\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"mod/sqrt.cpp\"\n\n#line\
    \ 3 \"mod/sqrt.cpp\"\nusing namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename\
    \ T>\nint jacobi(T a,T mod){\n  int s=1;\n  if(a<0) a=a%mod+mod;\n  while(mod>1){\n\
    \    a%=mod;\n    if(a==0) return 0;\n    int r=__builtin_ctz(a);\n    if((r&1)&&((mod+2)&4))\
    \ s=-s;\n    a>>=r;\n    if(a&mod&2) s=-s;\n    swap(a,mod);\n  }\n  return s;\n\
    }\n\ntemplate<typename T>\nvector<T> mod_sqrt(T a,T mod){\n  if(mod==2) return\
    \ {a&1};\n  int j=jacobi(a,mod);\n  if(j== 0) return {0};\n  if(j==-1) return\
    \ {};\n\n  using ll = long long;\n  mt19937 mt;\n  ll b,d;\n  while(1){\n    b=mt()%mod;\n\
    \    d=(b*b-a)%mod;\n    if(d<0) d+=mod;\n    if(jacobi<ll>(d,mod)==-1) break;\n\
    \  }\n\n  ll f0=b,f1=1,g0=1,g1=0;\n  for(ll e=(mod+1)>>1;e;e>>=1){\n    if(e&1){\n\
    \      ll tmp=(g0*f0+d*((g1*f1)%mod))%mod;\n      g1=(g0*f1+g1*f0)%mod;\n    \
    \  g0=tmp;\n    }\n    ll tmp=(f0*f0+d*((f1*f1)%mod))%mod;\n    f1=(2*f0*f1)%mod;\n\
    \    f0=tmp;\n  }\n  if(g0>mod-g0) g0=mod-g0;\n  return {T(g0),T(mod-g0)};\n}\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n#line 8 \"test/yosupo/sqrt_mod.test.cpp\"\n#undef call_from_test\n\
    \nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int T;\n  cin>>T;\n\
    \  for(int t=0;t<T;t++){\n    int y,p;\n    cin>>y>>p;\n    auto res=mod_sqrt(y,p);\n\
    \    if(res.empty()) cout<<-1<<\"\\n\";\n    else cout<<res[0]<<\"\\n\";\n  }\n\
    \  cout<<flush;\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/sqrt_mod\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../mod/sqrt.cpp\"\n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n\n  int T;\n  cin>>T;\n  for(int t=0;t<T;t++){\n\
    \    int y,p;\n    cin>>y>>p;\n    auto res=mod_sqrt(y,p);\n    if(res.empty())\
    \ cout<<-1<<\"\\n\";\n    else cout<<res[0]<<\"\\n\";\n  }\n  cout<<flush;\n \
    \ return 0;\n}\n"
  dependsOn:
  - mod/sqrt.cpp
  isVerificationFile: true
  path: test/yosupo/sqrt_mod.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 16:01:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sqrt_mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sqrt_mod.test.cpp
- /verify/test/yosupo/sqrt_mod.test.cpp.html
title: test/yosupo/sqrt_mod.test.cpp
---
