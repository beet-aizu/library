#include<iostream>
using namespace std;
long long o,n;
int main(){
  int i,j,k;
  long long d[4][4001]={{}};
  for(i=0;i<=1000;i++) d[0][i]=1;
  for(j=1;j<4;j++){
    for(i=0;i<=4001;i++) d[j][i]=0;
    for(i=0;i<=4000;i++){
      for(k=0;k<=1000;k++){
	if(i+k>4000) break;
	
	d[j][i+k]+=d[j-1][i];
	//if(i+k==4000) cout << k << ":" << d[j][4000] << endl;
      }
    }
  }
  //cout << d[1][0] << d[2][0]<<endl;
  while(cin>>n) {
    cout << d[3][n] << endl;
  }
}
