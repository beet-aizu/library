---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2294.test.cpp
    title: test/aoj/2294.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"vector/multi.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nvector<T> make_v(size_t\
    \ a){return vector<T>(a);}\n\ntemplate<typename T,typename... Ts>\nauto make_v(size_t\
    \ a,Ts... ts){\n  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));\n\
    }\n\ntemplate<typename T,typename U,typename... V>\ntypename enable_if<is_same<T,\
    \ U>::value!=0>::type\nfill_v(U &u,const V... v){u=U(v...);}\n\ntemplate<typename\
    \ T,typename U,typename... V>\ntypename enable_if<is_same<T, U>::value==0>::type\n\
    fill_v(U &u,const V... v){\n  for(auto &e:u) fill_v<T>(e,v...);\n}\n//END CUT\
    \ HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename T>\nvector<T> make_v(size_t a){return\
    \ vector<T>(a);}\n\ntemplate<typename T,typename... Ts>\nauto make_v(size_t a,Ts...\
    \ ts){\n  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));\n}\n\n\
    template<typename T,typename U,typename... V>\ntypename enable_if<is_same<T, U>::value!=0>::type\n\
    fill_v(U &u,const V... v){u=U(v...);}\n\ntemplate<typename T,typename U,typename...\
    \ V>\ntypename enable_if<is_same<T, U>::value==0>::type\nfill_v(U &u,const V...\
    \ v){\n  for(auto &e:u) fill_v<T>(e,v...);\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: vector/multi.cpp
  requiredBy: []
  timestamp: '2020-10-27 12:29:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2294.test.cpp
documentation_of: vector/multi.cpp
layout: document
redirect_from:
- /library/vector/multi.cpp
- /library/vector/multi.cpp.html
title: vector/multi.cpp
---
