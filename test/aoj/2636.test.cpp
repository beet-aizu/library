#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2636"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../toptree/toptree.cpp"
#include "../../toptree/distancesum.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int n;
  cin>>n;

  using ll = long long;
  const size_t LIM = 1e6;
  DistanceSum<ll, LIM> G;
  using Vertex = decltype(G)::Vertex;
  using Cluster = decltype(G)::Cluster;

  vector<Vertex*> vs(n);
  for(int i=0;i<n;i++) vs[i]=G.G.create(Vertex(0));

  for(int i=1;i<n;i++){
    int p,d;
    cin>>p>>d;
    p--;
    G.G.link(vs[p],Cluster(d),vs[i]);
  }

  for(int i=0;i<n;i++){
    G.G.set_vertex(vs[i],Vertex(1));
    cout<<G.query(G.centroid(vs[i]))<<newl;
  }
  return 0;
}
