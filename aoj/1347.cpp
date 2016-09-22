#include<iostream>
using namespace std;
int main(){
  int n,m;
  cin >> n >> m;
  int p[1050]={};
  int i,j,k;
  for(i=0;i<m;i++){
    cin >> j >> k;
    p[j]=max(p[j],k);
  }
  int inf = 1<<15;
  int dp[1050][1050];
  fill(dp[0],dp[1049],inf);
  dp[0][0]=0;
  i=0;
  for(j=max(i+1,p[i+1]);j<=n+1;j++){
    dp[j][i+1]=min(dp[j][i+1],dp[i][i]+2*(j-i)-1);
  }
  for(i=1;i<=n+1;i++){
    if(i>=p[i])
      dp[i][i]=min(dp[i][i],dp[i-1][i-1]+1);
    
    for(j=p[i];j<=n+1;j++){
      dp[j][i]=min(dp[j][i],dp[j][i-1]+1);
    }
    
    for(j=max(i+1,p[i+1]);j<=n+1;j++){
      dp[j][i+1]=min(dp[j][i+1],dp[i][i]+2*(j-i)-1);
    }
  }

  //cout << dp[1000][2] << endl;

  /*
  for(i=0;i<=10;i++){
    for(j=0;j<=10;j++){
      //cout << dp[j][i] << " ";
      printf("%3d ", dp[j][i]);
    }
    cout << endl;
  }
  */
  /*
  for(i=990;i<=1001;i++){
    for(j=990;j<=1001;j++){
      //cout << dp[j][i] << " ";
      printf("%3d ", dp[j][i]);
    }
    cout << endl;
  }
  */
  
  
  int o=inf;
  o=min(o,dp[n+1][n+1]);
  cout << o << endl;
  return 0;
}
