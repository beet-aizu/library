#include<bits/stdc++.h>
#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b)) < EPS)
#define PI 3.141592653589793238
#define int long long
using namespace std;
struct Point3D{
  double x,y,z;
  Point3D(){}
  Point3D(double x,double y,double z):x(x),y(y),z(z){}
  Point3D operator+(Point3D p) {return Point3D(x+p.x,y+p.y,z+p.x);}
  Point3D operator-(Point3D p) {return Point3D(x-p.x,y-p.y,z-p.z);}
  Point3D operator*(double k){return Point3D(x*k,y*k,z*k);}
  Point3D operator/(double k){return Point3D(x/k,y/k,z/k);}
  double norm(){return x*x+y*y+z*z;}
  double abs(){return sqrt(norm());}
  bool operator < (const Point3D &p) const{
    if(x!=p.x) return x<p.x;
    if(y!=p.y) return y<p.y;
    return z<p.z;
  }
  bool operator == (const Point3D &p) const{
    return fabs(x-p.x)<EPS && fabs(y-p.y)<EPS && fabs(z-p.z)<EPS;
  }
};
istream &operator >> (istream &is,Point3D &p){
  is>>p.x>>p.y>>p.z;
  return is;
}
ostream &operator << (ostream &os,Point3D p){
  os<<fixed<<setprecision(12)<<p.x<<" "<<p.y<<" "<<p.z;
  return os;
}

typedef Point3D Vector3D;
typedef vector<Point3D> Polygon3D;

struct Segment3D{
  Point3D p1,p2;
  Segment3D(){}
  Segment3D(Point3D p1, Point3D p2):p1(p1),p2(p2){}
};
typedef Segment3D Line3D;

istream &operator >> (istream &is,Segment3D &s){
  is>>s.p1>>s.p2;
  return is;
}

struct Sphere{
  Point3D c;
  double r;
  Sphere(){}
  Sphere(Point3D c,double r):c(c),r(r){}
};

istream &operator >> (istream &is,Sphere &c){
  is>>c.c>>c.r;
  return is;
}

double norm(Vector3D a){
  return a.x*a.x+a.y*a.y+a.z*a.z;
}
double abs(Vector3D a){
  return sqrt(norm(a));
}
double dot(Vector3D a,Vector3D b){
  return a.x*b.x+a.y*b.y+a.z*b.z;
}
Vector3D cross(Vector3D a,Vector3D b){
  return Vector3D(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}
double getDistanceLP(Line3D l,Point3D p){
  return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));
}

double getDistanceSP(Segment3D s,Point3D p){
  if(dot(s.p2-s.p1,p-s.p1) < 0.0 ) return abs(p-s.p1);
  if(dot(s.p1-s.p2,p-s.p2) < 0.0 ) return abs(p-s.p2);
  return getDistanceLP(s,p);
}

bool intersectSC(Segment3D s,Sphere c){
  double d=getDistanceSP(s,c.c);
  if(d>c.r) return 0;
  return !((abs(s.p1-c.c)<=c.r)&&(abs(s.p2-c.c)<=c.r));
}

signed main(){
  return 0;
}
