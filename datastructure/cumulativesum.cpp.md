---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_sum.test.cpp
    title: test/yosupo/static_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructure/cumulativesum.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct CumulativeSum{\n\
    \  vector<T> sm;\n  CumulativeSum(const vector<T> &as){\n    int n=as.size();\n\
    \    sm.resize(n+1);\n    sm[0]=T();\n    for(int i=0;i<n;i++)\n      sm[i+1]=sm[i]+as[i];\n\
    \  }\n  // [l, r)\n  T query(int l,int r){return -sm[l]+sm[r];}\n};\n//END CUT\
    \ HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct CumulativeSum{\n  vector<T>\
    \ sm;\n  CumulativeSum(const vector<T> &as){\n    int n=as.size();\n    sm.resize(n+1);\n\
    \    sm[0]=T();\n    for(int i=0;i<n;i++)\n      sm[i+1]=sm[i]+as[i];\n  }\n \
    \ // [l, r)\n  T query(int l,int r){return -sm[l]+sm[r];}\n};\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/cumulativesum.cpp
  requiredBy: []
  timestamp: '2020-04-13 16:26:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/static_range_sum.test.cpp
documentation_of: datastructure/cumulativesum.cpp
layout: document
redirect_from:
- /library/datastructure/cumulativesum.cpp
- /library/datastructure/cumulativesum.cpp.html
title: datastructure/cumulativesum.cpp
---
