// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B
// verification-helper: ERROR 0.000001

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#undef call_from_test


//diameter of Polygon
signed main(){
  int n;
  cin>>n;
  Polygon ps(n);
  cin>>ps;
  cout<<fixed<<setprecision(12)<<diameter(ps)<<endl;
  return 0;
}
