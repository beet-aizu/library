---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/sort_points_by_argument.test.cpp
    title: test/yosupo/sort_points_by_argument.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"geometry/argsort.cpp\"\n\n#ifndef call_from_test\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#endif\n//BEGIN CUT HERE\n// (-pi, pi],\
    \ atan2(0, 0) = 0\ntemplate<typename P>\nvoid argsort(vector<P> &ps){\n  auto\
    \ getA=\n    [&](P p){\n      if(p.x>=0 and p.y>=0) return 0;\n      if(p.y>=0)\
    \ return 1;\n      if(p.x<=0) return -2;\n      return -1;\n    };\n  auto cross=[&](P\
    \ a,P b){return a.x*b.y-a.y*b.x;};\n  auto cmp=\n    [&](P a,P b){\n      if(getA(a)!=getA(b))\
    \ return getA(a)<getA(b);\n      if(a.x==0 and a.y==0) return !(b.x==0 and b.y==0);\n\
    \      if(b.x==0 and b.y==0) return false;\n      return cross(a,b)>0;\n    };\n\
    \  sort(ps.begin(),ps.end(),cmp);\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\n// (-pi, pi], atan2(0, 0) = 0\ntemplate<typename\
    \ P>\nvoid argsort(vector<P> &ps){\n  auto getA=\n    [&](P p){\n      if(p.x>=0\
    \ and p.y>=0) return 0;\n      if(p.y>=0) return 1;\n      if(p.x<=0) return -2;\n\
    \      return -1;\n    };\n  auto cross=[&](P a,P b){return a.x*b.y-a.y*b.x;};\n\
    \  auto cmp=\n    [&](P a,P b){\n      if(getA(a)!=getA(b)) return getA(a)<getA(b);\n\
    \      if(a.x==0 and a.y==0) return !(b.x==0 and b.y==0);\n      if(b.x==0 and\
    \ b.y==0) return false;\n      return cross(a,b)>0;\n    };\n  sort(ps.begin(),ps.end(),cmp);\n\
    }\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/argsort.cpp
  requiredBy: []
  timestamp: '2020-03-14 17:16:27+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/sort_points_by_argument.test.cpp
documentation_of: geometry/argsort.cpp
layout: document
redirect_from:
- /library/geometry/argsort.cpp
- /library/geometry/argsort.cpp.html
title: geometry/argsort.cpp
---
