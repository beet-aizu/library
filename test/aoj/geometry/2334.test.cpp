// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2334
// verification-helper: ERROR 1e-9

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#include "../../../tools/chminmax.cpp"
#include "../../../graph/dijkstra.cpp"
#undef call_from_test

signed main(){
  int n,m;
  cin>>n>>m;

  Polygon ps(n),qs(m);
  for(int i=0;i<n;i++) cin>>ps[i];
  for(int i=0;i<m;i++) cin>>qs[i];

  using D = double;
  const D INF = 1e18;

  Dijkstra<D> G(n),H(m);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j) continue;
      Segment s(ps[i],ps[j]);
      Segment t(qs[0],qs[1]);
      if(getDistanceSS(s,t)<EPS) continue;
      G.add_edge(i,j,abs(ps[i]-ps[j]));
    }
  }

  for(int i=0;i<m;i++){
    for(int j=0;j<m;j++){
      if(i==j) continue;
      Segment s(qs[i],qs[j]);
      Segment t(ps[0],ps[1]);
      if(getDistanceSS(s,t)<EPS) continue;
      H.add_edge(i,j,abs(qs[i]-qs[j]));
    }
  }
  G.build(0);
  H.build(0);

  D ans=INF;
  chmin(ans,G[1]+abs(qs[0]-qs[1]));
  chmin(ans,H[1]+abs(ps[0]-ps[1]));

  if(ans==INF) cout<<-1<<endl;
  else cout<<fixed<<setprecision(12)<<ans<<endl;
  return 0;
}
