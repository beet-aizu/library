#define PROBLEM "https://judge.yosupo.jp/problem/assignment"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../bflow/capacityscaling.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using ll = long long;

  int n;
  cin>>n;
  MinCostFlow<ll, ll> G(n+n);

  for(int i=0;i<n;i++){
    G.add_supply(0+i,1);
    G.add_demand(n+i,1);
  }

  vector<vector<decltype(G)::EdgePtr>> E(n);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int a;
      cin>>a;
      E[i].emplace_back(G.add_edge(i,n+j,0,1,a));
    }
  }

  assert(G.build());
  cout<<G.get_cost()<<endl;
  for(int i=0;i<n;i++){
    if(i) cout<<' ';
    for(auto e:E[i])
      if(G.get_edge(e).flow)
        cout<<G.get_edge(e).dst-n;
  }
  cout<<endl;
  return 0;
}
