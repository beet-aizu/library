---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/3267.test.cpp
    title: test GCDConvolution
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/7107.test.cpp
    title: test LCMConvolution
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://noshi91.hatenablog.com/entry/2019/09/23/002445
  bundledCode: "#line 1 \"convolution/divisor.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n// https://noshi91.hatenablog.com/entry/2019/09/23/002445\n\
    //BEGIN CUT HERE\n// O(n \\log \\log n)\nnamespace DivisorTransform{\n  template<typename\
    \ T, typename F>\n  void inc(vector<T> &as,F f){\n    assert(as[0]==T(0));\n \
    \   int n=as.size();\n    vector<bool> sieve(n,false);\n    for(int p=2;p<n;p++){\n\
    \      if(sieve[p]) continue;\n      for(int k=1;k*p<n;k++){\n        sieve[k*p]=true;\n\
    \        f(as[k],as[k*p]);\n      }\n    }\n  }\n  template<typename T, typename\
    \ F>\n  void dec(vector<T> &as,F f){\n    assert(as[0]==T(0));\n    int n=as.size();\n\
    \    vector<bool> sieve(n,false);\n    for(int p=2;p<n;p++){\n      if(sieve[p])\
    \ continue;\n      for(int k=(n-1)/p;k!=0;--k){\n        sieve[k*p]=true;\n  \
    \      f(as[k],as[k*p]);\n      }\n    }\n  }\n}\nnamespace GCDConvolution{\n\
    \  template<typename T>\n  void zeta(vector<T> &as){\n    auto f=[](T &lo,T &hi){lo+=hi;};\n\
    \    DivisorTransform::dec(as,f);\n  }\n  template<typename T>\n  void moebius(vector<T>\
    \ &as){\n    auto f=[](T &lo,T &hi){lo-=hi;};\n    DivisorTransform::inc(as,f);\n\
    \  }\n}\nnamespace LCMConvolution{\n  template<typename T>\n  void zeta(vector<T>\
    \ &as){\n    auto f=[](T &lo,T &hi){hi+=lo;};\n    DivisorTransform::inc(as,f);\n\
    \  }\n  template<typename T>\n  void moebius(vector<T> &as){\n    auto f=[](T\
    \ &lo,T &hi){hi-=lo;};\n    DivisorTransform::dec(as,f);\n  }\n}\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n// https://noshi91.hatenablog.com/entry/2019/09/23/002445\n//BEGIN CUT\
    \ HERE\n// O(n \\log \\log n)\nnamespace DivisorTransform{\n  template<typename\
    \ T, typename F>\n  void inc(vector<T> &as,F f){\n    assert(as[0]==T(0));\n \
    \   int n=as.size();\n    vector<bool> sieve(n,false);\n    for(int p=2;p<n;p++){\n\
    \      if(sieve[p]) continue;\n      for(int k=1;k*p<n;k++){\n        sieve[k*p]=true;\n\
    \        f(as[k],as[k*p]);\n      }\n    }\n  }\n  template<typename T, typename\
    \ F>\n  void dec(vector<T> &as,F f){\n    assert(as[0]==T(0));\n    int n=as.size();\n\
    \    vector<bool> sieve(n,false);\n    for(int p=2;p<n;p++){\n      if(sieve[p])\
    \ continue;\n      for(int k=(n-1)/p;k!=0;--k){\n        sieve[k*p]=true;\n  \
    \      f(as[k],as[k*p]);\n      }\n    }\n  }\n}\nnamespace GCDConvolution{\n\
    \  template<typename T>\n  void zeta(vector<T> &as){\n    auto f=[](T &lo,T &hi){lo+=hi;};\n\
    \    DivisorTransform::dec(as,f);\n  }\n  template<typename T>\n  void moebius(vector<T>\
    \ &as){\n    auto f=[](T &lo,T &hi){lo-=hi;};\n    DivisorTransform::inc(as,f);\n\
    \  }\n}\nnamespace LCMConvolution{\n  template<typename T>\n  void zeta(vector<T>\
    \ &as){\n    auto f=[](T &lo,T &hi){hi+=lo;};\n    DivisorTransform::inc(as,f);\n\
    \  }\n  template<typename T>\n  void moebius(vector<T> &as){\n    auto f=[](T\
    \ &lo,T &hi){hi-=lo;};\n    DivisorTransform::dec(as,f);\n  }\n}\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: convolution/divisor.cpp
  requiredBy: []
  timestamp: '2021-11-21 12:07:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/7107.test.cpp
  - test/yukicoder/3267.test.cpp
documentation_of: convolution/divisor.cpp
layout: document
redirect_from:
- /library/convolution/divisor.cpp
- /library/convolution/divisor.cpp.html
title: convolution/divisor.cpp
---
