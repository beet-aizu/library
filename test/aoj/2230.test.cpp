#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2230"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/chminmax.cpp"
#include "../../bflow/capacityscaling.cpp"
#undef call_from_test

signed main(){
  using P = pair<int, int>;
  using ll = long long;
  const ll INF = 1<<30;

  int n,m;
  cin>>n>>m;
  vector< vector<P> > H(n);
  MinCostFlow<ll, ll> G(n);
  for(int i=0;i<m;i++){
    int x,y,s;
    cin>>x>>y>>s;
    H[x].emplace_back(y,s);
    G.add_edge(y,x,1,INF,-s);
  }

  vector<int> dp(n,0);
  for(int i=0;i<n;i++)
    for(auto e:H[i])
      chmax(dp[e.first],dp[i]+e.second);
  G.add_edge(0,n-1,0,INF,dp[n-1]);

  assert(G.build());
  cout<<G.get_cost()<<endl;
  return 0;
}
