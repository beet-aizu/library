---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bbst/rbst/basic/base.cpp
    title: bbst/rbst/basic/base.cpp
  - icon: ':question:'
    path: bbst/rbst/persistent/base.cpp
    title: bbst/rbst/persistent/base.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/persistent_queue.test.cpp
    title: test/yosupo/persistent_queue.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
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
    #define call_from_test\n#include \"../basic/base.cpp\"\n#include \"base.cpp\"\n\
    #undef call_from_test\n\n#endif\n//BEGIN CUT HERE\ntemplate<typename Tp>\nstruct\
    \ NodeBase{\n  using T = Tp;\n  NodeBase *l,*r,*p;\n  size_t cnt;\n  bool rev;\n\
    \  T val;\n  NodeBase(T val):\n    cnt(1),rev(0),val(val){l=r=p=nullptr;}\n};\n\
    \ntemplate<typename Node, size_t LIM>\nstruct PersistentArray :\n  PersistentBase<Node,\
    \ LIM, PersistentArray<Node, LIM>>{\n  using super = PersistentBase<Node, LIM,\
    \ PersistentArray>;\n  using T = typename Node::T;\n\n  inline void toggle(Node\
    \ *t){\n    swap(t->l,t->r);\n    t->rev^=1;\n  }\n\n  using super::clone;\n \
    \ inline Node* eval(Node* t){\n    t=clone(t);\n    if(t->rev){\n      t->l=clone(t->l);\n\
    \      t->r=clone(t->r);\n    }\n    return t;\n  }\n\n  using super::count;\n\
    \  inline Node* pushup(Node *t){\n    t->cnt=count(t->l)+1+count(t->r);\n    return\
    \ t;\n  }\n\n  using super::find_by_order;\n\n  Node* set_val(Node *a,size_t k,T\
    \ val){\n    auto b=find_by_order(a,k);\n    b->val=val;\n    return b;\n  }\n\
    \n  T get_val(Node *a,size_t k){\n    return find_by_order(a,k)->val;\n  }\n};\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned JOISC2012_COPYPASTE(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int m;\n  string buf;\n  cin>>m>>buf;\n\
    \n  using Node = NodeBase<char>;\n  const size_t LIM = 1e7;\n  PersistentArray<Node,\
    \ LIM> pa;\n\n  vector<Node> vs(buf.begin(),buf.end());\n  auto rt=pa.build(vs);\n\
    \n  int n;\n  cin>>n;\n  for(int i=0;i<n;i++){\n    int a,b,c;\n    cin>>a>>b>>c;\n\
    \    auto s=pa.split(rt,a);\n    auto t=pa.split(s.second,b-a);\n    auto u=pa.split(rt,c);\n\
    \    rt=pa.merge(pa.merge(u.first,t.first),u.second);\n\n    if((int)pa.count(rt)>m)\n\
    \      rt=pa.split(rt,m).first;\n\n    if(pa.almost_full()) rt=pa.rebuild(rt);\n\
    \  }\n\n  auto ds=pa.dump(rt);\n  buf.resize(ds.size());\n  for(int i=0;i<(int)ds.size();i++)\
    \ buf[i]=ds[i].val;\n  cout<<buf<<endl;\n  return 0;\n}\n/*\n  verified on 2020/10/28\n\
    \  https://atcoder.jp/contests/joisc2012/tasks/joisc2012_copypaste\n*/\n\nsigned\
    \ main(){\n  JOISC2012_COPYPASTE();\n  return 0;\n}\n#endif\n"
  dependsOn:
  - bbst/rbst/basic/base.cpp
  - bbst/rbst/persistent/base.cpp
  isVerificationFile: false
  path: bbst/rbst/persistent/array.cpp
  requiredBy: []
  timestamp: '2020-10-28 18:43:09+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/persistent_queue.test.cpp
documentation_of: bbst/rbst/persistent/array.cpp
layout: document
redirect_from:
- /library/bbst/rbst/persistent/array.cpp
- /library/bbst/rbst/persistent/array.cpp.html
title: bbst/rbst/persistent/array.cpp
---
