#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,p,a,b;
  int i,j,k,l;
  int x,y,z;
  while(cin>>n>>m>>p>>a>>b,n||m||p||a||b){
    a--;b--;
    int t[n];
    for(i=0;i<n;i++) cin>>t[i];
    int e[m][m];
    memset(e,-1,sizeof(e));
    for(i=0;i<p;i++){
      cin>>x>>y>>z;
      x--;y--;
      e[x][y]=e[y][x]=z;
    }
    double dp[1<<n][m];
    double inf = 1<<28;
    for(i=0;i<1<<n;i++)
      for(j=0;j<m;j++)
	dp[i][j]=inf;
    dp[0][a]=0;
    for(i=0;i<1<<n;i++){
      for(j=0;j<m;j++){
	for(k=0;k<m;k++){
	  if(!~e[j][k]) continue;
	  for(l=0;l<n;l++){
	    if(i>>l&1) continue;
	    dp[i|1<<l][k]=min(dp[i|1<<l][k],dp[i][j]+(double)e[j][k]/t[l]);
	  }
	}
      }
    }
    double ans = inf;
    for(i=0;i<1<<n;i++) ans=min(ans,dp[i][b]);
    if(ans!=inf) printf("%.8f\n",ans);
    else printf("Impossible\n");
  }
  return 0;
}
