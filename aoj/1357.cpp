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
struct Circle{
  Point c;
  double r;
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
  Point a;
  vector<Circle> v;
  Circle c;
  double r;
  cin >> r;
  c.c.x=r;c.c.y=r;c.r=r;
  v.push_back(c);
  for(int i=1;i<n;i++){
    cin >> r;
    c.c.x=r;c.c.y=r;c.r=r;
    for(int j=0;j<i;j++){
      
      c.c.x=max(c.c.x,v[j].c.x+sqrt((v[j].r+c.r)*(v[j].r+c.r)-(v[j].c.y-c.c.y)*(v[j].c.y-c.c.y)));
      
    }
    if(c.c.x<0) c.c.x=0;
    v.push_back(c);
  }
  //cout << v[n-1].c.x+v[n-1].r << endl;
  double o=0;
  for(int i=0;i<n;i++) o=max(o,v[i].c.x+v[i].r);
  printf("%.5f\n",o);
  return 0;
}
