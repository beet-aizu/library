#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C"
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#undef call_from_test

//CCW
signed main(){
  Point p0,p1;
  cin>>p0>>p1;
  int q;
  cin>>q;
  while(q--){
    Point p2;
    cin>>p2;
    int t=ccw(p0,p1,p2);
    if(t==CCW_COUNTER_CLOCKWISE) cout<<"COUNTER_CLOCKWISE"<<endl;
    if(t==CCW_CLOCKWISE) cout<<"CLOCKWISE"<<endl;
    if(t==CCW_ONLINE_BACK) cout<<"ONLINE_BACK"<<endl;
    if(t==CCW_ONLINE_FRONT) cout<<"ONLINE_FRONT"<<endl;
    if(t==CCW_ON_SEGMENT) cout<<"ON_SEGMENT"<<endl;
  }
  return 0;
}
