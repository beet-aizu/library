---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bbst/rbst/basic/base.cpp
    title: bbst/rbst/basic/base.cpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: bbst/rbst/persistent/array.cpp
    title: bbst/rbst/persistent/array.cpp
  - icon: ':warning:'
    path: bbst/rbst/persistent/lazy.cpp
    title: bbst/rbst/persistent/lazy.cpp
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/persistent/ushi.cpp
    title: bbst/rbst/persistent/ushi.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0437.test.cpp
    title: test/aoj/0437.test.cpp
  - icon: ':x:'
    path: test/yosupo/persistent_queue.test.cpp
    title: test/yosupo/persistent_queue.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ bbst/rbst/persistent/base.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../basic/base.cpp\"\n#undef call_from_test\n\
    \n#endif\n//BEGIN CUT HERE\ntemplate<typename Node, size_t LIM, typename Impl>\n\
    struct PersistentBase : BBSTBase<Node, LIM, PersistentBase<Node, LIM, Impl>>{\n\
    \  using super = BBSTBase<Node, LIM, PersistentBase>;\n  using T = typename Node::T;\n\
    \n  static bool exist;\n  PersistentBase(){\n    // rebuild destroys all elements\
    \ in the pool\n    assert(!exchange(exist,true));\n  }\n\n  inline Node* clone(Node*\
    \ a){\n    if(a==nullptr) return a;\n    return super::create(*a);\n  }\n\n  inline\
    \ void toggle(Node *t){\n    static_cast<Impl*>(this)->toggle(t);\n  }\n\n  inline\
    \ Node* eval(Node *t){\n    return static_cast<Impl*>(this)->eval(t);\n  }\n\n\
    \  inline Node* pushup(Node *t){\n    return static_cast<Impl*>(this)->pushup(t);\n\
    \  }\n\n  using super::count;\n  void dump(Node* a,typename vector<Node>::iterator\
    \ it){\n    if(!count(a)) return;\n    a=eval(a);\n    auto cur=it+count(a->l);\n\
    \    dump(a->l,it);\n    dump(a->r,it+count(a->l)+1);\n    a->l=a->r=nullptr;\n\
    \    *cur=*pushup(a);\n  }\n\n  vector<Node> dump(Node* a){\n    assert(a!=nullptr);\n\
    \    vector<Node> vs(count(a),*a);\n    dump(a,vs.begin());\n    return vs;\n\
    \  }\n\n  Node* rebuild(Node* a){\n    auto vs=dump(a);\n    super::size=0;\n\
    \    return super::build(vs);\n  }\n\n  bool almost_full(double d=0.8) const{\n\
    \    return super::size>LIM*d;\n  }\n};\ntemplate<typename Node, size_t LIM, typename\
    \ Impl>\nbool PersistentBase<Node, LIM, Impl>::exist = false;\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n"
  dependsOn:
  - bbst/rbst/basic/base.cpp
  isVerificationFile: false
  path: bbst/rbst/persistent/base.cpp
  requiredBy:
  - bbst/rbst/persistent/ushi.cpp
  - bbst/rbst/persistent/array.cpp
  - bbst/rbst/persistent/lazy.cpp
  timestamp: '2020-10-28 18:43:09+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/0437.test.cpp
  - test/yosupo/persistent_queue.test.cpp
documentation_of: bbst/rbst/persistent/base.cpp
layout: document
redirect_from:
- /library/bbst/rbst/persistent/base.cpp
- /library/bbst/rbst/persistent/base.cpp.html
title: bbst/rbst/persistent/base.cpp
---
