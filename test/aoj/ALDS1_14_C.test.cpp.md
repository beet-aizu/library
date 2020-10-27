---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/rectanglehash.cpp
    title: string/rectanglehash.cpp
  - icon: ':question:'
    path: string/rollinghash.cpp
    title: string/rollinghash.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/rectanglehash.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../string/rollinghash.cpp\"\n#include \"../../string/rectanglehash.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int h,w;\n  cin>>h>>w;\n  vector<string> ss(h);\n  for(int i=0;i<h;i++) cin>>ss[i];\n\
    \n  int r,c;\n  cin>>r>>c;\n  vector<string> ts(r);\n  for(int i=0;i<r;i++) cin>>ts[i];\n\
    \n  const int MOD = 1e9+7;\n  const int B1 = 1777771;\n  const int B2 = 1e8+7;\n\
    \  auto srh=rectangle_hash<int, MOD, B1, B2>(ss,r,c);\n  auto trh=rectangle_hash<int,\
    \ MOD, B1, B2>(ts,r,c);\n\n  for(int i=0;i<h-r+1;i++)\n    for(int j=0;j<w-c+1;j++)\n\
    \      if(srh[i][j]==trh[0][0]) cout<<i<<\" \"<<j<<\"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - string/rollinghash.cpp
  - string/rectanglehash.cpp
  isVerificationFile: true
  path: test/aoj/ALDS1_14_C.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 19:04:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_C.test.cpp
- /verify/test/aoj/ALDS1_14_C.test.cpp.html
title: test/aoj/ALDS1_14_C.test.cpp
---
