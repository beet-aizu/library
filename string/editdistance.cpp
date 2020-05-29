#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../tools/chminmax.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
int edit_distance(string s,string t){
  int n=s.size(),m=t.size();
  vector< vector<int> > dp(n+1,vector<int>(m+1,n+m+1));
  dp[0][0]=0;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      if(i<n) chmin(dp[i+1][j],dp[i][j]+1);
      if(j<m) chmin(dp[i][j+1],dp[i][j]+1);
      if(i<n and j<m)
        chmin(dp[i+1][j+1],dp[i][j]+(s[i]!=t[j]));
    }
  }
  return dp[n][m];
}
//END CUT HERE
//INSERT ABOVE HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
