---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2359.test.cpp
    title: test/aoj/2359.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2969.test.cpp
    title: test/aoj/2969.test.cpp
  - icon: ':x:'
    path: test/yukicoder/4778.test.cpp
    title: test/yukicoder/4778.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"vector/near.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nvector<T> add(vector<T>\
    \ vs,vector<T> as){\n  assert(vs.size()==as.size());\n  for(int i=0;i<(int)vs.size();i++)\
    \ vs[i]+=as[i];\n  return vs;\n}\n\ntemplate<typename T, typename U>\nvector<T>\
    \ add(vector<T> vs,U a){\n  return add(vs,vector<T>(vs.size(),a));\n}\n\ntemplate<typename\
    \ T>\nvector<T> mul(vector<T> vs,vector<T> as){\n  assert(vs.size()==as.size());\n\
    \  for(int i=0;i<(int)vs.size();i++) vs[i]*=as[i];\n  return vs;\n}\n\ntemplate<typename\
    \ T, typename U>\nvector<T> mul(vector<T> vs,U a){\n  return mul(vs,vector<T>(vs.size(),a));\n\
    }\n\ntemplate<typename T, typename ...Ts>\nvector<T> near(vector<T> vs,Ts... ts){\n\
    \  vector<T> rs;\n  rs.reserve(vs.size()*sizeof...(ts));\n  auto append=[&](auto\
    \ a){\n    for(auto w:add(vs,a)) rs.emplace_back(w);\n  };\n  initializer_list<int>{(void(append(ts)),0)...};\n\
    \  return rs;\n}\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename T>\nvector<T> add(vector<T> vs,vector<T>\
    \ as){\n  assert(vs.size()==as.size());\n  for(int i=0;i<(int)vs.size();i++) vs[i]+=as[i];\n\
    \  return vs;\n}\n\ntemplate<typename T, typename U>\nvector<T> add(vector<T>\
    \ vs,U a){\n  return add(vs,vector<T>(vs.size(),a));\n}\n\ntemplate<typename T>\n\
    vector<T> mul(vector<T> vs,vector<T> as){\n  assert(vs.size()==as.size());\n \
    \ for(int i=0;i<(int)vs.size();i++) vs[i]*=as[i];\n  return vs;\n}\n\ntemplate<typename\
    \ T, typename U>\nvector<T> mul(vector<T> vs,U a){\n  return mul(vs,vector<T>(vs.size(),a));\n\
    }\n\ntemplate<typename T, typename ...Ts>\nvector<T> near(vector<T> vs,Ts... ts){\n\
    \  vector<T> rs;\n  rs.reserve(vs.size()*sizeof...(ts));\n  auto append=[&](auto\
    \ a){\n    for(auto w:add(vs,a)) rs.emplace_back(w);\n  };\n  initializer_list<int>{(void(append(ts)),0)...};\n\
    \  return rs;\n}\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: vector/near.cpp
  requiredBy: []
  timestamp: '2020-11-15 18:14:20+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/4778.test.cpp
  - test/aoj/2969.test.cpp
  - test/aoj/2359.test.cpp
documentation_of: vector/near.cpp
layout: document
redirect_from:
- /library/vector/near.cpp
- /library/vector/near.cpp.html
title: vector/near.cpp
---
