#include<iostream>
#include<stdlib.h>
#include<math.h>
#define EPS (1e-10)
using namespace std;
struct Point{
  double x,y;
  Point(){};
  Point(double x,double y):x(x),y(y){}
  Point operator-(Point p){return Point(x-p.x,y-p.y);}
};
double dot(Point a,Point b){
  return a.x*b.x+a.y*b.y;
}
int main(){
  Point p[4];
  while(cin>>p[0].x>>p[0].y){
    int i,j,k;
    for(i=1;i<4;i++) cin>>p[i].x>>p[i].y;
    if(fabs(dot(p[0]-p[1],p[2]-p[3]))<EPS) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
