#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2872"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../bflow/capacityscaling.cpp"
#include "../../graph/bellmanford.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using ll = long long;
  const ll INF = 1<<30;

  int n,m,s,t;
  cin>>n>>m>>s>>t;
  s--;t--;
  MaxGainFlow<ll, ll> G(n);
  BellmanFord<int> H(n);
  for(int i=0;i<m;i++){
    int u,v,d,c;
    cin>>u>>v>>d>>c;
    u--;v--;
    G.add_edge(u,v,0,c,-d);
    H.add_edge(u,v,d);
  }
  int neg_loop;
  int len=H.shortest_path(s,t,neg_loop);
  assert(!neg_loop);
  G.add_edge(t,s,0,INF,len+1);

  assert(G.build());
  cout<<G.get_gain()<<endl;
  return 0;
}
