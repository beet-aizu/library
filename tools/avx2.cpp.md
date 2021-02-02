---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4271.avx2.test.cpp
    title: test/yukicoder/4271.avx2.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://beet-aizu.hatenablog.com/entry/2020/09/04/173522
  bundledCode: "#line 1 \"tools/avx2.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n// https://beet-aizu.hatenablog.com/entry/2020/09/04/173522\n\
    //BEGIN CUT HERE\n#pragma GCC optimize (\"O3\")\n#pragma GCC target (\"avx2\"\
    ) // or sse4\n#pragma GCC optimize(\"unroll-loops\")\n//END CUT HERE\n#ifndef\
    \ call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n// https://beet-aizu.hatenablog.com/entry/2020/09/04/173522\n//BEGIN CUT\
    \ HERE\n#pragma GCC optimize (\"O3\")\n#pragma GCC target (\"avx2\") // or sse4\n\
    #pragma GCC optimize(\"unroll-loops\")\n//END CUT HERE\n#ifndef call_from_test\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/avx2.cpp
  requiredBy: []
  timestamp: '2020-11-14 15:24:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/4271.avx2.test.cpp
documentation_of: tools/avx2.cpp
layout: document
redirect_from:
- /library/tools/avx2.cpp
- /library/tools/avx2.cpp.html
title: tools/avx2.cpp
---
