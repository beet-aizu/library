---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0168.test.cpp
    title: test/aoj/0168.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0104.test.cpp
    title: test/yukicoder/0104.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/naive.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\n// O(N M)\ntemplate<typename T>\n\
    decltype(auto) naive(){\n  using Poly = vector<T>;\n  auto conv=[](Poly as, Poly\
    \ bs){\n    Poly cs(as.size()+bs.size()-1,0);\n    for(int i=0;i<(int)as.size();i++)\n\
    \      for(int j=0;j<(int)bs.size();j++)\n        cs[i+j]+=as[i]*bs[j];\n    return\
    \ cs;\n  };\n  return +conv;\n}\n//END CUT HERE\n#ifndef call_from_test\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\n// O(N M)\ntemplate<typename T>\ndecltype(auto) naive(){\n\
    \  using Poly = vector<T>;\n  auto conv=[](Poly as, Poly bs){\n    Poly cs(as.size()+bs.size()-1,0);\n\
    \    for(int i=0;i<(int)as.size();i++)\n      for(int j=0;j<(int)bs.size();j++)\n\
    \        cs[i+j]+=as[i]*bs[j];\n    return cs;\n  };\n  return +conv;\n}\n//END\
    \ CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: convolution/naive.cpp
  requiredBy: []
  timestamp: '2020-12-19 16:36:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0168.test.cpp
  - test/yukicoder/0104.test.cpp
documentation_of: convolution/naive.cpp
layout: document
redirect_from:
- /library/convolution/naive.cpp
- /library/convolution/naive.cpp.html
title: convolution/naive.cpp
---
