---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/arbitrarymod.cpp
    title: convolution/arbitrarymod.cpp
  - icon: ':heavy_check_mark:'
    path: tools/bigint.cpp
    title: tools/bigint.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2985.test.cpp
    title: test/aoj/2985.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod_1000000007.test.cpp
    title: test/yosupo/convolution_mod_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/frequency_table_of_tree_distance.test.cpp
    title: test/yosupo/frequency_table_of_tree_distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0444.test.cpp
    title: test/yukicoder/0444.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2744.test.cpp
    title: test/yukicoder/2744.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/fastfouriertransform.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\nnamespace FFT{\n  using dbl =\
    \ double;\n\n  struct num{\n    dbl x,y;\n    num(){x=y=0;}\n    num(dbl x,dbl\
    \ y):x(x),y(y){}\n  };\n\n  inline num operator+(num a,num b){\n    return num(a.x+b.x,a.y+b.y);\n\
    \  }\n  inline num operator-(num a,num b){\n    return num(a.x-b.x,a.y-b.y);\n\
    \  }\n  inline num operator*(num a,num b){\n    return num(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);\n\
    \  }\n  inline num conj(num a){\n    return num(a.x,-a.y);\n  }\n\n  int base=1;\n\
    \  vector<num> rts={{0,0},{1,0}};\n  vector<int> rev={0,1};\n\n  const dbl PI=asinl(1)*2;\n\
    \n  void ensure_base(int nbase){\n    if(nbase<=base) return;\n\n    rev.resize(1<<nbase);\n\
    \    for(int i=0;i<(1<<nbase);i++)\n      rev[i]=(rev[i>>1]>>1)+((i&1)<<(nbase-1));\n\
    \n    rts.resize(1<<nbase);\n    while(base<nbase){\n      dbl angle=2*PI/(1<<(base+1));\n\
    \      for(int i=1<<(base-1);i<(1<<base);i++){\n        rts[i<<1]=rts[i];\n  \
    \      dbl angle_i=angle*(2*i+1-(1<<base));\n        rts[(i<<1)+1]=num(cos(angle_i),sin(angle_i));\n\
    \      }\n      base++;\n    }\n  }\n\n  void fft(vector<num> &as){\n    int n=as.size();\n\
    \    assert((n&(n-1))==0);\n\n    int zeros=__builtin_ctz(n);\n    ensure_base(zeros);\n\
    \    int shift=base-zeros;\n    for(int i=0;i<n;i++)\n      if(i<(rev[i]>>shift))\n\
    \        swap(as[i],as[rev[i]>>shift]);\n\n    for(int k=1;k<n;k<<=1){\n     \
    \ for(int i=0;i<n;i+=2*k){\n        for(int j=0;j<k;j++){\n          num z=as[i+j+k]*rts[j+k];\n\
    \          as[i+j+k]=as[i+j]-z;\n          as[i+j]=as[i+j]+z;\n        }\n   \
    \   }\n    }\n  }\n\n  template<typename T>\n  vector<long long> multiply(vector<T>\
    \ &as,vector<T> &bs){\n    int need=as.size()+bs.size()-1;\n    int nbase=0;\n\
    \    while((1<<nbase)<need) nbase++;\n    ensure_base(nbase);\n\n    int sz=1<<nbase;\n\
    \    vector<num> fa(sz);\n    for(int i=0;i<sz;i++){\n      T x=(i<(int)as.size()?as[i]:0);\n\
    \      T y=(i<(int)bs.size()?bs[i]:0);\n      fa[i]=num(x,y);\n    }\n    fft(fa);\n\
    \n    num r(0,-0.25/sz);\n    for(int i=0;i<=(sz>>1);i++){\n      int j=(sz-i)&(sz-1);\n\
    \      num z=(fa[j]*fa[j]-conj(fa[i]*fa[i]))*r;\n      if(i!=j)\n        fa[j]=(fa[i]*fa[i]-conj(fa[j]*fa[j]))*r;\n\
    \      fa[i]=z;\n    }\n    fft(fa);\n\n    vector<long long> res(need);\n   \
    \ for(int i=0;i<need;i++)\n      res[i]=round(fa[i].x);\n\n    return res;\n \
    \ }\n\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n\
    }\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nnamespace FFT{\n  using dbl = double;\n\n  struct num{\n   \
    \ dbl x,y;\n    num(){x=y=0;}\n    num(dbl x,dbl y):x(x),y(y){}\n  };\n\n  inline\
    \ num operator+(num a,num b){\n    return num(a.x+b.x,a.y+b.y);\n  }\n  inline\
    \ num operator-(num a,num b){\n    return num(a.x-b.x,a.y-b.y);\n  }\n  inline\
    \ num operator*(num a,num b){\n    return num(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);\n\
    \  }\n  inline num conj(num a){\n    return num(a.x,-a.y);\n  }\n\n  int base=1;\n\
    \  vector<num> rts={{0,0},{1,0}};\n  vector<int> rev={0,1};\n\n  const dbl PI=asinl(1)*2;\n\
    \n  void ensure_base(int nbase){\n    if(nbase<=base) return;\n\n    rev.resize(1<<nbase);\n\
    \    for(int i=0;i<(1<<nbase);i++)\n      rev[i]=(rev[i>>1]>>1)+((i&1)<<(nbase-1));\n\
    \n    rts.resize(1<<nbase);\n    while(base<nbase){\n      dbl angle=2*PI/(1<<(base+1));\n\
    \      for(int i=1<<(base-1);i<(1<<base);i++){\n        rts[i<<1]=rts[i];\n  \
    \      dbl angle_i=angle*(2*i+1-(1<<base));\n        rts[(i<<1)+1]=num(cos(angle_i),sin(angle_i));\n\
    \      }\n      base++;\n    }\n  }\n\n  void fft(vector<num> &as){\n    int n=as.size();\n\
    \    assert((n&(n-1))==0);\n\n    int zeros=__builtin_ctz(n);\n    ensure_base(zeros);\n\
    \    int shift=base-zeros;\n    for(int i=0;i<n;i++)\n      if(i<(rev[i]>>shift))\n\
    \        swap(as[i],as[rev[i]>>shift]);\n\n    for(int k=1;k<n;k<<=1){\n     \
    \ for(int i=0;i<n;i+=2*k){\n        for(int j=0;j<k;j++){\n          num z=as[i+j+k]*rts[j+k];\n\
    \          as[i+j+k]=as[i+j]-z;\n          as[i+j]=as[i+j]+z;\n        }\n   \
    \   }\n    }\n  }\n\n  template<typename T>\n  vector<long long> multiply(vector<T>\
    \ &as,vector<T> &bs){\n    int need=as.size()+bs.size()-1;\n    int nbase=0;\n\
    \    while((1<<nbase)<need) nbase++;\n    ensure_base(nbase);\n\n    int sz=1<<nbase;\n\
    \    vector<num> fa(sz);\n    for(int i=0;i<sz;i++){\n      T x=(i<(int)as.size()?as[i]:0);\n\
    \      T y=(i<(int)bs.size()?bs[i]:0);\n      fa[i]=num(x,y);\n    }\n    fft(fa);\n\
    \n    num r(0,-0.25/sz);\n    for(int i=0;i<=(sz>>1);i++){\n      int j=(sz-i)&(sz-1);\n\
    \      num z=(fa[j]*fa[j]-conj(fa[i]*fa[i]))*r;\n      if(i!=j)\n        fa[j]=(fa[i]*fa[i]-conj(fa[j]*fa[j]))*r;\n\
    \      fa[i]=z;\n    }\n    fft(fa);\n\n    vector<long long> res(need);\n   \
    \ for(int i=0;i<need;i++)\n      res[i]=round(fa[i].x);\n\n    return res;\n \
    \ }\n\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n\
    }\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: convolution/fastfouriertransform.cpp
  requiredBy:
  - convolution/arbitrarymod.cpp
  - tools/bigint.cpp
  timestamp: '2019-12-26 23:10:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/convolution_mod_1000000007.test.cpp
  - test/yosupo/frequency_table_of_tree_distance.test.cpp
  - test/yukicoder/2744.test.cpp
  - test/yukicoder/0444.test.cpp
  - test/aoj/2985.test.cpp
documentation_of: convolution/fastfouriertransform.cpp
layout: document
redirect_from:
- /library/convolution/fastfouriertransform.cpp
- /library/convolution/fastfouriertransform.cpp.html
title: convolution/fastfouriertransform.cpp
---
