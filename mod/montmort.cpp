#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../mod/enumeration.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
// number of permutations with p_i != i
template<typename M>
struct Montmort{
  using E = Enumeration<M>;
  vector<M> dp;

  Montmort(int n):dp(n+1,0){
    E::init(n);
    M res(0);
    for(int k=2;k<=n;k++){
      if(k&1) res-=E::Finv(k);
      else res+=E::Finv(k);
      dp[k]=res*E::Fact(k);
    }
  }

  M operator()(int n){return dp[n];}
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../mod/mint.cpp"
#undef call_from_test

//montmort
signed ARC009_C(){
  long long n,k;
  scanf("%lld %lld",&n,&k);
  const int MOD = 1777777777;
  using M = Mint<long long, MOD>;
  Montmort<M> as(k);
  printf("%lld\n",(as(k)*M::comb(n,k)).v);
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
