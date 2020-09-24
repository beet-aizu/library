#define PROBLEM "https://judge.yosupo.jp/problem/min_cost_b_flow"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../bflow/capacityscaling.cpp"
#undef call_from_test

#ifdef __clang__
#define IGNORE
#endif

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;

  using ll = long long;
  MinCostFlow<ll, ll> G(n);
  for(int i=0;i<n;i++){
    int b;
    cin>>b;
    if(b>0) G.add_supply(i,+b);
    if(b<0) G.add_demand(i,-b);
  }

  vector<decltype(G)::EdgePtr> es;
  for(int i=0;i<m;i++){
    int s,t,l,u,c;
    cin>>s>>t>>l>>u>>c;
    auto e=G.add_edge(s,t,l,u,c);
    es.emplace_back(e);
  }

  if(!G.build()){
    cout<<"infeasible\n";
    return 0;
  }

  auto print=[&](auto res){
    if(res==0){
      cout<<0<<'\n';
      return;
    }
    if(res<0) cout<<'-',res*=-1;
    string ans;
    while(res){
      ans+=char('0'+res%10);
      res/=10;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<'\n';
  };
  print(G.get_cost<__int128_t>());

  auto p=G.get_potential();
  for(int i=0;i<n;i++) cout<<p[i]<<'\n';
  for(auto e:es) cout<<G.get_edge(e).flow<<'\n';
  return 0;
}
