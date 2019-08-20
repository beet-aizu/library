#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H"
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#undef call_from_test

#define ERROR "0.00001"

//Intersection of a Circle and a Polygon
signed main(){
  int n;
  double r;
  cin>>n>>r;
  Circle c(Point(0,0),r);
  Polygon ps(n);
  for(int i=0;i<n;i++) cin>>ps[i];
  cout<<fixed<<setprecision(12)<<area(ps,c)<<endl;
  return 0;
}
