#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H"
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#include "../../../io/precision.cpp"
#undef call_from_test

#define ERROR "0.00001"

// intersection of a circle and a polygon
signed main(){
  int n;
  double r;
  cin>>n>>r;
  Circle c(Point(0,0),r);
  Polygon ps(n);
  for(int i=0;i<n;i++) cin>>ps[i];
  cout<<area(ps,c)<<endl;
  return 0;
}
