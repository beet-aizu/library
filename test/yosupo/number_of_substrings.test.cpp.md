---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/longestcommonprefix.cpp: line 6: unable to process #include in #if /\
    \ #ifdef / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../string/suffixarray.cpp\"\n#include \"../../string/longestcommonprefix.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  string s;\n  cin>>s;\n  LongestCommonPrefix lcp(s);\n\n  int n=s.size();\n\
    \  long long ans=0;\n  for(int i=0;i<n;i++)\n    ans+=(n-lcp.sa[i+1])-lcp.query(i,i+1);\n\
    \n  cout<<ans<<endl;\n  return 0;\n}\n"
  dependsOn:
  - string/suffixarray.cpp
  - string/longestcommonprefix.cpp
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/suffixarray.cpp
    title: string/suffixarray.cpp
  - icon: ':heavy_check_mark:'
    path: string/longestcommonprefix.cpp
    title: string/longestcommonprefix.cpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: test/yosupo/number_of_substrings.test.cpp
  requiredBy: []
  timestamp: '2020-03-05 21:02:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: test/yosupo/number_of_substrings.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/number_of_substrings.test.cpp
- /verify/test/yosupo/number_of_substrings.test.cpp.html
title: test/yosupo/number_of_substrings.test.cpp
---
