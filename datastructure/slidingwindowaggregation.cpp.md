---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/fastio.cpp
    title: tools/fastio.cpp
  - icon: ':heavy_check_mark:'
    path: tools/chminmax.cpp
    title: tools/chminmax.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_3_D.slidingwindowaggregation.test.cpp
    title: test/aoj/DSL_3_D.slidingwindowaggregation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/queue_operate_all_composite.test.cpp
    title: test/yosupo/queue_operate_all_composite.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://atcoder.jp/contests/jag2018summer-day2/tasks/jag2018summer_day2_d
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/slidingwindowaggregation.cpp: line 47: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename T,typename S>\nstruct SWAG{\n  using F1 =\
    \ function<S(S,T)>;\n  using F2 = function<S(T,S)>;\n  const F1 f1;\n  const F2\
    \ f2;\n  S id;\n  vector<T> lt,rt;\n  vector<S> ls,rs;\n  SWAG(F1 f1,F2 f2,S id):f1(f1),f2(f2),id(id),ls(1,id),rs(1,id){}\n\
    \n  // S, T identical / commutative is not required\n  SWAG(F1 f1,S id):f1(f1),f2([&](T\
    \ y,S x){return f1(y,x);}),\n                   id(id),ls(1,id),rs(1,id){}\n\n\
    \  void push(T x){\n    rt.emplace_back(x);\n    rs.emplace_back(f1(rs.back(),x));\n\
    \  }\n\n  void pop(){\n    if(lt.empty()){\n      reverse(rt.begin(),rt.end());\n\
    \      for(auto x:rt){\n        lt.emplace_back(x);\n        ls.emplace_back(f2(x,ls.back()));\n\
    \      }\n      rt.resize(0);\n      rs.resize(1);\n    }\n    lt.pop_back();\n\
    \    ls.pop_back();\n  }\n\n  template<typename Q>\n  void fold(Q q){q(ls.back(),rs.back());}\n\
    };\n//END CUT HERE\n#ifndef call_from_test\n\n#define call_from_test\n#include\
    \ \"../tools/fastio.cpp\"\n#include \"../tools/chminmax.cpp\"\n#undef call_from_test\n\
    \n//INSERT ABOVE HERE\n\nclass Crypto {\npublic:\n  Crypto() {\n    sm = cnt =\
    \ 0;\n    seed();\n  }\n\n  int decode(int z) {\n    z ^= next();\n    z ^= (next()\
    \ << 8);\n    z ^= (next() << 16);\n    z ^= (next() << 22);\n    return z;\n\
    \  }\n\n  void query(long long z) {\n    const long long B = 425481007;\n    const\
    \ long long MD = 1000000007;\n    cnt++;\n    sm = ((sm * B % MD + z) % MD + MD)\
    \ % MD;\n    seed();\n  }\nprivate:\n  long long sm;\n  int cnt;\n\n  uint8_t\
    \ data[256];\n  int I, J;\n\n  void swap_data(int i, int j) {\n    uint8_t tmp\
    \ = data[i];\n    data[i] = data[j];\n    data[j] = tmp;\n  }\n\n  void seed()\
    \ {\n    uint8_t key[8];\n    for (int i = 0; i < 4; i++) {\n      key[i] = (sm\
    \ >> (i * 8));\n    }\n    for (int i = 0; i < 4; i++) {\n      key[i+4] = (cnt\
    \ >> (i * 8));\n    }\n\n    for (int i = 0; i < 256; i++) {\n      data[i] =\
    \ i;\n    }\n    I = J = 0;\n\n    int j = 0;\n    for (int i = 0; i < 256; i++)\
    \ {\n      j = (j + data[i] + key[i%8]) % 256;\n      swap_data(i, j);\n    }\n\
    \  }\n\n  uint8_t next() {\n    I = (I+1) % 256;\n    J = (J + data[I]) % 256;\n\
    \    swap_data(I, J);\n    return data[(data[I] + data[J]) % 256];\n  }\n};\n\n\
    signed JAG2018_DAY2_D(){\n  int MOD;\n  cin>>MOD;\n  int q;\n  cin>>q;\n  Crypto\
    \ c;\n\n  using ll = long long;\n  const ll INF = 1e18;\n  using T = pair<ll,\
    \ ll>;\n  using S = array<ll, 512>;\n  auto f1=\n    [&](S x,T y){\n      S z(x);\n\
    \      for(int i=0;i<MOD;i++){\n        int j=(i+y.first)%MOD;\n        chmax(z[j],x[i]+y.second);\n\
    \      }\n      return z;\n    };\n  auto f2=\n    [&](T y,S x){\n      return\
    \ f1(x,y);\n    };\n\n  S id;\n  fill(id.begin(),id.end(),-INF);\n  id[0]=0;\n\
    \n  SWAG<T, S> swag(f1,f2,id);\n\n  for(int i=0;i<q;i++){\n    int t,w,v,l,r;\n\
    \    cin>>t>>w>>v>>l>>r;\n    t = c.decode(t);\n    w = c.decode(w);\n    v =\
    \ c.decode(v);\n    l = c.decode(l);\n    r = c.decode(r);\n    if(t == 1) swag.push(T(w,v));\n\
    \    else swag.pop();\n\n    r++;\n    auto ask=\n      [&](S x,S y){\n      \
    \  SWAG<ll, ll> rmq([](ll a,ll b){return max(a,b);},-INF);\n        for(int i=0;i<r;i++)\
    \ rmq.push(x[i]);\n        for(int i=0;i<l;i++) rmq.pop();\n\n        ll ans=-1;\n\
    \        for(int i=MOD;i>0;i--){\n          rmq.fold([&](ll a,ll b){chmax(ans,max(a,b)+y[i%MOD]);});\n\
    \          rmq.push(x[(r+(MOD-i))%MOD]);\n          rmq.pop();\n        }\n  \
    \      c.query(ans);\n        cout<<ans<<\"\\n\";\n      };\n    swag.fold(ask);\n\
    \  }\n  return 0;\n}\n/*\n  verified on 2019/12/28\n  https://atcoder.jp/contests/jag2018summer-day2/tasks/jag2018summer_day2_d\n\
    */\n\nsigned main(){\n  JAG2018_DAY2_D();\n  return 0;\n}\n#endif\n"
  dependsOn:
  - tools/fastio.cpp
  - tools/chminmax.cpp
  isVerificationFile: false
  path: datastructure/slidingwindowaggregation.cpp
  requiredBy: []
  timestamp: '2020-05-07 20:09:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_3_D.slidingwindowaggregation.test.cpp
  - test/yosupo/queue_operate_all_composite.test.cpp
documentation_of: datastructure/slidingwindowaggregation.cpp
layout: document
redirect_from:
- /library/datastructure/slidingwindowaggregation.cpp
- /library/datastructure/slidingwindowaggregation.cpp.html
title: datastructure/slidingwindowaggregation.cpp
---
