#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#endif
//BEGIN CUT HERE
template<typename M>
struct Partition{
  vector< vector<M> > dp;
  Partition(int h,int w):dp(h+1,vector<M>(w+1,0)){
    dp[0][0]=M(1);
    for(int i=0;i<=h;i++){
      for(int j=1;j<=w;j++){
        dp[i][j]=dp[i][j-1];
        if(i-j>=0) dp[i][j]+=dp[i-j][j];
      }
    }
  }
  // put n identical balls into k identical boxes
  M operator()(int n,int k){return dp[n][k];}

  // put n identical balls into some boxes
  M operator()(int n){return dp[n][n];}
};
//END CUT HERE

#ifndef call_from_test
signed main(){
  return 0;
}
#endif
