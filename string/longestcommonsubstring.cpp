#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
string longest_common_substring(string s,string t){
  int n=s.size(),m=t.size();
  s+='$';t+='%';
  vector< vector<int> > dp(n+2,vector<int>(m+2,-(n+m)));
  dp[0][0]=0;

  auto chmax=[&](int &a,int b){if(a<b) a=b;};
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      chmax(dp[i+1][j],dp[i][j]);
      chmax(dp[i][j+1],dp[i][j]);
      chmax(dp[i+1][j+1],dp[i][j]+(s[i]==t[j]));
    }
  }
  if(dp[n][m]==0) return ""s;
  string ans;
  int i=n,j=m;
  while(dp[i][j]){
    if((dp[i][j]==dp[i-1][j-1]+1) and (s[i-1]==t[j-1])){
      ans+=s[i-1];
      i--;j--;
    }else if(dp[i][j]==dp[i-1][j]) i--;
    else j--;
  }
  reverse(ans.begin(),ans.end());
  return ans;
}
//END CUT HERE
//INSERT ABOVE HERE
#ifndef call_from_test
signed DP_F(){
  string s,t;
  cin>>s>>t;
  cout<<longest_common_substring(s,t)<<endl;
  return 0;
}
/*
  verified on 2020/12/21
  https://atcoder.jp/contests/dp/tasks/dp_f
*/

signed main(){
  DP_F();
  return 0;
}
#endif
