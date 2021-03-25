---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bbst/rbst/rbst.cpp
    title: bbst/rbst/rbst.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0438.test.cpp
    title: test find_by_order, order_of_key
  - icon: ':heavy_check_mark:'
    path: test/aoj/1508.test.cpp
    title: test/aoj/1508.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1579.test.cpp
    title: test/aoj/1579.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2890.test.cpp
    title: test order_of_key
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.bbst.test.cpp
    title: test/aoj/DSL_2_F.bbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.bbst.test.cpp
    title: test/aoj/DSL_2_G.bbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H.bbst.test.cpp
    title: test/aoj/DSL_2_H.bbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I.bbst.test.cpp
    title: test/aoj/DSL_2_I.bbst.test.cpp
  - icon: ':x:'
    path: test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
    title: test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ bbst/rbst/impl/basic.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../rbst.cpp\"\n#undef call_from_test\n\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename Data, size_t LIM>\nstruct Basic : RBST<Basic<Data,\
    \ LIM>, Data, typename Data::Node, LIM>{\n  using super = RBST<Basic, Data, typename\
    \ Data::Node, LIM>;\n  using Node = typename Data::Node;\n\n  Data data;\n\n \
    \ template<class... Args>\n  Basic(Args... args):data(forward<Args>(args)...){}\n\
    \n  inline Node* touch(Node *t){return data.eval(t);}\n\n  using super::toggle;\n\
    \  inline void toggle(Node *t){return data.toggle(t);}\n  template<typename E>\n\
    \  inline void propagate(Node *t,E x){return data.propagate(t,x);}\n  inline Node*\
    \ pushup(Node *t){return data.pushup(t);}\n\n  inline decltype(auto) get_val(Node\
    \ *a,size_t k){\n    return data.get_val(super::get_val(a,k));\n  }\n\n  using\
    \ super::query;\n  inline decltype(auto) query(Node *a){\n    return data.reflect(a);\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - bbst/rbst/rbst.cpp
  isVerificationFile: false
  path: bbst/rbst/impl/basic.cpp
  requiredBy: []
  timestamp: '2020-11-04 18:35:12+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
  - test/aoj/DSL_2_H.bbst.test.cpp
  - test/aoj/DSL_2_F.bbst.test.cpp
  - test/aoj/1579.test.cpp
  - test/aoj/0438.test.cpp
  - test/aoj/1508.test.cpp
  - test/aoj/DSL_2_G.bbst.test.cpp
  - test/aoj/2890.test.cpp
  - test/aoj/DSL_2_I.bbst.test.cpp
documentation_of: bbst/rbst/impl/basic.cpp
layout: document
redirect_from:
- /library/bbst/rbst/impl/basic.cpp
- /library/bbst/rbst/impl/basic.cpp.html
title: bbst/rbst/impl/basic.cpp
---
