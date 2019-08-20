#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A"
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#undef call_from_test

#define ERROR "0.000001"

// closest_pair
signed main(){
  int n;
  cin>>n;
  Polygon p(n);
  for(int i=0;i<n;i++) cin>>p[i];
  cout<<fixed<<setprecision(12)<<closest_pair(p)<<endl;
  return 0;
}
