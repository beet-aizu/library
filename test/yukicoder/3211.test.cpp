#define PROBLEM "https://yukicoder.me/problems/3211"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../mod/mint.cpp"
#include "../../polynomial/berlekamp_massey.cpp"
#undef call_from_test

signed main(){
  using M = Mint<int>;
  int p;
  cin>>p;

  const int n = 100;
  vector<M> as(n);
  as[0]=M(0);
  as[1]=M(0);
  as[2]=M(1);
  for(int i=3;i<n;i++) as[i]=M(p)*as[i-1]+as[i-2];

  vector<M> bs(n,M(0));
  for(int s=0;s<n;s++)
    for(int t=0;s+t<n;t++)
      bs[s+t]+=as[s]*as[t];

  auto cs=berlekamp_massey(bs);
  reverse(cs.begin(),cs.end());

  const int MAX = 2e6 + 100;
  vector<M> dp(MAX,0);
  for(int i=0;i<n;i++) dp[i]=bs[i];
  for(int i=n;i<MAX;i++)
    for(int j=0;j<(int)cs.size();j++)
      dp[i]-=dp[i-j]*cs[j];

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int k;
    cin>>k;
    cout<<dp[k]<<"\n";
  }
  return 0;
}
