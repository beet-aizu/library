---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/numbertheoretictransform.cpp
    title: convolution/numbertheoretictransform.cpp
  - icon: ':heavy_check_mark:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: mod/factorial.cpp
    title: mod/factorial.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2985.garner.test.cpp
    title: test/aoj/2985.garner.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod_1000000007.garner.test.cpp
    title: test/yosupo/convolution_mod_1000000007.garner.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1504.test.cpp
    title: test/yukicoder/1504.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ convolution/garner.cpp: line 6: unable to process #include in #if / #ifdef /\
    \ #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../mod/mint.cpp\"\n#include \"numbertheoretictransform.cpp\"\
    \n#undef call_from_test\n\n#endif\n//BEGIN CUT HERE\nstruct Garner{\n  using ll\
    \ = long long;\n  inline static NTT<0> ntt0;\n  inline static NTT<1> ntt1;\n \
    \ inline static NTT<2> ntt2;\n\n  static constexpr int pow(int a,int b,int md){\n\
    \    int res=1;\n    a=a%md;\n    while(b){\n      if(b&1) res=(ll)res*a%md;\n\
    \      a=(ll)a*a%md;\n      b>>=1;\n    }\n    return res;\n  }\n\n  static constexpr\
    \ int inv(int x,int md){\n    return pow(x,md-2,md);\n  }\n\n  inline void garner(int\
    \ &c0,int c1,int c2,int m01,int MOD){\n    static constexpr int r01=inv(ntt0.md,ntt1.md);\n\
    \    static constexpr int r02=inv(ntt0.md,ntt2.md);\n    static constexpr int\
    \ r12=inv(ntt1.md,ntt2.md);\n\n    c1=(ll)(c1-c0)*r01%ntt1.md;\n    if(c1<0) c1+=ntt1.md;\n\
    \n    c2=(ll)(c2-c0)*r02%ntt2.md;\n    c2=(ll)(c2-c1)*r12%ntt2.md;\n    if(c2<0)\
    \ c2+=ntt2.md;\n\n    c0%=MOD;\n    c0+=(ll)c1*ntt0.md%MOD;\n    if(c0>=MOD) c0-=MOD;\n\
    \    c0+=(ll)c2*m01%MOD;\n    if(c0>=MOD) c0-=MOD;\n  }\n\n  inline void garner(vector<\
    \ vector<int> > &cs,int MOD){\n    int m01 =(ll)ntt0.md*ntt1.md%MOD;\n    int\
    \ sz=cs[0].size();\n    for(int i=0;i<sz;i++) garner(cs[0][i],cs[1][i],cs[2][i],m01,MOD);\n\
    \  }\n\n  vector<int> multiply(vector<int> as,vector<int> bs,int MOD){\n    vector<\
    \ vector<int> > cs(3);\n    cs[0]=ntt0.multiply(as,bs);\n    cs[1]=ntt1.multiply(as,bs);\n\
    \    cs[2]=ntt2.multiply(as,bs);\n    size_t sz=as.size()+bs.size()-1;\n    for(auto&\
    \ v:cs) v.resize(sz);\n    garner(cs,MOD);\n    return cs[0];\n  }\n\n  template<typename\
    \ T>\n  decltype(auto) multiply(vector<T> am,\n                          vector<T>\
    \ bm){\n    vector<int> as(am.size()),bs(bm.size());\n    for(int i=0;i<(int)as.size();i++)\
    \ as[i]=am[i].v;\n    for(int i=0;i<(int)bs.size();i++) bs[i]=bm[i].v;\n    vector<int>\
    \ cs=multiply(as,bs,T::mod);\n    vector<T> cm(cs.size());\n    for(int i=0;i<(int)cm.size();i++)\
    \ cm[i]=T(cs[i]);\n    return cm;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - mod/mint.cpp
  - convolution/numbertheoretictransform.cpp
  isVerificationFile: false
  path: convolution/garner.cpp
  requiredBy:
  - mod/factorial.cpp
  timestamp: '2021-03-25 09:46:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1504.test.cpp
  - test/aoj/2985.garner.test.cpp
  - test/yosupo/convolution_mod_1000000007.garner.test.cpp
documentation_of: convolution/garner.cpp
layout: document
redirect_from:
- /library/convolution/garner.cpp
- /library/convolution/garner.cpp.html
title: convolution/garner.cpp
---
