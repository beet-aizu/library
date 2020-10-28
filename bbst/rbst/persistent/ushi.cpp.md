---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bbst/rbst/basic/base.cpp
    title: bbst/rbst/basic/base.cpp
  - icon: ':question:'
    path: bbst/rbst/basic/ushi.cpp
    title: bbst/rbst/basic/ushi.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/0437.test.cpp
    title: test/aoj/0437.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ bbst/rbst/persistent/ushi.cpp: line 7: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n#define call_from_test\n#include \"../basic/base.cpp\"\n#include \"../basic/ushi.cpp\"\
    \n#undef call_from_test\n\n#endif\n//BEGIN CUT HERE\ntemplate<typename Node, size_t\
    \ LIM>\nstruct PersistentUshi : Ushi<Node, LIM>{\n  using super = Ushi<Node, LIM>;\n\
    \  using super::super;\n  using T = typename Node::T;\n\n  inline Node* clone(Node*\
    \ t){\n    if(t==nullptr) return t;\n    return super::create(*t);\n  }\n\n  Node*\
    \ eval(Node* t){\n    t=clone(t);\n    if(t->rev){\n      t->l=clone(t->l);\n\
    \      t->r=clone(t->r);\n    }\n    return super::eval(t);\n  }\n\n  T query(Node\
    \ *a,size_t l,size_t r){\n    auto s=super::split(a,l);\n    auto t=super::split(s.second,r-l);\n\
    \    return super::query(t.first);\n  }\n\n  Node* rebuild(Node* a){\n    auto\
    \ vs=super::dump(a);\n    super::size=0;\n    return super::build(vector<Node>(vs.begin(),vs.end()));\n\
    \  }\n\n  bool almost_full() const{\n    return super::size>LIM*9/10;\n  }\n};\n\
    //END CUT HERE\n//INSERT ABOVE HERE\n#ifndef call_from_test\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn:
  - bbst/rbst/basic/base.cpp
  - bbst/rbst/basic/ushi.cpp
  isVerificationFile: false
  path: bbst/rbst/persistent/ushi.cpp
  requiredBy: []
  timestamp: '2020-10-28 16:34:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/0437.test.cpp
documentation_of: bbst/rbst/persistent/ushi.cpp
layout: document
redirect_from:
- /library/bbst/rbst/persistent/ushi.cpp
- /library/bbst/rbst/persistent/ushi.cpp.html
title: bbst/rbst/persistent/ushi.cpp
---
