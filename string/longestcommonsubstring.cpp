#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#endif
//BEGIN CUT HERE
int longest_common_substring(string s,string t){
  int n=s.size(),m=t.size();
  s+='$';t+='%';
  vector< vector<int> > dp(n+2,vector<int>(m+2,-(n+m)));
  dp[0][0]=0;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      chmax(dp[i+1][j],dp[i][j]);
      chmax(dp[i][j+1],dp[i][j]);
      chmax(dp[i+1][j+1],dp[i][j]+(s[i]==t[j]));
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
