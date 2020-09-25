// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F
// verification-helper: ERROR 0.00001

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#undef call_from_test


//tangent to a Circle
signed main(){
  Point p;
  Circle c;
  cin>>p>>c;
  auto pp=tangent(c,p);
  for(auto p:pp) cout<<p<<endl;
  return 0;
}
