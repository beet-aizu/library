---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"string/rollinghash.cpp\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T,T MOD,T B>\nstruct\
    \ RollingHash{\n  using ll = long long;\n  vector<T> hash,po;\n  RollingHash(){}\n\
    \  RollingHash(vector<T> vs){init(vs);}\n  RollingHash(string &s){\n    vector<T>\
    \ vs;\n    for(char c:s) vs.emplace_back(c);\n    init(vs);\n  }\n  void init(vector<T>\
    \ vs){\n    int n=vs.size();\n    hash.assign(n+1,0);\n    po.assign(n+1,1);\n\
    \    for(int i=0;i<n;i++){\n      hash[i+1]=((ll)hash[i]*B+vs[i])%MOD;\n     \
    \ po[i+1]=(ll)po[i]*B%MOD;\n    }\n  }\n  //S[l, r)\n  T find(int l,int r){\n\
    \    T res=(ll)hash[r]+MOD-(ll)hash[l]*po[r-l]%MOD;\n    return res>=MOD?res-MOD:res;\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename T,T MOD,T B>\nstruct RollingHash{\n  using\
    \ ll = long long;\n  vector<T> hash,po;\n  RollingHash(){}\n  RollingHash(vector<T>\
    \ vs){init(vs);}\n  RollingHash(string &s){\n    vector<T> vs;\n    for(char c:s)\
    \ vs.emplace_back(c);\n    init(vs);\n  }\n  void init(vector<T> vs){\n    int\
    \ n=vs.size();\n    hash.assign(n+1,0);\n    po.assign(n+1,1);\n    for(int i=0;i<n;i++){\n\
    \      hash[i+1]=((ll)hash[i]*B+vs[i])%MOD;\n      po[i+1]=(ll)po[i]*B%MOD;\n\
    \    }\n  }\n  //S[l, r)\n  T find(int l,int r){\n    T res=(ll)hash[r]+MOD-(ll)hash[l]*po[r-l]%MOD;\n\
    \    return res>=MOD?res-MOD:res;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/rectanglehash.cpp
    title: string/rectanglehash.cpp
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_C.test.cpp
    title: test/aoj/ALDS1_14_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.test.cpp
    title: test/aoj/ALDS1_14_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2444.test.cpp
    title: test/aoj/2444.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1312.test.cpp
    title: test/aoj/1312.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2292.test.cpp
    title: test/aoj/2292.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0399.test.cpp
    title: test/yukicoder/0399.test.cpp
  isVerificationFile: false
  path: string/rollinghash.cpp
  requiredBy:
  - string/rectanglehash.cpp
  timestamp: '2019-10-28 14:24:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - test/aoj/ALDS1_14_C.test.cpp
  - test/aoj/ALDS1_14_B.test.cpp
  - test/aoj/2444.test.cpp
  - test/aoj/1312.test.cpp
  - test/aoj/2292.test.cpp
  - test/yukicoder/0399.test.cpp
documentation_of: string/rollinghash.cpp
layout: document
redirect_from:
- /library/string/rollinghash.cpp
- /library/string/rollinghash.cpp.html
title: string/rollinghash.cpp
---
