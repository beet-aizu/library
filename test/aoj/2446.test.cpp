// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446
// verification-helper: ERROR 1e-7

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/precision.cpp"
#include "../../convolution/bitwise/fwht.cpp"
#include "../../convolution/bitwise/or.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using ll = long long;

  int n;
  ll m;
  cin>>n>>m;
  vector<ll> as(n),ps(n);
  for(int i=0;i<n;i++) cin>>as[i];
  for(int i=0;i<n;i++) cin>>ps[i];

  vector<ll> dp(1<<n,0);
  for(int bit=1;bit<(1<<n);bit++){
    ll t=1;
    for(int i=0;i<n;i++){
      if((~bit>>i)&1) continue;
      ll k=as[i]/gcd(t,as[i]);
      t=(t<=m/k?t*k:m+1);
      if(t>m) break;
    }
    dp[bit]=m/t;
  }

  fwht(dp,moebius);

  double ans=0;
  for(int bit=0;bit<(1<<n);bit++){
    double po=1;
    for(int i=0;i<n;i++)
      if((bit>>i)&1) po*=ps[i]/100.0;
      else po*=1.0-(ps[i]/100.0);
    ans+=po*abs(dp[bit]);
  }
  cout<<ans<<endl;
  return 0;
}
