#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_triangles"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../graph/triangle.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using ll = long long;

  int n,m;
  cin>>n>>m;
  vector<ll> xs(n);
  for(int i=0;i<n;i++) cin>>xs[i];

  Triangle G(n);
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    G.add_edge(u,v);
  }

  const ll mod = 998244353;
  ll ans=0;
  auto f=[&](int x,int y,int z){
    ans+=xs[x]*xs[y]%mod*xs[z]%mod;
    ans%=mod;
  };
  G.build(f);

  cout<<ans<<endl;
  return 0;
}
