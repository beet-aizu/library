---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"graph/chebyshevneighbors.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct ChebyshevNeighbors{\n\
    \  struct Point{\n    T x,y;\n    int idx,idy;\n    Point(){}\n    Point(T x,T\
    \ y,int idx):x(x),y(y),idx(idx),idy(-1){}\n    bool operator<(const Point &a)const{\n\
    \      if(y!=a.y) return y>a.y;\n      return x<a.x;\n    }\n  };\n\n  vector<T>\
    \ xs,ys;\n  ChebyshevNeighbors(vector<T> xs,vector<T> ys):xs(xs),ys(ys){}\n\n\
    \  vector<Point> ps,bk;\n\n  void chk(int idx,int j){\n    if(idx<0) return;\n\
    \    int &idy=ps[j].idy;\n    if(idy<0||xs[idy]<xs[idx]) idy=idx;\n  }\n\n  void\
    \ upd(int &idx,int i){\n    if(idx<0||xs[idx]<ps[i].x) idx=ps[i].idx;\n  }\n\n\
    \  void dfs(int l,int r){\n    if(l+1==r) return;\n    int m=(l+r)>>1;\n    dfs(l,m);dfs(m,r);\n\
    \n    {\n      int i=l,j=m,idx=-1;\n      while(i<m||j<r){\n        if(i==m||j==r){\n\
    \          if(i==m) chk(idx,j++);\n          if(j==r) upd(idx,i++);\n        \
    \  continue;\n        }\n        ps[i].x+ps[i].y<=ps[j].x+ps[j].y?upd(idx,i++):chk(idx,j++);\n\
    \      }\n    }\n\n    {\n      int i=l,j=m,k=l;\n      for(int i=l;i<r;i++) bk[i]=ps[i];\n\
    \      while(i<m||j<r){\n        if(i==m||j==r) ps[k++]=bk[(j==r?i:j)++];\n  \
    \      else ps[k++]=bk[(bk[i].x+bk[i].y<=bk[j].x+bk[j].y?i:j)++];\n      }\n \
    \   }\n  }\n\n  vector< pair<int, int> > build(){\n    vector< pair<int, int>\
    \ > res;\n    int n=xs.size();\n    ps.resize(n);bk.resize(n);\n    for(int b=0;b<4;b++){\n\
    \      for(int i=0;i<n;i++){\n        if(b&1) swap(xs[i],ys[i]);\n        if(b&2)\
    \ xs[i]*=-1;\n        ps[i]=Point(xs[i],ys[i],i);\n      }\n      sort(ps.begin(),ps.end());\n\
    \      dfs(0,n);\n      for(int i=0;i<n;i++){\n        if(b&1) swap(xs[i],ys[i]);\n\
    \        if(b&2) xs[i]*=-1;\n        if(ps[i].idy<0) continue;\n        int u=ps[i].idx,v=ps[i].idy;\n\
    \        if(u>v) swap(u,v);\n        res.emplace_back(u,v);\n      }\n    }\n\
    \    return res;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\n//INSERT\
    \ ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename T>\nstruct ChebyshevNeighbors{\n  struct Point{\n\
    \    T x,y;\n    int idx,idy;\n    Point(){}\n    Point(T x,T y,int idx):x(x),y(y),idx(idx),idy(-1){}\n\
    \    bool operator<(const Point &a)const{\n      if(y!=a.y) return y>a.y;\n  \
    \    return x<a.x;\n    }\n  };\n\n  vector<T> xs,ys;\n  ChebyshevNeighbors(vector<T>\
    \ xs,vector<T> ys):xs(xs),ys(ys){}\n\n  vector<Point> ps,bk;\n\n  void chk(int\
    \ idx,int j){\n    if(idx<0) return;\n    int &idy=ps[j].idy;\n    if(idy<0||xs[idy]<xs[idx])\
    \ idy=idx;\n  }\n\n  void upd(int &idx,int i){\n    if(idx<0||xs[idx]<ps[i].x)\
    \ idx=ps[i].idx;\n  }\n\n  void dfs(int l,int r){\n    if(l+1==r) return;\n  \
    \  int m=(l+r)>>1;\n    dfs(l,m);dfs(m,r);\n\n    {\n      int i=l,j=m,idx=-1;\n\
    \      while(i<m||j<r){\n        if(i==m||j==r){\n          if(i==m) chk(idx,j++);\n\
    \          if(j==r) upd(idx,i++);\n          continue;\n        }\n        ps[i].x+ps[i].y<=ps[j].x+ps[j].y?upd(idx,i++):chk(idx,j++);\n\
    \      }\n    }\n\n    {\n      int i=l,j=m,k=l;\n      for(int i=l;i<r;i++) bk[i]=ps[i];\n\
    \      while(i<m||j<r){\n        if(i==m||j==r) ps[k++]=bk[(j==r?i:j)++];\n  \
    \      else ps[k++]=bk[(bk[i].x+bk[i].y<=bk[j].x+bk[j].y?i:j)++];\n      }\n \
    \   }\n  }\n\n  vector< pair<int, int> > build(){\n    vector< pair<int, int>\
    \ > res;\n    int n=xs.size();\n    ps.resize(n);bk.resize(n);\n    for(int b=0;b<4;b++){\n\
    \      for(int i=0;i<n;i++){\n        if(b&1) swap(xs[i],ys[i]);\n        if(b&2)\
    \ xs[i]*=-1;\n        ps[i]=Point(xs[i],ys[i],i);\n      }\n      sort(ps.begin(),ps.end());\n\
    \      dfs(0,n);\n      for(int i=0;i<n;i++){\n        if(b&1) swap(xs[i],ys[i]);\n\
    \        if(b&2) xs[i]*=-1;\n        if(ps[i].idy<0) continue;\n        int u=ps[i].idx,v=ps[i].idy;\n\
    \        if(u>v) swap(u,v);\n        res.emplace_back(u,v);\n      }\n    }\n\
    \    return res;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\n//INSERT\
    \ ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0403.test.cpp
    title: test/aoj/0403.test.cpp
  extendedVerifiedWith: []
  isVerificationFile: false
  path: graph/chebyshevneighbors.cpp
  requiredBy:
  - test/aoj/0403.test.cpp
  timestamp: '2019-11-21 16:50:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: graph/chebyshevneighbors.cpp
layout: document
redirect_from:
- /library/graph/chebyshevneighbors.cpp
- /library/graph/chebyshevneighbors.cpp.html
title: graph/chebyshevneighbors.cpp
---
