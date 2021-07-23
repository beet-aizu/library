---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/skewheap.cpp
    title: datastructure/skewheap.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2415.test.cpp
    title: test/aoj/2415.test.cpp
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
    \ algorithm/optimalbinarytree.cpp: line 6: unable to process #include in #if /\
    \ #ifdef / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../datastructure/skewheap.cpp\"\n#undef call_from_test\n\
    \n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nT optimalbinarytree(vector<T>\
    \ ws){\n  const T INF = numeric_limits<T>::max()/2;\n  using Heap=SkewHeap<T,\
    \ T>;\n\n  auto g=[](T a,T b){return a+b;};\n  auto c=[](T a,T b){return a>b;};\n\
    \  Heap heap(g,g,c,INF,0);\n\n  int n=ws.size();\n  vector<typename Heap::Node*\
    \ > hs(n-1,nullptr);\n  vector<int> ls(n),rs(n);\n  vector<T> cs(n-1);\n\n  using\
    \ P = pair<T, int>;\n  priority_queue<P,vector<P>,greater<P> > pq;\n  for(int\
    \ i=0;i<n-1;i++){\n    ls[i]=i-1;\n    rs[i]=i+1;\n    cs[i]=ws[i]+ws[i+1];\n\
    \    pq.emplace(cs[i],i);\n  }\n\n  T res=0;\n  for(int k=0;k<n-1;k++){\n    T\
    \ c;\n    int i;\n    do{\n      tie(c,i)=pq.top();pq.pop();\n    }while(rs[i]<0\
    \ or cs[i]!=c);\n\n    bool ml=false,mr=false;\n    if(ws[i]+heap.top(hs[i])==c){\n\
    \      hs[i]=heap.pop(hs[i]);\n      ml=true;\n    }else if(ws[i]+ws[rs[i]]==c){\n\
    \      ml=mr=true;\n    }else if(heap.top(hs[i])+heap.snd(hs[i])==c){\n      hs[i]=heap.pop(heap.pop(hs[i]));\n\
    \    }else{\n      hs[i]=heap.pop(hs[i]);\n      mr=true;\n    }\n\n    res+=c;\n\
    \    hs[i]=heap.meld(hs[i],heap.push(c));\n\n    if(ml) ws[i]=INF;\n    if(mr)\
    \ ws[rs[i]]=INF;\n\n    if(ml and i>0){\n      int j=ls[i];\n      hs[j]=heap.meld(hs[j],hs[i]);\n\
    \      rs[j]=rs[i];\n      rs[i]=-1;\n      ls[rs[j]]=j;\n      i=j;\n    }\n\n\
    \    if(mr and rs[i]+1<n){\n      int j=rs[i];\n      hs[i]=heap.meld(hs[i],hs[j]);\n\
    \      rs[i]=rs[j];\n      rs[j]=-1;\n      ls[rs[i]]=i;\n    }\n\n    cs[i]=min({ws[i]+ws[rs[i]],INF,\n\
    \               min(ws[i],ws[rs[i]])+heap.top(hs[i]),\n               heap.top(hs[i])+heap.snd(hs[i])});\n\
    \    pq.emplace(cs[i],i);\n  }\n  return res;\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - datastructure/skewheap.cpp
  isVerificationFile: false
  path: algorithm/optimalbinarytree.cpp
  requiredBy: []
  timestamp: '2020-10-27 13:13:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2415.test.cpp
documentation_of: algorithm/optimalbinarytree.cpp
layout: document
redirect_from:
- /library/algorithm/optimalbinarytree.cpp
- /library/algorithm/optimalbinarytree.cpp.html
title: algorithm/optimalbinarytree.cpp
---
