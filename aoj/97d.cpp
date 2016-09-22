#include<iostream>
using namespace std;
typedef long long ll;
int main(){
  int i,j,k,l;
  ll n,s;
  ll dp[10][101][1001]={{{}}};
  fill(dp[0][0],dp[9][100],0);
  for(i=0;i<101;i++) dp[0][i][i]=1;
  for(i=0;i<9;i++){
    for(j=0;j<101;j++){
      for(k=0;k<1001;k++){
	for(l=j+1;l<101;l++){
	  if(k+l>1000) break;
	  dp[i+1][l][k+l]+=dp[i][j][k];
	}
      }
    }
  }
  while(cin >> n >> s,n||s) {
    ll o=0;
    for(i=0;i<101;i++) o+=dp[n-1][i][s];
    cout << o << endl;
  }
  return 0;
}
