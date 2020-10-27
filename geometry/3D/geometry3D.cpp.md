---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://vjudge.net/problem/HDU-3662
  bundledCode: "#line 1 \"geometry/3D/geometry3D.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n//BEGIN CUT HERE\n\n#define EPS (1e-10)\n#define equals(a,b)\
    \ (fabs((a)-(b)) < EPS)\n#define PI 3.141592653589793238\nstruct Point3D{\n  double\
    \ x,y,z;\n  Point3D(){}\n  Point3D(double x,double y,double z):x(x),y(y),z(z){}\n\
    \  Point3D operator+(Point3D p) {return Point3D(x+p.x,y+p.y,z+p.z);}\n  Point3D\
    \ operator-(Point3D p) {return Point3D(x-p.x,y-p.y,z-p.z);}\n  Point3D operator*(double\
    \ k){return Point3D(x*k,y*k,z*k);}\n  Point3D operator/(double k){return Point3D(x/k,y/k,z/k);}\n\
    \  Point3D operator*(Point3D p){\n    return Point3D(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);\n\
    \  }\n  double operator^(Point3D p){\n    return x*p.x+y*p.y+z*p.z;\n  }\n  double\
    \ norm(){return x*x+y*y+z*z;}\n  double abs(){return sqrt(norm());}\n  bool operator\
    \ < (const Point3D &p) const{\n    if(x!=p.x) return x<p.x;\n    if(y!=p.y) return\
    \ y<p.y;\n    return z<p.z;\n  }\n  bool operator == (const Point3D &p) const{\n\
    \    return fabs(x-p.x)<EPS  and  fabs(y-p.y)<EPS  and  fabs(z-p.z)<EPS;\n  }\n\
    };\nistream &operator >> (istream &is,Point3D &p){\n  is>>p.x>>p.y>>p.z;\n  return\
    \ is;\n}\nostream &operator << (ostream &os,Point3D p){\n  os<<fixed<<setprecision(12)<<p.x<<\"\
    \ \"<<p.y<<\" \"<<p.z;\n  return os;\n}\n\ntypedef Point3D Vector3D;\ntypedef\
    \ vector<Point3D> Polygon3D;\n\nstruct Segment3D{\n  Point3D p1,p2;\n  Segment3D(){}\n\
    \  Segment3D(Point3D p1, Point3D p2):p1(p1),p2(p2){}\n};\ntypedef Segment3D Line3D;\n\
    \nistream &operator >> (istream &is,Segment3D &s){\n  is>>s.p1>>s.p2;\n  return\
    \ is;\n}\n\nstruct Sphere{\n  Point3D c;\n  double r;\n  Sphere(){}\n  Sphere(Point3D\
    \ c,double r):c(c),r(r){}\n};\n\nistream &operator >> (istream &is,Sphere &c){\n\
    \  is>>c.c>>c.r;\n  return is;\n}\n\ndouble norm(Vector3D a){\n  return a.x*a.x+a.y*a.y+a.z*a.z;\n\
    }\ndouble abs(Vector3D a){\n  return sqrt(norm(a));\n}\ndouble dot(Vector3D a,Vector3D\
    \ b){\n  return a.x*b.x+a.y*b.y+a.z*b.z;\n}\nVector3D cross(Vector3D a,Vector3D\
    \ b){\n  return Vector3D(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);\n}\n\
    \nPoint3D project(Line3D l,Point3D p){\n  Point3D b=l.p2-l.p1;\n  double t=dot(p-l.p1,b)/norm(b);\n\
    \  return l.p1+b*t;\n}\n\nPoint3D reflect(Line3D l,Point3D p){\n  return p+(project(l,p)-p)*2.0;\n\
    }\n\ndouble getDistanceLP(Line3D l,Point3D p){\n  return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));\n\
    }\n\ndouble getDistanceSP(Segment3D s,Point3D p){\n  if(dot(s.p2-s.p1,p-s.p1)\
    \ < 0.0 ) return abs(p-s.p1);\n  if(dot(s.p1-s.p2,p-s.p2) < 0.0 ) return abs(p-s.p2);\n\
    \  return getDistanceLP(s,p);\n}\n\nbool intersectSC(Segment3D s,Sphere c){\n\
    \  double d=getDistanceSP(s,c.c);\n  if(d>c.r) return 0;\n  return !((abs(s.p1-c.c)<=c.r)\
    \ and (abs(s.p2-c.c)<=c.r));\n}\n\nstruct ConvexHull3D{\n  struct face{\n    int\
    \ a,b,c;\n    bool ok;\n    face(){}\n    face(int a,int b,int c,bool ok):a(a),b(b),c(c),ok(ok){}\n\
    \  };\n  int n,num;\n  vector<Point3D> p;\n  vector<face> f;\n  vector<vector<int>\
    \ >  g;\n\n  ConvexHull3D(int n):n(n),p(n),f(n*8),g(n,vector<int>(n)){}\n\n  void\
    \ input(){\n    for(int i=0;i<n;i++) cin>>p[i];\n  }\n\n  double dblcmp(Point3D\
    \ q,face f){\n    Point3D m=p[f.b]-p[f.a];\n    Point3D n=p[f.c]-p[f.a];\n   \
    \ Point3D t=q-p[f.a];\n    return (m*n)^t;\n  }\n\n  void deal(int q,int a,int\
    \ b){\n    int idx=g[a][b];\n    face add;\n    if(f[idx].ok){\n      if(dblcmp(p[q],f[idx])>EPS)\
    \ dfs(q,idx);\n      else{\n        add=face(b,a,q,1);\n        g[q][b]=g[a][q]=g[b][a]=num;\n\
    \        f[num++]=add;\n      }\n    }\n  }\n\n  void dfs(int q,int now){\n  \
    \  f[now].ok=0;\n    deal(q,f[now].b,f[now].a);\n    deal(q,f[now].c,f[now].b);\n\
    \    deal(q,f[now].a,f[now].c);\n  }\n\n  void build(){\n    num=0;\n    if(n<4)\
    \ return;\n    bool flg=1;\n    for(int i=1;i<n;i++){\n      if(abs(p[0]-p[i])>EPS){\n\
    \        swap(p[1],p[i]);\n        flg=0;\n        break;\n      }\n    }\n  \
    \  if(flg) return;\n    flg=1;\n    for(int i=2;i<n;i++){\n      if(abs((p[0]-p[1])*(p[1]-p[i]))>EPS){\n\
    \        swap(p[2],p[i]);\n        flg=0;\n        break;\n      }\n    }\n  \
    \  if(flg) return;\n    flg=1;\n    for(int i=3;i<n;i++){\n      if(abs(((p[0]-p[1])*(p[1]-p[2]))^(p[0]-p[i]))>EPS){\n\
    \        swap(p[3],p[i]);\n        flg=0;\n        break;\n      }\n    }\n  \
    \  if(flg) return;\n    face add;\n    for(int i=0;i<4;i++){\n      add=face((i+1)%4,(i+2)%4,(i+3)%4,1);\n\
    \      if(dblcmp(p[i],add)>0) swap(add.b,add.c);\n      g[add.a][add.b]=g[add.b][add.c]=g[add.c][add.a]=num;\n\
    \      f[num++]=add;\n    }\n    for(int i=4;i<n;i++){\n      for(int j=0;j<num;j++){\n\
    \        if(f[j].ok and dblcmp(p[i],f[j])>EPS){\n          dfs(i,j);\n       \
    \   break;\n        }\n      }\n    }\n    int tmp=num;\n    num=0;\n    for(int\
    \ i=0;i<tmp;i++)\n      if(f[i].ok) f[num++]=f[i];\n  }\n\n  double volume(Point3D\
    \ a,Point3D b,Point3D c,Point3D d){\n    return ((b-a)*(c-a))^(d-a);\n  }\n\n\
    \  bool same(int s,int t){\n    Point3D &a=p[f[s].a];\n    Point3D &b=p[f[s].b];\n\
    \    Point3D &c=p[f[s].c];\n    return  (abs(volume(a,b,c,p[f[t].a]))<EPS)\n \
    \      and     (abs(volume(a,b,c,p[f[t].b]))<EPS)\n       and     (abs(volume(a,b,c,p[f[t].c]))<EPS);\n\
    \  }\n\n  int polygon(){\n    int res=0;\n    for(int i=0;i<num;i++){\n      int\
    \ flg=1;\n      for(int j=0;j<i;j++)\n        flg&=!same(i,j);\n      res+=flg;\n\
    \    }\n    return res;\n  }\n\n  int triangle(){\n    return num;\n  }\n\n  double\
    \ area(Point3D a,Point3D b,Point3D c){\n    return abs((b-a)*(c-a));\n  }\n\n\
    \  Point3D cross(Point3D a,Point3D b,Point3D c){\n    return Point3D((b.y-a.y)*(c.z-a.z)-(b.z-a.z)*(c.y-a.y),\n\
    \                   (b.z-a.z)*(c.x-a.x)-(b.x-a.x)*(c.z-a.z),\n               \
    \    (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x));\n  }\n\n  double area(){\n    double\
    \ res=0;\n    if(n==3){\n      Point3D q=cross(p[0],p[1],p[2]);\n      res=abs(q)/2.0;\n\
    \      return res;\n    }\n    return res;\n    for(int i=0;i<num;i++)\n     \
    \ res+=area(p[f[i].a],p[f[i].b],p[f[i].c]);\n    return res/2.0;\n  }\n};\n\n\
    //END CUT HERE\n\nsigned main(){\n  int n;\n  while(cin>>n){\n    ConvexHull3D\
    \ ch(n);\n    ch.input();\n    ch.build();\n    cout<<ch.polygon()<<endl;\n  }\n\
    \  return 0;\n}\n\n/*\n  verified on 2019/10/22\n  https://vjudge.net/problem/HDU-3662\n\
    */\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n//BEGIN CUT HERE\n\n#define\
    \ EPS (1e-10)\n#define equals(a,b) (fabs((a)-(b)) < EPS)\n#define PI 3.141592653589793238\n\
    struct Point3D{\n  double x,y,z;\n  Point3D(){}\n  Point3D(double x,double y,double\
    \ z):x(x),y(y),z(z){}\n  Point3D operator+(Point3D p) {return Point3D(x+p.x,y+p.y,z+p.z);}\n\
    \  Point3D operator-(Point3D p) {return Point3D(x-p.x,y-p.y,z-p.z);}\n  Point3D\
    \ operator*(double k){return Point3D(x*k,y*k,z*k);}\n  Point3D operator/(double\
    \ k){return Point3D(x/k,y/k,z/k);}\n  Point3D operator*(Point3D p){\n    return\
    \ Point3D(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);\n  }\n  double operator^(Point3D\
    \ p){\n    return x*p.x+y*p.y+z*p.z;\n  }\n  double norm(){return x*x+y*y+z*z;}\n\
    \  double abs(){return sqrt(norm());}\n  bool operator < (const Point3D &p) const{\n\
    \    if(x!=p.x) return x<p.x;\n    if(y!=p.y) return y<p.y;\n    return z<p.z;\n\
    \  }\n  bool operator == (const Point3D &p) const{\n    return fabs(x-p.x)<EPS\
    \  and  fabs(y-p.y)<EPS  and  fabs(z-p.z)<EPS;\n  }\n};\nistream &operator >>\
    \ (istream &is,Point3D &p){\n  is>>p.x>>p.y>>p.z;\n  return is;\n}\nostream &operator\
    \ << (ostream &os,Point3D p){\n  os<<fixed<<setprecision(12)<<p.x<<\" \"<<p.y<<\"\
    \ \"<<p.z;\n  return os;\n}\n\ntypedef Point3D Vector3D;\ntypedef vector<Point3D>\
    \ Polygon3D;\n\nstruct Segment3D{\n  Point3D p1,p2;\n  Segment3D(){}\n  Segment3D(Point3D\
    \ p1, Point3D p2):p1(p1),p2(p2){}\n};\ntypedef Segment3D Line3D;\n\nistream &operator\
    \ >> (istream &is,Segment3D &s){\n  is>>s.p1>>s.p2;\n  return is;\n}\n\nstruct\
    \ Sphere{\n  Point3D c;\n  double r;\n  Sphere(){}\n  Sphere(Point3D c,double\
    \ r):c(c),r(r){}\n};\n\nistream &operator >> (istream &is,Sphere &c){\n  is>>c.c>>c.r;\n\
    \  return is;\n}\n\ndouble norm(Vector3D a){\n  return a.x*a.x+a.y*a.y+a.z*a.z;\n\
    }\ndouble abs(Vector3D a){\n  return sqrt(norm(a));\n}\ndouble dot(Vector3D a,Vector3D\
    \ b){\n  return a.x*b.x+a.y*b.y+a.z*b.z;\n}\nVector3D cross(Vector3D a,Vector3D\
    \ b){\n  return Vector3D(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);\n}\n\
    \nPoint3D project(Line3D l,Point3D p){\n  Point3D b=l.p2-l.p1;\n  double t=dot(p-l.p1,b)/norm(b);\n\
    \  return l.p1+b*t;\n}\n\nPoint3D reflect(Line3D l,Point3D p){\n  return p+(project(l,p)-p)*2.0;\n\
    }\n\ndouble getDistanceLP(Line3D l,Point3D p){\n  return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));\n\
    }\n\ndouble getDistanceSP(Segment3D s,Point3D p){\n  if(dot(s.p2-s.p1,p-s.p1)\
    \ < 0.0 ) return abs(p-s.p1);\n  if(dot(s.p1-s.p2,p-s.p2) < 0.0 ) return abs(p-s.p2);\n\
    \  return getDistanceLP(s,p);\n}\n\nbool intersectSC(Segment3D s,Sphere c){\n\
    \  double d=getDistanceSP(s,c.c);\n  if(d>c.r) return 0;\n  return !((abs(s.p1-c.c)<=c.r)\
    \ and (abs(s.p2-c.c)<=c.r));\n}\n\nstruct ConvexHull3D{\n  struct face{\n    int\
    \ a,b,c;\n    bool ok;\n    face(){}\n    face(int a,int b,int c,bool ok):a(a),b(b),c(c),ok(ok){}\n\
    \  };\n  int n,num;\n  vector<Point3D> p;\n  vector<face> f;\n  vector<vector<int>\
    \ >  g;\n\n  ConvexHull3D(int n):n(n),p(n),f(n*8),g(n,vector<int>(n)){}\n\n  void\
    \ input(){\n    for(int i=0;i<n;i++) cin>>p[i];\n  }\n\n  double dblcmp(Point3D\
    \ q,face f){\n    Point3D m=p[f.b]-p[f.a];\n    Point3D n=p[f.c]-p[f.a];\n   \
    \ Point3D t=q-p[f.a];\n    return (m*n)^t;\n  }\n\n  void deal(int q,int a,int\
    \ b){\n    int idx=g[a][b];\n    face add;\n    if(f[idx].ok){\n      if(dblcmp(p[q],f[idx])>EPS)\
    \ dfs(q,idx);\n      else{\n        add=face(b,a,q,1);\n        g[q][b]=g[a][q]=g[b][a]=num;\n\
    \        f[num++]=add;\n      }\n    }\n  }\n\n  void dfs(int q,int now){\n  \
    \  f[now].ok=0;\n    deal(q,f[now].b,f[now].a);\n    deal(q,f[now].c,f[now].b);\n\
    \    deal(q,f[now].a,f[now].c);\n  }\n\n  void build(){\n    num=0;\n    if(n<4)\
    \ return;\n    bool flg=1;\n    for(int i=1;i<n;i++){\n      if(abs(p[0]-p[i])>EPS){\n\
    \        swap(p[1],p[i]);\n        flg=0;\n        break;\n      }\n    }\n  \
    \  if(flg) return;\n    flg=1;\n    for(int i=2;i<n;i++){\n      if(abs((p[0]-p[1])*(p[1]-p[i]))>EPS){\n\
    \        swap(p[2],p[i]);\n        flg=0;\n        break;\n      }\n    }\n  \
    \  if(flg) return;\n    flg=1;\n    for(int i=3;i<n;i++){\n      if(abs(((p[0]-p[1])*(p[1]-p[2]))^(p[0]-p[i]))>EPS){\n\
    \        swap(p[3],p[i]);\n        flg=0;\n        break;\n      }\n    }\n  \
    \  if(flg) return;\n    face add;\n    for(int i=0;i<4;i++){\n      add=face((i+1)%4,(i+2)%4,(i+3)%4,1);\n\
    \      if(dblcmp(p[i],add)>0) swap(add.b,add.c);\n      g[add.a][add.b]=g[add.b][add.c]=g[add.c][add.a]=num;\n\
    \      f[num++]=add;\n    }\n    for(int i=4;i<n;i++){\n      for(int j=0;j<num;j++){\n\
    \        if(f[j].ok and dblcmp(p[i],f[j])>EPS){\n          dfs(i,j);\n       \
    \   break;\n        }\n      }\n    }\n    int tmp=num;\n    num=0;\n    for(int\
    \ i=0;i<tmp;i++)\n      if(f[i].ok) f[num++]=f[i];\n  }\n\n  double volume(Point3D\
    \ a,Point3D b,Point3D c,Point3D d){\n    return ((b-a)*(c-a))^(d-a);\n  }\n\n\
    \  bool same(int s,int t){\n    Point3D &a=p[f[s].a];\n    Point3D &b=p[f[s].b];\n\
    \    Point3D &c=p[f[s].c];\n    return  (abs(volume(a,b,c,p[f[t].a]))<EPS)\n \
    \      and     (abs(volume(a,b,c,p[f[t].b]))<EPS)\n       and     (abs(volume(a,b,c,p[f[t].c]))<EPS);\n\
    \  }\n\n  int polygon(){\n    int res=0;\n    for(int i=0;i<num;i++){\n      int\
    \ flg=1;\n      for(int j=0;j<i;j++)\n        flg&=!same(i,j);\n      res+=flg;\n\
    \    }\n    return res;\n  }\n\n  int triangle(){\n    return num;\n  }\n\n  double\
    \ area(Point3D a,Point3D b,Point3D c){\n    return abs((b-a)*(c-a));\n  }\n\n\
    \  Point3D cross(Point3D a,Point3D b,Point3D c){\n    return Point3D((b.y-a.y)*(c.z-a.z)-(b.z-a.z)*(c.y-a.y),\n\
    \                   (b.z-a.z)*(c.x-a.x)-(b.x-a.x)*(c.z-a.z),\n               \
    \    (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x));\n  }\n\n  double area(){\n    double\
    \ res=0;\n    if(n==3){\n      Point3D q=cross(p[0],p[1],p[2]);\n      res=abs(q)/2.0;\n\
    \      return res;\n    }\n    return res;\n    for(int i=0;i<num;i++)\n     \
    \ res+=area(p[f[i].a],p[f[i].b],p[f[i].c]);\n    return res/2.0;\n  }\n};\n\n\
    //END CUT HERE\n\nsigned main(){\n  int n;\n  while(cin>>n){\n    ConvexHull3D\
    \ ch(n);\n    ch.input();\n    ch.build();\n    cout<<ch.polygon()<<endl;\n  }\n\
    \  return 0;\n}\n\n/*\n  verified on 2019/10/22\n  https://vjudge.net/problem/HDU-3662\n\
    */\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/3D/geometry3D.cpp
  requiredBy: []
  timestamp: '2020-10-27 15:50:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/3D/geometry3D.cpp
layout: document
redirect_from:
- /library/geometry/3D/geometry3D.cpp
- /library/geometry/3D/geometry3D.cpp.html
title: geometry/3D/geometry3D.cpp
---
