// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E
// verification-helper: ERROR 0.000001

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#undef call_from_test

//intersectCC
signed main(){
  Circle c1,c2;
  cin>>c1>>c2;
  auto pp=getCrossPointCC(c1,c2);
  if(pp.size()==1u) pp.emplace_back(pp[0]);
  if(pp[1]<pp[0]) swap(pp[0],pp[1]);
  cout<<pp[0]<<" "<<pp[1]<<endl;
  return 0;
}
