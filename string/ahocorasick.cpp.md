---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/trie.cpp
    title: string/trie.cpp
  _extendedRequiredBy: []
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/ahocorasick.cpp: line 6: unable to process #include in #if / #ifdef /\
    \ #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"trie.cpp\"\n#undef call_from_test\n\n#endif\n\
    //BEGIN CUT HERE\ntemplate<size_t X, bool heavy>\nstruct AhoCorasick : Trie<X+1>{\n\
    \  using super = Trie<X+1>;\n  using super::super, super::next, super::size;\n\
    \  using super::vs, super::conv;\n\n  vector<int> cnt,ord;\n\n  // O(\\sigma \\\
    sum |T_i|)\n  void build(){\n    int n=vs.size();\n    cnt.resize(n);\n    for(int\
    \ i=0;i<n;i++){\n      if(heavy) sort(vs[i].idxs.begin(),vs[i].idxs.end());\n\
    \      cnt[i]=vs[i].idxs.size();\n    }\n\n    queue<int> que;\n    for(int i=0;i<(int)X;i++){\n\
    \      if(~next(0,i)){\n        next(next(0,i),X)=0;\n        que.emplace(next(0,i));\n\
    \      }else{\n        next(0,i)=0;\n      }\n    }\n\n    while(!que.empty()){\n\
    \      ord.emplace_back(que.front());\n      auto &x=vs[que.front()];\n      int\
    \ fail=x.nxt[X];\n\n      cnt[que.front()]+=cnt[fail];\n      que.pop();\n\n \
    \     for(int i=0;i<(int)X;i++){\n        int &nx=x.nxt[i];\n        if(nx<0){\n\
    \          nx=next(fail,i);\n          continue;\n        }\n        que.emplace(nx);\n\
    \        next(nx,X)=next(fail,i);\n        if(heavy){\n          auto &idx=vs[nx].idxs;\n\
    \          auto &idy=vs[next(fail,i)].idxs;\n          vector<int> idz;\n    \
    \      set_union(idx.begin(),idx.end(),\n                    idy.begin(),idy.end(),\n\
    \                    back_inserter(idz));\n          idx=idz;\n        }\n   \
    \   }\n    }\n    reverse(ord.begin(),ord.end());\n  }\n\n  int count(int pos){\n\
    \    return cnt[pos];\n  }\n\n  // O(|S|)\n  long long match(string s){\n    long\
    \ long res=0;\n    int pos=0;\n    for(auto &c:s){\n      pos=next(pos,conv(c));\n\
    \      res+=count(pos);\n    }\n    return res;\n  }\n\n  // O(|S| + \\sum |T_i|)\n\
    \  vector<int> frequency(string s){\n    vector<int> res(size(),0);\n    int pos=0;\n\
    \    for(auto &c:s){\n      pos=next(pos,conv(c));\n      res[pos]++;\n    }\n\
    \    for(int p:ord)\n      res[vs[p].nxt[X]]+=res[p];\n    return res;\n  }\n\
    };\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - string/trie.cpp
  isVerificationFile: false
  path: string/ahocorasick.cpp
  requiredBy: []
  timestamp: '2021-01-22 18:37:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1013.test.cpp
  - test/aoj/3073.test.cpp
  - test/aoj/2257.test.cpp
  - test/aoj/2212.test.cpp
documentation_of: string/ahocorasick.cpp
layout: document
redirect_from:
- /library/string/ahocorasick.cpp
- /library/string/ahocorasick.cpp.html
title: string/ahocorasick.cpp
---
