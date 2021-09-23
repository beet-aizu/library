// verification-helper: PROBLEM https://yukicoder.me/problems/5025

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../convolution/bitwise/fwht.cpp"
#include "../../convolution/bitwise/or.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  vector<int> as(1<<n);
  for(int &a:as) cin>>a;
  int sum=0;
  for(int a:as) sum+=a;

  using M = Mint<int, 998244353>;
  vector<M> dp(1<<n);
  for(int i=0;i<(int)as.size();i++)
    dp[i]=M(as[i])/M(sum);

  fwht(dp,bitwise_or::zeta);
  for(int i=0;i<(int)dp.size();i++)
    dp[i]=M(1)/(M(1)-dp[i]);
  fwht(dp,bitwise_or::moebius);

  cout<<accumulate(dp.begin(),dp.end()-1,M(0))<<endl;
  return 0;
}
