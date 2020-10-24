---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/basic/array.cpp
    title: bbst/rbst/basic/array.cpp
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/basic/base.cpp
    title: bbst/rbst/basic/base.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_queue.test.cpp
    title: test/yosupo/persistent_queue.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/joisc2012/tasks/joisc2012_copypaste
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ bbst/rbst/persistent/array.cpp: line 6: unable to process #include in #if /\
    \ #ifdef / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../basic/base.cpp\"\n#include \"../basic/array.cpp\"\
    \n#undef call_from_test\n\n#endif\n//BEGIN CUT HERE\ntemplate<typename Node, size_t\
    \ LIM>\nstruct PersistentArray : Array<Node, LIM>{\n  using super = Array<Node,\
    \ LIM>;\n  using super::super;\n\n  inline Node* clone(Node* a){\n    if(a==nullptr)\
    \ return a;\n    Node* b=super::create();\n    *b=*a;\n    return b;\n  }\n\n\
    \  Node* eval(Node* a){\n    a=clone(a);\n    if(a->rev){\n      a->l=clone(a->l);\n\
    \      a->r=clone(a->r);\n    }\n    return super::eval(a);\n  }\n\n  Node* rebuild(Node*\
    \ a){\n    auto v=super::dump(a);\n    super::ptr=0;\n    return super::build(v);\n\
    \  }\n\n  bool almost_full() const{\n    return super::ptr>LIM*9/10;\n  }\n};\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned JOISC2012_COPYPASTE(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int m;\n  string buf;\n  cin>>m>>buf;\n\
    \n  using Node = NodeBase<char>;\n  const size_t LIM = 1e7;\n  PersistentArray<Node,\
    \ LIM> pa;\n\n  vector<char> v(buf.begin(),buf.end());\n  auto rt=pa.build(v);\n\
    \n  int n;\n  cin>>n;\n  for(int i=0;i<n;i++){\n    int a,b,c;\n    cin>>a>>b>>c;\n\
    \    auto s=pa.split(rt,a);\n    auto t=pa.split(s.second,b-a);\n    auto u=pa.split(rt,c);\n\
    \    rt=pa.merge(pa.merge(u.first,t.first),u.second);\n\n    if((int)pa.count(rt)>m)\n\
    \      rt=pa.split(rt,m).first;\n\n    if(pa.almost_full()) rt=pa.rebuild(rt);\n\
    \  }\n\n  auto ds=pa.dump(rt);\n  buf.resize(ds.size());\n  for(int i=0;i<(int)ds.size();i++)\
    \ buf[i]=ds[i];\n  cout<<buf<<endl;\n  return 0;\n}\n/*\n  verified on 2019/10/22\n\
    \  https://atcoder.jp/contests/joisc2012/tasks/joisc2012_copypaste\n*/\n\nsigned\
    \ main(){\n  JOISC2012_COPYPASTE();\n  return 0;\n}\n#endif\n"
  dependsOn:
  - bbst/rbst/basic/base.cpp
  - bbst/rbst/basic/array.cpp
  isVerificationFile: false
  path: bbst/rbst/persistent/array.cpp
  requiredBy: []
  timestamp: '2020-10-02 16:55:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/persistent_queue.test.cpp
documentation_of: bbst/rbst/persistent/array.cpp
layout: document
redirect_from:
- /library/bbst/rbst/persistent/array.cpp
- /library/bbst/rbst/persistent/array.cpp.html
title: bbst/rbst/persistent/array.cpp
---
