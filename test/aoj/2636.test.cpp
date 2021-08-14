// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2636

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
  const size_t N = 2e5;
  using Cluster = DistanceSum<ll>;
  TopTree<Vertex, Cluster, N> G;

  vector<Vertex*> vs(n);
  for(int i=0;i<n;i++) vs[i]=G.create(0);

  for(int i=1;i<n;i++){
    int p,d;
    cin>>p>>d;
    p--;
    G.link(vs[p],d,vs[i]);
  }

  for(int i=0;i<n;i++){
    G.set_vertex(vs[i],1);
    cout<<G.get_subtree(centroid(G,vs[i])).ans<<newl;
  }
  return 0;
}
