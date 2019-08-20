#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A"
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#undef call_from_test

//intersectCC
signed main(){
  Circle c1,c2;
  cin>>c1>>c2;
  cout<<intersectCC(c1,c2)<<endl;
  return 0;
}
