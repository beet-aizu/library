#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
struct Point{double x,y;};
double dis(Point a,Point b){
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
Point tri(Point a, Point b, Point c){
  double a1,a2,b1,b2,c1,c2;
  a1=2*(b.x-a.x);
  b1=2*(b.y-a.y);
  c1=a.x*a.x-b.x*b.x+a.y*a.y-b.y*b.y;
  a2=2*(c.x-a.x);
  b2=2*(c.y-a.y);
  c2=a.x*a.x-c.x*c.x+a.y*a.y-c.y*c.y;
  Point p;
  p.x=(b1*c2-b2*c1)/(a1*b2-a2*b1);
  p.y=(c1*a2-c2*a1)/(a1*b2-a2*b1);
  return p;
}
int main(){
  int n;
  cin >> n;
  int i;
  for(i=0;i<n;i++){
  Point a,b,c;
  cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
  Point x = tri(a,b,c);
  printf("%.3f %.3f %.3f\n",x.x,x.y,dis(x,a));
  }
  return 0;
}
