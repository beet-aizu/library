---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"geometry/geometry.cpp\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\n#define EPS (1e-10)\n#define equals(a,b)\
    \ (fabs((a)-(b)) < EPS)\nconst double PI = asinl(1) * 2;\n\n// COUNTER CLOCKWISE\n\
    static const int CCW_COUNTER_CLOCKWISE = 1;\nstatic const int CCW_CLOCKWISE =\
    \ -1;\nstatic const int CCW_ONLINE_BACK = 2;\nstatic const int CCW_ONLINE_FRONT\
    \ = -2;\nstatic const int CCW_ON_SEGMENT = 0;\n\n// intercsect of circles\nstatic\
    \ const int ICC_SEPERATE = 4;\nstatic const int ICC_CIRCUMSCRIBE = 3;\nstatic\
    \ const int ICC_INTERSECT = 2;\nstatic const int ICC_INSCRIBE = 1;\nstatic const\
    \ int ICC_CONTAIN = 0;\n\nstruct Point{\n  double x,y;\n  Point(){}\n  Point(double\
    \ x,double y) :x(x),y(y){}\n  Point operator+(Point p) {return Point(x+p.x,y+p.y);}\n\
    \  Point operator-(Point p) {return Point(x-p.x,y-p.y);}\n  Point operator*(double\
    \ k){return Point(x*k,y*k);}\n  Point operator/(double k){return Point(x/k,y/k);}\n\
    \  double norm(){return x*x+y*y;}\n  double abs(){return sqrt(norm());}\n\n  bool\
    \ operator < (const Point &p) const{\n    return x!=p.x?x<p.x:y<p.y;\n    //grid-point\
    \ only\n    //return !equals(x,p.x)?x<p.x:!equals(y,p.y)?y<p.y:0;\n  }\n\n  bool\
    \ operator == (const Point &p) const{\n    return fabs(x-p.x)<EPS && fabs(y-p.y)<EPS;\n\
    \  }\n};\n\nstruct EndPoint{\n  Point p;\n  int seg,st;\n  EndPoint(){}\n  EndPoint(Point\
    \ p,int seg,int st):p(p),seg(seg),st(st){}\n  bool operator<(const EndPoint &ep)const{\n\
    \    if(p.y==ep.p.y) return st<ep.st;\n    return p.y<ep.p.y;\n  }\n};\n\nistream\
    \ &operator >> (istream &is,Point &p){\n  is>>p.x>>p.y;\n  return is;\n}\n\nostream\
    \ &operator << (ostream &os,Point p){\n  os<<fixed<<setprecision(12)<<p.x<<\"\
    \ \"<<p.y;\n  return os;\n}\n\nbool sort_x(Point a,Point b){\n  return a.x!=b.x?a.x<b.x:a.y<b.y;\n\
    }\n\nbool sort_y(Point a,Point b){\n  return a.y!=b.y?a.y<b.y:a.x<b.x;\n}\n\n\
    typedef Point Vector;\ntypedef vector<Point> Polygon;\n\nistream &operator >>\
    \ (istream &is,Polygon &p){\n  for(int i=0;i<(int)p.size();i++) is>>p[i];\n  return\
    \ is;\n}\n\nstruct Segment{\n  Point p1,p2;\n  Segment(){}\n  Segment(Point p1,\
    \ Point p2):p1(p1),p2(p2){}\n};\ntypedef Segment Line;\n\nistream &operator >>\
    \ (istream &is,Segment &s){\n  is>>s.p1>>s.p2;\n  return is;\n}\n\nstruct Circle{\n\
    \  Point c;\n  double r;\n  Circle(){}\n  Circle(Point c,double r):c(c),r(r){}\n\
    };\n\nistream &operator >> (istream &is,Circle &c){\n  is>>c.c>>c.r;\n  return\
    \ is;\n}\n\ndouble norm(Vector a){\n  return a.x*a.x+a.y*a.y;\n}\ndouble abs(Vector\
    \ a){\n  return sqrt(norm(a));\n}\ndouble dot(Vector a,Vector b){\n  return a.x*b.x+a.y*b.y;\n\
    }\ndouble cross(Vector a,Vector b){\n  return a.x*b.y-a.y*b.x;\n}\n\nPoint orth(Point\
    \ p){return Point(-p.y,p.x);}\n\nbool isOrthogonal(Vector a,Vector b){\n  return\
    \ equals(dot(a,b),0.0);\n}\n\nbool isOrthogonal(Point a1,Point a2,Point b1,Point\
    \ b2){\n  return isOrthogonal(a1-a2,b1-b2);\n}\n\nbool isOrthogonal(Segment s1,Segment\
    \ s2){\n  return equals(dot(s1.p2-s1.p1,s2.p2-s2.p1),0.0);\n}\n\nbool isParallel(Vector\
    \ a,Vector b){\n  return equals(cross(a,b),0.0);\n}\n\nbool isParallel(Point a1,Point\
    \ a2,Point b1,Point b2){\n  return isParallel(a1-a2,b1-b2);\n}\n\nbool isParallel(Segment\
    \ s1,Segment s2){\n  return equals(cross(s1.p2-s1.p1,s2.p2-s2.p1),0.0);\n}\n\n\
    Point project(Segment s,Point p){\n  Vector base=s.p2-s.p1;\n  double r=dot(p-s.p1,base)/norm(base);\n\
    \  return s.p1+base*r;\n}\n\nPoint reflect(Segment s,Point p){\n  return p+(project(s,p)-p)*2.0;\n\
    }\n\ndouble arg(Vector p){\n  return atan2(p.y,p.x);\n}\n\nVector polar(double\
    \ a,double r){\n  return Point(cos(r)*a,sin(r)*a);\n}\n\nint ccw(Point p0,Point\
    \ p1,Point p2);\nbool intersectSS(Point p1,Point p2,Point p3,Point p4);\nbool\
    \ intersectSS(Segment s1,Segment s2);\nbool intersectPS(Polygon p,Segment l);\n\
    int intersectCC(Circle c1,Circle c2);\nbool intersectSC(Segment s,Circle c);\n\
    double getDistanceLP(Line l,Point p);\ndouble getDistanceSP(Segment s,Point p);\n\
    double getDistanceSS(Segment s1,Segment s2);\nPoint getCrossPointSS(Segment s1,Segment\
    \ s2);\nPoint getCrossPointLL(Line l1,Line l2);\nPolygon getCrossPointCL(Circle\
    \ c,Line l);\nPolygon getCrossPointCC(Circle c1,Circle c2);\nint contains(Polygon\
    \ g,Point p);\nPolygon andrewScan(Polygon s);\nPolygon convex_hull(Polygon ps);\n\
    double diameter(Polygon s);\nbool isConvex(Polygon p);\ndouble area(Polygon s);\n\
    Polygon convexCut(Polygon p,Line l);\nLine bisector(Point p1,Point p2);\nVector\
    \ translate(Vector v,double theta);\nvector<Line> corner(Line l1,Line l2);\nvector<\
    \ vector<int> >\nsegmentArrangement(vector<Segment> &ss, Polygon &ps);\n\nint\
    \ ccw(Point p0,Point p1,Point p2){\n  Vector a = p1-p0;\n  Vector b = p2-p0;\n\
    \  if(cross(a,b) > EPS) return CCW_COUNTER_CLOCKWISE;\n  if(cross(a,b) < -EPS)\
    \ return CCW_CLOCKWISE;\n  if(dot(a,b) < -EPS) return CCW_ONLINE_BACK;\n  if(a.norm()<b.norm())\
    \ return CCW_ONLINE_FRONT;\n  return CCW_ON_SEGMENT;\n}\n\nbool intersectSS(Point\
    \ p1,Point p2,Point p3,Point p4){\n  return (ccw(p1,p2,p3)*ccw(p1,p2,p4) <= 0\
    \ &&\n          ccw(p3,p4,p1)*ccw(p3,p4,p2) <= 0 );\n}\n\nbool intersectSS(Segment\
    \ s1,Segment s2){\n  return intersectSS(s1.p1,s1.p2,s2.p1,s2.p2);\n}\n\nbool intersectPS(Polygon\
    \ p,Segment l){\n  int n=p.size();\n  for(int i=0;i<n;i++)\n    if(intersectSS(Segment(p[i],p[(i+1)%n]),l))\
    \ return 1;\n  return 0;\n}\n\nint intersectCC(Circle c1,Circle c2){\n  if(c1.r<c2.r)\
    \ swap(c1,c2);\n  double d=abs(c1.c-c2.c);\n  double r=c1.r+c2.r;\n  if(equals(d,r))\
    \ return ICC_CIRCUMSCRIBE;\n  if(d>r) return ICC_SEPERATE;\n  if(equals(d+c2.r,c1.r))\
    \ return ICC_INSCRIBE;\n  if(d+c2.r<c1.r) return ICC_CONTAIN;\n  return ICC_INTERSECT;\n\
    }\n\nbool intersectSC(Segment s,Circle c){\n  return getDistanceSP(s,c.c)<=c.r;\n\
    }\n\nint intersectCS(Circle c,Segment s){\n  if(norm(project(s,c.c)-c.c)-c.r*c.r>EPS)\
    \ return 0;\n  double d1=abs(c.c-s.p1),d2=abs(c.c-s.p2);\n  if(d1<c.r+EPS&&d2<c.r+EPS)\
    \ return 0;\n  if((d1<c.r-EPS&&d2>c.r+EPS)||(d1>c.r+EPS&&d2<c.r-EPS)) return 1;\n\
    \  Point h=project(s,c.c);\n  if(dot(s.p1-h,s.p2-h)<0) return 2;\n  return 0;\n\
    }\n\ndouble getDistanceLP(Line l,Point p){\n  return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));\n\
    }\n\ndouble getDistanceSP(Segment s,Point p){\n  if(dot(s.p2-s.p1,p-s.p1) < 0.0\
    \ ) return abs(p-s.p1);\n  if(dot(s.p1-s.p2,p-s.p2) < 0.0 ) return abs(p-s.p2);\n\
    \  return getDistanceLP(s,p);\n}\n\ndouble getDistanceSS(Segment s1,Segment s2){\n\
    \  if(intersectSS(s1,s2)) return 0.0;\n  return min(min(getDistanceSP(s1,s2.p1),getDistanceSP(s1,s2.p2)),\n\
    \             min(getDistanceSP(s2,s1.p1),getDistanceSP(s2,s1.p2)));\n}\n\nPoint\
    \ getCrossPointSS(Segment s1,Segment s2){\n  for(int k=0;k<2;k++){\n    if(getDistanceSP(s1,s2.p1)<EPS)\
    \ return s2.p1;\n    if(getDistanceSP(s1,s2.p2)<EPS) return s2.p2;\n    swap(s1,s2);\n\
    \  }\n  Vector base=s2.p2-s2.p1;\n  double d1=abs(cross(base,s1.p1-s2.p1));\n\
    \  double d2=abs(cross(base,s1.p2-s2.p1));\n  double t=d1/(d1+d2);\n  return s1.p1+(s1.p2-s1.p1)*t;\n\
    }\n\nPoint getCrossPointLL(Line l1,Line l2){\n  double a=cross(l1.p2-l1.p1,l2.p2-l2.p1);\n\
    \  double b=cross(l1.p2-l1.p1,l1.p2-l2.p1);\n  if(abs(a)<EPS&&abs(b)<EPS) return\
    \ l2.p1;\n  return l2.p1+(l2.p2-l2.p1)*(b/a);\n}\n\nPolygon getCrossPointCL(Circle\
    \ c,Line l){\n  Polygon ps;\n  Point pr=project(l,c.c);\n  Vector e=(l.p2-l.p1)/abs(l.p2-l.p1);\n\
    \  if(equals(getDistanceLP(l,c.c),c.r)){\n    ps.emplace_back(pr);\n    return\
    \ ps;\n  }\n  double base=sqrt(c.r*c.r-norm(pr-c.c));\n  ps.emplace_back(pr+e*base);\n\
    \  ps.emplace_back(pr-e*base);\n  return ps;\n}\n\nPolygon getCrossPointCS(Circle\
    \ c,Segment s){\n  Line l(s);\n  Polygon res=getCrossPointCL(c,l);\n  if(intersectCS(c,s)==2)\
    \ return res;\n  if(res.size()>1u){\n    if(dot(l.p1-res[0],l.p2-res[0])>0) swap(res[0],res[1]);\n\
    \    res.pop_back();\n  }\n  return res;\n}\n\n\nPolygon getCrossPointCC(Circle\
    \ c1,Circle c2){\n  Polygon p(2);\n  double d=abs(c1.c-c2.c);\n  double a=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));\n\
    \  double t=arg(c2.c-c1.c);\n  p[0]=c1.c+polar(c1.r,t+a);\n  p[1]=c1.c+polar(c1.r,t-a);\n\
    \  return p;\n}\n\n// IN:2 ON:1 OUT:0\nint contains(Polygon g,Point p){\n  int\
    \ n=g.size();\n  bool x=false;\n  for(int i=0;i<n;i++){\n    Point a=g[i]-p,b=g[(i+1)%n]-p;\n\
    \    if(fabs(cross(a,b)) < EPS && dot(a,b) < EPS) return 1;\n    if(a.y>b.y) swap(a,b);\n\
    \    if(a.y < EPS && EPS < b.y && cross(a,b) > EPS ) x = !x;\n  }\n  return (x?2:0);\n\
    }\n\nPolygon andrewScan(Polygon s){\n  Polygon u,l;\n  if(s.size()<3) return s;\n\
    \  sort(s.begin(),s.end());\n  u.push_back(s[0]);\n  u.push_back(s[1]);\n  l.push_back(s[s.size()-1]);\n\
    \  l.push_back(s[s.size()-2]);\n  for(int i=2;i<(int)s.size();i++){\n    for(int\
    \ n=u.size();\n        n>=2&&ccw(u[n-2],u[n-1],s[i])!=CCW_CLOCKWISE;\n       \
    \ n--){\n      u.pop_back();\n    }\n    u.push_back(s[i]);\n  }\n  for(int i=s.size()-3;i>=0;i--){\n\
    \    for(int n=l.size();\n        n>=2&&ccw(l[n-2],l[n-1],s[i])!=CCW_CLOCKWISE;\n\
    \        n--){\n      l.pop_back();\n    }\n    l.push_back(s[i]);\n  }\n  reverse(l.begin(),l.end());\n\
    \  for(int i=u.size()-2;i>=1;i--) l.push_back(u[i]);\n  return l;\n}\n\nPolygon\
    \ convex_hull(Polygon ps){\n  int n=ps.size();\n  sort(ps.begin(),ps.end(),sort_y);\n\
    \  int k=0;\n  Polygon qs(n*2);\n  for(int i=0;i<n;i++){\n    while(k>1&&cross(qs[k-1]-qs[k-2],ps[i]-qs[k-1])<0)\
    \ k--;\n    qs[k++]=ps[i];\n  }\n  for(int i=n-2,t=k;i>=0;i--){\n    while(k>t&&cross(qs[k-1]-qs[k-2],ps[i]-qs[k-1])<0)\
    \ k--;\n    qs[k++]=ps[i];\n  }\n  qs.resize(k-1);\n  return qs;\n}\n\ndouble\
    \ diameter(Polygon s){\n  Polygon p=s;\n  int n=p.size();\n  if(n==2) return abs(p[0]-p[1]);\n\
    \  int i=0,j=0;\n  for(int k=0;k<n;k++){\n    if(p[i]<p[k]) i=k;\n    if(!(p[j]<p[k]))\
    \ j=k;\n  }\n  double res=0;\n  int si=i,sj=j;\n  while(i!=sj||j!=si){\n    res=max(res,abs(p[i]-p[j]));\n\
    \    if(cross(p[(i+1)%n]-p[i],p[(j+1)%n]-p[j])<0.0){\n      i=(i+1)%n;\n    }else{\n\
    \      j=(j+1)%n;\n    }\n  }\n  return res;\n}\n\nbool isConvex(Polygon p){\n\
    \  bool f=1;\n  int n=p.size();\n  for(int i=0;i<n;i++){\n    int t=ccw(p[(i+n-1)%n],p[i],p[(i+1)%n]);\n\
    \    f&=t!=CCW_CLOCKWISE;\n  }\n  return f;\n}\n\ndouble area(Polygon s){\n  double\
    \ res=0;\n  for(int i=0;i<(int)s.size();i++){\n    res+=cross(s[i],s[(i+1)%s.size()])/2.0;\n\
    \  }\n  return res;\n}\n\ndouble area(Circle c1,Circle c2){\n  double d=abs(c1.c-c2.c);\n\
    \  if(c1.r+c2.r<=d+EPS) return 0;\n  if(d<=abs(c1.r-c2.r)){\n    double r=min(c1.r,c2.r);\n\
    \    return PI*r*r;\n  }\n  double res=0;\n  for(int k=0;k<2;k++){\n    double\
    \ rc=(d*d+c1.r*c1.r-c2.r*c2.r)/(2*d*c1.r);\n    double th=acosl(rc)*2;\n    res+=(th-sinl(th))*c1.r*c1.r/2;\n\
    \    swap(c1,c2);\n  }\n  return res;\n}\n\nPolygon convexCut(Polygon p,Line l){\n\
    \  Polygon q;\n  for(int i=0;i<(int)p.size();i++){\n    Point a=p[i],b=p[(i+1)%p.size()];\n\
    \    if(ccw(l.p1,l.p2,a)!=-1) q.push_back(a);\n    if(ccw(l.p1,l.p2,a)*ccw(l.p1,l.p2,b)<0)\n\
    \      q.push_back(getCrossPointLL(Line(a,b),l));\n  }\n  return q;\n}\n\nLine\
    \ bisector(Point p1,Point p2){\n  Circle c1=Circle(p1,abs(p1-p2)),c2=Circle(p2,abs(p1-p2));\n\
    \  Polygon p=getCrossPointCC(c1,c2);\n  if(cross(p2-p1,p[0]-p1)>0) swap(p[0],p[1]);\n\
    \  return Line(p[0],p[1]);\n}\n\nVector translate(Vector v,double theta){\n  Vector\
    \ res;\n  res.x=cos(theta)*v.x-sin(theta)*v.y;\n  res.y=sin(theta)*v.x+cos(theta)*v.y;\n\
    \  return res;\n}\n\nvector<Line> corner(Line l1,Line l2){\n  vector<Line> res;\n\
    \  if(isParallel(l1,l2)){\n    double d=getDistanceLP(l1,l2.p1)/2.0;\n    Vector\
    \ v1=l1.p2-l1.p1;\n    v1=v1/v1.abs()*d;\n    Point p=l2.p1+translate(v1,90.0*(PI/180.0));\n\
    \    double d1=getDistanceLP(l1,p);\n    double d2=getDistanceLP(l2,p);\n    if(abs(d1-d2)>d){\n\
    \      p=l2.p1+translate(v1,-90.0*(PI/180.0));\n    }\n    res.push_back(Line(p,p+v1));\n\
    \  }else{\n    Point p=getCrossPointLL(l1,l2);\n    Vector v1=l1.p2-l1.p1,v2=l2.p2-l2.p1;\n\
    \    v1=v1/v1.abs();\n    v2=v2/v2.abs();\n    res.push_back(Line(p,p+(v1+v2)));\n\
    \    res.push_back(Line(p,p+translate(v1+v2,90.0*(PI/180.0))));\n  }\n  return\
    \ res;\n}\n\nPolygon tangent(Circle c1,Point p2){\n  Circle c2=Circle(p2,sqrt(norm(c1.c-p2)-c1.r*c1.r));\n\
    \  Polygon p=getCrossPointCC(c1,c2);\n  sort(p.begin(),p.end());\n  return p;\n\
    }\n\nvector<Line> tangent(Circle c1,Circle c2){\n  vector<Line> ls;\n  if(c1.r<c2.r)\
    \ swap(c1,c2);\n  double g=norm(c1.c-c2.c);\n  if(equals(g,0)) return ls;\n  Point\
    \ u=(c2.c-c1.c)/sqrt(g);\n  Point v=orth(u);\n  for(int s=1;s>=-1;s-=2){\n   \
    \ double h=(c1.r+s*c2.r)/sqrt(g);\n    if(equals(1-h*h,0)){\n      ls.emplace_back(c1.c+u*c1.r,c1.c+(u+v)*c1.r);\n\
    \    }else if(1-h*h>0){\n      Point uu=u*h,vv=v*sqrt(1-h*h);\n      ls.emplace_back(c1.c+(uu+vv)*c1.r,c2.c-(uu+vv)*c2.r*s);\n\
    \      ls.emplace_back(c1.c+(uu-vv)*c1.r,c2.c-(uu-vv)*c2.r*s);\n    }\n  }\n\n\
    \  return ls;\n}\n\ndouble closest_pair(Polygon &a,int l=0,int r=-1){\n  if(r<0){\n\
    \    r=a.size();\n    sort(a.begin(),a.end(),sort_x);\n  }\n  if(r-l<=1) return\
    \ abs(a[0]-a[1]);\n  int m=(l+r)>>1;\n  double x=a[m].x;\n  double d=min(closest_pair(a,l,m),closest_pair(a,m,r));\n\
    \  inplace_merge(a.begin()+l,a.begin()+m,a.begin()+r,sort_y);\n\n  Polygon b;\n\
    \  for(int i=l;i<r;i++){\n    if(fabs(a[i].x-x)>=d) continue;\n    for(int j=0;j<(int)b.size();j++){\n\
    \      double dy=a[i].y-next(b.rbegin(),j)->y;\n      if(dy>=d) break;\n     \
    \ d=min(d,abs(a[i]-*next(b.rbegin(),j)));\n    }\n    b.emplace_back(a[i]);\n\
    \  }\n  return d;\n}\n\nvector<vector<int> >\nsegmentArrangement(vector<Segment>\
    \ &ss, Polygon &ps){\n  int n=ss.size();\n  for(int i=0;i<n;i++){\n    ps.emplace_back(ss[i].p1);\n\
    \    ps.emplace_back(ss[i].p2);\n    for(int j=i+1;j<n;j++)\n      if(intersectSS(ss[i],ss[j]))\n\
    \        ps.emplace_back(getCrossPointSS(ss[i],ss[j]));\n  }\n  sort(ps.begin(),ps.end());\n\
    \  ps.erase(unique(ps.begin(),ps.end()),ps.end());\n\n  vector<vector<int> > G(ps.size());\n\
    \  for(int i=0;i<n;i++){\n    vector<pair<double,int> > ls;\n    for(int j=0;j<(int)ps.size();j++)\n\
    \      if(getDistanceSP(ss[i],ps[j])<EPS)\n        ls.emplace_back(make_pair(norm(ss[i].p1-ps[j]),j));\n\
    \n    sort(ls.begin(),ls.end());\n    for(int j=0;j+1<(int)ls.size();j++){\n \
    \     int a=ls[j].second,b=ls[j+1].second;\n      G[a].emplace_back(b);\n    \
    \  G[b].emplace_back(a);\n    }\n  }\n  for(auto &v:G){\n    sort(v.begin(),v.end());\n\
    \    v.erase(unique(v.begin(),v.end()),v.end());\n  }\n  return G;\n}\n\nint manhattan_intersection(vector<Segment>\
    \ ss,const int INF){\n  const int BTM = 0;\n  const int LFT = 1;\n  const int\
    \ RGH = 2;\n  const int TOP = 3;\n\n  int n=ss.size();\n  vector<EndPoint> ep;\n\
    \  for(int i=0;i<n;i++){\n    if(ss[i].p1.y==ss[i].p2.y){\n      if(ss[i].p1.x>ss[i].p2.x)\
    \ swap(ss[i].p1,ss[i].p2);\n      ep.emplace_back(ss[i].p1,i,LFT);\n      ep.emplace_back(ss[i].p2,i,RGH);\n\
    \    }else{\n      if(ss[i].p1.y>ss[i].p2.y) swap(ss[i].p1,ss[i].p2);\n      ep.emplace_back(ss[i].p1,i,BTM);\n\
    \      ep.emplace_back(ss[i].p2,i,TOP);\n    }\n  }\n  sort(ep.begin(),ep.end());\n\
    \n  set<int> bt;\n  bt.insert(INF);\n\n  int cnt=0;\n  for(int i=0;i<n*2;i++){\n\
    \    if(ep[i].st==TOP){\n      bt.erase(ep[i].p.x);\n    }else if(ep[i].st==BTM){\n\
    \      bt.emplace(ep[i].p.x);\n    }else if(ep[i].st==LFT){\n      auto b=bt.lower_bound(ss[ep[i].seg].p1.x);\n\
    \      auto e=bt.upper_bound(ss[ep[i].seg].p2.x);\n      cnt+=distance(b,e);\n\
    \    }\n  }\n\n  return cnt;\n}\n\ndouble area(Polygon ps,Circle c){\n  if(ps.size()<3u)\
    \ return 0;\n  function<double(Circle, Point, Point)> dfs=\n    [&](Circle c,Point\
    \ a,Point b){\n      Vector va=c.c-a,vb=c.c-b;\n      double f=cross(va,vb),res=0;\n\
    \      if(equals(f,0.0)) return res;\n      if(max(abs(va),abs(vb))<c.r+EPS) return\
    \ f;\n      Vector d(dot(va,vb),cross(va,vb));\n      if(getDistanceSP(Segment(a,b),c.c)>c.r-EPS)\n\
    \        return c.r*c.r*atan2(d.y,d.x);\n      auto u=getCrossPointCS(c,Segment(a,b));\n\
    \      if(u.empty()) return res;\n      if(u.size()>1u&&dot(u[1]-u[0],a-u[0])>0)\
    \ swap(u[0],u[1]);\n      u.emplace(u.begin(),a);\n      u.emplace_back(b);\n\
    \      for(int i=1;i<(int)u.size();i++)\n        res+=dfs(c,u[i-1],u[i]);\n  \
    \    return res;\n    };\n  double res=0;\n  for(int i=0;i<(int)ps.size();i++)\n\
    \    res+=dfs(c,ps[i],ps[(i+1)%ps.size()]);\n  return res/2;\n}\n//END CUT HERE\n\
    #ifndef call_from_test\n\nsigned ECR002_D(){\n  Circle c1,c2;\n  cin>>c1>>c2;\n\
    \  cout<<fixed<<setprecision(12)<<area(c1,c2)<<endl;\n  return 0;\n}\n/*\n  verified\
    \ on 2019/11/13\n  https://codeforces.com/contest/600/problem/D\n*/\n\nsigned\
    \ main(){\n  ECR002_D();\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\n#define EPS (1e-10)\n#define equals(a,b) (fabs((a)-(b)) < EPS)\n\
    const double PI = asinl(1) * 2;\n\n// COUNTER CLOCKWISE\nstatic const int CCW_COUNTER_CLOCKWISE\
    \ = 1;\nstatic const int CCW_CLOCKWISE = -1;\nstatic const int CCW_ONLINE_BACK\
    \ = 2;\nstatic const int CCW_ONLINE_FRONT = -2;\nstatic const int CCW_ON_SEGMENT\
    \ = 0;\n\n// intercsect of circles\nstatic const int ICC_SEPERATE = 4;\nstatic\
    \ const int ICC_CIRCUMSCRIBE = 3;\nstatic const int ICC_INTERSECT = 2;\nstatic\
    \ const int ICC_INSCRIBE = 1;\nstatic const int ICC_CONTAIN = 0;\n\nstruct Point{\n\
    \  double x,y;\n  Point(){}\n  Point(double x,double y) :x(x),y(y){}\n  Point\
    \ operator+(Point p) {return Point(x+p.x,y+p.y);}\n  Point operator-(Point p)\
    \ {return Point(x-p.x,y-p.y);}\n  Point operator*(double k){return Point(x*k,y*k);}\n\
    \  Point operator/(double k){return Point(x/k,y/k);}\n  double norm(){return x*x+y*y;}\n\
    \  double abs(){return sqrt(norm());}\n\n  bool operator < (const Point &p) const{\n\
    \    return x!=p.x?x<p.x:y<p.y;\n    //grid-point only\n    //return !equals(x,p.x)?x<p.x:!equals(y,p.y)?y<p.y:0;\n\
    \  }\n\n  bool operator == (const Point &p) const{\n    return fabs(x-p.x)<EPS\
    \ && fabs(y-p.y)<EPS;\n  }\n};\n\nstruct EndPoint{\n  Point p;\n  int seg,st;\n\
    \  EndPoint(){}\n  EndPoint(Point p,int seg,int st):p(p),seg(seg),st(st){}\n \
    \ bool operator<(const EndPoint &ep)const{\n    if(p.y==ep.p.y) return st<ep.st;\n\
    \    return p.y<ep.p.y;\n  }\n};\n\nistream &operator >> (istream &is,Point &p){\n\
    \  is>>p.x>>p.y;\n  return is;\n}\n\nostream &operator << (ostream &os,Point p){\n\
    \  os<<fixed<<setprecision(12)<<p.x<<\" \"<<p.y;\n  return os;\n}\n\nbool sort_x(Point\
    \ a,Point b){\n  return a.x!=b.x?a.x<b.x:a.y<b.y;\n}\n\nbool sort_y(Point a,Point\
    \ b){\n  return a.y!=b.y?a.y<b.y:a.x<b.x;\n}\n\ntypedef Point Vector;\ntypedef\
    \ vector<Point> Polygon;\n\nistream &operator >> (istream &is,Polygon &p){\n \
    \ for(int i=0;i<(int)p.size();i++) is>>p[i];\n  return is;\n}\n\nstruct Segment{\n\
    \  Point p1,p2;\n  Segment(){}\n  Segment(Point p1, Point p2):p1(p1),p2(p2){}\n\
    };\ntypedef Segment Line;\n\nistream &operator >> (istream &is,Segment &s){\n\
    \  is>>s.p1>>s.p2;\n  return is;\n}\n\nstruct Circle{\n  Point c;\n  double r;\n\
    \  Circle(){}\n  Circle(Point c,double r):c(c),r(r){}\n};\n\nistream &operator\
    \ >> (istream &is,Circle &c){\n  is>>c.c>>c.r;\n  return is;\n}\n\ndouble norm(Vector\
    \ a){\n  return a.x*a.x+a.y*a.y;\n}\ndouble abs(Vector a){\n  return sqrt(norm(a));\n\
    }\ndouble dot(Vector a,Vector b){\n  return a.x*b.x+a.y*b.y;\n}\ndouble cross(Vector\
    \ a,Vector b){\n  return a.x*b.y-a.y*b.x;\n}\n\nPoint orth(Point p){return Point(-p.y,p.x);}\n\
    \nbool isOrthogonal(Vector a,Vector b){\n  return equals(dot(a,b),0.0);\n}\n\n\
    bool isOrthogonal(Point a1,Point a2,Point b1,Point b2){\n  return isOrthogonal(a1-a2,b1-b2);\n\
    }\n\nbool isOrthogonal(Segment s1,Segment s2){\n  return equals(dot(s1.p2-s1.p1,s2.p2-s2.p1),0.0);\n\
    }\n\nbool isParallel(Vector a,Vector b){\n  return equals(cross(a,b),0.0);\n}\n\
    \nbool isParallel(Point a1,Point a2,Point b1,Point b2){\n  return isParallel(a1-a2,b1-b2);\n\
    }\n\nbool isParallel(Segment s1,Segment s2){\n  return equals(cross(s1.p2-s1.p1,s2.p2-s2.p1),0.0);\n\
    }\n\nPoint project(Segment s,Point p){\n  Vector base=s.p2-s.p1;\n  double r=dot(p-s.p1,base)/norm(base);\n\
    \  return s.p1+base*r;\n}\n\nPoint reflect(Segment s,Point p){\n  return p+(project(s,p)-p)*2.0;\n\
    }\n\ndouble arg(Vector p){\n  return atan2(p.y,p.x);\n}\n\nVector polar(double\
    \ a,double r){\n  return Point(cos(r)*a,sin(r)*a);\n}\n\nint ccw(Point p0,Point\
    \ p1,Point p2);\nbool intersectSS(Point p1,Point p2,Point p3,Point p4);\nbool\
    \ intersectSS(Segment s1,Segment s2);\nbool intersectPS(Polygon p,Segment l);\n\
    int intersectCC(Circle c1,Circle c2);\nbool intersectSC(Segment s,Circle c);\n\
    double getDistanceLP(Line l,Point p);\ndouble getDistanceSP(Segment s,Point p);\n\
    double getDistanceSS(Segment s1,Segment s2);\nPoint getCrossPointSS(Segment s1,Segment\
    \ s2);\nPoint getCrossPointLL(Line l1,Line l2);\nPolygon getCrossPointCL(Circle\
    \ c,Line l);\nPolygon getCrossPointCC(Circle c1,Circle c2);\nint contains(Polygon\
    \ g,Point p);\nPolygon andrewScan(Polygon s);\nPolygon convex_hull(Polygon ps);\n\
    double diameter(Polygon s);\nbool isConvex(Polygon p);\ndouble area(Polygon s);\n\
    Polygon convexCut(Polygon p,Line l);\nLine bisector(Point p1,Point p2);\nVector\
    \ translate(Vector v,double theta);\nvector<Line> corner(Line l1,Line l2);\nvector<\
    \ vector<int> >\nsegmentArrangement(vector<Segment> &ss, Polygon &ps);\n\nint\
    \ ccw(Point p0,Point p1,Point p2){\n  Vector a = p1-p0;\n  Vector b = p2-p0;\n\
    \  if(cross(a,b) > EPS) return CCW_COUNTER_CLOCKWISE;\n  if(cross(a,b) < -EPS)\
    \ return CCW_CLOCKWISE;\n  if(dot(a,b) < -EPS) return CCW_ONLINE_BACK;\n  if(a.norm()<b.norm())\
    \ return CCW_ONLINE_FRONT;\n  return CCW_ON_SEGMENT;\n}\n\nbool intersectSS(Point\
    \ p1,Point p2,Point p3,Point p4){\n  return (ccw(p1,p2,p3)*ccw(p1,p2,p4) <= 0\
    \ &&\n          ccw(p3,p4,p1)*ccw(p3,p4,p2) <= 0 );\n}\n\nbool intersectSS(Segment\
    \ s1,Segment s2){\n  return intersectSS(s1.p1,s1.p2,s2.p1,s2.p2);\n}\n\nbool intersectPS(Polygon\
    \ p,Segment l){\n  int n=p.size();\n  for(int i=0;i<n;i++)\n    if(intersectSS(Segment(p[i],p[(i+1)%n]),l))\
    \ return 1;\n  return 0;\n}\n\nint intersectCC(Circle c1,Circle c2){\n  if(c1.r<c2.r)\
    \ swap(c1,c2);\n  double d=abs(c1.c-c2.c);\n  double r=c1.r+c2.r;\n  if(equals(d,r))\
    \ return ICC_CIRCUMSCRIBE;\n  if(d>r) return ICC_SEPERATE;\n  if(equals(d+c2.r,c1.r))\
    \ return ICC_INSCRIBE;\n  if(d+c2.r<c1.r) return ICC_CONTAIN;\n  return ICC_INTERSECT;\n\
    }\n\nbool intersectSC(Segment s,Circle c){\n  return getDistanceSP(s,c.c)<=c.r;\n\
    }\n\nint intersectCS(Circle c,Segment s){\n  if(norm(project(s,c.c)-c.c)-c.r*c.r>EPS)\
    \ return 0;\n  double d1=abs(c.c-s.p1),d2=abs(c.c-s.p2);\n  if(d1<c.r+EPS&&d2<c.r+EPS)\
    \ return 0;\n  if((d1<c.r-EPS&&d2>c.r+EPS)||(d1>c.r+EPS&&d2<c.r-EPS)) return 1;\n\
    \  Point h=project(s,c.c);\n  if(dot(s.p1-h,s.p2-h)<0) return 2;\n  return 0;\n\
    }\n\ndouble getDistanceLP(Line l,Point p){\n  return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));\n\
    }\n\ndouble getDistanceSP(Segment s,Point p){\n  if(dot(s.p2-s.p1,p-s.p1) < 0.0\
    \ ) return abs(p-s.p1);\n  if(dot(s.p1-s.p2,p-s.p2) < 0.0 ) return abs(p-s.p2);\n\
    \  return getDistanceLP(s,p);\n}\n\ndouble getDistanceSS(Segment s1,Segment s2){\n\
    \  if(intersectSS(s1,s2)) return 0.0;\n  return min(min(getDistanceSP(s1,s2.p1),getDistanceSP(s1,s2.p2)),\n\
    \             min(getDistanceSP(s2,s1.p1),getDistanceSP(s2,s1.p2)));\n}\n\nPoint\
    \ getCrossPointSS(Segment s1,Segment s2){\n  for(int k=0;k<2;k++){\n    if(getDistanceSP(s1,s2.p1)<EPS)\
    \ return s2.p1;\n    if(getDistanceSP(s1,s2.p2)<EPS) return s2.p2;\n    swap(s1,s2);\n\
    \  }\n  Vector base=s2.p2-s2.p1;\n  double d1=abs(cross(base,s1.p1-s2.p1));\n\
    \  double d2=abs(cross(base,s1.p2-s2.p1));\n  double t=d1/(d1+d2);\n  return s1.p1+(s1.p2-s1.p1)*t;\n\
    }\n\nPoint getCrossPointLL(Line l1,Line l2){\n  double a=cross(l1.p2-l1.p1,l2.p2-l2.p1);\n\
    \  double b=cross(l1.p2-l1.p1,l1.p2-l2.p1);\n  if(abs(a)<EPS&&abs(b)<EPS) return\
    \ l2.p1;\n  return l2.p1+(l2.p2-l2.p1)*(b/a);\n}\n\nPolygon getCrossPointCL(Circle\
    \ c,Line l){\n  Polygon ps;\n  Point pr=project(l,c.c);\n  Vector e=(l.p2-l.p1)/abs(l.p2-l.p1);\n\
    \  if(equals(getDistanceLP(l,c.c),c.r)){\n    ps.emplace_back(pr);\n    return\
    \ ps;\n  }\n  double base=sqrt(c.r*c.r-norm(pr-c.c));\n  ps.emplace_back(pr+e*base);\n\
    \  ps.emplace_back(pr-e*base);\n  return ps;\n}\n\nPolygon getCrossPointCS(Circle\
    \ c,Segment s){\n  Line l(s);\n  Polygon res=getCrossPointCL(c,l);\n  if(intersectCS(c,s)==2)\
    \ return res;\n  if(res.size()>1u){\n    if(dot(l.p1-res[0],l.p2-res[0])>0) swap(res[0],res[1]);\n\
    \    res.pop_back();\n  }\n  return res;\n}\n\n\nPolygon getCrossPointCC(Circle\
    \ c1,Circle c2){\n  Polygon p(2);\n  double d=abs(c1.c-c2.c);\n  double a=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));\n\
    \  double t=arg(c2.c-c1.c);\n  p[0]=c1.c+polar(c1.r,t+a);\n  p[1]=c1.c+polar(c1.r,t-a);\n\
    \  return p;\n}\n\n// IN:2 ON:1 OUT:0\nint contains(Polygon g,Point p){\n  int\
    \ n=g.size();\n  bool x=false;\n  for(int i=0;i<n;i++){\n    Point a=g[i]-p,b=g[(i+1)%n]-p;\n\
    \    if(fabs(cross(a,b)) < EPS && dot(a,b) < EPS) return 1;\n    if(a.y>b.y) swap(a,b);\n\
    \    if(a.y < EPS && EPS < b.y && cross(a,b) > EPS ) x = !x;\n  }\n  return (x?2:0);\n\
    }\n\nPolygon andrewScan(Polygon s){\n  Polygon u,l;\n  if(s.size()<3) return s;\n\
    \  sort(s.begin(),s.end());\n  u.push_back(s[0]);\n  u.push_back(s[1]);\n  l.push_back(s[s.size()-1]);\n\
    \  l.push_back(s[s.size()-2]);\n  for(int i=2;i<(int)s.size();i++){\n    for(int\
    \ n=u.size();\n        n>=2&&ccw(u[n-2],u[n-1],s[i])!=CCW_CLOCKWISE;\n       \
    \ n--){\n      u.pop_back();\n    }\n    u.push_back(s[i]);\n  }\n  for(int i=s.size()-3;i>=0;i--){\n\
    \    for(int n=l.size();\n        n>=2&&ccw(l[n-2],l[n-1],s[i])!=CCW_CLOCKWISE;\n\
    \        n--){\n      l.pop_back();\n    }\n    l.push_back(s[i]);\n  }\n  reverse(l.begin(),l.end());\n\
    \  for(int i=u.size()-2;i>=1;i--) l.push_back(u[i]);\n  return l;\n}\n\nPolygon\
    \ convex_hull(Polygon ps){\n  int n=ps.size();\n  sort(ps.begin(),ps.end(),sort_y);\n\
    \  int k=0;\n  Polygon qs(n*2);\n  for(int i=0;i<n;i++){\n    while(k>1&&cross(qs[k-1]-qs[k-2],ps[i]-qs[k-1])<0)\
    \ k--;\n    qs[k++]=ps[i];\n  }\n  for(int i=n-2,t=k;i>=0;i--){\n    while(k>t&&cross(qs[k-1]-qs[k-2],ps[i]-qs[k-1])<0)\
    \ k--;\n    qs[k++]=ps[i];\n  }\n  qs.resize(k-1);\n  return qs;\n}\n\ndouble\
    \ diameter(Polygon s){\n  Polygon p=s;\n  int n=p.size();\n  if(n==2) return abs(p[0]-p[1]);\n\
    \  int i=0,j=0;\n  for(int k=0;k<n;k++){\n    if(p[i]<p[k]) i=k;\n    if(!(p[j]<p[k]))\
    \ j=k;\n  }\n  double res=0;\n  int si=i,sj=j;\n  while(i!=sj||j!=si){\n    res=max(res,abs(p[i]-p[j]));\n\
    \    if(cross(p[(i+1)%n]-p[i],p[(j+1)%n]-p[j])<0.0){\n      i=(i+1)%n;\n    }else{\n\
    \      j=(j+1)%n;\n    }\n  }\n  return res;\n}\n\nbool isConvex(Polygon p){\n\
    \  bool f=1;\n  int n=p.size();\n  for(int i=0;i<n;i++){\n    int t=ccw(p[(i+n-1)%n],p[i],p[(i+1)%n]);\n\
    \    f&=t!=CCW_CLOCKWISE;\n  }\n  return f;\n}\n\ndouble area(Polygon s){\n  double\
    \ res=0;\n  for(int i=0;i<(int)s.size();i++){\n    res+=cross(s[i],s[(i+1)%s.size()])/2.0;\n\
    \  }\n  return res;\n}\n\ndouble area(Circle c1,Circle c2){\n  double d=abs(c1.c-c2.c);\n\
    \  if(c1.r+c2.r<=d+EPS) return 0;\n  if(d<=abs(c1.r-c2.r)){\n    double r=min(c1.r,c2.r);\n\
    \    return PI*r*r;\n  }\n  double res=0;\n  for(int k=0;k<2;k++){\n    double\
    \ rc=(d*d+c1.r*c1.r-c2.r*c2.r)/(2*d*c1.r);\n    double th=acosl(rc)*2;\n    res+=(th-sinl(th))*c1.r*c1.r/2;\n\
    \    swap(c1,c2);\n  }\n  return res;\n}\n\nPolygon convexCut(Polygon p,Line l){\n\
    \  Polygon q;\n  for(int i=0;i<(int)p.size();i++){\n    Point a=p[i],b=p[(i+1)%p.size()];\n\
    \    if(ccw(l.p1,l.p2,a)!=-1) q.push_back(a);\n    if(ccw(l.p1,l.p2,a)*ccw(l.p1,l.p2,b)<0)\n\
    \      q.push_back(getCrossPointLL(Line(a,b),l));\n  }\n  return q;\n}\n\nLine\
    \ bisector(Point p1,Point p2){\n  Circle c1=Circle(p1,abs(p1-p2)),c2=Circle(p2,abs(p1-p2));\n\
    \  Polygon p=getCrossPointCC(c1,c2);\n  if(cross(p2-p1,p[0]-p1)>0) swap(p[0],p[1]);\n\
    \  return Line(p[0],p[1]);\n}\n\nVector translate(Vector v,double theta){\n  Vector\
    \ res;\n  res.x=cos(theta)*v.x-sin(theta)*v.y;\n  res.y=sin(theta)*v.x+cos(theta)*v.y;\n\
    \  return res;\n}\n\nvector<Line> corner(Line l1,Line l2){\n  vector<Line> res;\n\
    \  if(isParallel(l1,l2)){\n    double d=getDistanceLP(l1,l2.p1)/2.0;\n    Vector\
    \ v1=l1.p2-l1.p1;\n    v1=v1/v1.abs()*d;\n    Point p=l2.p1+translate(v1,90.0*(PI/180.0));\n\
    \    double d1=getDistanceLP(l1,p);\n    double d2=getDistanceLP(l2,p);\n    if(abs(d1-d2)>d){\n\
    \      p=l2.p1+translate(v1,-90.0*(PI/180.0));\n    }\n    res.push_back(Line(p,p+v1));\n\
    \  }else{\n    Point p=getCrossPointLL(l1,l2);\n    Vector v1=l1.p2-l1.p1,v2=l2.p2-l2.p1;\n\
    \    v1=v1/v1.abs();\n    v2=v2/v2.abs();\n    res.push_back(Line(p,p+(v1+v2)));\n\
    \    res.push_back(Line(p,p+translate(v1+v2,90.0*(PI/180.0))));\n  }\n  return\
    \ res;\n}\n\nPolygon tangent(Circle c1,Point p2){\n  Circle c2=Circle(p2,sqrt(norm(c1.c-p2)-c1.r*c1.r));\n\
    \  Polygon p=getCrossPointCC(c1,c2);\n  sort(p.begin(),p.end());\n  return p;\n\
    }\n\nvector<Line> tangent(Circle c1,Circle c2){\n  vector<Line> ls;\n  if(c1.r<c2.r)\
    \ swap(c1,c2);\n  double g=norm(c1.c-c2.c);\n  if(equals(g,0)) return ls;\n  Point\
    \ u=(c2.c-c1.c)/sqrt(g);\n  Point v=orth(u);\n  for(int s=1;s>=-1;s-=2){\n   \
    \ double h=(c1.r+s*c2.r)/sqrt(g);\n    if(equals(1-h*h,0)){\n      ls.emplace_back(c1.c+u*c1.r,c1.c+(u+v)*c1.r);\n\
    \    }else if(1-h*h>0){\n      Point uu=u*h,vv=v*sqrt(1-h*h);\n      ls.emplace_back(c1.c+(uu+vv)*c1.r,c2.c-(uu+vv)*c2.r*s);\n\
    \      ls.emplace_back(c1.c+(uu-vv)*c1.r,c2.c-(uu-vv)*c2.r*s);\n    }\n  }\n\n\
    \  return ls;\n}\n\ndouble closest_pair(Polygon &a,int l=0,int r=-1){\n  if(r<0){\n\
    \    r=a.size();\n    sort(a.begin(),a.end(),sort_x);\n  }\n  if(r-l<=1) return\
    \ abs(a[0]-a[1]);\n  int m=(l+r)>>1;\n  double x=a[m].x;\n  double d=min(closest_pair(a,l,m),closest_pair(a,m,r));\n\
    \  inplace_merge(a.begin()+l,a.begin()+m,a.begin()+r,sort_y);\n\n  Polygon b;\n\
    \  for(int i=l;i<r;i++){\n    if(fabs(a[i].x-x)>=d) continue;\n    for(int j=0;j<(int)b.size();j++){\n\
    \      double dy=a[i].y-next(b.rbegin(),j)->y;\n      if(dy>=d) break;\n     \
    \ d=min(d,abs(a[i]-*next(b.rbegin(),j)));\n    }\n    b.emplace_back(a[i]);\n\
    \  }\n  return d;\n}\n\nvector<vector<int> >\nsegmentArrangement(vector<Segment>\
    \ &ss, Polygon &ps){\n  int n=ss.size();\n  for(int i=0;i<n;i++){\n    ps.emplace_back(ss[i].p1);\n\
    \    ps.emplace_back(ss[i].p2);\n    for(int j=i+1;j<n;j++)\n      if(intersectSS(ss[i],ss[j]))\n\
    \        ps.emplace_back(getCrossPointSS(ss[i],ss[j]));\n  }\n  sort(ps.begin(),ps.end());\n\
    \  ps.erase(unique(ps.begin(),ps.end()),ps.end());\n\n  vector<vector<int> > G(ps.size());\n\
    \  for(int i=0;i<n;i++){\n    vector<pair<double,int> > ls;\n    for(int j=0;j<(int)ps.size();j++)\n\
    \      if(getDistanceSP(ss[i],ps[j])<EPS)\n        ls.emplace_back(make_pair(norm(ss[i].p1-ps[j]),j));\n\
    \n    sort(ls.begin(),ls.end());\n    for(int j=0;j+1<(int)ls.size();j++){\n \
    \     int a=ls[j].second,b=ls[j+1].second;\n      G[a].emplace_back(b);\n    \
    \  G[b].emplace_back(a);\n    }\n  }\n  for(auto &v:G){\n    sort(v.begin(),v.end());\n\
    \    v.erase(unique(v.begin(),v.end()),v.end());\n  }\n  return G;\n}\n\nint manhattan_intersection(vector<Segment>\
    \ ss,const int INF){\n  const int BTM = 0;\n  const int LFT = 1;\n  const int\
    \ RGH = 2;\n  const int TOP = 3;\n\n  int n=ss.size();\n  vector<EndPoint> ep;\n\
    \  for(int i=0;i<n;i++){\n    if(ss[i].p1.y==ss[i].p2.y){\n      if(ss[i].p1.x>ss[i].p2.x)\
    \ swap(ss[i].p1,ss[i].p2);\n      ep.emplace_back(ss[i].p1,i,LFT);\n      ep.emplace_back(ss[i].p2,i,RGH);\n\
    \    }else{\n      if(ss[i].p1.y>ss[i].p2.y) swap(ss[i].p1,ss[i].p2);\n      ep.emplace_back(ss[i].p1,i,BTM);\n\
    \      ep.emplace_back(ss[i].p2,i,TOP);\n    }\n  }\n  sort(ep.begin(),ep.end());\n\
    \n  set<int> bt;\n  bt.insert(INF);\n\n  int cnt=0;\n  for(int i=0;i<n*2;i++){\n\
    \    if(ep[i].st==TOP){\n      bt.erase(ep[i].p.x);\n    }else if(ep[i].st==BTM){\n\
    \      bt.emplace(ep[i].p.x);\n    }else if(ep[i].st==LFT){\n      auto b=bt.lower_bound(ss[ep[i].seg].p1.x);\n\
    \      auto e=bt.upper_bound(ss[ep[i].seg].p2.x);\n      cnt+=distance(b,e);\n\
    \    }\n  }\n\n  return cnt;\n}\n\ndouble area(Polygon ps,Circle c){\n  if(ps.size()<3u)\
    \ return 0;\n  function<double(Circle, Point, Point)> dfs=\n    [&](Circle c,Point\
    \ a,Point b){\n      Vector va=c.c-a,vb=c.c-b;\n      double f=cross(va,vb),res=0;\n\
    \      if(equals(f,0.0)) return res;\n      if(max(abs(va),abs(vb))<c.r+EPS) return\
    \ f;\n      Vector d(dot(va,vb),cross(va,vb));\n      if(getDistanceSP(Segment(a,b),c.c)>c.r-EPS)\n\
    \        return c.r*c.r*atan2(d.y,d.x);\n      auto u=getCrossPointCS(c,Segment(a,b));\n\
    \      if(u.empty()) return res;\n      if(u.size()>1u&&dot(u[1]-u[0],a-u[0])>0)\
    \ swap(u[0],u[1]);\n      u.emplace(u.begin(),a);\n      u.emplace_back(b);\n\
    \      for(int i=1;i<(int)u.size();i++)\n        res+=dfs(c,u[i-1],u[i]);\n  \
    \    return res;\n    };\n  double res=0;\n  for(int i=0;i<(int)ps.size();i++)\n\
    \    res+=dfs(c,ps[i],ps[(i+1)%ps.size()]);\n  return res/2;\n}\n//END CUT HERE\n\
    #ifndef call_from_test\n\nsigned ECR002_D(){\n  Circle c1,c2;\n  cin>>c1>>c2;\n\
    \  cout<<fixed<<setprecision(12)<<area(c1,c2)<<endl;\n  return 0;\n}\n/*\n  verified\
    \ on 2019/11/13\n  https://codeforces.com/contest/600/problem/D\n*/\n\nsigned\
    \ main(){\n  ECR002_D();\n  return 0;\n}\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/3056.test.cpp
    title: test/aoj/geometry/3056.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/CGL_6_A.test.cpp
    title: test/aoj/geometry/CGL_6_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/CGL_7_H.test.cpp
    title: test/aoj/geometry/CGL_7_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/CGL_7_E.test.cpp
    title: test/aoj/geometry/CGL_7_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/CGL_1_A.test.cpp
    title: test/aoj/geometry/CGL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/CGL_3_B.test.cpp
    title: test/aoj/geometry/CGL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/CGL_4_C.test.cpp
    title: test/aoj/geometry/CGL_4_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/CGL_2_A.test.cpp
    title: test/aoj/geometry/CGL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/CGL_2_C.test.cpp
    title: test/aoj/geometry/CGL_2_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/3049.test.cpp
    title: test/aoj/geometry/3049.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/CGL_2_D.test.cpp
    title: test/aoj/geometry/CGL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/CGL_2_B.test.cpp
    title: test/aoj/geometry/CGL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/CGL_7_A.test.cpp
    title: test/aoj/geometry/CGL_7_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/CGL_4_A.test.cpp
    title: test/aoj/geometry/CGL_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/CGL_3_A.test.cpp
    title: test/aoj/geometry/CGL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/CGL_7_F.test.cpp
    title: test/aoj/geometry/CGL_7_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/2572.test.cpp
    title: test/aoj/geometry/2572.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/CGL_3_C.test.cpp
    title: test/aoj/geometry/CGL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/2448.test.cpp
    title: test/aoj/geometry/2448.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/CGL_7_D.test.cpp
    title: test/aoj/geometry/CGL_7_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/CGL_1_B.test.cpp
    title: test/aoj/geometry/CGL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/CGL_7_G.test.cpp
    title: test/aoj/geometry/CGL_7_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/2334.test.cpp
    title: test/aoj/geometry/2334.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/2454.test.cpp
    title: test/aoj/geometry/2454.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/CGL_4_B.test.cpp
    title: test/aoj/geometry/CGL_4_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/CGL_5_A.test.cpp
    title: test/aoj/geometry/CGL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/geometry/CGL_1_C.test.cpp
    title: test/aoj/geometry/CGL_1_C.test.cpp
  isVerificationFile: false
  path: geometry/geometry.cpp
  requiredBy: []
  timestamp: '2019-12-17 20:13:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - test/aoj/geometry/3056.test.cpp
  - test/aoj/geometry/CGL_6_A.test.cpp
  - test/aoj/geometry/CGL_7_H.test.cpp
  - test/aoj/geometry/CGL_7_E.test.cpp
  - test/aoj/geometry/CGL_1_A.test.cpp
  - test/aoj/geometry/CGL_3_B.test.cpp
  - test/aoj/geometry/CGL_4_C.test.cpp
  - test/aoj/geometry/CGL_2_A.test.cpp
  - test/aoj/geometry/CGL_2_C.test.cpp
  - test/aoj/geometry/3049.test.cpp
  - test/aoj/geometry/CGL_2_D.test.cpp
  - test/aoj/geometry/CGL_2_B.test.cpp
  - test/aoj/geometry/CGL_7_A.test.cpp
  - test/aoj/geometry/CGL_4_A.test.cpp
  - test/aoj/geometry/CGL_3_A.test.cpp
  - test/aoj/geometry/CGL_7_F.test.cpp
  - test/aoj/geometry/2572.test.cpp
  - test/aoj/geometry/CGL_3_C.test.cpp
  - test/aoj/geometry/2448.test.cpp
  - test/aoj/geometry/CGL_7_D.test.cpp
  - test/aoj/geometry/CGL_1_B.test.cpp
  - test/aoj/geometry/CGL_7_G.test.cpp
  - test/aoj/geometry/2334.test.cpp
  - test/aoj/geometry/2454.test.cpp
  - test/aoj/geometry/CGL_4_B.test.cpp
  - test/aoj/geometry/CGL_5_A.test.cpp
  - test/aoj/geometry/CGL_1_C.test.cpp
documentation_of: geometry/geometry.cpp
layout: document
redirect_from:
- /library/geometry/geometry.cpp
- /library/geometry/geometry.cpp.html
title: geometry/geometry.cpp
---
