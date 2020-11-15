---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/bitwise/xor.cpp
    title: convolution/bitwise/xor.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0402.test.cpp
    title: test/aoj/0402.test.cpp
  - icon: ':x:'
    path: test/aoj/2446.test.cpp
    title: test/aoj/2446.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2981.test.cpp
    title: test/aoj/2981.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://kazuma8128.hatenablog.com/entry/2018/05/31/144519
  bundledCode: "#line 1 \"convolution/bitwise/fwht.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n// https://kazuma8128.hatenablog.com/entry/2018/05/31/144519\n\
    //BEGIN CUT HERE\ntemplate<typename T, typename F>\nvoid fwht(vector<T> &as,F\
    \ f){\n  int n=as.size();\n  for(int d=1;d<n;d<<=1)\n    for(int m=d<<1,i=0;i<n;i+=m)\n\
    \      for(int j=0;j<d;j++)\n        f(as[i+j],as[i+j+d]);\n}\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n// https://kazuma8128.hatenablog.com/entry/2018/05/31/144519\n//BEGIN\
    \ CUT HERE\ntemplate<typename T, typename F>\nvoid fwht(vector<T> &as,F f){\n\
    \  int n=as.size();\n  for(int d=1;d<n;d<<=1)\n    for(int m=d<<1,i=0;i<n;i+=m)\n\
    \      for(int j=0;j<d;j++)\n        f(as[i+j],as[i+j+d]);\n}\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: convolution/bitwise/fwht.cpp
  requiredBy:
  - convolution/bitwise/xor.cpp
  timestamp: '2020-11-15 18:54:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/0402.test.cpp
  - test/aoj/2981.test.cpp
  - test/aoj/2446.test.cpp
documentation_of: convolution/bitwise/fwht.cpp
layout: document
redirect_from:
- /library/convolution/bitwise/fwht.cpp
- /library/convolution/bitwise/fwht.cpp.html
title: convolution/bitwise/fwht.cpp
---
