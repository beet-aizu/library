#include<iostream>
using namespace std;

int main(){
  int n,m;
  double l[21]={},a[21]={},b[21]={};
  cin >> n >> m;
  int i,j,k;
  for(i=0;i<n;i++){
    cin >> l[i] >> a[i] >> b[i];
  }
  double dp[21][21]={{}};
  for(i=0;i<m-1;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	
	dp[i+1][k]=max(dp[i+1][k],dp[i][j]+
		       (l[j]-l[k])*(l[j]-l[k])+
		       (a[j]-a[k])*(a[j]-a[k])+
		       (b[j]-b[k])*(b[j]-b[k]));
	cout << i << " "<< j << " "<< k  <<" "<< dp[i][j]+
		       (l[j]-l[k])*(l[j]-l[k])+
		       (a[j]-a[k])*(a[j]-a[k])+
	  (b[j]-b[k])*(b[j]-b[k]) << endl;
      }
      
    }
    for(j=0;j<n;j++){
      cout << dp[i+1][j] << " ";
    }
    cout << endl;
  }
  double o=0;
  for(i=0;i<n;i++){
    if(o<dp[m-1][i]) o=dp[m-1][i];
  }
  cout << o << endl;
  return 0;
}
