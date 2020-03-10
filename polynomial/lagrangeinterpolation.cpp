#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename M>
M lagrange_interpolation(vector<M> &y,M t){
  int n=y.size()-1;
  if(t.v<=n) return y[t.v];

  vector<M> dp(n+1,1),pd(n+1,1);
  for(int i=0;i<n;i++) dp[i+1]=dp[i]*(t-M(i));
  for(int i=n;i>0;i--) pd[i-1]=pd[i]*(t-M(i));

  vector<M> fact(n+1,1),finv(n+1,1);
  for(int i=1;i<=n;i++) fact[i]=fact[i-1]*M(i);
  finv[n]=M(1)/fact[n];
  for(int i=n;i>=1;i--) finv[i-1]=finv[i]*M(i);

  M res(0);
  for(int i=0;i<=n;i++){
    M tmp=y[i]*dp[i]*pd[i]*finv[i]*finv[n-i];
    if((n-i)&1) res-=tmp;
    else res+=tmp;
  }
  return res;
}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
