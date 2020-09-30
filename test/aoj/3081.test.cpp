// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3081

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../string/zalgorithm.cpp"
#include "../../string/run.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  auto run=Run::enumerate(as);
  using ll = long long;
  vector<ll> dp(n+1,0),sm(n+1,0);
  for(ll i=1;i<=n;i++){
    dp[i]=dp[i-1]+(i-1)*1;
    sm[i]=sm[i-1]+(i-1)*i;
  }

  auto calc=[&](ll t,ll len)->ll{
    return (len+1)*dp[len/t]-t*sm[len/t];
  };

  ll ans=(ll)n*(n+1)/2;
  set<Run::P> used;
  for(int t=1;t<=n;t++){
    for(auto p:run[t]){
      if(used.count(p)) continue;
      used.emplace(p);
      ans+=calc(t,p.second-p.first);
    }
  }
  cout<<ans<<endl;
  return 0;
}
