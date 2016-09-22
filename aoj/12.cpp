#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
#define EPS (1e-10)
#define equals(a,b) (fabs((a) - (b)) < EPS)
class Point{
public:
  double x,y;
  Point(double x = 0, double y = 0):x(x), y(y) {}
  Point operator + (Point p){
    return Point(x+p.x,y+p.y);
  }
  Point operator - (Point p){
    return Point(x-p.x,y-p.y);
  }
  Point operator * (double k){
    return Point(x*k,y*k);
  }
  Point operator / (double k){
    return Point(x/k,y/k);
  }
  bool operator == (const Point &p) const{
    return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
  }
};
typedef Point Vector;
typedef vector<Point> Polygon;
double dot(Vector a,Vector b){
  return a.x * b.x + a.y * b.y;
}
double cross(Vector a,Vector b){
  return a.x * b.y - a.y * b.x;
}
// IN 2 ON 1 OUT 0
int contains(Polygon g,Point p){
  int n=g.size();
  bool x = false;
  for(int i=0;i<n;i++){
    Point a = g[i] - p, b = g[(i+1)%n] - p;
    if(fabs(cross(a,b))<EPS && dot(a,b) < EPS ) return 1;
    if(a.y > b.y ) swap(a,b);
    if(a.y<EPS && EPS < b.y && cross(a,b) > EPS) x = !x;
  }
  return ( x ? 2:0);
}
int main(){
  Point a,b,c,d;
  while(cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y){
    Polygon g;
    g.push_back(a);g.push_back(b);g.push_back(c);
    if(contains(g,d)==2) cout << "YES" <<endl;
    else cout << "NO" <<endl;
  }
  return 0;
}
