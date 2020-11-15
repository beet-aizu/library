---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4872.test.cpp
    title: test/yukicoder/4872.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"vector/runlength.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename T>\ndecltype(auto)\
    \ runlength(vector<T> vs){\n  vector<pair<T, int>> es;\n  for(auto v:vs){\n  \
    \  if(es.empty() or es.back().first!=v)\n      es.emplace_back(v,0);\n    es.back().second++;\n\
    \  }\n  return es;\n}\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE\
    \ HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n\n//BEGIN CUT HERE\ntemplate<typename T>\ndecltype(auto) runlength(vector<T>\
    \ vs){\n  vector<pair<T, int>> es;\n  for(auto v:vs){\n    if(es.empty() or es.back().first!=v)\n\
    \      es.emplace_back(v,0);\n    es.back().second++;\n  }\n  return es;\n}\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: vector/runlength.cpp
  requiredBy: []
  timestamp: '2020-11-15 16:01:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/4872.test.cpp
documentation_of: vector/runlength.cpp
layout: document
redirect_from:
- /library/vector/runlength.cpp
- /library/vector/runlength.cpp.html
title: vector/runlength.cpp
---
