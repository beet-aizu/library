#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
//BEGIN CUT HERE
int lcs(string s,string t){
  int n=s.size(),m=t.size();
  s+='$';t+='%';
  vector<vector<int> > dp(n+2,vector<int>(m+2,-(n+m)));
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
signed ALDS1_10_C(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int q;
  cin>>q;
  while(q--){
    string s,t;
    cin>>s>>t;
    cout<<lcs(s,t)<<"\n";
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/04/07
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C&lang=jp
*/

signed main(){
  ALDS1_10_C();
  return 0;
}
