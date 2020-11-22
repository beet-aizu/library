---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0613.test.cpp
    title: test/aoj/0613.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_3_D.test.cpp
    title: test/aoj/DSL_3_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1923.test.cpp
    title: test/yukicoder/1923.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructure/rangeslide.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T, typename\
    \ F>\nstruct RangeSlide{\n  vector<size_t> ls,rs;\n  vector<T> vs;\n  F cmp;\n\
    \  RangeSlide(vector<T> vs,F cmp):vs(vs),cmp(cmp){}\n\n  void add_range(size_t\
    \ l,size_t r){\n    ls.emplace_back(l);\n    rs.emplace_back(r);\n  }\n\n  vector<size_t>\
    \ build(){\n    deque<size_t> deq;\n    vector<size_t> res;\n    for(size_t i=0,l=0,r=0;i<ls.size();i++){\n\
    \      if(r<=ls[i]){\n        deq.clear();\n        l=r=ls[i];\n      }\n    \
    \  while(r<rs[i]){\n        while(!deq.empty() and\n              !cmp(vs[deq.back()],vs[r]))\
    \ deq.pop_back();\n        deq.emplace_back(r++);\n      }\n      while(l<ls[i]){\n\
    \        if(deq.front()==l++) deq.pop_front();\n      }\n      res.emplace_back(deq.front());\n\
    \    }\n    return res;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT\
    \ ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename T, typename F>\nstruct RangeSlide{\n  vector<size_t>\
    \ ls,rs;\n  vector<T> vs;\n  F cmp;\n  RangeSlide(vector<T> vs,F cmp):vs(vs),cmp(cmp){}\n\
    \n  void add_range(size_t l,size_t r){\n    ls.emplace_back(l);\n    rs.emplace_back(r);\n\
    \  }\n\n  vector<size_t> build(){\n    deque<size_t> deq;\n    vector<size_t>\
    \ res;\n    for(size_t i=0,l=0,r=0;i<ls.size();i++){\n      if(r<=ls[i]){\n  \
    \      deq.clear();\n        l=r=ls[i];\n      }\n      while(r<rs[i]){\n    \
    \    while(!deq.empty() and\n              !cmp(vs[deq.back()],vs[r])) deq.pop_back();\n\
    \        deq.emplace_back(r++);\n      }\n      while(l<ls[i]){\n        if(deq.front()==l++)\
    \ deq.pop_front();\n      }\n      res.emplace_back(deq.front());\n    }\n   \
    \ return res;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE\
    \ HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/rangeslide.cpp
  requiredBy: []
  timestamp: '2020-10-27 12:55:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1923.test.cpp
  - test/aoj/DSL_3_D.test.cpp
  - test/aoj/0613.test.cpp
documentation_of: datastructure/rangeslide.cpp
layout: document
redirect_from:
- /library/datastructure/rangeslide.cpp
- /library/datastructure/rangeslide.cpp.html
title: datastructure/rangeslide.cpp
---
