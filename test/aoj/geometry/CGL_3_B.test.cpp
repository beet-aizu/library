// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#undef call_from_test

//isConvex
signed main(){
  int n;
  cin>>n;
  Polygon ps(n);
  cin>>ps;
  cout<<isConvex(ps)<<endl;
  return 0;
}
