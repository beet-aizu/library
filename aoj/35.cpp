#include<iostream>
#include<string>
#include<sstream>
#include<stdlib.h>
#include<math.h>
#include<vector>
#define EPS (1e-10)
using namespace std;
double s2d(string str){
  stringstream ss(str);
  double x;ss>>x;
  return x;
}
struct Point{
  double x,y;
  Point(){}
  Point(double x,double y) :x(x),y(y){}
  Point operator + (Point &p) {return Point(x+p.x,y+p.y);}
  Point operator - (Point &p) {return Point(x-p.x,y-p.y);}
  Point operator * (double k) {return Point(x*k,y*k);}
  Point operator / (double k) {return Point(x/k,y/k);}
};
typedef Point Vector;
typedef vector<Point> Polygon;
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
int main(){
  string str;
  while(cin >> str){
    Point p[4];
    int i,j,k;
    for(i=0;i<str.size();i++)if(str[i]==',') str[i]=' ';
    stringstream ss(str);
    for(i=0;i<4;i++){
      ss>>str;p[i].x=s2d(str);
      ss>>str;p[i].y=s2d(str);
      //cout << p[i].x <<":" << p[i].y << endl;
    }
    bool f=false;
    for(i=0;i<4;i++){
      Polygon g;
      g.clear();
      for(j=0;j<4;j++){
	if(i!=j) g.push_back(p[j]);
      }
      //cout << contains(g,p[i]) << endl;
      if(contains(g,p[i])==2) f=true;
    }
    if(!f) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
