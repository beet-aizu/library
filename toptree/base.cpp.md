---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 2 \"toptree/base.cpp\"\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\nstruct Vertex{\n  void* handle;\n\
    \  Vertex():handle(nullptr){}\n};\nstruct Cluster{\n  Cluster(){}\n  void toggle(){}\n\
    \  static Cluster compress(Cluster x,Vertex *v,Cluster y){}\n  static Cluster\
    \ rake(Cluster x,Cluster y){}\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT\
    \ ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\nstruct Vertex{\n  void* handle;\n  Vertex():handle(nullptr){}\n\
    };\nstruct Cluster{\n  Cluster(){}\n  void toggle(){}\n  static Cluster compress(Cluster\
    \ x,Vertex *v,Cluster y){}\n  static Cluster rake(Cluster x,Cluster y){}\n};\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: toptree/base.cpp
  requiredBy: []
  timestamp: '2020-04-01 20:29:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: toptree/base.cpp
layout: document
redirect_from:
- /library/toptree/base.cpp
- /library/toptree/base.cpp.html
title: toptree/base.cpp
---
