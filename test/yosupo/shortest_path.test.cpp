#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/drop.cpp"
#include "../../graph/dijkstra.cpp"
#undef call_from_test

#ifdef SANITIZE
#define IGNORE
#endif

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int n,m,s,t;
  cin>>n>>m>>s>>t;

  using ll = long long;
  Dijkstra<ll> G(n);
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    G.add_edge(a,b,c);
  }

  G.build(s);
  auto ps=G.restore(t);
  if(ps.empty()) drop(-1);

  int y=ps.size()-1;
  cout<<G[t]<<' '<<y<<newl;
  for(int i=0;i<y;i++) cout<<ps[i]<<' '<<ps[i+1]<<newl;
  return 0;
}
