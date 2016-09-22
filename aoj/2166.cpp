#include<iostream>
using namespace std;
int main(){
  int tm,n;
  while(cin >> tm,tm){
    int i,j,k;
    int t[tm];
    for(i=0;i<tm;i++) cin >> t[i];
    cin >> n;
    int d[n+1],m[n+1];
    for(i=1;i<=n;i++){
      cin >> d[i] >> m[i];
    }
    d[0]=0;m[0]=0;
    int inf = 1<<20;
    int dp[150][50];
    fill(dp[0],dp[50],inf);
    dp[0][0]=0;

    
    if(t[(d[1]-1)%tm]<=m[1]) dp[1][0]=0;
    else dp[1][0]=1;

    for(j=0;j<tm;j++){
      dp[1][0]
    }
    
    for(i=1;i<n;i++){
      for(j=0;j<tm;j++){
	if(dp[i][j]==inf) continue;
	dp[i+1][0]=min(dp[i+1][0],dp[i][j]+1);
	//cout << i<<":"<<j<<":"<<(j+d[i+1]-d[i])<<":"<<t[(j+d[i+1]-d[i])%tm]<<":"<<m[i+1]<<endl;
	
	if(t[(j+d[i+1]-d[i])%tm]<=m[i+1]){
	  dp[i+1][(j+d[i+1]-d[i])%tm]=
	    min(dp[i+1][(j+d[i+1]-d[i])%tm],dp[i][j]);
	}
	
      }
    }
    int o=inf;
    /*
    for(j=0;j<=n;j++){
      cout << j << ":";
      for(i=0;i<tm;i++) cout << dp[j][i] << (i==tm-1?"\n":" ");
    }
    */
    for(i=0;i<tm;i++) o=min(o,dp[n][i]);
    cout << o << endl;
  }
  return 0;
}
