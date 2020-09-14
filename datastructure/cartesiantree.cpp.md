---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_3_D.cartesiantree.test.cpp
    title: test/aoj/DSL_3_D.cartesiantree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/cartesian_tree.test.cpp
    title: test/yosupo/cartesian_tree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"datastructure/cartesiantree.cpp\"\n\n#ifndef call_from_test\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename\
    \ T>\nvector<int> cartesian_tree(const vector<T> &vs){\n  int n=vs.size();\n \
    \ vector<int> ps(n,-1),ls(n,-1),rs(n,-1);\n  int cur=0;\n  for(int i=1;i<n;i++){\n\
    \    if(vs[cur]<=vs[i]){\n      rs[cur]=i;\n      ps[i]=cur;\n      cur=i;\n \
    \     continue;\n    }\n    while(~ps[cur] and vs[i]<vs[ps[cur]]) cur=ps[cur];\n\
    \    ps[i]=ps[cur];\n    if(~ps[i]) rs[ps[i]]=i;\n    ls[i]=cur;\n    ps[cur]=i;\n\
    \    cur=i;\n  }\n  return ps;\n}\n//END CUT HERE\n\n#ifndef call_from_test\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename T>\nvector<int> cartesian_tree(const\
    \ vector<T> &vs){\n  int n=vs.size();\n  vector<int> ps(n,-1),ls(n,-1),rs(n,-1);\n\
    \  int cur=0;\n  for(int i=1;i<n;i++){\n    if(vs[cur]<=vs[i]){\n      rs[cur]=i;\n\
    \      ps[i]=cur;\n      cur=i;\n      continue;\n    }\n    while(~ps[cur] and\
    \ vs[i]<vs[ps[cur]]) cur=ps[cur];\n    ps[i]=ps[cur];\n    if(~ps[i]) rs[ps[i]]=i;\n\
    \    ls[i]=cur;\n    ps[cur]=i;\n    cur=i;\n  }\n  return ps;\n}\n//END CUT HERE\n\
    \n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/cartesiantree.cpp
  requiredBy: []
  timestamp: '2020-07-27 11:09:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_3_D.cartesiantree.test.cpp
  - test/yosupo/cartesian_tree.test.cpp
documentation_of: datastructure/cartesiantree.cpp
layout: document
redirect_from:
- /library/datastructure/cartesiantree.cpp
- /library/datastructure/cartesiantree.cpp.html
title: datastructure/cartesiantree.cpp
---
