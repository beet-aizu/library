#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D"
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#undef call_from_test

#define ERROR "0.000001"

//getCrossPointCL
signed main(){
  Circle c;
  int q;
  cin>>c>>q;
  while(q--){
    Line l;
    cin>>l;
    auto pp=getCrossPointCL(c,l);
    if(pp.size()==1u) pp.emplace_back(pp[0]);
    if(pp[1]<pp[0]) swap(pp[0],pp[1]);
    cout<<pp[0]<<" "<<pp[1]<<endl;
  }
  return 0;
}
