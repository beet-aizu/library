---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/skewheap.cpp
    title: datastructure/skewheap.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/skewheap.cpp: line 72: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../datastructure/skewheap.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  using Heap=SkewHeap<int, int>;\n\
    \  auto g=[](int a,int b){return a+b;};\n  auto c=[](int a,int b){return a<b;};\n\
    \  int INF = -1;\n  Heap heap(g,g,c,INF,0);\n  auto base=heap.push(0);\n\n  string\
    \ s;\n  while(cin>>s,s!=\"end\"){\n    int x;\n    if(s==\"insert\"){\n      cin>>x;\n\
    \      base=heap.meld(base,heap.push(x));\n    }\n    if(s==\"extract\"){\n  \
    \    x=heap.top(base);\n      base=heap.pop(base);\n      cout<<x<<\"\\n\";\n\
    \    }\n  }\n  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - datastructure/skewheap.cpp
  isVerificationFile: true
  path: test/aoj/ALDS1_9_C.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 13:13:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_9_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_9_C.test.cpp
- /verify/test/aoj/ALDS1_9_C.test.cpp.html
title: test/aoj/ALDS1_9_C.test.cpp
---
