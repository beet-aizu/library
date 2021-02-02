---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/3453.test.cpp
    title: Minimum Steiner Tree
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"toptree/steiner.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\nstruct Vertex{\n  void* handle;\n\
    \  int color;\n  Vertex(int color=0):handle(nullptr),color(color){}\n};\n\ntemplate<typename\
    \ T>\nstruct SteinerTree{\n  T con,len,lf,rg,md,chd,ans;\n  SteinerTree(T len=0):con(0),len(len),lf(0),rg(0),md(0),chd(0),ans(0){}\n\
    \  void toggle(){return swap(lf,rg);}\n  static SteinerTree compress(SteinerTree\
    \ x,Vertex* v,SteinerTree y){\n    if(x.chd){\n      if(!x.con){\n        x.con=1;\n\
    \        x.lf=x.len;\n        x.rg=0;\n        x.md=x.chd;\n      }else{\n   \
    \     x.ans+=x.md+x.rg+x.chd;\n        x.md=x.rg=x.chd=0;\n      }\n    }\n\n\
    \    if(!x.con and !(v->color) and !y.con)\n      return SteinerTree(x.len+y.len);\n\
    \n    SteinerTree nxt;\n    nxt.con=1;\n    nxt.lf=x.con?x.lf:(v->color?x.len:x.len+y.lf);\n\
    \    nxt.rg=y.con?y.rg:(v->color?y.len:y.len+x.rg);\n    nxt.ans=x.ans+y.ans;\n\
    \    if(x.con and (v->color or y.con)){\n      nxt.ans+=x.md+x.rg;\n      x.md=0;\n\
    \    }\n    if(y.con and (v->color or x.con)){\n      nxt.ans+=y.md+y.lf;\n  \
    \    y.md=0;\n    }\n    nxt.md=x.md+y.md;\n    return nxt;\n  }\n\n  static SteinerTree\
    \ rake(SteinerTree x,SteinerTree y){\n    x.chd+=y.chd+y.rg+y.md;\n    x.ans+=y.ans;\n\
    \    return x;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE\
    \ HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\nstruct Vertex{\n  void* handle;\n  int color;\n  Vertex(int\
    \ color=0):handle(nullptr),color(color){}\n};\n\ntemplate<typename T>\nstruct\
    \ SteinerTree{\n  T con,len,lf,rg,md,chd,ans;\n  SteinerTree(T len=0):con(0),len(len),lf(0),rg(0),md(0),chd(0),ans(0){}\n\
    \  void toggle(){return swap(lf,rg);}\n  static SteinerTree compress(SteinerTree\
    \ x,Vertex* v,SteinerTree y){\n    if(x.chd){\n      if(!x.con){\n        x.con=1;\n\
    \        x.lf=x.len;\n        x.rg=0;\n        x.md=x.chd;\n      }else{\n   \
    \     x.ans+=x.md+x.rg+x.chd;\n        x.md=x.rg=x.chd=0;\n      }\n    }\n\n\
    \    if(!x.con and !(v->color) and !y.con)\n      return SteinerTree(x.len+y.len);\n\
    \n    SteinerTree nxt;\n    nxt.con=1;\n    nxt.lf=x.con?x.lf:(v->color?x.len:x.len+y.lf);\n\
    \    nxt.rg=y.con?y.rg:(v->color?y.len:y.len+x.rg);\n    nxt.ans=x.ans+y.ans;\n\
    \    if(x.con and (v->color or y.con)){\n      nxt.ans+=x.md+x.rg;\n      x.md=0;\n\
    \    }\n    if(y.con and (v->color or x.con)){\n      nxt.ans+=y.md+y.lf;\n  \
    \    y.md=0;\n    }\n    nxt.md=x.md+y.md;\n    return nxt;\n  }\n\n  static SteinerTree\
    \ rake(SteinerTree x,SteinerTree y){\n    x.chd+=y.chd+y.rg+y.md;\n    x.ans+=y.ans;\n\
    \    return x;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE\
    \ HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: toptree/steiner.cpp
  requiredBy: []
  timestamp: '2020-10-27 16:52:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/3453.test.cpp
documentation_of: toptree/steiner.cpp
layout: document
redirect_from:
- /library/toptree/steiner.cpp
- /library/toptree/steiner.cpp.html
title: toptree/steiner.cpp
---
