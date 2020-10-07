---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0168.test.cpp
    title: test/aoj/0168.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0104.test.cpp
    title: test/yukicoder/0104.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1973.test.cpp
    title: test/yukicoder/1973.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc009/tasks/abc009_4
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/kitamasa.cpp: line 49: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename R>\nstruct Kitamasa{\n  using VR = vector<R>;\n\
    \  VR cs;\n  vector<VR> rs;\n  int m;\n\n  Kitamasa(const VR &C)\n    :cs(C),rs(1),m(C.size()){\n\
    \    rs[0].assign(2*m+1,R::add_identity());\n    rs[0][1]=R::mul_identity();\n\
    \  }\n\n  VR merge(const VR &xs,const VR &ys){\n    VR zs(2*m+1,R::add_identity());\n\
    \    for(int i=1;i<=m;i++)\n      for(int j=1;j<=m;j++)\n        zs[i+j]=zs[i+j]+(xs[i]*ys[j]);\n\
    \n    for(int i=2*m;i>m;zs[i--]=R::add_identity())\n      for(int j=1;j<=m;j++)\n\
    \        zs[i-j]=zs[i-j]+(cs[m-j]*zs[i]);\n    return zs;\n  }\n\n  R calc(const\
    \ VR &A,long long n){\n    assert((int)A.size()==m);\n    VR res(rs[0]);\n   \
    \ for(int i=0;n;i++,n>>=1){\n      if(i>=(int)rs.size())\n        rs.emplace_back(merge(rs[i-1],rs[i-1]));\n\
    \      if(~n&1) continue;\n      res=merge(res,rs[i]);\n    }\n    R ans=R::add_identity();\n\
    \    for(int i=1;i<=m;i++) ans=ans+(res[i]*A[i-1]);\n    return ans;\n  }\n};\n\
    //END CUT HERE\n#ifndef call_from_test\n\n#define call_from_test\n#include \"\
    ../mod/mint.cpp\"\n#undef call_from_test\n\n//INSERT ABOVE HERE\nsigned ABC009_D(){\n\
    \  int k,m;\n  scanf(\"%d %d\",&k,&m);\n\n  struct M{\n    uint32_t v;\n    M(){*this=add_identity();}\n\
    \    M(uint32_t v):v(v){}\n    M operator+(const M &a)const{return M(v^a.v);}\n\
    \    M operator*(const M &a)const{return M(v&a.v);}\n    static M add_identity(){return\
    \ M(0);}\n    static M mul_identity(){return M(~0u);}\n  };\n\n  vector<M> as(k),cs(k);\n\
    \  for(int i=0;i<k;i++) scanf(\"%u\",&as[i].v);\n  for(int i=0;i<k;i++) scanf(\"\
    %u\",&cs[k-(i+1)].v);\n  Kitamasa<M> v(cs);\n\n  printf(\"%u\\n\",v.calc(as,--m).v);\n\
    \  return 0;\n}\n/*\n  verified on 2019/12/10\n  https://atcoder.jp/contests/abc009/tasks/abc009_4\n\
    */\n\nsigned main(){\n  //ABC009_D();\n  return 0;\n}\n#endif\n"
  dependsOn:
  - mod/mint.cpp
  isVerificationFile: false
  path: math/kitamasa.cpp
  requiredBy: []
  timestamp: '2020-10-07 14:44:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0168.test.cpp
  - test/yukicoder/0104.test.cpp
  - test/yukicoder/1973.test.cpp
documentation_of: math/kitamasa.cpp
layout: document
redirect_from:
- /library/math/kitamasa.cpp
- /library/math/kitamasa.cpp.html
title: math/kitamasa.cpp
---
