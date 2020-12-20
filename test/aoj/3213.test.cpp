// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3213

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/single.cpp"
#include "../../tools/chminmax.cpp"
#include "../../tools/defaultdict.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int n,m;
  cin>>n>>m;
  m++; // [0, m] -> [0, m)

  auto as=read(n);
  auto bs=read(n);

  while(n<34){
    as.emplace_back(0);
    bs.emplace_back(0);
    n++;
  }
  assert(n==34);
  using ll = long long;

  const int h = n/2;
  const int sz = 1<<h;
  using P = pair<ll, ll>;
  vector<P> vp,vq;
  for(int t=0;t<2;t++){
    for(int bit=0;bit<sz;bit++){
      ll x=0,y=0;
      for(int i=0;i<h;i++){
        if((bit>>i)&1){
          x^=as[t*h+i];
          y+=bs[t*h+i];
        }
      }
      vp.emplace_back(x,y);
    }
    swap(vp,vq);
  }

  const ll INF = 1e18;
  const int LOG = 30;

  ll ans=0;
  for(int t=LOG-1;t>=0;t--){
    if((~m>>t)&1) continue;

    DefaultDict<ll, ll> dp(-INF);
    auto get_bit=[&](int b){return (b>>t)<<t;};
    for(auto[x,y]:vp)
      chmax(dp[get_bit(x)],y);

    for(auto[x,y]:vq)
      if(dp.count(get_bit(m^(1LL<<t)^x)))
        chmax(ans,dp[get_bit(m^(1LL<<t)^x)]+y);
  }

  cout<<ans<<newl;
  return 0;
}
