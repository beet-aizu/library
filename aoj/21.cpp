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

bool isParallel(Vector a,Vector b){
  return equals(cross(a,b),0.0);
}
int main(){
  Point a,b,c,d;
  int n;
  cin >> n;
  int i;
  for(i=0;i<n;i++){
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    if(isParallel(a-b,c-d)) cout << "YES" <<endl;
    else cout << "NO" <<endl;
  }
  return 0;
}
