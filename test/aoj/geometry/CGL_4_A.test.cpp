#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#undef call_from_test

//convex hull
signed main(){
  int n;
  cin>>n;
  Polygon ps(n);
  cin>>ps;
  Polygon qs=convex_hull(ps);
  cout<<qs.size()<<endl;
  for(Point v:qs) cout<<(int)v.x<<" "<<(int)v.y<<endl;
  return 0;
}
