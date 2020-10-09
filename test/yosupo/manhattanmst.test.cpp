#define PROBLEM "https://judge.yosupo.jp/problem/manhattanmst"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../graph/manhattanmst.cpp"
#include "../../datastructure/unionfind.cpp"
#include "../../graph/kruskal.cpp"
#undef call_from_test

#ifdef SANITIZE
#define IGNORE
#endif

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  using ll = long long;

  int n;
  cin>>n;
  vector<ll> xs(n),ys(n);
  for(int i=0;i<n;i++) cin>>xs[i]>>ys[i];

  Kruskal<ll> mst(n);
  for(auto[u,v]:manhattanmst(xs,ys))
    mst.add_edge(u,v,abs(xs[u]-xs[v])+abs(ys[u]-ys[v]));

  cout<<mst.build()<<newl;
  for(auto e:mst.es)
    if(e.used) cout<<e.src<<' '<<e.dst<<newl;
  return 0;
}
