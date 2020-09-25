// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#undef call_from_test

//Parallel / Orthogonal
signed main(){
  int q;
  cin>>q;
  while(q--){
    Point p0,p1,p2,p3;
    cin>>p0>>p1>>p2>>p3;
    if(isParallel(Line(p0,p1),Line(p2,p3))) cout<<2<<endl;
    else if(isOrthogonal(Line(p0,p1),Line(p2,p3))) cout<<1<<endl;
    else cout<<0<<endl;
  }
  return 0;
}
