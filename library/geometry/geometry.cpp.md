---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: geometry/geometry.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ed7daeb157cd9b31e53896ad3c771a26">geometry</a>
* <a href="{{ site.github.repository_url }}/blob/master/geometry/geometry.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 20:13:07+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/2334.test.cpp.html">test/aoj/geometry/2334.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/2448.test.cpp.html">test/aoj/geometry/2448.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/2454.test.cpp.html">test/aoj/geometry/2454.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/3049.test.cpp.html">test/aoj/geometry/3049.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/3056.test.cpp.html">test/aoj/geometry/3056.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/CGL_1_A.test.cpp.html">test/aoj/geometry/CGL_1_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/CGL_1_B.test.cpp.html">test/aoj/geometry/CGL_1_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/CGL_1_C.test.cpp.html">test/aoj/geometry/CGL_1_C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/CGL_2_A.test.cpp.html">test/aoj/geometry/CGL_2_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/CGL_2_B.test.cpp.html">test/aoj/geometry/CGL_2_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/CGL_2_C.test.cpp.html">test/aoj/geometry/CGL_2_C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/CGL_2_D.test.cpp.html">test/aoj/geometry/CGL_2_D.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/CGL_3_A.test.cpp.html">test/aoj/geometry/CGL_3_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/CGL_3_B.test.cpp.html">test/aoj/geometry/CGL_3_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/CGL_3_C.test.cpp.html">test/aoj/geometry/CGL_3_C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/CGL_4_A.test.cpp.html">test/aoj/geometry/CGL_4_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/CGL_4_B.test.cpp.html">test/aoj/geometry/CGL_4_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/CGL_4_C.test.cpp.html">test/aoj/geometry/CGL_4_C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/CGL_5_A.test.cpp.html">test/aoj/geometry/CGL_5_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/CGL_6_A.test.cpp.html">test/aoj/geometry/CGL_6_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/CGL_7_A.test.cpp.html">test/aoj/geometry/CGL_7_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/CGL_7_D.test.cpp.html">test/aoj/geometry/CGL_7_D.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/CGL_7_E.test.cpp.html">test/aoj/geometry/CGL_7_E.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/CGL_7_F.test.cpp.html">test/aoj/geometry/CGL_7_F.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/CGL_7_G.test.cpp.html">test/aoj/geometry/CGL_7_G.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/CGL_7_H.test.cpp.html">test/aoj/geometry/CGL_7_H.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b)) < EPS)
const double PI = asinl(1) * 2;

// COUNTER CLOCKWISE
static const int CCW_COUNTER_CLOCKWISE = 1;
static const int CCW_CLOCKWISE = -1;
static const int CCW_ONLINE_BACK = 2;
static const int CCW_ONLINE_FRONT = -2;
static const int CCW_ON_SEGMENT = 0;

// intercsect of circles
static const int ICC_SEPERATE = 4;
static const int ICC_CIRCUMSCRIBE = 3;
static const int ICC_INTERSECT = 2;
static const int ICC_INSCRIBE = 1;
static const int ICC_CONTAIN = 0;

struct Point{
  double x,y;
  Point(){}
  Point(double x,double y) :x(x),y(y){}
  Point operator+(Point p) {return Point(x+p.x,y+p.y);}
  Point operator-(Point p) {return Point(x-p.x,y-p.y);}
  Point operator*(double k){return Point(x*k,y*k);}
  Point operator/(double k){return Point(x/k,y/k);}
  double norm(){return x*x+y*y;}
  double abs(){return sqrt(norm());}

  bool operator < (const Point &p) const{
    return x!=p.x?x<p.x:y<p.y;
    //grid-point only
    //return !equals(x,p.x)?x<p.x:!equals(y,p.y)?y<p.y:0;
  }

  bool operator == (const Point &p) const{
    return fabs(x-p.x)<EPS && fabs(y-p.y)<EPS;
  }
};

struct EndPoint{
  Point p;
  int seg,st;
  EndPoint(){}
  EndPoint(Point p,int seg,int st):p(p),seg(seg),st(st){}
  bool operator<(const EndPoint &ep)const{
    if(p.y==ep.p.y) return st<ep.st;
    return p.y<ep.p.y;
  }
};

istream &operator >> (istream &is,Point &p){
  is>>p.x>>p.y;
  return is;
}

ostream &operator << (ostream &os,Point p){
  os<<fixed<<setprecision(12)<<p.x<<" "<<p.y;
  return os;
}

bool sort_x(Point a,Point b){
  return a.x!=b.x?a.x<b.x:a.y<b.y;
}

bool sort_y(Point a,Point b){
  return a.y!=b.y?a.y<b.y:a.x<b.x;
}

typedef Point Vector;
typedef vector<Point> Polygon;

istream &operator >> (istream &is,Polygon &p){
  for(int i=0;i<(int)p.size();i++) is>>p[i];
  return is;
}

struct Segment{
  Point p1,p2;
  Segment(){}
  Segment(Point p1, Point p2):p1(p1),p2(p2){}
};
typedef Segment Line;

istream &operator >> (istream &is,Segment &s){
  is>>s.p1>>s.p2;
  return is;
}

struct Circle{
  Point c;
  double r;
  Circle(){}
  Circle(Point c,double r):c(c),r(r){}
};

istream &operator >> (istream &is,Circle &c){
  is>>c.c>>c.r;
  return is;
}

double norm(Vector a){
  return a.x*a.x+a.y*a.y;
}
double abs(Vector a){
  return sqrt(norm(a));
}
double dot(Vector a,Vector b){
  return a.x*b.x+a.y*b.y;
}
double cross(Vector a,Vector b){
  return a.x*b.y-a.y*b.x;
}

Point orth(Point p){return Point(-p.y,p.x);}

bool isOrthogonal(Vector a,Vector b){
  return equals(dot(a,b),0.0);
}

bool isOrthogonal(Point a1,Point a2,Point b1,Point b2){
  return isOrthogonal(a1-a2,b1-b2);
}

bool isOrthogonal(Segment s1,Segment s2){
  return equals(dot(s1.p2-s1.p1,s2.p2-s2.p1),0.0);
}

bool isParallel(Vector a,Vector b){
  return equals(cross(a,b),0.0);
}

bool isParallel(Point a1,Point a2,Point b1,Point b2){
  return isParallel(a1-a2,b1-b2);
}

bool isParallel(Segment s1,Segment s2){
  return equals(cross(s1.p2-s1.p1,s2.p2-s2.p1),0.0);
}

Point project(Segment s,Point p){
  Vector base=s.p2-s.p1;
  double r=dot(p-s.p1,base)/norm(base);
  return s.p1+base*r;
}

Point reflect(Segment s,Point p){
  return p+(project(s,p)-p)*2.0;
}

double arg(Vector p){
  return atan2(p.y,p.x);
}

Vector polar(double a,double r){
  return Point(cos(r)*a,sin(r)*a);
}

int ccw(Point p0,Point p1,Point p2);
bool intersectSS(Point p1,Point p2,Point p3,Point p4);
bool intersectSS(Segment s1,Segment s2);
bool intersectPS(Polygon p,Segment l);
int intersectCC(Circle c1,Circle c2);
bool intersectSC(Segment s,Circle c);
double getDistanceLP(Line l,Point p);
double getDistanceSP(Segment s,Point p);
double getDistanceSS(Segment s1,Segment s2);
Point getCrossPointSS(Segment s1,Segment s2);
Point getCrossPointLL(Line l1,Line l2);
Polygon getCrossPointCL(Circle c,Line l);
Polygon getCrossPointCC(Circle c1,Circle c2);
int contains(Polygon g,Point p);
Polygon andrewScan(Polygon s);
Polygon convex_hull(Polygon ps);
double diameter(Polygon s);
bool isConvex(Polygon p);
double area(Polygon s);
Polygon convexCut(Polygon p,Line l);
Line bisector(Point p1,Point p2);
Vector translate(Vector v,double theta);
vector<Line> corner(Line l1,Line l2);
vector< vector<int> >
segmentArrangement(vector<Segment> &ss, Polygon &ps);

int ccw(Point p0,Point p1,Point p2){
  Vector a = p1-p0;
  Vector b = p2-p0;
  if(cross(a,b) > EPS) return CCW_COUNTER_CLOCKWISE;
  if(cross(a,b) < -EPS) return CCW_CLOCKWISE;
  if(dot(a,b) < -EPS) return CCW_ONLINE_BACK;
  if(a.norm()<b.norm()) return CCW_ONLINE_FRONT;
  return CCW_ON_SEGMENT;
}

bool intersectSS(Point p1,Point p2,Point p3,Point p4){
  return (ccw(p1,p2,p3)*ccw(p1,p2,p4) <= 0 &&
          ccw(p3,p4,p1)*ccw(p3,p4,p2) <= 0 );
}

bool intersectSS(Segment s1,Segment s2){
  return intersectSS(s1.p1,s1.p2,s2.p1,s2.p2);
}

bool intersectPS(Polygon p,Segment l){
  int n=p.size();
  for(int i=0;i<n;i++)
    if(intersectSS(Segment(p[i],p[(i+1)%n]),l)) return 1;
  return 0;
}

int intersectCC(Circle c1,Circle c2){
  if(c1.r<c2.r) swap(c1,c2);
  double d=abs(c1.c-c2.c);
  double r=c1.r+c2.r;
  if(equals(d,r)) return ICC_CIRCUMSCRIBE;
  if(d>r) return ICC_SEPERATE;
  if(equals(d+c2.r,c1.r)) return ICC_INSCRIBE;
  if(d+c2.r<c1.r) return ICC_CONTAIN;
  return ICC_INTERSECT;
}

bool intersectSC(Segment s,Circle c){
  return getDistanceSP(s,c.c)<=c.r;
}

int intersectCS(Circle c,Segment s){
  if(norm(project(s,c.c)-c.c)-c.r*c.r>EPS) return 0;
  double d1=abs(c.c-s.p1),d2=abs(c.c-s.p2);
  if(d1<c.r+EPS&&d2<c.r+EPS) return 0;
  if((d1<c.r-EPS&&d2>c.r+EPS)||(d1>c.r+EPS&&d2<c.r-EPS)) return 1;
  Point h=project(s,c.c);
  if(dot(s.p1-h,s.p2-h)<0) return 2;
  return 0;
}

double getDistanceLP(Line l,Point p){
  return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));
}

double getDistanceSP(Segment s,Point p){
  if(dot(s.p2-s.p1,p-s.p1) < 0.0 ) return abs(p-s.p1);
  if(dot(s.p1-s.p2,p-s.p2) < 0.0 ) return abs(p-s.p2);
  return getDistanceLP(s,p);
}

double getDistanceSS(Segment s1,Segment s2){
  if(intersectSS(s1,s2)) return 0.0;
  return min(min(getDistanceSP(s1,s2.p1),getDistanceSP(s1,s2.p2)),
             min(getDistanceSP(s2,s1.p1),getDistanceSP(s2,s1.p2)));
}

Point getCrossPointSS(Segment s1,Segment s2){
  for(int k=0;k<2;k++){
    if(getDistanceSP(s1,s2.p1)<EPS) return s2.p1;
    if(getDistanceSP(s1,s2.p2)<EPS) return s2.p2;
    swap(s1,s2);
  }
  Vector base=s2.p2-s2.p1;
  double d1=abs(cross(base,s1.p1-s2.p1));
  double d2=abs(cross(base,s1.p2-s2.p1));
  double t=d1/(d1+d2);
  return s1.p1+(s1.p2-s1.p1)*t;
}

Point getCrossPointLL(Line l1,Line l2){
  double a=cross(l1.p2-l1.p1,l2.p2-l2.p1);
  double b=cross(l1.p2-l1.p1,l1.p2-l2.p1);
  if(abs(a)<EPS&&abs(b)<EPS) return l2.p1;
  return l2.p1+(l2.p2-l2.p1)*(b/a);
}

Polygon getCrossPointCL(Circle c,Line l){
  Polygon ps;
  Point pr=project(l,c.c);
  Vector e=(l.p2-l.p1)/abs(l.p2-l.p1);
  if(equals(getDistanceLP(l,c.c),c.r)){
    ps.emplace_back(pr);
    return ps;
  }
  double base=sqrt(c.r*c.r-norm(pr-c.c));
  ps.emplace_back(pr+e*base);
  ps.emplace_back(pr-e*base);
  return ps;
}

Polygon getCrossPointCS(Circle c,Segment s){
  Line l(s);
  Polygon res=getCrossPointCL(c,l);
  if(intersectCS(c,s)==2) return res;
  if(res.size()>1u){
    if(dot(l.p1-res[0],l.p2-res[0])>0) swap(res[0],res[1]);
    res.pop_back();
  }
  return res;
}


Polygon getCrossPointCC(Circle c1,Circle c2){
  Polygon p(2);
  double d=abs(c1.c-c2.c);
  double a=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
  double t=arg(c2.c-c1.c);
  p[0]=c1.c+polar(c1.r,t+a);
  p[1]=c1.c+polar(c1.r,t-a);
  return p;
}

// IN:2 ON:1 OUT:0
int contains(Polygon g,Point p){
  int n=g.size();
  bool x=false;
  for(int i=0;i<n;i++){
    Point a=g[i]-p,b=g[(i+1)%n]-p;
    if(fabs(cross(a,b)) < EPS && dot(a,b) < EPS) return 1;
    if(a.y>b.y) swap(a,b);
    if(a.y < EPS && EPS < b.y && cross(a,b) > EPS ) x = !x;
  }
  return (x?2:0);
}

Polygon andrewScan(Polygon s){
  Polygon u,l;
  if(s.size()<3) return s;
  sort(s.begin(),s.end());
  u.push_back(s[0]);
  u.push_back(s[1]);
  l.push_back(s[s.size()-1]);
  l.push_back(s[s.size()-2]);
  for(int i=2;i<(int)s.size();i++){
    for(int n=u.size();
        n>=2&&ccw(u[n-2],u[n-1],s[i])!=CCW_CLOCKWISE;
        n--){
      u.pop_back();
    }
    u.push_back(s[i]);
  }
  for(int i=s.size()-3;i>=0;i--){
    for(int n=l.size();
        n>=2&&ccw(l[n-2],l[n-1],s[i])!=CCW_CLOCKWISE;
        n--){
      l.pop_back();
    }
    l.push_back(s[i]);
  }
  reverse(l.begin(),l.end());
  for(int i=u.size()-2;i>=1;i--) l.push_back(u[i]);
  return l;
}

Polygon convex_hull(Polygon ps){
  int n=ps.size();
  sort(ps.begin(),ps.end(),sort_y);
  int k=0;
  Polygon qs(n*2);
  for(int i=0;i<n;i++){
    while(k>1&&cross(qs[k-1]-qs[k-2],ps[i]-qs[k-1])<0) k--;
    qs[k++]=ps[i];
  }
  for(int i=n-2,t=k;i>=0;i--){
    while(k>t&&cross(qs[k-1]-qs[k-2],ps[i]-qs[k-1])<0) k--;
    qs[k++]=ps[i];
  }
  qs.resize(k-1);
  return qs;
}

double diameter(Polygon s){
  Polygon p=s;
  int n=p.size();
  if(n==2) return abs(p[0]-p[1]);
  int i=0,j=0;
  for(int k=0;k<n;k++){
    if(p[i]<p[k]) i=k;
    if(!(p[j]<p[k])) j=k;
  }
  double res=0;
  int si=i,sj=j;
  while(i!=sj||j!=si){
    res=max(res,abs(p[i]-p[j]));
    if(cross(p[(i+1)%n]-p[i],p[(j+1)%n]-p[j])<0.0){
      i=(i+1)%n;
    }else{
      j=(j+1)%n;
    }
  }
  return res;
}

bool isConvex(Polygon p){
  bool f=1;
  int n=p.size();
  for(int i=0;i<n;i++){
    int t=ccw(p[(i+n-1)%n],p[i],p[(i+1)%n]);
    f&=t!=CCW_CLOCKWISE;
  }
  return f;
}

double area(Polygon s){
  double res=0;
  for(int i=0;i<(int)s.size();i++){
    res+=cross(s[i],s[(i+1)%s.size()])/2.0;
  }
  return res;
}

double area(Circle c1,Circle c2){
  double d=abs(c1.c-c2.c);
  if(c1.r+c2.r<=d+EPS) return 0;
  if(d<=abs(c1.r-c2.r)){
    double r=min(c1.r,c2.r);
    return PI*r*r;
  }
  double res=0;
  for(int k=0;k<2;k++){
    double rc=(d*d+c1.r*c1.r-c2.r*c2.r)/(2*d*c1.r);
    double th=acosl(rc)*2;
    res+=(th-sinl(th))*c1.r*c1.r/2;
    swap(c1,c2);
  }
  return res;
}

Polygon convexCut(Polygon p,Line l){
  Polygon q;
  for(int i=0;i<(int)p.size();i++){
    Point a=p[i],b=p[(i+1)%p.size()];
    if(ccw(l.p1,l.p2,a)!=-1) q.push_back(a);
    if(ccw(l.p1,l.p2,a)*ccw(l.p1,l.p2,b)<0)
      q.push_back(getCrossPointLL(Line(a,b),l));
  }
  return q;
}

Line bisector(Point p1,Point p2){
  Circle c1=Circle(p1,abs(p1-p2)),c2=Circle(p2,abs(p1-p2));
  Polygon p=getCrossPointCC(c1,c2);
  if(cross(p2-p1,p[0]-p1)>0) swap(p[0],p[1]);
  return Line(p[0],p[1]);
}

Vector translate(Vector v,double theta){
  Vector res;
  res.x=cos(theta)*v.x-sin(theta)*v.y;
  res.y=sin(theta)*v.x+cos(theta)*v.y;
  return res;
}

vector<Line> corner(Line l1,Line l2){
  vector<Line> res;
  if(isParallel(l1,l2)){
    double d=getDistanceLP(l1,l2.p1)/2.0;
    Vector v1=l1.p2-l1.p1;
    v1=v1/v1.abs()*d;
    Point p=l2.p1+translate(v1,90.0*(PI/180.0));
    double d1=getDistanceLP(l1,p);
    double d2=getDistanceLP(l2,p);
    if(abs(d1-d2)>d){
      p=l2.p1+translate(v1,-90.0*(PI/180.0));
    }
    res.push_back(Line(p,p+v1));
  }else{
    Point p=getCrossPointLL(l1,l2);
    Vector v1=l1.p2-l1.p1,v2=l2.p2-l2.p1;
    v1=v1/v1.abs();
    v2=v2/v2.abs();
    res.push_back(Line(p,p+(v1+v2)));
    res.push_back(Line(p,p+translate(v1+v2,90.0*(PI/180.0))));
  }
  return res;
}

Polygon tangent(Circle c1,Point p2){
  Circle c2=Circle(p2,sqrt(norm(c1.c-p2)-c1.r*c1.r));
  Polygon p=getCrossPointCC(c1,c2);
  sort(p.begin(),p.end());
  return p;
}

vector<Line> tangent(Circle c1,Circle c2){
  vector<Line> ls;
  if(c1.r<c2.r) swap(c1,c2);
  double g=norm(c1.c-c2.c);
  if(equals(g,0)) return ls;
  Point u=(c2.c-c1.c)/sqrt(g);
  Point v=orth(u);
  for(int s=1;s>=-1;s-=2){
    double h=(c1.r+s*c2.r)/sqrt(g);
    if(equals(1-h*h,0)){
      ls.emplace_back(c1.c+u*c1.r,c1.c+(u+v)*c1.r);
    }else if(1-h*h>0){
      Point uu=u*h,vv=v*sqrt(1-h*h);
      ls.emplace_back(c1.c+(uu+vv)*c1.r,c2.c-(uu+vv)*c2.r*s);
      ls.emplace_back(c1.c+(uu-vv)*c1.r,c2.c-(uu-vv)*c2.r*s);
    }
  }

  return ls;
}

double closest_pair(Polygon &a,int l=0,int r=-1){
  if(r<0){
    r=a.size();
    sort(a.begin(),a.end(),sort_x);
  }
  if(r-l<=1) return abs(a[0]-a[1]);
  int m=(l+r)>>1;
  double x=a[m].x;
  double d=min(closest_pair(a,l,m),closest_pair(a,m,r));
  inplace_merge(a.begin()+l,a.begin()+m,a.begin()+r,sort_y);

  Polygon b;
  for(int i=l;i<r;i++){
    if(fabs(a[i].x-x)>=d) continue;
    for(int j=0;j<(int)b.size();j++){
      double dy=a[i].y-next(b.rbegin(),j)->y;
      if(dy>=d) break;
      d=min(d,abs(a[i]-*next(b.rbegin(),j)));
    }
    b.emplace_back(a[i]);
  }
  return d;
}

vector<vector<int> >
segmentArrangement(vector<Segment> &ss, Polygon &ps){
  int n=ss.size();
  for(int i=0;i<n;i++){
    ps.emplace_back(ss[i].p1);
    ps.emplace_back(ss[i].p2);
    for(int j=i+1;j<n;j++)
      if(intersectSS(ss[i],ss[j]))
        ps.emplace_back(getCrossPointSS(ss[i],ss[j]));
  }
  sort(ps.begin(),ps.end());
  ps.erase(unique(ps.begin(),ps.end()),ps.end());

  vector<vector<int> > G(ps.size());
  for(int i=0;i<n;i++){
    vector<pair<double,int> > ls;
    for(int j=0;j<(int)ps.size();j++)
      if(getDistanceSP(ss[i],ps[j])<EPS)
        ls.emplace_back(make_pair(norm(ss[i].p1-ps[j]),j));

    sort(ls.begin(),ls.end());
    for(int j=0;j+1<(int)ls.size();j++){
      int a=ls[j].second,b=ls[j+1].second;
      G[a].emplace_back(b);
      G[b].emplace_back(a);
    }
  }
  for(auto &v:G){
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
  }
  return G;
}

int manhattan_intersection(vector<Segment> ss,const int INF){
  const int BTM = 0;
  const int LFT = 1;
  const int RGH = 2;
  const int TOP = 3;

  int n=ss.size();
  vector<EndPoint> ep;
  for(int i=0;i<n;i++){
    if(ss[i].p1.y==ss[i].p2.y){
      if(ss[i].p1.x>ss[i].p2.x) swap(ss[i].p1,ss[i].p2);
      ep.emplace_back(ss[i].p1,i,LFT);
      ep.emplace_back(ss[i].p2,i,RGH);
    }else{
      if(ss[i].p1.y>ss[i].p2.y) swap(ss[i].p1,ss[i].p2);
      ep.emplace_back(ss[i].p1,i,BTM);
      ep.emplace_back(ss[i].p2,i,TOP);
    }
  }
  sort(ep.begin(),ep.end());

  set<int> bt;
  bt.insert(INF);

  int cnt=0;
  for(int i=0;i<n*2;i++){
    if(ep[i].st==TOP){
      bt.erase(ep[i].p.x);
    }else if(ep[i].st==BTM){
      bt.emplace(ep[i].p.x);
    }else if(ep[i].st==LFT){
      auto b=bt.lower_bound(ss[ep[i].seg].p1.x);
      auto e=bt.upper_bound(ss[ep[i].seg].p2.x);
      cnt+=distance(b,e);
    }
  }

  return cnt;
}

double area(Polygon ps,Circle c){
  if(ps.size()<3u) return 0;
  function<double(Circle, Point, Point)> dfs=
    [&](Circle c,Point a,Point b){
      Vector va=c.c-a,vb=c.c-b;
      double f=cross(va,vb),res=0;
      if(equals(f,0.0)) return res;
      if(max(abs(va),abs(vb))<c.r+EPS) return f;
      Vector d(dot(va,vb),cross(va,vb));
      if(getDistanceSP(Segment(a,b),c.c)>c.r-EPS)
        return c.r*c.r*atan2(d.y,d.x);
      auto u=getCrossPointCS(c,Segment(a,b));
      if(u.empty()) return res;
      if(u.size()>1u&&dot(u[1]-u[0],a-u[0])>0) swap(u[0],u[1]);
      u.emplace(u.begin(),a);
      u.emplace_back(b);
      for(int i=1;i<(int)u.size();i++)
        res+=dfs(c,u[i-1],u[i]);
      return res;
    };
  double res=0;
  for(int i=0;i<(int)ps.size();i++)
    res+=dfs(c,ps[i],ps[(i+1)%ps.size()]);
  return res/2;
}
//END CUT HERE
#ifndef call_from_test

signed ECR002_D(){
  Circle c1,c2;
  cin>>c1>>c2;
  cout<<fixed<<setprecision(12)<<area(c1,c2)<<endl;
  return 0;
}
/*
  verified on 2019/11/13
  https://codeforces.com/contest/600/problem/D
*/

signed main(){
  ECR002_D();
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 347, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=self.cpp_source_path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 63, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: geometry/geometry.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

