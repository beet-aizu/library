---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2687.test.cpp
    title: test/aoj/2687.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructure/rotcev.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\n// no resize() because it is dangerous\n\
    template<typename T>\nstruct Rotcev{\n  vector<T> data;\n\n  size_t size()const{return\
    \ data.size();};\n  bool empty()const{return data.empty();}\n\n  T& operator[](size_t\
    \ n){return data[size()-1-n];}\n  const T& operator[](size_t n)const{return data[size()-1-n];}\n\
    \n  void push_front(T val){data.push_back(val);}\n  void pop_front(){data.pop_back();};\n\
    \  void clear(){data.clear();}\n\n  template<typename... Args>\n  Rotcev(Args\
    \ ...args):data(forward<Args>(args)...){}\n  template<typename... Args>\n  void\
    \ emplace_front(Args ...args){data.emplace_back(forward<Args>(args)...);}\n  template<typename...\
    \ Args>\n  void assign(Args ...args){data.assign(forward<Args>(args)...);}\n};\n\
    //END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\n// no resize() because it is dangerous\ntemplate<typename\
    \ T>\nstruct Rotcev{\n  vector<T> data;\n\n  size_t size()const{return data.size();};\n\
    \  bool empty()const{return data.empty();}\n\n  T& operator[](size_t n){return\
    \ data[size()-1-n];}\n  const T& operator[](size_t n)const{return data[size()-1-n];}\n\
    \n  void push_front(T val){data.push_back(val);}\n  void pop_front(){data.pop_back();};\n\
    \  void clear(){data.clear();}\n\n  template<typename... Args>\n  Rotcev(Args\
    \ ...args):data(forward<Args>(args)...){}\n  template<typename... Args>\n  void\
    \ emplace_front(Args ...args){data.emplace_back(forward<Args>(args)...);}\n  template<typename...\
    \ Args>\n  void assign(Args ...args){data.assign(forward<Args>(args)...);}\n};\n\
    //END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/rotcev.cpp
  requiredBy: []
  timestamp: '2021-03-11 20:23:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2687.test.cpp
documentation_of: datastructure/rotcev.cpp
layout: document
redirect_from:
- /library/datastructure/rotcev.cpp
- /library/datastructure/rotcev.cpp.html
title: datastructure/rotcev.cpp
---
