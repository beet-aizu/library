#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C"
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#undef call_from_test

#define IGNORE

//cross point
signed main(){
  int q;
  cin>>q;
  while(q--){
    Point p0,p1,p2,p3;
    cin>>p0>>p1>>p2>>p3;
    cout<<getCrossPointSS(Segment(p0,p1),Segment(p2,p3))<<endl;
  }
  return 0;
}
