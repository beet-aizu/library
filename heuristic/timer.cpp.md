---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"heuristic/timer.cpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n\n/**\n * @ignore\n */\n//BEGIN CUT HERE\nusing i16 = int16_t;\nusing\
    \ i32 = int32_t;\nusing i64 = int64_t;\n\nusing u16 = uint16_t;\nusing u32 = uint32_t;\n\
    using u64 = uint64_t;\n\n// AtCoder\nconst i64 CYCLES_PER_SEC = 2800000000;\n\n\
    struct Timer {\n\ti64 start;\n\tTimer(){reset();}\n\tvoid reset(){start=getCycle();}\n\
    \tinline double get(){return (double)(getCycle()-start)/CYCLES_PER_SEC;}\n\tinline\
    \ i64 getCycle(){\n\t\tu32 low,high;\n\t\t__asm__ volatile (\"rdtsc\" : \"=a\"\
    \ (low), \"=d\" (high));\n\t\treturn ((i64)low)|((i64)high<<32);\n\t}\n};\n\n\
    Timer timer;\n//END CUT HERE\n\n//INSERT ABOVE HERE\nvoid nxt(){\n  static i64\
    \ x = 0;\n  static i64 y = 1;\n  x=(x<<10)+y;\n  y=x/3;\n}\n\nsigned main(){\n\
    \  cout<<fixed<<setprecision(12);\n  auto start1=clock(),stop1=clock();\n  for(int\
    \ i=0;i<1000000;i++) stop1=clock();\n\n  double d=0;\n  auto start2=clock();\n\
    \  for(int i=0;i<1000000;i++) d+=timer.get();\n  auto stop2=clock();\n\n  cout<<(double)(stop1-start1)/CLOCKS_PER_SEC<<endl;\n\
    \  cout<<(double)(stop2-start2)/CLOCKS_PER_SEC<<endl;\n  return 0;\n}\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n\n/**\n * @ignore\n */\n//BEGIN\
    \ CUT HERE\nusing i16 = int16_t;\nusing i32 = int32_t;\nusing i64 = int64_t;\n\
    \nusing u16 = uint16_t;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\n// AtCoder\n\
    const i64 CYCLES_PER_SEC = 2800000000;\n\nstruct Timer {\n\ti64 start;\n\tTimer(){reset();}\n\
    \tvoid reset(){start=getCycle();}\n\tinline double get(){return (double)(getCycle()-start)/CYCLES_PER_SEC;}\n\
    \tinline i64 getCycle(){\n\t\tu32 low,high;\n\t\t__asm__ volatile (\"rdtsc\" :\
    \ \"=a\" (low), \"=d\" (high));\n\t\treturn ((i64)low)|((i64)high<<32);\n\t}\n\
    };\n\nTimer timer;\n//END CUT HERE\n\n//INSERT ABOVE HERE\nvoid nxt(){\n  static\
    \ i64 x = 0;\n  static i64 y = 1;\n  x=(x<<10)+y;\n  y=x/3;\n}\n\nsigned main(){\n\
    \  cout<<fixed<<setprecision(12);\n  auto start1=clock(),stop1=clock();\n  for(int\
    \ i=0;i<1000000;i++) stop1=clock();\n\n  double d=0;\n  auto start2=clock();\n\
    \  for(int i=0;i<1000000;i++) d+=timer.get();\n  auto stop2=clock();\n\n  cout<<(double)(stop1-start1)/CLOCKS_PER_SEC<<endl;\n\
    \  cout<<(double)(stop2-start2)/CLOCKS_PER_SEC<<endl;\n  return 0;\n}\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: heuristic/timer.cpp
  requiredBy: []
  timestamp: '2020-03-10 22:18:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: heuristic/timer.cpp
layout: document
redirect_from:
- /library/heuristic/timer.cpp
- /library/heuristic/timer.cpp.html
title: heuristic/timer.cpp
---
