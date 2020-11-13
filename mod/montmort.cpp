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

  // MOD can be composite numbers
  Montmort(int n,const int MOD):dp(n+1,0){
    for(int k=2;k<=n;k++){
      dp[k]=(ll)dp[k-1]*k%MOD;
      if(~k&1) dp[k]+=1;
      else dp[k]+=MOD-1;
      if(dp[k]>=MOD) dp[k]-=MOD;
    }
  }

  T operator[](int n){return dp[n];}
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
