#define PROBLEM "https://yukicoder.me/problems/3227"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/chminmax.cpp"
#include "../../datastructure/waveletmatrix.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using ll = long long;
  int n;
  cin>>n;
  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  const int OFS = 1e9;
  for(int &a:as) a+=OFS;

  WaveletMatrix<int, 31> wm(as);

  ll ans=0;
  for(ll k=1;k<=n;k++){
    int p=(k-1)/2;
    vector<ll> ls,rs;
    for(int i=0;i+k<=n;i+=k)
      ls.emplace_back((wm.rquantile(i,i+k,p)-OFS)*k);
    for(int i=n;i-k>=0;i-=k)
      rs.emplace_back((wm.rquantile(i-k,i,p)-OFS)*k);

    int sz=ls.size();
    vector<ll> dp(sz+1,0),pd(sz+1,0);

    for(ll i=0,sum=0;i<sz;i++){
      sum+=ls[i];
      chmax(dp[i+1],dp[i]);
      chmax(dp[i+1],sum);
    }
    for(ll i=sz,sum=0;i>0;i--){
      sum+=rs[sz-i];
      chmax(pd[i-1],pd[i]);
      chmax(pd[i-1],sum);
    }

    for(int i=0;i<=sz;i++)
      chmax(ans,dp[i]+pd[i]);
  }

  cout<<ans<<endl;
  return 0;
}
