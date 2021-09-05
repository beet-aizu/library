---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/ahocorasick.cpp
    title: string/ahocorasick.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2212.test.cpp
    title: test/aoj/2212.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2257.test.cpp
    title: test/aoj/2257.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3073.test.cpp
    title: test/aoj/3073.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1013.test.cpp
    title: test/yukicoder/1013.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/trie.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<size_t X>\nstruct Trie{\n  struct Node{\n\
    \    array<int, X> nxt;\n    vector<int> idxs;\n    int idx;\n    Node():idx(-1){fill(nxt.begin(),nxt.end(),-1);}\n\
    \  };\n\n  using F = function<int(char)>;\n  vector<Node> vs;\n  F conv;\n\n \
    \ Trie(F conv):conv(conv){vs.emplace_back();}\n  Trie(char start):Trie([=](char\
    \ a){return a-start;}){}\n\n  inline int &next(int i,int j){\n    return vs[i].nxt[j];\n\
    \  }\n\n  void add(const string &s,int x){\n    int pos=0;\n    for(char c:s){\n\
    \      int k=conv(c);\n      if(~next(pos,k)){\n        pos=next(pos,k);\n   \
    \     continue;\n      }\n      int npos=vs.size();\n      next(pos,k)=npos;\n\
    \      vs.emplace_back();\n      pos=npos;\n    }\n    vs[pos].idx=x;\n    vs[pos].idxs.emplace_back(x);\n\
    \  }\n\n  int find(const string &s){\n    int pos=0;\n    for(char c:s){\n   \
    \   int k=conv(c);\n      if(next(pos,k)<0) return -1;\n      pos=next(pos,k);\n\
    \    }\n    return pos;\n  }\n\n  int move(int pos,char c){\n    assert(pos<(int)vs.size());\n\
    \    return pos<0?-1:next(pos,conv(c));\n  }\n\n  int size(){return vs.size();}\n\
    \n  int idx(int pos){\n    return pos<0?-1:vs[pos].idx;\n  }\n\n  vector<int>\
    \ idxs(int pos){\n    return pos<0?vector<int>():vs[pos].idxs;\n  }\n};\n//END\
    \ CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<size_t X>\nstruct Trie{\n  struct Node{\n \
    \   array<int, X> nxt;\n    vector<int> idxs;\n    int idx;\n    Node():idx(-1){fill(nxt.begin(),nxt.end(),-1);}\n\
    \  };\n\n  using F = function<int(char)>;\n  vector<Node> vs;\n  F conv;\n\n \
    \ Trie(F conv):conv(conv){vs.emplace_back();}\n  Trie(char start):Trie([=](char\
    \ a){return a-start;}){}\n\n  inline int &next(int i,int j){\n    return vs[i].nxt[j];\n\
    \  }\n\n  void add(const string &s,int x){\n    int pos=0;\n    for(char c:s){\n\
    \      int k=conv(c);\n      if(~next(pos,k)){\n        pos=next(pos,k);\n   \
    \     continue;\n      }\n      int npos=vs.size();\n      next(pos,k)=npos;\n\
    \      vs.emplace_back();\n      pos=npos;\n    }\n    vs[pos].idx=x;\n    vs[pos].idxs.emplace_back(x);\n\
    \  }\n\n  int find(const string &s){\n    int pos=0;\n    for(char c:s){\n   \
    \   int k=conv(c);\n      if(next(pos,k)<0) return -1;\n      pos=next(pos,k);\n\
    \    }\n    return pos;\n  }\n\n  int move(int pos,char c){\n    assert(pos<(int)vs.size());\n\
    \    return pos<0?-1:next(pos,conv(c));\n  }\n\n  int size(){return vs.size();}\n\
    \n  int idx(int pos){\n    return pos<0?-1:vs[pos].idx;\n  }\n\n  vector<int>\
    \ idxs(int pos){\n    return pos<0?vector<int>():vs[pos].idxs;\n  }\n};\n//END\
    \ CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return\
    \ 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.cpp
  requiredBy:
  - string/ahocorasick.cpp
  timestamp: '2021-01-22 18:27:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1013.test.cpp
  - test/aoj/3073.test.cpp
  - test/aoj/2257.test.cpp
  - test/aoj/2212.test.cpp
documentation_of: string/trie.cpp
layout: document
redirect_from:
- /library/string/trie.cpp
- /library/string/trie.cpp.html
title: string/trie.cpp
---
