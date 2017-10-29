#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
int editDistance(string x,string y){
  int n=x.length(),m=y.length();
  int INF=n+m;
  vector<vector<int> > dp(n+1,vector<int>(m+1,INF));
  for(int i=0;i<=n;i++) dp[i][0]=i;
  for(int i=0;i<=m;i++) dp[0][i]=i;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
      dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
      dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(x[i-1]!=y[j-1]));
    }
  }
  return dp[n][m];
}
//END CUT HERE
signed main(){
  string s1,s2;
  cin>>s1>>s2;
  cout<<editDistance(s1,s2)<<endl;
  return 0;
}

/*
  verified on 2017/10/29
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E&lang=jp
*/
