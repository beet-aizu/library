#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
#define equals(a,b) (fabs((a)-(b)) < EPS)
using number = double;
const number EPS = 1e-10;
const number PI = acos(-1);
// COUNTER CLOCKWISE
static const int CCW_COUNTER_CLOCKWISE = 1;
static const int CCW_CLOCKWISE = -1;
static const int CCW_ONLINE_BACK = 2;
static const int CCW_ONLINE_FRONT = -2;
static const int CCW_ON_SEGMENT = 0;
//Intercsect Circle & Circle
static const int ICC_SEPERATE = 4;
static const int ICC_CIRCUMSCRIBE = 3;
static const int ICC_INTERSECT = 2;
static const int ICC_INSCRIBE = 1;
static const int ICC_CONTAIN = 0;
struct Point{
  number x,y;
  Point(){}
  Point(number x,number y) :x(x),y(y){}
  Point operator+(Point p) {return Point(x+p.x,y+p.y);}
  Point operator-(Point p) {return Point(x-p.x,y-p.y);}
  Point operator*(number k){return Point(x*k,y*k);}
  Point operator/(number k){return Point(x/k,y/k);}
  number norm(){return x*x+y*y;}
  number abs(){return sqrt(norm());}
  bool operator < (const Point &p) const{
    return x!=p.x?x<p.x:y<p.y;
    //grid-point only
    //return !equals(x,p.x)?x<p.x:!equals(y,p.y)?y<p.y:0;
  }
  bool operator == (const Point &p) const{
    return equals(x,p.x)&&equals(y,p.y);
  }
};
typedef Point Vector;
typedef vector<Point> Polygon;
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
struct Segment{
  Point p1,p2;
  Segment(){}
  Segment(Point p1, Point p2):p1(p1),p2(p2){}
};
typedef Segment Line;
struct Circle{
  Point c;
  number r;
  Circle(){}
  Circle(Point c,number r):c(c),r(r){}
};
bool sort_x(Point a,Point b){
  return a.x!=b.x?a.x<b.x:a.y<b.y;
}
bool sort_y(Point a,Point b){
  return a.y!=b.y?a.y<b.y:a.x<b.x;
}
number norm(Vector a){
  return a.x*a.x+a.y*a.y;
}
number abs(Vector a){
  return sqrt(norm(a));
}
number dot(Vector a,Vector b){
  return a.x*b.x+a.y*b.y;
}
number cross(Vector a,Vector b){
  return a.x*b.y-a.y*b.x;
}
Point orth(Point p){
  return Point(-p.y,p.x);
}
Point project(Segment s,Point p){
  Vector base=s.p2-s.p1;
  number r=dot(p-s.p1,base)/norm(base);
  return s.p1+base*r;
}
Point reflect(Segment s,Point p){
  return p+(project(s,p)-p)*2.0;
}
number arg(Vector p){
  return atan2(p.y,p.x);
}
Vector polar(number a,number r){
  return Point(cos(r)*a,sin(r)*a);
} 
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
number getDistanceLP(Line l,Point p){
  return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));
}
number getDistanceSP(Segment s,Point p){
  if(dot(s.p2-s.p1,p-s.p1) < 0.0 ) return abs(p-s.p1);
  if(dot(s.p1-s.p2,p-s.p2) < 0.0 ) return abs(p-s.p2);
  return getDistanceLP(s,p);
}
number getDistanceSS(Segment s1,Segment s2){
  if(intersectSS(s1,s2)) return 0.0;
  return min(min(getDistanceSP(s1,s2.p1),getDistanceSP(s1,s2.p2)),
             min(getDistanceSP(s2,s1.p1),getDistanceSP(s2,s1.p2)));
}
int intersectCC(Circle c1,Circle c2){
  if(c1.r<c2.r) swap(c1,c2);
  number d=abs(c1.c-c2.c);
  number r=c1.r+c2.r;
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
  number d1=abs(c.c-s.p1),d2=abs(c.c-s.p2);
  if(d1<c.r+EPS&&d2<c.r+EPS) return 0;
  if((d1<c.r-EPS&&d2>c.r+EPS)||(d1>c.r+EPS&&d2<c.r-EPS)) return 1;
  Point h=project(s,c.c);
  if(dot(s.p1-h,s.p2-h)<0) return 2;
  return 0;
}
Point getCrossPointLL(Line l1,Line l2){
  number a=cross(l1.p2-l1.p1,l2.p2-l2.p1);
  number b=cross(l1.p2-l1.p1,l1.p2-l2.p1);
  if(abs(a)<EPS&&abs(b)<EPS) return l2.p1;
  return l2.p1+(l2.p2-l2.p1)*(b/a);
}
Point getCrossPointSS(Segment s1,Segment s2){
  return getCrossPointLL(s1,s2);
}
Polygon getCrossPointCL(Circle c,Line l){
  Polygon ps;
  Point pr=project(l,c.c);
  Vector e=(l.p2-l.p1)/abs(l.p2-l.p1);
  if(equals(getDistanceLP(l,c.c),c.r)){
    ps.emplace_back(pr);
    return ps;
  }
  number base=sqrt(c.r*c.r-norm(pr-c.c));
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
  number d=abs(c1.c-c2.c);
  number a=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
  number t=arg(c2.c-c1.c);
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
    for(int n=u.size();n>=2&&ccw(u[n-2],u[n-1],s[i])!=CCW_CLOCKWISE;n--){
      u.pop_back();
    }
    u.push_back(s[i]);
  } 
  for(int i=s.size()-3;i>=0;i--){
    for(int n=l.size();n>=2&&ccw(l[n-2],l[n-1],s[i])!=CCW_CLOCKWISE;n--){
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
number diameter(Polygon s){
  Polygon p=s;
  int n=p.size();
  if(n==2) return abs(p[0]-p[1]);
  int i=0,j=0;
  for(int k=0;k<n;k++){
    if(p[i]<p[k]) i=k;
    if(!(p[j]<p[k])) j=k;
  }
  number res=0;
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
number area(Polygon s){
  number res=0;
  for(int i=0;i<(int)s.size();i++){
    res+=cross(s[i],s[(i+1)%s.size()])/2.0;
  }
  return abs(res);
}
number area(Circle c1,Circle c2){
  number d=abs(c1.c-c2.c);
  if(c1.r+c2.r<=d+EPS) return 0;
  if(d<=abs(c1.r-c2.r)){
    number r=min(c1.r,c2.r);
    return PI*r*r;
  }
  number rc=(d*d+c1.r*c1.r-c2.r*c2.r)/(2*d);
  number th=acos(rc/c1.r);
  number ph=acos((d-rc)/c2.r);
  return c1.r*c1.r*th+c2.r*c2.r*ph-d*c1.r*sin(th);
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
Vector translate(Vector v,number theta){
  Vector res;
  res.x=cos(theta)*v.x-sin(theta)*v.y;
  res.y=sin(theta)*v.x+cos(theta)*v.y;
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
  number g=norm(c1.c-c2.c);
  if(equals(g,0)) return ls;
  Point u=(c2.c-c1.c)/sqrt(g);
  Point v=orth(u);
  for(int s=1;s>=-1;s-=2){
    number h=(c1.r+s*c2.r)/sqrt(g);
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
number closest_pair(Polygon &a,int l=0,int r=-1){
  if(r<0){
    r=a.size();
    sort(a.begin(),a.end(),sort_x);
  }
  if(r-l<=1) return abs(a[0]-a[1]);
  int m=(l+r)>>1;
  number x=a[m].x;
  number d=min(closest_pair(a,l,m),closest_pair(a,m,r));
  inplace_merge(a.begin()+l,a.begin()+m,a.begin()+r,sort_y);

  Polygon b;
  for(int i=l;i<r;i++){
    if(fabs(a[i].x-x)>=d) continue;
    for(int j=0;j<(int)b.size();j++){
      number dy=a[i].y-next(b.rbegin(),j)->y;
      if(dy>=d) break;
      d=min(d,abs(a[i]-*next(b.rbegin(),j)));
    }
    b.emplace_back(a[i]);
  }
  return d;
}
vector<vector<pair<int, number> > >
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
  
  vector<vector<pair<int, number> > > G(ps.size());
  for(int i=0;i<n;i++){
    vector<pair<number,int> > ls;
    for(int j=0;j<(int)ps.size();j++)
      if(getDistanceSP(ss[i],ps[j])<EPS)
        ls.emplace_back(make_pair(norm(ss[i].p1-ps[j]),j));
      
    sort(ls.begin(),ls.end());
    for(int j=0;j+1<(int)ls.size();j++){
      int a=ls[j].second,b=ls[j+1].second;
      G[a].emplace_back(b,abs(ps[a]-ps[b]));
      G[b].emplace_back(a,abs(ps[a]-ps[b]));
    }
  }
  return G;
}
int manhattanIntersection(vector<Segment> ss,const int INF){
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
number area(Polygon ps,Circle c){
  if(ps.size()<3u) return 0;
  function<number(Circle, Point, Point)> dfs=
    [&](Circle c,Point a,Point b){
      Vector va=c.c-a,vb=c.c-b;
      number f=cross(va,vb),res=0;
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
  number res=0;
  for(int i=0;i<(int)ps.size();i++)
    res+=dfs(c,ps[i],ps[(i+1)%ps.size()]);
  return res/2;
}
//END CUT HERE

istream &operator >> (istream &is,Point &p){
  is>>p.x>>p.y;
  return is;
}
ostream &operator << (ostream &os,Point p){
  os<<fixed<<setprecision(12)<<p.x<<" "<<p.y;
  return os;
}
istream &operator >> (istream &is,Polygon &p){
  for(int i=0;i<(int)p.size();i++) is>>p[i];
  return is;
}
istream &operator >> (istream &is,Segment &s){
  is>>s.p1>>s.p2;
  return is;
}
istream &operator >> (istream &is,Circle &c){
  is>>c.c>>c.r;
  return is;
}

//Projection
signed AOJ_CGL1A(){
  Point p1,p2;
  cin>>p1>>p2;
  int q;
  cin>>q;
  while(q--){
    Point p;
    cin>>p;
    cout<<project(Line(p1,p2),p)<<endl;
  }
  return 0;
}
/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A&lang=jp
*/

//Reflect
signed AOJ_CGL1B(){
  Point p1,p2;
  cin>>p1>>p2;
  int q;
  cin>>q;
  while(q--){
    Point p;
    cin>>p;
    cout<<reflect(Line(p1,p2),p)<<endl;
  }
  return 0;
}
/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B&lang=jp
*/

//CCW
signed AOJ_CGL1C(){
  Point p0,p1;
  cin>>p0>>p1;
  int q;
  cin>>q;
  while(q--){
    Point p2;
    cin>>p2;
    int t=ccw(p0,p1,p2);
    if(t==CCW_COUNTER_CLOCKWISE) cout<<"COUNTER_CLOCKWISE"<<endl;
    if(t==CCW_CLOCKWISE) cout<<"CLOCKWISE"<<endl;
    if(t==CCW_ONLINE_BACK) cout<<"ONLINE_BACK"<<endl;
    if(t==CCW_ONLINE_FRONT) cout<<"ONLINE_FRONT"<<endl;
    if(t==CCW_ON_SEGMENT) cout<<"ON_SEGMENT"<<endl;
  }
  return 0;
}
/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C&lang=jp
*/

//intersectSS
signed AOJ_CGL2B(){
  int q;
  cin>>q;
  while(q--){
    Point p0,p1,p2,p3;
    cin>>p0>>p1>>p2>>p3;
    cout<<(intersectSS(Segment(p0,p1),Segment(p2,p3)))<<endl;
  }
  return 0;
}
/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B&lang=jp
*/

//cross point
signed AOJ_CGL2C(){
  int q;
  cin>>q;
  while(q--){
    Point p0,p1,p2,p3;
    cin>>p0>>p1>>p2>>p3;
    cout<<getCrossPointSS(Segment(p0,p1),Segment(p2,p3))<<endl;
  }
  return 0;
}
/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C&lang=jp
*/

//distanceSS
signed AOJ_CGL2D(){
  int q;
  cin>>q;
  while(q--){
    Point p0,p1,p2,p3;
    cin>>p0>>p1>>p2>>p3;
    printf("%.12f\n",getDistanceSS(Segment(p0,p1),Segment(p2,p3)));
  }
  return 0;
}
/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D&lang=jp
*/

//area of Polygon
signed AOJ_CGL3A(){
  int n;
  cin>>n;
  Polygon p(n);
  for(int i=0;i<n;i++) cin>>p[i];
  printf("%.1f\n",area(p));
  return 0;
}
/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A&lang=jp
*/


//isConvex
signed AOJ_CGL3B(){
  int n;
  cin>>n;
  Polygon p(n);
  for(int i=0;i<n;i++) cin>>p[i];
  cout<<isConvex(p)<<endl;
  return 0;
}
/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B&lang=jp
*/



//contains
signed AOJ_CGL3C(){
  int n;
  cin>>n;
  Polygon p(n);
  for(int i=0;i<n;i++) cin>>p[i];
  int q;
  cin>>q;
  while(q--){
    Point r;
    cin>>r;
    cout<<contains(p,r)<<endl;
  }
  return 0;
}
/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C
*/


//convex hull
signed AOJ_CGL4A(){
  int n;
  cin>>n;
  Polygon p(n);
  for(int i=0;i<n;i++) cin>>p[i];
  Polygon q=convex_hull(p);
  cout<<q.size()<<endl;
  for(Point v:q) cout<<v.x<<" "<<v.y<<endl;
  return 0;
}
/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A&lang=jp
*/

//diameter of Polygon
signed AOJ_CGL4B(){
  int n;
  cin>>n;
  Polygon p(n);
  for(int i=0;i<n;i++) cin>>p[i];
  printf("%.12f\n",diameter(p));
  return 0;
}
/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B&lang=jp
*/

//convexCut:
signed AOJ_CGL4C(){
  int n;
  cin>>n;
  Polygon g(n);
  for(int i=0;i<n;i++) cin>>g[i];
  Polygon p=andrewScan(g);
  int q;
  cin>>q;
  while(q--){
    Line l;
    cin>>l.p1>>l.p2;
    printf("%.12f\n",area(convexCut(p,l)));
  }
  return 0;
}
/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C&lang=jp
*/

//closest pair:
signed AOJ_CGL5A(){
  int n;
  cin>>n;
  Polygon p(n);
  for(int i=0;i<n;i++) cin>>p[i];
  cout<<fixed<<setprecision(12)<<closest_pair(p)<<endl;
  return 0;
}
/*
  verified on 2018/01/04
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A&lang=jp
*/

//manhattanIntersection:
signed AOJ_CGL6A(){
  int n;
  cin>>n;
  vector<Segment> ss(n);
  for(int i=0;i<n;i++) cin>>ss[i];
  //for(int i=0;i<n;i++) cout<<ss[i].p1<<":"<<ss[i].p2<<endl;
  cout<<manhattanIntersection(ss,1e9+10)<<endl;
  return 0;
}
/*
  verified on 2018/06/18
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_6_A&lang=jp
*/

//intersectCC
signed AOJ_CGL7A(){
  Circle c1,c2;
  cin>>c1>>c2;
  cout<<intersectCC(c1,c2)<<endl;
  return 0;
}
/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A&lang=jp
*/


//getCrossPointCL
signed AOJ_CGL7D(){
  Circle c;
  int q;
  cin>>c>>q;
  while(q--){
    Line l;
    cin>>l;
    auto pp=getCrossPointCL(c,l);
    if(pp.size()==1u) pp.emplace_back(pp[0]);
    if(pp[1]<pp[0]) swap(pp[0],pp[1]);
    cout<<pp[0]<<" "<<pp[1]<<endl;
  }
  return 0;
}
/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D&lang=jp
*/

//intersectCC
signed AOJ_CGL7E(){
  Circle c1,c2;
  cin>>c1>>c2;
  auto pp=getCrossPointCC(c1,c2);
  if(pp.size()==1u) pp.emplace_back(pp[0]);
  if(pp[1]<pp[0]) swap(pp[0],pp[1]);
  cout<<pp[0]<<" "<<pp[1]<<endl;
  return 0;
}
/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E&lang=jp
*/

//tangent to a Circle
signed AOJ_CGL7F(){
  Point p;
  Circle c;
  cin>>p>>c;
  auto pp=tangent(c,p);
  for(auto p:pp) cout<<p<<endl;
  return 0;
}
/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F&lang=jp
*/

//Common Tangent
signed AOJ_CGL7G(){
  Circle c1,c2;
  cin>>c1>>c2;
  auto ls=tangent(c1,c2);
  Polygon ps;
  for(auto l:ls) ps.emplace_back(getCrossPointCL(c1,l)[0]);
  sort(ps.begin(),ps.end());
  for(auto p:ps) cout<<p<<endl;
  return 0;
}
/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge//description.jsp?id=CGL_7_G&lang=jp
*/

//Intersection of a Circle and a Polygon
signed AOJ_CGL7H(){
  int n;
  number r;
  cin>>n>>r;
  Circle c(Point(0,0),r);
  Polygon ps(n);
  for(int i=0;i<n;i++) cin>>ps[i];
  cout<<fixed<<setprecision(12)<<area(ps,c)<<endl;
  return 0;
}
/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge//description.jsp?id=CGL_7_G&lang=jp
*/

//area of 2 circles' intersection
signed AOJ_2572(){
  number uw,uh,a,b,ab;
  while(cin>>uw>>uh>>a>>b>>ab,uw!=0){
    Circle c1(Point(0,0),sqrt(a/PI));
    Circle c2(Point(0,0),sqrt(b/PI));
    bool f=0;
    if(c1.r<=c2.r) swap(c1,c2),f=1;
    number l=max(0.0,c1.r-c2.r),r=c1.r+c2.r+EPS;
    for(int k=0;k<100;k++){
      number m=(l+r)/2;
      c2.c.x=m;
      //cout<<area(c1,c2)<<endl;
      if(area(c1,c2)<=ab) r=m;
      else l=m;
    }
    c2.c.x=l;
    
    number EPS3=1e-4;
    assert(abs(area(c1,c2)-ab)<=EPS3);

    l=0,r=PI/2;
    for(int k=0;k<200;k++){
      number m=(l+r)/2;
      Circle t=c2;
      t.c=translate(c2.c,m);
      if(c1.r+max(c1.r,t.c.x+t.r)<=uw) r=m;
      else l=m;
    }
    c2.c=translate(c2.c,r);
    //cout<<c1.c<<"/"<<c2.c<<endl;
    
    Vector v(c1.r,c1.r);
    c1.c=c1.c+v;
    c2.c=c2.c+v;
    
    //cout<<c1.c<<"/"<<c2.c<<endl;

    if(f) swap(c1,c2);
    f=1;
    f&=(c1.c.x-c1.r>=-EPS3);
    f&=(c1.c.x+c1.r<=uw+EPS3);
    f&=(c1.c.y-c1.r>=-EPS3);
    f&=(c1.c.y+c1.r<=uh+EPS3);
    f&=(c2.c.x-c2.r>=-EPS3);
    f&=(c2.c.x+c2.r<=uw+EPS3);
    f&=(c2.c.y-c2.r>=-EPS3);
    f&=(c2.c.y+c2.r<=uh+EPS3);
    if(f) cout<<c1.c<<" "<<c1.r<<" "<<c2.c<<" "<<c2.r<<endl;
    else cout<<"impossible"<<endl;
    //else cout<<c1.c<<" "<<c1.r<<"/"<<c2.c<<" "<<c2.r<<endl;
  }
  return 0;
}
/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2572
*/

//Segment Arrangement
signed AOJ_2454(){
  int n,m;
  cin>>n>>m;
  vector<Segment> ss(n);
  Polygon ps(m);
  for(int i=0;i<n;i++) cin>>ss[i];
  for(int i=0;i<m;i++) cin>>ps[i];
  map<Point, int> mp;
  for(int i=0;i<m;i++) mp[ps[i]]=i;
  Point s,g;
  cin>>s>>g;
  ps.emplace_back(s);
  ps.emplace_back(g);

  auto G=segmentArrangement(ss,ps);
  
  number ans=0,tmp=0;
  for(int i=0;i<n;i++) ans+=abs(ss[i].p1-ss[i].p2);

  vector<int> used(G.size(),0);
  queue<int> q;
  for(int i=0;i<(int)G.size();i++)
    if(ps[i]==g) {used[i]=1;q.emplace(i);}

  while(!q.empty()){
    int v=q.front();q.pop();
    if(ps[v]==s){
      cout<<(int)-1<<endl;
      return 0;
    }
    if(mp.count(ps[v])) continue;
    for(auto &e:G[v]){
      int u=e.first;
      if(!used[u]){
        used[u]=1;
        q.emplace(u);
      }
    }
  }
  
  for(int i=0;i<(int)G.size();i++)
    if(ps[i]==s) q.emplace(i);

  while(!q.empty()){
    int v=q.front();q.pop();
    for(auto &e:G[v]){
      int u=e.first;
      number &c=e.second;
      if(used[v]&&used[u]) continue;
      if(c==0) continue;
      tmp+=c;c=0;
      q.emplace(u);
    }
  }
  tmp/=2;
  
  cout<<fixed<<setprecision(12)<<ans-tmp<<endl;
  return 0;
}
/*
  verified on 2018/01/27
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2454
*/



signed main(){
  //AOJ_CGL1A();
  //AOJ_CGL1B();
  //AOJ_CGL1C();

  //AOJ_CGL2B();
  //AOJ_CGL2C();
  //AOJ_CGL2D();
  
  //AOJ_CGL3A();
  //AOJ_CGL3B();
  //AOJ_CGL3C();
  
  //AOJ_CGL4A();
  //AOJ_CGL4B();
  //AOJ_CGL4C();
  
  //AOJ_CGL5A();

  //AOJ_CGL6A();
  
  //AOJ_CGL7A();
  //AOJ_CGL7D();
  //AOJ_CGL7E();
  //AOJ_CGL7F();
  //AOJ_CGL7G();
  //AOJ_CGL7H();

  //AOJ_2572();
  //AOJ_2454();
  
  return 0;
}
