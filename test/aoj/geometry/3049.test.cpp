// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3049
// verification-helper: ERROR 1e-5

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../tools/chminmax.cpp"
#include "../../../io/precision.cpp"
#include "../../../geometry/geometry.cpp"
#undef call_from_test


signed main(){
  int n;
  cin>>n;
  Polygon ps(n);
  cin>>ps;
  ps=andrewScan(ps);
  n=ps.size();

  int m;
  cin>>m;
  Polygon cs(m);
  cin>>cs;

  double ans=0;
  for(int i=0;i<m;i++){
    Polygon ts(ps);
    for(int j=0;j<m;j++){
      if(i==j) continue;
      Line l=bisector(cs[i],cs[j]);
      ts=convexCut(ts,l);
    }
    for(Point &x:ts) chmax(ans,abs(x-cs[i]));
  }

  cout<<ans<<endl;
  return 0;
}
