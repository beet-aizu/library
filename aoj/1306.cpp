#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main(){
  int n;
  while(cin >> n,n){
    int p[50],t[50];
    int i,j,k;
    p[0]=0;t[0]=0;
    for(i=1;i<=n;i++){
      cin >> p[i] >> t[i];
    }
    int dp[50][4];
    int inf = 1<<20;
    fill(dp[0],dp[49],inf);
    dp[0][0]=0;
    for(i=0;i<n;i++){
      for(j=0;j<3;j++){
	if(dp[i][j]==inf) continue;
	//cout << (j+1)*(t[i+1]-t[i]) << ":" << abs(p[i+1]-p[i]) <<endl;
	if((t[i+1]-t[i]) >= abs(p[i+1]-p[i])*(j+1))
	  dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+abs(p[i+1]-p[i]));
      }
      for(j=1;j<4;j++){
	if(dp[i][j]==inf) continue;
	//cout << i << j << endl;
	//cout << p[i]*(j+1)+p[i+1]<<":"<<(t[i+1]-t[i]) << endl;
	if(p[i]*(j+1)+p[i+1]<=(t[i+1]-t[i]))
	  dp[i+1][1]=min(dp[i+1][1],dp[i][j]+p[i]+p[i+1]);
      }
    }
    
    for(j=1;j<4;j++){
      if(dp[n][j]==inf) continue;
      dp[n+1][j]=min(dp[n+1][j],dp[n][j]+p[n]);
    }
    
    int o=inf;
    for(i=0;i<4;i++) {
      //cout << dp[n+1][i] << ":";
      o=min(o,dp[n+1][i]);
    }

    bool f=!true;
    if(f){
      for(i=1;i<=n+1;i++){
	cout << i << ":" ;
	for(j=0;j<4;j++) cout << dp[i][j] << ":";
	cout << endl;
      }
    }
    
    if(o<inf){
      cout << "OK " << o << endl;
    }else{
      k=1;
      for(j=1;j<=n;j++){
	o=inf;
	for(i=0;i<4;i++) {
	  o=min(o,dp[j][i]);
	}
	if(o==inf){
	  k=j;
	  break;
	}
      }
      cout << "NG " << k <<  endl;
    }
  }
  return 0;
}
