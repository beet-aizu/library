#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2872"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../flow/primaldual.cpp"
#include "../../flow/negativeedge.cpp"
#include "../../graph/bellmanford.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using ll = long long;
  const ll INF = 1e9;
  int n,m,s,t;
  cin>>n>>m>>s>>t;
  s--;t--;
  NegativeEdge<ll, ll> G(n);
  BellmanFord<int> H(n);
  for(int i=0;i<m;i++){
    int u,v,d,c;
    cin>>u>>v>>d>>c;
    u--;v--;
    G.add_edge(u,v,c,d);
    H.add_edge(u,v,d);
  }
  int neg_loop;
  int len=H.shortest_path(s,t,neg_loop);
  assert(!neg_loop);
  G.add_edge(t,s,INF,-(len+1));
  int ok;
  cout<<-G.flow(ok)<<endl;
  assert(ok);
  return 0;
}
