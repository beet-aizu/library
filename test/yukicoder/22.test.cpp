#define PROBLEM "https://yukicoder.me/problems/22"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../polynomial/lagrangeinterpolation.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using M = Mint<int, int(1e9+9)>;
  const int MAX = 666 * 6 + 10;
  vector<M> dp(MAX,0);
  dp[0]=M(1);

  for(int x:{1,5,10,50,100,500})
    for(int j=x;j<MAX;j++) dp[j]+=dp[j-x];

  int T;
  cin>>T;
  while(T--){
    using ll = long long;
    ll m;
    cin>>m;
    vector<M> ys(6);
    for(int i=0;i<6;i++) ys[i]=dp[(m%500)+(i*500)];
    cout<<lagrange_interpolation(ys,M(m/500))<<"\n";
  }
  cout<<flush;
  return 0;
}
