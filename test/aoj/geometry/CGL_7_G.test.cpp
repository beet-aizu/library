// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_G
// verification-helper: ERROR 0.00001

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#undef call_from_test


//Common Tangent
signed main(){
  Circle c1,c2;
  cin>>c1>>c2;
  auto ls=tangent(c1,c2);
  Polygon ps;
  for(auto l:ls) ps.emplace_back(getCrossPointCL(c1,l)[0]);
  sort(ps.begin(),ps.end());
  for(auto p:ps) cout<<p<<endl;
  return 0;
}
