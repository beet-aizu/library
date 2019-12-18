#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../mod/enumeration.cpp"
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

#define call_from_test
#include "../mod/mint.cpp"
#undef call_from_test

signed CFR315_B(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  using M = Mint<int>;
  using E = Enumeration<M>;
  E::init(n+1);

  M res;
  for(int i=0;i<n;i++)
    res+=E::C(n,i)*bell<M>(i,i);

  cout<<res.v<<endl;
  return 0;
}
/*
  verified on 2019/12/18
  https://codeforces.com/contest/568/problem/B
*/

signed main(){
  CFR315_B();
  return 0;
}
#endif
