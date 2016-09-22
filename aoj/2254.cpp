#include<iostream>
#include <cstring>
using namespace std;

int n;
int m[20][20]={{}};
int inf = 10000000;
int dp[(1<<17)][17];
int k;

int rec(int s,int v){
  if(dp[s][v]>=0) return dp[s][v];

  if(s == (1<<(n+1))-1 && v == 0) return dp[s][v] = 0;

  int res = inf;
  for(int u=0;u<=n;u++){
    if(!(s>>u&1)){
      int cost = m[u][0];
      for(int i=0;i<=n;i++){
	if(s>>i&1)
	  cost= min(cost,m[u][i]);
      }
      res = min(res,rec(s | 1 << u, u)+cost);
    }
  }
  return dp[s][v] = res;
}

int main(){
  int i,j;
  
  
  cin >> n;
  while(n!=0){
    //memset(m,inf,sizeof(m));
    fill(m[0],m[19],inf);
    for(j=0;j<=n;j++) m[0][j]=0;
    for(i=1;i<=n;i++){
      for(j=0;j<=n;j++){
	cin >> m[i][j];
      }
    }
    int s=0;
    memset(dp,-1,sizeof(dp));
    cout << rec(0,0) << endl;
    cin >> n;
  }
  return 0;
}
