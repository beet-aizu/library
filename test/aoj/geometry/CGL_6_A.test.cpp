#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_6_A"
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#undef call_from_test

// manhattanIntersection
signed main(){
  int n;
  cin>>n;
  vector<Segment> ss(n);
  for(int i=0;i<n;i++) cin>>ss[i];
  cout<<manhattanIntersection(ss,1e9+10)<<endl;
  return 0;
}
