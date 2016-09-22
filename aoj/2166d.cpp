#include<iostream>
using namespace std;
int main(){
  int tm,n;
  while(cin >> tm,tm){
    int i,j,k;
    int t[tm];
    for(i=0;i<tm;i++) cin >> t[i];
    cin >> n;
    int m[150]={};
    fill(m,m+150,24);
    for(i=1;i<=n;i++){
      cin >> k;
      cin >> j;
      m[k]=min(m[k],j);
    }
    int inf = 1<<20;
    int dp[150][50];
    fill(dp[0],dp[149],inf);
    dp[1][0]=0;
    for(i=1;i<=100;i++){
      for(j=0;j<50;j++){
	if(dp[i][j]==inf) continue;
	dp[i+1][0]=min(dp[i+1][0],dp[i][j]+1);
	//cout <<i<<":"<<j<<":"<< t[(j+1)%tm]<<":"<<m[i]<<endl;
	if(t[(j+1)%tm]<=m[i+1]){
	  dp[i+1][(j+1)%tm]=min(dp[i+1][(j+1)%tm],dp[i][j]);
	}
      }
    }
    int o=inf;
    /*
    for(j=1;j<=n+10;j++){
      cout << j << ":";
      for(i=0;i<tm;i++) cout << dp[j][i] << (i==tm-1?"\n":" ");
    }
    */
    for(i=0;i<50;i++) o=min(o,dp[101][i]);
    cout << o << endl;
  }
  return 0;
}
