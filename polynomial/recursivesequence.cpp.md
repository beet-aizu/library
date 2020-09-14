---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4271.test.cpp
    title: test/yukicoder/4271.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 2 \"polynomial/recursivesequence.cpp\"\n\n#ifndef call_from_test\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#endif\n//BEGIN CUT HERE\n//\
    \ add recursive sequence\ntemplate<typename T>\nstruct RecursiveSequence{\n  vector<vector<int>>\
    \ add,sub;\n  RecursiveSequence(int n):add(n),sub(n+1){}\n\n  // add a_0, ...,\
    \ a_{r-l-1} to [l, r)\n  void query(int l,int r){\n    add[l].emplace_back(0);\n\
    \    sub[r].emplace_back(r-l);\n  }\n\n  // a_i = \\sum_{k} c_k a_{i-k}\n  vector<T>\
    \ build(vector<T> as,vector<T> cs){\n    assert(as.size()==cs.size());\n    int\
    \ n=add.size();\n    int k=as.size();\n\n    reverse(cs.begin(),cs.end());\n \
    \   as.resize(n+k);\n    for(int i=0;i<n;i++)\n      for(int j=0;j<k;j++)\n  \
    \      as[i+k]+=as[i+j]*cs[j];\n\n    vector<T> ss(n+k,T(0));\n    for(int i=0;i<n;i++){\n\
    \      for(int l:add[i])\n        for(int j=0;j<k;j++)\n          ss[i+j]+=as[l+j];\n\
    \n      for(int l:sub[i])\n        for(int j=0;j<k;j++)\n          ss[i+j]-=as[l+j];\n\
    \n      for(int j=0;j<k;j++)\n        ss[i+k]+=ss[i+j]*cs[j];\n    }\n    ss.resize(n);\n\
    \    return ss;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#endif\n//BEGIN CUT HERE\n// add recursive sequence\ntemplate<typename\
    \ T>\nstruct RecursiveSequence{\n  vector<vector<int>> add,sub;\n  RecursiveSequence(int\
    \ n):add(n),sub(n+1){}\n\n  // add a_0, ..., a_{r-l-1} to [l, r)\n  void query(int\
    \ l,int r){\n    add[l].emplace_back(0);\n    sub[r].emplace_back(r-l);\n  }\n\
    \n  // a_i = \\sum_{k} c_k a_{i-k}\n  vector<T> build(vector<T> as,vector<T> cs){\n\
    \    assert(as.size()==cs.size());\n    int n=add.size();\n    int k=as.size();\n\
    \n    reverse(cs.begin(),cs.end());\n    as.resize(n+k);\n    for(int i=0;i<n;i++)\n\
    \      for(int j=0;j<k;j++)\n        as[i+k]+=as[i+j]*cs[j];\n\n    vector<T>\
    \ ss(n+k,T(0));\n    for(int i=0;i<n;i++){\n      for(int l:add[i])\n        for(int\
    \ j=0;j<k;j++)\n          ss[i+j]+=as[l+j];\n\n      for(int l:sub[i])\n     \
    \   for(int j=0;j<k;j++)\n          ss[i+j]-=as[l+j];\n\n      for(int j=0;j<k;j++)\n\
    \        ss[i+k]+=ss[i+j]*cs[j];\n    }\n    ss.resize(n);\n    return ss;\n \
    \ }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n\
    }\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: polynomial/recursivesequence.cpp
  requiredBy: []
  timestamp: '2020-08-28 13:36:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/4271.test.cpp
documentation_of: polynomial/recursivesequence.cpp
layout: document
redirect_from:
- /library/polynomial/recursivesequence.cpp
- /library/polynomial/recursivesequence.cpp.html
title: polynomial/recursivesequence.cpp
---
