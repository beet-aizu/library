---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"tools/all_permutations.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename F>\nvoid all_permutations(int\
    \ n,F f){\n  vector<int> vs(n);\n  iota(vs.begin(),vs.end(),0);\n  do f(vs); while(next_permutation(vs.begin(),vs.end()));\n\
    }\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename F>\nvoid all_permutations(int n,F f){\n  vector<int>\
    \ vs(n);\n  iota(vs.begin(),vs.end(),0);\n  do f(vs); while(next_permutation(vs.begin(),vs.end()));\n\
    }\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3053.test.cpp
    title: test/aoj/3053.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2187.test.cpp
    title: test/aoj/2187.test.cpp
  extendedVerifiedWith: []
  isVerificationFile: false
  path: tools/all_permutations.cpp
  requiredBy:
  - test/aoj/3053.test.cpp
  - test/aoj/2187.test.cpp
  timestamp: '2019-12-27 08:35:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: tools/all_permutations.cpp
layout: document
redirect_from:
- /library/tools/all_permutations.cpp
- /library/tools/all_permutations.cpp.html
title: tools/all_permutations.cpp
---
