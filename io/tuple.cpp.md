---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4918.test.cpp
    title: test/yukicoder/4918.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4852.test.cpp
    title: test/yukicoder/4852.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"io/tuple.cpp\"\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename TV, const\
    \ int N> void read_tuple_impl(TV&) {}\ntemplate<typename TV, const int N, typename\
    \ Head, typename... Tail>\nvoid read_tuple_impl(TV& ts) {\n  get<N>(ts).emplace_back(*(istream_iterator<Head>(cin)));\n\
    \  read_tuple_impl<TV, N+1, Tail...>(ts);\n}\ntemplate<typename... Ts> decltype(auto)\
    \ read_tuple(size_t n) {\n  tuple<vector<Ts>...> ts;\n  for(size_t i=0;i<n;i++)\
    \ read_tuple_impl<decltype(ts), 0, Ts...>(ts);\n  return ts;\n}\n//END CUT HERE\n\
    \n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename TV, const int N> void read_tuple_impl(TV&)\
    \ {}\ntemplate<typename TV, const int N, typename Head, typename... Tail>\nvoid\
    \ read_tuple_impl(TV& ts) {\n  get<N>(ts).emplace_back(*(istream_iterator<Head>(cin)));\n\
    \  read_tuple_impl<TV, N+1, Tail...>(ts);\n}\ntemplate<typename... Ts> decltype(auto)\
    \ read_tuple(size_t n) {\n  tuple<vector<Ts>...> ts;\n  for(size_t i=0;i<n;i++)\
    \ read_tuple_impl<decltype(ts), 0, Ts...>(ts);\n  return ts;\n}\n//END CUT HERE\n\
    \n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: io/tuple.cpp
  requiredBy: []
  timestamp: '2020-08-07 15:47:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/4918.test.cpp
  - test/yukicoder/4852.test.cpp
documentation_of: io/tuple.cpp
layout: document
redirect_from:
- /library/io/tuple.cpp
- /library/io/tuple.cpp.html
title: io/tuple.cpp
---
