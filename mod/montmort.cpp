#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// number of permutations with p_i != i
template<typename T>
struct Montmort{
  using ll = long long;
  vector<T> dp;

  Montmort(int n,int mod):dp(n+1,0){
    for(int k=2;k<=n;k++){
      dp[k]=(ll)dp[k-1]*k%mod;
      if(~k&1) dp[k]+=1;
      else dp[k]+=mod-1;
      if(dp[k]>=mod) dp[k]-=mod;
    }
  }

  T operator[](int n){return dp[n];}
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../math/extgcd.cpp"
#undef call_from_test

// montmort
signed ARC009_C(){
  using ll = long long;

  ll n,k;
  scanf("%lld %lld",&n,&k);
  const int MOD = 1777777777;
  int ans=Montmort<ll>(k,MOD)[k];

  int dom=1;
  for(int i=0;i<k;i++){
    ans=(ll)ans*((n-i)%MOD)%MOD;
    dom=(ll)dom*(i+1)%MOD;
  }

  ans=(ll)ans*mod_inverse<ll>(dom,MOD)%MOD;
  printf("%d\n",ans);
  return 0;
}
/*
  verified on 2019/12/18
  https://atcoder.jp/contests/arc009/tasks/arc009_3
*/

signed main(){
  ARC009_C();
  return 0;
}
#endif
