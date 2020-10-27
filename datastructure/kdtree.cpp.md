---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_2_C.test.cpp
    title: test/aoj/DSL_2_C.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructure/kdtree.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct KDTree{\n\
    \  static const int NIL = -1;\n\n  class Node{\n  public:\n    int pos,p,l,r;\n\
    \    Node(){pos=p=l=r=NIL;}\n  };\n\n  class Point{\n  public:\n    int id;\n\
    \    T x,y;\n    Point(){}\n    Point(int id,T x,T y): id(id),x(x),y(y){}\n  \
    \  bool operator<(const Point &p)const{\n      return id<p.id;\n    }\n  };\n\n\
    \  vector<Point> ps;\n  vector<Node> ts;\n  int np;\n\n  void add_point(int i,int\
    \ x,int y){\n    ps.emplace_back(i,x,y);\n    ts.emplace_back();\n  }\n\n  static\
    \ bool lessX(const Point &p1,const Point &p2){return p1.x<p2.x;}\n  static bool\
    \ lessY(const Point &p1,const Point &p2){return p1.y<p2.y;}\n\n  int dfs(int l,int\
    \ r,int depth){\n    if(l>=r) return NIL;\n    int mid=(l+r)/2;\n    int t=np++;\n\
    \    if(depth%2==0){\n      sort(ps.begin()+l,ps.begin()+r,lessX);\n    }else{\n\
    \      sort(ps.begin()+l,ps.begin()+r,lessY);\n    }\n    ts[t].pos=mid;\n   \
    \ ts[t].l=dfs(l,mid,depth+1);\n    ts[t].r=dfs(mid+1,r,depth+1);\n    return t;\n\
    \  }\n\n  int build(){\n    np=0;\n    return dfs(0,ps.size(),0);\n  }\n\n  //\
    \ [sx, tx] * [sy, ty]\n  void find(int v,T sx,T tx,T sy,T ty,int depth,vector<Point>\
    \ &ans){\n    T x=ps[ts[v].pos].x;\n    T y=ps[ts[v].pos].y;\n    if(sx<=x and\
    \ x<=tx and sy<=y and y<=ty)\n      ans.emplace_back(ps[ts[v].pos]);\n\n    if(depth%2==0){\n\
    \      if(ts[v].l!=NIL){\n        if(sx<=x) find(ts[v].l,sx,tx,sy,ty,depth+1,ans);\n\
    \      }\n      if(ts[v].r!=NIL){\n        if(x<=tx) find(ts[v].r,sx,tx,sy,ty,depth+1,ans);\n\
    \      }\n    }else{\n      if(ts[v].l!=NIL){\n        if(sy<=y) find(ts[v].l,sx,tx,sy,ty,depth+1,ans);\n\
    \      }\n      if(ts[v].r!=NIL){\n        if(y<=ty) find(ts[v].r,sx,tx,sy,ty,depth+1,ans);\n\
    \      }\n    }\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct KDTree{\n  static const\
    \ int NIL = -1;\n\n  class Node{\n  public:\n    int pos,p,l,r;\n    Node(){pos=p=l=r=NIL;}\n\
    \  };\n\n  class Point{\n  public:\n    int id;\n    T x,y;\n    Point(){}\n \
    \   Point(int id,T x,T y): id(id),x(x),y(y){}\n    bool operator<(const Point\
    \ &p)const{\n      return id<p.id;\n    }\n  };\n\n  vector<Point> ps;\n  vector<Node>\
    \ ts;\n  int np;\n\n  void add_point(int i,int x,int y){\n    ps.emplace_back(i,x,y);\n\
    \    ts.emplace_back();\n  }\n\n  static bool lessX(const Point &p1,const Point\
    \ &p2){return p1.x<p2.x;}\n  static bool lessY(const Point &p1,const Point &p2){return\
    \ p1.y<p2.y;}\n\n  int dfs(int l,int r,int depth){\n    if(l>=r) return NIL;\n\
    \    int mid=(l+r)/2;\n    int t=np++;\n    if(depth%2==0){\n      sort(ps.begin()+l,ps.begin()+r,lessX);\n\
    \    }else{\n      sort(ps.begin()+l,ps.begin()+r,lessY);\n    }\n    ts[t].pos=mid;\n\
    \    ts[t].l=dfs(l,mid,depth+1);\n    ts[t].r=dfs(mid+1,r,depth+1);\n    return\
    \ t;\n  }\n\n  int build(){\n    np=0;\n    return dfs(0,ps.size(),0);\n  }\n\n\
    \  // [sx, tx] * [sy, ty]\n  void find(int v,T sx,T tx,T sy,T ty,int depth,vector<Point>\
    \ &ans){\n    T x=ps[ts[v].pos].x;\n    T y=ps[ts[v].pos].y;\n    if(sx<=x and\
    \ x<=tx and sy<=y and y<=ty)\n      ans.emplace_back(ps[ts[v].pos]);\n\n    if(depth%2==0){\n\
    \      if(ts[v].l!=NIL){\n        if(sx<=x) find(ts[v].l,sx,tx,sy,ty,depth+1,ans);\n\
    \      }\n      if(ts[v].r!=NIL){\n        if(x<=tx) find(ts[v].r,sx,tx,sy,ty,depth+1,ans);\n\
    \      }\n    }else{\n      if(ts[v].l!=NIL){\n        if(sy<=y) find(ts[v].l,sx,tx,sy,ty,depth+1,ans);\n\
    \      }\n      if(ts[v].r!=NIL){\n        if(y<=ty) find(ts[v].r,sx,tx,sy,ty,depth+1,ans);\n\
    \      }\n    }\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/kdtree.cpp
  requiredBy: []
  timestamp: '2020-10-27 12:55:52+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_2_C.test.cpp
documentation_of: datastructure/kdtree.cpp
layout: document
redirect_from:
- /library/datastructure/kdtree.cpp
- /library/datastructure/kdtree.cpp.html
title: datastructure/kdtree.cpp
---
