---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"math/convertbase.cpp\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nvector<T> convert_base(T\
    \ x,T b){\n  vector<T> res;\n  T t=1,k=abs(b);\n  while(x){\n    res.emplace_back((x*t)%k);\n\
    \    if(res.back()<0) res.back()+=k;\n    x-=res.back()*t;\n    x/=k;\n    t*=b/k;\n\
    \  }\n  if(res.empty()) res.emplace_back(0);\n  reverse(res.begin(),res.end());\n\
    \  return res;\n}\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename T>\nvector<T> convert_base(T x,T b){\n  vector<T>\
    \ res;\n  T t=1,k=abs(b);\n  while(x){\n    res.emplace_back((x*t)%k);\n    if(res.back()<0)\
    \ res.back()+=k;\n    x-=res.back()*t;\n    x/=k;\n    t*=b/k;\n  }\n  if(res.empty())\
    \ res.emplace_back(0);\n  reverse(res.begin(),res.end());\n  return res;\n}\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0233.test.cpp
    title: test/aoj/0233.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1580.test.cpp
    title: test/yukicoder/1580.test.cpp
  isVerificationFile: false
  path: math/convertbase.cpp
  requiredBy: []
  timestamp: '2020-02-15 15:47:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - test/aoj/0233.test.cpp
  - test/yukicoder/1580.test.cpp
documentation_of: math/convertbase.cpp
layout: document
redirect_from:
- /library/math/convertbase.cpp
- /library/math/convertbase.cpp.html
title: math/convertbase.cpp
---
