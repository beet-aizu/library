---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0403.test.cpp
    title: test/aoj/0403.test.cpp
  - icon: ':x:'
    path: test/yosupo/manhattanmst.test.cpp
    title: test/yosupo/manhattanmst.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/manhattanmst.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nvector<pair<int,\
    \ int>> manhattanmst(vector<T> xs,vector<T> ys){\n  using P = pair<int, int>;\n\
    \  vector<P> es;\n  int n=xs.size();\n\n  // xs[i] <- xs[i] + \\eps^i, ys[i] <-\
    \ ys[i] + \\eps^(n+i),\n  for(int s=0;s<2;s++){\n    for(int t=0;t<2;t++){\n \
    \     vector<int> ord(n);\n      iota(ord.begin(),ord.end(),0);\n      auto cmp=[&](int\
    \ i,int j)->bool{\n        if(xs[i]+ys[i]!=xs[j]+ys[j]) return xs[i]+ys[i]<xs[j]+ys[j];\n\
    \        return s^(i>j);\n      };\n      sort(ord.begin(),ord.end(),cmp);\n\n\
    \      map<pair<T, int>, int> idx;\n      for(int i:ord){\n        for(auto it=idx.lower_bound({-ys[i],(s&t)?+i:-i});\n\
    \            it!=idx.end();it=idx.erase(it)){\n          int j=it->second;\n \
    \         if(xs[i]-xs[j]<ys[i]-ys[j]) break;\n          es.emplace_back(i,j);\n\
    \        }\n        idx[{-ys[i],(s&t)?+i:-i}]=i;\n      }\n      swap(xs,ys);\n\
    \    }\n    for(int i=0;i<n;i++) xs[i]*=-1;\n  }\n  return es;\n}\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename T>\nvector<pair<int, int>> manhattanmst(vector<T>\
    \ xs,vector<T> ys){\n  using P = pair<int, int>;\n  vector<P> es;\n  int n=xs.size();\n\
    \n  // xs[i] <- xs[i] + \\eps^i, ys[i] <- ys[i] + \\eps^(n+i),\n  for(int s=0;s<2;s++){\n\
    \    for(int t=0;t<2;t++){\n      vector<int> ord(n);\n      iota(ord.begin(),ord.end(),0);\n\
    \      auto cmp=[&](int i,int j)->bool{\n        if(xs[i]+ys[i]!=xs[j]+ys[j])\
    \ return xs[i]+ys[i]<xs[j]+ys[j];\n        return s^(i>j);\n      };\n      sort(ord.begin(),ord.end(),cmp);\n\
    \n      map<pair<T, int>, int> idx;\n      for(int i:ord){\n        for(auto it=idx.lower_bound({-ys[i],(s&t)?+i:-i});\n\
    \            it!=idx.end();it=idx.erase(it)){\n          int j=it->second;\n \
    \         if(xs[i]-xs[j]<ys[i]-ys[j]) break;\n          es.emplace_back(i,j);\n\
    \        }\n        idx[{-ys[i],(s&t)?+i:-i}]=i;\n      }\n      swap(xs,ys);\n\
    \    }\n    for(int i=0;i<n;i++) xs[i]*=-1;\n  }\n  return es;\n}\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/manhattanmst.cpp
  requiredBy: []
  timestamp: '2020-10-09 14:11:38+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/0403.test.cpp
  - test/yosupo/manhattanmst.test.cpp
documentation_of: graph/manhattanmst.cpp
layout: document
redirect_from:
- /library/graph/manhattanmst.cpp
- /library/graph/manhattanmst.cpp.html
title: graph/manhattanmst.cpp
---
