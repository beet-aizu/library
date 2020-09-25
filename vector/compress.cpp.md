---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1607.test.cpp
    title: test/aoj/1607.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2563.test.cpp
    title: test/aoj/2563.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1599.test.cpp
    title: test/aoj/1599.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1300.test.cpp
    title: test/aoj/1300.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0343.test.cpp
    title: test/aoj/0343.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0613.test.cpp
    title: test/aoj/0613.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2359.test.cpp
    title: test/aoj/2359.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/3961.test.cpp
    title: test/yukicoder/3961.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4778.test.cpp
    title: test/yukicoder/4778.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1732.test.cpp
    title: test/yukicoder/1732.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4852.test.cpp
    title: test/yukicoder/4852.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/line_add_get_min.test.cpp
    title: test/yosupo/line_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/rectangle_sum.test.cpp
    title: test/yosupo/rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_add_rectangle_sum.test.cpp
    title: test/yosupo/point_add_rectangle_sum.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"vector/compress.cpp\"\n\n#ifndef call_from_test\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename\
    \ V>\nV compress(V vs){\n  sort(vs.begin(),vs.end());\n  vs.erase(unique(vs.begin(),vs.end()),vs.end());\n\
    \  return vs;\n}\ntemplate<typename T>\nmap<T, int> dict(const vector<T> &vs){\n\
    \  map<T, int> res;\n  for(int i=0;i<(int)vs.size();i++)\n    res[vs[i]]=i;\n\
    \  return res;\n}\nmap<char, int> dict(const string &s){\n  return dict(vector<char>(s.begin(),s.end()));\n\
    }\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename V>\nV compress(V vs){\n\
    \  sort(vs.begin(),vs.end());\n  vs.erase(unique(vs.begin(),vs.end()),vs.end());\n\
    \  return vs;\n}\ntemplate<typename T>\nmap<T, int> dict(const vector<T> &vs){\n\
    \  map<T, int> res;\n  for(int i=0;i<(int)vs.size();i++)\n    res[vs[i]]=i;\n\
    \  return res;\n}\nmap<char, int> dict(const string &s){\n  return dict(vector<char>(s.begin(),s.end()));\n\
    }\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: vector/compress.cpp
  requiredBy: []
  timestamp: '2020-04-18 17:56:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1607.test.cpp
  - test/aoj/2563.test.cpp
  - test/aoj/1599.test.cpp
  - test/aoj/1300.test.cpp
  - test/aoj/0343.test.cpp
  - test/aoj/0613.test.cpp
  - test/aoj/2359.test.cpp
  - test/yukicoder/3961.test.cpp
  - test/yukicoder/4778.test.cpp
  - test/yukicoder/1732.test.cpp
  - test/yukicoder/4852.test.cpp
  - test/yosupo/line_add_get_min.test.cpp
  - test/yosupo/rectangle_sum.test.cpp
  - test/yosupo/point_add_rectangle_sum.test.cpp
documentation_of: vector/compress.cpp
layout: document
redirect_from:
- /library/vector/compress.cpp
- /library/vector/compress.cpp.html
title: vector/compress.cpp
---
