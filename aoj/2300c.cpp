#include<iostream>
#include<stdio.h>
using namespace std;
int n,m;
double l[21]={},a[21]={},b[21]={};
double dp[21][21]={{}};
double o=0;

void saiki(int s,double sum,int k){
  int i,j;
  //cout << sum << endl;
  if(m==k) {
    if(o<sum) o=sum;
  }else{
    for(i=0;i<n;i++){
      //cout << i << endl << endl;
      if((s&(1<<i))!=0){
      }else{
	double b=0;
	for(j=0;j<n;j++){
	  if((s&(1<<j))!=0)
	    b+=dp[i][j];
	}
	
	saiki((s|(1<<i)),sum+b,k+1);
      }
    }
  }
}
int main(){
  int i,j,k;
  cin >> n >> m;
  
  for(i=0;i<n;i++){
    cin >> l[i] >> a[i] >> b[i];
  }
  
  for(j=0;j<n;j++){
    for(k=0;k<n;k++){
      dp[j][k]=(l[j]-l[k])*(l[j]-l[k])+
	(a[j]-a[k])*(a[j]-a[k])+
	(b[j]-b[k])*(b[j]-b[k]);
    }
  }
  saiki(0,0,0);
  printf("%.6f\n",o);
  return 0;
}

