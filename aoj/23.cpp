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
double norm(Vector a){
  return pow(a.x,2.0)+pow(a.y,2.0);
}
double abs(Vector a){
  return sqrt(norm(a));
}
class Circle{
public:
  Point c;
  double r;
  Circle(Point c = Point(),double r = 0.0):c(c),r(r){}
};
int check(Circle a,Circle b){
  double d1 = abs(b.c-a.c) , d2 = (a.r+b.r);
  
  if(d1+b.r-a.r<0) return 2;
  if(d1+a.r-b.r<0) return -2;
  if(d1-d2<=0) return 1;
  return 0;
}
int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    Point a,b;
    double r1,r2;
    cin >> a.x >> a.y >> r1 >> b.x >> b.y >> r2;
    Circle c1(a,r1),c2(b,r2);
    cout << check(c1,c2) << endl;
  }
  return 0;
}
