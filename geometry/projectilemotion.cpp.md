---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2308.test.cpp
    title: test/aoj/2308.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"geometry/projectilemotion.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\n// throw from origin to (x,y)\
    \ with verocity v (x>0)\n// g: gravity\ntemplate<typename D>\nvector< pair<D,\
    \ D> > projectile_motion(D v,D g,D x,D y){\n  D a=x*x+y*y;\n  D b=g*x*x*y-v*v*x*x;\n\
    \  D c=g*g*x*x*x*x/4;\n  if(b*b<4*a*c) return {};\n  vector< pair<D, D> > res;\n\
    \  {\n    D p=(-b+sqrt(b*b-4*a*c))/(2*a);\n    if(0<p&&p<v*v) res.emplace_back(sqrt(p),sqrt(v*v-p));\n\
    \  }\n  {\n    D p=(-b-sqrt(b*b-4*a*c))/(2*a);\n    if(0<p&&p<v*v) res.emplace_back(sqrt(p),sqrt(v*v-p));\n\
    \  }\n  return res;\n}\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE\
    \ HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\n// throw from origin to (x,y) with verocity v (x>0)\n// g: gravity\n\
    template<typename D>\nvector< pair<D, D> > projectile_motion(D v,D g,D x,D y){\n\
    \  D a=x*x+y*y;\n  D b=g*x*x*y-v*v*x*x;\n  D c=g*g*x*x*x*x/4;\n  if(b*b<4*a*c)\
    \ return {};\n  vector< pair<D, D> > res;\n  {\n    D p=(-b+sqrt(b*b-4*a*c))/(2*a);\n\
    \    if(0<p&&p<v*v) res.emplace_back(sqrt(p),sqrt(v*v-p));\n  }\n  {\n    D p=(-b-sqrt(b*b-4*a*c))/(2*a);\n\
    \    if(0<p&&p<v*v) res.emplace_back(sqrt(p),sqrt(v*v-p));\n  }\n  return res;\n\
    }\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/projectilemotion.cpp
  requiredBy: []
  timestamp: '2020-01-12 16:26:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2308.test.cpp
documentation_of: geometry/projectilemotion.cpp
layout: document
redirect_from:
- /library/geometry/projectilemotion.cpp
- /library/geometry/projectilemotion.cpp.html
title: geometry/projectilemotion.cpp
---
