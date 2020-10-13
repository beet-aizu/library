---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/unionfind.cpp
    title: datastructure/unionfind.cpp
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.cpp
    title: graph/kruskal.cpp
  - icon: ':heavy_check_mark:'
    path: linearalgebra/matrix.cpp
    title: linearalgebra/matrix.cpp
  - icon: ':question:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0314.test.cpp
    title: test/aoj/0314.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/arc018/tasks/arc018_4
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ linearalgebra/tree_theorem.cpp: line 8: unable to process #include in #if /\
    \ #ifdef / #ifndef other than include guards\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define call_from_test\n#include \"matrix.cpp\"\n#include \"../datastructure/unionfind.cpp\"\
    \n#undef call_from_test\n\n#endif\n//BEGIN CUT HERE\ntemplate<typename K, typename\
    \ T>\nstruct MatrixTreeTheorem{\n  using M = Matrix<K>;\n  struct edge{\n    int\
    \ a,b;\n    T c;\n    edge(int a,int b,T c):a(a),b(b),c(c){}\n    bool operator<(const\
    \ edge &e)const{\n      return c<e.c;\n    }\n  };\n\n  vector<edge> es;\n  vector<int>\
    \ used;\n  vector<vector<int> > H;\n  UnionFind uf;\n\n  MatrixTreeTheorem(int\
    \ n):used(n),H(n),uf(n){}\n\n  void add_edge(int a,int b,T c){\n    es.emplace_back(a,b,c);\n\
    \  }\n\n  vector<int> bfs(int v){\n    vector<int> vs;\n    queue<int> q;\n  \
    \  used[v]=1;\n    q.emplace(v);\n    while(!q.empty()){\n      v=q.front();q.pop();\n\
    \      vs.emplace_back(v);\n      for(int u:H[v]){\n        if(used[u]) continue;\n\
    \        used[u]=1;\n        q.emplace(u);\n      }\n    }\n    return vs;\n \
    \ }\n\n  K build(){\n    sort(es.begin(),es.end());\n    fill(used.begin(),used.end(),0);\n\
    \    K res(1);\n    for(int i=0;i<(int)es.size();){\n      queue<int> q,r;\n \
    \     for(auto &h:H) h.clear();\n      int p=i;\n      while(i<(int)es.size()&&es[i].c==es[p].c){\n\
    \        int u=uf.find(es[i].a);\n        int v=uf.find(es[i++].b);\n        H[u].emplace_back(v);\n\
    \        H[v].emplace_back(u);\n        q.emplace(u);q.emplace(v);\n        r.emplace(u);r.emplace(v);\n\
    \      }\n      while(!q.empty()){\n        int v=q.front();q.pop();\n       \
    \ if(used[v]) continue;\n        vector<int> vs=bfs(v);\n        int m=vs.size();\n\
    \        if(m==1) continue;\n\n        sort(vs.begin(),vs.end());\n        auto\
    \ idx=\n          [&](int x){\n            return lower_bound(vs.begin(),vs.end(),x)-vs.begin();\n\
    \          };\n        M A(m,m);\n        for(int x:vs)\n          for(int y:H[x])\n\
    \            if(x!=y) A[idx(x)][idx(y)]-=K(1);\n\n        for(int x=0;x<m;x++)\n\
    \          for(int y=0;y<m;y++)\n            if(x!=y) A[x][x]-=A[x][y];\n\n  \
    \      A.dat.pop_back();\n        for(auto &a:A.dat) a.pop_back();\n\n       \
    \ res*=A.determinant();\n        for(int x:vs) uf.unite(v,x);\n      }\n     \
    \ while(!r.empty()){\n        int v=r.front();r.pop();\n        used[v]=0;\n \
    \     }\n    }\n    return res;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    \n#define call_from_test\n#include \"../mod/mint.cpp\"\n#include \"../graph/kruskal.cpp\"\
    \n#undef call_from_test\n\n//INSERT ABOVE HERE\nsigned ARC018_D(){\n  using M\
    \ = Mint<int>;\n  int n,m;\n  scanf(\"%d %d\",&n,&m);\n  MatrixTreeTheorem<M,\
    \ int> mtt(n);\n  Kruskal<int> G(n);\n  for(int i=0;i<m;i++){\n    int a,b,c;\n\
    \    scanf(\"%d %d %d\",&a,&b,&c);\n    a--;b--;\n    mtt.add_edge(a,b,c);\n \
    \   G.add_edge(a,b,c);\n  }\n  printf(\"%d %d\\n\",G.build(),mtt.build().v);\n\
    \  return 0;\n}\n/*\n  verified on 2018/10/30\n  https://atcoder.jp/contests/arc018/tasks/arc018_4\n\
    */\n\nsigned main(){\n  ARC018_D();\n  return 0;\n}\n#endif\n"
  dependsOn:
  - linearalgebra/matrix.cpp
  - datastructure/unionfind.cpp
  - mod/mint.cpp
  - graph/kruskal.cpp
  isVerificationFile: false
  path: linearalgebra/tree_theorem.cpp
  requiredBy: []
  timestamp: '2020-10-09 14:11:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0314.test.cpp
documentation_of: linearalgebra/tree_theorem.cpp
layout: document
redirect_from:
- /library/linearalgebra/tree_theorem.cpp
- /library/linearalgebra/tree_theorem.cpp.html
title: linearalgebra/tree_theorem.cpp
---
