---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tree/mo_on_tree.cpp
    title: tree/mo_on_tree.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0425.test.cpp
    title: test/aoj/0425.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2270.test.cpp
    title: test/aoj/2270.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_inversions_query.test.cpp
    title: test/yosupo/static_range_inversions_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/5223.test.cpp
    title: test/yukicoder/5223.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/mo.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\nstruct Mo{\n  using F = function<void(int)>;\n\
    \  vector<int> ls,rs,ord;\n  int n,width,nl,nr,ptr;\n  F expandL,expandR;\n  F\
    \ shrinkL,shrinkR;\n\n  Mo(int n,int width,F expandL,F expandR,F shrinkL,F shrinkR):\n\
    \    n(n),width(width),nl(0),nr(0),ptr(0),\n    expandL(expandL),expandR(expandR),\n\
    \    shrinkL(shrinkL),shrinkR(shrinkR){}\n\n  Mo(int n,int width,F expand,F shrink):\n\
    \    Mo(n,width,expand,expand,shrink,shrink){}\n\n  void add(int l,int r){\n \
    \   ls.emplace_back(l);\n    rs.emplace_back(r);\n  }\n\n  void build(){\n   \
    \ ord.resize(ls.size());\n    iota(ord.begin(),ord.end(),0);\n    sort(ord.begin(),ord.end(),\n\
    \         [&](int a,int b){\n           if(ls[a]/width!=ls[b]/width) return ls[a]<ls[b];\n\
    \           if(rs[a]==rs[b]) return ls[a]<ls[b];\n           return bool((rs[a]<rs[b])^((ls[a]/width)&1));\n\
    \         });\n  }\n\n  int process(){\n    if(ptr==(int)ord.size()) return -1;\n\
    \    const int idx=ord[ptr++];\n    while(nl>ls[idx]) expandL(--nl);\n    while(nr<rs[idx])\
    \ expandR(nr++);\n    while(nl<ls[idx]) shrinkL(nl++);\n    while(nr>rs[idx])\
    \ shrinkR(--nr);\n    return idx;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\nstruct Mo{\n  using F = function<void(int)>;\n  vector<int>\
    \ ls,rs,ord;\n  int n,width,nl,nr,ptr;\n  F expandL,expandR;\n  F shrinkL,shrinkR;\n\
    \n  Mo(int n,int width,F expandL,F expandR,F shrinkL,F shrinkR):\n    n(n),width(width),nl(0),nr(0),ptr(0),\n\
    \    expandL(expandL),expandR(expandR),\n    shrinkL(shrinkL),shrinkR(shrinkR){}\n\
    \n  Mo(int n,int width,F expand,F shrink):\n    Mo(n,width,expand,expand,shrink,shrink){}\n\
    \n  void add(int l,int r){\n    ls.emplace_back(l);\n    rs.emplace_back(r);\n\
    \  }\n\n  void build(){\n    ord.resize(ls.size());\n    iota(ord.begin(),ord.end(),0);\n\
    \    sort(ord.begin(),ord.end(),\n         [&](int a,int b){\n           if(ls[a]/width!=ls[b]/width)\
    \ return ls[a]<ls[b];\n           if(rs[a]==rs[b]) return ls[a]<ls[b];\n     \
    \      return bool((rs[a]<rs[b])^((ls[a]/width)&1));\n         });\n  }\n\n  int\
    \ process(){\n    if(ptr==(int)ord.size()) return -1;\n    const int idx=ord[ptr++];\n\
    \    while(nl>ls[idx]) expandL(--nl);\n    while(nr<rs[idx]) expandR(nr++);\n\
    \    while(nl<ls[idx]) shrinkL(nl++);\n    while(nr>rs[idx]) shrinkR(--nr);\n\
    \    return idx;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/mo.cpp
  requiredBy:
  - tree/mo_on_tree.cpp
  timestamp: '2020-10-09 19:36:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/5223.test.cpp
  - test/aoj/2270.test.cpp
  - test/aoj/0425.test.cpp
  - test/yosupo/static_range_inversions_query.test.cpp
documentation_of: algorithm/mo.cpp
layout: document
redirect_from:
- /library/algorithm/mo.cpp
- /library/algorithm/mo.cpp.html
title: algorithm/mo.cpp
---
