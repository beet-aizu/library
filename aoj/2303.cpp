#include<bits/stdc++.h>
using namespace std;
double C(int x,int y){
  double res=1;
  for(int i=0;i<y;i++) res*=x-i;
  for(int i=1;i<=y;i++) res/=i;
  return res;
}
int main(){
  int n,m;
  double l;
  cin >> n >> m >> l;
  int i,j,k,a;
  double p[n],t[n],v[n];
  double b[n][m+1];
  for(i=0;i<n;i++) {
    cin >> p[i] >> t[i] >> v[i];
    for(j=0;j<=m;j++){
      b[i][j]=C(m,j)*pow(p[i]/100,j)*pow(1.0-p[i]/100,m-j);
      //cout << i << "/" << j << ":" << b[i][j] <<"_" << l/v[i]+t[i]*j << endl;
    }
  }
  double ans,x,y;
  for(i=0;i<n;i++){
    ans=0;
    for(j=0;j<=m;j++){
      x=b[i][j];
      for(k=0;k<n;k++){
	if(i==k) continue;
	y=0;
	for(a=m;a>=0;a--){
	  if(l/v[k]+t[k]*a>l/v[i]+t[i]*j) y+=b[k][a];
	  else break;
	}
	//cout << "y:" << y << endl;
	x*=y;
      }
      //cout << "x:" << x << endl;
      ans+=x;
    }
    printf("%.8f\n",ans);
  }
  return 0;
}
