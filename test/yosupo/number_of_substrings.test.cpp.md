---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/longestcommonprefix.cpp
    title: Longest Common Prefix
  - icon: ':heavy_check_mark:'
    path: string/suffixarray.cpp
    title: Suffix Array
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
    links:
    - https://judge.yosupo.jp/problem/number_of_substrings
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/longestcommonprefix.cpp: line 6: unable to process #include in #if /\
    \ #ifdef / #ifndef other than include guards\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/number_of_substrings\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../string/suffixarray.cpp\"\n#include \"../../string/longestcommonprefix.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  string s;\n  cin>>s;\n  LongestCommonPrefix lcp(s);\n\n  int n=s.size();\n\
    \  long long ans=0;\n  for(int i=0;i<n;i++)\n    ans+=(n-lcp.sa[i+1])-lcp.query(i,i+1);\n\
    \n  cout<<ans<<endl;\n  return 0;\n}\n"
  dependsOn:
  - string/suffixarray.cpp
  - string/longestcommonprefix.cpp
  isVerificationFile: true
  path: test/yosupo/number_of_substrings.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 19:04:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/number_of_substrings.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/number_of_substrings.test.cpp
- /verify/test/yosupo/number_of_substrings.test.cpp.html
title: test/yosupo/number_of_substrings.test.cpp
---
