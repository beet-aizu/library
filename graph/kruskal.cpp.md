---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/unionfind.cpp
    title: datastructure/unionfind.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/voronoiminimumspanningtree.cpp
    title: graph/voronoiminimumspanningtree.cpp
  - icon: ':heavy_check_mark:'
    path: linearalgebra/tree_theorem.cpp
    title: linearalgebra/tree_theorem.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0403.test.cpp
    title: test/aoj/0403.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/manhattanmst.test.cpp
    title: test/yosupo/manhattanmst.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/kruskal.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../datastructure/unionfind.cpp\"\n#undef call_from_test\n\
    \n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct Kruskal : UnionFind{\n\
    \  using UnionFind::UnionFind;\n  struct Edge{\n    int src,dst;\n    T cost;\n\
    \    int used;\n    Edge(int src,int dst,T cost):\n      src(src),dst(dst),cost(cost),used(0){}\n\
    \    bool operator<(const Edge& o) const{\n      return cost<o.cost;\n    }\n\
    \  };\n\n  vector<Edge> es;\n  void add_edge(int u,int v,T c){\n    es.emplace_back(u,v,c);\n\
    \  }\n\n  T build(){\n    sort(es.begin(),es.end());\n    T res=0;\n    for(auto\
    \ &e:es){\n      if(same(e.src,e.dst)) continue;\n      res+=e.cost;\n      unite(e.src,e.dst);\n\
    \      e.used=1;\n    }\n    return res;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    int main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - datastructure/unionfind.cpp
  isVerificationFile: false
  path: graph/kruskal.cpp
  requiredBy:
  - graph/voronoiminimumspanningtree.cpp
  - linearalgebra/tree_theorem.cpp
  timestamp: '2020-10-27 19:32:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/manhattanmst.test.cpp
  - test/aoj/0403.test.cpp
  - test/aoj/GRL_2_A.test.cpp
documentation_of: graph/kruskal.cpp
layout: document
redirect_from:
- /library/graph/kruskal.cpp
- /library/graph/kruskal.cpp.html
title: graph/kruskal.cpp
---
