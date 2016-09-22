#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
  int n,t,l,b;
  int i,j,k;
  cin >> n >> t >> l >> b;
  while(n!=0){
    int ls[105]={},bs[105]={};
    for(i=0;i<l;i++){
      cin >> k;
      ls[k]=1;
    }
    for(i=0;i<b;i++){
      cin >> k;
      bs[k]=1;
    }
    double ma[105]={};
    double pre[105]={};
    double rs[105]={};
    pre[0]=1;
    int p;
    for(i=0;i<t;i++){
      fill(ma,ma+105,0);
      ma[n]=pre[n];
      for(j=0;j<n;j++){
	for(k=1;k<=6;k++){
	  p=j+k;
	  if(p>n) p=2*n-p;
	  if(bs[p]==1){
	    ma[0]+=pre[j]/6;
	  }else{
	    ma[p]+=pre[j]/6;
	  }
	}
      }
      for(j=0;j<=n;j++){
	if(ls[j]==1){
	  pre[j]=rs[j];
	  rs[j]=ma[j];
	}else{
	  pre[j]=ma[j];
	}
      }
    }
    //cout << pre[n] << endl;
    printf("%.6f\n",pre[n]);
    cin >> n >> t >> l >> b;
  }
  return 0;
}
