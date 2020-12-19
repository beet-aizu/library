---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/base.cpp
    title: formalpowerseries/base.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/diff.cpp
    title: formalpowerseries/diff.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/div.cpp
    title: formalpowerseries/div.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/exp.cpp
    title: formalpowerseries/exp.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/integral.cpp
    title: formalpowerseries/integral.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/inv.cpp
    title: formalpowerseries/inv.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/log.cpp
    title: formalpowerseries/log.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/mod.cpp
    title: formalpowerseries/mod.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/pow.cpp
    title: formalpowerseries/pow.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/shift.cpp
    title: formalpowerseries/shift.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/sqrt.cpp
    title: formalpowerseries/sqrt.cpp
  - icon: ':heavy_check_mark:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ formalpowerseries/base.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: '#ifndef call_from_test

    #include <bits/stdc++.h>

    using namespace std;

    #endif


    //BEGIN CUT HERE

    #define call_from_test

    #include "../mod/mint.cpp"

    #include "../combinatorics/enumeration.cpp"

    #include "../formalpowerseries/base.cpp"

    #include "../formalpowerseries/inv.cpp"

    #include "../formalpowerseries/div.cpp"

    #include "../formalpowerseries/mod.cpp"

    #include "../formalpowerseries/sqrt.cpp"

    #include "../formalpowerseries/diff.cpp"

    #include "../formalpowerseries/integral.cpp"

    #include "../formalpowerseries/log.cpp"

    #include "../formalpowerseries/exp.cpp"

    #include "../formalpowerseries/pow.cpp"

    #include "../formalpowerseries/shift.cpp"

    #undef call_from_test

    //END CUT HERE

    '
  dependsOn:
  - mod/mint.cpp
  - combinatorics/enumeration.cpp
  - formalpowerseries/base.cpp
  - formalpowerseries/inv.cpp
  - formalpowerseries/div.cpp
  - formalpowerseries/mod.cpp
  - formalpowerseries/sqrt.cpp
  - formalpowerseries/diff.cpp
  - formalpowerseries/integral.cpp
  - formalpowerseries/log.cpp
  - formalpowerseries/exp.cpp
  - formalpowerseries/pow.cpp
  - formalpowerseries/shift.cpp
  isVerificationFile: false
  path: includes/formalpowerseries.h
  requiredBy: []
  timestamp: '2020-11-22 17:38:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: includes/formalpowerseries.h
layout: document
redirect_from:
- /library/includes/formalpowerseries.h
- /library/includes/formalpowerseries.h.html
title: includes/formalpowerseries.h
---
