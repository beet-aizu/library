//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<stdlib.h>

using namespace std;
#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b)) < EPS)
 
static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;
 
struct Point{
  double x,y;
  Point(){}
  Point(double x,double y):x(x),y(y){}
  
  Point operator+(Point p){return Point(x+p.x,y+p.y);}
  Point operator-(Point p){return Point(x-p.x,y-p.y);}
  Point operator*(double k){return Point(x*k,y*k);}
  Point operator/(double k){return Point(x/k,y/k);}
   
  double norm(){return x*x+y*y;}
  double abs(){return sqrt(norm());}
 
  bool operator<(const Point &p) const{
    return x!=p.x? x< p.x : y < p.y;
  }
 
  bool operator==(const Point &p) const{
    return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS ;
  }
};
 
typedef Point Vector;
double norm(Vector a){return a.x*a.x+a.y*a.y;}
double abs(Vector a){return sqrt(norm(a));}
double dot(Vector a,Vector b){
  return a.x*b.x+a.y*b.y;
}
double cross(Vector a,Vector b){
  return a.x*b.y-a.y*b.x;
}
int ccw(Point p0,Point p1,Point p2){
  Vector a = p1-p0;
  Vector b = p2-p0;
  if(cross(a,b) > EPS) return COUNTER_CLOCKWISE;
  if(cross(a,b) < -EPS) return CLOCKWISE;
  if(dot(a,b) < -EPS) return ONLINE_BACK;
  if(a.norm()<b.norm()) return ONLINE_FRONT;
  return ON_SEGMENT;
}
typedef vector<Point> Polygon;
struct Segment{
  Point p1,p2;
  Segment(){}
  Segment(Point p1, Point p2):p1(p1),p2(p2){}
};
typedef Segment Line;
 
double getDistanceLP(Line l,Point p){
  return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));
}
 
Vector half(Vector a,Vector b){
  return (a*b.abs()+b*a.abs())*1000;
}
 
Point getCrossPoint(Segment s1,Segment s2){
  Vector base=s2.p2-s2.p1;
  double d1=abs(cross(base,s1.p1-s2.p1));
  double d2=abs(cross(base,s1.p2-s2.p1));
  double t=d1/(d1+d2);
  return s1.p1+(s1.p2-s1.p1)*t;
}
int contains(Polygon g, Point p){
  int n=g.size();
  bool x=false;
  for(int i=0;i<n;i++){
    Point a=g[i]-p,b=g[(i+1)%n]-p;
    if(abs(cross(a,b)) < EPS && dot(a,b) < EPS) return 1;
    if(a.y>b.y) swap(a,b);
    if(a.y<EPS&&EPS<b.y&&cross(a,b)>EPS) x=!x;
  }
  return (x?2:0);
}
 
int main(){
  int n;
  while(cin>>n,n){
    Polygon p;
    p.clear();
    double x,y;
    for(int i=0;i<n;i++){
      scanf("%lf %lf",&x,&y);
      p.push_back(Point(x,y));
    }
 
    double ans=0,bg1,bg2;
     
    Point g1,g2;
     
    for(int i=0;i<n;i++){
      Vector v = half(p[(i+n-1)%n]-p[i],p[(i+1)%n]-p[i]);
      v=v/v.abs()*30000;
      //cout << v.x << ":" << v.y << endl;
      Point s=p[i],e=p[i]+v;
      while(contains(p,e)==0){
	e=(s+e*3)/4.0;
      }
      for(int j=0;j<5000;j++){
	g1=(s*2+e)/3.0;
	g2=(s+e*2)/3.0;
	bg1=getDistanceLP(Segment(p[0],p[1]),g1);
	bg2=getDistanceLP(Segment(p[0],p[1]),g2);
	for(int j=1;j<n;j++){
	  bg1=min(bg1,getDistanceLP(Segment(p[j],p[(j+1)%n]),g1));
	  bg2=min(bg2,getDistanceLP(Segment(p[j],p[(j+1)%n]),g2));
	}	
	ans=max(ans,bg1);
	ans=max(ans,bg2);
	if(bg1<bg2) s=g1;
	else e=g2;
      }
    }

     
    //cout << ans << endl;
   
    printf("%.6lf\n",ans);
  }
   
  return 0;
}
