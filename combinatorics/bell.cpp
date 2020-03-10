#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "enumeration.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
// put n distinct balls into at most k identical boxes
template<typename M>
M bell(int n,int k){
  if(n==0) return M(1);

  using E = Enumeration<M>;
  k=min(k,n);
  E::init(k);

  vector<M> dp(k+1);
  dp[0]=M(1);
  for(int i=1;i<=k;i++)
    dp[i]=dp[i-1]+((i&1)?-E::Finv(i):E::Finv(i));

  M res(0);
  for(int i=1;i<=k;i++)
    res+=M(i).pow(n)*E::Finv(i)*dp[k-i];
  return res;
}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
