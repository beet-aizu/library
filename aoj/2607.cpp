#include<iostream>
using namespace std;
#define MAX 100005
int main(){
  int n,d,x;
  cin >> n >> d >> x;
  int p[20][20]={{}};
  int i,j,k;
  for(i=0;i<d;i++){
    for(j=0;j<n;j++){
      cin >> p[i][j];
    }
  }
  int o=x,pre=x;
  int inf = 1<<20;
  for(k=0;k<d-1;k++){
    int dp[20][MAX]={{}};
    fill(dp[0],dp[19],-inf);
    dp[0][0]=pre;
    for(i=0;i<n;i++){
      for(j=0;j<=pre;j++){
	if(dp[i][j]==-inf) continue;
	for(int l=0;j+l*p[k][i]<=pre;l++){
	  dp[i+1][j+l*p[k][i]]=max(dp[i+1][j+l*p[k][i]],
				   dp[i][j]+l*(p[k+1][i]-p[k][i]));
	}
      }  
    }
    pre=0;
    for(j=0;j<MAX;j++) pre=max(pre,dp[n][j]);
    //cout << pre << endl;
    o=max(o,pre);
  }

      
  cout << o << endl;
  return 0;
}
