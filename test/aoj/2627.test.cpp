#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2627"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/chminmax.cpp"
#include "../../flow/primaldual.cpp"
#include "../../flow/negativeedge.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using ll = long long;
  const ll INF = 1e9;

  int n;
  cin>>n;
  NegativeEdge<int, ll> G(n+1);

  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    map<int, int> dst;
    for(int j=0;j<k;j++){
      int t,c;
      cin>>t>>c;
      t--;
      G.use_edge(i,t,1,c);
      if(!dst.count(t)) dst[t]=c;
      chmin(dst[t],c);
    }

    for(auto p:dst)
      G.add_edge(i,p.first,INF,p.second);

    G.add_edge(i,n,INF,0);
  }

  int ok;
  ll ans=G.flow(0,n,INF,ok);
  assert(ok);
  cout<<ans<<endl;
  return 0;
}
