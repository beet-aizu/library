---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 2 \"vector/near.cpp\"\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nvector<T>\
    \ add(vector<T> vs,vector<T> as){\n  assert(vs.size()==as.size());\n  for(int\
    \ i=0;i<(int)vs.size();i++) vs[i]+=as[i];\n  return vs;\n}\ntemplate<typename\
    \ T>\nvector<T> add(vector<T> vs,T a){\n  return add(vs,vector<T>(vs.size(),a));\n\
    }\ntemplate<typename T>\nvector<T> mul(vector<T> vs,vector<T> as){\n  assert(vs.size()==as.size());\n\
    \  for(int i=0;i<(int)vs.size();i++) vs[i]*=as[i];\n  return vs;\n}\ntemplate<typename\
    \ T>\nvector<T> mul(vector<T> vs,T a){\n  return mul(vs,vector<T>(vs.size(),a));\n\
    }\ntemplate<typename T, typename ...Ts>\nvector<T> near(vector<T> vs,Ts... ts){\n\
    \  vector<T> rs;\n  rs.reserve(vs.size()*sizeof...(ts));\n  auto append=[&](auto\
    \ a){\n    auto ws=add(vs,a);\n    for(auto w:ws) rs.emplace_back(w);\n  };\n\
    \  initializer_list<int>{(void(append(ts)),0)...};\n  return rs;\n}\n//END CUT\
    \ HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nvector<T> add(vector<T>\
    \ vs,vector<T> as){\n  assert(vs.size()==as.size());\n  for(int i=0;i<(int)vs.size();i++)\
    \ vs[i]+=as[i];\n  return vs;\n}\ntemplate<typename T>\nvector<T> add(vector<T>\
    \ vs,T a){\n  return add(vs,vector<T>(vs.size(),a));\n}\ntemplate<typename T>\n\
    vector<T> mul(vector<T> vs,vector<T> as){\n  assert(vs.size()==as.size());\n \
    \ for(int i=0;i<(int)vs.size();i++) vs[i]*=as[i];\n  return vs;\n}\ntemplate<typename\
    \ T>\nvector<T> mul(vector<T> vs,T a){\n  return mul(vs,vector<T>(vs.size(),a));\n\
    }\ntemplate<typename T, typename ...Ts>\nvector<T> near(vector<T> vs,Ts... ts){\n\
    \  vector<T> rs;\n  rs.reserve(vs.size()*sizeof...(ts));\n  auto append=[&](auto\
    \ a){\n    auto ws=add(vs,a);\n    for(auto w:ws) rs.emplace_back(w);\n  };\n\
    \  initializer_list<int>{(void(append(ts)),0)...};\n  return rs;\n}\n//END CUT\
    \ HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2359.test.cpp
    title: test/aoj/2359.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4778.test.cpp
    title: test/yukicoder/4778.test.cpp
  isVerificationFile: false
  path: vector/near.cpp
  requiredBy: []
  timestamp: '2020-07-30 16:42:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - test/aoj/2359.test.cpp
  - test/yukicoder/4778.test.cpp
documentation_of: vector/near.cpp
layout: document
redirect_from:
- /library/vector/near.cpp
- /library/vector/near.cpp.html
title: vector/near.cpp
---
