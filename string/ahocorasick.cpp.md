---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/trie.cpp
    title: string/trie.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2257.test.cpp
    title: test/aoj/2257.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2212.test.cpp
    title: test/aoj/2212.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3073.test.cpp
    title: test/aoj/3073.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/ahocorasick.cpp: line 6: unable to process #include in #if / #ifdef /\
    \ #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"trie.cpp\"\n#undef call_from_test\n\n#endif\n\
    //BEGIN CUT HERE\ntemplate<size_t X>\nstruct AhoCorasick : Trie<X+1>{\n  using\
    \ TRIE = Trie<X+1>;\n  using TRIE::TRIE;\n  using TRIE::next;\n  vector<int> cnt;\n\
    \n  void build(int heavy=true){\n    auto &vs=TRIE::vs;\n    int n=vs.size();\n\
    \    cnt.resize(n);\n    for(int i=0;i<n;i++){\n      if(heavy) sort(vs[i].idxs.begin(),vs[i].idxs.end());\n\
    \      cnt[i]=vs[i].idxs.size();\n    }\n\n    queue<int> que;\n    for(int i=0;i<(int)X;i++){\n\
    \      if(~next(0,i)){\n        next(next(0,i),X)=0;\n        que.emplace(next(0,i));\n\
    \      }else{\n        next(0,i)=0;\n      }\n    }\n\n    while(!que.empty()){\n\
    \      auto &x=vs[que.front()];\n      int fail=x.nxt[X];\n\n      cnt[que.front()]+=cnt[fail];\n\
    \      que.pop();\n\n      for(int i=0;i<(int)X;i++){\n        int &nx=x.nxt[i];\n\
    \        if(nx<0){\n          nx=next(fail,i);\n          continue;\n        }\n\
    \        que.emplace(nx);\n        next(nx,X)=next(fail,i);\n        if(heavy){\n\
    \          auto &idx=vs[nx].idxs;\n          auto &idy=vs[next(fail,i)].idxs;\n\
    \          vector<int> idz;\n          set_union(idx.begin(),idx.end(),\n    \
    \                idy.begin(),idy.end(),\n                    back_inserter(idz));\n\
    \          idx=idz;\n        }\n      }\n    }\n  }\n\n  vector<int> match(string\
    \ s,int heavy=true){\n    auto &vs=TRIE::vs;\n    vector<int> res(heavy?TRIE::size():1);\n\
    \    int pos=0;\n    for(auto &c:s){\n      pos=next(pos,TRIE::conv(c));\n   \
    \   if(heavy) for(auto &x:vs[pos].idxs) res[x]++;\n      else res[0]+=cnt[pos];\n\
    \    }\n    return res;\n  }\n\n  int count(int pos){\n    return cnt[pos];\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n\
    }\n#endif\n"
  dependsOn:
  - string/trie.cpp
  isVerificationFile: false
  path: string/ahocorasick.cpp
  requiredBy: []
  timestamp: '2019-12-26 23:10:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2257.test.cpp
  - test/aoj/2212.test.cpp
  - test/aoj/3073.test.cpp
documentation_of: string/ahocorasick.cpp
layout: document
redirect_from:
- /library/string/ahocorasick.cpp
- /library/string/ahocorasick.cpp.html
title: string/ahocorasick.cpp
---
