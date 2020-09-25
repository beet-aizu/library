// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_I
// verification-helper: ERROR 0.000001

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#include "../../../io/precision.cpp"
#undef call_from_test

// area of 2 circles' intersection
signed main(){
  Circle c1,c2;
  cin>>c1>>c2;
  cout<<area(c1,c2)<<endl;
  return 0;
}
