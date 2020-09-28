---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: datastructure/slidingwindowaggregation.cpp
    title: datastructure/slidingwindowaggregation.cpp
  - icon: ':heavy_check_mark:'
    path: string/editdistance.cpp
    title: string/editdistance.cpp
  - icon: ':heavy_check_mark:'
    path: string/longestcommonsubstring.cpp
    title: string/longestcommonsubstring.cpp
  - icon: ':heavy_check_mark:'
    path: graph/nicetree.cpp
    title: graph/nicetree.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1607.test.cpp
    title: test/aoj/1607.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0596.test.cpp
    title: test/aoj/0596.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3037.test.cpp
    title: test/aoj/3037.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2790.test.cpp
    title: test/aoj/2790.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0391.test.cpp
    title: test/aoj/0391.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0415.test.cpp
    title: test/aoj/0415.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3069.test.cpp
    title: test/aoj/3069.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_A.linkcuttree.test.cpp
    title: test/aoj/GRL_5_A.linkcuttree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2736.test.cpp
    title: test/aoj/2736.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2230.test.cpp
    title: test/aoj/2230.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_3_B.test.cpp
    title: test/aoj/DPL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2290.test.cpp
    title: test/aoj/2290.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/3056.test.cpp
    title: test/aoj/geometry/3056.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/3049.test.cpp
    title: test/aoj/geometry/3049.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/2334.test.cpp
    title: test/aoj/geometry/2334.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2187.test.cpp
    title: test/aoj/2187.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2627.test.cpp
    title: test/aoj/2627.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_1_E.test.cpp
    title: test/aoj/DPL_1_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2975.test.cpp
    title: test/aoj/2975.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2308.test.cpp
    title: test/aoj/2308.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1549.test.cpp
    title: Verify succ, pred
  - icon: ':heavy_check_mark:'
    path: test/aoj/0613.test.cpp
    title: test/aoj/0613.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3069.lichao.test.cpp
    title: test/aoj/3069.lichao.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_10_C.test.cpp
    title: test/aoj/ALDS1_10_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3112.test.cpp
    title: test/aoj/3112.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4918.test.cpp
    title: test/yukicoder/4918.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/3912.test.cpp
    title: test/yukicoder/3912.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1732.test.cpp
    title: Verify quantile
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/3227.test.cpp
    title: test/yukicoder/3227.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4706.test.cpp
    title: test/yukicoder/4706.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tools/chminmax.cpp\"\n\n#ifndef call_from_test\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename\
    \ T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}\ntemplate<typename\
    \ T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}\n//END CUT HERE\n\
    #ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T1,typename T2> inline void\
    \ chmin(T1 &a,T2 b){if(a>b) a=b;}\ntemplate<typename T1,typename T2> inline void\
    \ chmax(T1 &a,T2 b){if(a<b) a=b;}\n//END CUT HERE\n#ifndef call_from_test\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/chminmax.cpp
  requiredBy:
  - datastructure/slidingwindowaggregation.cpp
  - string/editdistance.cpp
  - string/longestcommonsubstring.cpp
  - graph/nicetree.cpp
  timestamp: '2020-03-12 16:36:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1607.test.cpp
  - test/aoj/0596.test.cpp
  - test/aoj/3037.test.cpp
  - test/aoj/2790.test.cpp
  - test/aoj/0391.test.cpp
  - test/aoj/0415.test.cpp
  - test/aoj/3069.test.cpp
  - test/aoj/GRL_5_A.linkcuttree.test.cpp
  - test/aoj/2736.test.cpp
  - test/aoj/2230.test.cpp
  - test/aoj/DPL_3_B.test.cpp
  - test/aoj/2290.test.cpp
  - test/aoj/geometry/3056.test.cpp
  - test/aoj/geometry/3049.test.cpp
  - test/aoj/geometry/2334.test.cpp
  - test/aoj/2187.test.cpp
  - test/aoj/2627.test.cpp
  - test/aoj/DPL_1_E.test.cpp
  - test/aoj/2975.test.cpp
  - test/aoj/2308.test.cpp
  - test/aoj/1549.test.cpp
  - test/aoj/0613.test.cpp
  - test/aoj/3069.lichao.test.cpp
  - test/aoj/ALDS1_10_C.test.cpp
  - test/aoj/3112.test.cpp
  - test/yukicoder/4918.test.cpp
  - test/yukicoder/3912.test.cpp
  - test/yukicoder/1732.test.cpp
  - test/yukicoder/3227.test.cpp
  - test/yukicoder/4706.test.cpp
documentation_of: tools/chminmax.cpp
layout: document
redirect_from:
- /library/tools/chminmax.cpp
- /library/tools/chminmax.cpp.html
title: tools/chminmax.cpp
---
