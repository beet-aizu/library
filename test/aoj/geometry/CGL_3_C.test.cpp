// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#undef call_from_test

//contains
signed main(){
  int n;
  cin>>n;
  Polygon ps(n);
  cin>>ps;
  int q;
  cin>>q;
  while(q--){
    Point r;
    cin>>r;
    cout<<contains(ps,r)<<endl;
  }
  return 0;
}
