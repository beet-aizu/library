#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D"
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#include "../../../tools/precision.cpp"
#undef call_from_test

#define ERROR "0.00000001"

//distanceSS
signed main(){
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    Point p0,p1,p2,p3;
    cin>>p0>>p1>>p2>>p3;
    cout<<getDistanceSS(Segment(p0,p1),Segment(p2,p3))<<endl;
  }
  return 0;
}
