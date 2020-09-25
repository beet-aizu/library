// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C
// verification-helper: ERROR 0.00001

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#undef call_from_test

//convexCut
signed main(){
  int n;
  cin>>n;
  Polygon gs(n);
  cin>>gs;
  Polygon ps=andrewScan(gs);
  int q;
  cin>>q;
  while(q--){
    Line l;
    cin>>l.p1>>l.p2;
    cout<<fixed<<setprecision(12)<<area(convexCut(ps,l))<<endl;
  }
  return 0;
}
