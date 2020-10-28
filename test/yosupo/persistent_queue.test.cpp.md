---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/basic/base.cpp
    title: bbst/rbst/basic/base.cpp
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/persistent/array.cpp
    title: bbst/rbst/persistent/array.cpp
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/persistent/base.cpp
    title: bbst/rbst/persistent/base.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_queue
    links:
    - https://judge.yosupo.jp/problem/persistent_queue
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ bbst/rbst/persistent/base.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\n\n\
    #include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../bbst/rbst/basic/base.cpp\"\n#include \"../../bbst/rbst/persistent/base.cpp\"\
    \n#include \"../../bbst/rbst/persistent/array.cpp\"\n#undef call_from_test\n\n\
    #ifdef SANITIZE\n#define IGNORE\n#endif\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  using Node = NodeBase<int>;\n  const int LIM = 2e7;\n  PersistentArray<Node,\
    \ LIM> pa;\n  Node* rt=pa.create(0);\n\n  int q;\n  cin>>q;\n  vector<Node*> ss(q,nullptr);\n\
    \  for(int i=0;i<q;i++){\n    int a;\n    cin>>a;\n    if(a==0){\n      int t,x;\n\
    \      cin>>t>>x;\n      Node* p=~t?ss[t]:rt;\n      ss[i]=pa.insert(p,p->cnt,Node(x));\n\
    \    }\n    if(a==1){\n      int t;\n      cin>>t;\n      cout<<pa.get_val(ss[t],1)<<\"\
    \\n\";\n      ss[i]=pa.erase(ss[t],1);\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - bbst/rbst/basic/base.cpp
  - bbst/rbst/persistent/base.cpp
  - bbst/rbst/persistent/array.cpp
  isVerificationFile: true
  path: test/yosupo/persistent_queue.test.cpp
  requiredBy: []
  timestamp: '2020-10-28 18:29:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/persistent_queue.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/persistent_queue.test.cpp
- /verify/test/yosupo/persistent_queue.test.cpp.html
title: test/yosupo/persistent_queue.test.cpp
---
