---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1607.test.cpp
    title: test/aoj/1607.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_A.test.cpp
    title: test/aoj/GRL_1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructure/radixheap.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\n// prohibited to push an element\
    \ less than popped one\n// Key: int or long long\ntemplate<typename K,typename\
    \ V>\nstruct RadixHeap{\n  static constexpr int bit = sizeof(K) * 8;\n  array<vector<\
    \ pair<K, V> >, bit> vs;\n\n  int size;\n  K last;\n  RadixHeap():size(0),last(0){}\n\
    \n  bool empty() const{return size==0;}\n\n  inline int getbit(int a){\n    return\
    \ a?bit-__builtin_clz(a):0;\n  }\n\n  inline int getbit(long long a){\n    return\
    \ a?bit-__builtin_clzll(a):0;\n  }\n\n  void emplace(K key,V val){\n    size++;\n\
    \    vs[getbit(key^last)].emplace_back(key,val);\n  }\n\n  pair<K, V> pop(){\n\
    \    if(vs[0].empty()){\n      int idx=1;\n      while(vs[idx].empty()) idx++;\n\
    \      last=min_element(vs[idx].begin(),vs[idx].end())->first;\n      for(auto\
    \ &p:vs[idx]) vs[getbit(p.first^last)].emplace_back(p);\n      vs[idx].clear();\n\
    \    }\n    --size;\n    auto res=vs[0].back();\n    vs[0].pop_back();\n    return\
    \ res;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\n// prohibited to push an element less than popped one\n// Key:\
    \ int or long long\ntemplate<typename K,typename V>\nstruct RadixHeap{\n  static\
    \ constexpr int bit = sizeof(K) * 8;\n  array<vector< pair<K, V> >, bit> vs;\n\
    \n  int size;\n  K last;\n  RadixHeap():size(0),last(0){}\n\n  bool empty() const{return\
    \ size==0;}\n\n  inline int getbit(int a){\n    return a?bit-__builtin_clz(a):0;\n\
    \  }\n\n  inline int getbit(long long a){\n    return a?bit-__builtin_clzll(a):0;\n\
    \  }\n\n  void emplace(K key,V val){\n    size++;\n    vs[getbit(key^last)].emplace_back(key,val);\n\
    \  }\n\n  pair<K, V> pop(){\n    if(vs[0].empty()){\n      int idx=1;\n      while(vs[idx].empty())\
    \ idx++;\n      last=min_element(vs[idx].begin(),vs[idx].end())->first;\n    \
    \  for(auto &p:vs[idx]) vs[getbit(p.first^last)].emplace_back(p);\n      vs[idx].clear();\n\
    \    }\n    --size;\n    auto res=vs[0].back();\n    vs[0].pop_back();\n    return\
    \ res;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/radixheap.cpp
  requiredBy: []
  timestamp: '2019-12-09 23:10:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1607.test.cpp
  - test/aoj/GRL_1_A.test.cpp
documentation_of: datastructure/radixheap.cpp
layout: document
redirect_from:
- /library/datastructure/radixheap.cpp
- /library/datastructure/radixheap.cpp.html
title: datastructure/radixheap.cpp
---
