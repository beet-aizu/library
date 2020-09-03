---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 2 \"vector/multi.cpp\"\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nvector<T>\
    \ make_v(size_t a){return vector<T>(a);}\n\ntemplate<typename T,typename... Ts>\n\
    auto make_v(size_t a,Ts... ts){\n  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));\n\
    }\n\ntemplate<typename T,typename U,typename... V>\ntypename enable_if<is_same<T,\
    \ U>::value!=0>::type\nfill_v(U &u,const V... v){u=U(v...);}\n\ntemplate<typename\
    \ T,typename U,typename... V>\ntypename enable_if<is_same<T, U>::value==0>::type\n\
    fill_v(U &u,const V... v){\n  for(auto &e:u) fill_v<T>(e,v...);\n}\n//END CUT\
    \ HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nvector<T> make_v(size_t\
    \ a){return vector<T>(a);}\n\ntemplate<typename T,typename... Ts>\nauto make_v(size_t\
    \ a,Ts... ts){\n  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));\n\
    }\n\ntemplate<typename T,typename U,typename... V>\ntypename enable_if<is_same<T,\
    \ U>::value!=0>::type\nfill_v(U &u,const V... v){u=U(v...);}\n\ntemplate<typename\
    \ T,typename U,typename... V>\ntypename enable_if<is_same<T, U>::value==0>::type\n\
    fill_v(U &u,const V... v){\n  for(auto &e:u) fill_v<T>(e,v...);\n}\n//END CUT\
    \ HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2294.test.cpp
    title: test/aoj/2294.test.cpp
  extendedVerifiedWith: []
  isVerificationFile: false
  path: vector/multi.cpp
  requiredBy:
  - test/aoj/2294.test.cpp
  timestamp: '2020-04-18 17:56:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: vector/multi.cpp
layout: document
redirect_from:
- /library/vector/multi.cpp
- /library/vector/multi.cpp.html
title: vector/multi.cpp
---
